// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Brant.py
// SHA256 876e82febb405393ee8637664325115b9c7c3f16a7fd520344db03d6462a9777
void OfficialCharacter::install_Brant(){
auto scope=std::make_shared<Scope>();
// Official method Brant.__init__, lines 7-12
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Brant.py:8
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Brant");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Brant.py:9
    {V value_6=V(0LL);set_attr(self_value(),"perform_anchor",value_6);}
    // Brant.py:10
    {V value_7=V(0LL);set_attr(self_value(),"attribute",value_7);}
    // Brant.py:11
    {V value_8=V{};set_attr(self_value(),"char_lupa",value_8);}
    // Brant.py:12
    {V value_9=V(false);set_attr(self_value(),"check_f_on_switch",value_9);}
return V{};
}),false);
// Official method Brant.reset_state, lines 14-17
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_10=bind_arguments(official_args,signature,captured);
    // Brant.py:15
    ([&]()->V{auto fn_14=attr(([&]()->V{auto fn_12=global("super","Brant");Args args_11;return invoke(fn_12,args_11);}()),"reset_state");Args args_13;return invoke(fn_14,args_13);}());
    // Brant.py:16
    {V value_15=V(0LL);set_attr(self_value(),"attribute",value_15);}
    // Brant.py:17
    {V value_16=V{};set_attr(self_value(),"char_lupa",value_16);}
return V{};
}),false);
// Official method Brant.do_perform, lines 19-42
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_17=bind_arguments(official_args,signature,captured);
    // Brant.py:20
    ([&]()->V{auto fn_19=attr(self_value(),"decide_teammate");Args args_18;return invoke(fn_19,args_18);}());
    // Brant.py:21
    if(attr(self_value(),"has_intro").truth()){
        // Brant.py:22
        ([&]()->V{auto fn_21=attr(self_value(),"continues_normal_attack");Args args_20;args_20.pos(V(1.3));return invoke(fn_21,args_20);}());
        // Brant.py:23
        if(([&]()->V{V operand_22;operand_22=attr(self_value(),"has_sub_dps_intro");if(!operand_22.truth())return operand_22;operand_22=([&]()->V{V compare_23=([&]()->V{auto fn_26=attr(self_value(),"check_outro");Args args_25;return invoke(fn_26,args_25);}());V compare_24;V comparison_result_27;compare_24=V::set({V("char_lupa")});comparison_result_27=compare_value("in",compare_23,compare_24);return comparison_result_27;}());if(!operand_22.truth())return operand_22;return ([&]()->V{auto fn_29=attr(self_value(),"perform_in_outro");Args args_28;return invoke(fn_29,args_28);}());}()).truth()){
            // Brant.py:24
            return ([&]()->V{auto fn_31=attr(self_value(),"switch_next_char");Args args_30;return invoke(fn_31,args_30);}());
        }
    }
    // Brant.py:25
    ([&]()->V{auto fn_33=attr(self_value(),"f_break");Args args_32;return invoke(fn_33,args_32);}());
    // Brant.py:26
    if(([&]()->V{V operand_34;operand_34=([&]()->V{auto fn_36=attr(self_value(),"is_forte_full");Args args_35;return invoke(fn_36,args_35);}());if(!operand_34.truth())return operand_34;return ([&]()->V{auto fn_38=attr(self_value(),"resonance_available");Args args_37;return invoke(fn_38,args_37);}());}()).truth()){
        // Brant.py:27
        ([&]()->V{auto fn_40=attr(self_value(),"resonance_forte_full");Args args_39;return invoke(fn_40,args_39);}());
        // Brant.py:28
        {V value_41=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_41);}
        // Brant.py:29
        {V value_42=([&]()->V{auto fn_44=attr(global("time","Brant"),"time");Args args_43;return invoke(fn_44,args_43);}());set_attr(self_value(),"perform_anchor",value_42);}
        // Brant.py:30
        if(([&]()->V{auto fn_46=attr(self_value(),"echo_available");Args args_45;return invoke(fn_46,args_45);}()).truth()){
            // Brant.py:31
            ([&]()->V{auto fn_48=attr(self_value(),"click_echo");Args args_47;return invoke(fn_48,args_47);}());
        }
    }
    // Brant.py:32
    if(([&]()->V{V operand_49;operand_49=unary("not",([&]()->V{auto fn_51=attr(self_value(),"need_fast_perform");Args args_50;return invoke(fn_51,args_50);}()));if(!operand_49.truth())return operand_49;operand_49=unary("not",([&]()->V{auto fn_53=attr(self_value(),"is_forte_full");Args args_52;return invoke(fn_53,args_52);}()));if(!operand_49.truth())return operand_49;return ([&]()->V{auto fn_55=attr(self_value(),"click_liberation");Args args_54;return invoke(fn_55,args_54);}());}()).truth()){
        // Brant.py:33
        ([&]()->V{auto fn_57=attr(self_value(),"continues_normal_attack");Args args_56;args_56.pos(V(0.8));return invoke(fn_57,args_56);}());
    }
    // Brant.py:34
    ([&]()->V{auto fn_59=attr(self_value(),"click_jump_with_click");Args args_58;args_58.pos(V(1.3));return invoke(fn_59,args_58);}());
    // Brant.py:35
    if(([&]()->V{V operand_60;operand_60=([&]()->V{auto fn_62=attr(self_value(),"is_forte_full");Args args_61;return invoke(fn_62,args_61);}());if(!operand_60.truth())return operand_60;return ([&]()->V{auto fn_64=attr(self_value(),"resonance_available");Args args_63;return invoke(fn_64,args_63);}());}()).truth()){
        // Brant.py:36
        ([&]()->V{auto fn_66=attr(self_value(),"resonance_forte_full");Args args_65;return invoke(fn_66,args_65);}());
        // Brant.py:37
        {V value_67=([&]()->V{auto fn_69=attr(global("time","Brant"),"time");Args args_68;return invoke(fn_69,args_68);}());set_attr(self_value(),"perform_anchor",value_67);}
        // Brant.py:38
        {V value_70=V(0LL);set_attr(self_value(),"in_liberaction",value_70);}
        // Brant.py:39
        return ([&]()->V{auto fn_72=attr(self_value(),"switch_next_char");Args args_71;return invoke(fn_72,args_71);}());
    }
    // Brant.py:40
    if(([&]()->V{V operand_73;operand_73=unary("not",([&]()->V{auto fn_75=attr(self_value(),"still_in_liberation");Args args_74;return invoke(fn_75,args_74);}()));if(!operand_73.truth())return operand_73;return ([&]()->V{auto fn_77=attr(self_value(),"echo_available");Args args_76;return invoke(fn_77,args_76);}());}()).truth()){
        // Brant.py:41
        ([&]()->V{auto fn_79=attr(self_value(),"click_echo");Args args_78;return invoke(fn_79,args_78);}());
    }
    // Brant.py:42
    ([&]()->V{auto fn_81=attr(self_value(),"switch_next_char");Args args_80;return invoke(fn_81,args_80);}());
return V{};
}),false);
// Official method Brant.still_in_liberation, lines 44-45
register_method("still_in_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_82=bind_arguments(official_args,signature,captured);
    // Brant.py:45
    return ([&]()->V{V compare_83=([&]()->V{auto fn_86=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_85;args_85.pos(attr(self_value(),"last_liberation"));return invoke(fn_86,args_85);}());V compare_84;V comparison_result_87;compare_84=V(12LL);comparison_result_87=compare_value("<",compare_83,compare_84);return comparison_result_87;}());
return V{};
}),false);
// Official method Brant.perform_in_outro, lines 47-80
register_method("perform_in_outro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_88=bind_arguments(official_args,signature,captured);
scope_88->set("click",V::missing());
scope_88->set("liber",V::missing());
scope_88->set("start",V::missing());
scope_88->set("timeout",V::missing());
    // Brant.py:48
    {V value_89=V(0LL);scope_88->set("click",value_89);}
    // Brant.py:49
    {V value_90=([&]()->V{auto fn_92=attr(global("time","Brant"),"time");Args args_91;return invoke(fn_92,args_91);}());scope_88->set("start",value_90);}
    // Brant.py:50
    {V value_93=V(1.5);scope_88->set("timeout",value_93);}
    // Brant.py:51
    {V value_94=V(false);scope_88->set("liber",value_94);}
    // Brant.py:52
    if(([&]()->V{auto fn_96=attr(self_value(),"still_in_liberation");Args args_95;return invoke(fn_96,args_95);}()).truth()){
        // Brant.py:53
        {V value_97=V(10LL);scope_88->set("timeout",value_97);}
        // Brant.py:54
        {V value_98=V(true);scope_88->set("liber",value_98);}
    }
    // Brant.py:55
        while(V(true).truth()){
        // Brant.py:56
        if(([&]()->V{V operand_99;operand_99=([&]()->V{auto fn_101=attr(self_value(),"is_forte_full");Args args_100;return invoke(fn_101,args_100);}());if(!operand_99.truth())return operand_99;return ([&]()->V{auto fn_103=attr(self_value(),"resonance_available");Args args_102;return invoke(fn_103,args_102);}());}()).truth()){
            // Brant.py:57
            ([&]()->V{auto fn_105=attr(attr(self_value(),"logger"),"debug");Args args_104;args_104.pos(V("perform anchar"));return invoke(fn_105,args_104);}());
            // Brant.py:58
            ([&]()->V{auto fn_107=attr(self_value(),"resonance_forte_full");Args args_106;return invoke(fn_107,args_106);}());
            // Brant.py:59
            {V value_108=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_108);}
            // Brant.py:60
            ([&]()->V{auto fn_110=attr(self_value(),"wait_down");Args args_109;args_109.pos(V(4LL));return invoke(fn_110,args_109);}());
            // Brant.py:61
            if(scope_88->get("liber").truth()){
                // Brant.py:62
                break;
                // Brant.py:63
                return V(true);
            }
        }
        // Brant.py:64
        if(([&]()->V{V operand_111;operand_111=([&]()->V{auto fn_113=attr(self_value(),"liberation_available");Args args_112;return invoke(fn_113,args_112);}());if(!operand_111.truth())return operand_111;return ([&]()->V{auto fn_115=attr(self_value(),"click_liberation");Args args_114;return invoke(fn_115,args_114);}());}()).truth()){
            // Brant.py:65
            {V value_116=([&]()->V{auto fn_118=attr(global("time","Brant"),"time");Args args_117;return invoke(fn_118,args_117);}());scope_88->set("start",value_116);}
            // Brant.py:66
            {V value_119=V(10LL);scope_88->set("timeout",value_119);}
            // Brant.py:67
            {V value_120=V(true);scope_88->set("liber",value_120);}
        }
        // Brant.py:68
        if(([&]()->V{V compare_121=([&]()->V{V left_123=([&]()->V{auto fn_126=attr(global("time","Brant"),"time");Args args_125;return invoke(fn_126,args_125);}());V right_124=scope_88->get("start");return official::binary("-",left_123,right_124);}());V compare_122;V comparison_result_127;compare_122=scope_88->get("timeout");comparison_result_127=compare_value(">",compare_121,compare_122);return comparison_result_127;}()).truth()){
            // Brant.py:69
            break;
        }
        // Brant.py:70
        if(([&]()->V{V operand_128;operand_128=attr(attr(self_value(),"task"),"has_lavitator");if(!operand_128.truth())return operand_128;return unary("not",([&]()->V{auto fn_130=attr(self_value(),"flying");Args args_129;return invoke(fn_130,args_129);}()));}()).truth()){
            // Brant.py:71
            ([&]()->V{auto fn_132=attr(self_value(),"flick_resonance");Args args_131;return invoke(fn_132,args_131);}());
            // Brant.py:72
            ([&]()->V{auto fn_134=attr(self_value(),"sleep");Args args_133;args_133.pos(V(0.2));return invoke(fn_134,args_133);}());
        }else{
            // Brant.py:73
            if(unary("not",attr(attr(self_value(),"task"),"has_lavitator")).truth()){
                // Brant.py:74
                ([&]()->V{auto fn_136=attr(attr(self_value(),"task"),"jump");Args args_135;return invoke(fn_136,args_135);}());
            }
        }
        // Brant.py:75
        ([&]()->V{auto fn_138=attr(self_value(),"click");Args args_137;return invoke(fn_138,args_137);}());
        // Brant.py:76
        {V value_139=([&]()->V{V left_140=V(1LL);V right_141=scope_88->get("click");return official::binary("-",left_140,right_141);}());scope_88->set("click",value_139);}
        // Brant.py:77
        ([&]()->V{auto fn_143=attr(self_value(),"check_combat");Args args_142;return invoke(fn_143,args_142);}());
        // Brant.py:78
        ([&]()->V{auto fn_145=attr(attr(self_value(),"task"),"next_frame");Args args_144;return invoke(fn_145,args_144);}());
    }
    // Brant.py:79
    ([&]()->V{auto fn_147=attr(self_value(),"click_echo");Args args_146;return invoke(fn_147,args_146);}());
    // Brant.py:80
    return V(true);
return V{};
}),false);
// Official method Brant.resonance_forte_full, lines 82-89
register_method("resonance_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_148=bind_arguments(official_args,signature,captured);
scope_148->set("start",V::missing());
    // Brant.py:83
    {V value_149=([&]()->V{auto fn_151=attr(global("time","Brant"),"time");Args args_150;return invoke(fn_151,args_150);}());scope_148->set("start",value_149);}
    // Brant.py:84
        while(([&]()->V{V operand_165;operand_165=([&]()->V{auto fn_167=attr(self_value(),"resonance_available");Args args_166;return invoke(fn_167,args_166);}());if(!operand_165.truth())return operand_165;return ([&]()->V{auto fn_169=attr(self_value(),"is_forte_full");Args args_168;return invoke(fn_169,args_168);}());}()).truth()){
        // Brant.py:85
        ([&]()->V{auto fn_153=attr(self_value(),"send_resonance_key");Args args_152;return invoke(fn_153,args_152);}());
        // Brant.py:86
        if(([&]()->V{V compare_154=([&]()->V{V left_156=([&]()->V{auto fn_159=attr(global("time","Brant"),"time");Args args_158;return invoke(fn_159,args_158);}());V right_157=scope_148->get("start");return official::binary("-",left_156,right_157);}());V compare_155;V comparison_result_160;compare_155=V(1LL);comparison_result_160=compare_value(">",compare_154,compare_155);return comparison_result_160;}()).truth()){
            // Brant.py:87
            break;
        }
        // Brant.py:88
        ([&]()->V{auto fn_162=attr(self_value(),"check_combat");Args args_161;return invoke(fn_162,args_161);}());
        // Brant.py:89
        ([&]()->V{auto fn_164=attr(attr(self_value(),"task"),"next_frame");Args args_163;return invoke(fn_164,args_163);}());
    }
return V{};
}),false);
// Official method Brant.click_jump_with_click, lines 91-106
register_method("click_jump_with_click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"delay",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_170=bind_arguments(official_args,signature,captured);
scope_170->set("click",V::missing());
scope_170->set("start",V::missing());
    // Brant.py:92
    {V value_171=V(0LL);scope_170->set("click",value_171);}
    // Brant.py:93
    if(([&]()->V{V operand_172;operand_172=attr(attr(self_value(),"task"),"has_lavitator");if(!operand_172.truth())return operand_172;return unary("not",([&]()->V{auto fn_174=attr(self_value(),"flying");Args args_173;return invoke(fn_174,args_173);}()));}()).truth()){
        // Brant.py:94
        ([&]()->V{auto fn_176=attr(self_value(),"flick_resonance");Args args_175;return invoke(fn_176,args_175);}());
        // Brant.py:95
        ([&]()->V{auto fn_178=attr(self_value(),"sleep");Args args_177;args_177.pos(V(0.2));return invoke(fn_178,args_177);}());
        // Brant.py:96
        {V value_179=V(1LL);scope_170->set("click",value_179);}
    }
    // Brant.py:97
    {V value_180=([&]()->V{auto fn_182=attr(global("time","Brant"),"time");Args args_181;return invoke(fn_182,args_181);}());scope_170->set("start",value_180);}
    // Brant.py:98
        while(V(true).truth()){
        // Brant.py:99
        if(([&]()->V{V compare_183=([&]()->V{V left_185=([&]()->V{auto fn_188=attr(global("time","Brant"),"time");Args args_187;return invoke(fn_188,args_187);}());V right_186=scope_170->get("start");return official::binary("-",left_185,right_186);}());V compare_184;V comparison_result_189;compare_184=scope_170->get("delay");comparison_result_189=compare_value(">",compare_183,compare_184);return comparison_result_189;}()).truth()){
            // Brant.py:100
            break;
        }
        // Brant.py:101
        if(([&]()->V{V compare_190=scope_170->get("click");V compare_191;V comparison_result_192;compare_191=V(0LL);comparison_result_192=compare_value("==",compare_190,compare_191);return comparison_result_192;}()).truth()){
            // Brant.py:102
            ([&]()->V{auto fn_194=attr(attr(self_value(),"task"),"jump");Args args_193;return invoke(fn_194,args_193);}());
        }else{
            // Brant.py:104
            ([&]()->V{auto fn_196=attr(self_value(),"click");Args args_195;return invoke(fn_196,args_195);}());
        }
        // Brant.py:105
        {V value_197=([&]()->V{V left_198=V(1LL);V right_199=scope_170->get("click");return official::binary("-",left_198,right_199);}());scope_170->set("click",value_197);}
        // Brant.py:106
        ([&]()->V{auto fn_201=attr(attr(self_value(),"task"),"next_frame");Args args_200;return invoke(fn_201,args_200);}());
    }
return V{};
}),false);
// Official method Brant.get_switch_priority, lines 108-116
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_202=bind_arguments(official_args,signature,captured);
    // Brant.py:109
    ([&]()->V{auto fn_204=attr(self_value(),"decide_teammate");Args args_203;return invoke(fn_204,args_203);}());
    // Brant.py:110
    if(([&]()->V{V compare_205=([&]()->V{auto fn_208=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_207;args_207.pos(attr(self_value(),"perform_anchor"));args_207.pos(V(true));return invoke(fn_208,args_207);}());V compare_206;V comparison_result_209;compare_206=V(4LL);comparison_result_209=compare_value("<",compare_205,compare_206);return comparison_result_209;}()).truth()){
        // Brant.py:111
        return attr(global("SwitchPriority","Brant"),"NO");
    }
    // Brant.py:112
    if(([&]()->V{auto fn_211=attr(self_value(),"still_in_liberation");Args args_210;return invoke(fn_211,args_210);}()).truth()){
        // Brant.py:113
        return attr(global("SwitchPriority","Brant"),"MUST");
    }
    // Brant.py:114
    if(([&]()->V{V operand_212;operand_212=scope_202->get("has_intro");if(!operand_212.truth())return operand_212;operand_212=scope_202->get("current_char");if(!operand_212.truth())return operand_212;return ([&]()->V{V compare_213=attr(scope_202->get("current_char"),"char_name");V compare_214;V comparison_result_215;compare_214=V::set({V("char_lupa")});comparison_result_215=compare_value("in",compare_213,compare_214);return comparison_result_215;}());}()).truth()){
        // Brant.py:115
        return attr(global("SwitchPriority","Brant"),"MUST");
    }
    // Brant.py:116
    return ([&]()->V{auto fn_219=attr(([&]()->V{auto fn_217=global("super","Brant");Args args_216;return invoke(fn_217,args_216);}()),"get_switch_priority");Args args_218;args_218.pos(scope_202->get("current_char"));args_218.pos(scope_202->get("has_intro"));args_218.pos(scope_202->get("target_low_con"));return invoke(fn_219,args_218);}());
return V{};
}),false);
// Official method Brant.decide_teammate, lines 118-129
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_220=bind_arguments(official_args,signature,captured);
scope_220->set("Lupa",V::missing());
scope_220->set("_",V::missing());
scope_220->set("char",V::missing());
    // Brant.py:119
    if(([&]()->V{V compare_221=attr(self_value(),"attribute");V compare_222;V comparison_result_223;compare_222=V(0LL);comparison_result_223=compare_value(">",compare_221,compare_222);return comparison_result_223;}()).truth()){
        // Brant.py:120
        return V{};
    }
    // Brant.py:121
    scope_220->set("Lupa",import_value("src.char.Lupa","Lupa"));
    // Brant.py:122
    {auto iterator_224=official::iterate(([&]()->V{auto fn_233=global("enumerate","Brant");Args args_232;args_232.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_233,args_232);}()));V item_225;while(iterator_224.next(item_225)){
        auto unpack_234=unpack(item_225,2);scope_220->set("_",unpack_234[0]);scope_220->set("char",unpack_234[1]);
        // Brant.py:123
        ([&]()->V{auto fn_227=attr(attr(self_value(),"logger"),"debug");Args args_226;args_226.pos(V(std::string{}+"teammate char: "+format_value(attr(scope_220->get("char"),"char_name"),"",-1)));return invoke(fn_227,args_226);}());
        // Brant.py:124
        if(([&]()->V{auto fn_229=global("isinstance","Brant");Args args_228;args_228.pos(scope_220->get("char"));args_228.pos(scope_220->get("Lupa"));return invoke(fn_229,args_228);}()).truth()){
            // Brant.py:125
            {V value_230=scope_220->get("char");set_attr(self_value(),"char_lupa",value_230);}
            // Brant.py:126
            {V value_231=V(1LL);set_attr(self_value(),"attribute",value_231);}
            // Brant.py:127
            return V{};
        }
    }
    }
    // Brant.py:128
    {V value_235=V(1LL);set_attr(self_value(),"attribute",value_235);}
    // Brant.py:129
    return V{};
return V{};
}),false);
// Official method Brant.flick_resonance, lines 131-139
register_method("flick_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(0.2)},{"send_click",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_236=bind_arguments(official_args,signature,captured);
    // Brant.py:132
    if(([&]()->V{V operand_237;operand_237=scope_236->get("send_click");if(!operand_237.truth())return operand_237;return ([&]()->V{auto fn_239=attr(self_value(),"resonance_available");Args args_238;return invoke(fn_239,args_238);}());}()).truth()){
        // Brant.py:133
        ([&]()->V{auto fn_241=attr(attr(self_value(),"task"),"wait_until");Args args_240;args_240.pos(V::function([this,captured=capture_scope(scope_236,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_242=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_243=([&]()->V{auto fn_246=attr(self_value(),"current_resonance");Args args_245;return invoke(fn_246,args_245);}());V compare_244;V comparison_result_247;compare_244=V(0LL);comparison_result_247=compare_value(">",compare_243,compare_244);return comparison_result_247;}());
}));args_240.kw("post_action",attr(self_value(),"click_with_interval"));args_240.kw("time_out",V(0.2));return invoke(fn_241,args_240);}());
    }
    // Brant.py:135
    if(([&]()->V{V operand_248;operand_248=([&]()->V{V compare_249=([&]()->V{auto fn_252=attr(self_value(),"current_resonance");Args args_251;return invoke(fn_252,args_251);}());V compare_250;V comparison_result_253;compare_250=V(0LL);comparison_result_253=compare_value(">",compare_249,compare_250);return comparison_result_253;}());if(!operand_248.truth())return operand_248;return ([&]()->V{auto fn_255=attr(self_value(),"resonance_available");Args args_254;return invoke(fn_255,args_254);}());}()).truth()){
        // Brant.py:136
        ([&]()->V{auto fn_257=attr(attr(self_value(),"task"),"wait_until");Args args_256;args_256.pos(V::function([this,captured=capture_scope(scope_236,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_258=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_260=attr(self_value(),"resonance_available");Args args_259;return invoke(fn_260,args_259);}()));
}));args_256.kw("post_action",attr(self_value(),"send_resonance_key"));args_256.kw("time_out",scope_236->get("time_out"));return invoke(fn_257,args_256);}());
        // Brant.py:138
        return V(true);
    }
    // Brant.py:139
    return V(false);
return V{};
}),false);
// Official method Brant.wait_down, lines 141-143
register_method("wait_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(1.2)},{"click",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_261=bind_arguments(official_args,signature,captured);
    // Brant.py:142
    ([&]()->V{auto fn_263=attr(attr(self_value(),"task"),"wait_until");Args args_262;args_262.pos(V::function([this,captured=capture_scope(scope_261,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_264=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_266=attr(self_value(),"flying");Args args_265;return invoke(fn_266,args_265);}()));
}));args_262.kw("post_action",(scope_261->get("click").truth()?attr(self_value(),"click_with_interval"):V{}));args_262.kw("time_out",scope_261->get("time_out"));return invoke(fn_263,args_262);}());
return V{};
}),false);
}
