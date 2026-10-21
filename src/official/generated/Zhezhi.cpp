#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Zhezhi.py
// SHA256 21086a6f034f60d2aa49c40047346bdbfcac8c18b80e15063a06b6575f358e0b
void OfficialCharacter::install_Zhezhi(){
auto scope=std::make_shared<Scope>();
set_global("zhezhi_forte_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(185LL),V(215LL)}));set_item(dictionary_1,V("g"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_1,V("b"),V::tuple({V(235LL),V(255LL)}));return dictionary_1;}()));
set_global("zhezhi_blue_color",([&]()->V{V dictionary_2=V::dict();set_item(dictionary_2,V("r"),V::tuple({V(160LL),V(180LL)}));set_item(dictionary_2,V("g"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_2,V("b"),V::tuple({V(245LL),V(255LL)}));return dictionary_2;}()));
// Official method Zhezhi.__init__, lines 10-14
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_3=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:11
    ([&]()->V{auto fn_7=attr(([&]()->V{auto fn_5=global("super","Zhezhi");Args args_4;return invoke(fn_5,args_4);}()),"__init__");Args args_6;args_6.spread(scope_3->get("args"));args_6.spread_keywords(scope_3->get("kwargs"));return invoke(fn_7,args_6);}());
    // Zhezhi.py:12
    {V value_8=V(false);set_attr(self_value(),"_resonance_blue",value_8);}
    // Zhezhi.py:13
    {V value_9=V{};set_attr(self_value(),"char_carlotta",value_9);}
    // Zhezhi.py:14
    {V value_10=V(0LL);set_attr(self_value(),"forte",value_10);}
return V{};
}),false);
// Official method Zhezhi.reset_state, lines 16-20
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:17
    ([&]()->V{auto fn_15=attr(([&]()->V{auto fn_13=global("super","Zhezhi");Args args_12;return invoke(fn_13,args_12);}()),"reset_state");Args args_14;return invoke(fn_15,args_14);}());
    // Zhezhi.py:18
    {V value_16=V(false);set_attr(self_value(),"_resonance_blue",value_16);}
    // Zhezhi.py:19
    {V value_17=V{};set_attr(self_value(),"char_carlotta",value_17);}
    // Zhezhi.py:20
    {V value_18=V(0LL);set_attr(self_value(),"forte",value_18);}
return V{};
}),false);
// Official method Zhezhi.do_perform, lines 22-41
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_19=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:23
    if(([&]()->V{V compare_20=attr(self_value(),"char_carlotta");V compare_21;V comparison_result_22;compare_21=V{};comparison_result_22=compare_value("is not",compare_20,compare_21);return comparison_result_22;}()).truth()){
        // Zhezhi.py:24
        return ([&]()->V{auto fn_24=attr(self_value(),"do_perform_interlock");Args args_23;return invoke(fn_24,args_23);}());
    }
    // Zhezhi.py:25
    if(attr(self_value(),"has_intro").truth()){
        // Zhezhi.py:26
        ([&]()->V{auto fn_26=attr(self_value(),"continues_normal_attack");Args args_25;args_25.pos(V(1.5));return invoke(fn_26,args_25);}());
    }
    // Zhezhi.py:27
    ([&]()->V{auto fn_28=attr(self_value(),"click_liberation");Args args_27;return invoke(fn_28,args_27);}());
    // Zhezhi.py:28
    if(([&]()->V{V operand_29;operand_29=([&]()->V{V operand_30;operand_30=attr(self_value(),"_resonance_blue");if(operand_30.truth())return operand_30;return ([&]()->V{auto fn_32=attr(self_value(),"resonance_blue");Args args_31;return invoke(fn_32,args_31);}());}());if(!operand_29.truth())return operand_29;return ([&]()->V{auto fn_34=attr(self_value(),"resonance_available");Args args_33;return invoke(fn_34,args_33);}());}()).truth()){
        // Zhezhi.py:29
        {V value_35=V(false);set_attr(self_value(),"_resonance_blue",value_35);}
        // Zhezhi.py:30
        ([&]()->V{auto fn_37=attr(self_value(),"resonance_until_not_blue");Args args_36;return invoke(fn_37,args_36);}());
        // Zhezhi.py:31
        return ([&]()->V{auto fn_39=attr(self_value(),"switch_next_char");Args args_38;return invoke(fn_39,args_38);}());
    }else{
        // Zhezhi.py:32
        if(([&]()->V{V operand_40;operand_40=([&]()->V{auto fn_42=attr(self_value(),"resonance_available");Args args_41;return invoke(fn_42,args_41);}());if(!operand_40.truth())return operand_40;return unary("not",([&]()->V{auto fn_44=attr(self_value(),"is_forte_full");Args args_43;return invoke(fn_44,args_43);}()));}()).truth()){
        }else{
            // Zhezhi.py:34
            if(([&]()->V{V operand_45;operand_45=([&]()->V{auto fn_47=attr(self_value(),"resonance_available");Args args_46;return invoke(fn_47,args_46);}());if(!operand_45.truth())return operand_45;return ([&]()->V{auto fn_49=attr(self_value(),"is_forte_full");Args args_48;return invoke(fn_49,args_48);}());}()).truth()){
                // Zhezhi.py:35
                ([&]()->V{auto fn_51=attr(self_value(),"click_resonance");Args args_50;return invoke(fn_51,args_50);}());
                // Zhezhi.py:36
                ([&]()->V{auto fn_53=attr(self_value(),"continues_normal_attack");Args args_52;args_52.pos(V(0.8));return invoke(fn_53,args_52);}());
                // Zhezhi.py:37
                {V value_54=V(true);set_attr(self_value(),"_resonance_blue",value_54);}
                // Zhezhi.py:38
                return ([&]()->V{auto fn_56=attr(self_value(),"switch_next_char");Args args_55;return invoke(fn_56,args_55);}());
            }
        }
    }
    // Zhezhi.py:39
    if(unary("not",([&]()->V{auto fn_58=attr(self_value(),"click_echo");Args args_57;return invoke(fn_58,args_57);}())).truth()){
        // Zhezhi.py:40
        ([&]()->V{auto fn_60=attr(self_value(),"continues_normal_attack");Args args_59;args_59.pos(V(0.1));return invoke(fn_60,args_59);}());
    }
    // Zhezhi.py:41
    ([&]()->V{auto fn_62=attr(self_value(),"switch_next_char");Args args_61;return invoke(fn_62,args_61);}());
return V{};
}),false);
// Official method Zhezhi.resonance_until_not_blue, lines 43-65
register_method("resonance_until_not_blue",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_63=bind_arguments(official_args,signature,captured);
scope_63->set("jump_intval",V::missing());
scope_63->set("start",V::missing());
    // Zhezhi.py:44
    {V value_64=([&]()->V{auto fn_66=attr(global("time","Zhezhi"),"time");Args args_65;return invoke(fn_66,args_65);}());scope_63->set("start",value_64);}
    // Zhezhi.py:45
        while(unary("not",([&]()->V{auto fn_79=attr(self_value(),"resonance_blue");Args args_78;return invoke(fn_79,args_78);}())).truth()){
        // Zhezhi.py:46
        if(([&]()->V{V compare_67=([&]()->V{V left_69=([&]()->V{auto fn_72=attr(global("time","Zhezhi"),"time");Args args_71;return invoke(fn_72,args_71);}());V right_70=scope_63->get("start");return official::binary("-",left_69,right_70);}());V compare_68;V comparison_result_73;compare_68=V(0.3);comparison_result_73=compare_value(">",compare_67,compare_68);return comparison_result_73;}()).truth()){
            // Zhezhi.py:47
            break;
        }
        // Zhezhi.py:48
        ([&]()->V{auto fn_75=attr(self_value(),"check_combat");Args args_74;return invoke(fn_75,args_74);}());
        // Zhezhi.py:49
        ([&]()->V{auto fn_77=attr(attr(self_value(),"task"),"next_frame");Args args_76;return invoke(fn_77,args_76);}());
    }
    // Zhezhi.py:50
    {V value_80=([&]()->V{V left_81=([&]()->V{auto fn_84=attr(global("time","Zhezhi"),"time");Args args_83;return invoke(fn_84,args_83);}());V right_82=V(0.4);return official::binary("+",left_81,right_82);}());scope_63->set("jump_intval",value_80);}
    // Zhezhi.py:51
    ([&]()->V{auto fn_86=attr(attr(self_value(),"task"),"mouse_down");Args args_85;return invoke(fn_86,args_85);}());
    // Zhezhi.py:52
        while(([&]()->V{V operand_126;operand_126=([&]()->V{auto fn_128=attr(self_value(),"resonance_available");Args args_127;return invoke(fn_128,args_127);}());if(!operand_126.truth())return operand_126;return ([&]()->V{auto fn_130=attr(self_value(),"resonance_blue");Args args_129;return invoke(fn_130,args_129);}());}()).truth()){
        // Zhezhi.py:53
        ([&]()->V{auto fn_88=attr(self_value(),"send_resonance_key");Args args_87;return invoke(fn_88,args_87);}());
        // Zhezhi.py:54
        if(([&]()->V{V operand_89;operand_89=([&]()->V{auto fn_91=attr(self_value(),"need_fast_perform");Args args_90;return invoke(fn_91,args_90);}());if(!operand_89.truth())return operand_89;return ([&]()->V{V compare_92=([&]()->V{V left_94=([&]()->V{auto fn_97=attr(global("time","Zhezhi"),"time");Args args_96;return invoke(fn_97,args_96);}());V right_95=scope_63->get("start");return official::binary("-",left_94,right_95);}());V compare_93;V comparison_result_98;compare_93=V(1.1);comparison_result_98=compare_value(">",compare_92,compare_93);return comparison_result_98;}());}()).truth()){
            // Zhezhi.py:55
            break;
        }
        // Zhezhi.py:56
        if(([&]()->V{V operand_99;operand_99=([&]()->V{auto fn_101=attr(self_value(),"is_con_full");Args args_100;return invoke(fn_101,args_100);}());if(!operand_99.truth())return operand_99;return ([&]()->V{V operand_102;operand_102=([&]()->V{V compare_103=attr(self_value(),"char_carlotta");V compare_104;V comparison_result_105;compare_104=V{};comparison_result_105=compare_value("is",compare_103,compare_104);return comparison_result_105;}());if(operand_102.truth())return operand_102;return ([&]()->V{auto fn_107=attr(self_value(),"con_lock");Args args_106;return invoke(fn_107,args_106);}());}());}()).truth()){
            // Zhezhi.py:57
            break;
        }
        // Zhezhi.py:58
        if(([&]()->V{V compare_108=([&]()->V{V left_110=([&]()->V{auto fn_113=attr(global("time","Zhezhi"),"time");Args args_112;return invoke(fn_113,args_112);}());V right_111=scope_63->get("start");return official::binary("-",left_110,right_111);}());V compare_109;V comparison_result_114;compare_109=V(4LL);comparison_result_114=compare_value(">",compare_108,compare_109);return comparison_result_114;}()).truth()){
            // Zhezhi.py:59
            break;
        }
        // Zhezhi.py:60
        if(([&]()->V{V compare_115=([&]()->V{auto fn_118=attr(global("time","Zhezhi"),"time");Args args_117;return invoke(fn_118,args_117);}());V compare_116;V comparison_result_119;compare_116=scope_63->get("jump_intval");comparison_result_119=compare_value(">",compare_115,compare_116);return comparison_result_119;}()).truth()){
            // Zhezhi.py:61
            ([&]()->V{auto fn_121=attr(attr(self_value(),"task"),"jump");Args args_120;args_120.kw("after_sleep",V(0.01));return invoke(fn_121,args_120);}());
            // Zhezhi.py:62
            scope_63->set("jump_intval",official::binary("+",scope_63->get("jump_intval"),V(0.4)));
        }
        // Zhezhi.py:63
        ([&]()->V{auto fn_123=attr(self_value(),"check_combat");Args args_122;return invoke(fn_123,args_122);}());
        // Zhezhi.py:64
        ([&]()->V{auto fn_125=attr(attr(self_value(),"task"),"next_frame");Args args_124;return invoke(fn_125,args_124);}());
    }
    // Zhezhi.py:65
    ([&]()->V{auto fn_132=attr(attr(self_value(),"task"),"mouse_up");Args args_131;return invoke(fn_132,args_131);}());
return V{};
}),false);
// Official method Zhezhi.con_lock, lines 67-69
register_method("con_lock",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_133=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:68
    return ([&]()->V{V operand_134;operand_134=([&]()->V{auto fn_136=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_135;return invoke(fn_136,args_135);}());if(operand_134.truth())return operand_134;operand_134=([&]()->V{V compare_137=([&]()->V{auto fn_140=attr(self_value(),"get_current_con");Args args_139;return invoke(fn_140,args_139);}());V compare_138;V comparison_result_141;compare_138=V(0.6);comparison_result_141=compare_value("<",compare_137,compare_138);return comparison_result_141;}());if(operand_134.truth())return operand_134;return ([&]()->V{V operand_142;operand_142=([&]()->V{auto fn_144=attr(self_value(),"is_con_full");Args args_143;return invoke(fn_144,args_143);}());if(!operand_142.truth())return operand_142;return unary("not",([&]()->V{auto fn_146=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_145;return invoke(fn_146,args_145);}()));}());}());
return V{};
}),false);
// Official method Zhezhi.get_switch_priority, lines 71-74
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_147=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:72
    if(([&]()->V{V operand_148;operand_148=([&]()->V{V compare_149=attr(self_value(),"char_carlotta");V compare_150;V comparison_result_151;compare_150=V{};comparison_result_151=compare_value("is not",compare_149,compare_150);return comparison_result_151;}());if(!operand_148.truth())return operand_148;return ([&]()->V{auto fn_153=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_152;return invoke(fn_153,args_152);}());}()).truth()){
        // Zhezhi.py:73
        return attr(global("SwitchPriority","Zhezhi"),"MUST");
    }
    // Zhezhi.py:74
    return ([&]()->V{auto fn_157=attr(([&]()->V{auto fn_155=global("super","Zhezhi");Args args_154;return invoke(fn_155,args_154);}()),"get_switch_priority");Args args_156;args_156.pos(scope_147->get("current_char"));args_156.pos(scope_147->get("has_intro"));args_156.pos(scope_147->get("target_low_con"));return invoke(fn_157,args_156);}());
return V{};
}),false);
// Official method Zhezhi.do_perform_interlock, lines 76-101
register_method("do_perform_interlock",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_158=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:77
    if(attr(self_value(),"has_intro").truth()){
        // Zhezhi.py:78
        ([&]()->V{auto fn_160=attr(self_value(),"continues_normal_attack");Args args_159;args_159.pos(V(1.3));return invoke(fn_160,args_159);}());
    }
    // Zhezhi.py:79
    if(([&]()->V{auto fn_162=attr(self_value(),"flying");Args args_161;return invoke(fn_162,args_161);}()).truth()){
        // Zhezhi.py:80
        ([&]()->V{auto fn_164=attr(attr(self_value(),"task"),"wait_until");Args args_163;args_163.pos(V::function([this,captured=capture_scope(scope_158,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_165=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_167=attr(self_value(),"flying");Args args_166;return invoke(fn_167,args_166);}()));
}));args_163.kw("post_action",attr(self_value(),"click_with_interval"));args_163.kw("time_out",V(1.2));return invoke(fn_164,args_163);}());
        // Zhezhi.py:81
        ([&]()->V{auto fn_169=attr(self_value(),"continues_right_click");Args args_168;args_168.pos(V(0.05));return invoke(fn_169,args_168);}());
    }
    // Zhezhi.py:82
    if(([&]()->V{V operand_170;operand_170=unary("not",([&]()->V{auto fn_172=attr(self_value(),"resonance_blue");Args args_171;return invoke(fn_172,args_171);}()));if(!operand_170.truth())return operand_170;operand_170=([&]()->V{V compare_173=([&]()->V{auto fn_176=attr(self_value(),"judge_forte");Args args_175;return invoke(fn_176,args_175);}());V compare_174;V comparison_result_177;compare_174=V(3LL);comparison_result_177=compare_value("<",compare_173,compare_174);return comparison_result_177;}());if(!operand_170.truth())return operand_170;return unary("not",([&]()->V{V operand_178;operand_178=([&]()->V{auto fn_180=attr(self_value(),"is_con_full");Args args_179;return invoke(fn_180,args_179);}());if(!operand_178.truth())return operand_178;return ([&]()->V{auto fn_182=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_181;return invoke(fn_182,args_181);}());}()));}()).truth()){
        // Zhezhi.py:84
        ([&]()->V{auto fn_184=attr(self_value(),"continues_normal_attack");Args args_183;args_183.pos(V(1.4));return invoke(fn_184,args_183);}());
        // Zhezhi.py:85
        if(unary("not",([&]()->V{auto fn_186=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_185;return invoke(fn_186,args_185);}())).truth()){
            // Zhezhi.py:86
            return ([&]()->V{auto fn_188=attr(self_value(),"switch_next_char");Args args_187;return invoke(fn_188,args_187);}());
        }
    }
    // Zhezhi.py:87
    if(([&]()->V{V operand_189;operand_189=unary("not",([&]()->V{auto fn_191=attr(self_value(),"resonance_blue");Args args_190;return invoke(fn_191,args_190);}()));if(!operand_189.truth())return operand_189;operand_189=([&]()->V{auto fn_193=attr(self_value(),"resonance_available");Args args_192;return invoke(fn_193,args_192);}());if(!operand_189.truth())return operand_189;operand_189=([&]()->V{V compare_194=([&]()->V{auto fn_197=attr(self_value(),"judge_forte");Args args_196;return invoke(fn_197,args_196);}());V compare_195;V comparison_result_198;compare_195=V(1LL);comparison_result_198=compare_value(">",compare_194,compare_195);return comparison_result_198;}());if(!operand_189.truth())return operand_189;return unary("not",([&]()->V{V operand_199;operand_199=([&]()->V{auto fn_201=attr(self_value(),"is_con_full");Args args_200;return invoke(fn_201,args_200);}());if(!operand_199.truth())return operand_199;return ([&]()->V{auto fn_203=attr(attr(self_value(),"char_carlotta"),"get_ready");Args args_202;return invoke(fn_203,args_202);}());}()));}()).truth()){
        // Zhezhi.py:89
        if(([&]()->V{V operand_204;operand_204=([&]()->V{auto fn_206=attr(self_value(),"con_lock");Args args_205;return invoke(fn_206,args_205);}());if(!operand_204.truth())return operand_204;return ([&]()->V{auto fn_208=attr(self_value(),"click_liberation");Args args_207;return invoke(fn_208,args_207);}());}()).truth()){
            // Zhezhi.py:90
            ([&]()->V{auto fn_210=attr(self_value(),"sleep");Args args_209;args_209.pos(V(0.2));return invoke(fn_210,args_209);}());
        }
        // Zhezhi.py:91
        ([&]()->V{auto fn_212=attr(self_value(),"click_resonance");Args args_211;return invoke(fn_212,args_211);}());
        // Zhezhi.py:92
        ([&]()->V{auto fn_214=attr(self_value(),"continues_normal_attack");Args args_213;args_213.pos(V(0.8));return invoke(fn_214,args_213);}());
    }
    // Zhezhi.py:93
    if(([&]()->V{auto fn_216=attr(self_value(),"con_lock");Args args_215;return invoke(fn_216,args_215);}()).truth()){
        // Zhezhi.py:94
        if(([&]()->V{V operand_217;operand_217=([&]()->V{auto fn_219=attr(self_value(),"resonance_blue");Args args_218;return invoke(fn_219,args_218);}());if(!operand_217.truth())return operand_217;return ([&]()->V{auto fn_221=attr(self_value(),"resonance_available");Args args_220;return invoke(fn_221,args_220);}());}()).truth()){
            // Zhezhi.py:95
            ([&]()->V{auto fn_223=attr(self_value(),"resonance_until_not_blue");Args args_222;return invoke(fn_223,args_222);}());
            // Zhezhi.py:96
            if(([&]()->V{V operand_224;operand_224=([&]()->V{auto fn_226=attr(self_value(),"con_lock");Args args_225;return invoke(fn_226,args_225);}());if(!operand_224.truth())return operand_224;return ([&]()->V{auto fn_228=attr(self_value(),"click_liberation");Args args_227;args_227.kw("wait_if_cd_ready",V(0.5));return invoke(fn_228,args_227);}());}()).truth()){
                // Zhezhi.py:97
                ([&]()->V{auto fn_230=attr(self_value(),"sleep");Args args_229;args_229.pos(V(0.2));return invoke(fn_230,args_229);}());
            }else{
                // Zhezhi.py:98
                if(([&]()->V{auto fn_232=attr(self_value(),"echo_available");Args args_231;return invoke(fn_232,args_231);}()).truth()){
                    // Zhezhi.py:99
                    ([&]()->V{auto fn_234=attr(self_value(),"continues_right_click");Args args_233;args_233.pos(V(0.05));return invoke(fn_234,args_233);}());
                }
            }
        }
    }
    // Zhezhi.py:100
    ([&]()->V{auto fn_236=attr(self_value(),"click_echo");Args args_235;args_235.kw("time_out",V(2LL));return invoke(fn_236,args_235);}());
    // Zhezhi.py:101
    return ([&]()->V{auto fn_238=attr(self_value(),"switch_next_char");Args args_237;return invoke(fn_238,args_237);}());
return V{};
}),false);
// Official method Zhezhi.judge_forte, lines 103-107
register_method("judge_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_239=bind_arguments(official_args,signature,captured);
scope_239->set("box",V::missing());
    // Zhezhi.py:104
    {V value_240=([&]()->V{auto fn_242=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_241;args_241.pos(V(5120LL));args_241.pos(V(2880LL));args_241.pos(V(2164LL));args_241.pos(V(2675LL));args_241.pos(V(2900LL));args_241.pos(V(2685LL));args_241.kw("name",V("zhezhi_forte"));args_241.kw("hcenter",V(true));return invoke(fn_242,args_241);}());scope_239->set("box",value_240);}
    // Zhezhi.py:105
    ([&]()->V{auto fn_244=attr(attr(self_value(),"task"),"draw_boxes");Args args_243;args_243.pos(attr(scope_239->get("box"),"name"));args_243.pos(scope_239->get("box"));return invoke(fn_244,args_243);}());
    // Zhezhi.py:106
    {V value_245=([&]()->V{auto fn_247=attr(self_value(),"calculate_forte_num");Args args_246;args_246.pos(global("zhezhi_forte_color","Zhezhi"));args_246.pos(scope_239->get("box"));args_246.pos(V(3LL));args_246.pos(V(12LL));args_246.pos(V(14LL));args_246.pos(V(100LL));return invoke(fn_247,args_246);}());set_attr(self_value(),"forte",value_245);}
    // Zhezhi.py:107
    return attr(self_value(),"forte");
return V{};
}),false);
// Official method Zhezhi.resonance_blue, lines 109-114
register_method("resonance_blue",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_248=bind_arguments(official_args,signature,captured);
scope_248->set("blue_percent",V::missing());
scope_248->set("box",V::missing());
    // Zhezhi.py:110
    {V value_249=([&]()->V{auto fn_251=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_250;args_250.pos(V(5120LL));args_250.pos(V(2880LL));args_250.pos(V(2242LL));args_250.pos(V(2664LL));args_250.pos(V(2300LL));args_250.pos(V(2690LL));args_250.kw("name",V("zhezhi_kagane"));args_250.kw("hcenter",V(true));return invoke(fn_251,args_250);}());scope_248->set("box",value_249);}
    // Zhezhi.py:111
    ([&]()->V{auto fn_253=attr(attr(self_value(),"task"),"draw_boxes");Args args_252;args_252.pos(attr(scope_248->get("box"),"name"));args_252.pos(scope_248->get("box"));return invoke(fn_253,args_252);}());
    // Zhezhi.py:112
    {V value_254=([&]()->V{auto fn_256=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_255;args_255.pos(global("text_white_color","Zhezhi"));args_255.pos(scope_248->get("box"));return invoke(fn_256,args_255);}());scope_248->set("blue_percent",value_254);}
    // Zhezhi.py:113
    ([&]()->V{auto fn_258=attr(attr(self_value(),"logger"),"debug");Args args_257;args_257.pos(V(std::string{}+"zhezhi_kagane percent: "+format_value(scope_248->get("blue_percent"),"",-1)));return invoke(fn_258,args_257);}());
    // Zhezhi.py:114
    return ([&]()->V{V compare_259=scope_248->get("blue_percent");V compare_260;V comparison_result_261;compare_260=V(0.3);comparison_result_261=compare_value(">",compare_259,compare_260);return comparison_result_261;}());
return V{};
}),false);
// Official method Zhezhi.judge_frequncy_and_amplitude, lines 116-133
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_262=bind_arguments(official_args,signature,captured);
scope_262->set("amplitude",V::missing());
scope_262->set("frequncy",V::missing());
scope_262->set("height",V::missing());
scope_262->set("i",V::missing());
scope_262->set("n",V::missing());
scope_262->set("profile",V::missing());
scope_262->set("width",V::missing());
    // Zhezhi.py:117
    {V value_263=item(attr(scope_262->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_264=unpack(value_263,2);scope_262->set("height",unpack_264[0]);scope_262->set("width",unpack_264[1]);}
    // Zhezhi.py:118
    if(([&]()->V{V operand_265;operand_265=([&]()->V{V compare_266=scope_262->get("height");V compare_267;V comparison_result_268;compare_267=V(0LL);comparison_result_268=compare_value("==",compare_266,compare_267);return comparison_result_268;}());if(operand_265.truth())return operand_265;operand_265=([&]()->V{V compare_269=scope_262->get("width");V compare_270;V comparison_result_271;compare_270=V(64LL);comparison_result_271=compare_value("<",compare_269,compare_270);return comparison_result_271;}());if(operand_265.truth())return operand_265;return unary("not",([&]()->V{auto fn_273=attr(global("np","Zhezhi"),"array_equal");Args args_272;args_272.pos(([&]()->V{auto fn_275=attr(global("np","Zhezhi"),"unique");Args args_274;args_274.pos(scope_262->get("gray"));return invoke(fn_275,args_274);}()));args_272.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_273,args_272);}()));}()).truth()){
        // Zhezhi.py:119
        return V(0LL);
    }
    // Zhezhi.py:121
    {V value_276=([&]()->V{auto fn_283=attr(([&]()->V{auto fn_278=attr(global("np","Zhezhi"),"sum");Args args_277;args_277.pos(([&]()->V{V compare_279=scope_262->get("gray");V compare_280;V comparison_result_281;compare_280=V(255LL);comparison_result_281=compare_value("==",compare_279,compare_280);return comparison_result_281;}()));args_277.kw("axis",V(0LL));return invoke(fn_278,args_277);}()),"astype");Args args_282;args_282.pos(attr(global("np","Zhezhi"),"float32"));return invoke(fn_283,args_282);}());scope_262->set("profile",value_276);}
    // Zhezhi.py:122
    scope_262->set("profile",official::binary("-",scope_262->get("profile"),([&]()->V{auto fn_285=attr(global("np","Zhezhi"),"mean");Args args_284;args_284.pos(scope_262->get("profile"));return invoke(fn_285,args_284);}())));
    // Zhezhi.py:123
    {V value_286=([&]()->V{auto fn_288=attr(global("np","Zhezhi"),"abs");Args args_287;args_287.pos(([&]()->V{auto fn_290=attr(attr(global("np","Zhezhi"),"fft"),"fft");Args args_289;args_289.pos(scope_262->get("profile"));return invoke(fn_290,args_289);}()));return invoke(fn_288,args_287);}());scope_262->set("n",value_286);}
    // Zhezhi.py:124
    {V value_291=V(0LL);scope_262->set("amplitude",value_291);}
    // Zhezhi.py:125
    {V value_292=V(0LL);scope_262->set("frequncy",value_292);}
    // Zhezhi.py:126
    {V value_293=V(1LL);scope_262->set("i",value_293);}
    // Zhezhi.py:127
        while(([&]()->V{V compare_299=scope_262->get("i");V compare_300;V comparison_result_301;compare_300=scope_262->get("width");comparison_result_301=compare_value("<",compare_299,compare_300);return comparison_result_301;}()).truth()){
        // Zhezhi.py:128
        if(([&]()->V{V compare_294=item(scope_262->get("n"),scope_262->get("i"));V compare_295;V comparison_result_296;compare_295=scope_262->get("amplitude");comparison_result_296=compare_value(">",compare_294,compare_295);return comparison_result_296;}()).truth()){
            // Zhezhi.py:129
            {V value_297=item(scope_262->get("n"),scope_262->get("i"));scope_262->set("amplitude",value_297);}
            // Zhezhi.py:130
            {V value_298=scope_262->get("i");scope_262->set("frequncy",value_298);}
        }
        // Zhezhi.py:131
        scope_262->set("i",official::binary("+",scope_262->get("i"),V(1LL)));
    }
    // Zhezhi.py:132
    ([&]()->V{auto fn_303=attr(attr(self_value(),"logger"),"info");Args args_302;args_302.pos(V(std::string{}+"forte with freq "+format_value(scope_262->get("frequncy"),"",-1)+" & amp "+format_value(scope_262->get("amplitude"),"",-1)));return invoke(fn_303,args_302);}());
    // Zhezhi.py:133
    return ([&]()->V{V operand_304;operand_304=([&]()->V{V compare_305=scope_262->get("min_freq");V compare_306;V comparison_result_307;compare_306=scope_262->get("frequncy");comparison_result_307=compare_value("<=",compare_305,compare_306);if(!comparison_result_307.truth())return comparison_result_307;compare_305=compare_306;compare_306=scope_262->get("max_freq");comparison_result_307=compare_value("<=",compare_305,compare_306);return comparison_result_307;}());if(operand_304.truth())return operand_304;return ([&]()->V{V compare_308=scope_262->get("amplitude");V compare_309;V comparison_result_310;compare_309=scope_262->get("min_amp");comparison_result_310=compare_value(">=",compare_308,compare_309);return comparison_result_310;}());}());
return V{};
}),false);
// Official method Zhezhi.calculate_forte_num, lines 135-154
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_311=bind_arguments(official_args,signature,captured);
scope_311->set("cropped",V::missing());
scope_311->set("forte",V::missing());
scope_311->set("gray",V::missing());
scope_311->set("height",V::missing());
scope_311->set("image",V::missing());
scope_311->set("left",V::missing());
scope_311->set("lower_bound",V::missing());
scope_311->set("score",V::missing());
scope_311->set("step",V::missing());
scope_311->set("upper_bound",V::missing());
scope_311->set("width",V::missing());
    // Zhezhi.py:136
    {V value_312=([&]()->V{auto fn_314=attr(scope_311->get("box"),"crop_frame");Args args_313;args_313.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_314,args_313);}());scope_311->set("cropped",value_312);}
    // Zhezhi.py:137
    {V value_315=([&]()->V{auto fn_317=global("color_range_to_bound","Zhezhi");Args args_316;args_316.pos(scope_311->get("forte_color"));return invoke(fn_317,args_316);}());auto unpack_318=unpack(value_315,2);scope_311->set("lower_bound",unpack_318[0]);scope_311->set("upper_bound",unpack_318[1]);}
    // Zhezhi.py:138
    {V value_319=([&]()->V{auto fn_321=attr(global("cv2","Zhezhi"),"inRange");Args args_320;args_320.pos(scope_311->get("cropped"));args_320.pos(scope_311->get("lower_bound"));args_320.pos(scope_311->get("upper_bound"));return invoke(fn_321,args_320);}());scope_311->set("image",value_319);}
    // Zhezhi.py:140
    {V value_322=V(0LL);scope_311->set("forte",value_322);}
    // Zhezhi.py:141
    {V value_323=attr(scope_311->get("image"),"shape");auto unpack_324=unpack(value_323,2);scope_311->set("height",unpack_324[0]);scope_311->set("width",unpack_324[1]);}
    // Zhezhi.py:142
    {V value_325=([&]()->V{auto fn_327=global("int","Zhezhi");Args args_326;args_326.pos(([&]()->V{V left_328=scope_311->get("width");V right_329=scope_311->get("num");return official::binary("/",left_328,right_329);}()));return invoke(fn_327,args_326);}());scope_311->set("step",value_325);}
    // Zhezhi.py:144
    {V value_330=scope_311->get("num");scope_311->set("forte",value_330);}
    // Zhezhi.py:145
    {V value_331=([&]()->V{V left_332=scope_311->get("step");V right_333=([&]()->V{V left_334=scope_311->get("forte");V right_335=V(1LL);return official::binary("-",left_334,right_335);}());return official::binary("*",left_332,right_333);}());scope_311->set("left",value_331);}
    // Zhezhi.py:146
        while(([&]()->V{V compare_342=scope_311->get("forte");V compare_343;V comparison_result_344;compare_343=V(0LL);comparison_result_344=compare_value(">",compare_342,compare_343);return comparison_result_344;}()).truth()){
        // Zhezhi.py:147
        {V value_336=item(scope_311->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_311->get("left"),([&]()->V{V left_337=scope_311->get("left");V right_338=scope_311->get("step");return official::binary("+",left_337,right_338);}()),V{})}));scope_311->set("gray",value_336);}
        // Zhezhi.py:148
        {V value_339=([&]()->V{auto fn_341=attr(self_value(),"judge_frequncy_and_amplitude");Args args_340;args_340.pos(scope_311->get("gray"));args_340.pos(scope_311->get("min_freq"));args_340.pos(scope_311->get("max_freq"));args_340.pos(scope_311->get("min_amp"));return invoke(fn_341,args_340);}());scope_311->set("score",value_339);}
        // Zhezhi.py:149
        if(scope_311->get("score").truth()){
            // Zhezhi.py:150
            break;
        }
        // Zhezhi.py:151
        scope_311->set("left",official::binary("-",scope_311->get("left"),scope_311->get("step")));
        // Zhezhi.py:152
        scope_311->set("forte",official::binary("-",scope_311->get("forte"),V(1LL)));
    }
    // Zhezhi.py:153
    ([&]()->V{auto fn_346=attr(attr(self_value(),"logger"),"info");Args args_345;args_345.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_311->get("forte"),"",-1)));return invoke(fn_346,args_345);}());
    // Zhezhi.py:154
    return scope_311->get("forte");
return V{};
}),false);
// Official method Zhezhi.resonance_available, lines 156-159
register_method("resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current",V{}},{"check_ready",V(false)},{"check_cd",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_347=bind_arguments(official_args,signature,captured);
    // Zhezhi.py:157
    if(([&]()->V{V operand_348;operand_348=attr(self_value(),"is_current_char");if(!operand_348.truth())return operand_348;return ([&]()->V{auto fn_350=attr(self_value(),"resonance_blue");Args args_349;return invoke(fn_350,args_349);}());}()).truth()){
        // Zhezhi.py:158
        return V(true);
    }
    // Zhezhi.py:159
    return ([&]()->V{auto fn_354=attr(([&]()->V{auto fn_352=global("super","Zhezhi");Args args_351;return invoke(fn_352,args_351);}()),"resonance_available");Args args_353;return invoke(fn_354,args_353);}());
return V{};
}),false);
}
}
