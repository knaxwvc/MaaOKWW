#include "OfficialTask.h"

namespace official {
std::map<OriginalBaseChar*,OfficialCharacter*>& OfficialCharacter::registry(){static std::map<OriginalBaseChar*,OfficialCharacter*> result;return result;}
V OfficialCharacter::from(OriginalBaseChar* actor){if(!actor)return V{};const auto found=registry().find(actor);if(found==registry().end())throw TypeError("character is outside the official native registry");return found->second->self_value();}
OfficialCharacter::OfficialCharacter(OriginalCombatIO& io,OriginalSwitchCharacter& member,const std::string& name):OriginalBaseChar(io,member),class_name_(name),module_name_("BaseChar"),member_(&member){
    registry()[this]=this;bool constructed=false;auto constructor_guard=on_scope_exit([&](){if(!constructed)registry().erase(this);});
    self_=V(ObjectPtr(static_cast<Object*>(this),[](Object*){}));task_value_=V(std::make_shared<TaskObject>(*this));class_token_=V(std::make_shared<ClassToken>(name));
    globals_=standard_globals();
    auto time=std::make_shared<Namespace>("time");time->members["time"]=V::function([this](const Args&){return V(task.seconds());});time->members["sleep"]=V::function([this](const Args& a){const double sec=a.get(0,"seconds").numeric();if(task.raw_sleep)task.raw_sleep(sec);else original_sleep_for(sec);return V{};});globals_["time"]=V(time);
    auto labels=std::make_shared<Namespace>("Labels");labels->dynamic_get=[](const std::string& key){return V(key);};globals_["Labels"]=V(labels);
    auto logger_factory=std::make_shared<Namespace>("Logger");logger_factory->members["get_logger"]=V::function([this](const Args& args){
        const auto label=args.get(0,"name").text();auto logger=std::make_shared<Namespace>("logger");logger->dynamic_get=[this,label](const std::string& level){if(level!="debug"&&level!="info"&&level!="warning"&&level!="error"&&level!="exception")throw AttributeError("unknown logger method "+level);return V::function([this,label,level](const Args& a){if(level!="debug")std::cout<<"official class="<<class_name_<<" slot="<<this->member().index+1<<" level="<<level<<" message="<<a.get(0,"message",V("")).text()<<'\n';return V{};});};return V(logger);
    });globals_["Logger"]=V(logger_factory);
    globals_["super"]=V::function([this](const Args&){auto object=std::make_shared<Namespace>("super");object->dynamic_get=[this](const std::string& name){const auto found=base_methods_.find(name);if(found==base_methods_.end())throw AttributeError("official BaseChar has no method "+name);return bound(found->second);};return V(object);});
    install_BaseChar();base_globals_=globals_;module_name_=name;
#include "generated/Install.inc"
    initialize();
    std::static_pointer_cast<TaskObject>(task_value_.object)->initialize();constructed=true;
}
OfficialCharacter::~OfficialCharacter(){registry().erase(this);}
V OfficialCharacter::global(const std::string& name,const std::string& module){const auto& values=module=="BaseChar"&&!base_globals_.empty()?base_globals_:globals_;const auto found=values.find(name);if(found!=values.end())return found->second;
    if(name=="BaseChar"||name=="AutoCombatTask")return V(std::make_shared<ClassToken>(name));
    for(const auto& definition:character_definitions)if(definition.class_name==name)return V(std::make_shared<ClassToken>(name));
    throw AttributeError("unmapped official global: "+module_name_+"."+name);
}
V OfficialCharacter::import_value(const std::string& module,const std::string& name){
    if(name=="State"){
        const std::string origin=module.substr(module.find_last_of('.')+1);
        const std::string& module_=origin;
        (void)module_;
        // Each module's enum is created once, as in its official source.
        const auto module=origin;
#include "generated/ModuleEnums.inc"
        throw AttributeError("official enum not registered: "+origin+"."+name);
    }
    return global(name);
}
V OfficialCharacter::make_namespace(const std::string& name,std::initializer_list<std::pair<std::string,V>> values){if(name=="State")return import_value("src.char."+module_name_,name);return official::make_namespace(name,values);}
void OfficialCharacter::register_method(const std::string& name,V method,bool base){methods_[name]=method;if(base)base_methods_[name]=std::move(method);}
V OfficialCharacter::bound(const V& method){return V::function([this,method](const Args& args){Args actual;actual.pos(self_value());actual.positional.insert(actual.positional.end(),args.positional.begin(),args.positional.end());actual.keywords=args.keywords;return invoke(method,actual);});}
V OfficialCharacter::call_official(const std::string& name,const Args& args){const auto found=methods_.find(name);if(found==methods_.end())throw AttributeError("official method not found: "+class_name_+"."+name);return invoke(bound(found->second),args);}
V OfficialCharacter::call_official(const std::string& name,std::initializer_list<V> args){Args actual;actual.positional=args;return call_official(name,actual);}
void OfficialCharacter::initialize(){
    Args args;args.pos(task_value_);args.pos(V(this->member().index));args.kw("char_name",V(std::string(this->member().definition->portrait_template)));args.kw("confidence",V(1.0));
    std::string role="MainDps";int ring=-1;V buff;bool short_target=false;
#include "generated/InitialMetadata.inc"
    if(class_name_!="BaseChar"&&buff.is_none())buff=V(role=="Healer"?28:14);
    args.kw("ring_index",V(ring));args.kw("char_type",V(role));args.kw("buff_time",buff);call_official("__init__",args);apply_registration();sync_metadata();
}
void OfficialCharacter::apply_registration(){
    if(class_name_=="BaseChar")return;
    std::string role="MainDps";int ring=-1;V buff;bool short_target=false;
#include "generated/InitialMetadata.inc"
    if(buff.is_none())buff=V(role=="Healer"?28:14);
    set("char_name",V(std::string(this->member().definition->portrait_template)));
    call_official("set_char_type",{V(role)});call_official("set_buff_time",{buff});set("target_box_short_combat_check",V(short_target));
}
V OfficialCharacter::state_get(const std::string& name,bool& found){
    found=true;
    if(name=="index")return V(this->member().index);
    if(name=="ring_index")return V(this->member().ring_index);
    if(name=="is_current_char")return V(this->member().is_current_char);
    if(name=="has_intro")return V(this->member().has_intro);
    if(name=="has_sub_dps_intro")return V(this->member().has_sub_dps_intro);
    if(name=="current_con")return V(this->member().current_con);
    if(name=="last_switch_time")return V(this->member().last_switch_time);
    if(name=="last_switch_in_time")return V(this->member().last_switch_in_time);
    if(name=="last_full_con_switch_time")return V(this->member().last_full_con_switch_time);
    if(name=="last_buff_time")return V(this->member().last_buff_time);
    if(name=="last_outro_time")return V(this->member().last_outro_time);
    if(name=="last_perform")return V(this->member().last_perform);
    if(name=="has_tool_box")return V(this->member().has_tool_box);
    if(name=="_liberation_available")return V(this->member().cached_liberation_available);
    if(name=="last_liberation")return V(this->member().last_liberation);
    found=false;return V{};
}
bool OfficialCharacter::state_set(const std::string& name,const V& value){
    if(name=="index"){this->member().index=static_cast<int>(value.integral());return true;}
    if(name=="ring_index"){this->member().ring_index=static_cast<int>(value.integral());return true;}
    if(name=="is_current_char"){this->member().is_current_char=value.truth();if(this->member().is_current_char&&task.confirm_current_character)task.confirm_current_character(this->member().index+1);return true;}
    if(name=="has_intro"){this->member().has_intro=value.truth();return true;}
    if(name=="has_sub_dps_intro"){this->member().has_sub_dps_intro=value.truth();return true;}
    if(name=="current_con"){this->member().current_con=value.numeric();return true;}
    if(name=="last_switch_time"){this->member().last_switch_time=value.numeric();return true;}
    if(name=="last_switch_in_time"){this->member().last_switch_in_time=value.numeric();return true;}
    if(name=="last_full_con_switch_time"){this->member().last_full_con_switch_time=value.numeric();return true;}
    if(name=="last_buff_time"){this->member().last_buff_time=value.numeric();return true;}
    if(name=="last_outro_time"){this->member().last_outro_time=value.numeric();return true;}
    if(name=="last_perform"){this->member().last_perform=value.numeric();return true;}
    if(name=="has_tool_box"){this->member().has_tool_box=value.truth();return true;}
    if(name=="_liberation_available"){this->member().cached_liberation_available=value.truth();return true;}
    if(name=="last_liberation"){this->member().last_liberation=value.numeric();return true;}
    return false;
}
V OfficialCharacter::get(const std::string& name){
    if(name=="__class__")return class_token_;
    if(const auto getter=methods_.find("@get:"+name);getter!=methods_.end())return invoke(bound(getter->second),{});
    bool found=false;V state_value=state_get(name,found);if(found)return state_value;
    if(const auto value=fields_.find(name);value!=fields_.end())return value->second;
    if(const auto method=methods_.find(name);method!=methods_.end())return bound(method->second);
    if(const auto value=class_attributes_.find(name);value!=class_attributes_.end())return value->second;
    throw AttributeError("official character has no attribute: "+class_name_+"."+name);
}
void OfficialCharacter::set(const std::string& name,V value){if(const auto setter=methods_.find("@set:"+name);setter!=methods_.end()){invoke(bound(setter->second),{value});return;}if(!state_set(name,value))fields_[name]=std::move(value);}
std::string OfficialCharacter::text()const{return const_cast<OfficialCharacter*>(this)->call_official("__str__").text();}
V OfficialCharacter::comparison(const std::string& operation,const V& other){if(operation=="=="||operation=="!="){const auto same=call_official("__eq__",{other});return operation=="=="?same:V(!same.truth());}return Object::comparison(operation,other);}
V OfficialCharacter::team_values(){V out=V::list();for(int slot=1;slot<=task.team_size();++slot)if(auto* member=task.member_at(slot)){OriginalBaseChar* actor=member==&this->member()?this:task.find_character(member->definition->class_name);out.sequence->push_back(from(actor));}return out;}
void OfficialCharacter::perform(){call_official("perform");sync_metadata();}
void OfficialCharacter::do_perform(){call_official("do_perform");}
void OfficialCharacter::reset_state(){call_official("reset_state");sync_metadata();}
void OfficialCharacter::on_combat_end(){call_official("on_combat_end",{team_values()});}
void OfficialCharacter::switch_out(bool full,double){call_official("switch_out",{V(full)});sync_metadata();}
int OfficialCharacter::get_switch_priority(OriginalBaseChar* current,bool intro,bool low){sync_metadata();return static_cast<int>(call_official("get_switch_priority",{from(current),V(intro),V(low)}).integral());}
bool OfficialCharacter::skip_combat_check(){return call_official("skip_combat_check").truth();}
bool OfficialCharacter::wait_switch(){return call_official("wait_switch").truth();}
double OfficialCharacter::intro_freeze_seconds()const{return const_cast<OfficialCharacter*>(this)->get("intro_motion_freeze_duration").numeric();}
double OfficialCharacter::current_con_for_switch(){return call_official("get_current_con").numeric();}
bool OfficialCharacter::con_full_for_switch(){return call_official("is_con_full").truth();}
void OfficialCharacter::break_on_switch(){Args a;a.kw("check_f_on_switch",V(true));call_official("f_break",a);}
void OfficialCharacter::attack_without_switch(double duration){call_official("continues_normal_attack",{V(duration)});}
bool OfficialCharacter::liberation_available(){return call_official("liberation_available").truth();}
void OfficialCharacter::sync_metadata(){const auto role=call_official("get_char_type").text();this->member().role_override=static_cast<int>(role=="Healer"?CharacterRole::HEALER:role=="SubDps"?CharacterRole::SUB_DPS:CharacterRole::MAIN_DPS);this->member().buff_override=call_official("get_buff_time").numeric();}
void OfficialCharacter::rethrow_control_exception(const std::exception& error){if(dynamic_cast<const OriginalCombatStopped*>(&error)||dynamic_cast<const OriginalHudUnavailable*>(&error)||dynamic_cast<const OriginalNotInCombat*>(&error)||dynamic_cast<const OriginalSoloSuspended*>(&error))throw;}
} // namespace official
