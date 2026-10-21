#pragma once
#include <cstdlib>
#include <map>
#include <regex>
#include "../CombatConfig.h"
#include "../combat/CombatCheck.h"
#include "../combat/OriginalHealthBar.h"
#include "../combat/OriginalCooldown.h"
#include "../combat/MaaFrameRecognition.h"
#include "../combat/OriginalForteMatch.h"
#include "../char/MaaCharFactory.h"
#include "../char/OriginalCharFactory.h"
#include "OriginalSwitch.h"
#include "OriginalFreeze.h"
#include "OriginalTiming.h"
#include "SingleCharacterPolicy.h"
#include "OriginalRetarget.h"

inline MaaStatus run_combat(const fs::path& root, HMODULE dll, MaaController* controller,
                            MaaTasker* tasker, const std::string& entry, int argc,MaaContext* context) {
    if(argc==3)throw std::runtime_error("Combat mode requires the live game controller");
    const CombatConfig config=CombatConfig::load(root);
    SingleCharacterPolicy solo;
    OriginalRosterConfirmation roster_confirmation;
    OriginalStableHud hud_recovery;
    bool hud_suspended=false;
    double hud_suspended_at=0;
    bool raw_size=true;
    if(!api<decltype(&MaaControllerSetOption)>(dll,"MaaControllerSetOption")(
        controller,MaaCtrlOption_ScreenshotUseRawSize,&raw_size,sizeof(raw_size)))
        throw std::runtime_error("Maa original-size capture option failed");
    auto ctrl_wait=api<decltype(&MaaControllerWait)>(dll,"MaaControllerWait");
    auto touch_down=api<decltype(&MaaControllerPostTouchDown)>(dll,"MaaControllerPostTouchDown");
    auto touch_up=api<decltype(&MaaControllerPostTouchUp)>(dll,"MaaControllerPostTouchUp");
    auto key_down=api<decltype(&MaaControllerPostKeyDown)>(dll,"MaaControllerPostKeyDown");
    auto key_up=api<decltype(&MaaControllerPostKeyUp)>(dll,"MaaControllerPostKeyUp");
    auto seconds=[](){return original_wall_seconds();};
    auto stop_requested=[&](){return fs::exists(root/"stop.flag");};
    struct ReleaseInputs {
        std::function<void()> release;
        ~ReleaseInputs(){try{release();}catch(...){}}
    } release_inputs{[&](){
        for(int contact=0;contact<3;++contact)ctrl_wait(controller,touch_up(controller,contact));
        for(int key:std::array<int,10>{{'E','Q','R','T','F','W','A','S','D',VK_SPACE}})
            ctrl_wait(controller,key_up(controller,config.map_key(key)));
    }};
    OriginalFreezeClock freeze_clock;
    OriginalCooldown original_cooldown(dll,controller,tasker,context);
    original_cooldown.set_timing(seconds,[&](double start){return freeze_clock.elapsed(start,false,seconds());});
    MaaFrameRecognition hud_match(dll,tasker,controller,root,context);
    CombatCheck checker(dll,controller);
    checker.load_calibrations(root/"configs"/"_con_full_size.json",root/"resource"/"original_con_full_size.json");
    OriginalHealthBar health_bar;
    OriginalCombatIO io{};
    // Successful Maa input requests, not confirmed game skill casts.
    std::array<std::uint64_t,7> input_requests{}; // E,Q,R,normal,heavy,right,middle
    std::array<OriginalSwitchCharacter,3> members{};
    std::array<std::shared_ptr<OriginalBaseChar>,3> characters{};
    std::vector<std::shared_ptr<OriginalBaseChar>> retired_characters;
    std::array<CharacterMatch,3> previous_team{};
    std::array<CharacterMatch,3> lone_team{};
    std::string last_solo_identity;
    static const CharacterDefinition unknown_character{"BaseChar","",nullptr,"",nullptr,
        CharacterRole::MAIN_DPS,CharacterElement::UNKNOWN,14,false};
    int current_slot=0,team_count=3,scene_combat=-1,esc_count=0;
    bool combat_started=false,in_sleep_check=false;
    std::function<bool(bool)> original_in_combat;
    std::function<bool()> load_chars;
    FrameState scene_frame;
    bool scene_captured=false,pixels_ready=false;
    double scene_captured_at=0;
    double scene_capture_ms=0;
    int scene_target=-2,scene_slot=-2,current_slot_for_cd=0;
    auto reset_scene=[&](){
        scene_captured=false;pixels_ready=false;scene_target=-2;scene_slot=-2;
        original_cooldown.reset_scene();
        scene_combat=-1;
    };
    auto capture_scene=[&](){
        if(!scene_captured){
            const double capture_started=seconds();
            scene_captured=hud_match.capture();
            if(scene_captured){
                scene_captured_at=seconds();
                scene_capture_ms=std::max(0.0,(scene_captured_at-capture_started)*1000);
            }
        }
        return scene_captured;
    };
    auto next_frame=[&](){reset_scene();capture_scene();};
    // Decode portraits and load the OCR model before entering a rotation.
    // Discard the warm-up cooldowns; normal scene/slot refresh stays unchanged.
    if(capture_scene()){
        for(const auto& definition:character_definitions){
            hud_match.prepare_template(definition.portrait_image.data(),false,0,1);
            if(definition.alternate_portrait_image)hud_match.prepare_template(definition.alternate_portrait_image,false,0,1);
        }
        original_cooldown.refresh(1,hud_match.buffer());
        std::cout<<"recognition_ready ocr_warmup_ms="<<original_cooldown.recognition_ms()<<'\n'<<std::flush;
        original_cooldown.reset_combat();reset_scene();
    }
    auto frame=[&](){
        if(!pixels_ready && capture_scene()){
            if(current_slot>0)checker.set_ring_index(members[current_slot-1].ring_index);
            scene_frame=checker.capture(false,hud_match.buffer(),false);pixels_ready=true;
            if(current_slot>0 && members[current_slot-1].ring_index<0)
                members[current_slot-1].ring_index=scene_frame.concerto_color_index;
        }
        return pixels_ready?scene_frame:FrameState{};
    };
    std::map<std::string,std::string> templates;
    {
        std::ifstream file(root/"resource"/"pipeline"/"features.json");
        const std::string json((std::istreambuf_iterator<char>(file)),{});
        const std::regex item(R"re("OKWW_([^"]+)"\s*:\s*\{[^{}]*?"template"\s*:\s*"([^"]+)")re");
        for(auto it=std::sregex_iterator(json.begin(),json.end(),item);it!=std::sregex_iterator();++it)
            templates[(*it)[1].str()]=(*it)[2].str();
    }
    auto feature_at=[&](std::string_view name,ScreenBox box,double threshold,int target_height=0){
        const auto it=templates.find(std::string(name));
        return it!=templates.end() && capture_scene() && hud_match.match(it->second.c_str(),box,threshold,false,0,target_height).hit;
    };
    auto feature_in_box=[&](std::string_view name,std::string_view box_name,double threshold){
        const auto* source=find_original_box(box_name);
        if(!source || !capture_scene())return false;
        auto box=scale_original_box(*source,hud_match.width,hud_match.height);
        if(name.size()>=5 && name.substr(name.size()-5)=="_half")box.height=std::max(1,int(box.height*0.6));
        return feature_at(name,box,threshold);
    };
    auto feature=[&](std::string_view name,double threshold){
        const auto* source=find_original_box(name);
        const auto it=templates.find(std::string(name));
        if(!source || it==templates.end() || !capture_scene())return false;
        auto box=scale_original_box(*source,hud_match.width,hud_match.height);
        const int x1=std::max(0,original_round(box.x-hud_match.width*0.002));
        const int y1=std::max(0,original_round(box.y-hud_match.height*0.002));
        const int x2=std::min(hud_match.width,original_round(box.x+box.width+hud_match.width*0.002));
        const int y2=std::min(hud_match.height,original_round(box.y+box.height+hud_match.height*0.002));
        const bool bw=name=="world_earth_icon" || name=="illusive_realm_exit";
        return hud_match.match(it->second.c_str(),{x1,y1,x2-x1,y2-y1},threshold,bw).hit;
    };
    auto portrait_score=[&](const char* file,CharacterBox box){
        const auto* original=find_original_box("box_char_"+std::to_string(
            box.y==original_character_boxes[0].y?1:box.y==original_character_boxes[1].y?2:3));
        const auto roi=original?scale_original_box(*original,hud_match.width,hud_match.height):
            ScreenBox{box.x,box.y,box.width,box.height};
        return hud_match.match(file,roi,0.6).score;
    };
    auto active_slot=[&](){
        if(scene_slot!=-2)return scene_slot;
        std::array<double,3> scores{{-1,-1,-1}};
        scene_slot=capture_scene()?hud_match.active_slot(&scores):-1;
        const bool established_party=combat_started && !hud_suspended;
        if(scene_slot<1 && scene_captured && solo.can_probe_single_member(established_party)) {
            const auto hud=frame();
            const bool skill_hud=int(hud.resonance_white>0)+int(hud.echo_white>0)+int(hud.liberation_white>0)>=2;
            if(skill_hud) {
                if(combat_started && solo.known_team_count==1 && characters[0]) {
                    const auto* definition=members[0].definition;
                    double confidence=portrait_score(definition->portrait_image.data(),original_character_boxes[0]);
                    if(definition->alternate_portrait_image)confidence=std::max(confidence,
                        portrait_score(definition->alternate_portrait_image,original_character_boxes[0]));
                    lone_team={};
                    if(confidence>=0.6)lone_team[0]={definition,confidence,true};
                } else lone_team=recognize_original_team(portrait_score,{},3);
                const std::array<bool,3> visible{{lone_team[0].definition!=nullptr,
                    lone_team[1].definition!=nullptr,lone_team[2].definition!=nullptr}};
                // The solo extension has no teammate numbers. Require an
                // independent gameplay anchor or the original high-confidence
                // portrait reuse score; bright scenery alone is not a HUD.
                const bool anchored=visible[0] && (lone_team[0].confidence>=0.92 ||
                    feature("world_earth_icon",0.55) || feature("illusive_realm_exit",0.7));
                if(anchored && solo.single_member_hud(visible,skill_hud,established_party)) {
                    scene_slot=1;hud_match.team_count=1;
                }
            }
        }
        return scene_slot;
    };
    auto hud_readable=[&](){
        const int observed=active_slot();
        return scene_captured && observed>0 && observed<=hud_match.team_count && hud_match.team_count<=3 &&
            (!combat_started || hud_match.team_count==team_count);
    };
    auto observation_diagnostic=[&](std::string_view reason){
        const bool valid=capture_scene();
        std::string saved;
        try{
            if(valid){
                saved="debug/"+std::string(reason)+"-"+std::to_string(GetCurrentProcessId())+"-"+
                    std::to_string(GetTickCount64())+".png";
                fs::create_directories(root/"debug");
                if(!hud_match.save(root/saved))saved.clear();
            }
        }catch(const std::exception& error){std::cout<<"observation_diagnostic error="<<error.what()<<'\n';}
        const auto hud=frame();
        std::cout<<"observation_frame reason="<<reason<<" capture_valid="<<valid
            <<" capture_sequence="<<hud_match.sequence()<<" capture_ms="<<scene_capture_ms
            <<" frame_age_ms="<<(valid?std::max(0.0,(seconds()-scene_captured_at)*1000):-1)
            <<" sample_repeats="<<hud_match.sample_repeats<<" hud_slot="<<active_slot()
            <<" observed_team="<<hud_match.team_count<<" accepted_team="<<solo.known_team_count
            <<" E_white="<<hud.resonance_white<<" Q_white="<<hud.echo_white<<" R_white="<<hud.liberation_white
            <<" frame="<<(saved.empty()?"unavailable":saved)<<'\n'<<std::flush;
    };
    auto suspend_hud=[&](){
        if(hud_suspended)return;
        hud_suspended=true;hud_suspended_at=seconds();hud_recovery.reset();
        release_inputs.release();
        std::cout<<"original_hud_suspend input_released=1 combat_end_confirmed=0\n";
        observation_diagnostic("hud-unreadable");
    };
    auto require_combat_hud=[&](){
        if(stop_requested())throw OriginalCombatStopped();
        if(io.in_liberation)return;
        if(!hud_suspended && hud_readable())return;
        suspend_hud();
        const double started=seconds();
        do{
            const int observed=active_slot();
            if(hud_recovery.observe(hud_match.sequence(),seconds(),hud_readable()?observed+4*hud_match.team_count:0)){
                hud_suspended=false;
                std::cout<<"original_hud_recovered slot="<<observed<<" unreadable_seconds="
                    <<seconds()-hud_suspended_at<<" actors_retained=1\n";
                return;
            }
            if(stop_requested())throw OriginalCombatStopped();
            original_sleep_for(0.05);next_frame();
        }while(seconds()-started<0.5);
        // A prolonged unreadable HUD suspends monitoring. It must not run the
        // combat-end/healer/reset path or manufacture completed skill stages.
        throw OriginalHudUnavailable();
    };
    auto guard_solo_input=[&](){
        if(io.in_liberation)return;
        // Reuse an already captured observation. Keep the original capture
        // cadence between rapid inputs; an unknown cache is not a new failure.
        if(combat_started && (hud_suspended || (scene_captured && !hud_readable())))require_combat_hud();
        if(solo.enabled && solo.slot>0 &&
           (!solo.allows(active_slot()) || hud_match.team_count!=1))throw OriginalSoloSuspended();
    };
    bool allow_short_target=false;
    std::function<void(double,bool)> pause;
    std::function<bool(int,double,double,double)> send_key;
    std::function<int(bool)> target_locked;
    target_locked=[&](bool double_check=false){
        scene_target=-1;
        if(!capture_scene())return scene_target;
        const char* has=hud_match.width==1600?"160_370.png":"159_97.png";
        const char* no=hud_match.width==1600?"191_300.png":"190_80.png";
        const char* boxes[]={hud_match.width==1600?"has_target_169":"has_target","box_target_enemy_long","target_box_long2"};
        for(int i=0;i<3;++i){
            const auto a=hud_match.match_box(has,boxes[i],0.6,i==0?1.1:1,i==0?1.1:1);
            const auto b=hud_match.match_box(no,boxes[i],0.6,i==0?1.1:1,i==0?1.1:1);
            if(std::max(a.score,b.score)>=0.6){scene_target=a.score>=b.score?1:0;return scene_target;}
        }
        if(allow_short_target){
            if(hud_match.match_box(has,"target_box_short",0.6).hit ||
               hud_match.match_box(no,"target_box_short",0.6).hit)scene_target=1;
        }
        if(scene_target==1)return scene_target;
        const char* box=hud_match.width==1600?"has_target_169":"has_target";
        const auto a=hud_match.match_box(has,box,0.6,1.1,2.0);
        const auto b=hud_match.match_box(no,box,0.6,1.1,2.0);
        if(std::max(a.score,b.score)>=0.6){
            if(esc_count==0){
                if(double_check){
                    send_key(VK_ESCAPE,0.02,-1,2);send_key(VK_ESCAPE,0.02,-1,1.5);
                    esc_count=1;return 0;
                }
                pause(1,true);return target_locked(true);
            }
            return a.score>=b.score?1:0;
        }
        return scene_target;
    };
    // check_interval is shared by every input, just as BaseTask.last_click_time.
    // An interval is a throttle: a skipped operation does not sleep.
    double last_click_time=0;
    auto check_interval=[&](double interval){
        if(interval<=0)return true;
        const double now=seconds();
        if(now-last_click_time<interval)return false;
        last_click_time=now;return true;
    };
    auto triple_tap=[&](double duration,auto&& emit){
        using Clock=std::chrono::steady_clock;
        const auto started=Clock::now();
        const auto deadline=started+std::chrono::duration<double>(std::max(0.0,duration));
        for(int index=0;index<3;++index){
            const auto target=started+std::chrono::duration<double>(duration*index/3);
            original_sleep_for(std::chrono::duration<double>(target-Clock::now()).count());
            const double press=std::max(0.0,std::min(duration/9,
                std::chrono::duration<double>(deadline-Clock::now()).count()));
            if(!emit(press))return false;
        }
        original_sleep_for(std::chrono::duration<double>(deadline-Clock::now()).count());
        return true;
    };
    auto physical_send_key=[&](int vk,double down_time,double interval,double after_sleep){
        const int key=vk==config.map_key('E')?'E':vk==config.map_key('Q')?'Q':vk==config.map_key('R')?'R':vk;
        if(solo.enabled && key>='1' && key<='3')return false;
        guard_solo_input();
        if(!check_interval(interval)){reset_scene();return false;}
        reset_scene();
        const bool skill=key=='E' || key=='Q' || key=='R';
        auto emit=[&](double duration){
            const bool down_ok=ctrl_wait(controller,key_down(controller,vk))==MaaStatus_Succeeded;
            if(down_ok)original_sleep_for(duration);
            const bool up_ok=ctrl_wait(controller,key_up(controller,vk))==MaaStatus_Succeeded;
            if(!down_ok || !up_ok)throw std::runtime_error("Maa key input failed");
            return true;
        };
        const bool sent=skill && down_time<=0.1?triple_tap(down_time,emit):emit(down_time);
        if(sent && skill)++input_requests[key=='E'?0:key=='Q'?1:2];
        if(after_sleep>0)pause(after_sleep,true);
        return sent;
    };
    send_key=[&](int key,double down_time,double interval,double after_sleep){return physical_send_key(config.map_key(key),down_time,interval,after_sleep);};
    auto mouse_click=[&](int button,double interval=-1,double after_sleep=0){
        guard_solo_input();
        if(!check_interval(interval)){reset_scene();return false;}
        auto emit=[&](double duration){
            const bool down_ok=ctrl_wait(controller,touch_down(controller,button,hud_match.width/2,hud_match.height/2,0))==MaaStatus_Succeeded;
            if(down_ok)original_sleep_for(duration);
            const bool up_ok=ctrl_wait(controller,touch_up(controller,button))==MaaStatus_Succeeded;
            if(!down_ok || !up_ok)throw std::runtime_error("Maa mouse input failed");
            return true;
        };
        const bool sent=button==2?emit(0.01):triple_tap(0.01,emit);
        if(sent)++input_requests[button==0?3:button==1?5:6];
        if(after_sleep>0)pause(after_sleep,true);
        reset_scene();
        return sent;
    };
    auto check_health_bar=[&](){
        return health_bar.has_health_bar(frame(),combat_started) ||
            feature("boss_break_shield",0.8) || feature("boss_break_lock",0.8);
    };
    auto acquire_target=[&](double timeout=3,bool check_health=false){
        auto target_hud=[&](){
            if(stop_requested())throw OriginalCombatStopped();
            if(!hud_readable()){suspend_hud();throw OriginalHudUnavailable();}
        };
        const OriginalRetargetIO target_io{seconds,stop_requested,
            [&](){target_hud();return target_locked(false)==1;},[&](){target_hud();mouse_click(2,0.2);},
            next_frame,[&](){target_hud();return check_health_bar();}};
        const auto result=original_target_enemy(target_io,timeout,check_health);
        if(result.locked)return true;
        if(!stop_requested())target_hud();
        if(result.reason==OriginalRetargetExit::health_lost){
            std::cout<<"original_retarget_exit reason=health_bar_disappeared retry_seconds="
                <<result.elapsed<<" limit_seconds="<<timeout<<" health_lost_seconds=1.2\n";
            return false;
        }
        if(!stop_requested()){
            // Observe the final frame without sending input or extending retry.
            const bool valid=capture_scene();
            double has_score=-1,no_score=-1,best_score=-1;
            int best_region=-1;
            bool health=false;
            std::string saved;
            try{
                if(valid){
                    health=health_bar.has_health_bar(frame(),true);
                    const bool special=hud_match.width==1600;
                    const char* boxes[]={special?"has_target_169":"has_target","box_target_enemy_long",
                        "target_box_long2",special?"has_target_169":"has_target","target_box_short"};
                    for(int region=0;region<(allow_short_target?5:4);++region){
                        const double x=region==0 || region==3?1.1:1;
                        const double y=region==3?2:region==0?1.1:1;
                        const auto has=hud_match.match_box(special?"160_370.png":"159_97.png",boxes[region],0.6,x,y);
                        const auto no=hud_match.match_box(special?"191_300.png":"190_80.png",boxes[region],0.6,x,y);
                        if(std::max(has.raw_score,no.raw_score)>best_score){
                            best_score=std::max(has.raw_score,no.raw_score);best_region=region;
                            has_score=has.raw_score;no_score=no.raw_score;
                        }
                    }
                    saved="debug/target-timeout-"+std::to_string(GetCurrentProcessId())+"-"+
                        std::to_string(GetTickCount64())+".png";
                    fs::create_directories(root/"debug");
                    if(!hud_match.save(root/saved))saved.clear();
                }
            }catch(const std::exception& error){std::cout<<"target_diagnostic error="<<error.what()<<'\n';}
            std::cout<<"original_target_timeout retry_seconds="<<result.elapsed<<" limit_seconds="<<timeout
                <<" check_health="<<check_health
                <<" capture_valid="<<valid<<" hud_slot="<<active_slot()<<" health_bar="<<health
                <<" best_region="<<best_region<<" has_score="<<has_score<<" no_score="<<no_score
                <<" frame="<<(saved.empty()?"unavailable":saved)<<'\n';
        }
        return false;
    };
    double last_sleep_check_time=0;
    pause=[&](double duration,bool check_combat=true){
        reset_scene();
        if(duration<=0)return;
        const double deadline=seconds()+duration;
        while(!stop_requested()){
            const double now=seconds();
            if(!in_sleep_check && now-last_sleep_check_time>=0.4){
                in_sleep_check=true;
                try{
                    next_frame();
                    if(check_combat && !io.skip_combat_check && combat_started){
                        next_frame(); // BaseCombatTask.sleep_check refreshes again.
                        if(!original_in_combat(false))throw OriginalNotInCombat("Sleep check no longer in combat");
                    }
                    reset_scene();
                }catch(...){in_sleep_check=false;throw;}
                last_sleep_check_time=seconds();in_sleep_check=false;
            }
            const double remaining=deadline-seconds();
            if(remaining<=0)return;
            double wait=std::min(remaining,0.1);
            if(!in_sleep_check)wait=std::min(wait,std::max(0.0,0.4-(seconds()-last_sleep_check_time)));
            original_sleep_for(wait);
        }
    };
    auto select=[&](int slot){
        if(solo.enabled)return 0;
        // BaseChar.switch_other_char (before/after-combat healer selection).
        const int before=current_slot_for_cd;
        const double start=seconds();
        while(seconds()-start<6 && !stop_requested()){
            const int observed=active_slot();
            if(observed>0 && observed!=before)return observed;
            send_key('0'+slot,0.02,-1,0);
            pause(0.2,false);
        }
        return 0;
    };
    const int requested_team=entry=="--combat-one-team1"?1:entry=="--combat-one-team2"?2:entry=="--combat-one-team3"?3:0;
    // load_chars does not fabricate a switch-in timestamp for the initial team.
    OriginalForteMatch forte_match(hud_match);
    io.use_liberation=config.use_liberation;
    io.solo_mode=solo.enabled;io.guard_solo_input=guard_solo_input;
    io.hud_readable=hud_readable;io.capture_valid=capture_scene;
    io.require_combat_hud=require_combat_hud;
    io.frame_sequence=[&](){return hud_match.sequence();};
    io.observation_diagnostic=observation_diagnostic;
    io.auto_combat_task=true;
    io.chisa_dps=config.chisa_dps;io.iuno_c6=config.iuno_c6;
    std::cout<<"rotation_source okww=master commit=0b37b5b79e771297536ff1155db1c23131297558"
        <<" team_members=automatic native=C++ framework=MaaFramework\n"<<std::flush;
    io.frame=frame;io.send_key_action=send_key;io.click_action=mouse_click;
    io.send_physical_key=physical_send_key;io.configured_key=[&](char key){return config.map_key(key);};
    io.observed_team_count=[&](){active_slot();return hud_match.team_count;};
    io.raw_sleep=original_sleep_for;
    io.recognize_feature=[&](std::string_view name,const ScreenBox* provided,double threshold,const FrameState* custom){
        OriginalFeatureObservation out;if(!capture_scene())return out;
        ScreenBox roi{};
        if(provided)roi=*provided;
        else {
            const auto* source=find_original_box(name);if(!source)throw std::runtime_error("Official feature ROI not registered: "+std::string(name));
            roi=scale_original_box(*source,hud_match.width,hud_match.height);
            const int x1=std::max(0,original_round(roi.x-hud_match.width*0.002)),y1=std::max(0,original_round(roi.y-hud_match.height*0.002));
            const int x2=std::min(hud_match.width,original_round(roi.x+roi.width+hud_match.width*0.002)),y2=std::min(hud_match.height,original_round(roi.y+roi.height+hud_match.height*0.002));
            roi={x1,y1,x2-x1,y2-y1};
        }
        MaaFrameMatch result;
        if(custom)result=hud_match.match_custom(*custom,roi,threshold);
        else {
            const auto it=templates.find(std::string(name));if(it==templates.end())throw std::runtime_error("Official image not registered: "+std::string(name));
            result=hud_match.match(it->second.c_str(),roi,threshold);
        }
        out.found=result.hit;out.confidence=result.score;out.name=std::string(name);out.box={result.box.x,result.box.y,result.box.width,result.box.height};return out;
    };
    io.template_frame=[&](std::string_view name){
        if(!capture_scene())throw OriginalHudUnavailable();
        const auto it=templates.find(std::string(name));if(it==templates.end())throw std::runtime_error("Official template is missing: "+std::string(name));
        const auto& image=hud_match.prepare_template(it->second.c_str(),false,0,1);FrameState result;result.width=image.w;result.height=image.h;result.channels=3;
        result.pixels.bytes=std::make_shared<std::vector<unsigned char>>(image.pixels);return result;
    };
    io.reload_characters=[&](){return load_chars();};
    io.pause=pause;io.next_frame=[&](){
        next_frame();
        const int observed=solo.enabled && solo.slot>0 ? active_slot() : -1;
        if(observed>0 && (!solo.allows(observed) || hud_match.team_count!=1))throw OriginalSoloSuspended();
    };
    io.frame_captured_at=[&](){return scene_captured_at;};
    io.frame_capture_ms=[&](){return scene_capture_ms;};
    io.key_down_action=[&](int key){
        if(solo.enabled && key>='1' && key<='3')return false;
        guard_solo_input();
        reset_scene();const bool sent=ctrl_wait(controller,key_down(controller,config.map_key(key)))==MaaStatus_Succeeded;
        if(sent && (key=='E' || key=='Q' || key=='R'))++input_requests[key=='E'?0:key=='Q'?1:2];
        return sent;
    };
    io.key_up_action=[&](int key){reset_scene();return ctrl_wait(controller,key_up(controller,config.map_key(key)))==MaaStatus_Succeeded;};
    io.physical_key_down=[&](int key){if(solo.enabled&&key>='1'&&key<='3')return false;guard_solo_input();reset_scene();const bool sent=ctrl_wait(controller,key_down(controller,key))==MaaStatus_Succeeded;if(!sent)throw std::runtime_error("Maa physical key down failed");return sent;};
    io.physical_key_up=[&](int key){reset_scene();const bool sent=ctrl_wait(controller,key_up(controller,key))==MaaStatus_Succeeded;if(!sent)throw std::runtime_error("Maa physical key up failed");return sent;};
    io.mouse_down=[&](){guard_solo_input();reset_scene();const bool sent=ctrl_wait(controller,touch_down(controller,0,hud_match.width/2,hud_match.height/2,0))==MaaStatus_Succeeded;if(sent)++input_requests[4];return sent;};
    io.mouse_up=[&](){reset_scene();return ctrl_wait(controller,touch_up(controller,0))==MaaStatus_Succeeded;};
    io.target_present=[&](){return original_in_combat(false);};
    io.has_target=[&](){return target_locked(false)==1;};
    io.is_open_world_auto_combat=[&](){
        return !(feature("illusive_realm_exit",0.7) && active_slot()>0 && !feature("world_earth_icon",0.55));
    };
    io.find_character=[&](std::string_view name)->OriginalBaseChar*{
        for(int i=0;i<team_count;++i)if((!solo.enabled || i==current_slot-1) &&
            members[i].definition && members[i].definition->class_name==name)return characters[i].get();
        return nullptr;
    };
    io.member_at=[&](int slot)->OriginalSwitchCharacter*{return (!solo.enabled || slot==current_slot) && slot>=1 && slot<=team_count && members[slot-1].definition?&members[slot-1]:nullptr;};
    io.team_size=[&](){return team_count;};
    io.feature_in_box=feature_in_box;io.feature=feature;
    io.feature_at=[&](std::string_view name,ScreenBox box,double threshold){return feature_at(name,box,threshold);};
    io.active_slot=active_slot;
    auto refresh_cd=[&](){if(current_slot_for_cd>0 && capture_scene())original_cooldown.refresh_scene(current_slot_for_cd,hud_match.buffer());};
    io.cooldown_remaining=[&](char key){refresh_cd();return original_cooldown.remaining(key,current_slot_for_cd,false);};
    io.cooldown_for_slot=[&](char key,int slot){refresh_cd();return original_cooldown.remaining(key,slot,false);};
    io.find_mouse_forte=[&](){return capture_scene() && forte_match.match(hud_match.recognition_buffer(),false);};
    io.find_e_forte=[&](){return capture_scene() && forte_match.match(hud_match.recognition_buffer(),true);};
    io.stop_requested=stop_requested;io.seconds=seconds;
    io.add_freeze_duration=[&](double start,double duration,double minimum){freeze_clock.add(start,duration,minimum,seconds());};
    io.elapsed_accounting_for_freeze=[&](double start,bool intro){return freeze_clock.elapsed(start,intro,seconds());};
    auto switch_healer=[&](){
        if(solo.enabled)return;
        if(!config.switch_healer || current_slot<1 || members[current_slot-1].is_healer())return;
        for(int i=0;i<3;++i)if(i!=current_slot-1 && members[i].is_healer()){
            const int observed=select(i+1);
            if(observed>0){
                for(auto& member:members)member.is_current_char=member.index==observed-1;
                current_slot=observed;current_slot_for_cd=current_slot;
                checker.set_ring_index(members[observed-1].ring_index);pixels_ready=false;
                allow_short_target=members[observed-1].definition->target_box_short_combat_check;
            }
            return;
        }
    };
    auto update_current=[&](int slot){
        if(slot<1 || slot>team_count)return;
        current_slot=slot;current_slot_for_cd=slot;
        for(int i=0;i<team_count;++i)members[i].is_current_char=i==slot-1;
        checker.set_ring_index(members[slot-1].ring_index);pixels_ready=false;
        allow_short_target=members[slot-1].definition->target_box_short_combat_check;
    };
    io.confirm_current_character=update_current;
    io.select_character=[&](int slot){const int observed=select(slot);if(observed>0)update_current(observed);return observed>0;};
    load_chars=[&](){
        const int observed=active_slot();if(observed<1){roster_confirmation.reject();return false;}
        const int observed_count=std::min(3,hud_match.team_count);
        if(observed_count<observed)return false;
        // A lone member needs a fresh identity. Normal teams retain the
        // original portrait reuse and their normal rotation selection.
        const auto recognized=observed_count==1 ? recognize_original_team(portrait_score,{},observed_count) :
            recognize_original_team(portrait_score,previous_team,observed_count);
        const int detected_team=original_team_is(recognized,"Aemeath","Linnai","Mornye")?1:
            original_team_is(recognized,"Hiyuki","Lucilla","Chisa")?2:
            original_team_is(recognized,"Qingxiao","Denia","ShoreKeeper")?3:0;
        if(observed_count>1 && requested_team && detected_team!=requested_team)return false;
        const auto* selected=recognized[observed-1].definition;
        if(observed_count==1 && !selected) {
                const std::string candidate=selected?std::string(selected->class_name):"unknown";
                if(candidate!=last_solo_identity) {
                    std::cout<<"single_member_identity_wait observed="<<candidate
                        <<" input_suspended=1\n"<<std::flush;
                    last_solo_identity=candidate;
                }
                return false;
        }
        std::string roster_identity;
        for(int i=0;i<observed_count;++i){
            roster_identity+=recognized[i].definition?recognized[i].definition->class_name:"BaseChar";
            roster_identity+=';';
        }
        if(!roster_confirmation.observe(roster_identity,observed_count,hud_match.sequence(),seconds()))return false;
        const int previous_count=solo.known_team_count;
        const std::string previous_identity=solo.character;
        if(!solo.bind(observed,observed_count,selected?selected->class_name:"BaseChar"))return false;
        team_count=observed_count;io.solo_mode=solo.enabled;last_solo_identity.clear();
        if(previous_count!=team_count || previous_identity!=solo.character)
            std::cout<<"team_mode team_count="<<team_count<<" single_member="<<solo.enabled
                <<" automatic_switch="<<!solo.enabled<<" class="<<(solo.enabled?solo.character:"party")
                <<'\n'<<std::flush;
        for(int i=0;i<3;++i){
            if(i>=team_count){if(characters[i]){static_cast<official::OfficialCharacter*>(characters[i].get())->detach_member();retired_characters.push_back(std::move(characters[i]));}members[i]={};previous_team[i]={};continue;}
            const auto* definition=recognized[i].definition?recognized[i].definition:&unknown_character;
            const bool identity_changed=members[i].definition!=definition;
            const bool replace=!characters[i] || !recognized[i].reused || members[i].definition!=definition;
            if(replace){
                if(characters[i]){static_cast<official::OfficialCharacter*>(characters[i].get())->detach_member();retired_characters.push_back(std::move(characters[i]));}
                members[i]={};members[i].definition=definition;members[i].index=i;
                members[i].ring_index=int(definition->element)-1;
                members[i].elapsed_accounting_for_freeze=io.elapsed_accounting_for_freeze;
                if(definition->class_name=="Chisa" && config.chisa_dps)members[i].role_override=int(CharacterRole::MAIN_DPS);
                if(definition->class_name=="Iuno" && config.iuno_c6)members[i].role_override=int(CharacterRole::MAIN_DPS);
                characters[i]=make_original_character(definition->class_name,io,members[i]);
                // Original load_chars logs only a changed character identity.
                if(identity_changed)std::cout<<"character_slot="<<i+1<<" class="<<definition->class_name<<" score="<<recognized[i].confidence<<'\n';
            }
            auto* official_actor=static_cast<official::OfficialCharacter*>(characters[i].get());official_actor->apply_registration();official_actor->set("confidence",official::V(recognized[i].confidence));
            previous_team[i]=recognized[i];previous_team[i].definition=definition;
            characters[i]->reset_state();
        }
        update_current(observed);io.combat_start=seconds();
        return team_count>=1;
    };
    auto is_pick_f=[&](){
        const auto* source=find_original_box("pick_up_f_hcenter_vcenter");
        const auto it=templates.find("pick_up_f_hcenter_vcenter");
        if(!source || it==templates.end() || !capture_scene())return false;
        auto box=scale_original_box(*source,hud_match.width,hud_match.height);
        box.x=original_round(box.x-box.width*0.3);box.y=original_round(box.y-box.height*5);
        box.width=original_round(box.width*1.65);box.height=original_round(box.height*7.5);
        const auto f=hud_match.match(it->second.c_str(),box,0.8);if(!f.hit)return false;
        return feature_at("dialog_3_dots",{f.box.x+f.box.width*3,f.box.y-f.box.height,
            original_round(f.box.width*2.8),f.box.height*3},0.6);
    };
    io.check_f_break_action=[&](){
        if(io.can_break)return true;
        if(feature("f_break_full",0.92)){io.can_break=true;return true;}
        if(!io.in_liberation && seconds()-io.last_break_check_time>1){
            io.last_break_check_time=seconds();
            if(capture_scene() && feature_at("f_break",original_screen_box(hud_match.width,hud_match.height,
                0.2,0.2,0.75,0.8,true,true),0.8,720) && !is_pick_f())io.can_break=true;
        }
        return io.can_break;
    };
    auto reset_combat=[&](){
        combat_started=false;io.in_liberation=false;io.skip_combat_check=false;in_sleep_check=false;io.has_levitator=false;io.can_break=false;
        hud_suspended=false;hud_recovery.reset();
        esc_count=0;original_cooldown.reset_combat();scene_combat=0;
    };
    // Official d590b6b reset_auto_combat: discard roster/freeze state when
    // leaving team/world. F10/F11 restart uses a fresh native process.
    auto reset_auto_combat=[&](const char* reason){
        reset_combat();freeze_clock=OriginalFreezeClock{};
        for(int i=0;i<3;++i){if(characters[i]){static_cast<official::OfficialCharacter*>(characters[i].get())->detach_member();retired_characters.push_back(std::move(characters[i]));}members[i]={};previous_team[i]={};}
        current_slot=0;current_slot_for_cd=0;team_count=3;solo=SingleCharacterPolicy{};io.solo_mode=false;roster_confirmation.reject();
        std::cout<<"official_auto_combat_reset reason="<<reason<<" chars_cleared=1 cooldowns_cleared=1 freezes_cleared=1\n";
    };
    // Read-only hint: defer full portrait scans on an idle frame. Include the
    // short bar so the first fight after a team change keeps its original check.
    // The actual target decision, including role allowance and Esc, runs only
    // after load_chars has established the current character.
    auto target_hint=[&](){
        if(!capture_scene())return false;
        const bool special=hud_match.width==1600;
        const char* boxes[]={special?"has_target_169":"has_target","box_target_enemy_long",
            "target_box_long2","target_box_short",special?"has_target_169":"has_target"};
        for(int region=0;region<5;++region){
            const double x=region==0 || region==4?1.1:1;
            const double y=region==4?2:region==0?1.1:1;
            if(hud_match.match_box(special?"160_370.png":"159_97.png",boxes[region],0.6,x,y).hit ||
               hud_match.match_box(special?"191_300.png":"190_80.png",boxes[region],0.6,x,y).hit)return true;
        }
        return false;
    };
    original_in_combat=[&](bool target){
        in_sleep_check=true;
        struct CheckScope {bool& value;~CheckScope(){value=false;}} scope{in_sleep_check};
        if(io.in_liberation)return true;
        if(combat_started){
            if(scene_combat!=-1)return scene_combat==1;
            if(current_slot>0 && characters[current_slot-1] && characters[current_slot-1]->skip_combat_check()){
                scene_combat=1;return true;
            }
            require_combat_hud();
            io.check_f_break_action();
            if(target_locked(false)==1){scene_combat=1;return true;}
            // AutoCombatTask.on_combat_check returns true and has no combat_end_condition.
            const auto retarget=original_retarget_settings(true,check_health_bar());
            if(acquire_target(retarget.timeout,retarget.check_health)){scene_combat=1;return true;}
            std::cout<<"original_combat_exit reason=target_enemy_failed\n";
            reset_combat();return false;
        }
        bool chars_loaded=false;
        if(config.auto_target){
            if(!target && !target_hint() && !health_bar.has_health_bar(frame(),false) &&
                !feature("boss_break_shield",0.8) && !feature("boss_break_lock",0.8))return false;
        }
        // Keep the original 0.6 acceptance, 0.92 reuse and reset behavior, and
        // establish the character before target_locked can perform any input.
        chars_loaded=load_chars();
        if(!chars_loaded)return false;
        bool has_target=target_locked(false)==1;
        if(!has_target && target)mouse_click(2,-1,0.1);
        const bool seen=has_target || (config.auto_target &&
            (health_bar.has_health_bar(frame(),false) || feature("boss_break_shield",0.8) || feature("boss_break_lock",0.8)));
        if(!seen)return false;
        if(!has_target && !acquire_target())return false;
        io.has_levitator=feature("edge_levitator",0.65);
        combat_started=chars_loaded || load_chars();
        if(combat_started)std::cout<<"original_combat_enter slot="<<current_slot<<" team_count="<<team_count<<'\n';
        return combat_started;
    };
    // Persistent AutoCombatTask.run/TriggerTask.should_trigger. The 0.1 second
    // interval is measured from trigger START, not appended to every fight.
    double last_trigger_time=0;
    double last_log_flush=0;
    double last_monitor_log=seconds();
    const auto flush_log=[&](){const double now=seconds();if(now-last_log_flush>=1){std::cout.flush();last_log_flush=now;}};
    while(!stop_requested()){
        retired_characters.clear();
        flush_log();
        const double wait=0.1-(seconds()-last_trigger_time);
        if(wait>0)pause(wait,false);
        if(stop_requested())break;
        last_trigger_time=seconds();next_frame();
        if(last_trigger_time-last_monitor_log>=10){
            std::cout<<"combat_monitor active_slot="<<active_slot()<<" combat="<<combat_started
                <<" capture_calls="<<hud_match.captures<<" recognition_calls="<<hud_match.recognition_calls()
                <<" unchanged_match_reuses="<<hud_match.unchanged_match_reuses<<'\n';
            last_monitor_log=last_trigger_time;
        }
        const int observed_slot=active_slot();
        if(observed_slot<1){
            roster_confirmation.reject();
            if(combat_started)suspend_hud();
            if(combat_started||current_slot>0)reset_auto_combat("not_in_team_and_world");
            continue;
        }
        bool recovered_roster_change=false;
        if(hud_suspended && combat_started && hud_match.team_count==solo.known_team_count){
            const auto observed=recognize_original_team(portrait_score,previous_team,hud_match.team_count);
            for(int i=0;i<hud_match.team_count;++i)
                if(observed[i].definition!=previous_team[i].definition)recovered_roster_change=true;
        }
        // A genuine roster change re-loads the actors. No session-wide
        // character lock survives a return to a two/three-member party.
        if(recovered_roster_change || (solo.known_team_count>0 && hud_match.team_count!=solo.known_team_count) ||
           (!solo.enabled && hud_match.team_count==1)) {
            if(!load_chars())continue;
            reset_combat();
        }
        io.use_liberation=config.use_liberation;
        if(!solo.enabled && !io.use_liberation && !(feature("world_earth_icon",0.55) && active_slot()>0 &&
            !feature("illusive_realm_exit",0.7)))io.use_liberation=true;
        bool ret=false,switched_healer=false;
        int performances=0;
        try{
            while(!stop_requested() && original_in_combat(false)){
                ret=true;
                if(!switched_healer){switch_healer();switched_healer=true;}
                // The original current character comes from cached load/switch
                // state. Do not insert a HUD wait or reset intro mid-animation.
                std::cout<<"original_perform class="<<members[current_slot-1].definition->class_name<<" slot="<<current_slot<<'\n';
                flush_log();
                const int from=current_slot;
                const auto performed_class=members[from-1].definition->class_name;
                const auto started=std::chrono::steady_clock::now();
                const auto before=input_requests;
                const auto log_result=[&](const char* result){
                    std::cout<<"original_perform_end class="<<performed_class<<" from_slot="<<from
                        <<" current_slot="<<current_slot<<" result="<<result<<" duration_ms="
                        <<std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count()
                        <<" input_requests_E="<<input_requests[0]-before[0]<<" Q="<<input_requests[1]-before[1]
                        <<" R="<<input_requests[2]-before[2]<<" normal="<<input_requests[3]-before[3]
                        <<" heavy="<<input_requests[4]-before[4]<<" right="<<input_requests[5]-before[5]
                        <<" middle="<<input_requests[6]-before[6]<<'\n';
                };
                try{characters[from-1]->perform();++performances;log_result("completed");}
                catch(...){io.skip_combat_check=false;log_result(stop_requested()?"stopped":"interrupted");throw;}
            }
        }catch(const OriginalSoloSuspended&){
            release_inputs.release();io.in_liberation=false;reset_scene();
            reset_combat();
            std::cout<<"single_member_hud_retry class="<<solo.character
                <<" reload_team=1 input_released=1\n"<<std::flush;
            continue;
        }catch(const OriginalCombatStopped&){
            std::cout<<"combat_stop requested=1\n";break;
        }catch(const OriginalHudUnavailable&){
            suspend_hud();
            release_inputs.release();io.in_liberation=false;reset_scene();
            // Keep the accepted roster and actor state while waiting for HUD
            // recovery. No after-combat inputs are allowed on an unknown frame.
            continue;
        }catch(const OriginalHudRetry& error){
            if(stop_requested())break;
            io.in_liberation=false;
            std::cout<<"original_hud_retry reason="<<error.what()<<'\n';
            const double started=seconds();
            int observed=0;
            while(seconds()-started<=2 && !stop_requested()){
                next_frame();
                observed=active_slot();
                if(observed>0 && target_locked(false)==1)break;
                observed=0;
            }
            if(stop_requested())break;
            if(observed>0){
                // A failed switch is not a combat end. Rebind the observed
                // character without inventing an Intro/buff or erasing stages.
                update_current(observed);
                std::cout<<"original_hud_recovered slot="<<observed<<" rotation_state_preserved=1\n";
                continue;
            }
            reset_combat();
        }catch(const OriginalNotInCombat& error){
            if(stop_requested())break;
            std::cout<<"original_perform interrupted="<<error.what()<<'\n';
            // BaseCombatTask.raise_not_in_combat waits up to 2 seconds for the
            // original revive-confirm feature, then resets its combat state.
            const double started=seconds();
            while(seconds()-started<=2 && !stop_requested()){
                next_frame();
                if(feature_in_box("revive_confirm_hcenter_vcenter","revive_confirm_hcenter_vcenter",0.8))break;
            }
            reset_combat();
        }
        if(ret && !stop_requested()){
            try{
                if(!solo.enabled)characters[current_slot-1]->on_combat_end();
                for(auto& character:characters)if(character)character->reset_state();
                switch_healer();
            }catch(const OriginalCombatStopped&){
                std::cout<<"combat_stop requested=1\n";break;
            }
            std::cout<<"original_team performances="<<performances<<" continue_monitoring=1\n";
        }
    }
    std::cout<<"combat_performance capture_calls="<<hud_match.captures
        <<" capture_ms="<<hud_match.capture_ms<<" template_calls="<<hud_match.recognition_calls()
        <<" template_ms="<<hud_match.recognition_ms()<<" same_frame_reuse="<<hud_match.cache_hits
        <<" roi_preparations="<<hud_match.region_preparations<<" roi_reuses="<<hud_match.region_reuses
        <<" unchanged_roi_reuses="<<hud_match.unchanged_region_reuses
        <<" unchanged_match_reuses="<<hud_match.unchanged_match_reuses
        <<" roi_copy_bytes="<<hud_match.region_copy_bytes
        <<" ocr_calls="<<original_cooldown.recognition_calls()<<" ocr_ms="<<original_cooldown.recognition_ms()<<'\n'<<std::flush;
    return MaaStatus_Succeeded;
}

