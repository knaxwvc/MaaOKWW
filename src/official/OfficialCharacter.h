#pragma once
#include "../NativePrelude.h"
#include "../char/OriginalBaseChar.h"
#include "OfficialValue.h"

namespace official {
class TaskObject;
class OfficialCharacter:public OriginalBaseChar,public Object {
    std::string class_name_,module_name_;
    OriginalSwitchCharacter* member_=nullptr;
    std::unique_ptr<OriginalSwitchCharacter> retired_member_;
    std::weak_ptr<OfficialCharacter> lifetime_;
    V self_,task_value_,class_token_;
    std::map<std::string,V> globals_,base_globals_,fields_,class_attributes_,methods_,base_methods_;
    static std::map<OriginalBaseChar*,OfficialCharacter*>& registry();
    V bound(const V& method);
    V state_get(const std::string& name,bool& found);
    bool state_set(const std::string& name,const V& value);
    void initialize();
public:
    OfficialCharacter(OriginalCombatIO& io,OriginalSwitchCharacter& member,const std::string& name);
    ~OfficialCharacter()override;
    static V from(OriginalBaseChar* actor);
    V self_value(){if(auto owner=lifetime_.lock())return V(std::static_pointer_cast<Object>(owner));return self_;}
    void bind_lifetime(const std::shared_ptr<OfficialCharacter>& owner){lifetime_=owner;}
    void detach_member(){retired_member_=std::make_unique<OriginalSwitchCharacter>(*member_);member_=retired_member_.get();}
    void apply_registration();
    V global(const std::string& name,const std::string& module="");
    V import_value(const std::string& module,const std::string& name);
    void set_global(const std::string& name,V value){globals_[name]=std::move(value);}
    void set_class_attribute(const std::string& name,V value){class_attributes_[name]=std::move(value);}
    V make_namespace(const std::string& name,std::initializer_list<std::pair<std::string,V>> values);
    void register_method(const std::string& name,V method,bool base);
    V call_official(const std::string& name,const Args& args=Args{});
    V call_official(const std::string& name,std::initializer_list<V> args);
    V get(const std::string& name)override;
    void set(const std::string& name,V value)override;
    std::string text()const override;
    V comparison(const std::string& operation,const V& other)override;
    OriginalCombatIO& io(){return task;}
    OriginalSwitchCharacter& member(){return *member_;}
    V team_values();
    void perform()override;
    void do_perform()override;
    void reset_state()override;
    void on_combat_end()override;
    void switch_out(bool full,double now)override;
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool intro=false,bool low=false)override;
    bool skip_combat_check()override;
    bool wait_switch()override;
    double intro_freeze_seconds()const override;
    double current_con_for_switch()override;
    bool con_full_for_switch()override;
    void break_on_switch()override;
    void attack_without_switch(double duration)override;
    bool liberation_available()override;
    void sync_metadata()override;
    static void rethrow_control_exception(const std::exception& error);
#include "generated/Declarations.inc"
};
} // namespace official
