// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Lupa.py
// SHA256 370044330298962451bd953fe5641f1d5dd36adc11f7dc2ffa5bd4c4bc298dcc
void OfficialCharacter::install_Lupa(){
auto scope=std::make_shared<Scope>();
set_global("lupa_red_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(235LL),V(255LL)}));set_item(dictionary_1,V("g"),V::tuple({V(75LL),V(105LL)}));set_item(dictionary_1,V("b"),V::tuple({V(75LL),V(105LL)}));return dictionary_1;}()));
// Official method Lupa.__init__, lines 10-13
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Lupa.py:11
    ([&]()->V{auto fn_6=attr(([&]()->V{auto fn_4=global("super","Lupa");Args args_3;return invoke(fn_4,args_3);}()),"__init__");Args args_5;args_5.spread(scope_2->get("args"));args_5.spread_keywords(scope_2->get("kwargs"));return invoke(fn_6,args_5);}());
    // Lupa.py:12
    {V value_7=V(false);set_attr(self_value(),"wolf",value_7);}
    // Lupa.py:13
    {V value_8=V(false);set_attr(self_value(),"check_f_on_switch",value_8);}
return V{};
}),false);
// Official method Lupa.reset_state, lines 15-17
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_9=bind_arguments(official_args,signature,captured);
    // Lupa.py:16
    ([&]()->V{auto fn_13=attr(([&]()->V{auto fn_11=global("super","Lupa");Args args_10;return invoke(fn_11,args_10);}()),"reset_state");Args args_12;return invoke(fn_13,args_12);}());
    // Lupa.py:17
    {V value_14=V(false);set_attr(self_value(),"wolf",value_14);}
return V{};
}),false);
// Official method Lupa.do_perform, lines 19-75
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
scope_15->set("in_outro",V::missing());
    // Lupa.py:20
    {V value_16=V(false);scope_15->set("in_outro",value_16);}
    // Lupa.py:21
    if(attr(self_value(),"has_intro").truth()){
        // Lupa.py:22
        ([&]()->V{auto fn_18=attr(self_value(),"continues_normal_attack");Args args_17;args_17.pos(V(1LL));return invoke(fn_18,args_17);}());
        // Lupa.py:23
        if(([&]()->V{V compare_19=([&]()->V{auto fn_22=attr(self_value(),"check_outro");Args args_21;return invoke(fn_22,args_21);}());V compare_20;V comparison_result_23;compare_20=V("chang_changli");comparison_result_23=compare_value("==",compare_19,compare_20);return comparison_result_23;}()).truth()){
            // Lupa.py:24
            {V value_24=V(true);scope_15->set("in_outro",value_24);}
        }
    }
    // Lupa.py:25
    ([&]()->V{auto fn_26=attr(self_value(),"click_echo");Args args_25;args_25.kw("time_out",V(0LL));return invoke(fn_26,args_25);}());
    // Lupa.py:26
    if(([&]()->V{V operand_27;operand_27=([&]()->V{auto fn_29=attr(self_value(),"res_wolf");Args args_28;return invoke(fn_29,args_28);}());if(!operand_27.truth())return operand_27;return unary("not",scope_15->get("in_outro"));}()).truth()){
        // Lupa.py:27
        return ([&]()->V{auto fn_31=attr(self_value(),"switch_next_char");Args args_30;return invoke(fn_31,args_30);}());
    }
    // Lupa.py:28
    if(([&]()->V{V operand_32;operand_32=([&]()->V{V compare_33=([&]()->V{auto fn_36=attr(self_value(),"judge_forte");Args args_35;return invoke(fn_36,args_35);}());V compare_34;V comparison_result_37;compare_34=V(2LL);comparison_result_37=compare_value("==",compare_33,compare_34);return comparison_result_37;}());if(!operand_32.truth())return operand_32;return unary("not",([&]()->V{auto fn_39=attr(attr(self_value(),"task"),"find_one");Args args_38;args_38.pos(V("lupa_wolf_icon2"));args_38.kw("threshold",V(0.85));return invoke(fn_39,args_38);}()));}()).truth()){
        // Lupa.py:29
        ([&]()->V{auto fn_41=attr(attr(self_value(),"logger"),"debug");Args args_40;args_40.pos(V("perform forte full"));return invoke(fn_41,args_40);}());
        // Lupa.py:30
        if(([&]()->V{auto fn_43=attr(self_value(),"flying");Args args_42;return invoke(fn_43,args_42);}()).truth()){
            // Lupa.py:31
            ([&]()->V{auto fn_45=attr(attr(self_value(),"task"),"wait_until");Args args_44;args_44.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_46=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_48=attr(self_value(),"is_forte_full");Args args_47;return invoke(fn_48,args_47);}()));
}));args_44.kw("post_action",attr(self_value(),"click_with_interval"));args_44.kw("time_out",V(2LL));return invoke(fn_45,args_44);}());
        }else{
            // Lupa.py:33
            ([&]()->V{auto fn_50=attr(self_value(),"heavy_attack");Args args_49;return invoke(fn_50,args_49);}());
            // Lupa.py:34
            ([&]()->V{auto fn_52=attr(attr(self_value(),"task"),"wait_until");Args args_51;args_51.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_53=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_55=attr(self_value(),"is_forte_full");Args args_54;return invoke(fn_55,args_54);}()));
}));args_51.kw("post_action",attr(self_value(),"click_with_interval"));args_51.kw("time_out",V(1.4));return invoke(fn_52,args_51);}());
        }
        // Lupa.py:36
        if(unary("not",([&]()->V{auto fn_57=attr(self_value(),"is_forte_full");Args args_56;return invoke(fn_57,args_56);}())).truth()){
            // Lupa.py:37
            {V value_58=V(true);set_attr(self_value(),"wolf",value_58);}
        }
        // Lupa.py:38
        if(scope_15->get("in_outro").truth()){
            // Lupa.py:39
            ([&]()->V{auto fn_60=attr(attr(self_value(),"task"),"wait_until");Args args_59;args_59.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_61=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_63=attr(attr(self_value(),"task"),"find_one");Args args_62;args_62.pos(V("lupa_wolf_icon2"));args_62.kw("threshold",V(0.85));return invoke(fn_63,args_62);}());
}));args_59.kw("post_action",V{});args_59.kw("time_out",V(0.5));return invoke(fn_60,args_59);}());
            // Lupa.py:41
            ([&]()->V{auto fn_65=attr(self_value(),"res_wolf");Args args_64;return invoke(fn_65,args_64);}());
        }else{
            // Lupa.py:43
            return ([&]()->V{auto fn_67=attr(self_value(),"switch_next_char");Args args_66;return invoke(fn_67,args_66);}());
        }
    }
    // Lupa.py:44
    ([&]()->V{auto fn_69=attr(attr(self_value(),"logger"),"debug");Args args_68;args_68.pos(V(std::string{}+"resonance percent "+format_value(([&]()->V{auto fn_71=attr(self_value(),"current_resonance");Args args_70;return invoke(fn_71,args_70);}()),"",-1)));return invoke(fn_69,args_68);}());
    // Lupa.py:45
    if(([&]()->V{V operand_72;operand_72=([&]()->V{V compare_73=([&]()->V{auto fn_76=attr(self_value(),"current_resonance");Args args_75;return invoke(fn_76,args_75);}());V compare_74;V comparison_result_77;compare_74=V(0.05);comparison_result_77=compare_value(">",compare_73,compare_74);return comparison_result_77;}());if(!operand_72.truth())return operand_72;return item(([&]()->V{auto fn_79=attr(self_value(),"click_resonance");Args args_78;return invoke(fn_79,args_78);}()),V(0LL));}()).truth()){
        // Lupa.py:46
        {V value_80=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_80);}
        // Lupa.py:47
        if(([&]()->V{auto fn_82=attr(self_value(),"liberation_available");Args args_81;return invoke(fn_82,args_81);}()).truth()){
            // Lupa.py:48
            ([&]()->V{auto fn_84=attr(self_value(),"wait_down");Args args_83;return invoke(fn_84,args_83);}());
        }else{
            // Lupa.py:50
            return ([&]()->V{auto fn_86=attr(self_value(),"switch_next_char");Args args_85;return invoke(fn_86,args_85);}());
        }
    }
    // Lupa.py:51
    ([&]()->V{auto fn_88=attr(self_value(),"f_break");Args args_87;return invoke(fn_88,args_87);}());
    // Lupa.py:52
    if(([&]()->V{V operand_89;operand_89=([&]()->V{V operand_90;operand_90=scope_15->get("in_outro");if(operand_90.truth())return operand_90;return unary("not",([&]()->V{auto fn_92=attr(self_value(),"need_fast_perform");Args args_91;return invoke(fn_92,args_91);}()));}());if(!operand_89.truth())return operand_89;return ([&]()->V{auto fn_94=attr(self_value(),"click_liberation");Args args_93;return invoke(fn_94,args_93);}());}()).truth()){
        // Lupa.py:53
        ([&]()->V{auto fn_96=attr(self_value(),"continues_normal_attack");Args args_95;args_95.pos(V(0.3));return invoke(fn_96,args_95);}());
        // Lupa.py:54
        if(scope_15->get("in_outro").truth()){
            // Lupa.py:55
            ([&]()->V{auto fn_98=attr(self_value(),"continues_normal_attack");Args args_97;args_97.pos(V(1LL));return invoke(fn_98,args_97);}());
        }else{
            // Lupa.py:57
            return ([&]()->V{auto fn_100=attr(self_value(),"switch_next_char");Args args_99;return invoke(fn_100,args_99);}());
        }
    }
    // Lupa.py:58
    if(([&]()->V{auto fn_102=attr(self_value(),"still_in_liberation");Args args_101;return invoke(fn_102,args_101);}()).truth()){
        // Lupa.py:59
        ([&]()->V{auto fn_104=attr(attr(self_value(),"logger"),"debug");Args args_103;args_103.pos(V("perform in liberation"));return invoke(fn_104,args_103);}());
        // Lupa.py:60
        ([&]()->V{auto fn_106=attr(self_value(),"click_jump_with_click");Args args_105;args_105.pos(V(4LL));return invoke(fn_106,args_105);}());
        // Lupa.py:61
        if(([&]()->V{auto fn_108=attr(self_value(),"flying");Args args_107;return invoke(fn_108,args_107);}()).truth()){
            // Lupa.py:62
            ([&]()->V{auto fn_110=attr(attr(self_value(),"task"),"wait_until");Args args_109;args_109.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_111=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_113=attr(self_value(),"is_forte_full");Args args_112;return invoke(fn_113,args_112);}()));
}));args_109.kw("post_action",attr(self_value(),"click_with_interval"));args_109.kw("time_out",V(2LL));return invoke(fn_110,args_109);}());
        }else{
            // Lupa.py:64
            ([&]()->V{auto fn_115=attr(self_value(),"heavy_attack");Args args_114;return invoke(fn_115,args_114);}());
            // Lupa.py:65
            ([&]()->V{auto fn_117=attr(attr(self_value(),"task"),"wait_until");Args args_116;args_116.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_118=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_120=attr(self_value(),"is_forte_full");Args args_119;return invoke(fn_120,args_119);}()));
}));args_116.kw("post_action",attr(self_value(),"click_with_interval"));args_116.kw("time_out",V(1.4));return invoke(fn_117,args_116);}());
        }
        // Lupa.py:67
        if(unary("not",([&]()->V{auto fn_122=attr(self_value(),"is_forte_full");Args args_121;return invoke(fn_122,args_121);}())).truth()){
            // Lupa.py:68
            {V value_123=V(true);set_attr(self_value(),"wolf",value_123);}
        }
        // Lupa.py:69
        if(scope_15->get("in_outro").truth()){
            // Lupa.py:70
            ([&]()->V{auto fn_125=attr(attr(self_value(),"task"),"wait_until");Args args_124;args_124.pos(V::function([this,captured=capture_scope(scope_15,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_126=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_128=attr(attr(self_value(),"task"),"find_one");Args args_127;args_127.pos(V("lupa_wolf_icon2"));args_127.kw("threshold",V(0.85));return invoke(fn_128,args_127);}());
}));args_124.kw("post_action",V{});args_124.kw("time_out",V(0.5));return invoke(fn_125,args_124);}());
            // Lupa.py:72
            ([&]()->V{auto fn_130=attr(self_value(),"res_wolf");Args args_129;return invoke(fn_130,args_129);}());
        }
        // Lupa.py:73
        return ([&]()->V{auto fn_132=attr(self_value(),"switch_next_char");Args args_131;return invoke(fn_132,args_131);}());
    }
    // Lupa.py:74
    ([&]()->V{auto fn_134=attr(self_value(),"continues_normal_attack");Args args_133;args_133.pos(V(0.1));return invoke(fn_134,args_133);}());
    // Lupa.py:75
    ([&]()->V{auto fn_136=attr(self_value(),"switch_next_char");Args args_135;return invoke(fn_136,args_135);}());
return V{};
}),false);
// Official method Lupa.still_in_liberation, lines 77-78
register_method("still_in_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_137=bind_arguments(official_args,signature,captured);
    // Lupa.py:78
    return ([&]()->V{V compare_138=([&]()->V{auto fn_141=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_140;args_140.pos(attr(self_value(),"last_liberation"));return invoke(fn_141,args_140);}());V compare_139;V comparison_result_142;compare_139=V(12LL);comparison_result_142=compare_value("<",compare_138,compare_139);return comparison_result_142;}());
return V{};
}),false);
// Official method Lupa.get_switch_priority, lines 80-85
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_143=bind_arguments(official_args,signature,captured);
    // Lupa.py:81
    if(([&]()->V{auto fn_145=attr(self_value(),"still_in_liberation");Args args_144;return invoke(fn_145,args_144);}()).truth()){
        // Lupa.py:82
        return attr(global("SwitchPriority","Lupa"),"MUST");
    }
    // Lupa.py:83
    if(([&]()->V{V operand_146;operand_146=scope_143->get("has_intro");if(!operand_146.truth())return operand_146;operand_146=scope_143->get("current_char");if(!operand_146.truth())return operand_146;return ([&]()->V{V compare_147=attr(scope_143->get("current_char"),"char_name");V compare_148;V comparison_result_149;compare_148=V::set({V("chang_changli")});comparison_result_149=compare_value("in",compare_147,compare_148);return comparison_result_149;}());}()).truth()){
        // Lupa.py:84
        return attr(global("SwitchPriority","Lupa"),"MUST");
    }
    // Lupa.py:85
    return ([&]()->V{auto fn_153=attr(([&]()->V{auto fn_151=global("super","Lupa");Args args_150;return invoke(fn_151,args_150);}()),"get_switch_priority");Args args_152;args_152.pos(scope_143->get("current_char"));args_152.pos(scope_143->get("has_intro"));args_152.pos(scope_143->get("target_low_con"));return invoke(fn_153,args_152);}());
return V{};
}),false);
// Official method Lupa.click_jump_with_click, lines 87-101
register_method("click_jump_with_click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"delay",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_154=bind_arguments(official_args,signature,captured);
scope_154->set("click",V::missing());
scope_154->set("start",V::missing());
    // Lupa.py:88
    {V value_155=([&]()->V{auto fn_157=attr(global("time","Lupa"),"time");Args args_156;return invoke(fn_157,args_156);}());scope_154->set("start",value_155);}
    // Lupa.py:89
    {V value_158=V(0LL);scope_154->set("click",value_158);}
    // Lupa.py:90
        while(V(true).truth()){
        // Lupa.py:91
        if(([&]()->V{V compare_159=([&]()->V{V left_161=([&]()->V{auto fn_164=attr(global("time","Lupa"),"time");Args args_163;return invoke(fn_164,args_163);}());V right_162=scope_154->get("start");return official::binary("-",left_161,right_162);}());V compare_160;V comparison_result_165;compare_160=scope_154->get("delay");comparison_result_165=compare_value(">",compare_159,compare_160);return comparison_result_165;}()).truth()){
            // Lupa.py:92
            break;
        }
        // Lupa.py:93
        if(([&]()->V{V compare_166=scope_154->get("click");V compare_167;V comparison_result_168;compare_167=V(0LL);comparison_result_168=compare_value("==",compare_166,compare_167);return comparison_result_168;}()).truth()){
            // Lupa.py:94
            ([&]()->V{auto fn_170=attr(attr(self_value(),"task"),"jump");Args args_169;args_169.kw("after_sleep",V(0.01));return invoke(fn_170,args_169);}());
        }else{
            // Lupa.py:96
            ([&]()->V{auto fn_172=attr(self_value(),"click");Args args_171;return invoke(fn_172,args_171);}());
        }
        // Lupa.py:97
        {V value_173=([&]()->V{V left_174=V(1LL);V right_175=scope_154->get("click");return official::binary("-",left_174,right_175);}());scope_154->set("click",value_173);}
        // Lupa.py:98
        if(([&]()->V{V compare_176=([&]()->V{auto fn_179=attr(self_value(),"judge_forte");Args args_178;return invoke(fn_179,args_178);}());V compare_177;V comparison_result_180;compare_177=V(2LL);comparison_result_180=compare_value("==",compare_176,compare_177);return comparison_result_180;}()).truth()){
            // Lupa.py:99
            return V{};
        }
        // Lupa.py:100
        ([&]()->V{auto fn_182=attr(self_value(),"check_combat");Args args_181;return invoke(fn_182,args_181);}());
        // Lupa.py:101
        ([&]()->V{auto fn_184=attr(attr(self_value(),"task"),"next_frame");Args args_183;return invoke(fn_184,args_183);}());
    }
return V{};
}),false);
// Official method Lupa.res_wolf, lines 103-122
register_method("res_wolf",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"timeout",V(1LL)}},"","",{})](const Args& official_args)->V{
auto scope_185=bind_arguments(official_args,signature,captured);
scope_185->set("click",V::missing());
scope_185->set("start",V::missing());
    // Lupa.py:104
    ([&]()->V{auto fn_187=attr(attr(self_value(),"logger"),"debug");Args args_186;args_186.pos(V("perform res wolf"));return invoke(fn_187,args_186);}());
    // Lupa.py:105
    {V value_188=([&]()->V{auto fn_190=attr(global("time","Lupa"),"time");Args args_189;return invoke(fn_190,args_189);}());scope_185->set("start",value_188);}
    // Lupa.py:106
    {V value_191=V(false);scope_185->set("click",value_191);}
    // Lupa.py:107
        while(V(true).truth()){
        // Lupa.py:108
        if(([&]()->V{V operand_192;operand_192=attr(self_value(),"wolf");if(!operand_192.truth())return operand_192;return ([&]()->V{V compare_193=([&]()->V{V left_195=([&]()->V{auto fn_198=attr(global("time","Lupa"),"time");Args args_197;return invoke(fn_198,args_197);}());V right_196=scope_185->get("start");return official::binary("-",left_195,right_196);}());V compare_194;V comparison_result_199;compare_194=V(0.2);comparison_result_199=compare_value("<",compare_193,compare_194);return comparison_result_199;}());}()).truth()){
        }else{
            // Lupa.py:110
            if(unary("not",([&]()->V{auto fn_201=attr(attr(self_value(),"task"),"find_one");Args args_200;args_200.pos(V("lupa_wolf_icon2"));args_200.kw("threshold",V(0.85));return invoke(fn_201,args_200);}())).truth()){
                // Lupa.py:111
                break;
            }
        }
        // Lupa.py:112
        ([&]()->V{auto fn_203=attr(self_value(),"send_resonance_key");Args args_202;return invoke(fn_203,args_202);}());
        // Lupa.py:113
        {V value_204=V(true);scope_185->set("click",value_204);}
        // Lupa.py:114
        if(([&]()->V{V compare_205=([&]()->V{V left_207=([&]()->V{auto fn_210=attr(global("time","Lupa"),"time");Args args_209;return invoke(fn_210,args_209);}());V right_208=scope_185->get("start");return official::binary("-",left_207,right_208);}());V compare_206;V comparison_result_211;compare_206=scope_185->get("timeout");comparison_result_211=compare_value(">",compare_205,compare_206);return comparison_result_211;}()).truth()){
            // Lupa.py:115
            break;
        }
        // Lupa.py:116
        ([&]()->V{auto fn_213=attr(self_value(),"check_combat");Args args_212;return invoke(fn_213,args_212);}());
        // Lupa.py:117
        ([&]()->V{auto fn_215=attr(attr(self_value(),"task"),"next_frame");Args args_214;return invoke(fn_215,args_214);}());
    }
    // Lupa.py:118
    if(scope_185->get("click").truth()){
        // Lupa.py:119
        {V value_216=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_216);}
        // Lupa.py:120
        {V value_217=V(false);set_attr(self_value(),"wolf",value_217);}
        // Lupa.py:121
        ([&]()->V{auto fn_219=attr(self_value(),"sleep");Args args_218;args_218.pos(V(1.2));return invoke(fn_219,args_218);}());
    }
    // Lupa.py:122
    return scope_185->get("click");
return V{};
}),false);
// Official method Lupa.judge_forte, lines 124-129
register_method("judge_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_220=bind_arguments(official_args,signature,captured);
scope_220->set("box",V::missing());
scope_220->set("forte",V::missing());
    // Lupa.py:125
    if(unary("not",([&]()->V{auto fn_222=attr(self_value(),"is_forte_full");Args args_221;return invoke(fn_222,args_221);}())).truth()){
        // Lupa.py:126
        return V(0LL);
    }
    // Lupa.py:127
    {V value_223=([&]()->V{auto fn_225=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_224;args_224.pos(V(3840LL));args_224.pos(V(2160LL));args_224.pos(V(1633LL));args_224.pos(V(2004LL));args_224.pos(V(2160LL));args_224.pos(V(2016LL));args_224.kw("name",V("lupa_forte"));args_224.kw("hcenter",V(true));return invoke(fn_225,args_224);}());scope_220->set("box",value_223);}
    // Lupa.py:128
    {V value_226=([&]()->V{auto fn_228=attr(self_value(),"calculate_forte_num");Args args_227;args_227.pos(global("lupa_red_color","Lupa"));args_227.pos(scope_220->get("box"));args_227.pos(V(2LL));args_227.pos(V(19LL));args_227.pos(V(21LL));args_227.pos(V(400LL));return invoke(fn_228,args_227);}());scope_220->set("forte",value_226);}
    // Lupa.py:129
    return scope_220->get("forte");
return V{};
}),false);
// Official method Lupa.judge_frequncy_and_amplitude, lines 131-148
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_229=bind_arguments(official_args,signature,captured);
scope_229->set("amplitude",V::missing());
scope_229->set("frequncy",V::missing());
scope_229->set("height",V::missing());
scope_229->set("i",V::missing());
scope_229->set("n",V::missing());
scope_229->set("profile",V::missing());
scope_229->set("width",V::missing());
    // Lupa.py:132
    {V value_230=item(attr(scope_229->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_231=unpack(value_230,2);scope_229->set("height",unpack_231[0]);scope_229->set("width",unpack_231[1]);}
    // Lupa.py:133
    if(([&]()->V{V operand_232;operand_232=([&]()->V{V compare_233=scope_229->get("height");V compare_234;V comparison_result_235;compare_234=V(0LL);comparison_result_235=compare_value("==",compare_233,compare_234);return comparison_result_235;}());if(operand_232.truth())return operand_232;operand_232=([&]()->V{V compare_236=scope_229->get("width");V compare_237;V comparison_result_238;compare_237=V(64LL);comparison_result_238=compare_value("<",compare_236,compare_237);return comparison_result_238;}());if(operand_232.truth())return operand_232;return unary("not",([&]()->V{auto fn_240=attr(global("np","Lupa"),"array_equal");Args args_239;args_239.pos(([&]()->V{auto fn_242=attr(global("np","Lupa"),"unique");Args args_241;args_241.pos(scope_229->get("gray"));return invoke(fn_242,args_241);}()));args_239.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_240,args_239);}()));}()).truth()){
        // Lupa.py:134
        return V(0LL);
    }
    // Lupa.py:136
    {V value_243=([&]()->V{auto fn_250=attr(([&]()->V{auto fn_245=attr(global("np","Lupa"),"sum");Args args_244;args_244.pos(([&]()->V{V compare_246=scope_229->get("gray");V compare_247;V comparison_result_248;compare_247=V(255LL);comparison_result_248=compare_value("==",compare_246,compare_247);return comparison_result_248;}()));args_244.kw("axis",V(0LL));return invoke(fn_245,args_244);}()),"astype");Args args_249;args_249.pos(attr(global("np","Lupa"),"float32"));return invoke(fn_250,args_249);}());scope_229->set("profile",value_243);}
    // Lupa.py:137
    scope_229->set("profile",official::binary("-",scope_229->get("profile"),([&]()->V{auto fn_252=attr(global("np","Lupa"),"mean");Args args_251;args_251.pos(scope_229->get("profile"));return invoke(fn_252,args_251);}())));
    // Lupa.py:138
    {V value_253=([&]()->V{auto fn_255=attr(global("np","Lupa"),"abs");Args args_254;args_254.pos(([&]()->V{auto fn_257=attr(attr(global("np","Lupa"),"fft"),"fft");Args args_256;args_256.pos(scope_229->get("profile"));return invoke(fn_257,args_256);}()));return invoke(fn_255,args_254);}());scope_229->set("n",value_253);}
    // Lupa.py:139
    {V value_258=V(0LL);scope_229->set("amplitude",value_258);}
    // Lupa.py:140
    {V value_259=V(0LL);scope_229->set("frequncy",value_259);}
    // Lupa.py:141
    {V value_260=V(1LL);scope_229->set("i",value_260);}
    // Lupa.py:142
        while(([&]()->V{V compare_266=scope_229->get("i");V compare_267;V comparison_result_268;compare_267=scope_229->get("width");comparison_result_268=compare_value("<",compare_266,compare_267);return comparison_result_268;}()).truth()){
        // Lupa.py:143
        if(([&]()->V{V compare_261=item(scope_229->get("n"),scope_229->get("i"));V compare_262;V comparison_result_263;compare_262=scope_229->get("amplitude");comparison_result_263=compare_value(">",compare_261,compare_262);return comparison_result_263;}()).truth()){
            // Lupa.py:144
            {V value_264=item(scope_229->get("n"),scope_229->get("i"));scope_229->set("amplitude",value_264);}
            // Lupa.py:145
            {V value_265=scope_229->get("i");scope_229->set("frequncy",value_265);}
        }
        // Lupa.py:146
        scope_229->set("i",official::binary("+",scope_229->get("i"),V(1LL)));
    }
    // Lupa.py:147
    ([&]()->V{auto fn_270=attr(attr(self_value(),"logger"),"info");Args args_269;args_269.pos(V(std::string{}+"forte with freq "+format_value(scope_229->get("frequncy"),"",-1)+" & amp "+format_value(scope_229->get("amplitude"),"",-1)));return invoke(fn_270,args_269);}());
    // Lupa.py:148
    return ([&]()->V{V operand_271;operand_271=([&]()->V{V compare_272=scope_229->get("min_freq");V compare_273;V comparison_result_274;compare_273=scope_229->get("frequncy");comparison_result_274=compare_value("<=",compare_272,compare_273);if(!comparison_result_274.truth())return comparison_result_274;compare_272=compare_273;compare_273=scope_229->get("max_freq");comparison_result_274=compare_value("<=",compare_272,compare_273);return comparison_result_274;}());if(operand_271.truth())return operand_271;return ([&]()->V{V compare_275=scope_229->get("amplitude");V compare_276;V comparison_result_277;compare_276=scope_229->get("min_amp");comparison_result_277=compare_value(">=",compare_275,compare_276);return comparison_result_277;}());}());
return V{};
}),false);
// Official method Lupa.calculate_forte_num, lines 150-169
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_278=bind_arguments(official_args,signature,captured);
scope_278->set("cropped",V::missing());
scope_278->set("forte",V::missing());
scope_278->set("gray",V::missing());
scope_278->set("height",V::missing());
scope_278->set("image",V::missing());
scope_278->set("left",V::missing());
scope_278->set("lower_bound",V::missing());
scope_278->set("score",V::missing());
scope_278->set("step",V::missing());
scope_278->set("upper_bound",V::missing());
scope_278->set("width",V::missing());
    // Lupa.py:151
    {V value_279=([&]()->V{auto fn_281=attr(scope_278->get("box"),"crop_frame");Args args_280;args_280.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_281,args_280);}());scope_278->set("cropped",value_279);}
    // Lupa.py:152
    {V value_282=([&]()->V{auto fn_284=global("color_range_to_bound","Lupa");Args args_283;args_283.pos(scope_278->get("forte_color"));return invoke(fn_284,args_283);}());auto unpack_285=unpack(value_282,2);scope_278->set("lower_bound",unpack_285[0]);scope_278->set("upper_bound",unpack_285[1]);}
    // Lupa.py:153
    {V value_286=([&]()->V{auto fn_288=attr(global("cv2","Lupa"),"inRange");Args args_287;args_287.pos(scope_278->get("cropped"));args_287.pos(scope_278->get("lower_bound"));args_287.pos(scope_278->get("upper_bound"));return invoke(fn_288,args_287);}());scope_278->set("image",value_286);}
    // Lupa.py:155
    {V value_289=V(0LL);scope_278->set("forte",value_289);}
    // Lupa.py:156
    {V value_290=attr(scope_278->get("image"),"shape");auto unpack_291=unpack(value_290,2);scope_278->set("height",unpack_291[0]);scope_278->set("width",unpack_291[1]);}
    // Lupa.py:157
    {V value_292=([&]()->V{auto fn_294=global("int","Lupa");Args args_293;args_293.pos(([&]()->V{V left_295=scope_278->get("width");V right_296=scope_278->get("num");return official::binary("/",left_295,right_296);}()));return invoke(fn_294,args_293);}());scope_278->set("step",value_292);}
    // Lupa.py:159
    {V value_297=scope_278->get("num");scope_278->set("forte",value_297);}
    // Lupa.py:160
    {V value_298=([&]()->V{V left_299=scope_278->get("step");V right_300=([&]()->V{V left_301=scope_278->get("forte");V right_302=V(1LL);return official::binary("-",left_301,right_302);}());return official::binary("*",left_299,right_300);}());scope_278->set("left",value_298);}
    // Lupa.py:161
        while(([&]()->V{V compare_309=scope_278->get("forte");V compare_310;V comparison_result_311;compare_310=V(0LL);comparison_result_311=compare_value(">",compare_309,compare_310);return comparison_result_311;}()).truth()){
        // Lupa.py:162
        {V value_303=item(scope_278->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_278->get("left"),([&]()->V{V left_304=scope_278->get("left");V right_305=scope_278->get("step");return official::binary("+",left_304,right_305);}()),V{})}));scope_278->set("gray",value_303);}
        // Lupa.py:163
        {V value_306=([&]()->V{auto fn_308=attr(self_value(),"judge_frequncy_and_amplitude");Args args_307;args_307.pos(scope_278->get("gray"));args_307.pos(scope_278->get("min_freq"));args_307.pos(scope_278->get("max_freq"));args_307.pos(scope_278->get("min_amp"));return invoke(fn_308,args_307);}());scope_278->set("score",value_306);}
        // Lupa.py:164
        if(scope_278->get("score").truth()){
            // Lupa.py:165
            break;
        }
        // Lupa.py:166
        scope_278->set("left",official::binary("-",scope_278->get("left"),scope_278->get("step")));
        // Lupa.py:167
        scope_278->set("forte",official::binary("-",scope_278->get("forte"),V(1LL)));
    }
    // Lupa.py:168
    ([&]()->V{auto fn_313=attr(attr(self_value(),"logger"),"info");Args args_312;args_312.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_278->get("forte"),"",-1)));return invoke(fn_313,args_312);}());
    // Lupa.py:169
    return scope_278->get("forte");
return V{};
}),false);
}
