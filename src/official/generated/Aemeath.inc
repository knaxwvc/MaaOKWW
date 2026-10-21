// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Aemeath.py
// SHA256 9706df3a8151b59a280dbdce78b7bacf076b53ef08e00bcb9d8ce97bd93c67bc
void OfficialCharacter::install_Aemeath(){
auto scope=std::make_shared<Scope>();
set_class_attribute("LIBERATION_COOLDOWN",V(25LL));
set_class_attribute("LIBERATION_FORCE_DURATION",V(30LL));
set_class_attribute("LIB2_PREPARE_WINDOW",V(8LL));
set_class_attribute("INTRO_LIBERATION_DELAY",V(14LL));
// Official method Aemeath.__init__, lines 12-16
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Aemeath.py:13
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Aemeath");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Aemeath.py:14
    {V value_6=V(false);set_attr(self_value(),"enhance_e_cast_this_turn",value_6);}
    // Aemeath.py:15
    {V value_7=V(false);set_attr(self_value(),"lib2_cast_this_turn",value_7);}
    // Aemeath.py:16
    {V value_8=V(false);set_attr(self_value(),"must_cast_lib2_this_turn",value_8);}
return V{};
}),false);
// Official method Aemeath.lib2_available, lines 18-19
register_method("lib2_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_9=bind_arguments(official_args,signature,captured);
    // Aemeath.py:19
    return ([&]()->V{auto fn_11=global("bool","Aemeath");Args args_10;args_10.pos(([&]()->V{auto fn_13=attr(attr(self_value(),"task"),"find_one");Args args_12;args_12.pos(V("aemeath_lib2"));args_12.kw("threshold",V(0.7));return invoke(fn_13,args_12);}()));return invoke(fn_11,args_10);}());
return V{};
}),false);
// Official method Aemeath.waits_for_intro, lines 21-24
register_method("waits_for_intro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_14=bind_arguments(official_args,signature,captured);
scope_14->set("char",V::missing());
scope_14->set("teammates",V::missing());
    // Aemeath.py:23
    {V value_15=([&]()->V{auto comprehension_scope_16=std::make_shared<Scope>(scope_14);V result_17=V::list();auto iterator_18=official::iterate(([&]()->V{auto fn_21=global("getattr","Aemeath");Args args_20;args_20.pos(attr(self_value(),"task"));args_20.pos(V("chars"));args_20.pos(V::list({}));return invoke(fn_21,args_20);}()));V value_19;while(iterator_18.next(value_19)){comprehension_scope_16->set("char",value_19);if(!([&]()->V{V operand_22;operand_22=comprehension_scope_16->get("char");if(!operand_22.truth())return operand_22;return ([&]()->V{V compare_23=comprehension_scope_16->get("char");V compare_24;V comparison_result_25;compare_24=self_value();comparison_result_25=compare_value("is not",compare_23,compare_24);return comparison_result_25;}());}()).truth())continue;append(result_17,comprehension_scope_16->get("char"));}return result_17;}());scope_14->set("teammates",value_15);}
    // Aemeath.py:24
    return ([&]()->V{V operand_26;operand_26=([&]()->V{V compare_27=([&]()->V{auto fn_30=global("len","Aemeath");Args args_29;args_29.pos(scope_14->get("teammates"));return invoke(fn_30,args_29);}());V compare_28;V comparison_result_31;compare_28=V(2LL);comparison_result_31=compare_value("!=",compare_27,compare_28);return comparison_result_31;}());if(operand_26.truth())return operand_26;return ([&]()->V{auto generator_scope_32=std::make_shared<Scope>(scope_14);auto iterator_33=official::iterate(generator_scope_32->get("teammates"));V value_34;while(iterator_33.next(value_34)){generator_scope_32->set("char",value_34);if(attr(generator_scope_32->get("char"),"is_sub_dps").truth())return V(true);}return V(false);}());}());
return V{};
}),false);
// Official method Aemeath.do_perform, lines 26-40
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_35=bind_arguments(official_args,signature,captured);
    // Aemeath.py:27
    {V value_36=V(false);set_attr(self_value(),"enhance_e_cast_this_turn",value_36);}
    // Aemeath.py:28
    {V value_37=V(false);set_attr(self_value(),"lib2_cast_this_turn",value_37);}
    // Aemeath.py:29
    {V value_38=([&]()->V{V operand_39;operand_39=([&]()->V{auto fn_41=attr(self_value(),"has_all_buff");Args args_40;return invoke(fn_41,args_40);}());if(!operand_39.truth())return operand_39;return attr(self_value(),"has_intro");}());set_attr(self_value(),"must_cast_lib2_this_turn",value_38);}
    // Aemeath.py:30
    if(([&]()->V{V operand_42;operand_42=unary("not",attr(self_value(),"must_cast_lib2_this_turn"));if(!operand_42.truth())return operand_42;return ([&]()->V{auto fn_44=attr(self_value(),"waits_for_intro");Args args_43;return invoke(fn_44,args_43);}());}()).truth()){
        // Aemeath.py:31
                while(([&]()->V{auto fn_50=attr(self_value(),"has_long_action");Args args_49;return invoke(fn_50,args_49);}()).truth()){
            // Aemeath.py:32
            if(([&]()->V{auto fn_46=attr(self_value(),"handle_heavy");Args args_45;return invoke(fn_46,args_45);}()).truth()){
                // Aemeath.py:33
                ([&]()->V{auto fn_48=attr(self_value(),"sleep");Args args_47;args_47.pos(V(0.3));return invoke(fn_48,args_47);}());
            }
        }
        // Aemeath.py:34
        return ([&]()->V{auto fn_52=attr(self_value(),"switch_next_char");Args args_51;return invoke(fn_52,args_51);}());
    }else{
        // Aemeath.py:35
        if(attr(self_value(),"has_intro").truth()){
            // Aemeath.py:36
            ([&]()->V{auto fn_54=attr(self_value(),"continues_normal_attack");Args args_53;args_53.pos(V(2.1));return invoke(fn_54,args_53);}());
        }
    }
    // Aemeath.py:38
    ([&]()->V{auto fn_56=attr(self_value(),"perform_everything");Args args_55;return invoke(fn_56,args_55);}());
    // Aemeath.py:40
    ([&]()->V{auto fn_58=attr(self_value(),"switch_next_char");Args args_57;return invoke(fn_58,args_57);}());
return V{};
}),false);
// Official method Aemeath.lib, lines 42-48
register_method("lib",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_59=bind_arguments(official_args,signature,captured);
scope_59->set("is_lib2",V::missing());
scope_59->set("liberated",V::missing());
    // Aemeath.py:43
    {V value_60=([&]()->V{auto fn_62=attr(self_value(),"lib2_available");Args args_61;return invoke(fn_62,args_61);}());scope_59->set("is_lib2",value_60);}
    // Aemeath.py:44
    {V value_63=([&]()->V{auto fn_65=attr(self_value(),"click_liberation");Args args_64;args_64.kw("wait_if_cd_ready",V(0LL));return invoke(fn_65,args_64);}());scope_59->set("liberated",value_63);}
    // Aemeath.py:45
    if(scope_59->get("liberated").truth()){
        // Aemeath.py:46
        if(scope_59->get("is_lib2").truth()){
            // Aemeath.py:47
            {V value_66=V(true);set_attr(self_value(),"lib2_cast_this_turn",value_66);}
        }
    }
    // Aemeath.py:48
    return scope_59->get("liberated");
return V{};
}),false);
// Official method Aemeath.record_enhance_e, lines 50-51
register_method("record_enhance_e",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_67=bind_arguments(official_args,signature,captured);
    // Aemeath.py:51
    {V value_68=V(true);set_attr(self_value(),"enhance_e_cast_this_turn",value_68);}
return V{};
}),false);
// Official method Aemeath.required_action_pending, lines 53-55
register_method("required_action_pending",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_69=bind_arguments(official_args,signature,captured);
    // Aemeath.py:54
    return ([&]()->V{V operand_70;operand_70=([&]()->V{V operand_71;operand_71=attr(self_value(),"has_intro");if(!operand_71.truth())return operand_71;return unary("not",attr(self_value(),"enhance_e_cast_this_turn"));}());if(operand_70.truth())return operand_70;return ([&]()->V{V operand_72;operand_72=attr(self_value(),"must_cast_lib2_this_turn");if(!operand_72.truth())return operand_72;return unary("not",attr(self_value(),"lib2_cast_this_turn"));}());}());
return V{};
}),false);
// Official method Aemeath.continue_after_action, lines 57-62
register_method("continue_after_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"start",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_73=bind_arguments(official_args,signature,captured);
    // Aemeath.py:58
    if(([&]()->V{auto fn_75=attr(self_value(),"has_long_action");Args args_74;return invoke(fn_75,args_74);}()).truth()){
        // Aemeath.py:59
        return ([&]()->V{auto fn_77=attr(global("time","Aemeath"),"time");Args args_76;return invoke(fn_77,args_76);}());
    }
    // Aemeath.py:60
    if(([&]()->V{auto fn_79=attr(self_value(),"required_action_pending");Args args_78;return invoke(fn_79,args_78);}()).truth()){
        // Aemeath.py:61
        return scope_73->get("start");
    }
    // Aemeath.py:62
    return V{};
return V{};
}),false);
// Official method Aemeath.perform_everything, lines 64-95
register_method("perform_everything",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_80=bind_arguments(official_args,signature,captured);
scope_80->set("action_performed",V::missing());
scope_80->set("start",V::missing());
    // Aemeath.py:65
    {V value_81=([&]()->V{auto fn_83=attr(global("time","Aemeath"),"time");Args args_82;return invoke(fn_83,args_82);}());scope_80->set("start",value_81);}
    // Aemeath.py:66
        while(([&]()->V{V compare_124=([&]()->V{auto fn_127=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_126;args_126.pos(scope_80->get("start"));return invoke(fn_127,args_126);}());V compare_125;V comparison_result_128;compare_125=V(12LL);comparison_result_128=compare_value("<",compare_124,compare_125);return comparison_result_128;}()).truth()){
        // Aemeath.py:67
        ([&]()->V{auto fn_85=attr(self_value(),"cycle_start");Args args_84;return invoke(fn_85,args_84);}());
        // Aemeath.py:68
        if(([&]()->V{auto fn_87=attr(self_value(),"handle_heavy");Args args_86;return invoke(fn_87,args_86);}()).truth()){
            // Aemeath.py:69
            {V value_88=([&]()->V{auto fn_90=attr(global("time","Aemeath"),"time");Args args_89;return invoke(fn_90,args_89);}());scope_80->set("start",value_88);}
            // Aemeath.py:70
            if(unary("not",([&]()->V{auto fn_92=attr(self_value(),"f_break");Args args_91;return invoke(fn_92,args_91);}())).truth()){
                // Aemeath.py:71
                ([&]()->V{auto fn_94=attr(self_value(),"sleep");Args args_93;args_93.pos(V(0.1));return invoke(fn_94,args_93);}());
            }
            // Aemeath.py:72
            ([&]()->V{auto fn_96=attr(self_value(),"check_combat");Args args_95;return invoke(fn_96,args_95);}());
            // Aemeath.py:73
            continue;
        }
        // Aemeath.py:74
        if(([&]()->V{auto fn_98=attr(self_value(),"lib");Args args_97;return invoke(fn_98,args_97);}()).truth()){
            // Aemeath.py:75
            if(attr(self_value(),"lib2_cast_this_turn").truth()){
                // Aemeath.py:76
                return V{};
            }
            // Aemeath.py:77
            {V value_99=V(true);scope_80->set("action_performed",value_99);}
        }else{
            // Aemeath.py:78
            if(([&]()->V{auto fn_101=attr(self_value(),"enhance_e_available");Args args_100;return invoke(fn_101,args_100);}()).truth()){
                // Aemeath.py:79
                if(item(([&]()->V{auto fn_103=attr(self_value(),"click_resonance");Args args_102;args_102.kw("has_animation",V(true));args_102.kw("send_click",V(true));args_102.kw("animation_min_duration",V(0.5));args_102.kw("time_out",V(1.5));return invoke(fn_103,args_102);}()),V(0LL)).truth()){
                    // Aemeath.py:81
                    ([&]()->V{auto fn_105=attr(self_value(),"record_enhance_e");Args args_104;return invoke(fn_105,args_104);}());
                    // Aemeath.py:82
                    ([&]()->V{auto fn_107=attr(self_value(),"click_echo");Args args_106;args_106.kw("time_out",V(0LL));return invoke(fn_107,args_106);}());
                    // Aemeath.py:83
                    ([&]()->V{auto fn_109=attr(attr(self_value(),"task"),"next_frame");Args args_108;return invoke(fn_109,args_108);}());
                }
                // Aemeath.py:84
                ([&]()->V{auto fn_111=attr(self_value(),"lib");Args args_110;return invoke(fn_111,args_110);}());
                // Aemeath.py:85
                if(attr(self_value(),"lib2_cast_this_turn").truth()){
                    // Aemeath.py:86
                    return V{};
                }
                // Aemeath.py:87
                {V value_112=V(true);scope_80->set("action_performed",value_112);}
            }else{
                // Aemeath.py:89
                ([&]()->V{auto fn_114=attr(self_value(),"click");Args args_113;return invoke(fn_114,args_113);}());
                // Aemeath.py:90
                {V value_115=V(false);scope_80->set("action_performed",value_115);}
            }
        }
        // Aemeath.py:91
        if(scope_80->get("action_performed").truth()){
            // Aemeath.py:92
            {V value_116=([&]()->V{auto fn_118=attr(self_value(),"continue_after_action");Args args_117;args_117.pos(scope_80->get("start"));return invoke(fn_118,args_117);}());scope_80->set("start",value_116);}
            // Aemeath.py:93
            if(([&]()->V{V compare_119=scope_80->get("start");V compare_120;V comparison_result_121;compare_120=V{};comparison_result_121=compare_value("is",compare_119,compare_120);return comparison_result_121;}()).truth()){
                // Aemeath.py:94
                return V{};
            }
        }
        // Aemeath.py:95
        ([&]()->V{auto fn_123=attr(self_value(),"cycle_sleep");Args args_122;return invoke(fn_123,args_122);}());
    }
return V{};
}),false);
// Official method Aemeath.enhance_e_available, lines 97-99
register_method("enhance_e_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_129=bind_arguments(official_args,signature,captured);
    // Aemeath.py:98
    return ([&]()->V{V operand_130;operand_130=([&]()->V{auto fn_132=attr(attr(self_value(),"task"),"find_one");Args args_131;args_131.pos(V("aemeath_e1"));args_131.kw("threshold",V(0.7));return invoke(fn_132,args_131);}());if(operand_130.truth())return operand_130;return ([&]()->V{auto fn_134=attr(attr(self_value(),"task"),"find_one");Args args_133;args_133.pos(V("aemeath_e2"));args_133.kw("threshold",V(0.7));return invoke(fn_134,args_133);}());}());
return V{};
}),false);
// Official method Aemeath.heavy_wait_highlight_down, lines 101-106
register_method("heavy_wait_highlight_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_135=bind_arguments(official_args,signature,captured);
scope_135->set("ret",V::missing());
    // Aemeath.py:102
    ([&]()->V{auto fn_137=attr(attr(self_value(),"task"),"mouse_down");Args args_136;return invoke(fn_137,args_136);}());
    // Aemeath.py:103
    {V value_138=([&]()->V{auto fn_140=attr(attr(self_value(),"task"),"wait_until");Args args_139;args_139.pos(V::function([this,captured=capture_scope(scope_135,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_141=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_143=attr(self_value(),"has_long_action");Args args_142;return invoke(fn_143,args_142);}()));
}));args_139.kw("time_out",V(1.2));return invoke(fn_140,args_139);}());scope_135->set("ret",value_138);}
    // Aemeath.py:104
    ([&]()->V{auto fn_145=attr(attr(self_value(),"task"),"mouse_up");Args args_144;return invoke(fn_145,args_144);}());
    // Aemeath.py:105
    ([&]()->V{auto fn_147=attr(self_value(),"sleep");Args args_146;args_146.pos(V(0.01));return invoke(fn_147,args_146);}());
    // Aemeath.py:106
    return scope_135->get("ret");
return V{};
}),false);
// Official method Aemeath.handle_heavy, lines 108-113
register_method("handle_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_148=bind_arguments(official_args,signature,captured);
    // Aemeath.py:109
    if(unary("not",([&]()->V{auto fn_150=attr(self_value(),"has_long_action");Args args_149;return invoke(fn_150,args_149);}())).truth()){
        // Aemeath.py:110
        return V(false);
    }
    // Aemeath.py:111
    if(([&]()->V{auto fn_152=attr(self_value(),"heavy_wait_highlight_down");Args args_151;return invoke(fn_152,args_151);}()).truth()){
        // Aemeath.py:112
        return V(true);
    }
    // Aemeath.py:113
    return V(false);
return V{};
}),false);
// Official method Aemeath.on_combat_end, lines 115-116
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_153=bind_arguments(official_args,signature,captured);
    // Aemeath.py:116
    ([&]()->V{auto fn_155=attr(self_value(),"switch_other_char");Args args_154;return invoke(fn_155,args_154);}());
return V{};
}),false);
}
