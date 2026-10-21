#include "OfficialTask.h"
#include <set>

namespace official {
V BoxObject::get(const std::string& key){
    if(key=="x")return V(box.x);if(key=="y")return V(box.y);if(key=="width")return V(box.width);if(key=="height")return V(box.height);if(key=="name")return V(name);if(key=="confidence")return V(confidence);
    if(key=="copy")return V::function([copy=*this](const Args&){return V(std::make_shared<BoxObject>(copy));});
    if(key=="crop_frame")return V::function([bounds=box](const Args& a){return array(a.get(0,"frame"))->at(V::tuple({V::slice(V(bounds.y),V(bounds.y+bounds.height),V{}),V::slice(V(bounds.x),V(bounds.x+bounds.width),V{})}));});
    return Object::get(key);
}
void BoxObject::set(const std::string& key,V value){if(key=="x")box.x=static_cast<int>(value.integral());else if(key=="y")box.y=static_cast<int>(value.integral());else if(key=="width")box.width=static_cast<int>(value.integral());else if(key=="height")box.height=static_cast<int>(value.integral());else if(key=="name")name=value.text();else if(key=="confidence")confidence=value.numeric();else Object::set(key,std::move(value));}
static char cooldown_key(const V& value){const auto name=value.text();if(name=="resonance"||name=="box_resonance")return 'E';if(name=="echo"||name=="box_echo")return 'Q';if(name=="liberation"||name=="box_liberation")return 'R';throw ValueError("unmapped cooldown key "+name);}
static int input_key(const V& value){std::string key=value.is_number()?std::to_string(value.integral()):value.text();std::transform(key.begin(),key.end(),key.begin(),[](unsigned char c){return static_cast<char>(std::toupper(c));});if(key.size()==1)return static_cast<unsigned char>(key[0]);if(key=="SPACE")return VK_SPACE;if(key=="ESC"||key=="ESCAPE")return VK_ESCAPE;if(key=="SHIFT")return VK_SHIFT;if(key=="CTRL"||key=="CONTROL")return VK_CONTROL;if(key=="TAB")return VK_TAB;throw ValueError("unmapped official input key "+key);}
V TaskObject::current_character(){const V chars=owner.team_values();for(const auto& value:*chars.sequence)if(!value.is_none()&&attr(value,"is_current_char").truth())return value;return V{};}
V TaskObject::get_box(const V& value){if(value.kind==V::Kind::object&&std::dynamic_pointer_cast<BoxObject>(value.object))return value;const std::string name=value.text();const auto* box=find_original_box(name);if(!box)throw AttributeError("official ROI missing: "+name);const auto frame=owner.io().frame();return box_value(scale_original_box(*box,frame.width,frame.height),name);}
V TaskObject::get(const std::string& name){
    auto& io=owner.io();
    if(const auto method=methods_.find(name);method!=methods_.end())return V::function([this,body=method->second](const Args& args){
        if(owner.io().stop_requested())throw OriginalCombatStopped();Args actual;actual.pos(self_value());actual.positional.insert(actual.positional.end(),args.positional.begin(),args.positional.end());actual.keywords=args.keywords;return invoke(body,actual);
    });
    if(name=="switch_char_time_out")return V(5);
    if(name=="log_debug")return V::function([](const Args&){return V{};});
    if(name=="__class__")return V(std::make_shared<ClassToken>("AutoCombatTask"));
    if(name=="chars")return owner.team_values();
    if(name=="frame")return array_from_frame(io.frame())->value();
    if(name=="in_liberation")return V(io.in_liberation);
    if(name=="skip_combat_check")return V(io.skip_combat_check);
    if(name=="use_liberation")return V(io.use_liberation);
    if(name=="has_lavitator")return V(io.has_levitator);
    if(name=="can_break")return V(io.can_break);
    if(name=="combat_start")return V(io.combat_start);
    if(name=="name")return V("AutoCombatTask");
    if(name=="debug")return V(false);
    if(name=="char_config"){V out=V::dict();set_item(out,V("Chisa DPS"),V(io.chisa_dps));set_item(out,V("Iuno C6"),V(io.iuno_c6));return out;}
    if(name=="key_config"){V out=V::dict();for(const auto& entry:std::initializer_list<std::pair<const char*,char>>{{"Tool Key",'T'},{"Resonance Key",'E'},{"Echo Key",'Q'},{"Liberation Key",'R'}}){const int key=io.configured_key?io.configured_key(entry.second):entry.second;set_item(out,V(entry.first),V(std::string(1,static_cast<char>(key))));}return out;}
    static const std::set<std::string> methods={"wait_until","next_frame","find_one","mouse_up","mouse_down","in_team","box_of_screen_scaled","click","calculate_color_percentage","send_key","has_char","draw_boxes","get_box_by_name","send_key_down","send_key_up","raise_not_in_combat","in_team_and_world","get_target_names","has_cd","screenshot","jump","f_break","wait_in_team_and_world","find_best_match_in_box","get_cd","find_feature","check_f_break","is_open_world_auto_combat","get_current_con","get_current_char","get_feature_by_name","middle_click_relative","switch_next_char","sleep","log_error","check_combat","add_freeze_duration","time_elapsed_accounting_for_freeze","get_liberation_key","get_echo_key","get_resonance_key","is_con_full","find_mouse_forte","find_e_forte","available","has_short_action","box_highlighted","has_target","load_chars","_ensure_ring_index","info_set","tr"};
    if(!methods.count(name))return Object::get(name);
    return V::function([this,name](const Args& args){if(name!="mouse_up"&&name!="send_key_up"&&owner.io().stop_requested())throw OriginalCombatStopped();return invoke_task(name,args);});
}
void TaskObject::set(const std::string& name,V value){auto& io=owner.io();if(name=="in_liberation")io.in_liberation=value.truth();else if(name=="skip_combat_check")io.skip_combat_check=value.truth();else if(name=="use_liberation")io.use_liberation=value.truth();else if(name=="has_lavitator")io.has_levitator=value.truth();else if(name=="can_break")io.can_break=value.truth();else Object::set(name,std::move(value));}
static FrameState template_pixels(const V& value){const auto source=array(value);if(source->shape.size()!=3||source->shape[2]!=3)throw TypeError("official image template must be BGR");FrameState out;out.height=source->shape[0];out.width=source->shape[1];out.channels=3;out.pixels.bytes=std::make_shared<std::vector<unsigned char>>(source->size());for(size_t i=0;i<source->size();++i)(*out.pixels.bytes)[i]=static_cast<unsigned char>(source->number_at(i));return out;}
V TaskObject::find_one(const Args& args,bool best){
    auto& io=owner.io();if(!io.recognize_feature)throw std::runtime_error("Maa official feature binding is unavailable");
    const V requested=args.get(best?1:0,best?"feature_names":"feature_name",V{});
    const V box_input=args.get(best?0:5,"box",V{}),custom=args.get(10,"template",V{});const double threshold=args.get(best?2:3,"threshold",V(0.8)).numeric();
    std::shared_ptr<BoxObject> roi;if(!box_input.is_none())roi=box_object(get_box(box_input));else if(requested.kind==V::Kind::object)roi=std::dynamic_pointer_cast<BoxObject>(requested.object);
    if(!custom.is_none()){const auto pixels=template_pixels(custom);if(!roi)throw TypeError("custom template needs an explicit ROI");const auto result=io.recognize_feature("",&roi->box,threshold,&pixels);return result.found?box_value(result.box,result.name,result.confidence):V{};}
    V names=requested.sequence?requested:V::list({requested});OriginalFeatureObservation selected;
    for(const auto& name:*names.sequence){const auto result=io.recognize_feature(name.text(),roi?&roi->box:nullptr,threshold,nullptr);if(result.found&&(!selected.found||result.confidence>selected.confidence))selected=result;if(result.found&&!best)break;}
    return selected.found?box_value(selected.box,selected.name,selected.confidence):V{};
}
V TaskObject::invoke_task(const std::string& method,const Args& a){
    auto& io=owner.io();
    if(method=="next_frame"){io.next_frame();return array_from_frame(io.frame())->value();}
    if(method=="sleep"){io.pause(a.get(0,"sec").numeric(),true);return V(true);}
    if(method=="send_key"){const bool sent=(io.send_physical_key?io.send_physical_key:io.send_key_action)(input_key(a.get(0,"key")),a.get(1,"down_time",V(0.02)).numeric(),a.get(2,"interval",V(-1)).numeric(),a.get(3,"after_sleep",V(0)).numeric());return V(sent);}
    if(method=="send_key_down"){const int key=input_key(a.get(0,"key"));if(io.physical_key_down)io.physical_key_down(key);else io.key_down(key);const double after=a.get(1,"after_sleep",V(0)).numeric();if(after>0)io.pause(after,true);return V{};}
    if(method=="send_key_up"){const int key=input_key(a.get(0,"key"));if(io.physical_key_up)io.physical_key_up(key);else io.key_up(key);const double after=a.get(1,"after_sleep",V(0)).numeric();if(after>0)io.pause(after,true);return V{};}
    if(method=="mouse_down"){io.mouse_down();return V{};}
    if(method=="mouse_up"){io.mouse_up();return V{};}
    if(method=="click"){
        const double x=a.get(0,"x",V(-1)).numeric(),y=a.get(1,"y",V(-1)).numeric();
        if(x!=-1||y!=-1)throw TypeError("unmapped official coordinate click");
        const auto key=a.get(8,"key",V("left")).text();const auto interval=a.get(4,"interval",V(-1)).numeric(),after=a.get(7,"after_sleep",V(0)).numeric();
        return V(key=="right"?io.right_click(interval,after):key=="middle"?io.middle_click(interval,after):io.click(interval,after));
    }
    if(method=="middle_click_relative"){if(a.get(0,"x").numeric()!=0.5||a.get(1,"y").numeric()!=0.5)throw TypeError("unmapped official relative click coordinate");io.middle_click(-1,0);return V{};}
    if(method=="jump"){io.jump(a.get(0,"after_sleep",V(0.01)).numeric());return V{};}
    if(method=="get_liberation_key"||method=="get_echo_key"||method=="get_resonance_key"){const char logical=method=="get_liberation_key"?'R':method=="get_echo_key"?'Q':'E';return V(std::string(1,static_cast<char>(io.configured_key?io.configured_key(logical):logical)));}
    if(method=="in_team"){const int observed=io.active_slot();return V::tuple({V(observed>0),V(observed>0?observed-1:-1),V(io.observed_team_count?io.observed_team_count():io.team_size())});}
    if(method=="in_team_and_world")return V(io.active_slot()>0);
    if(method=="is_open_world_auto_combat")return V(io.is_open_world_auto_combat());
    if(method=="has_target")return V(io.has_target());
    if(method=="check_combat"){if(!io.in_liberation&&!io.skip_combat_check&&!io.target_present())throw OriginalNotInCombat("Official check_combat: target lost");return V{};}
    if(method=="raise_not_in_combat")throw OriginalNotInCombat(a.get(0,"reason",V("official combat ended")).text().c_str());
    if(method=="get_current_char"){V current=current_character();if(current.is_none()&&a.get(0,"raise_exception",V(false)).truth()&&io.active_slot()<1)throw OriginalNotInCombat("Official current character HUD is absent");return current;}
    if(method=="has_char"){const auto token=std::dynamic_pointer_cast<ClassToken>(a.get(0,"char_cls").object);if(!token)throw TypeError("has_char requires an official class");return OfficialCharacter::from(io.find_character(token->name));}
    if(method=="load_chars"){if(!io.reload_characters)throw std::runtime_error("Maa official reload binding is unavailable");io.reload_characters();return V{};}
    if(method=="_ensure_ring_index"){V current=current_character();if(current.is_none())return V(-1);if(attr(current,"ring_index").numeric()<0){const auto frame=io.frame();set_attr(current,"ring_index",V(frame.concerto_color_index<0?0:frame.concerto_color_index));}return attr(current,"ring_index");}
    if(method=="get_current_con"){const auto frame=io.frame();return V(frame.concerto_full?1.0:frame.concerto_coverage);}
    if(method=="is_con_full")return V(io.frame().concerto_full);
    if(method=="get_cd"||method=="has_cd"){
        const char key=cooldown_key(a.get(0,"box_name"));const V index=a.get(1,"char_index",V{});const double remaining=index.is_none()?io.cooldown_remaining(key):io.cooldown_for_slot(key,static_cast<int>(index.integral())+1);return method=="has_cd"?V(remaining>0.2):V(remaining);
    }
    if(method=="get_box_by_name")return get_box(a.get(0,"name"));
    if(method=="box_of_screen_scaled"){
        const int sw=static_cast<int>(a.get(0,"original_width").integral()),sh=static_cast<int>(a.get(1,"original_height").integral());const double x=a.get(2,"x").numeric(),y=a.get(3,"y").numeric(),right=a.get(4,"to_x").numeric(),bottom=a.get(5,"to_y").numeric();const auto frame=io.frame();const double scale=std::min(static_cast<double>(frame.width)/sw,static_cast<double>(frame.height)/sh);const bool hc=a.get(7,"hcenter",V(false)).truth(),vc=a.get(8,"vcenter",V(false)).truth();
        return box_value({original_anchor(x,sw,frame.width,scale,hc),original_anchor(y,sh,frame.height,scale,vc),original_round((right-x)*scale),original_round((bottom-y)*scale)},a.get(6,"name",V("")).text());
    }
    if(method=="calculate_color_percentage"){
        const V color=a.get(0,"color_range"),bounds=a.get(1,"box",V{});const auto frame=io.frame();const ScreenBox roi=bounds.is_none()?ScreenBox{0,0,frame.width,frame.height}:box_object(get_box(bounds))->box;
        auto endpoint=[&](const char* channel,int at){return static_cast<int>(item(item(color,V(channel)),V(at)).integral());};
        return V(original_color_percent(frame,roi,{endpoint("b",0),endpoint("b",1),endpoint("g",0),endpoint("g",1),endpoint("r",0),endpoint("r",1)}));
    }
    if(method=="box_highlighted"){
        const auto frame=io.frame();const auto box=box_object(get_box(V("box_"+a.get(0,"name").text())))->box;
        return V(original_color_percent(frame,box,{244,255,244,255,244,255})>0?1:0);
    }
    if(method=="available"){
        const V key=a.get(0,"name");bool highlighted=true;if(a.get(1,"check_color",V(true)).truth()){const auto frame=io.frame();const auto box=box_object(get_box(V("box_"+key.text())))->box;highlighted=original_color_percent(frame,box,{244,255,244,255,244,255})>0;}
        Args cd;cd.pos(key);return highlighted&&(!a.get(2,"check_cd",V(true)).truth()||!invoke_task("has_cd",cd).truth())?V(true):V{};
    }
    if(method=="find_mouse_forte")return V(io.find_mouse_forte());if(method=="find_e_forte")return V(io.find_e_forte());
    if(method=="get_target_names"){const auto frame=io.frame();return frame.width==1600?V::tuple({V("has_target_169"),V("no_target_169")}):V::tuple({V("has_target"),V("no_target")});}
    if(method=="find_one")return find_one(a);
    if(method=="find_best_match_in_box")return find_one(a,true);
    if(method=="find_feature"){V result=V::list();V first=find_one(a);if(!first.is_none())result.sequence->push_back(first);return result;}
    if(method=="get_feature_by_name"){if(!io.template_frame)throw std::runtime_error("Maa official template image binding is unavailable");auto feature=std::make_shared<Namespace>("Feature");feature->members["mat"]=array_from_frame(io.template_frame(a.get(0,"name").text()))->value();return V(feature);}
    if(method=="has_short_action"){Args names;const auto target=invoke_task("get_target_names",names);Args query;query.pos(item(target,V(0)));query.kw("box",V("target_box_short"));query.kw("threshold",V(0.6));return find_one(query);}
    if(method=="check_f_break")return V(io.check_f_break_action());
    if(method=="f_break"){
        if(!io.can_break&&!io.check_f_break_action())return V{};const double start=io.seconds();
        while(io.seconds()-start<0.5||(io.seconds()-start<5&&(io.can_break||io.check_f_break_action()))){if(io.stop_requested())throw OriginalCombatStopped();io.send_key('F',0.02,-1,0.1);io.click(-1,0.1);io.can_break=false;}return V(true);
    }
    if(method=="add_freeze_duration"){const double start=a.get(0,"start").numeric();const double duration=a.get(1,"duration",V(-1)).numeric();io.add_freeze_duration(start,duration<0?io.seconds()-start:duration,a.get(2,"freeze_time",V(0.1)).numeric());return V{};}
    if(method=="time_elapsed_accounting_for_freeze")return V(io.elapsed_accounting_for_freeze(a.get(0,"start").numeric(),a.get(1,"intro_motion_freeze",V(false)).truth()));
    if(method=="wait_until"||method=="wait_in_team_and_world"){
        const bool world=method=="wait_in_team_and_world";const V condition=world?V::function([&io](const Args&){return V(io.active_slot()>0);}):a.get(0,"condition");
        double timeout=a.get(world?0:1,"time_out",V(world?10:0)).numeric();if(timeout==0)timeout=10;
        const V pre=world?V{}:a.get(2,"pre_action",V{}),post=world?V{}:a.get(3,"post_action",V{});
        double settle=world?0:a.get(4,"settle_time",V(-1)).numeric();const bool raise_failure=a.get(world?1:5,"raise_if_not_found",V(world)).truth();
        const bool esc=world&&a.get(2,"esc",V(false)).truth();const double start=io.seconds();double settled=0;
        while(!io.stop_requested()){
            if(!pre.is_none())invoke(pre,{});io.next_frame();const V result=invoke(condition,{});
            if(result.truth()){if(settle==-1)settle=0;if(settle<=0||settled>0&&io.seconds()-settled>settle){if(world)io.pause(0.5,true);return result;}if(settled==0)settled=io.seconds();continue;}settled=0;
            if(!post.is_none())invoke(post,{});if(esc)(io.send_physical_key?io.send_physical_key:io.send_key_action)(VK_ESCAPE,0.02,-1,2);
            if(io.seconds()-start>timeout)break;
        }
        if(io.stop_requested())throw OriginalCombatStopped();if(raise_failure)throw std::runtime_error("official WaitFailedException");return V{};
    }
    if(method=="screenshot"){if(io.observation_diagnostic){auto label=a.get(0,"name",V("official")).text();for(char& c:label)if(!std::isalnum(static_cast<unsigned char>(c))&&c!='-'&&c!='_')c='_';io.observation_diagnostic(label);}return V{};}
    if(method=="draw_boxes"||method=="info_set")return V{};
    if(method=="tr")return a.get(0,"text");
    if(method=="log_error"){std::cout<<"official_task_error message="<<a.get(0,"message",V("")).text()<<'\n';return V{};}
    throw AttributeError("unmapped official task operation: "+method);
}
} // namespace official
