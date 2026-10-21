#pragma once
#include "../official/OfficialTask.h"
#include "../task/OriginalFreeze.h"

namespace official_test {
using namespace official;
inline std::string json(const V& value){
    if(value.is_none())return "null";
    if(value.kind==V::Kind::boolean)return value.truth()?"true":"false";
    if(value.is_number())return value.text();
    if(value.kind==V::Kind::string){std::string out="\"";for(unsigned char c:value.text()){if(c=='\"'||c=='\\'){out+='\\';out+=c;}else if(c=='\n')out+="\\n";else if(c=='\r')out+="\\r";else if(c=='\t')out+="\\t";else out+=c;}return out+'\"';}
    if(value.sequence){std::string out="[";for(const auto& x:*value.sequence){if(out.size()>1)out+=',';out+=json(x);}return out+"]";}
    if(value.mapping){std::string out="{";for(const auto& x:*value.mapping){if(out.size()>1)out+=',';out+=json(x.first)+':'+json(x.second);}return out+"}";}
    return json(V(value.text()));
}
struct Fixture {
    OriginalCombatIO io{};
    std::array<OriginalSwitchCharacter,3> members{};
    std::array<std::unique_ptr<OfficialCharacter>,3> actors{};
    FrameState image{};
    V trace=V::list();
    double clock=100;
    int active=1,hidden=0,scenario=0,reads=0,count=3;
    std::array<double,3> cds{};
    OriginalFreezeClock freeze;
    bool constructing=true;
    double now(){clock+=0.001;return clock;}
    void event(std::initializer_list<V> values){if(!constructing)trace.sequence->push_back(V::list(values));if(trace.sequence->size()>6000)throw std::runtime_error("fixture operation budget");}
    void pause(double duration){event({V("sleep"),V(duration)});clock+=std::max(0.0,duration);}
    double cd(char key,int=0){return scenario==0?10.0:std::max(0.0,cds[key=='E'?0:key=='Q'?1:2]-clock);}
    bool send(int key,double down,double interval,double after){
        event({V("key"),V(std::string(1,static_cast<char>(key))),V(down),V(interval),V(after)});
        clock+=down;if(key>='1'&&key<='3')active=key-'0';
        if(key=='E'||key=='Q'||key=='R'){cds[key=='E'?0:key=='Q'?1:2]=clock+10;if(key=='R')hidden=3;}
        if(after>0)pause(after);return true;
    }
    FrameState frame(){if(++reads>50000)throw std::runtime_error("fixture observation budget");return image;}
    const CharacterDefinition* definition(std::string_view name){for(const auto& d:character_definitions)if(d.class_name==name)return &d;throw std::runtime_error("fixture character missing");}
    Fixture(const CharacterDefinition& d,int mode,int size=3):scenario(mode),count(size){
        image.width=1280;image.height=720;image.channels=3;image.pixels.bytes=std::make_shared<std::vector<unsigned char>>(1280*720*3,0);
        if(mode>0)for(const std::string name:{"box_resonance","box_echo","box_liberation"}){
            auto roi=scale_original_box(*find_original_box(name),1280,720);for(int y=roi.y;y<roi.y+roi.height;++y)for(int x=roi.x;x<roi.x+roi.width;++x)for(int c=0;c<3;++c)(*image.pixels.bytes)[(size_t(y)*1280+x)*3+c]=255;
        }
        image.concerto_coverage=mode==2?1:0;image.concerto_full=mode==2;image.concerto_color_index=0;
        io.seconds=[this](){return now();};io.stop_requested=[](){return false;};io.frame=[this](){return frame();};
        io.team_size=io.observed_team_count=[this](){return count;};io.active_slot=[this](){return hidden>0?-1:active;};
        io.member_at=[this](int slot){return slot>=1&&slot<=count?&members[slot-1]:nullptr;};
        io.find_character=[this](std::string_view name)->OriginalBaseChar*{for(auto& actor:actors)if(actor&&actor->member().definition->class_name==name)return actor.get();return nullptr;};
        io.template_frame=[](std::string_view){FrameState out;out.width=48;out.height=48;out.channels=3;out.pixels.bytes=std::make_shared<std::vector<unsigned char>>(48*48*3,0);return out;};
        io.recognize_feature=[](std::string_view,const ScreenBox*,double,const FrameState*){return OriginalFeatureObservation{};};
        io.next_frame=[this](){event({V("frame")});clock+=0.05;if(hidden>0)--hidden;};
        io.pause=[this](double d,bool){pause(d);};io.raw_sleep=[this](double d){event({V("raw_sleep"),V(d)});clock+=std::max(0.0,d);};
        io.send_physical_key=io.send_key_action=[this](int key,double down,double interval,double after){return send(key,down,interval,after);};
        io.physical_key_down=io.key_down_action=[this](int key){event({V("key_down"),V(std::string(1,static_cast<char>(key)))});return true;};
        io.physical_key_up=io.key_up_action=[this](int key){event({V("key_up"),V(std::string(1,static_cast<char>(key)))});return true;};
        io.click_action=[this](int button,double interval,double after){event({V("click"),V(button),V(interval),V(after)});clock+=0.01;if(after>0)pause(after);return true;};
        io.mouse_down=[this](){event({V("mouse_down")});return true;};io.mouse_up=[this](){event({V("mouse_up")});return true;};
        io.target_present=io.has_target=[](){return true;};io.is_open_world_auto_combat=[](){return true;};io.check_f_break_action=[](){return false;};
        io.find_mouse_forte=io.find_e_forte=[](){return false;};io.cooldown_remaining=[this](char key){return cd(key);};io.cooldown_for_slot=[this](char key,int slot){return cd(key,slot);};
        io.add_freeze_duration=[this](double start,double duration,double minimum){freeze.add(start,duration,minimum,now());};
        io.elapsed_accounting_for_freeze=[this](double start,bool intro){return freeze.elapsed(start,intro,now());};
        io.reload_characters=[](){return true;};io.use_liberation=true;io.auto_combat_task=true;io.combat_start=100;
        const CharacterDefinition* definitions[]={&d,definition(d.class_name=="Sanhua"?"Mortefi":"Sanhua"),definition(d.class_name=="Verina"?"ShoreKeeper":"Verina")};
        for(int i=0;i<count;++i){members[i].definition=definitions[i];members[i].index=i;members[i].elapsed_accounting_for_freeze=io.elapsed_accounting_for_freeze;actors[i]=std::make_unique<OfficialCharacter>(io,members[i],std::string(definitions[i]->class_name));}
        for(int i=0;i<count;++i){actors[i]->reset_state();members[i].is_current_char=i==0;members[i].has_intro=i==0&&mode==2;members[i].last_buff_time=i>0&&mode==2?99:-1;}
        clock=100;constructing=false;reads=0;
    }
    V run(){
        V result=V::dict();set_item(result,V("role"),V(std::string(members[0].definition->class_name)));set_item(result,V("scenario"),V(scenario));
        try{actors[0]->perform();set_item(result,V("error"),V{});}catch(const std::exception& e){set_item(result,V("error"),V(e.what()));}
        set_item(result,V("trace"),trace);V state=V::dict();for(const std::string name:{"last_res","last_echo","last_liberation","current_con","has_intro","is_current_char"})set_item(state,V(name),actors[0]->get(name));
        set_item(result,V("state"),state);return result;
    }
};
} // namespace official_test
