#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Changli.py
// SHA256 b236e1189ae7c6f5a0c2b2640719123e8397946e89d447216640e93cc7df7950
void OfficialCharacter::install_Changli(){
auto scope=std::make_shared<Scope>();
set_global("changli_red_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_1,V("g"),V::tuple({V(85LL),V(105LL)}));set_item(dictionary_1,V("b"),V::tuple({V(95LL),V(115LL)}));return dictionary_1;}()));
// Official method Changli.__init__, lines 10-12
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Changli.py:11
    ([&]()->V{auto fn_6=attr(([&]()->V{auto fn_4=global("super","Changli");Args args_3;return invoke(fn_4,args_3);}()),"__init__");Args args_5;args_5.spread(scope_2->get("args"));args_5.spread_keywords(scope_2->get("kwargs"));return invoke(fn_6,args_5);}());
    // Changli.py:12
    {V value_7=V(false);set_attr(self_value(),"enhanced_normal",value_7);}
return V{};
}),false);
// Official method Changli.reset_state, lines 14-16
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Changli.py:15
    ([&]()->V{auto fn_12=attr(([&]()->V{auto fn_10=global("super","Changli");Args args_9;return invoke(fn_10,args_9);}()),"reset_state");Args args_11;return invoke(fn_12,args_11);}());
    // Changli.py:16
    {V value_13=V(false);set_attr(self_value(),"enhanced_normal",value_13);}
return V{};
}),false);
// Official method Changli.get_switch_priority, lines 18-21
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_14=bind_arguments(official_args,signature,captured);
    // Changli.py:19
    if(([&]()->V{V operand_15;operand_15=scope_14->get("has_intro");if(!operand_15.truth())return operand_15;operand_15=scope_14->get("current_char");if(!operand_15.truth())return operand_15;return ([&]()->V{V compare_16=attr(scope_14->get("current_char"),"char_name");V compare_17;V comparison_result_18;compare_17=V::set({V("char_brant")});comparison_result_18=compare_value("in",compare_16,compare_17);return comparison_result_18;}());}()).truth()){
        // Changli.py:20
        return attr(global("SwitchPriority","Changli"),"MUST");
    }
    // Changli.py:21
    return ([&]()->V{auto fn_22=attr(([&]()->V{auto fn_20=global("super","Changli");Args args_19;return invoke(fn_20,args_19);}()),"get_switch_priority");Args args_21;args_21.pos(scope_14->get("current_char"));args_21.pos(scope_14->get("has_intro"));args_21.pos(scope_14->get("target_low_con"));return invoke(fn_22,args_21);}());
return V{};
}),false);
// Official method Changli.do_perform, lines 23-60
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_23=bind_arguments(official_args,signature,captured);
scope_23->set("forte",V::missing());
scope_23->set("outro",V::missing());
    // Changli.py:24
    {V value_24=V(false);scope_23->set("outro",value_24);}
    // Changli.py:25
    {V value_25=unary("-",V(1LL));scope_23->set("forte",value_25);}
    // Changli.py:26
    {V value_26=V(true);set_attr(self_value(),"check_f_on_switch",value_26);}
    // Changli.py:27
    if(attr(self_value(),"has_intro").truth()){
        // Changli.py:28
        ([&]()->V{auto fn_28=attr(self_value(),"continues_normal_attack");Args args_27;args_27.pos(V(0.3));return invoke(fn_28,args_27);}());
        // Changli.py:29
        {V value_29=V(true);set_attr(self_value(),"enhanced_normal",value_29);}
    }
    // Changli.py:30
    {V value_30=([&]()->V{auto fn_32=attr(self_value(),"judge_forte");Args args_31;return invoke(fn_32,args_31);}());scope_23->set("forte",value_30);}
    // Changli.py:31
    if(attr(self_value(),"enhanced_normal").truth()){
        // Changli.py:32
        ([&]()->V{auto fn_34=attr(attr(self_value(),"logger"),"debug");Args args_33;args_33.pos(V("Changli has enhanced"));return invoke(fn_34,args_33);}());
        // Changli.py:33
        ([&]()->V{auto fn_36=attr(self_value(),"continues_normal_attack");Args args_35;args_35.pos(V(0.2));return invoke(fn_36,args_35);}());
        // Changli.py:34
        ([&]()->V{auto fn_38=attr(self_value(),"sleep");Args args_37;args_37.pos(V(0.2));return invoke(fn_38,args_37);}());
        // Changli.py:35
        if(([&]()->V{V compare_39=([&]()->V{auto fn_42=attr(self_value(),"check_outro");Args args_41;return invoke(fn_42,args_41);}());V compare_40;V comparison_result_43;compare_40=V::set({V("char_brant")});comparison_result_43=compare_value("in",compare_39,compare_40);return comparison_result_43;}()).truth()){
            // Changli.py:36
            ([&]()->V{auto fn_45=attr(self_value(),"sleep");Args args_44;args_44.pos(V(0.2));return invoke(fn_45,args_44);}());
            // Changli.py:37
            ([&]()->V{auto fn_47=attr(self_value(),"do_perform_outro");Args args_46;args_46.pos(([&]()->V{auto fn_49=attr(self_value(),"judge_forte");Args args_48;return invoke(fn_49,args_48);}()));return invoke(fn_47,args_46);}());
            // Changli.py:38
            return ([&]()->V{auto fn_51=attr(self_value(),"switch_next_char");Args args_50;return invoke(fn_51,args_50);}());
        }
        // Changli.py:39
        if(([&]()->V{V compare_52=scope_23->get("forte");V compare_53;V comparison_result_54;compare_53=V(3LL);comparison_result_54=compare_value("==",compare_52,compare_53);return comparison_result_54;}()).truth()){
            // Changli.py:40
            ([&]()->V{auto fn_56=attr(self_value(),"sleep");Args args_55;args_55.pos(V(0.2));return invoke(fn_56,args_55);}());
            // Changli.py:41
            {V value_57=([&]()->V{auto fn_59=attr(self_value(),"judge_forte");Args args_58;return invoke(fn_59,args_58);}());scope_23->set("forte",value_57);}
        }
    }
    // Changli.py:42
    {V value_60=V(false);set_attr(self_value(),"enhanced_normal",value_60);}
    // Changli.py:43
    if(([&]()->V{V operand_61;operand_61=([&]()->V{V compare_62=scope_23->get("forte");V compare_63;V comparison_result_64;compare_63=V(4LL);comparison_result_64=compare_value("==",compare_62,compare_63);return comparison_result_64;}());if(operand_61.truth())return operand_61;return ([&]()->V{auto fn_66=attr(self_value(),"is_mouse_forte_full");Args args_65;return invoke(fn_66,args_65);}());}()).truth()){
        // Changli.py:44
        if(([&]()->V{auto fn_68=attr(self_value(),"flying");Args args_67;return invoke(fn_68,args_67);}()).truth()){
            // Changli.py:45
            ([&]()->V{auto fn_70=attr(self_value(),"heavy_attack");Args args_69;return invoke(fn_70,args_69);}());
        }
        // Changli.py:46
        ([&]()->V{auto fn_72=attr(self_value(),"heavy_click_forte");Args args_71;args_71.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_72,args_71);}());
        // Changli.py:47
        {V value_73=V(false);set_attr(self_value(),"check_f_on_switch",value_73);}
        // Changli.py:48
        ([&]()->V{auto fn_75=attr(self_value(),"check_combat");Args args_74;return invoke(fn_75,args_74);}());
        // Changli.py:49
        return ([&]()->V{auto fn_77=attr(self_value(),"switch_next_char");Args args_76;return invoke(fn_77,args_76);}());
    }
    // Changli.py:50
    if(([&]()->V{V operand_78;operand_78=unary("not",([&]()->V{V operand_79;operand_79=([&]()->V{V compare_80=scope_23->get("forte");V compare_81;V comparison_result_82;compare_81=V(3LL);comparison_result_82=compare_value(">=",compare_80,compare_81);return comparison_result_82;}());if(!operand_79.truth())return operand_79;return ([&]()->V{auto fn_84=attr(self_value(),"resonance_available");Args args_83;return invoke(fn_84,args_83);}());}()));if(!operand_78.truth())return operand_78;return ([&]()->V{auto fn_86=attr(self_value(),"liberation_available");Args args_85;return invoke(fn_86,args_85);}());}()).truth()){
        // Changli.py:51
        if(([&]()->V{auto fn_88=attr(self_value(),"liberation_and_heavy");Args args_87;return invoke(fn_88,args_87);}()).truth()){
            // Changli.py:52
            {V value_89=V(false);set_attr(self_value(),"check_f_on_switch",value_89);}
            // Changli.py:53
            return ([&]()->V{auto fn_91=attr(self_value(),"switch_next_char");Args args_90;return invoke(fn_91,args_90);}());
        }
    }
    // Changli.py:54
    if(([&]()->V{auto fn_93=attr(self_value(),"flick_resonance");Args args_92;args_92.kw("send_click",V(false));return invoke(fn_93,args_92);}()).truth()){
        // Changli.py:55
        {V value_94=V(true);set_attr(self_value(),"enhanced_normal",value_94);}
        // Changli.py:56
        return ([&]()->V{auto fn_96=attr(self_value(),"switch_next_char");Args args_95;return invoke(fn_96,args_95);}());
    }
    // Changli.py:57
    if(([&]()->V{auto fn_98=attr(self_value(),"click_echo");Args args_97;return invoke(fn_98,args_97);}()).truth()){
        // Changli.py:58
        return ([&]()->V{auto fn_100=attr(self_value(),"switch_next_char");Args args_99;return invoke(fn_100,args_99);}());
    }
    // Changli.py:59
    ([&]()->V{auto fn_102=attr(self_value(),"continues_normal_attack");Args args_101;args_101.pos(V(0.1));return invoke(fn_102,args_101);}());
    // Changli.py:60
    ([&]()->V{auto fn_104=attr(self_value(),"switch_next_char");Args args_103;return invoke(fn_104,args_103);}());
return V{};
}),false);
// Official method Changli.do_perform_outro, lines 62-94
register_method("do_perform_outro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_105=bind_arguments(official_args,signature,captured);
scope_105->set("forte_time",V::missing());
scope_105->set("res",V::missing());
scope_105->set("start",V::missing());
    // Changli.py:63
    if(([&]()->V{V compare_106=scope_105->get("forte");V compare_107;V comparison_result_108;compare_107=V(3LL);comparison_result_108=compare_value("==",compare_106,compare_107);return comparison_result_108;}()).truth()){
        // Changli.py:64
        {V value_109=([&]()->V{auto fn_111=attr(global("time","Changli"),"time");Args args_110;return invoke(fn_111,args_110);}());scope_105->set("start",value_109);}
        // Changli.py:65
        {V value_112=scope_105->get("start");scope_105->set("forte_time",value_112);}
        // Changli.py:66
        {V value_113=V(true);scope_105->set("res",value_113);}
        // Changli.py:67
                while(([&]()->V{V compare_136=([&]()->V{V left_138=([&]()->V{auto fn_141=attr(global("time","Changli"),"time");Args args_140;return invoke(fn_141,args_140);}());V right_139=scope_105->get("start");return official::binary("-",left_138,right_139);}());V compare_137;V comparison_result_142;compare_137=V(5LL);comparison_result_142=compare_value("<",compare_136,compare_137);return comparison_result_142;}()).truth()){
            // Changli.py:68
            if(([&]()->V{V operand_114;operand_114=scope_105->get("res");if(!operand_114.truth())return operand_114;return ([&]()->V{auto fn_116=attr(self_value(),"flick_resonance");Args args_115;args_115.kw("send_click",V(false));return invoke(fn_116,args_115);}());}()).truth()){
                // Changli.py:69
                {V value_117=V(false);scope_105->set("res",value_117);}
                // Changli.py:70
                continue;
            }
            // Changli.py:71
            ([&]()->V{auto fn_119=attr(self_value(),"click");Args args_118;args_118.kw("interval",V(0.1));return invoke(fn_119,args_118);}());
            // Changli.py:72
            if(([&]()->V{auto fn_121=attr(self_value(),"is_mouse_forte_full");Args args_120;return invoke(fn_121,args_120);}()).truth()){
                // Changli.py:73
                if(([&]()->V{V compare_122=([&]()->V{V left_124=([&]()->V{auto fn_127=attr(global("time","Changli"),"time");Args args_126;return invoke(fn_127,args_126);}());V right_125=scope_105->get("forte_time");return official::binary("-",left_124,right_125);}());V compare_123;V comparison_result_128;compare_123=V(0.2);comparison_result_128=compare_value(">",compare_122,compare_123);return comparison_result_128;}()).truth()){
                    // Changli.py:74
                    break;
                }
            }else{
                // Changli.py:76
                {V value_129=([&]()->V{auto fn_131=attr(global("time","Changli"),"time");Args args_130;return invoke(fn_131,args_130);}());scope_105->set("forte_time",value_129);}
            }
            // Changli.py:77
            ([&]()->V{auto fn_133=attr(self_value(),"check_combat");Args args_132;return invoke(fn_133,args_132);}());
            // Changli.py:78
            ([&]()->V{auto fn_135=attr(attr(self_value(),"task"),"next_frame");Args args_134;return invoke(fn_135,args_134);}());
        }
        // Changli.py:79
        if(([&]()->V{auto fn_144=attr(self_value(),"is_mouse_forte_full");Args args_143;return invoke(fn_144,args_143);}()).truth()){
            // Changli.py:80
            ([&]()->V{auto fn_146=attr(self_value(),"heavy_click_forte");Args args_145;args_145.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_146,args_145);}());
            // Changli.py:81
            ([&]()->V{auto fn_148=attr(self_value(),"sleep");Args args_147;args_147.pos(V(1LL));return invoke(fn_148,args_147);}());
        }
    }else{
        // Changli.py:82
        if(([&]()->V{V operand_149;operand_149=([&]()->V{V compare_150=scope_105->get("forte");V compare_151;V comparison_result_152;compare_151=V(4LL);comparison_result_152=compare_value(">=",compare_150,compare_151);return comparison_result_152;}());if(operand_149.truth())return operand_149;return ([&]()->V{auto fn_154=attr(self_value(),"is_mouse_forte_full");Args args_153;return invoke(fn_154,args_153);}());}()).truth()){
            // Changli.py:83
            if(([&]()->V{auto fn_156=attr(self_value(),"flying");Args args_155;return invoke(fn_156,args_155);}()).truth()){
                // Changli.py:84
                ([&]()->V{auto fn_158=attr(self_value(),"heavy_attack");Args args_157;return invoke(fn_158,args_157);}());
            }
            // Changli.py:85
            ([&]()->V{auto fn_160=attr(self_value(),"heavy_click_forte");Args args_159;args_159.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_160,args_159);}());
            // Changli.py:86
            {V value_161=V(0LL);scope_105->set("forte",value_161);}
            // Changli.py:87
            ([&]()->V{auto fn_163=attr(self_value(),"sleep");Args args_162;args_162.pos(V(1LL));return invoke(fn_163,args_162);}());
        }
    }
    // Changli.py:88
    if(([&]()->V{V operand_164;operand_164=([&]()->V{auto fn_166=attr(self_value(),"liberation_available");Args args_165;return invoke(fn_166,args_165);}());if(!operand_164.truth())return operand_164;return ([&]()->V{auto fn_168=attr(self_value(),"liberation_and_heavy");Args args_167;return invoke(fn_168,args_167);}());}()).truth()){
        // Changli.py:89
        ([&]()->V{auto fn_170=attr(self_value(),"sleep");Args args_169;args_169.pos(V(0.6));return invoke(fn_170,args_169);}());
        // Changli.py:90
        {V value_171=V(0LL);scope_105->set("forte",value_171);}
    }
    // Changli.py:91
    if(([&]()->V{V operand_172;operand_172=([&]()->V{V compare_173=scope_105->get("forte");V compare_174;V comparison_result_175;compare_174=V(3LL);comparison_result_175=compare_value("<",compare_173,compare_174);return comparison_result_175;}());if(!operand_172.truth())return operand_172;return ([&]()->V{auto fn_177=attr(self_value(),"flick_resonance");Args args_176;args_176.kw("send_click",V(false));return invoke(fn_177,args_176);}());}()).truth()){
        // Changli.py:92
        {V value_178=V(true);set_attr(self_value(),"enhanced_normal",value_178);}
        // Changli.py:93
        return V{};
    }
    // Changli.py:94
    ([&]()->V{auto fn_180=attr(self_value(),"click_echo");Args args_179;return invoke(fn_180,args_179);}());
return V{};
}),false);
// Official method Changli.judge_forte, lines 96-101
register_method("judge_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_181=bind_arguments(official_args,signature,captured);
scope_181->set("box",V::missing());
scope_181->set("forte",V::missing());
    // Changli.py:97
    if(([&]()->V{auto fn_183=attr(self_value(),"is_mouse_forte_full");Args args_182;return invoke(fn_183,args_182);}()).truth()){
        // Changli.py:98
        return V(4LL);
    }
    // Changli.py:99
    {V value_184=([&]()->V{auto fn_186=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_185;args_185.pos(V(3840LL));args_185.pos(V(2160LL));args_185.pos(V(1633LL));args_185.pos(V(2004LL));args_185.pos(V(2160LL));args_185.pos(V(2016LL));args_185.kw("name",V("changli_forte"));args_185.kw("hcenter",V(true));return invoke(fn_186,args_185);}());scope_181->set("box",value_184);}
    // Changli.py:100
    {V value_187=([&]()->V{auto fn_189=attr(self_value(),"calculate_forte_num");Args args_188;args_188.pos(global("changli_red_color","Changli"));args_188.pos(scope_181->get("box"));args_188.pos(V(4LL));args_188.pos(V(9LL));args_188.pos(V(11LL));args_188.pos(V(400LL));return invoke(fn_189,args_188);}());scope_181->set("forte",value_187);}
    // Changli.py:101
    return scope_181->get("forte");
return V{};
}),false);
// Official method Changli.liberation_and_heavy, lines 103-162
register_method("liberation_and_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_less_than",unary("-",V(1LL))},{"send_click",V(false)},{"wait_if_cd_ready",V(0LL)},{"timeout",V(5LL)}},"","",{})](const Args& official_args)->V{
auto scope_190=bind_arguments(official_args,signature,captured);
scope_190->set("clicked",V::missing());
scope_190->set("duration",V::missing());
scope_190->set("hold",V::missing());
scope_190->set("last_click",V::missing());
scope_190->set("now",V::missing());
scope_190->set("start",V::missing());
    // Changli.py:104
    if(([&]()->V{V compare_191=scope_190->get("con_less_than");V compare_192;V comparison_result_193;compare_192=V(0LL);comparison_result_193=compare_value(">",compare_191,compare_192);return comparison_result_193;}()).truth()){
        // Changli.py:105
        if(([&]()->V{V compare_194=([&]()->V{auto fn_197=attr(self_value(),"get_current_con");Args args_196;return invoke(fn_197,args_196);}());V compare_195;V comparison_result_198;compare_195=scope_190->get("con_less_than");comparison_result_198=compare_value(">",compare_194,compare_195);return comparison_result_198;}()).truth()){
            // Changli.py:106
            return V(false);
        }
    }
    // Changli.py:107
    ([&]()->V{auto fn_200=attr(attr(self_value(),"logger"),"debug");Args args_199;args_199.pos(V("click_liberation start"));return invoke(fn_200,args_199);}());
    // Changli.py:108
    {V value_201=([&]()->V{auto fn_203=attr(global("time","Changli"),"time");Args args_202;return invoke(fn_203,args_202);}());scope_190->set("start",value_201);}
    // Changli.py:109
    {V value_204=V(0LL);scope_190->set("last_click",value_204);}
    // Changli.py:110
    {V value_205=V(false);scope_190->set("clicked",value_205);}
    // Changli.py:111
        while(([&]()->V{V operand_212;operand_212=([&]()->V{V compare_213=([&]()->V{V left_215=([&]()->V{auto fn_218=attr(global("time","Changli"),"time");Args args_217;return invoke(fn_218,args_217);}());V right_216=scope_190->get("start");return official::binary("-",left_215,right_216);}());V compare_214;V comparison_result_219;compare_214=scope_190->get("wait_if_cd_ready");comparison_result_219=compare_value("<",compare_213,compare_214);return comparison_result_219;}());if(!operand_212.truth())return operand_212;operand_212=unary("not",([&]()->V{auto fn_221=attr(self_value(),"liberation_available");Args args_220;return invoke(fn_221,args_220);}()));if(!operand_212.truth())return operand_212;return unary("not",([&]()->V{auto fn_223=attr(self_value(),"has_cd");Args args_222;args_222.pos(V("liberation"));return invoke(fn_223,args_222);}()));}()).truth()){
        // Changli.py:113
        ([&]()->V{auto fn_207=attr(attr(self_value(),"logger"),"debug");Args args_206;args_206.pos(V(std::string{}+"click_liberation wait ready "+format_value(scope_190->get("wait_if_cd_ready"),"",-1)));return invoke(fn_207,args_206);}());
        // Changli.py:114
        if(scope_190->get("send_click").truth()){
            // Changli.py:115
            ([&]()->V{auto fn_209=attr(self_value(),"click");Args args_208;args_208.kw("interval",V(0.1));return invoke(fn_209,args_208);}());
        }
        // Changli.py:116
        ([&]()->V{auto fn_211=attr(attr(self_value(),"task"),"next_frame");Args args_210;return invoke(fn_211,args_210);}());
    }
    // Changli.py:117
        while(([&]()->V{V operand_251;operand_251=([&]()->V{auto fn_253=attr(self_value(),"liberation_available");Args args_252;return invoke(fn_253,args_252);}());if(!operand_251.truth())return operand_251;return item(([&]()->V{auto fn_255=attr(attr(self_value(),"task"),"in_team");Args args_254;return invoke(fn_255,args_254);}()),V(0LL));}()).truth()){
        // Changli.py:118
        ([&]()->V{auto fn_225=attr(attr(self_value(),"logger"),"debug");Args args_224;args_224.pos(V("click_liberation liberation_available click"));return invoke(fn_225,args_224);}());
        // Changli.py:119
        {V value_226=([&]()->V{auto fn_228=attr(global("time","Changli"),"time");Args args_227;return invoke(fn_228,args_227);}());scope_190->set("now",value_226);}
        // Changli.py:120
        if(([&]()->V{V compare_229=([&]()->V{V left_231=scope_190->get("now");V right_232=scope_190->get("last_click");return official::binary("-",left_231,right_232);}());V compare_230;V comparison_result_233;compare_230=V(0.1);comparison_result_233=compare_value(">",compare_229,compare_230);return comparison_result_233;}()).truth()){
            // Changli.py:121
            ([&]()->V{auto fn_235=attr(self_value(),"send_liberation_key");Args args_234;return invoke(fn_235,args_234);}());
            // Changli.py:122
            if(unary("not",scope_190->get("clicked")).truth()){
                // Changli.py:123
                {V value_236=V(true);scope_190->set("clicked",value_236);}
                // Changli.py:124
                ([&]()->V{auto fn_238=attr(self_value(),"record_liberation_use");Args args_237;return invoke(fn_238,args_237);}());
            }
            // Changli.py:125
            {V value_239=scope_190->get("now");scope_190->set("last_click",value_239);}
        }
        // Changli.py:126
        if(([&]()->V{V compare_240=([&]()->V{V left_242=([&]()->V{auto fn_245=attr(global("time","Changli"),"time");Args args_244;return invoke(fn_245,args_244);}());V right_243=scope_190->get("start");return official::binary("-",left_242,right_243);}());V compare_241;V comparison_result_246;compare_241=scope_190->get("timeout");comparison_result_246=compare_value(">",compare_240,compare_241);return comparison_result_246;}()).truth()){
            // Changli.py:127
            ([&]()->V{auto fn_248=attr(attr(self_value(),"task"),"raise_not_in_combat");Args args_247;args_247.pos(V("too long clicking a liberation"));return invoke(fn_248,args_247);}());
        }
        // Changli.py:128
        ([&]()->V{auto fn_250=attr(attr(self_value(),"task"),"next_frame");Args args_249;return invoke(fn_250,args_249);}());
    }
    // Changli.py:129
    if(scope_190->get("clicked").truth()){
        // Changli.py:130
        if(([&]()->V{auto fn_257=attr(attr(self_value(),"task"),"wait_until");Args args_256;args_256.pos(V::function([this,captured=capture_scope(scope_190,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_258=bind_arguments(official_args,signature,captured);
return unary("not",item(([&]()->V{auto fn_260=attr(attr(self_value(),"task"),"in_team");Args args_259;return invoke(fn_260,args_259);}()),V(0LL)));
}));args_256.kw("time_out",V(0.4));return invoke(fn_257,args_256);}()).truth()){
            // Changli.py:131
            {V value_261=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_261);}
            // Changli.py:132
            ([&]()->V{auto fn_263=attr(attr(self_value(),"logger"),"debug");Args args_262;args_262.pos(V("not in_team successfully casted liberation"));return invoke(fn_263,args_262);}());
        }else{
            // Changli.py:134
            {V value_264=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_264);}
            // Changli.py:135
            ([&]()->V{auto fn_266=attr(attr(self_value(),"logger"),"error");Args args_265;args_265.pos(V("clicked liberation but no effect"));return invoke(fn_266,args_265);}());
            // Changli.py:136
            return V(false);
        }
    }
    // Changli.py:137
    {V value_267=([&]()->V{auto fn_269=attr(global("time","Changli"),"time");Args args_268;return invoke(fn_269,args_268);}());scope_190->set("start",value_267);}
    // Changli.py:138
    {V value_270=V(false);scope_190->set("hold",value_270);}
    // Changli.py:139
        while(unary("not",item(([&]()->V{auto fn_301=attr(attr(self_value(),"task"),"in_team");Args args_300;return invoke(fn_301,args_300);}()),V(0LL))).truth()){
        // Changli.py:140
        {V value_271=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_271);}
        // Changli.py:141
        if(unary("not",scope_190->get("clicked")).truth()){
            // Changli.py:142
            {V value_272=V(true);scope_190->set("clicked",value_272);}
            // Changli.py:143
            ([&]()->V{auto fn_274=attr(self_value(),"record_liberation_use");Args args_273;return invoke(fn_274,args_273);}());
        }
        // Changli.py:144
        if(scope_190->get("send_click").truth()){
            // Changli.py:145
            ([&]()->V{auto fn_276=attr(self_value(),"click");Args args_275;args_275.kw("interval",V(0.1));return invoke(fn_276,args_275);}());
        }
        // Changli.py:146
        if(([&]()->V{V operand_277;operand_277=([&]()->V{V compare_278=([&]()->V{V left_280=([&]()->V{auto fn_283=attr(global("time","Changli"),"time");Args args_282;return invoke(fn_283,args_282);}());V right_281=scope_190->get("start");return official::binary("-",left_280,right_281);}());V compare_279;V comparison_result_284;compare_279=V(1.5);comparison_result_284=compare_value(">",compare_278,compare_279);return comparison_result_284;}());if(!operand_277.truth())return operand_277;return unary("not",scope_190->get("hold"));}()).truth()){
            // Changli.py:147
            ([&]()->V{auto fn_286=attr(attr(self_value(),"task"),"mouse_down");Args args_285;return invoke(fn_286,args_285);}());
            // Changli.py:148
            {V value_287=V(true);scope_190->set("hold",value_287);}
        }
        // Changli.py:149
        if(([&]()->V{V compare_288=([&]()->V{V left_290=([&]()->V{auto fn_293=attr(global("time","Changli"),"time");Args args_292;return invoke(fn_293,args_292);}());V right_291=scope_190->get("start");return official::binary("-",left_290,right_291);}());V compare_289;V comparison_result_294;compare_289=V(7LL);comparison_result_294=compare_value(">",compare_288,compare_289);return comparison_result_294;}()).truth()){
            // Changli.py:150
            {V value_295=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_295);}
            // Changli.py:151
            ([&]()->V{auto fn_297=attr(attr(self_value(),"task"),"raise_not_in_combat");Args args_296;args_296.pos(V("too long a liberation, the boss was killed by the liberation"));return invoke(fn_297,args_296);}());
        }
        // Changli.py:152
        ([&]()->V{auto fn_299=attr(attr(self_value(),"task"),"next_frame");Args args_298;return invoke(fn_299,args_298);}());
    }
    // Changli.py:153
    {V value_302=([&]()->V{V left_303=([&]()->V{auto fn_306=attr(global("time","Changli"),"time");Args args_305;return invoke(fn_306,args_305);}());V right_304=scope_190->get("start");return official::binary("-",left_303,right_304);}());scope_190->set("duration",value_302);}
    // Changli.py:154
    ([&]()->V{auto fn_308=attr(self_value(),"add_freeze_duration");Args args_307;args_307.pos(scope_190->get("start"));args_307.pos(scope_190->get("duration"));return invoke(fn_308,args_307);}());
    // Changli.py:155
    {V value_309=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_309);}
    // Changli.py:156
    if(scope_190->get("clicked").truth()){
        // Changli.py:157
        ([&]()->V{auto fn_311=attr(attr(self_value(),"logger"),"info");Args args_310;args_310.pos(V(std::string{}+"click_liberation end "+format_value(scope_190->get("duration"),"",-1)));return invoke(fn_311,args_310);}());
        // Changli.py:158
        ([&]()->V{auto fn_313=attr(attr(self_value(),"task"),"wait_until");Args args_312;args_312.pos(V::function([this,captured=capture_scope(scope_190,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_314=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_315;operand_315=item(([&]()->V{auto fn_317=attr(attr(self_value(),"task"),"in_team");Args args_316;return invoke(fn_317,args_316);}()),V(0LL));if(!operand_315.truth())return operand_315;return ([&]()->V{auto fn_319=attr(self_value(),"is_mouse_forte_full");Args args_318;return invoke(fn_319,args_318);}());}());
}));args_312.kw("time_out",V(0.6));return invoke(fn_313,args_312);}());
        // Changli.py:159
        ([&]()->V{auto fn_321=attr(attr(self_value(),"task"),"wait_until");Args args_320;args_320.pos(V::function([this,captured=capture_scope(scope_190,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_322=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_323;operand_323=item(([&]()->V{auto fn_325=attr(attr(self_value(),"task"),"in_team");Args args_324;return invoke(fn_325,args_324);}()),V(0LL));if(!operand_323.truth())return operand_323;return unary("not",([&]()->V{auto fn_327=attr(self_value(),"is_mouse_forte_full");Args args_326;return invoke(fn_327,args_326);}()));}());
}));args_320.kw("time_out",V(0.6));return invoke(fn_321,args_320);}());
    }
    // Changli.py:160
    ([&]()->V{auto fn_329=attr(attr(self_value(),"task"),"mouse_up");Args args_328;return invoke(fn_329,args_328);}());
    // Changli.py:161
    ([&]()->V{auto fn_331=attr(self_value(),"check_combat");Args args_330;return invoke(fn_331,args_330);}());
    // Changli.py:162
    return scope_190->get("clicked");
return V{};
}),false);
// Official method Changli.flick_resonance, lines 164-172
register_method("flick_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(0.2)},{"send_click",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_332=bind_arguments(official_args,signature,captured);
    // Changli.py:165
    if(([&]()->V{V operand_333;operand_333=scope_332->get("send_click");if(!operand_333.truth())return operand_333;return ([&]()->V{auto fn_335=attr(self_value(),"resonance_available");Args args_334;return invoke(fn_335,args_334);}());}()).truth()){
        // Changli.py:166
        ([&]()->V{auto fn_337=attr(attr(self_value(),"task"),"wait_until");Args args_336;args_336.pos(V::function([this,captured=capture_scope(scope_332,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_338=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_339=([&]()->V{auto fn_342=attr(self_value(),"current_resonance");Args args_341;return invoke(fn_342,args_341);}());V compare_340;V comparison_result_343;compare_340=V(0LL);comparison_result_343=compare_value(">",compare_339,compare_340);return comparison_result_343;}());
}));args_336.kw("post_action",attr(self_value(),"click_with_interval"));args_336.kw("time_out",V(0.2));return invoke(fn_337,args_336);}());
    }
    // Changli.py:168
    if(([&]()->V{V operand_344;operand_344=([&]()->V{V compare_345=([&]()->V{auto fn_348=attr(self_value(),"current_resonance");Args args_347;return invoke(fn_348,args_347);}());V compare_346;V comparison_result_349;compare_346=V(0LL);comparison_result_349=compare_value(">",compare_345,compare_346);return comparison_result_349;}());if(!operand_344.truth())return operand_344;return ([&]()->V{auto fn_351=attr(self_value(),"resonance_available");Args args_350;return invoke(fn_351,args_350);}());}()).truth()){
        // Changli.py:169
        ([&]()->V{auto fn_353=attr(attr(self_value(),"task"),"wait_until");Args args_352;args_352.pos(V::function([this,captured=capture_scope(scope_332,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_354=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_356=attr(self_value(),"resonance_available");Args args_355;return invoke(fn_356,args_355);}()));
}));args_352.kw("post_action",attr(self_value(),"send_resonance_key"));args_352.kw("time_out",scope_332->get("time_out"));return invoke(fn_353,args_352);}());
        // Changli.py:171
        return V(true);
    }
    // Changli.py:172
    return V(false);
return V{};
}),false);
// Official method Changli.judge_frequncy_and_amplitude, lines 174-191
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_357=bind_arguments(official_args,signature,captured);
scope_357->set("amplitude",V::missing());
scope_357->set("frequncy",V::missing());
scope_357->set("height",V::missing());
scope_357->set("i",V::missing());
scope_357->set("n",V::missing());
scope_357->set("profile",V::missing());
scope_357->set("width",V::missing());
    // Changli.py:175
    {V value_358=item(attr(scope_357->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_359=unpack(value_358,2);scope_357->set("height",unpack_359[0]);scope_357->set("width",unpack_359[1]);}
    // Changli.py:176
    if(([&]()->V{V operand_360;operand_360=([&]()->V{V compare_361=scope_357->get("height");V compare_362;V comparison_result_363;compare_362=V(0LL);comparison_result_363=compare_value("==",compare_361,compare_362);return comparison_result_363;}());if(operand_360.truth())return operand_360;operand_360=([&]()->V{V compare_364=scope_357->get("width");V compare_365;V comparison_result_366;compare_365=V(64LL);comparison_result_366=compare_value("<",compare_364,compare_365);return comparison_result_366;}());if(operand_360.truth())return operand_360;return unary("not",([&]()->V{auto fn_368=attr(global("np","Changli"),"array_equal");Args args_367;args_367.pos(([&]()->V{auto fn_370=attr(global("np","Changli"),"unique");Args args_369;args_369.pos(scope_357->get("gray"));return invoke(fn_370,args_369);}()));args_367.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_368,args_367);}()));}()).truth()){
        // Changli.py:177
        return V(0LL);
    }
    // Changli.py:179
    {V value_371=([&]()->V{auto fn_378=attr(([&]()->V{auto fn_373=attr(global("np","Changli"),"sum");Args args_372;args_372.pos(([&]()->V{V compare_374=scope_357->get("gray");V compare_375;V comparison_result_376;compare_375=V(255LL);comparison_result_376=compare_value("==",compare_374,compare_375);return comparison_result_376;}()));args_372.kw("axis",V(0LL));return invoke(fn_373,args_372);}()),"astype");Args args_377;args_377.pos(attr(global("np","Changli"),"float32"));return invoke(fn_378,args_377);}());scope_357->set("profile",value_371);}
    // Changli.py:180
    scope_357->set("profile",official::binary("-",scope_357->get("profile"),([&]()->V{auto fn_380=attr(global("np","Changli"),"mean");Args args_379;args_379.pos(scope_357->get("profile"));return invoke(fn_380,args_379);}())));
    // Changli.py:181
    {V value_381=([&]()->V{auto fn_383=attr(global("np","Changli"),"abs");Args args_382;args_382.pos(([&]()->V{auto fn_385=attr(attr(global("np","Changli"),"fft"),"fft");Args args_384;args_384.pos(scope_357->get("profile"));return invoke(fn_385,args_384);}()));return invoke(fn_383,args_382);}());scope_357->set("n",value_381);}
    // Changli.py:182
    {V value_386=V(0LL);scope_357->set("amplitude",value_386);}
    // Changli.py:183
    {V value_387=V(0LL);scope_357->set("frequncy",value_387);}
    // Changli.py:184
    {V value_388=V(1LL);scope_357->set("i",value_388);}
    // Changli.py:185
        while(([&]()->V{V compare_394=scope_357->get("i");V compare_395;V comparison_result_396;compare_395=scope_357->get("width");comparison_result_396=compare_value("<",compare_394,compare_395);return comparison_result_396;}()).truth()){
        // Changli.py:186
        if(([&]()->V{V compare_389=item(scope_357->get("n"),scope_357->get("i"));V compare_390;V comparison_result_391;compare_390=scope_357->get("amplitude");comparison_result_391=compare_value(">",compare_389,compare_390);return comparison_result_391;}()).truth()){
            // Changli.py:187
            {V value_392=item(scope_357->get("n"),scope_357->get("i"));scope_357->set("amplitude",value_392);}
            // Changli.py:188
            {V value_393=scope_357->get("i");scope_357->set("frequncy",value_393);}
        }
        // Changli.py:189
        scope_357->set("i",official::binary("+",scope_357->get("i"),V(1LL)));
    }
    // Changli.py:190
    ([&]()->V{auto fn_398=attr(attr(self_value(),"logger"),"debug");Args args_397;args_397.pos(V(std::string{}+"forte with freq "+format_value(scope_357->get("frequncy"),"",-1)+" & amp "+format_value(scope_357->get("amplitude"),"",-1)));return invoke(fn_398,args_397);}());
    // Changli.py:191
    return ([&]()->V{V operand_399;operand_399=([&]()->V{V compare_400=scope_357->get("min_freq");V compare_401;V comparison_result_402;compare_401=scope_357->get("frequncy");comparison_result_402=compare_value("<=",compare_400,compare_401);if(!comparison_result_402.truth())return comparison_result_402;compare_400=compare_401;compare_401=scope_357->get("max_freq");comparison_result_402=compare_value("<=",compare_400,compare_401);return comparison_result_402;}());if(operand_399.truth())return operand_399;return ([&]()->V{V compare_403=scope_357->get("amplitude");V compare_404;V comparison_result_405;compare_404=scope_357->get("min_amp");comparison_result_405=compare_value(">=",compare_403,compare_404);return comparison_result_405;}());}());
return V{};
}),false);
// Official method Changli.calculate_forte_num, lines 193-212
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_406=bind_arguments(official_args,signature,captured);
scope_406->set("cropped",V::missing());
scope_406->set("forte",V::missing());
scope_406->set("gray",V::missing());
scope_406->set("height",V::missing());
scope_406->set("image",V::missing());
scope_406->set("left",V::missing());
scope_406->set("lower_bound",V::missing());
scope_406->set("score",V::missing());
scope_406->set("step",V::missing());
scope_406->set("upper_bound",V::missing());
scope_406->set("width",V::missing());
    // Changli.py:194
    {V value_407=([&]()->V{auto fn_409=attr(scope_406->get("box"),"crop_frame");Args args_408;args_408.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_409,args_408);}());scope_406->set("cropped",value_407);}
    // Changli.py:195
    {V value_410=([&]()->V{auto fn_412=global("color_range_to_bound","Changli");Args args_411;args_411.pos(scope_406->get("forte_color"));return invoke(fn_412,args_411);}());auto unpack_413=unpack(value_410,2);scope_406->set("lower_bound",unpack_413[0]);scope_406->set("upper_bound",unpack_413[1]);}
    // Changli.py:196
    {V value_414=([&]()->V{auto fn_416=attr(global("cv2","Changli"),"inRange");Args args_415;args_415.pos(scope_406->get("cropped"));args_415.pos(scope_406->get("lower_bound"));args_415.pos(scope_406->get("upper_bound"));return invoke(fn_416,args_415);}());scope_406->set("image",value_414);}
    // Changli.py:198
    {V value_417=V(0LL);scope_406->set("forte",value_417);}
    // Changli.py:199
    {V value_418=attr(scope_406->get("image"),"shape");auto unpack_419=unpack(value_418,2);scope_406->set("height",unpack_419[0]);scope_406->set("width",unpack_419[1]);}
    // Changli.py:200
    {V value_420=([&]()->V{auto fn_422=global("int","Changli");Args args_421;args_421.pos(([&]()->V{V left_423=scope_406->get("width");V right_424=scope_406->get("num");return official::binary("/",left_423,right_424);}()));return invoke(fn_422,args_421);}());scope_406->set("step",value_420);}
    // Changli.py:202
    {V value_425=scope_406->get("num");scope_406->set("forte",value_425);}
    // Changli.py:203
    {V value_426=([&]()->V{V left_427=scope_406->get("step");V right_428=([&]()->V{V left_429=scope_406->get("forte");V right_430=V(1LL);return official::binary("-",left_429,right_430);}());return official::binary("*",left_427,right_428);}());scope_406->set("left",value_426);}
    // Changli.py:204
        while(([&]()->V{V compare_437=scope_406->get("forte");V compare_438;V comparison_result_439;compare_438=V(0LL);comparison_result_439=compare_value(">",compare_437,compare_438);return comparison_result_439;}()).truth()){
        // Changli.py:205
        {V value_431=item(scope_406->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_406->get("left"),([&]()->V{V left_432=scope_406->get("left");V right_433=scope_406->get("step");return official::binary("+",left_432,right_433);}()),V{})}));scope_406->set("gray",value_431);}
        // Changli.py:206
        {V value_434=([&]()->V{auto fn_436=attr(self_value(),"judge_frequncy_and_amplitude");Args args_435;args_435.pos(scope_406->get("gray"));args_435.pos(scope_406->get("min_freq"));args_435.pos(scope_406->get("max_freq"));args_435.pos(scope_406->get("min_amp"));return invoke(fn_436,args_435);}());scope_406->set("score",value_434);}
        // Changli.py:207
        if(scope_406->get("score").truth()){
            // Changli.py:208
            break;
        }
        // Changli.py:209
        scope_406->set("left",official::binary("-",scope_406->get("left"),scope_406->get("step")));
        // Changli.py:210
        scope_406->set("forte",official::binary("-",scope_406->get("forte"),V(1LL)));
    }
    // Changli.py:211
    ([&]()->V{auto fn_441=attr(attr(self_value(),"logger"),"info");Args args_440;args_440.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_406->get("forte"),"",-1)));return invoke(fn_441,args_440);}());
    // Changli.py:212
    return scope_406->get("forte");
return V{};
}),false);
}
}
