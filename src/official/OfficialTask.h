#pragma once
#include "OfficialCharacter.h"
#include "OfficialBuiltins.h"

namespace official {
struct BoxObject final:Object {
    ScreenBox box;std::string name;double confidence=0;
    BoxObject(ScreenBox b,std::string n,double c=0):box(b),name(std::move(n)),confidence(c){}
    V get(const std::string& key)override;
    void set(const std::string& key,V value)override;
    std::string text()const override{return name;}
};
inline V box_value(ScreenBox box,std::string name,double confidence=0){return V(std::make_shared<BoxObject>(box,std::move(name),confidence));}
inline std::shared_ptr<BoxObject> box_object(const V& value){if(value.kind==V::Kind::object)if(auto box=std::dynamic_pointer_cast<BoxObject>(value.object))return box;throw TypeError("expected official screen box");}
class TaskObject final:public Object {
    OfficialCharacter& owner;
    V invoke_task(const std::string& method,const Args& args);
    V find_one(const Args& args,bool best=false);
    V get_box(const V& value);
    V current_character();
    std::map<std::string,V> methods_,globals_;
    void install_combat_methods();
    V self_value(){return V(ObjectPtr(this,[](Object*){}));}
    V global(const std::string& name,const std::string& =""){if(name=="logger")return owner.get("logger");const auto found=globals_.find(name);return found==globals_.end()?owner.global(name,"BaseChar"):found->second;}
    V import_value(const std::string& module,const std::string& name){return owner.import_value(module,name);}
    void set_global(const std::string& name,V value){globals_[name]=std::move(value);}
    void register_method(const std::string& name,V value,bool){methods_[name]=std::move(value);}
    static void rethrow_control_exception(const std::exception& e){OfficialCharacter::rethrow_control_exception(e);}
public:
    explicit TaskObject(OfficialCharacter& character):owner(character){}
    void initialize(){install_combat_methods();}
    V get(const std::string& name)override;
    void set(const std::string& name,V value)override;
    std::string text()const override{return "AutoCombatTask";}
};
} // namespace official
