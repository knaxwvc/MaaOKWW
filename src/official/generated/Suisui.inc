// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Suisui.py
// SHA256 4f0de7edd7254bd0b17c229ab9ed790976678c51b8b035a5f661f9b62fd09985
void OfficialCharacter::install_Suisui(){
auto scope=std::make_shared<Scope>();
set_class_attribute("ATTACK_INTERVAL",V(0.1));
set_class_attribute("FORTE_TIMEOUT",V(26.0));
set_class_attribute("CONCERTO_TIMEOUT",V(12.0));
set_class_attribute("FORTE3_SWITCH_LOCKOUT",V(16.0));
set_class_attribute("MAIN_DPS_FORTE3_SWITCH_LOCKOUT",V(32LL));
// Official method Suisui.__init__, lines 14-17
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Suisui.py:15
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Suisui");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Suisui.py:16
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"last_forte3_switch",value_6);}
    // Suisui.py:17
    {V value_7=V(false);set_attr(self_value(),"should_heavy",value_7);}
return V{};
}),false);
// Official method Suisui.reset_state, lines 19-22
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Suisui.py:20
    ([&]()->V{auto fn_12=attr(([&]()->V{auto fn_10=global("super","Suisui");Args args_9;return invoke(fn_10,args_9);}()),"reset_state");Args args_11;return invoke(fn_12,args_11);}());
    // Suisui.py:21
    {V value_13=unary("-",V(1LL));set_attr(self_value(),"last_forte3_switch",value_13);}
    // Suisui.py:22
    {V value_14=V(false);set_attr(self_value(),"should_heavy",value_14);}
return V{};
}),false);
// Official method Suisui.do_perform, lines 24-28
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
    // Suisui.py:25
    if(unary("not",attr(self_value(),"should_heavy")).truth()){
        // Suisui.py:26
        {V value_16=attr(self_value(),"has_intro");set_attr(self_value(),"should_heavy",value_16);}
    }
    // Suisui.py:27
    ([&]()->V{auto fn_18=attr(self_value(),"perform_forte3_rotation");Args args_17;return invoke(fn_18,args_17);}());
    // Suisui.py:28
    ([&]()->V{auto fn_20=attr(self_value(),"switch_next_char");Args args_19;return invoke(fn_20,args_19);}());
return V{};
}),false);
// Official method Suisui.perform_forte3_rotation, lines 30-69
register_method("perform_forte3_rotation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
scope_21->set("i",V::missing());
scope_21->set("liberation_clicked",V::missing());
scope_21->set("start",V::missing());
    // Suisui.py:31
    {V value_22=([&]()->V{auto fn_24=attr(global("time","Suisui"),"time");Args args_23;return invoke(fn_24,args_23);}());scope_21->set("start",value_22);}
    // Suisui.py:32
    if(attr(self_value(),"should_heavy").truth()){
        // Suisui.py:33
        if(attr(self_value(),"has_intro").truth()){
            // Suisui.py:34
            ([&]()->V{auto fn_26=attr(self_value(),"heavy_attack");Args args_25;args_25.pos(V(1.5));return invoke(fn_26,args_25);}());
        }
        // Suisui.py:35
        ([&]()->V{auto fn_28=attr(self_value(),"click_resonance");Args args_27;return invoke(fn_28,args_27);}());
        // Suisui.py:36
        {V value_29=V(false);set_attr(self_value(),"should_heavy",value_29);}
    }
    // Suisui.py:37
    {bool loop_completed_30=true;
    while(([&]()->V{V compare_60=([&]()->V{auto fn_63=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_62;args_62.pos(scope_21->get("start"));return invoke(fn_63,args_62);}());V compare_61;V comparison_result_64;compare_61=attr(self_value(),"FORTE_TIMEOUT");comparison_result_64=compare_value("<",compare_60,compare_61);return comparison_result_64;}()).truth()){
        // Suisui.py:38
        if(([&]()->V{auto fn_32=attr(self_value(),"forte3_available");Args args_31;return invoke(fn_32,args_31);}()).truth()){
            // Suisui.py:39
            ([&]()->V{auto fn_34=attr(attr(self_value(),"logger"),"debug");Args args_33;args_33.pos(V("forte3 available"));return invoke(fn_34,args_33);}());
            // Suisui.py:40
            loop_completed_30=false;break;
        }else{
            // Suisui.py:41
            if(([&]()->V{V operand_35;operand_35=([&]()->V{auto fn_37=attr(self_value(),"forte2_available");Args args_36;return invoke(fn_37,args_36);}());if(operand_35.truth())return operand_35;return ([&]()->V{auto fn_39=attr(self_value(),"forte3_available");Args args_38;return invoke(fn_39,args_38);}());}()).truth()){
                // Suisui.py:42
                ([&]()->V{auto fn_41=attr(attr(self_value(),"logger"),"debug");Args args_40;args_40.pos(V("forte2 available"));return invoke(fn_41,args_40);}());
                // Suisui.py:43
                {auto iterator_42=official::iterate(([&]()->V{auto fn_49=global("range","Suisui");Args args_48;args_48.pos(V(7LL));return invoke(fn_49,args_48);}()));V item_43;while(iterator_42.next(item_43)){
                    scope_21->set("i",item_43);
                    // Suisui.py:44
                    if(([&]()->V{auto fn_45=attr(self_value(),"forte3_available");Args args_44;return invoke(fn_45,args_44);}()).truth()){
                        // Suisui.py:45
                        break;
                    }
                    // Suisui.py:46
                    ([&]()->V{auto fn_47=attr(self_value(),"click");Args args_46;args_46.kw("after_sleep",V(0.1));return invoke(fn_47,args_46);}());
                }
                }
                // Suisui.py:47
                loop_completed_30=false;break;
            }
        }
        // Suisui.py:48
        ([&]()->V{auto fn_51=attr(self_value(),"cycle_start");Args args_50;return invoke(fn_51,args_50);}());
        // Suisui.py:49
        if(unary("not",attr(self_value(),"has_intro")).truth()){
            // Suisui.py:50
            if(([&]()->V{auto fn_53=attr(self_value(),"try_e");Args args_52;return invoke(fn_53,args_52);}()).truth()){
                // Suisui.py:51
                return ([&]()->V{auto fn_55=attr(self_value(),"switch_next_char");Args args_54;return invoke(fn_55,args_54);}());
            }
        }
        // Suisui.py:52
        ([&]()->V{auto fn_57=attr(self_value(),"click");Args args_56;return invoke(fn_57,args_56);}());
        // Suisui.py:53
        ([&]()->V{auto fn_59=attr(self_value(),"cycle_sleep");Args args_58;args_58.pos(attr(self_value(),"ATTACK_INTERVAL"));return invoke(fn_59,args_58);}());
    }
    if(loop_completed_30){
        // Suisui.py:55
        ([&]()->V{auto fn_66=attr(attr(self_value(),"logger"),"warning");Args args_65;args_65.pos(V("Suisui forte3 detection timed out"));return invoke(fn_66,args_65);}());
        // Suisui.py:56
        return V{};
    }}
    // Suisui.py:58
    {V value_67=V(false);scope_21->set("liberation_clicked",value_67);}
    // Suisui.py:59
    {V value_68=([&]()->V{auto fn_70=attr(global("time","Suisui"),"time");Args args_69;return invoke(fn_70,args_69);}());scope_21->set("start",value_68);}
    // Suisui.py:60
        while(([&]()->V{V compare_83=([&]()->V{auto fn_86=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_85;args_85.pos(scope_21->get("start"));return invoke(fn_86,args_85);}());V compare_84;V comparison_result_87;compare_84=attr(self_value(),"CONCERTO_TIMEOUT");comparison_result_87=compare_value("<",compare_83,compare_84);return comparison_result_87;}()).truth()){
        // Suisui.py:61
        if(unary("not",scope_21->get("liberation_clicked")).truth()){
            // Suisui.py:62
            {V value_71=([&]()->V{auto fn_73=attr(self_value(),"click_liberation");Args args_72;args_72.kw("wait_if_cd_ready",V(0LL));return invoke(fn_73,args_72);}());scope_21->set("liberation_clicked",value_71);}
            // Suisui.py:63
            if(scope_21->get("liberation_clicked").truth()){
                // Suisui.py:64
                ([&]()->V{auto fn_75=attr(attr(self_value(),"task"),"next_frame");Args args_74;return invoke(fn_75,args_74);}());
                // Suisui.py:65
                continue;
            }
        }
        // Suisui.py:66
        if(([&]()->V{V operand_76;operand_76=([&]()->V{auto fn_78=attr(self_value(),"is_con_full");Args args_77;return invoke(fn_78,args_77);}());if(!operand_76.truth())return operand_76;return ([&]()->V{auto fn_80=attr(self_value(),"forte3_available");Args args_79;return invoke(fn_80,args_79);}());}()).truth()){
            // Suisui.py:67
            return V{};
        }
        // Suisui.py:68
        ([&]()->V{auto fn_82=attr(self_value(),"click");Args args_81;args_81.kw("after_sleep",V(0.1));return invoke(fn_82,args_81);}());
    }
    // Suisui.py:69
    ([&]()->V{auto fn_89=attr(attr(self_value(),"logger"),"warning");Args args_88;args_88.pos(V("Suisui concerto fill timed out"));return invoke(fn_89,args_88);}());
return V{};
}),false);
// Official method Suisui.try_e, lines 71-77
register_method("try_e",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_90=bind_arguments(official_args,signature,captured);
scope_90->set("start",V::missing());
    // Suisui.py:72
    if(([&]()->V{auto fn_92=attr(attr(self_value(),"task"),"find_one");Args args_91;args_91.pos(attr(global("Labels","Suisui"),"suisui_e1"));return invoke(fn_92,args_91);}()).truth()){
        // Suisui.py:73
        {V value_93=([&]()->V{auto fn_95=attr(global("time","Suisui"),"time");Args args_94;return invoke(fn_95,args_94);}());scope_90->set("start",value_93);}
        // Suisui.py:74
                while(([&]()->V{V operand_100;operand_100=([&]()->V{auto fn_102=attr(attr(self_value(),"task"),"find_one");Args args_101;args_101.pos(attr(global("Labels","Suisui"),"suisui_e1"));return invoke(fn_102,args_101);}());if(!operand_100.truth())return operand_100;return ([&]()->V{V compare_103=([&]()->V{auto fn_106=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_105;args_105.pos(scope_90->get("start"));return invoke(fn_106,args_105);}());V compare_104;V comparison_result_107;compare_104=V(2LL);comparison_result_107=compare_value("<",compare_103,compare_104);return comparison_result_107;}());}()).truth()){
            // Suisui.py:75
            ([&]()->V{auto fn_97=attr(self_value(),"send_resonance_key");Args args_96;return invoke(fn_97,args_96);}());
            // Suisui.py:76
            ([&]()->V{auto fn_99=attr(self_value(),"sleep");Args args_98;args_98.pos(V(0.05));return invoke(fn_99,args_98);}());
        }
        // Suisui.py:77
        return V(true);
    }
return V{};
}),false);
// Official method Suisui.forte3_available, lines 79-80
register_method("forte3_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_108=bind_arguments(official_args,signature,captured);
    // Suisui.py:80
    return ([&]()->V{auto fn_110=global("bool","Suisui");Args args_109;args_109.pos(([&]()->V{auto fn_112=attr(attr(self_value(),"task"),"find_one");Args args_111;args_111.pos(attr(global("Labels","Suisui"),"suisui_forte3"));args_111.kw("threshold",V(0.75));return invoke(fn_112,args_111);}()));return invoke(fn_110,args_109);}());
return V{};
}),false);
// Official method Suisui.forte2_available, lines 82-83
register_method("forte2_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_113=bind_arguments(official_args,signature,captured);
    // Suisui.py:83
    return ([&]()->V{auto fn_115=global("bool","Suisui");Args args_114;args_114.pos(([&]()->V{auto fn_117=attr(attr(self_value(),"task"),"find_one");Args args_116;args_116.pos(attr(global("Labels","Suisui"),"suisui_forte2"));args_116.kw("threshold",V(0.75));return invoke(fn_117,args_116);}()));return invoke(fn_115,args_114);}());
return V{};
}),false);
// Official method Suisui.switch_out, lines 85-88
register_method("switch_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_118=bind_arguments(official_args,signature,captured);
    // Suisui.py:86
    ([&]()->V{auto fn_122=attr(([&]()->V{auto fn_120=global("super","Suisui");Args args_119;return invoke(fn_120,args_119);}()),"switch_out");Args args_121;args_121.kw("con_full",scope_118->get("con_full"));return invoke(fn_122,args_121);}());
    // Suisui.py:87
    if(scope_118->get("con_full").truth()){
        // Suisui.py:88
        {V value_123=([&]()->V{auto fn_125=attr(global("time","Suisui"),"time");Args args_124;return invoke(fn_125,args_124);}());set_attr(self_value(),"last_forte3_switch",value_123);}
    }
return V{};
}),false);
// Official method Suisui.get_switch_priority, lines 90-103
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_126=bind_arguments(official_args,signature,captured);
scope_126->set("char",V::missing());
scope_126->set("has_main_dps",V::missing());
scope_126->set("since_last",V::missing());
    // Suisui.py:91
    {V value_127=([&]()->V{auto fn_129=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_128;args_128.pos(attr(self_value(),"last_forte3_switch"));return invoke(fn_129,args_128);}());scope_126->set("since_last",value_127);}
    // Suisui.py:92
    if(([&]()->V{V compare_130=scope_126->get("since_last");V compare_131;V comparison_result_132;compare_131=V(40LL);comparison_result_132=compare_value(">",compare_130,compare_131);return comparison_result_132;}()).truth()){
        // Suisui.py:93
        return attr(global("SwitchPriority","Suisui"),"MUST");
    }else{
        // Suisui.py:94
        if(([&]()->V{V compare_133=scope_126->get("since_last");V compare_134;V comparison_result_135;compare_134=attr(self_value(),"FORTE3_SWITCH_LOCKOUT");comparison_result_135=compare_value("<",compare_133,compare_134);return comparison_result_135;}()).truth()){
            // Suisui.py:95
            return attr(global("SwitchPriority","Suisui"),"NO");
        }
    }
    // Suisui.py:96
    {V value_136=([&]()->V{auto generator_scope_137=std::make_shared<Scope>(scope_126);auto iterator_142=official::iterate(([&]()->V{auto fn_145=global("getattr","Suisui");Args args_144;args_144.pos(attr(self_value(),"task"));args_144.pos(V("chars"));args_144.pos(V::list({}));return invoke(fn_145,args_144);}()));V value_143;while(iterator_142.next(value_143)){generator_scope_137->set("char",value_143);if(([&]()->V{V operand_138;operand_138=generator_scope_137->get("char");if(!operand_138.truth())return operand_138;operand_138=([&]()->V{V compare_139=generator_scope_137->get("char");V compare_140;V comparison_result_141;compare_140=self_value();comparison_result_141=compare_value("!=",compare_139,compare_140);return comparison_result_141;}());if(!operand_138.truth())return operand_138;return attr(generator_scope_137->get("char"),"is_main_dps");}()).truth())return V(true);}return V(false);}());scope_126->set("has_main_dps",value_136);}
    // Suisui.py:100
    if(scope_126->get("has_main_dps").truth()){
        // Suisui.py:101
        if(([&]()->V{V operand_146;operand_146=scope_126->get("current_char");if(!operand_146.truth())return operand_146;operand_146=attr(scope_126->get("current_char"),"is_main_dps");if(!operand_146.truth())return operand_146;return scope_126->get("has_intro");}()).truth()){
            // Suisui.py:102
            return attr(global("SwitchPriority","Suisui"),"MUST");
        }
    }
    // Suisui.py:103
    return ([&]()->V{auto fn_150=attr(([&]()->V{auto fn_148=global("super","Suisui");Args args_147;return invoke(fn_148,args_147);}()),"get_switch_priority");Args args_149;args_149.pos(scope_126->get("current_char"));args_149.pos(scope_126->get("has_intro"));args_149.pos(scope_126->get("target_low_con"));return invoke(fn_150,args_149);}());
return V{};
}),false);
}
