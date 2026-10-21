// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Mornye.py
// SHA256 eb525c0ef2c79b61a94a1142935df445938ca2eb37701ddab9897e61610ff118
void OfficialCharacter::install_Mornye(){
auto scope=std::make_shared<Scope>();
// Official method Mornye.__init__, lines 6-9
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Mornye.py:7
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Mornye");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Mornye.py:8
    {V value_6=V(0LL);set_attr(self_value(),"last_heavy",value_6);}
    // Mornye.py:9
    {V value_7=V(false);set_attr(self_value(),"echo_lit_on_air",value_7);}
return V{};
}),false);
// Official method Mornye.do_perform, lines 11-30
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Mornye.py:12
    if(attr(self_value(),"has_intro").truth()){
        // Mornye.py:13
        ([&]()->V{auto fn_10=attr(self_value(),"continues_normal_attack");Args args_9;args_9.pos(V(1.33));return invoke(fn_10,args_9);}());
    }
    // Mornye.py:14
    {V value_11=V(true);set_attr(self_value(),"check_f_on_switch",value_11);}
    // Mornye.py:15
    if(unary("not",([&]()->V{auto fn_13=attr(self_value(),"on_air");Args args_12;return invoke(fn_13,args_12);}())).truth()){
        // Mornye.py:16
        if(([&]()->V{auto fn_15=attr(self_value(),"combo_limit");Args args_14;return invoke(fn_15,args_14);}()).truth()){
            // Mornye.py:17
            ([&]()->V{auto fn_17=attr(attr(self_value(),"logger"),"debug");Args args_16;args_16.pos(V("perform quick actions"));return invoke(fn_17,args_16);}());
            // Mornye.py:18
            if(([&]()->V{auto fn_19=attr(self_value(),"click_echo");Args args_18;return invoke(fn_19,args_18);}()).truth()){
                // Mornye.py:19
                return ([&]()->V{auto fn_21=attr(self_value(),"switch_next_char");Args args_20;return invoke(fn_21,args_20);}());
            }else{
                // Mornye.py:20
                if(item(([&]()->V{auto fn_23=attr(self_value(),"click_resonance");Args args_22;return invoke(fn_23,args_22);}()),V(0LL)).truth()){
                    // Mornye.py:22
                    return ([&]()->V{auto fn_25=attr(self_value(),"switch_next_char");Args args_24;return invoke(fn_25,args_24);}());
                }else{
                    // Mornye.py:24
                    ([&]()->V{auto fn_27=attr(self_value(),"continues_normal_attack");Args args_26;args_26.pos(V(0.1));return invoke(fn_27,args_26);}());
                    // Mornye.py:25
                    return ([&]()->V{auto fn_29=attr(self_value(),"switch_next_char");Args args_28;return invoke(fn_29,args_28);}());
                }
            }
        }
        // Mornye.py:26
        ([&]()->V{auto fn_31=attr(self_value(),"not_on_air_actions");Args args_30;return invoke(fn_31,args_30);}());
    }
    // Mornye.py:28
    if(([&]()->V{auto fn_33=attr(self_value(),"on_air");Args args_32;return invoke(fn_33,args_32);}()).truth()){
        // Mornye.py:29
        ([&]()->V{auto fn_35=attr(self_value(),"on_air_actions");Args args_34;return invoke(fn_35,args_34);}());
    }
    // Mornye.py:30
    ([&]()->V{auto fn_37=attr(self_value(),"switch_next_char");Args args_36;return invoke(fn_37,args_36);}());
return V{};
}),false);
// Official method Mornye.on_air, lines 32-33
register_method("on_air",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_38=bind_arguments(official_args,signature,captured);
    // Mornye.py:33
    return ([&]()->V{auto fn_40=attr(self_value(),"has_long_action2");Args args_39;return invoke(fn_40,args_39);}());
return V{};
}),false);
// Official method Mornye.on_air_actions, lines 35-69
register_method("on_air_actions",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_41=bind_arguments(official_args,signature,captured);
scope_41->set("fill_start",V::missing());
scope_41->set("start",V::missing());
    // Mornye.py:36
    {V value_42=V(false);set_attr(self_value(),"echo_lit_on_air",value_42);}
    // Mornye.py:37
    ([&]()->V{auto fn_44=attr(attr(self_value(),"logger"),"debug");Args args_43;args_43.pos(V("on_air start attacking"));return invoke(fn_44,args_43);}());
    // Mornye.py:38
    {V value_45=([&]()->V{auto fn_47=attr(global("time","Mornye"),"time");Args args_46;return invoke(fn_47,args_46);}());scope_41->set("start",value_45);}
    // Mornye.py:39
        while(([&]()->V{V operand_117;operand_117=([&]()->V{V compare_118=([&]()->V{V left_120=([&]()->V{auto fn_123=attr(global("time","Mornye"),"time");Args args_122;return invoke(fn_123,args_122);}());V right_121=scope_41->get("start");return official::binary("-",left_120,right_121);}());V compare_119;V comparison_result_124;compare_119=V(10LL);comparison_result_124=compare_value("<",compare_118,compare_119);return comparison_result_124;}());if(!operand_117.truth())return operand_117;return ([&]()->V{auto fn_126=attr(self_value(),"on_air");Args args_125;return invoke(fn_126,args_125);}());}()).truth()){
        // Mornye.py:43
        if(([&]()->V{auto fn_49=attr(self_value(),"detect_elbow_strike");Args args_48;return invoke(fn_49,args_48);}()).truth()){
            // Mornye.py:44
            ([&]()->V{auto fn_51=attr(attr(self_value(),"logger"),"debug");Args args_50;args_50.pos(V("Detected an elbow strike, attempting to reset."));return invoke(fn_51,args_50);}());
            // Mornye.py:45
            ([&]()->V{auto fn_53=attr(attr(self_value(),"task"),"wait_until");Args args_52;args_52.pos(V::function([this,captured=capture_scope(scope_41,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_54=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_56=attr(self_value(),"detect_elbow_strike");Args args_55;return invoke(fn_56,args_55);}()));
}));args_52.kw("post_action",V::function([this,captured=capture_scope(scope_41,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_57=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_59=attr(self_value(),"continues_right_click");Args args_58;args_58.pos(V(0.05));return invoke(fn_59,args_58);}());
}));args_52.kw("time_out",V(1.5));return invoke(fn_53,args_52);}());
        }
        // Mornye.py:47
        ([&]()->V{auto fn_61=attr(self_value(),"click_liberation");Args args_60;return invoke(fn_61,args_60);}());
        // Mornye.py:48
        if(([&]()->V{V operand_62;operand_62=([&]()->V{auto fn_64=attr(self_value(),"on_air");Args args_63;return invoke(fn_64,args_63);}());if(!operand_62.truth())return operand_62;return ([&]()->V{auto fn_66=attr(self_value(),"is_mouse_forte_full");Args args_65;return invoke(fn_66,args_65);}());}()).truth()){
            // Mornye.py:49
            ([&]()->V{auto fn_68=attr(attr(self_value(),"logger"),"debug");Args args_67;args_67.pos(V("mouse forte full, heavy attack"));return invoke(fn_68,args_67);}());
            // Mornye.py:50
            if(([&]()->V{auto fn_70=attr(self_value(),"heavy_click_forte");Args args_69;args_69.kw("check_fun",V::function([this,captured=capture_scope(scope_41,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_71=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_72;operand_72=([&]()->V{auto fn_74=attr(self_value(),"is_mouse_forte_full");Args args_73;return invoke(fn_74,args_73);}());if(!operand_72.truth())return operand_72;return unary("not",([&]()->V{auto fn_76=attr(self_value(),"detect_elbow_strike");Args args_75;return invoke(fn_76,args_75);}()));}());
}));return invoke(fn_70,args_69);}()).truth()){
                // Mornye.py:52
                if(([&]()->V{auto fn_78=attr(self_value(),"detect_elbow_strike");Args args_77;return invoke(fn_78,args_77);}()).truth()){
                    // Mornye.py:53
                    continue;
                }
                // Mornye.py:55
                if(unary("not",([&]()->V{auto fn_80=attr(attr(self_value(),"task"),"wait_until");Args args_79;args_79.pos(V::function([this,captured=capture_scope(scope_41,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_81=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_83=attr(self_value(),"is_con_full");Args args_82;return invoke(fn_83,args_82);}());
}));args_79.kw("time_out",V(1.5));return invoke(fn_80,args_79);}())).truth()){
                    // Mornye.py:56
                    {V value_84=([&]()->V{auto fn_86=attr(global("time","Mornye"),"time");Args args_85;return invoke(fn_86,args_85);}());scope_41->set("fill_start",value_84);}
                    // Mornye.py:57
                                        while(([&]()->V{V operand_91;operand_91=unary("not",([&]()->V{auto fn_93=attr(self_value(),"is_con_full");Args args_92;return invoke(fn_93,args_92);}()));if(!operand_91.truth())return operand_91;operand_91=([&]()->V{V compare_94=([&]()->V{V left_96=([&]()->V{auto fn_99=attr(global("time","Mornye"),"time");Args args_98;return invoke(fn_99,args_98);}());V right_97=scope_41->get("fill_start");return official::binary("-",left_96,right_97);}());V compare_95;V comparison_result_100;compare_95=V(2LL);comparison_result_100=compare_value("<",compare_94,compare_95);return comparison_result_100;}());if(!operand_91.truth())return operand_91;return ([&]()->V{auto fn_102=attr(self_value(),"on_air");Args args_101;return invoke(fn_102,args_101);}());}()).truth()){
                        // Mornye.py:58
                        ([&]()->V{auto fn_88=attr(self_value(),"continues_normal_attack");Args args_87;args_87.pos(V(0.5));return invoke(fn_88,args_87);}());
                        // Mornye.py:59
                        if(([&]()->V{auto fn_90=attr(self_value(),"detect_elbow_strike");Args args_89;return invoke(fn_90,args_89);}()).truth()){
                            // Mornye.py:60
                            break;
                        }
                    }
                    // Mornye.py:61
                    if(unary("not",([&]()->V{auto fn_104=attr(self_value(),"is_con_full");Args args_103;return invoke(fn_104,args_103);}())).truth()){
                        // Mornye.py:62
                        ([&]()->V{auto fn_106=attr(self_value(),"click_echo");Args args_105;args_105.kw("duration",V(0.2));return invoke(fn_106,args_105);}());
                    }
                }
                // Mornye.py:63
                {V value_107=([&]()->V{auto fn_109=attr(global("time","Mornye"),"time");Args args_108;return invoke(fn_109,args_108);}());set_attr(self_value(),"last_heavy",value_107);}
                // Mornye.py:64
                {V value_110=V(false);set_attr(self_value(),"check_f_on_switch",value_110);}
                // Mornye.py:65
                break;
            }
        }
        // Mornye.py:66
        ([&]()->V{auto fn_112=attr(self_value(),"click_resonance");Args args_111;return invoke(fn_112,args_111);}());
        // Mornye.py:67
        ([&]()->V{auto fn_114=attr(self_value(),"click");Args args_113;return invoke(fn_114,args_113);}());
        // Mornye.py:68
        ([&]()->V{auto fn_116=attr(self_value(),"sleep");Args args_115;args_115.pos(V(0.01));return invoke(fn_116,args_115);}());
    }
    // Mornye.py:69
    ([&]()->V{auto fn_128=attr(attr(self_value(),"logger"),"debug");Args args_127;args_127.pos(V("finished attacking on_air"));return invoke(fn_128,args_127);}());
return V{};
}),false);
// Official method Mornye.not_on_air_actions, lines 71-85
register_method("not_on_air_actions",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_129=bind_arguments(official_args,signature,captured);
scope_129->set("start",V::missing());
scope_129->set("try_douge",V::missing());
    // Mornye.py:72
    ([&]()->V{auto fn_131=attr(attr(self_value(),"logger"),"debug");Args args_130;args_130.pos(V("not on_air start attacking"));return invoke(fn_131,args_130);}());
    // Mornye.py:73
    {V value_132=([&]()->V{auto fn_134=attr(global("time","Mornye"),"time");Args args_133;return invoke(fn_134,args_133);}());scope_129->set("start",value_132);}
    // Mornye.py:74
    {V value_135=V(true);scope_129->set("try_douge",value_135);}
    // Mornye.py:75
        while(([&]()->V{V operand_153;operand_153=([&]()->V{V compare_154=([&]()->V{V left_156=([&]()->V{auto fn_159=attr(global("time","Mornye"),"time");Args args_158;return invoke(fn_159,args_158);}());V right_157=scope_129->get("start");return official::binary("-",left_156,right_157);}());V compare_155;V comparison_result_160;compare_155=V(10LL);comparison_result_160=compare_value("<",compare_154,compare_155);return comparison_result_160;}());if(!operand_153.truth())return operand_153;return unary("not",([&]()->V{auto fn_162=attr(self_value(),"on_air");Args args_161;return invoke(fn_162,args_161);}()));}()).truth()){
        // Mornye.py:76
        ([&]()->V{auto fn_137=attr(self_value(),"click");Args args_136;return invoke(fn_137,args_136);}());
        // Mornye.py:77
        ([&]()->V{auto fn_139=attr(self_value(),"click_resonance");Args args_138;return invoke(fn_139,args_138);}());
        // Mornye.py:78
        ([&]()->V{auto fn_141=attr(self_value(),"check_combat");Args args_140;return invoke(fn_141,args_140);}());
        // Mornye.py:79
        ([&]()->V{auto fn_143=attr(self_value(),"sleep");Args args_142;args_142.pos(V(0.1));return invoke(fn_143,args_142);}());
        // Mornye.py:80
        if(([&]()->V{auto fn_145=attr(self_value(),"is_mouse_forte_full");Args args_144;return invoke(fn_145,args_144);}()).truth()){
            // Mornye.py:81
            if(scope_129->get("try_douge").truth()){
                // Mornye.py:82
                ([&]()->V{auto fn_147=attr(attr(self_value(),"task"),"click");Args args_146;args_146.kw("key",V("right"));return invoke(fn_147,args_146);}());
                // Mornye.py:83
                {V value_148=V(false);scope_129->set("try_douge",value_148);}
            }
            // Mornye.py:84
            ([&]()->V{auto fn_150=attr(self_value(),"heavy_attack");Args args_149;return invoke(fn_150,args_149);}());
            // Mornye.py:85
            ([&]()->V{auto fn_152=attr(self_value(),"sleep");Args args_151;args_151.pos(V(0.3));return invoke(fn_152,args_151);}());
        }
    }
return V{};
}),false);
// Official method Mornye.on_combat_end, lines 87-88
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_163=bind_arguments(official_args,signature,captured);
    // Mornye.py:88
    ([&]()->V{auto fn_165=attr(self_value(),"switch_other_char");Args args_164;return invoke(fn_165,args_164);}());
return V{};
}),false);
// Official method Mornye.combo_limit, lines 90-91
register_method("combo_limit",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_166=bind_arguments(official_args,signature,captured);
    // Mornye.py:91
    return ([&]()->V{V compare_167=([&]()->V{auto fn_170=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_169;args_169.pos(attr(self_value(),"last_heavy"));return invoke(fn_170,args_169);}());V compare_168;V comparison_result_171;compare_168=V(23LL);comparison_result_171=compare_value("<",compare_167,compare_168);return comparison_result_171;}());
return V{};
}),false);
// Official method Mornye.get_switch_priority, lines 93-99
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_172=bind_arguments(official_args,signature,captured);
scope_172->set("Linnai",V::missing());
    // Mornye.py:94
    if(([&]()->V{V operand_173;operand_173=scope_172->get("has_intro");if(!operand_173.truth())return operand_173;operand_173=scope_172->get("current_char");if(!operand_173.truth())return operand_173;return ([&]()->V{V compare_174=attr(scope_172->get("current_char"),"char_name");V compare_175;V comparison_result_176;compare_175=V::set({V("char_aemeath"),V("char_qingxiao")});comparison_result_176=compare_value("in",compare_174,compare_175);return comparison_result_176;}());}()).truth()){
        // Mornye.py:95
        return attr(global("SwitchPriority","Mornye"),"MUST");
    }
    // Mornye.py:96
    scope_172->set("Linnai",import_value("src.char.Linnai","Linnai"));
    // Mornye.py:97
    if(([&]()->V{V operand_177;operand_177=scope_172->get("has_intro");if(!operand_177.truth())return operand_177;operand_177=scope_172->get("current_char");if(!operand_177.truth())return operand_177;operand_177=([&]()->V{auto fn_179=attr(attr(self_value(),"task"),"has_char");Args args_178;args_178.pos(scope_172->get("Linnai"));return invoke(fn_179,args_178);}());if(!operand_177.truth())return operand_177;return ([&]()->V{V compare_180=attr(scope_172->get("current_char"),"char_name");V compare_181;V comparison_result_182;compare_181=V("char_linnai");comparison_result_182=compare_value("!=",compare_180,compare_181);return comparison_result_182;}());}()).truth()){
        // Mornye.py:98
        return attr(global("SwitchPriority","Mornye"),"MUST");
    }
    // Mornye.py:99
    return ([&]()->V{auto fn_186=attr(([&]()->V{auto fn_184=global("super","Mornye");Args args_183;return invoke(fn_184,args_183);}()),"get_switch_priority");Args args_185;args_185.pos(scope_172->get("current_char"));args_185.pos(scope_172->get("has_intro"));args_185.pos(scope_172->get("target_low_con"));return invoke(fn_186,args_185);}());
return V{};
}),false);
// Official method Mornye.detect_elbow_strike, lines 101-106
register_method("detect_elbow_strike",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_187=bind_arguments(official_args,signature,captured);
    // Mornye.py:103
    if(([&]()->V{auto fn_189=attr(self_value(),"available");Args args_188;args_188.pos(V("echo"));args_188.kw("check_color",V(true));return invoke(fn_189,args_188);}()).truth()){
        // Mornye.py:104
        {V value_190=V(true);set_attr(self_value(),"echo_lit_on_air",value_190);}
        // Mornye.py:105
        return V(false);
    }
    // Mornye.py:106
    return attr(self_value(),"echo_lit_on_air");
return V{};
}),false);
}
