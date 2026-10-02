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

inline MaaStatus run_combat(const fs::path& root, HMODULE dll, MaaController* controller,
                            MaaTasker* tasker, const std::string& entry, int argc) {
    if(argc==3)throw std::runtime_error("Combat mode requires the live game controller");
    const CombatConfig config=CombatConfig::load(root);
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
    OriginalCooldown original_cooldown(dll,controller,tasker);
    original_cooldown.set_timing(seconds,[&](double start){return freeze_clock.elapsed(start,false,seconds());});
    MaaFrameRecognition hud_match(dll,tasker,controller,root);
    CombatCheck checker(dll,controller);
    checker.load_calibrations(root/"configs"/"_con_full_size.json",root/"resource"/"original_con_full_size.json");
    OriginalHealthBar health_bar;
    OriginalCombatIO io{};
    std::array<OriginalSwitchCharacter,3> members{};
    std::array<std::unique_ptr<OriginalBaseChar>,3> characters{};
    std::array<CharacterMatch,3> previous_team{};
    static const CharacterDefinition unknown_character{"BaseChar","",nullptr,"",nullptr,
        CharacterRole::MAIN_DPS,CharacterElement::UNKNOWN,14,false};
    int current_slot=0,team_count=3,scene_combat=-1,esc_count=0;
    bool combat_started=false,in_sleep_check=false;
    std::function<bool(bool)> original_in_combat;
    std::function<bool()> load_chars;
    FrameState scene_frame;
    bool scene_captured=false,pixels_ready=false;
    int scene_target=-2,scene_slot=-2,current_slot_for_cd=0;
    auto reset_scene=[&](){
        scene_captured=false;pixels_ready=false;scene_target=-2;scene_slot=-2;
        original_cooldown.reset_scene();
        scene_combat=-1;
    };
    auto capture_scene=[&](){
        if(!scene_captured)scene_captured=hud_match.capture();
        return scene_captured;
    };
    auto next_frame=[&](){reset_scene();capture_scene();};
    auto frame=[&](){
        if(!pixels_ready && capture_scene()){
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
    auto active_slot=[&](){
        if(scene_slot!=-2)return scene_slot;
        std::array<double,3> scores{{-1,-1,-1}};
        scene_slot=capture_scene()?hud_match.active_slot(&scores):-1;
        return scene_slot;
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
    send_key=[&](int key,double down_time,double interval,double after_sleep){
        if(!check_interval(interval)){reset_scene();return false;}
        reset_scene();
        const bool skill=key=='E' || key=='Q' || key=='R';
        const int vk=config.map_key(key);
        auto emit=[&](double duration){
            const bool down_ok=ctrl_wait(controller,key_down(controller,vk))==MaaStatus_Succeeded;
            if(down_ok)original_sleep_for(duration);
            const bool up_ok=ctrl_wait(controller,key_up(controller,vk))==MaaStatus_Succeeded;
            if(!down_ok || !up_ok)throw std::runtime_error("Maa key input failed");
            return true;
        };
        const bool sent=skill && down_time<=0.1?triple_tap(down_time,emit):emit(down_time);
        if(after_sleep>0)pause(after_sleep,true);
        return sent;
    };
    auto mouse_click=[&](int button,double interval=-1,double after_sleep=0){
        if(!check_interval(interval)){reset_scene();return false;}
        auto emit=[&](double duration){
            const bool down_ok=ctrl_wait(controller,touch_down(controller,button,hud_match.width/2,hud_match.height/2,0))==MaaStatus_Succeeded;
            if(down_ok)original_sleep_for(duration);
            const bool up_ok=ctrl_wait(controller,touch_up(controller,button))==MaaStatus_Succeeded;
            if(!down_ok || !up_ok)throw std::runtime_error("Maa mouse input failed");
            return true;
        };
        const bool sent=button==2?emit(0.01):triple_tap(0.01,emit);
        if(after_sleep>0)pause(after_sleep,true);
        reset_scene();
        return sent;
    };
    auto acquire_target=[&](){
        if(target_locked(false)==1)return true;
        const double start=seconds(); // CombatCheck.target_enemy_time_out = 3.
        while(seconds()-start<3 && !stop_requested()){
            mouse_click(2,0.2);
            if(target_locked(false)==1)return true;
            next_frame();
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
    io.chisa_dps=config.chisa_dps;io.iuno_c6=config.iuno_c6;
    io.frame=frame;io.send_key_action=send_key;io.click_action=mouse_click;
    io.pause=pause;io.next_frame=next_frame;
    io.key_down_action=[&](int key){reset_scene();return ctrl_wait(controller,key_down(controller,config.map_key(key)))==MaaStatus_Succeeded;};
    io.key_up_action=[&](int key){reset_scene();return ctrl_wait(controller,key_up(controller,config.map_key(key)))==MaaStatus_Succeeded;};
    io.mouse_down=[&](){reset_scene();return ctrl_wait(controller,touch_down(controller,0,hud_match.width/2,hud_match.height/2,0))==MaaStatus_Succeeded;};
    io.mouse_up=[&](){reset_scene();return ctrl_wait(controller,touch_up(controller,0))==MaaStatus_Succeeded;};
    io.target_present=[&](){return original_in_combat(false);};
    io.has_target=[&](){return target_locked(false)==1;};
    io.is_open_world_auto_combat=[&](){
        return !(feature("illusive_realm_exit",0.7) && active_slot()>0 && !feature("world_earth_icon",0.55));
    };
    io.find_character=[&](std::string_view name)->OriginalBaseChar*{
        for(int i=0;i<team_count;++i)if(members[i].definition && members[i].definition->class_name==name)return characters[i].get();
        return nullptr;
    };
    io.member_at=[&](int slot)->OriginalSwitchCharacter*{return slot>=1 && slot<=team_count && members[slot-1].definition?&members[slot-1]:nullptr;};
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
    auto choose_target=[&](int from,bool intro,bool low_con){
        return choose_original_switch_target(members,from,intro,low_con,seconds(),
            [&](const OriginalSwitchCharacter& candidate,const OriginalSwitchCharacter& current,bool has_intro,bool low,double){
                return characters[candidate.index]->get_switch_priority(characters[current.index].get(),has_intro,low);
            });
    };
    io.need_fast_perform=[&](){
        for(int i=0;i<team_count;++i)if(i!=current_slot-1 &&
            characters[i]->get_switch_priority(characters[current_slot-1].get(),false,false)>=400)return true;
        return false;
    };
    auto update_lib_portrait_icon=[&](){
        const char* names[]={"lib_ready_spectro","lib_ready_electric","lib_ready_fire","lib_ready_ice","lib_ready_wind","lib_ready_havoc"};
        for(int i=0;i<team_count;++i){
            auto& member=members[i];
            if(!member.is_current_char && member.ring_index>=0 && !member.cached_liberation_available &&
               feature_in_box(names[member.ring_index],"lib_mark_char_"+std::to_string(i+1),0.8))member.cached_liberation_available=true;
        }
    };
    bool last_switch_intro=false;
    io.last_switch_had_intro=[&](){return last_switch_intro;};
    io.switch_next_char=[&](bool free_intro,bool low_con){
        last_switch_intro=false;
        const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        const int from=current_slot-1;
        auto remaining=[&](){return std::max(0.0,std::chrono::duration<double>(deadline-std::chrono::steady_clock::now()).count());};
        auto reliable_snapshot=[&](){const int observed=active_slot();return observed>0 && hud_match.team_count==team_count &&
            observed<=team_count && characters[observed-1]!=nullptr;};
        while(!reliable_snapshot() && remaining()>0 && !stop_requested()){pause(std::min(0.05,remaining()),true);next_frame();}
        if(stop_requested())return false;
        if(remaining()<=0)throw OriginalNotInCombat("Switch timed out waiting for current character HUD");
        if(active_slot()!=current_slot)throw OriginalNotInCombat("Active character changed before switch; re-read team");
        update_lib_portrait_icon();
        double current_con=free_intro?0:characters[from]->current_con_for_switch();
        if(!free_intro && current_con>0.8 && current_con!=1){
            pause(std::min(0.05,remaining()),true);next_frame();current_con=characters[from]->current_con_for_switch();
        }
        bool intro=free_intro || current_con==1;
        int to=choose_target(from,intro,low_con);
        if(to<0 || to==from){characters[from]->attack_without_switch(0.2);return true;}
        double last_press=-10000;
        while(remaining()>0 && !stop_requested()){
            if(!(members[to].definition->class_name=="ShoreKeeper" && intro) && !io.target_present())
                throw OriginalNotInCombat("No longer in combat while switching");
            const int observed=active_slot();
            if(reliable_snapshot() && observed==to+1){
                io.in_liberation=false;
                characters[from]->switch_out(intro,seconds());
                for(int i=0;i<3;++i)members[i].is_current_char=i==to;
                members[to].has_intro=intro;members[to].has_sub_dps_intro=intro && members[from].is_sub_dps();
                members[to].last_switch_in_time=seconds();
                current_slot=to+1;current_slot_for_cd=current_slot;
                allow_short_target=members[to].definition->target_box_short_combat_check;
                checker.set_ring_index(members[to].ring_index);pixels_ready=false;
                if(intro){
                    const double now=seconds();
                    freeze_clock.add(now,characters[to]->intro_freeze_seconds(),-100,now);
                    members[from].last_outro_time=now;
                }else characters[from]->break_on_switch();
                last_switch_intro=intro;
                std::cout<<"original_switch from="<<from+1<<" to="<<to+1<<" intro="<<intro<<'\n';
                return true;
            }
            if(!reliable_snapshot()){pause(std::min(0.05,remaining()),true);next_frame();continue;}
            if(observed!=from+1)throw OriginalNotInCombat("Unexpected active character while switching; re-read team");
            update_lib_portrait_icon();
            const bool refreshed_intro=intro || characters[from]->con_full_for_switch();
            if(refreshed_intro!=intro){
                intro=refreshed_intro;to=choose_target(from,intro,low_con);
                if(to<0 || to==from){characters[from]->attack_without_switch(0.2);return true;}
            }
            if(remaining()<=0)return false;
            if(intro)characters[from]->break_on_switch();
            const bool saved_intro=members[to].has_intro,saved_sub=members[to].has_sub_dps_intro;
            members[to].has_intro=intro;members[to].has_sub_dps_intro=intro && members[from].is_sub_dps();
            bool wait=false;
            try{wait=characters[to]->wait_switch();}
            catch(...){members[to].has_intro=saved_intro;members[to].has_sub_dps_intro=saved_sub;throw;}
            members[to].has_intro=saved_intro;members[to].has_sub_dps_intro=saved_sub;
            if(remaining()<=0)return false;
            if(wait){mouse_click(0);pause(std::min(0.1,remaining()),true);next_frame();continue;}
            const double now=std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
            if(now-last_press>0.1){
                send_key('0'+to+1,0.02,-1,0);pause(0.001,true);last_press=now;
                mouse_click(0);pause(0.001,true);
            }
            next_frame();
        }
        if(!stop_requested())throw OriginalNotInCombat("Character switch timed out");
        return false;
    };
    auto switch_healer=[&](){
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
    io.select_character=[&](int slot){const int observed=select(slot);if(observed>0)update_current(observed);return observed>0;};
    load_chars=[&](){
        const int observed=active_slot();if(observed<1)return false;
        team_count=std::min(3,hud_match.team_count);
        const auto recognized=recognize_original_team([&](const char* file,CharacterBox box){
            const auto* original=find_original_box("box_char_"+std::to_string(
                box.y==original_character_boxes[0].y?1:box.y==original_character_boxes[1].y?2:3));
            const auto roi=original?scale_original_box(*original,hud_match.width,hud_match.height):
                ScreenBox{box.x,box.y,box.width,box.height};
            return hud_match.match(file,roi,0.6).score;
        },previous_team,team_count);
        const int detected_team=original_team_is(recognized,"Aemeath","Linnai","Mornye")?1:
            original_team_is(recognized,"Hiyuki","Lucilla","Chisa")?2:
            original_team_is(recognized,"Qingxiao","Denia","ShoreKeeper")?3:0;
        if(requested_team && detected_team!=requested_team)return false;
        for(int i=0;i<3;++i){
            if(i>=team_count){characters[i].reset();members[i]={};previous_team[i]={};continue;}
            const auto* definition=recognized[i].definition?recognized[i].definition:&unknown_character;
            const bool replace=!characters[i] || !recognized[i].reused || members[i].definition!=definition;
            if(replace){
                members[i]={};members[i].definition=definition;members[i].index=i;
                members[i].ring_index=int(definition->element)-1;
                members[i].elapsed_accounting_for_freeze=io.elapsed_accounting_for_freeze;
                if(definition->class_name=="Chisa" && config.chisa_dps)members[i].role_override=int(CharacterRole::MAIN_DPS);
                if(definition->class_name=="Iuno" && config.iuno_c6)members[i].role_override=int(CharacterRole::MAIN_DPS);
                characters[i]=make_original_character(definition->class_name,io,members[i]);
                std::cout<<"character_slot="<<i+1<<" class="<<definition->class_name<<" score="<<recognized[i].confidence<<'\n';
            }
            previous_team[i]=recognized[i];previous_team[i].definition=definition;
            characters[i]->reset_state();
        }
        update_current(observed);io.combat_start=seconds();
        return team_count>=2;
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
        combat_started=false;io.in_liberation=false;io.has_levitator=false;io.can_break=false;
        esc_count=0;original_cooldown.reset_combat();scene_combat=0;
    };
    original_in_combat=[&](bool target){
        in_sleep_check=true;
        struct CheckScope {bool& value;~CheckScope(){value=false;}} scope{in_sleep_check};
        if(io.in_liberation)return true;
        if(combat_started){
            if(scene_combat!=-1)return scene_combat==1;
            io.check_f_break_action();
            if(current_slot>0 && characters[current_slot-1] && characters[current_slot-1]->skip_combat_check()){
                scene_combat=1;return true;
            }
            if(target_locked(false)==1){scene_combat=1;return true;}
            // AutoCombatTask.on_combat_check returns true and has no combat_end_condition.
            if(acquire_target()){scene_combat=1;return true;}
            std::cout<<"original_combat_exit reason=target_enemy_failed\n";
            reset_combat();return false;
        }
        const bool chars_loaded=load_chars();
        const bool has_target=target_locked(false)==1;
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
    while(!stop_requested()){
        const double wait=0.1-(seconds()-last_trigger_time);
        if(wait>0)pause(wait,false);
        if(stop_requested())break;
        last_trigger_time=seconds();next_frame();
        if(active_slot()<1)continue;
        io.use_liberation=config.use_liberation;
        if(!io.use_liberation && !(feature("world_earth_icon",0.55) && active_slot()>0 &&
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
                characters[current_slot-1]->perform();++performances;
            }
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
            characters[current_slot-1]->on_combat_end();
            for(auto& character:characters)if(character)character->reset_state();
            switch_healer();
            std::cout<<"original_team performances="<<performances<<" continue_monitoring=1\n";
        }
    }
    return MaaStatus_Succeeded;
}

