#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Hiyuki.py
// SHA256 2a02fa199feb60a882398c8d51e82ac17d6415d886aec84a93ed943656bd0fa4
void OfficialCharacter::install_Hiyuki(){
auto scope=std::make_shared<Scope>();
set_class_attribute("FIELD_TIME_OUT",V(16.0));
set_class_attribute("LINNAI_FIELD_TIME_OUT",V(18.0));
set_class_attribute("HOLD_LIB_TIME_OUT",V(8.0));
set_class_attribute("STANDARD_LIB_CD_MAX",V(3.5));
set_class_attribute("INTRO_NORMAL_ATTACK_TIME",V(1.0));
set_class_attribute("POST_RES_NORMAL_ATTACK_TIME",V(0.3));
set_class_attribute("POST_LIB_SETTLE",V(0.5));
set_class_attribute("LIB2_KENDO_COUNT",V(4LL));
set_class_attribute("HOLD_LIB_CD_WAIT",V(1.5));
set_class_attribute("WAIT_LOCK_TIME_OUT",V(2.0));
// Official method Hiyuki.__init__, lines 26-30
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Hiyuki.py:27
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Hiyuki");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Hiyuki.py:28
    {V value_6=V(true);set_attr(self_value(),"lib_permission",value_6);}
    // Hiyuki.py:30
    {V value_7=V(0LL);set_attr(self_value(),"lib2_count",value_7);}
return V{};
}),false);
// Official method Hiyuki.switch_out, lines 32-35
register_method("switch_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Hiyuki.py:34
    ([&]()->V{auto fn_12=attr(([&]()->V{auto fn_10=global("super","Hiyuki");Args args_9;return invoke(fn_10,args_9);}()),"switch_out");Args args_11;args_11.pos(scope_8->get("con_full"));return invoke(fn_12,args_11);}());
    // Hiyuki.py:35
    {V value_13=V(0LL);set_attr(self_value(),"lib2_count",value_13);}
return V{};
}),false);
// Official method Hiyuki.do_perform, lines 37-57
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_14=bind_arguments(official_args,signature,captured);
scope_14->set("lib_success",V::missing());
    // Hiyuki.py:38
    if(attr(self_value(),"has_intro").truth()){
        // Hiyuki.py:39
        ([&]()->V{auto fn_16=attr(self_value(),"continues_normal_attack");Args args_15;args_15.pos(attr(self_value(),"INTRO_NORMAL_ATTACK_TIME"));return invoke(fn_16,args_15);}());
    }
    // Hiyuki.py:41
    if(([&]()->V{V operand_17;operand_17=([&]()->V{auto fn_19=attr(self_value(),"has_long_action");Args args_18;return invoke(fn_19,args_18);}());if(!operand_17.truth())return operand_17;return ([&]()->V{V compare_20=([&]()->V{auto fn_23=attr(attr(self_value(),"task"),"get_cd");Args args_22;args_22.pos(V("liberation"));return invoke(fn_23,args_22);}());V compare_21;V comparison_result_24;compare_21=attr(self_value(),"STANDARD_LIB_CD_MAX");comparison_result_24=compare_value("<=",compare_20,compare_21);return comparison_result_24;}());}()).truth()){
        // Hiyuki.py:42
        ([&]()->V{auto fn_26=attr(self_value(),"perform_standard");Args args_25;return invoke(fn_26,args_25);}());
    }
    // Hiyuki.py:44
    if(([&]()->V{auto fn_28=attr(self_value(),"has_long_action2");Args args_27;return invoke(fn_28,args_27);}()).truth()){
        // Hiyuki.py:45
        {V value_29=([&]()->V{auto fn_31=attr(self_value(),"perform_lib");Args args_30;return invoke(fn_31,args_30);}());scope_14->set("lib_success",value_29);}
        // Hiyuki.py:46
        if(scope_14->get("lib_success").truth()){
            // Hiyuki.py:47
            ([&]()->V{auto fn_33=attr(self_value(),"sleep");Args args_32;args_32.pos(attr(self_value(),"POST_LIB_SETTLE"));return invoke(fn_33,args_32);}());
            // Hiyuki.py:48
            ([&]()->V{auto fn_35=attr(self_value(),"switch_next_char");Args args_34;return invoke(fn_35,args_34);}());
            // Hiyuki.py:49
            return V{};
        }else{
            // Hiyuki.py:51
            if(([&]()->V{V operand_36;operand_36=attr(self_value(),"lib_permission");if(!operand_36.truth())return operand_36;return ([&]()->V{auto fn_38=attr(self_value(),"liberation_available");Args args_37;return invoke(fn_38,args_37);}());}()).truth()){
                // Hiyuki.py:52
                if(([&]()->V{auto fn_40=attr(self_value(),"hold_liberation");Args args_39;return invoke(fn_40,args_39);}()).truth()){
                    // Hiyuki.py:53
                    ([&]()->V{auto fn_42=attr(self_value(),"sleep");Args args_41;args_41.pos(attr(self_value(),"POST_LIB_SETTLE"));return invoke(fn_42,args_41);}());
                    // Hiyuki.py:54
                    ([&]()->V{auto fn_44=attr(self_value(),"switch_next_char");Args args_43;return invoke(fn_44,args_43);}());
                    // Hiyuki.py:55
                    return V{};
                }
            }
        }
    }
    // Hiyuki.py:57
    ([&]()->V{auto fn_46=attr(self_value(),"switch_next_char");Args args_45;return invoke(fn_46,args_45);}());
return V{};
}),false);
// Official method Hiyuki.perform_standard, lines 59-82
register_method("perform_standard",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_47=bind_arguments(official_args,signature,captured);
scope_47->set("timeout",V::missing());
    // Hiyuki.py:60
    {V value_48=attr(self_value(),"FIELD_TIME_OUT");scope_47->set("timeout",value_48);}
    // Hiyuki.py:61
    if(([&]()->V{V operand_49;operand_49=attr(self_value(),"has_intro");if(!operand_49.truth())return operand_49;return ([&]()->V{V compare_50=([&]()->V{auto fn_53=attr(self_value(),"check_outro");Args args_52;return invoke(fn_53,args_52);}());V compare_51;V comparison_result_54;compare_51=V("char_linnai");comparison_result_54=compare_value("==",compare_50,compare_51);return comparison_result_54;}());}()).truth()){
        // Hiyuki.py:62
        {V value_55=attr(self_value(),"LINNAI_FIELD_TIME_OUT");scope_47->set("timeout",value_55);}
    }
    // Hiyuki.py:64
        while(([&]()->V{V operand_82;operand_82=([&]()->V{auto fn_84=attr(self_value(),"has_long_action");Args args_83;return invoke(fn_84,args_83);}());if(!operand_82.truth())return operand_82;return ([&]()->V{V compare_85=([&]()->V{auto fn_88=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_87;args_87.pos(attr(self_value(),"last_perform"));return invoke(fn_88,args_87);}());V compare_86;V comparison_result_89;compare_86=scope_47->get("timeout");comparison_result_89=compare_value("<",compare_85,compare_86);return comparison_result_89;}());}()).truth()){
        // Hiyuki.py:65
        ([&]()->V{auto fn_57=attr(self_value(),"click_echo");Args args_56;args_56.kw("time_out",V(0LL));return invoke(fn_57,args_56);}());
        // Hiyuki.py:66
        ([&]()->V{auto fn_59=attr(self_value(),"click_resonance");Args args_58;args_58.kw("send_click",V(false));args_58.kw("time_out",V(0LL));return invoke(fn_59,args_58);}());
        // Hiyuki.py:68
        if(([&]()->V{auto fn_61=attr(self_value(),"liberation_available");Args args_60;return invoke(fn_61,args_60);}()).truth()){
            // Hiyuki.py:69
            if(([&]()->V{auto fn_63=attr(self_value(),"click_liberation");Args args_62;return invoke(fn_63,args_62);}()).truth()){
                // Hiyuki.py:70
                ([&]()->V{auto fn_65=attr(attr(self_value(),"logger"),"debug");Args args_64;args_64.pos(V("hiyuki perform lib1"));return invoke(fn_65,args_64);}());
                // Hiyuki.py:71
                return V{};
            }
        }
        // Hiyuki.py:73
        if(([&]()->V{auto fn_67=attr(self_value(),"is_mouse_forte_full");Args args_66;return invoke(fn_67,args_66);}()).truth()){
            // Hiyuki.py:74
            ([&]()->V{auto fn_69=attr(attr(self_value(),"task"),"click");Args args_68;args_68.kw("key",V("right"));return invoke(fn_69,args_68);}());
            // Hiyuki.py:75
            ([&]()->V{auto fn_71=attr(self_value(),"heavy_click_forte");Args args_70;args_70.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_71,args_70);}());
            // Hiyuki.py:76
            ([&]()->V{auto fn_73=attr(attr(self_value(),"task"),"wait_until");Args args_72;args_72.pos(attr(self_value(),"liberation_available"));args_72.kw("post_action",attr(self_value(),"click_with_interval"));args_72.kw("time_out",attr(self_value(),"FIELD_TIME_OUT"));return invoke(fn_73,args_72);}());
            // Hiyuki.py:77
            if(([&]()->V{auto fn_75=attr(self_value(),"click_liberation");Args args_74;return invoke(fn_75,args_74);}()).truth()){
                // Hiyuki.py:78
                ([&]()->V{auto fn_77=attr(attr(self_value(),"logger"),"debug");Args args_76;args_76.pos(V("hiyuki perform lib1"));return invoke(fn_77,args_76);}());
                // Hiyuki.py:79
                return V{};
            }
        }else{
            // Hiyuki.py:81
            ([&]()->V{auto fn_79=attr(self_value(),"click");Args args_78;args_78.kw("interval",V(0.1));return invoke(fn_79,args_78);}());
        }
        // Hiyuki.py:82
        ([&]()->V{auto fn_81=attr(self_value(),"sleep");Args args_80;args_80.pos(V(0.05));return invoke(fn_81,args_80);}());
    }
return V{};
}),false);
// Official method Hiyuki.perform_lib, lines 84-147
register_method("perform_lib",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_90=bind_arguments(official_args,signature,captured);
scope_90->set("is_timeout",V::missing());
scope_90->set("lib_heavy_avail",V::missing());
scope_90->set("res_resonance",V::missing());
scope_90->set("start",V::missing());
scope_90->set("timeout",V::missing());
    // Hiyuki.py:85
    {V value_91=([&]()->V{auto fn_93=attr(global("time","Hiyuki"),"time");Args args_92;return invoke(fn_93,args_92);}());scope_90->set("start",value_91);}
    // Hiyuki.py:86
    {V value_94=attr(self_value(),"FIELD_TIME_OUT");scope_90->set("timeout",value_94);}
    // Hiyuki.py:87
    if(([&]()->V{V operand_95;operand_95=attr(self_value(),"has_intro");if(!operand_95.truth())return operand_95;return ([&]()->V{V compare_96=([&]()->V{auto fn_99=attr(self_value(),"check_outro");Args args_98;return invoke(fn_99,args_98);}());V compare_97;V comparison_result_100;compare_97=V("char_linnai");comparison_result_100=compare_value("==",compare_96,compare_97);return comparison_result_100;}());}()).truth()){
        // Hiyuki.py:88
        {V value_101=attr(self_value(),"LINNAI_FIELD_TIME_OUT");scope_90->set("timeout",value_101);}
    }
    // Hiyuki.py:90
    {V value_102=V(false);scope_90->set("is_timeout",value_102);}
    // Hiyuki.py:92
        while(([&]()->V{V operand_183;operand_183=([&]()->V{auto fn_185=attr(self_value(),"has_long_action2");Args args_184;return invoke(fn_185,args_184);}());if(!operand_183.truth())return operand_183;return ([&]()->V{V compare_186=([&]()->V{auto fn_189=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_188;args_188.pos(scope_90->get("start"));return invoke(fn_189,args_188);}());V compare_187;V comparison_result_190;compare_187=scope_90->get("timeout");comparison_result_190=compare_value("<",compare_186,compare_187);return comparison_result_190;}());}()).truth()){
        // Hiyuki.py:93
        ([&]()->V{auto fn_104=attr(self_value(),"f_break");Args args_103;return invoke(fn_104,args_103);}());
        // Hiyuki.py:94
        ([&]()->V{auto fn_106=attr(self_value(),"click_echo");Args args_105;args_105.kw("time_out",V(0LL));return invoke(fn_106,args_105);}());
        // Hiyuki.py:97
        {V value_107=([&]()->V{auto fn_109=attr(self_value(),"lib_heavy_available");Args args_108;return invoke(fn_109,args_108);}());scope_90->set("lib_heavy_avail",value_107);}
        // Hiyuki.py:98
        ([&]()->V{auto fn_111=attr(attr(self_value(),"logger"),"debug");Args args_110;args_110.pos(V(std::string{}+"hiyuki find mouse_forte: "+format_value(scope_90->get("lib_heavy_avail"),"",-1)));return invoke(fn_111,args_110);}());
        // Hiyuki.py:100
        {V value_112=([&]()->V{V compare_113=([&]()->V{auto fn_116=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_115;args_115.pos(scope_90->get("start"));return invoke(fn_116,args_115);}());V compare_114;V comparison_result_117;compare_114=([&]()->V{V left_118=scope_90->get("timeout");V right_119=V(0.5);return official::binary("-",left_118,right_119);}());comparison_result_117=compare_value(">=",compare_113,compare_114);return comparison_result_117;}());scope_90->set("is_timeout",value_112);}
        // Hiyuki.py:101
        if(([&]()->V{V operand_120;operand_120=attr(self_value(),"lib_permission");if(!operand_120.truth())return operand_120;operand_120=([&]()->V{auto fn_122=attr(self_value(),"liberation_available");Args args_121;return invoke(fn_122,args_121);}());if(!operand_120.truth())return operand_120;return ([&]()->V{V operand_123;operand_123=([&]()->V{V compare_124=attr(self_value(),"lib2_count");V compare_125;V comparison_result_126;compare_125=attr(self_value(),"LIB2_KENDO_COUNT");comparison_result_126=compare_value(">=",compare_124,compare_125);return comparison_result_126;}());if(operand_123.truth())return operand_123;return scope_90->get("is_timeout");}());}()).truth()){
            // Hiyuki.py:102
            if(([&]()->V{auto fn_128=attr(self_value(),"hold_liberation");Args args_127;return invoke(fn_128,args_127);}()).truth()){
                // Hiyuki.py:103
                ([&]()->V{auto fn_130=attr(attr(self_value(),"logger"),"info");Args args_129;args_129.pos(V(std::string{}+"hiyuki perform lib2 after heavy (count: "+format_value(attr(self_value(),"lib2_count"),"",-1)+", timeout: "+format_value(scope_90->get("is_timeout"),"",-1)+")"));return invoke(fn_130,args_129);}());
                // Hiyuki.py:104
                {V value_131=V(0LL);set_attr(self_value(),"lib2_count",value_131);}
                // Hiyuki.py:105
                return V(true);
            }
        }
        // Hiyuki.py:108
        {V value_132=([&]()->V{auto fn_134=attr(self_value(),"click_resonance");Args args_133;args_133.kw("send_click",V(false));args_133.kw("time_out",V(0LL));return invoke(fn_134,args_133);}());scope_90->set("res_resonance",value_132);}
        // Hiyuki.py:109
        if(([&]()->V{V operand_135;operand_135=scope_90->get("res_resonance");if(!operand_135.truth())return operand_135;return item(scope_90->get("res_resonance"),V(0LL));}()).truth()){
            // Hiyuki.py:110
            if(scope_90->get("is_timeout").truth()){
                // Hiyuki.py:111
                break;
            }
            // Hiyuki.py:112
            ([&]()->V{auto fn_137=attr(self_value(),"continues_normal_attack");Args args_136;args_136.pos(attr(self_value(),"POST_RES_NORMAL_ATTACK_TIME"));return invoke(fn_137,args_136);}());
        }else{
            // Hiyuki.py:113
            if(([&]()->V{auto fn_139=attr(self_value(),"lib_heavy_available");Args args_138;return invoke(fn_139,args_138);}()).truth()){
                // Hiyuki.py:114
                if(scope_90->get("is_timeout").truth()){
                    // Hiyuki.py:115
                    break;
                }
                // Hiyuki.py:116
                if(([&]()->V{auto fn_141=attr(self_value(),"wait_locked");Args args_140;args_140.pos(attr(self_value(),"WAIT_LOCK_TIME_OUT"));return invoke(fn_141,args_140);}()).truth()){
                    // Hiyuki.py:117
                    ([&]()->V{auto fn_143=attr(self_value(),"heavy_click_forte");Args args_142;args_142.kw("check_fun",attr(self_value(),"lib_heavy_available"));return invoke(fn_143,args_142);}());
                }
                // Hiyuki.py:118
                if(([&]()->V{auto fn_145=attr(attr(self_value(),"task"),"wait_until");Args args_144;args_144.pos(attr(self_value(),"liberation_available"));args_144.kw("post_action",attr(self_value(),"click"));args_144.kw("time_out",V(0.5));return invoke(fn_145,args_144);}()).truth()){
                    // Hiyuki.py:119
                    if(([&]()->V{V operand_146;operand_146=([&]()->V{auto fn_148=attr(self_value(),"wait_locked");Args args_147;args_147.pos(attr(self_value(),"WAIT_LOCK_TIME_OUT"));return invoke(fn_148,args_147);}());if(!operand_146.truth())return operand_146;return ([&]()->V{auto fn_150=attr(self_value(),"hold_liberation");Args args_149;return invoke(fn_150,args_149);}());}()).truth()){
                        // Hiyuki.py:120
                        ([&]()->V{auto fn_152=attr(attr(self_value(),"logger"),"debug");Args args_151;args_151.pos(V("hiyuki perform lib2 (after heavy)"));return invoke(fn_152,args_151);}());
                        // Hiyuki.py:121
                        {V value_153=V(0LL);set_attr(self_value(),"lib2_count",value_153);}
                        // Hiyuki.py:122
                        return V(true);
                    }
                }
                // Hiyuki.py:123
                set_attr(self_value(),"lib2_count",official::binary("+",attr(self_value(),"lib2_count"),V(1LL)));
                // Hiyuki.py:124
                ([&]()->V{auto fn_155=attr(self_value(),"sleep");Args args_154;args_154.pos(V(0.1));return invoke(fn_155,args_154);}());
                // Hiyuki.py:125
                ([&]()->V{auto fn_157=attr(attr(self_value(),"logger"),"debug");Args args_156;args_156.pos(V(std::string{}+"hiyuki heavy  count: "+format_value(attr(self_value(),"lib2_count"),"",-1)));return invoke(fn_157,args_156);}());
            }else{
                // Hiyuki.py:126
                if(([&]()->V{auto fn_159=global("bool","Hiyuki");Args args_158;args_158.pos(([&]()->V{auto fn_161=attr(attr(self_value(),"task"),"find_one");Args args_160;args_160.pos(V("hiyuki_left"));args_160.kw("threshold",V(0.5));return invoke(fn_161,args_160);}()));return invoke(fn_159,args_158);}()).truth()){
                    // Hiyuki.py:127
                    ([&]()->V{auto fn_163=attr(attr(self_value(),"task"),"wait_until");Args args_162;args_162.pos(V::function([this,captured=capture_scope(scope_90,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_164=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_166=global("bool","Hiyuki");Args args_165;args_165.pos(([&]()->V{auto fn_168=attr(attr(self_value(),"task"),"find_one");Args args_167;args_167.pos(V("hiyuki_left"));args_167.kw("threshold",V(0.5));return invoke(fn_168,args_167);}()));return invoke(fn_166,args_165);}()));
}));args_162.kw("post_action",attr(self_value(),"click"));args_162.kw("time_out",V(3.0));return invoke(fn_163,args_162);}());
                    // Hiyuki.py:129
                    if(scope_90->get("is_timeout").truth()){
                        // Hiyuki.py:130
                        break;
                    }
                    // Hiyuki.py:131
                    ([&]()->V{auto fn_170=attr(self_value(),"sleep");Args args_169;args_169.pos(V(0.1));return invoke(fn_170,args_169);}());
                }else{
                    // Hiyuki.py:132
                    if(([&]()->V{auto fn_172=global("bool","Hiyuki");Args args_171;args_171.pos(([&]()->V{auto fn_174=attr(attr(self_value(),"task"),"find_one");Args args_173;args_173.pos(V("hiyuki_right"));args_173.kw("threshold",V(0.5));return invoke(fn_174,args_173);}()));return invoke(fn_172,args_171);}()).truth()){
                        // Hiyuki.py:133
                        ([&]()->V{auto fn_176=attr(attr(self_value(),"task"),"click");Args args_175;args_175.kw("key",V("right"));args_175.kw("interval",V(1.0));return invoke(fn_176,args_175);}());
                        // Hiyuki.py:134
                        ([&]()->V{auto fn_178=attr(self_value(),"sleep");Args args_177;args_177.pos(V(0.1));return invoke(fn_178,args_177);}());
                    }else{
                        // Hiyuki.py:136
                        ([&]()->V{auto fn_180=attr(self_value(),"click");Args args_179;return invoke(fn_180,args_179);}());
                    }
                }
            }
        }
        // Hiyuki.py:138
        ([&]()->V{auto fn_182=attr(self_value(),"sleep");Args args_181;args_181.pos(V(0.05));return invoke(fn_182,args_181);}());
    }
    // Hiyuki.py:141
    if(([&]()->V{V operand_191;operand_191=attr(self_value(),"lib_permission");if(!operand_191.truth())return operand_191;return ([&]()->V{auto fn_193=attr(self_value(),"liberation_available");Args args_192;return invoke(fn_193,args_192);}());}()).truth()){
        // Hiyuki.py:142
        if(([&]()->V{auto fn_195=attr(self_value(),"hold_liberation");Args args_194;return invoke(fn_195,args_194);}()).truth()){
            // Hiyuki.py:143
            ([&]()->V{auto fn_197=attr(attr(self_value(),"logger"),"warning");Args args_196;args_196.pos(V("hiyuki perform lib2 (final fallback)"));return invoke(fn_197,args_196);}());
            // Hiyuki.py:144
            {V value_198=V(0LL);set_attr(self_value(),"lib2_count",value_198);}
            // Hiyuki.py:145
            return V(true);
        }
    }
    // Hiyuki.py:147
    return V(false);
return V{};
}),false);
// Official method Hiyuki.lib_heavy_available, lines 149-150
register_method("lib_heavy_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_199=bind_arguments(official_args,signature,captured);
    // Hiyuki.py:150
    return ([&]()->V{auto fn_201=global("bool","Hiyuki");Args args_200;args_200.pos(([&]()->V{auto fn_203=attr(attr(self_value(),"task"),"find_one");Args args_202;args_202.pos(V("hiyuki_lib_forte"));args_202.kw("threshold",V(0.7));return invoke(fn_203,args_202);}()));return invoke(fn_201,args_200);}());
return V{};
}),false);
// Official method Hiyuki.wait_locked, lines 152-158
register_method("wait_locked",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_204=bind_arguments(official_args,signature,captured);
    // Hiyuki.py:158
    return ([&]()->V{auto fn_206=global("bool","Hiyuki");Args args_205;args_205.pos(([&]()->V{auto fn_208=attr(attr(self_value(),"task"),"wait_until");Args args_207;args_207.pos(attr(self_value(),"has_long_action2"));args_207.kw("post_action",attr(self_value(),"click"));args_207.kw("time_out",scope_204->get("time_out"));return invoke(fn_208,args_207);}()));return invoke(fn_206,args_205);}());
return V{};
}),false);
// Official method Hiyuki.hold_liberation, lines 160-177
register_method("hold_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_209=bind_arguments(official_args,signature,captured);
scope_209->set("last_click",V::missing());
scope_209->set("start",V::missing());
    // Hiyuki.py:161
    if(unary("not",attr(attr(self_value(),"task"),"use_liberation")).truth()){
        // Hiyuki.py:162
        return V(false);
    }
    // Hiyuki.py:163
    {V value_210=V(0LL);scope_209->set("last_click",value_210);}
    // Hiyuki.py:164
    ([&]()->V{auto fn_212=attr(attr(self_value(),"logger"),"debug");Args args_211;args_211.pos(V("hold_liberation start"));return invoke(fn_212,args_211);}());
    // Hiyuki.py:165
    {V value_213=([&]()->V{auto fn_215=attr(global("time","Hiyuki"),"time");Args args_214;return invoke(fn_215,args_214);}());scope_209->set("start",value_213);}
    // Hiyuki.py:166
        while(([&]()->V{V operand_229;operand_229=item(([&]()->V{auto fn_231=attr(attr(self_value(),"task"),"in_team");Args args_230;return invoke(fn_231,args_230);}()),V(0LL));if(!operand_229.truth())return operand_229;operand_229=([&]()->V{V operand_232;operand_232=([&]()->V{auto fn_234=attr(self_value(),"liberation_available");Args args_233;return invoke(fn_234,args_233);}());if(operand_232.truth())return operand_232;return ([&]()->V{V compare_235=([&]()->V{auto fn_238=attr(attr(self_value(),"task"),"get_cd");Args args_237;args_237.pos(V("liberation"));return invoke(fn_238,args_237);}());V compare_236;V comparison_result_239;compare_236=attr(self_value(),"HOLD_LIB_CD_WAIT");comparison_result_239=compare_value("<=",compare_235,compare_236);return comparison_result_239;}());}());if(!operand_229.truth())return operand_229;return ([&]()->V{V compare_240=([&]()->V{V left_242=([&]()->V{auto fn_245=attr(global("time","Hiyuki"),"time");Args args_244;return invoke(fn_245,args_244);}());V right_243=scope_209->get("start");return official::binary("-",left_242,right_243);}());V compare_241;V comparison_result_246;compare_241=attr(self_value(),"HOLD_LIB_TIME_OUT");comparison_result_246=compare_value("<",compare_240,compare_241);return comparison_result_246;}());}()).truth()){
        // Hiyuki.py:167
        if(([&]()->V{V compare_216=([&]()->V{V left_218=([&]()->V{auto fn_221=attr(global("time","Hiyuki"),"time");Args args_220;return invoke(fn_221,args_220);}());V right_219=scope_209->get("start");return official::binary("-",left_218,right_219);}());V compare_217;V comparison_result_222;compare_217=scope_209->get("last_click");comparison_result_222=compare_value(">",compare_216,compare_217);return comparison_result_222;}()).truth()){
            // Hiyuki.py:168
            ([&]()->V{auto fn_224=attr(attr(self_value(),"task"),"send_key_down");Args args_223;args_223.pos(([&]()->V{auto fn_226=attr(self_value(),"get_liberation_key");Args args_225;return invoke(fn_226,args_225);}()));return invoke(fn_224,args_223);}());
            // Hiyuki.py:169
            scope_209->set("last_click",official::binary("+",scope_209->get("last_click"),V(0.2)));
        }
        // Hiyuki.py:170
        ([&]()->V{auto fn_228=attr(self_value(),"sleep");Args args_227;args_227.pos(V(0.05));return invoke(fn_228,args_227);}());
    }
    // Hiyuki.py:171
    {V value_247=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_247);}
    // Hiyuki.py:172
    ([&]()->V{auto fn_249=attr(attr(self_value(),"task"),"send_key_up");Args args_248;args_248.pos(([&]()->V{auto fn_251=attr(self_value(),"get_liberation_key");Args args_250;return invoke(fn_251,args_250);}()));return invoke(fn_249,args_248);}());
    // Hiyuki.py:173
    ([&]()->V{auto fn_253=attr(attr(self_value(),"task"),"wait_until");Args args_252;args_252.pos(V::function([this,captured=capture_scope(scope_209,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_254=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_256=attr(attr(self_value(),"task"),"in_team");Args args_255;return invoke(fn_256,args_255);}()),V(0LL));
}));args_252.kw("time_out",V(3LL));return invoke(fn_253,args_252);}());
    // Hiyuki.py:174
    {V value_257=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_257);}
    // Hiyuki.py:175
    ([&]()->V{auto fn_259=attr(self_value(),"add_freeze_duration");Args args_258;args_258.pos(scope_209->get("start"));args_258.pos(([&]()->V{V left_260=([&]()->V{auto fn_263=attr(global("time","Hiyuki"),"time");Args args_262;return invoke(fn_263,args_262);}());V right_261=scope_209->get("start");return official::binary("-",left_260,right_261);}()));return invoke(fn_259,args_258);}());
    // Hiyuki.py:176
    ([&]()->V{auto fn_265=attr(attr(self_value(),"logger"),"info");Args args_264;args_264.pos(V(std::string{}+"hold_liberation end "+format_value(([&]()->V{V left_266=([&]()->V{auto fn_269=attr(global("time","Hiyuki"),"time");Args args_268;return invoke(fn_269,args_268);}());V right_267=scope_209->get("start");return official::binary("-",left_266,right_267);}()),"",-1)));return invoke(fn_265,args_264);}());
    // Hiyuki.py:177
    return V(true);
return V{};
}),false);
// Official method Hiyuki.get_switch_priority, lines 179-182
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_270=bind_arguments(official_args,signature,captured);
    // Hiyuki.py:180
    if(([&]()->V{V operand_271;operand_271=scope_270->get("has_intro");if(!operand_271.truth())return operand_271;operand_271=scope_270->get("current_char");if(!operand_271.truth())return operand_271;return ([&]()->V{V compare_272=attr(scope_270->get("current_char"),"char_name");V compare_273;V comparison_result_274;compare_273=V::set({V("char_linnai"),V("char_lucilla")});comparison_result_274=compare_value("in",compare_272,compare_273);return comparison_result_274;}());}()).truth()){
        // Hiyuki.py:181
        return attr(global("SwitchPriority","Hiyuki"),"MUST");
    }
    // Hiyuki.py:182
    return ([&]()->V{auto fn_278=attr(([&]()->V{auto fn_276=global("super","Hiyuki");Args args_275;return invoke(fn_276,args_275);}()),"get_switch_priority");Args args_277;args_277.pos(scope_270->get("current_char"));args_277.pos(scope_270->get("has_intro"));args_277.pos(scope_270->get("target_low_con"));return invoke(fn_278,args_277);}());
return V{};
}),false);
}
}
