#define NOMINMAX
#include <Windows.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include "MaaFramework/MaaAPI.h"
template<class F> F api(HMODULE module,const char* name){return reinterpret_cast<F>(GetProcAddress(module,name));}
#include "../char/QingxiaoOriginal.h"
#include "../char/HsinOriginal.h"
#include "../char/HiyukiOriginal.h"
#include "../char/CartethyiaOriginal.h"
#include "../char/AemeathOriginal.h"
#include "../char/OriginalCharFactory.h"
#include "../task/SingleCharacterPolicy.h"
#include "../task/OriginalRetarget.h"

static void require(bool ok,const char* name){if(!ok)throw std::runtime_error(name);}
struct ExposedBaseChar : OriginalBaseChar {
    using OriginalBaseChar::OriginalBaseChar;
    using OriginalBaseChar::click_liberation;
};
struct Harness {
    double now=100;
    int slot=1,frames=0,keys=0,r_keys=0,e_keys=0,downs=0,ups=0,switches=0;
    bool stopped=false,held=false,free_intro=false;
    double e_cd=0,r_cd=0,q_cd=20,mouse_started=-1;
    std::map<std::string,bool> features;
    std::function<void()> on_frame=[]{};
    std::function<void(int)> on_key=[](int){};
    std::function<void(int)> on_click=[](int){};
    FrameState image{};
    CharacterDefinition definition{"Test","",nullptr,"",nullptr,CharacterRole::MAIN_DPS,CharacterElement::FIRE,20,false};
    std::array<OriginalSwitchCharacter,3> members{};
    OriginalCombatIO io{};
    Harness(){
        image.width=1280;image.height=720;image.channels=3;
        image.resonance_white=1;image.liberation_white=1;
        for(int i=0;i<3;++i){members[i].definition=&definition;members[i].index=i;members[i].last_buff_time=90;}
        members[0].has_intro=true;members[0].is_current_char=true;
        io.frame=[&]{return image;};
        io.active_slot=[&]{return slot;};
        io.seconds=[&]{return now;};
        io.frame_captured_at=[&]{return now;};
        io.stop_requested=[&]{return stopped;};
        io.next_frame=[&]{now+=0.05;++frames;on_frame();};
        io.pause=[&](double s,bool){now+=std::max(0.001,s);};
        io.elapsed_accounting_for_freeze=[&](double start,bool){return start<0?10000:now-start;};
        io.add_freeze_duration=[](double,double,double){};
        io.target_present=[]{return true;};
        io.has_target=[]{return true;};
        io.team_size=[]{return 3;};
        io.member_at=[&](int s){return s>=1 && s<=3?&members[s-1]:nullptr;};
        io.feature=[&](std::string_view name,double){return features[std::string(name)];};
        io.feature_in_box=[&](std::string_view name,std::string_view box,double){
            if(name=="forte_cartethyia_sword3_half")return features["cartethyia_base_form"];
            return features[std::string(box)];
        };
        io.feature_at=[](std::string_view,ScreenBox,double){return false;};
        io.check_f_break_action=[]{return false;};
        io.find_mouse_forte=[]{return false;};
        io.find_e_forte=[]{return false;};
        io.cooldown_remaining=[&](char key){return key=='E'?e_cd:key=='R'?r_cd:q_cd;};
        io.cooldown_for_slot=[&](char key,int){return io.cooldown_remaining(key);};
        io.send_key_action=[&](int key,double,double,double){++keys;if(key=='R')++r_keys;if(key=='E')++e_keys;on_key(key);return true;};
        io.key_down_action=[&](int key){held=true;++downs;if(key=='R')++r_keys;on_key(key);return true;};
        io.key_up_action=[&](int){held=false;++ups;return true;};
        io.mouse_down=[&]{held=true;++downs;mouse_started=now;return true;};
        io.mouse_up=[&]{held=false;++ups;return true;};
        io.click_action=[&](int button,double,double){on_click(button);return true;};
        io.switch_next_char=[&](bool free,bool){++switches;free_intro=free;return true;};
        io.select_character=[](int){return true;};
        io.find_character=[](std::string_view)->OriginalBaseChar*{return nullptr;};
        io.need_fast_perform=[]{return false;};
        io.last_switch_had_intro=[]{return false;};
        io.is_open_world_auto_combat=[]{return true;};
    }
};

struct RetargetHarness {
    double now=0,found_at=1e9,stop_at=1e9;
    int health_checks=0;
    std::function<bool(double)> health=[](double){return true;};
    OriginalRetargetIO io;
    RetargetHarness(){
        io.seconds=[&]{return now;};io.stopped=[&]{return now>=stop_at;};
        io.has_target=[&]{return now>=found_at;};io.middle_click=[]{};
        io.next_frame=[&]{now+=0.05;};io.check_health=[&]{++health_checks;return health(now);};
    }
};

static void emit_skill(Harness& h,int key,int& animation_frame){
 if(key=='E')h.e_cd=20;
 if(key=='R'){h.r_cd=20;h.image.liberation_white=0;h.slot=0;animation_frame=h.frames;}
}
static void finish_animation(Harness& h,int animation_frame){
 if(h.r_keys && h.frames-animation_frame>=4)h.slot=1;
}
int main(){try{
 int passed=0;
 {OriginalStableHud visible;
  require(!visible.observe(1,10,13) && !visible.observe(1,10.2,13) &&
      visible.observe(2,10.25,13),"HUD confirmation counted multiple reads of one capture");++passed;}
 {OriginalStableHud visible;
  require(!visible.observe(1,10,13) && !visible.observe(2,10.1,0) &&
      !visible.observe(3,10.2,13) && visible.observe(4,10.3,13),
      "HUD confirmation retained a one-frame return across another hidden frame");++passed;}
 {OriginalRosterConfirmation roster;
  require(roster.observe("Qingxiao;Lucilla;Chisa;",3,1,10),"initial party loading was delayed");
  require(!roster.observe("Yuanwu;",1,2,10.1) && !roster.observe("Yuanwu;",1,3,10.3) &&
      roster.observe("Qingxiao;Lucilla;Chisa;",3,4,10.304) &&
      roster.accepted=="3:Qingxiao;Lucilla;Chisa;","0.204s solo false positive erased the accepted party");++passed;}
 {OriginalRosterConfirmation roster;
  require(!roster.observe("Aemeath;",1,1,10) && !roster.observe("Aemeath;",1,2,10.2) &&
      roster.observe("Aemeath;",1,3,10.4),"genuine solo roster could not be confirmed");
  require(!roster.observe("Aemeath;Linnai;Mornye;",3,4,11) &&
      !roster.observe("Aemeath;Linnai;Mornye;",3,5,11.2) &&
      roster.observe("Aemeath;Linnai;Mornye;",3,6,11.4),"normal party could not replace genuine solo");++passed;}
 {OriginalRosterConfirmation roster;
  require(!roster.observe("Baizhi;",1,1,10),"new solo accepted one frame");roster.reject();
  require(!roster.observe("Baizhi;",1,2,10.3) && !roster.observe("Baizhi;",1,2,10.8),
      "roster confirmation bridged an invalid frame or counted a cached image");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);h.slot=0;bool suspended=false;
  try{actor.click_liberation();}catch(const OriginalHudUnavailable&){suspended=true;}
  require(suspended && h.r_keys==0 && h.members[0].last_liberation==-10000,
      "a pre-existing hidden HUD sent or confirmed R");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);
  h.on_key=[&](int key){if(key=='R'){h.r_cd=20;h.image.liberation_white=0;}};
  h.on_frame=[&]{h.slot=h.frames==1?0:1;};
  require(!actor.click_liberation() && h.r_keys==1 && h.members[0].last_liberation==-10000,
      "one missing HUD frame confirmed a liberation");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);int animation_frame=0;
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{h.slot=h.frames==4 || h.frames>=11?1:0;};
  require(actor.click_liberation() && h.frames>=12 && h.r_keys==1,
      "one visible HUD frame ended the liberation animation early");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);int animation_frame=0;
  h.on_key=[&](int key){if(key=='R' && h.r_keys==1)h.image.liberation_white=0;
      else emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.r_keys==1 && h.frames>=3)h.image.liberation_white=1;finish_animation(h,animation_frame);};
  require(actor.click_liberation() && h.r_keys==2 && h.frames<20,
      "ready/unconsumed R did not get its bounded recovery press");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);int animation_frame=0;bool stopped=false;
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.frames>=3)h.stopped=true;};
  try{actor.click_liberation();}catch(const OriginalCombatStopped&){stopped=true;}
  require(stopped && !h.io.in_liberation && h.members[0].last_liberation==-10000,
      "stop during R left animation protection or a fabricated completed cast");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);bool suspended=false;
  h.io.capture_valid=[&]{return h.frames==0;};
  h.on_key=[&](int key){if(key=='R')h.image.liberation_white=0;};
  try{actor.click_liberation();}catch(const OriginalHudUnavailable&){suspended=true;}
  require(suspended && h.r_keys==1 && !h.io.in_liberation && h.members[0].last_liberation==-10000,
      "a failed capture was accepted as an R animation");++passed;}
 {Harness h;ExposedBaseChar actor(h.io,h.members[0]);h.members[0].cached_liberation_available=true;
  h.on_key=[&](int key){if(key=='R'){h.r_cd=20;h.image.liberation_white=0;}};
  require(!actor.click_liberation() && h.r_keys==1 && !h.members[0].cached_liberation_available &&
      h.members[0].last_liberation==-10000,"unconfirmed R retained ready cache or recorded a cast");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);int animation_frame=0,normal=0;
  h.on_click=[&](int button){if(button==0){++normal;h.features[normal==1?"qingxiao_h1":"qingxiao_h2"]=true;}};
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.downs==1)h.features["qingxiao_h1"]=false;if(h.downs>=2)h.features["qingxiao_h2"]=false;finish_animation(h,animation_frame);};
  actor.do_perform();require(normal==2 && h.downs==2 && h.ups==2 && h.r_keys==1 && h.switches==1 && !h.held,"Qingxiao original click/H1/H2/R order mismatch");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);int animation_frame=0;
  h.features["qingxiao_h2"]=true;h.image.liberation_white=0;const double start=h.now;
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.downs)h.features["qingxiao_h2"]=false;if(!h.r_keys && h.now-start>=1)h.image.liberation_white=1;finish_animation(h,animation_frame);};
  actor.do_perform();require(h.r_keys==1 && h.now-start>=1 && h.switches==1,"Qingxiao omitted official 1.5s H2 energy wait");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);h.members[0].has_intro=false;
  actor.do_perform();require(h.r_keys==0 && h.downs==0 && h.switches==1,"Qingxiao original buff/intro gate removed");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);int animation_frame=0;bool interrupted=false,fail_once=true;
  h.features["qingxiao_h2"]=true;
  h.io.require_combat_hud=[&]{if(fail_once){fail_once=false;throw OriginalHudUnavailable();}};
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.downs)h.features["qingxiao_h2"]=false;finish_animation(h,animation_frame);};
  try{actor.do_perform();}catch(const OriginalHudUnavailable&){interrupted=true;}
  require(interrupted && h.downs==1 && h.ups==1 && h.r_keys==0 && h.switches==0,
      "Qingxiao did not retain an interrupted confirmed H2");
  h.members[1].last_buff_time=h.members[2].last_buff_time=-1;actor.do_perform();
  require(h.downs==1 && h.r_keys==1 && h.switches==1,
      "Qingxiao replayed H2 or lost pending R when support buffs expired during HUD recovery");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);int animation_frame=0;bool interrupted=false;
  h.features["qingxiao_h2"]=true;h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{if(h.downs)h.features["qingxiao_h2"]=false;finish_animation(h,animation_frame);};
  h.io.switch_next_char=[](bool,bool)->bool{throw OriginalHudUnavailable();};
  try{actor.do_perform();}catch(const OriginalHudUnavailable&){interrupted=true;}
  require(interrupted && h.r_keys==1 && h.downs==1,"Qingxiao handoff interruption fixture failed");
  h.io.switch_next_char=[&](bool,bool){++h.switches;return true;};actor.do_perform();
  require(h.r_keys==1 && h.downs==1 && h.switches==1,
      "Qingxiao repeated a completed R after the handoff HUD failed");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);h.features["qingxiao_h2"]=true;
  h.io.require_combat_hud=[]{throw OriginalHudUnavailable();};
  h.on_frame=[&]{if(h.downs)h.features["qingxiao_h2"]=false;};
  try{actor.do_perform();}catch(const OriginalHudUnavailable&){}
  actor.reset_state();h.io.require_combat_hud={};actor.do_perform();
  require(h.r_keys==0 && h.downs==1 && h.switches==1,"new combat retained a previous Qingxiao H2 checkpoint");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);h.features["qingxiao_h2"]=true;
  h.io.require_combat_hud=[]{throw OriginalHudUnavailable();};
  h.on_frame=[&]{if(h.downs)h.features["qingxiao_h2"]=false;};
  try{actor.do_perform();}catch(const OriginalHudUnavailable&){}
  h.now+=19;h.io.require_combat_hud={};actor.do_perform();
  require(h.r_keys==0 && h.downs==1 && h.switches==1,"expired Qingxiao checkpoint sent a stale R");++passed;}
 {Harness h;QingxiaoOriginal actor(h.io,h.members[0]);h.features["qingxiao_h2"]=true;
  actor.do_perform();require(h.r_keys==0 && h.downs==h.ups && !h.held && h.switches==1,
      "unconsumed H2 advanced to R or retained a held attack");++passed;}
 {Harness h;AemeathOriginal actor(h.io,h.members[0]);h.members[0].has_intro=false;
  h.members[1].role_override=int(CharacterRole::SUB_DPS);
  actor.do_perform();require(h.r_keys==0 && h.e_keys==0 && h.switches==1,"Aemeath used custom solo axis for a normal party");++passed;}
 {Harness h;AemeathOriginal actor(h.io,h.members[0]);int animation_frame=0;h.features["aemeath_lib2"]=true;
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};h.on_frame=[&]{finish_animation(h,animation_frame);};
  actor.do_perform();require(h.r_keys==1 && h.switches==1,"Aemeath official ready Lib2 handoff failed");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);int animation_frame=0;std::string skill_order;h.features["hsin_lib2"]=true;
  h.on_key=[&](int key){if(key=='E'||key=='R')skill_order+=char(key);emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{finish_animation(h,animation_frame);};actor.do_perform();
  require(skill_order=="R" && h.switches==1,"master Hsin ready R2 did not take priority over E");++passed;}
 {Harness h;AemeathOriginal actor(h.io,h.members[0]);int animation_frame=0;
  h.members[0].has_intro=false;h.members[1].role_override=h.members[2].role_override=int(CharacterRole::HEALER);
  h.features["aemeath_lib2"]=true;h.on_key=[&](int key){emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{finish_animation(h,animation_frame);};
  require(!actor.waits_for_intro(),"Aemeath double-support field condition missing");
  actor.do_perform();require(h.r_keys==1 && h.switches==1,"Aemeath without sub-DPS incorrectly waited for intro");++passed;}
 {Harness h;MornyeOriginal actor(h.io,h.members[0]);h.q_cd=0;h.image.echo_white=0;
  require(!actor.detect_elbow_strike(),"Mornye initial dark icon incorrectly detected a strike");
  h.image.echo_white=1;require(!actor.detect_elbow_strike(),"Mornye lit icon detected a strike");
  h.image.echo_white=0;require(actor.detect_elbow_strike(),"Mornye did not remember an icon lighting up later in flight");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);actor.finisher_start=h.now;int animation_frame=0;double r_at=0;
  h.features["hsin_h2"]=true;h.image.liberation_white=0;
  h.io.frame=[&]{if(h.mouse_started>=0 && !h.r_keys && h.now-h.mouse_started>=3)h.image.liberation_white=1;return h.image;};
  h.io.target_present=[&]{return h.mouse_started<0 || actor.skip_combat_check() || h.r_keys>0;};
  h.on_key=[&](int key){if(key=='R')r_at=h.now;emit_skill(h,key,animation_frame);};
  h.on_frame=[&]{
   if(h.mouse_started>=0){h.features["hsin_h2"]=h.now-h.mouse_started<0.4;
    if(!h.r_keys && h.now-h.mouse_started>=3)h.image.liberation_white=1;}
   finish_animation(h,animation_frame);
  };
  actor.perform_everything();
  require(actor.h2_completed && actor.lib2_cast_this_turn && h.r_keys==1 && h.e_keys==0 &&
      r_at-h.mouse_started>=3 && !h.held && !actor.skip_combat_check(),"Hsin H2 target loss did not preserve delayed generic R2");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);h.features["hsin_h2"]=true;
  require(!actor.handle_heavy() && !actor.h2_completed && !h.held && h.ups==1 &&
      !actor.skip_combat_check(),"failed Hsin H2 retained success, input, or protection");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);h.features["hsin_h1"]=true;const double start=h.now;
  h.on_frame=[&]{const double elapsed=h.now-start;h.features["hsin_h1"]=elapsed<0.4 && !(elapsed>0.09 && elapsed<0.14);};
  require(actor.handle_heavy() && h.now-start>=0.65 && !h.held && !actor.skip_combat_check(),
      "Hsin H1 accepted a brief disappearance or acquired H2 protection");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);h.features["hsin_h2"]=true;bool threw=false;
  h.on_frame=[&]{throw std::runtime_error("fixture frame error");};
  try{actor.handle_heavy();}catch(const std::runtime_error&){threw=true;}
  require(threw && h.downs==1 && h.ups==1 && !h.held && !actor.skip_combat_check(),
      "Hsin exception did not release heavy input and protection");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);h.features["hsin_h2"]=true;bool threw=false;
  h.io.target_present=[]{return false;};
  try{actor.handle_heavy();}catch(const OriginalNotInCombat&){threw=true;}
  require(threw && h.downs==0 && !actor.skip_combat_check(),"Hsin H2 bypassed its initial combat check");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);std::vector<double> keys;
  h.io.find_e_forte=[&]{return h.e_keys<2;};h.on_key=[&](int key){if(key=='E')keys.push_back(h.now);};
  require(actor.cast_enhanced_e() && actor.finisher_e_sent && keys.size()==2 &&
      keys[1]-keys[0]>=0.25 && h.now-keys[1]>=0.25,"Hsin enhanced E retry/consumption confirmation mismatch");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);const double start=h.now;
  require(!actor.cast_enhanced_e() && !actor.finisher_e_sent && h.e_keys==0 &&
      h.now-start>=1.5 && h.now-start<1.7,"Hsin absent enhanced E prompt sent keys or escaped timeout");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);const double start=h.now;
  h.io.find_e_forte=[&]{const double elapsed=h.now-start;return elapsed<0.6 && !(elapsed>0.09 && elapsed<0.19);};
  require(actor.cast_enhanced_e() && h.now-start>=0.84 && actor.finisher_e_sent,
      "Hsin enhanced E brief disappearance counted as consumption");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);actor.finisher_start=h.now;actor.h2_completed=true;
  h.image.liberation_white=0;h.r_cd=20;actor.perform_everything();
  require(h.keys==0 && actor.h2_completed && !actor.lib2_cast_this_turn && h.now>=118 && h.now<118.25,
      "Hsin confirmed H2 resumed E/Q or lost its 18s finishing budget");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);int animation_frame=0;h.features["hsin_lib1"]=true;
  h.on_key=[&](int key){emit_skill(h,key,animation_frame);};h.on_frame=[&]{finish_animation(h,animation_frame);};
  require(actor.lib() && bool(actor.finisher_start),"Hsin confirmed R1 failed to start finishing budget");
  const double start=*actor.finisher_start;h.now+=1;h.r_cd=0;h.image.liberation_white=1;
  require(actor.lib() && *actor.finisher_start==start,"Hsin R1 restarted an existing finishing budget");++passed;}
 {Harness h;HsinOriginal actor(h.io,h.members[0]);h.features["hsin_h2"]=true;
  h.on_frame=[&]{if(h.mouse_started>=0 && h.now-h.mouse_started>=0.4)h.features["hsin_h2"]=false;};
  require(actor.handle_heavy() && actor.skip_combat_check(),"Hsin confirmed H2 did not start its guard");
  h.now+=4;require(!actor.skip_combat_check(),"Hsin H2 guard became unbounded");++passed;}
 {const auto initial=original_retarget_settings(false,true),empty=original_retarget_settings(true,false),
       healthy=original_retarget_settings(true,true);
  require(initial.timeout==3 && !initial.check_health && empty.timeout==3 && !empty.check_health &&
      healthy.timeout==30 && healthy.check_health,"master health-dependent retarget policy mismatch");++passed;}
 {RetargetHarness h;h.health=[](double){return false;};const auto r=original_target_enemy(h.io,30,true);
  require(r.reason==OriginalRetargetExit::health_lost && r.elapsed>1.2 && r.elapsed<1.5,
      "retarget did not stop after 1.2s continuous health loss");++passed;}
 {RetargetHarness h;const auto r=original_target_enemy(h.io,30,true);
  require(r.reason==OriginalRetargetExit::timeout && r.elapsed>=30 && r.elapsed<30.1,
      "healthy retarget escaped its 30s deadline");++passed;}
 {RetargetHarness h;h.health=[](double){return false;};const auto r=original_target_enemy(h.io,3,false);
  require(r.reason==OriginalRetargetExit::timeout && r.elapsed>=3 && r.elapsed<3.1 && h.health_checks==0,
      "ordinary retarget changed its 3s/no-health-check path");++passed;}
 {RetargetHarness h;h.found_at=0.65;const auto r=original_target_enemy(h.io,30,true);
  require(r.locked && r.reason==OriginalRetargetExit::found && r.elapsed<1,
      "retarget did not return immediately after finding target");++passed;}
 {RetargetHarness h;h.health=[](double now){return now>=0.8 && now<1;};const auto r=original_target_enemy(h.io,30,true);
  require(r.reason==OriginalRetargetExit::health_lost && r.elapsed>=2.2 && r.elapsed<2.5,
      "retarget health-loss timer did not reset when bar returned");++passed;}
 {RetargetHarness h;h.stop_at=0.5;const auto r=original_target_enemy(h.io,30,true);
  require(r.reason==OriginalRetargetExit::stopped && r.elapsed<0.6,"retarget ignored user stop");++passed;}
 {Harness h;RoverOriginal actor(h.io,h.members[0]);int animation_frame=0;bool e_forte=true;double e_hold=0;
  h.image.concerto_color_index=1;h.image.forte_white=0.1;h.image.concerto_full=true;
  h.io.find_e_forte=[&]{return e_forte;};
  h.io.send_key_action=[&](int key,double down,double,double){++h.keys;if(key=='E'){++h.e_keys;e_hold=down;e_forte=false;h.image.forte_white=0;}if(key=='R')++h.r_keys;emit_skill(h,key,animation_frame);return true;};
  h.on_frame=[&]{finish_animation(h,animation_frame);};actor.do_perform();
  require(h.e_keys==1 && e_hold==0.05 && actor.known_form()==1 && h.switches==1 && h.members[0].effective_role()==CharacterRole::SUB_DPS,"v3.7.4 Electro Rover routine/hold/role mismatch");++passed;}
 {Harness h;SingleCharacterPolicy policy;
  require(policy.bind(1,1,"Qingxiao") && policy.enabled,"single-member support missing");
  require(policy.bind(2,2,"Linnai") && !policy.enabled && policy.allows(1),"two-member party retained a role lock");
  require(policy.bind(3,3,"ShoreKeeper") && !policy.enabled && policy.allows(2),"three-member party retained a role lock");++passed;}
 {int count=0;for(const auto& definition:character_definitions){Harness h;h.members[0].definition=&definition;
  auto actor=make_original_character(definition.class_name,h.io,h.members[0]);
  require(actor && typeid(*actor)!=typeid(OriginalBaseChar),"character factory fell back to generic base");++count;}
  require(count==52,"official character registry count changed");std::cout<<"upstream_registry characters="<<count<<" input_sent_to_game=0\n";++passed;}
 std::cout<<"upstream_contract_tests passed="<<passed<<" input_sent_to_game=0\n";return 0;
}catch(const std::exception& error){std::cerr<<"FAIL "<<error.what()<<'\n';return 1;}}
