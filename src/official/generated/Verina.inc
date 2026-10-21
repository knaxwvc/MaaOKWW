// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Verina.py
// SHA256 245f53207768715c617e546da5ed7ed2d2e10406624d8fc532a4758d38718120
void OfficialCharacter::install_Verina(){
auto scope=std::make_shared<Scope>();
set_class_attribute("NORMAL_ATTACK_TIME",V(0.6));
set_class_attribute("JUMP_ATTACK_TIME",V(0.5));
set_class_attribute("HEAVY_ATTACK_TIME",V(0.7));
set_class_attribute("RECOVER_TIME",V(0.8));
set_class_attribute("FIELD_TIME",V(6.5));
set_class_attribute("HEAVY_ATTACK_INTERVAL",V(8.0));
// Official method Verina.__init__, lines 17-19
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Verina.py:18
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Verina");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Verina.py:19
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"last_heavy",value_6);}
return V{};
}),false);
// Official method Verina.do_perform, lines 21-23
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Verina.py:22
    ([&]()->V{auto fn_9=attr(self_value(),"perform_combat");Args args_8;return invoke(fn_9,args_8);}());
    // Verina.py:23
    ([&]()->V{auto fn_11=attr(self_value(),"switch_next_char");Args args_10;return invoke(fn_11,args_10);}());
return V{};
}),false);
// Official method Verina.perform_combat, lines 25-47
register_method("perform_combat",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
scope_12->set("cast_skill",V::missing());
    // Verina.py:27
    {V value_13=([&]()->V{auto fn_15=attr(global("time","Verina"),"time");Args args_14;return invoke(fn_15,args_14);}());set_attr(self_value(),"start",value_13);}
    // Verina.py:29
    ([&]()->V{auto fn_17=attr(self_value(),"continues_normal_attack");Args args_16;args_16.pos(attr(self_value(),"NORMAL_ATTACK_TIME"));return invoke(fn_17,args_16);}());
    // Verina.py:32
    {auto iterator_18=official::iterate(V::tuple({attr(self_value(),"cast_liberation"),attr(self_value(),"cast_resonance"),attr(self_value(),"cast_echo")}));V item_19;while(iterator_18.next(item_19)){
        scope_12->set("cast_skill",item_19);
        // Verina.py:33
        if(([&]()->V{auto fn_21=attr(self_value(),"should_stop");Args args_20;return invoke(fn_21,args_20);}()).truth()){
            // Verina.py:34
            return V{};
        }
        // Verina.py:35
        ([&]()->V{auto fn_23=scope_12->get("cast_skill");Args args_22;return invoke(fn_23,args_22);}());
    }
    }
    // Verina.py:37
    if(([&]()->V{auto fn_25=attr(self_value(),"should_stop");Args args_24;return invoke(fn_25,args_24);}()).truth()){
        // Verina.py:38
        return V{};
    }
    // Verina.py:40
    ([&]()->V{auto fn_27=attr(attr(self_value(),"task"),"wait_until");Args args_26;args_26.pos(V::function([this,captured=capture_scope(scope_12,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_28=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_30=attr(attr(self_value(),"task"),"in_team");Args args_29;return invoke(fn_30,args_29);}()),V(0LL));
}));args_26.kw("time_out",V(2.0));return invoke(fn_27,args_26);}());
    // Verina.py:41
    ([&]()->V{auto fn_32=attr(self_value(),"sleep");Args args_31;args_31.pos(attr(self_value(),"RECOVER_TIME"));return invoke(fn_32,args_31);}());
    // Verina.py:43
    if(([&]()->V{V operand_33;operand_33=([&]()->V{auto fn_35=attr(self_value(),"is_mouse_forte_full");Args args_34;return invoke(fn_35,args_34);}());if(!operand_33.truth())return operand_33;return ([&]()->V{auto fn_37=attr(self_value(),"can_heavy_attack");Args args_36;return invoke(fn_37,args_36);}());}()).truth()){
        // Verina.py:44
        ([&]()->V{auto fn_39=attr(self_value(),"heavy_attack");Args args_38;args_38.pos(attr(self_value(),"HEAVY_ATTACK_TIME"));return invoke(fn_39,args_38);}());
        // Verina.py:45
        {V value_40=([&]()->V{auto fn_42=attr(global("time","Verina"),"time");Args args_41;return invoke(fn_42,args_41);}());set_attr(self_value(),"last_heavy",value_40);}
    }
    // Verina.py:46
    ([&]()->V{auto fn_44=attr(attr(self_value(),"task"),"jump");Args args_43;args_43.kw("after_sleep",V(0.01));return invoke(fn_44,args_43);}());
    // Verina.py:47
    ([&]()->V{auto fn_46=attr(self_value(),"continues_normal_attack");Args args_45;args_45.pos(attr(self_value(),"JUMP_ATTACK_TIME"));return invoke(fn_46,args_45);}());
return V{};
}),false);
// Official method Verina.cast_resonance, lines 49-52
register_method("cast_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_47=bind_arguments(official_args,signature,captured);
    // Verina.py:51
    if(([&]()->V{auto fn_49=attr(self_value(),"resonance_available");Args args_48;return invoke(fn_49,args_48);}()).truth()){
        // Verina.py:52
        ([&]()->V{auto fn_51=attr(self_value(),"click_resonance");Args args_50;args_50.kw("send_click",V(true));args_50.kw("time_out",V(0LL));return invoke(fn_51,args_50);}());
    }
return V{};
}),false);
// Official method Verina.cast_liberation, lines 54-57
register_method("cast_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_52=bind_arguments(official_args,signature,captured);
    // Verina.py:56
    if(([&]()->V{auto fn_54=attr(self_value(),"liberation_available");Args args_53;return invoke(fn_54,args_53);}()).truth()){
        // Verina.py:57
        ([&]()->V{auto fn_56=attr(self_value(),"click_liberation");Args args_55;return invoke(fn_56,args_55);}());
    }
return V{};
}),false);
// Official method Verina.cast_echo, lines 59-62
register_method("cast_echo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_57=bind_arguments(official_args,signature,captured);
    // Verina.py:61
    if(([&]()->V{auto fn_59=attr(self_value(),"echo_available");Args args_58;return invoke(fn_59,args_58);}()).truth()){
        // Verina.py:62
        ([&]()->V{auto fn_61=attr(self_value(),"click_echo");Args args_60;args_60.kw("time_out",V(0LL));return invoke(fn_61,args_60);}());
    }
return V{};
}),false);
// Official method Verina.should_stop, lines 64-66
register_method("should_stop",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_62=bind_arguments(official_args,signature,captured);
    // Verina.py:66
    return ([&]()->V{V operand_63;operand_63=([&]()->V{auto fn_65=attr(self_value(),"is_con_full");Args args_64;return invoke(fn_65,args_64);}());if(operand_63.truth())return operand_63;return ([&]()->V{auto fn_67=attr(self_value(),"field_time_out");Args args_66;return invoke(fn_67,args_66);}());}());
return V{};
}),false);
// Official method Verina.can_heavy_attack, lines 68-70
register_method("can_heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_68=bind_arguments(official_args,signature,captured);
    // Verina.py:70
    return ([&]()->V{V compare_69=([&]()->V{auto fn_72=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_71;args_71.pos(attr(self_value(),"last_heavy"));return invoke(fn_72,args_71);}());V compare_70;V comparison_result_73;compare_70=attr(self_value(),"HEAVY_ATTACK_INTERVAL");comparison_result_73=compare_value(">=",compare_69,compare_70);return comparison_result_73;}());
return V{};
}),false);
// Official method Verina.field_time_out, lines 72-74
register_method("field_time_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_74=bind_arguments(official_args,signature,captured);
    // Verina.py:74
    return ([&]()->V{V compare_75=([&]()->V{auto fn_78=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_77;args_77.pos(attr(self_value(),"start"));return invoke(fn_78,args_77);}());V compare_76;V comparison_result_79;compare_76=attr(self_value(),"FIELD_TIME");comparison_result_79=compare_value(">=",compare_75,compare_76);return comparison_result_79;}());
return V{};
}),false);
// Official method Verina.get_switch_priority, lines 76-79
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_80=bind_arguments(official_args,signature,captured);
    // Verina.py:77
    if(([&]()->V{V operand_81;operand_81=scope_80->get("has_intro");if(!operand_81.truth())return operand_81;operand_81=scope_80->get("current_char");if(!operand_81.truth())return operand_81;return ([&]()->V{V compare_82=attr(scope_80->get("current_char"),"char_name");V compare_83;V comparison_result_84;compare_83=V::set({V("char_hiyuki")});comparison_result_84=compare_value("in",compare_82,compare_83);return comparison_result_84;}());}()).truth()){
        // Verina.py:78
        return attr(global("SwitchPriority","Verina"),"MUST");
    }
    // Verina.py:79
    return ([&]()->V{auto fn_88=attr(([&]()->V{auto fn_86=global("super","Verina");Args args_85;return invoke(fn_86,args_85);}()),"get_switch_priority");Args args_87;args_87.pos(scope_80->get("current_char"));args_87.pos(scope_80->get("has_intro"));args_87.pos(scope_80->get("target_low_con"));return invoke(fn_88,args_87);}());
return V{};
}),false);
}
