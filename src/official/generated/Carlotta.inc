// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Carlotta.py
// SHA256 6640f3e95b2a2800d7c4468433b4fdb6256e46914fbbf3450134a183a2f47429
void OfficialCharacter::install_Carlotta(){
auto scope=std::make_shared<Scope>();
set_global("carlotta_forte_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(70LL),V(100LL)}));set_item(dictionary_1,V("g"),V::tuple({V(195LL),V(225LL)}));set_item(dictionary_1,V("b"),V::tuple({V(235LL),V(255LL)}));return dictionary_1;}()));
// Official method Carlotta.__init__, lines 10-17
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Carlotta.py:11
    ([&]()->V{auto fn_6=attr(([&]()->V{auto fn_4=global("super","Carlotta");Args args_3;return invoke(fn_4,args_3);}()),"__init__");Args args_5;args_5.spread(scope_2->get("args"));args_5.spread_keywords(scope_2->get("kwargs"));return invoke(fn_6,args_5);}());
    // Carlotta.py:12
    {V value_7=unary("-",V(1LL));set_attr(self_value(),"switch_lock",value_7);}
    // Carlotta.py:13
    {V value_8=unary("-",V(1LL));set_attr(self_value(),"press_w",value_8);}
    // Carlotta.py:14
    {V value_9=V{};set_attr(self_value(),"char_zhezhi",value_9);}
    // Carlotta.py:15
    {V value_10=V(0LL);set_attr(self_value(),"forte",value_10);}
    // Carlotta.py:16
    {V value_11=V(false);set_attr(self_value(),"continue_liberation",value_11);}
    // Carlotta.py:17
    {V value_12=V(false);set_attr(self_value(),"liberation_ready",value_12);}
return V{};
}),false);
// Official method Carlotta.reset_state, lines 19-26
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_13=bind_arguments(official_args,signature,captured);
    // Carlotta.py:20
    ([&]()->V{auto fn_17=attr(([&]()->V{auto fn_15=global("super","Carlotta");Args args_14;return invoke(fn_15,args_14);}()),"reset_state");Args args_16;return invoke(fn_17,args_16);}());
    // Carlotta.py:21
    {V value_18=unary("-",V(1LL));set_attr(self_value(),"switch_lock",value_18);}
    // Carlotta.py:22
    {V value_19=unary("-",V(1LL));set_attr(self_value(),"press_w",value_19);}
    // Carlotta.py:23
    {V value_20=V{};set_attr(self_value(),"char_zhezhi",value_20);}
    // Carlotta.py:24
    {V value_21=V(0LL);set_attr(self_value(),"forte",value_21);}
    // Carlotta.py:25
    {V value_22=V(false);set_attr(self_value(),"continue_liberation",value_22);}
    // Carlotta.py:26
    {V value_23=V(false);set_attr(self_value(),"liberation_ready",value_23);}
return V{};
}),false);
// Official method Carlotta.do_perform, lines 28-59
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_24=bind_arguments(official_args,signature,captured);
scope_24->set("auto_dodge",V::missing());
    // Carlotta.py:29
    if(([&]()->V{V compare_25=attr(self_value(),"press_w");V compare_26;V comparison_result_27;compare_26=unary("-",V(1LL));comparison_result_27=compare_value("==",compare_25,compare_26);return comparison_result_27;}()).truth()){
        // Carlotta.py:30
        ([&]()->V{auto fn_29=attr(self_value(),"decide_teammate");Args args_28;return invoke(fn_29,args_28);}());
    }
    // Carlotta.py:31
    if(([&]()->V{V compare_30=attr(self_value(),"char_zhezhi");V compare_31;V comparison_result_32;compare_31=V{};comparison_result_32=compare_value("is not",compare_30,compare_31);return comparison_result_32;}()).truth()){
        // Carlotta.py:32
        return ([&]()->V{auto fn_34=attr(self_value(),"do_perform_interlock");Args args_33;return invoke(fn_34,args_33);}());
    }
    // Carlotta.py:33
    {V value_35=V(0LL);set_attr(self_value(),"bullet",value_35);}
    // Carlotta.py:34
    if(attr(self_value(),"has_intro").truth()){
        // Carlotta.py:35
        ([&]()->V{auto fn_37=attr(attr(self_value(),"logger"),"debug");Args args_36;args_36.pos(V("has_intro wait click 1.3 sec"));return invoke(fn_37,args_36);}());
        // Carlotta.py:36
        {V value_38=V(1LL);set_attr(self_value(),"bullet",value_38);}
        // Carlotta.py:37
        ([&]()->V{auto fn_40=attr(self_value(),"continues_normal_attack");Args args_39;args_39.pos(V(1.3));return invoke(fn_40,args_39);}());
    }
    // Carlotta.py:38
    if(([&]()->V{auto fn_42=attr(self_value(),"heavy_click_forte");Args args_41;args_41.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_42,args_41);}()).truth()){
        // Carlotta.py:39
        return ([&]()->V{auto fn_44=attr(self_value(),"switch_next_char");Args args_43;return invoke(fn_44,args_43);}());
    }
    // Carlotta.py:40
    if(([&]()->V{V operand_45;operand_45=([&]()->V{auto fn_47=attr(self_value(),"liberation_available");Args args_46;return invoke(fn_47,args_46);}());if(!operand_45.truth())return operand_45;return unary("not",([&]()->V{auto fn_49=attr(self_value(),"need_fast_perform");Args args_48;return invoke(fn_49,args_48);}()));}()).truth()){
        // Carlotta.py:41
        {V value_50=unary("-",V(1LL));scope_24->set("auto_dodge",value_50);}
        // Carlotta.py:42
                while(([&]()->V{auto fn_74=attr(self_value(),"liberation_available");Args args_73;return invoke(fn_74,args_73);}()).truth()){
            // Carlotta.py:43
            if(([&]()->V{V operand_51;operand_51=([&]()->V{V compare_52=scope_24->get("auto_dodge");V compare_53;V comparison_result_54;compare_53=unary("-",V(1LL));comparison_result_54=compare_value("!=",compare_52,compare_53);return comparison_result_54;}());if(!operand_51.truth())return operand_51;operand_51=([&]()->V{V compare_55=([&]()->V{V left_57=([&]()->V{auto fn_60=attr(global("time","Carlotta"),"time");Args args_59;return invoke(fn_60,args_59);}());V right_58=scope_24->get("auto_dodge");return official::binary("-",left_57,right_58);}());V compare_56;V comparison_result_61;compare_56=V(0.5);comparison_result_61=compare_value(">",compare_55,compare_56);return comparison_result_61;}());if(!operand_51.truth())return operand_51;return ([&]()->V{auto fn_63=attr(self_value(),"flying");Args args_62;return invoke(fn_63,args_62);}());}()).truth()){
                // Carlotta.py:44
                ([&]()->V{auto fn_65=attr(self_value(),"shorekeeper_auto_dodge");Args args_64;return invoke(fn_65,args_64);}());
            }
            // Carlotta.py:45
            if(([&]()->V{auto fn_67=attr(self_value(),"click_liberation_1");Args args_66;return invoke(fn_67,args_66);}()).truth()){
                // Carlotta.py:46
                {V value_68=([&]()->V{auto fn_70=attr(global("time","Carlotta"),"time");Args args_69;return invoke(fn_70,args_69);}());scope_24->set("auto_dodge",value_68);}
            }
            // Carlotta.py:47
            ([&]()->V{auto fn_72=attr(self_value(),"check_combat");Args args_71;return invoke(fn_72,args_71);}());
        }
        // Carlotta.py:48
        ([&]()->V{auto fn_76=attr(self_value(),"click_echo");Args args_75;return invoke(fn_76,args_75);}());
        // Carlotta.py:49
        {V value_77=([&]()->V{auto fn_79=attr(global("time","Carlotta"),"time");Args args_78;return invoke(fn_79,args_78);}());set_attr(self_value(),"switch_lock",value_77);}
        // Carlotta.py:50
        return ([&]()->V{auto fn_81=attr(self_value(),"switch_next_char");Args args_80;return invoke(fn_81,args_80);}());
    }
    // Carlotta.py:51
    if(([&]()->V{auto fn_83=attr(self_value(),"resonance_available");Args args_82;return invoke(fn_83,args_82);}()).truth()){
        // Carlotta.py:52
        if(([&]()->V{V compare_84=attr(self_value(),"bullet");V compare_85;V comparison_result_86;compare_85=V(0LL);comparison_result_86=compare_value("==",compare_84,compare_85);return comparison_result_86;}()).truth()){
            // Carlotta.py:53
            ([&]()->V{auto fn_88=attr(self_value(),"heavy_attack");Args args_87;return invoke(fn_88,args_87);}());
        }
        // Carlotta.py:54
        if(item(([&]()->V{auto fn_90=attr(self_value(),"click_resonance");Args args_89;return invoke(fn_90,args_89);}()),V(0LL)).truth()){
            // Carlotta.py:55
            return ([&]()->V{auto fn_92=attr(self_value(),"switch_next_char");Args args_91;return invoke(fn_92,args_91);}());
        }
    }
    // Carlotta.py:56
    if(([&]()->V{auto fn_94=attr(self_value(),"click_echo");Args args_93;return invoke(fn_94,args_93);}()).truth()){
        // Carlotta.py:57
        return ([&]()->V{auto fn_96=attr(self_value(),"switch_next_char");Args args_95;return invoke(fn_96,args_95);}());
    }
    // Carlotta.py:58
    ([&]()->V{auto fn_98=attr(self_value(),"continues_normal_attack");Args args_97;args_97.pos(V(0.31));return invoke(fn_98,args_97);}());
    // Carlotta.py:59
    ([&]()->V{auto fn_100=attr(self_value(),"switch_next_char");Args args_99;return invoke(fn_100,args_99);}());
return V{};
}),false);
// Official method Carlotta.click_liberation_1, lines 61-68
register_method("click_liberation_1",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_101=bind_arguments(official_args,signature,captured);
scope_101->set("click",V::missing());
    // Carlotta.py:62
    if(([&]()->V{V compare_102=attr(self_value(),"press_w");V compare_103;V comparison_result_104;compare_103=V(1LL);comparison_result_104=compare_value("==",compare_102,compare_103);return comparison_result_104;}()).truth()){
        // Carlotta.py:63
        ([&]()->V{auto fn_106=attr(attr(self_value(),"task"),"send_key_down");Args args_105;args_105.kw("key",V("w"));return invoke(fn_106,args_105);}());
        // Carlotta.py:64
        {V value_107=([&]()->V{auto fn_109=attr(self_value(),"click_liberation");Args args_108;return invoke(fn_109,args_108);}());scope_101->set("click",value_107);}
        // Carlotta.py:65
        ([&]()->V{auto fn_111=attr(attr(self_value(),"task"),"send_key_up");Args args_110;args_110.kw("key",V("w"));return invoke(fn_111,args_110);}());
        // Carlotta.py:66
        return scope_101->get("click");
    }else{
        // Carlotta.py:68
        return ([&]()->V{auto fn_113=attr(self_value(),"click_liberation");Args args_112;return invoke(fn_113,args_112);}());
    }
return V{};
}),false);
// Official method Carlotta.click_liberation, lines 70-120
register_method("click_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_less_than",unary("-",V(1LL))},{"send_click",V(false)},{"wait_if_cd_ready",V(0.1)},{"animation_min_duration",V(0LL)},{"click_f",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_114=bind_arguments(official_args,signature,captured);
scope_114->set("clicked",V::missing());
scope_114->set("duration",V::missing());
scope_114->set("last_click",V::missing());
scope_114->set("last_f_click",V::missing());
scope_114->set("now",V::missing());
scope_114->set("start",V::missing());
    // Carlotta.py:72
    ([&]()->V{auto fn_116=attr(attr(self_value(),"logger"),"debug");Args args_115;args_115.pos(V("click_liberation start"));return invoke(fn_116,args_115);}());
    // Carlotta.py:73
    {V value_117=([&]()->V{auto fn_119=attr(global("time","Carlotta"),"time");Args args_118;return invoke(fn_119,args_118);}());scope_114->set("start",value_117);}
    // Carlotta.py:74
    {V value_120=V(0LL);scope_114->set("last_click",value_120);}
    // Carlotta.py:75
    {V value_121=V(false);scope_114->set("clicked",value_121);}
    // Carlotta.py:76
        while(([&]()->V{auto fn_146=attr(self_value(),"liberation_available");Args args_145;return invoke(fn_146,args_145);}()).truth()){
        // Carlotta.py:77
        ([&]()->V{auto fn_123=attr(attr(self_value(),"logger"),"debug");Args args_122;args_122.pos(V("click_liberation liberation_available click"));return invoke(fn_123,args_122);}());
        // Carlotta.py:78
        {V value_124=([&]()->V{auto fn_126=attr(global("time","Carlotta"),"time");Args args_125;return invoke(fn_126,args_125);}());scope_114->set("now",value_124);}
        // Carlotta.py:79
        if(([&]()->V{V compare_127=([&]()->V{V left_129=scope_114->get("now");V right_130=scope_114->get("last_click");return official::binary("-",left_129,right_130);}());V compare_128;V comparison_result_131;compare_128=V(0.1);comparison_result_131=compare_value(">",compare_127,compare_128);return comparison_result_131;}()).truth()){
            // Carlotta.py:80
            ([&]()->V{auto fn_133=attr(self_value(),"send_liberation_key");Args args_132;return invoke(fn_133,args_132);}());
            // Carlotta.py:81
            if(unary("not",scope_114->get("clicked")).truth()){
                // Carlotta.py:82
                {V value_134=V(true);scope_114->set("clicked",value_134);}
            }
            // Carlotta.py:83
            {V value_135=scope_114->get("now");scope_114->set("last_click",value_135);}
        }
        // Carlotta.py:84
        if(([&]()->V{V compare_136=([&]()->V{V left_138=([&]()->V{auto fn_141=attr(global("time","Carlotta"),"time");Args args_140;return invoke(fn_141,args_140);}());V right_139=scope_114->get("start");return official::binary("-",left_138,right_139);}());V compare_137;V comparison_result_142;compare_137=V(0.4);comparison_result_142=compare_value(">",compare_136,compare_137);return comparison_result_142;}()).truth()){
            // Carlotta.py:85
            return V(false);
        }
        // Carlotta.py:86
        ([&]()->V{auto fn_144=attr(attr(self_value(),"task"),"next_frame");Args args_143;return invoke(fn_144,args_143);}());
    }
    // Carlotta.py:87
    if(scope_114->get("clicked").truth()){
        // Carlotta.py:88
        if(([&]()->V{auto fn_148=attr(attr(self_value(),"task"),"wait_until");Args args_147;args_147.pos(V::function([this,captured=capture_scope(scope_114,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
return unary("not",item(([&]()->V{auto fn_151=attr(attr(self_value(),"task"),"in_team");Args args_150;return invoke(fn_151,args_150);}()),V(0LL)));
}));args_147.kw("time_out",V(0.4));args_147.kw("post_action",attr(self_value(),"click_with_interval"));return invoke(fn_148,args_147);}()).truth()){
            // Carlotta.py:90
            {V value_152=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_152);}
            // Carlotta.py:91
            ([&]()->V{auto fn_154=attr(attr(self_value(),"logger"),"debug");Args args_153;args_153.pos(V("not in_team successfully casted liberation"));return invoke(fn_154,args_153);}());
        }else{
            // Carlotta.py:93
            {V value_155=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_155);}
            // Carlotta.py:94
            ([&]()->V{auto fn_157=attr(attr(self_value(),"logger"),"error");Args args_156;args_156.pos(V("clicked liberation but no effect"));return invoke(fn_157,args_156);}());
            // Carlotta.py:95
            return V(false);
        }
    }else{
        // Carlotta.py:97
        return scope_114->get("clicked");
    }
    // Carlotta.py:98
    {V value_158=([&]()->V{auto fn_160=attr(global("time","Carlotta"),"time");Args args_159;return invoke(fn_160,args_159);}());scope_114->set("start",value_158);}
    // Carlotta.py:99
    {V value_161=V(0LL);scope_114->set("last_f_click",value_161);}
    // Carlotta.py:100
        while(unary("not",item(([&]()->V{auto fn_192=attr(attr(self_value(),"task"),"in_team");Args args_191;return invoke(fn_192,args_191);}()),V(0LL))).truth()){
        // Carlotta.py:101
        {V value_162=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_162);}
        // Carlotta.py:102
        if(unary("not",scope_114->get("clicked")).truth()){
            // Carlotta.py:103
            {V value_163=V(true);scope_114->set("clicked",value_163);}
        }
        // Carlotta.py:104
        {V value_164=([&]()->V{auto fn_166=attr(global("time","Carlotta"),"time");Args args_165;return invoke(fn_166,args_165);}());scope_114->set("now",value_164);}
        // Carlotta.py:105
        if(([&]()->V{V operand_167;operand_167=scope_114->get("click_f");if(!operand_167.truth())return operand_167;operand_167=([&]()->V{V compare_168=([&]()->V{V left_170=scope_114->get("now");V right_171=scope_114->get("start");return official::binary("-",left_170,right_171);}());V compare_169;V comparison_result_172;compare_169=scope_114->get("animation_min_duration");comparison_result_172=compare_value(">=",compare_168,compare_169);return comparison_result_172;}());if(!operand_167.truth())return operand_167;return ([&]()->V{V compare_173=([&]()->V{V left_175=scope_114->get("now");V right_176=scope_114->get("last_f_click");return official::binary("-",left_175,right_176);}());V compare_174;V comparison_result_177;compare_174=V(0.1);comparison_result_177=compare_value(">=",compare_173,compare_174);return comparison_result_177;}());}()).truth()){
            // Carlotta.py:107
            ([&]()->V{auto fn_179=attr(attr(self_value(),"task"),"send_key");Args args_178;args_178.pos(V("f"));return invoke(fn_179,args_178);}());
            // Carlotta.py:108
            {V value_180=scope_114->get("now");scope_114->set("last_f_click",value_180);}
        }
        // Carlotta.py:109
        if(([&]()->V{V compare_181=([&]()->V{V left_183=scope_114->get("now");V right_184=scope_114->get("start");return official::binary("-",left_183,right_184);}());V compare_182;V comparison_result_185;compare_182=V(7LL);comparison_result_185=compare_value(">",compare_181,compare_182);return comparison_result_185;}()).truth()){
            // Carlotta.py:110
            {V value_186=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_186);}
            // Carlotta.py:111
            ([&]()->V{auto fn_188=attr(attr(self_value(),"task"),"raise_not_in_combat");Args args_187;args_187.pos(V("too long a liberation, the boss was killed by the liberation"));return invoke(fn_188,args_187);}());
        }
        // Carlotta.py:112
        ([&]()->V{auto fn_190=attr(attr(self_value(),"task"),"next_frame");Args args_189;return invoke(fn_190,args_189);}());
    }
    // Carlotta.py:113
    {V value_193=([&]()->V{V left_194=([&]()->V{auto fn_197=attr(global("time","Carlotta"),"time");Args args_196;return invoke(fn_197,args_196);}());V right_195=scope_114->get("start");return official::binary("-",left_194,right_195);}());scope_114->set("duration",value_193);}
    // Carlotta.py:114
    ([&]()->V{auto fn_199=attr(self_value(),"add_freeze_duration");Args args_198;args_198.pos(scope_114->get("start"));args_198.pos(scope_114->get("duration"));return invoke(fn_199,args_198);}());
    // Carlotta.py:115
    ([&]()->V{auto fn_201=attr(self_value(),"record_liberation_use");Args args_200;return invoke(fn_201,args_200);}());
    // Carlotta.py:116
    {V value_202=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_202);}
    // Carlotta.py:117
    {V value_203=V(false);set_attr(self_value(),"_liberation_available",value_203);}
    // Carlotta.py:118
    if(scope_114->get("clicked").truth()){
        // Carlotta.py:119
        ([&]()->V{auto fn_205=attr(attr(self_value(),"logger"),"info");Args args_204;args_204.pos(V(std::string{}+"click_liberation end "+format_value(scope_114->get("duration"),"",-1)));return invoke(fn_205,args_204);}());
    }
    // Carlotta.py:120
    return scope_114->get("clicked");
return V{};
}),false);
// Official method Carlotta.click_resonance, lines 122-167
register_method("click_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"post_sleep",V(0LL)},{"has_animation",V(false)},{"send_click",V(true)},{"animation_min_duration",V(0LL)},{"check_cd",V(false)},{"time_out",V(0LL)}},"","",{})](const Args& official_args)->V{
auto scope_206=bind_arguments(official_args,signature,captured);
scope_206->set("animated",V::missing());
scope_206->set("clicked",V::missing());
scope_206->set("current_resonance",V::missing());
scope_206->set("duration",V::missing());
scope_206->set("last",V::missing());
scope_206->set("last_click",V::missing());
scope_206->set("last_op",V::missing());
scope_206->set("now",V::missing());
scope_206->set("resonance_click_time",V::missing());
scope_206->set("start",V::missing());
    // Carlotta.py:124
    {V value_207=V(false);scope_206->set("clicked",value_207);}
    // Carlotta.py:125
    ([&]()->V{auto fn_209=attr(attr(self_value(),"logger"),"debug");Args args_208;args_208.pos(V(std::string{}+"click_resonance start"));return invoke(fn_209,args_208);}());
    // Carlotta.py:126
    {V value_210=V(0LL);scope_206->set("last_click",value_210);}
    // Carlotta.py:127
    {V value_211=V("click");scope_206->set("last_op",value_211);}
    // Carlotta.py:128
    {V value_212=V(0LL);scope_206->set("resonance_click_time",value_212);}
    // Carlotta.py:129
    {V value_213=V(false);scope_206->set("animated",value_213);}
    // Carlotta.py:130
    {V value_214=([&]()->V{auto fn_216=attr(global("time","Carlotta"),"time");Args args_215;return invoke(fn_216,args_215);}());scope_206->set("start",value_214);}
    // Carlotta.py:131
    {V value_217=scope_206->get("start");scope_206->set("last",value_217);}
    // Carlotta.py:132
        while(V(true).truth()){
        // Carlotta.py:133
        if(([&]()->V{V compare_218=([&]()->V{V left_220=([&]()->V{auto fn_223=attr(global("time","Carlotta"),"time");Args args_222;return invoke(fn_223,args_222);}());V right_221=scope_206->get("start");return official::binary("-",left_220,right_221);}());V compare_219;V comparison_result_224;compare_219=([&]()->V{V operand_225;operand_225=scope_206->get("time_out");if(operand_225.truth())return operand_225;return V(10LL);}());comparison_result_224=compare_value(">",compare_218,compare_219);return comparison_result_224;}()).truth()){
            // Carlotta.py:134
            {V value_226=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_226);}
            // Carlotta.py:135
            ([&]()->V{auto fn_228=attr(self_value(),"alert_skill_failed");Args args_227;return invoke(fn_228,args_227);}());
            // Carlotta.py:136
            break;
        }
        // Carlotta.py:137
        ([&]()->V{auto fn_230=attr(self_value(),"check_combat");Args args_229;return invoke(fn_230,args_229);}());
        // Carlotta.py:138
        {V value_231=([&]()->V{auto fn_233=attr(global("time","Carlotta"),"time");Args args_232;return invoke(fn_233,args_232);}());scope_206->set("now",value_231);}
        // Carlotta.py:139
        {V value_234=([&]()->V{auto fn_236=attr(self_value(),"current_resonance");Args args_235;return invoke(fn_236,args_235);}());scope_206->set("current_resonance",value_234);}
        // Carlotta.py:140
        ([&]()->V{auto fn_238=attr(attr(self_value(),"logger"),"debug");Args args_237;args_237.pos(V(std::string{}+"click_resonance break percent "+format_value(scope_206->get("current_resonance"),"",-1)));return invoke(fn_238,args_237);}());
        // Carlotta.py:141
        if(([&]()->V{auto fn_240=attr(self_value(),"has_cd");Args args_239;args_239.pos(V("resonance"));return invoke(fn_240,args_239);}()).truth()){
            // Carlotta.py:142
            ([&]()->V{auto fn_242=attr(attr(self_value(),"logger"),"debug");Args args_241;args_241.pos(V(std::string{}+"click_resonance not available break"));return invoke(fn_242,args_241);}());
            // Carlotta.py:143
            break;
        }
        // Carlotta.py:144
        ([&]()->V{auto fn_244=attr(attr(self_value(),"logger"),"debug");Args args_243;args_243.pos(V(std::string{}+"click_resonance resonance_available click "+format_value(scope_206->get("current_resonance"),"",-1)));return invoke(fn_244,args_243);}());
        // Carlotta.py:146
        if(([&]()->V{V compare_245=([&]()->V{V left_247=scope_206->get("now");V right_248=scope_206->get("last_click");return official::binary("-",left_247,right_248);}());V compare_246;V comparison_result_249;compare_246=V(0.1);comparison_result_249=compare_value(">",compare_245,compare_246);return comparison_result_249;}()).truth()){
            // Carlotta.py:147
            if(([&]()->V{V operand_250;operand_250=scope_206->get("send_click");if(!operand_250.truth())return operand_250;return ([&]()->V{V operand_251;operand_251=([&]()->V{V compare_252=scope_206->get("current_resonance");V compare_253;V comparison_result_254;compare_253=V(0LL);comparison_result_254=compare_value("==",compare_252,compare_253);return comparison_result_254;}());if(operand_251.truth())return operand_251;return ([&]()->V{V compare_255=scope_206->get("last_op");V compare_256;V comparison_result_257;compare_256=V("resonance");comparison_result_257=compare_value("==",compare_255,compare_256);return comparison_result_257;}());}());}()).truth()){
                // Carlotta.py:148
                ([&]()->V{auto fn_259=attr(attr(self_value(),"task"),"click");Args args_258;return invoke(fn_259,args_258);}());
                // Carlotta.py:149
                {V value_260=V("click");scope_206->set("last_op",value_260);}
                // Carlotta.py:150
                continue;
            }
            // Carlotta.py:151
            if(([&]()->V{V operand_261;operand_261=([&]()->V{V compare_262=scope_206->get("current_resonance");V compare_263;V comparison_result_264;compare_263=V(0LL);comparison_result_264=compare_value(">",compare_262,compare_263);return comparison_result_264;}());if(!operand_261.truth())return operand_261;return ([&]()->V{auto fn_266=attr(self_value(),"resonance_available");Args args_265;return invoke(fn_266,args_265);}());}()).truth()){
                // Carlotta.py:152
                if(([&]()->V{V compare_267=scope_206->get("resonance_click_time");V compare_268;V comparison_result_269;compare_268=V(0LL);comparison_result_269=compare_value("==",compare_267,compare_268);return comparison_result_269;}()).truth()){
                    // Carlotta.py:153
                    {V value_270=V(true);scope_206->set("clicked",value_270);}
                    // Carlotta.py:154
                    {V value_271=scope_206->get("now");scope_206->set("resonance_click_time",value_271);}
                    // Carlotta.py:155
                    ([&]()->V{auto fn_273=attr(self_value(),"record_resonance_use");Args args_272;return invoke(fn_273,args_272);}());
                }
                // Carlotta.py:156
                {V value_274=V("resonance");scope_206->set("last_op",value_274);}
                // Carlotta.py:157
                ([&]()->V{auto fn_276=attr(self_value(),"send_resonance_key");Args args_275;return invoke(fn_276,args_275);}());
                // Carlotta.py:158
                if(scope_206->get("has_animation").truth()){
                    // Carlotta.py:159
                    ([&]()->V{auto fn_278=attr(self_value(),"sleep");Args args_277;args_277.pos(V(0.2));args_277.kw("check_combat",V(false));return invoke(fn_278,args_277);}());
                }
            }
            // Carlotta.py:160
            {V value_279=scope_206->get("now");scope_206->set("last_click",value_279);}
        }
        // Carlotta.py:161
        ([&]()->V{auto fn_281=attr(attr(self_value(),"task"),"next_frame");Args args_280;return invoke(fn_281,args_280);}());
    }
    // Carlotta.py:162
    {V value_282=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_282);}
    // Carlotta.py:163
    if(scope_206->get("clicked").truth()){
        // Carlotta.py:164
        ([&]()->V{auto fn_284=attr(self_value(),"sleep");Args args_283;args_283.pos(scope_206->get("post_sleep"));return invoke(fn_284,args_283);}());
    }
    // Carlotta.py:165
    {V value_285=(([&]()->V{V compare_286=scope_206->get("resonance_click_time");V compare_287;V comparison_result_288;compare_287=V(0LL);comparison_result_288=compare_value("!=",compare_286,compare_287);return comparison_result_288;}()).truth()?([&]()->V{V left_289=([&]()->V{auto fn_292=attr(global("time","Carlotta"),"time");Args args_291;return invoke(fn_292,args_291);}());V right_290=scope_206->get("resonance_click_time");return official::binary("-",left_289,right_290);}()):V(0LL));scope_206->set("duration",value_285);}
    // Carlotta.py:166
    ([&]()->V{auto fn_294=attr(attr(self_value(),"logger"),"debug");Args args_293;args_293.pos(V(std::string{}+"click_resonance end clicked "+format_value(scope_206->get("clicked"),"",-1)+" duration "+format_value(scope_206->get("duration"),"",-1)+" animated "+format_value(scope_206->get("animated"),"",-1)));return invoke(fn_294,args_293);}());
    // Carlotta.py:167
    return V::tuple({scope_206->get("clicked"),scope_206->get("duration"),scope_206->get("animated")});
return V{};
}),false);
// Official method Carlotta.echo_available, lines 169-173
register_method("echo_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_295=bind_arguments(official_args,signature,captured);
    // Carlotta.py:170
    if(attr(self_value(),"is_current_char").truth()){
        // Carlotta.py:171
        return unary("not",([&]()->V{auto fn_297=attr(self_value(),"has_cd");Args args_296;args_296.pos(V("echo"));return invoke(fn_297,args_296);}()));
    }else{
        // Carlotta.py:173
        return unary("not",([&]()->V{auto fn_299=attr(attr(self_value(),"task"),"has_cd");Args args_298;args_298.pos(V("echo"));args_298.pos(attr(self_value(),"index"));return invoke(fn_299,args_298);}()));
    }
return V{};
}),false);
// Official method Carlotta.get_switch_priority, lines 175-180
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_300=bind_arguments(official_args,signature,captured);
    // Carlotta.py:176
    if(([&]()->V{V compare_301=attr(self_value(),"press_w");V compare_302;V comparison_result_303;compare_302=unary("-",V(1LL));comparison_result_303=compare_value("==",compare_301,compare_302);return comparison_result_303;}()).truth()){
        // Carlotta.py:177
        ([&]()->V{auto fn_305=attr(self_value(),"decide_teammate");Args args_304;return invoke(fn_305,args_304);}());
    }
    // Carlotta.py:178
    if(([&]()->V{V operand_306;operand_306=scope_300->get("has_intro");if(!operand_306.truth())return operand_306;operand_306=scope_300->get("current_char");if(!operand_306.truth())return operand_306;return ([&]()->V{V compare_307=attr(scope_300->get("current_char"),"char_name");V compare_308;V comparison_result_309;compare_308=V::set({V("char_zhezhi")});comparison_result_309=compare_value("in",compare_307,compare_308);return comparison_result_309;}());}()).truth()){
        // Carlotta.py:179
        return attr(global("SwitchPriority","Carlotta"),"MUST");
    }
    // Carlotta.py:180
    return ([&]()->V{auto fn_313=attr(([&]()->V{auto fn_311=global("super","Carlotta");Args args_310;return invoke(fn_311,args_310);}()),"get_switch_priority");Args args_312;args_312.pos(scope_300->get("current_char"));args_312.pos(scope_300->get("has_intro"));args_312.pos(scope_300->get("target_low_con"));return invoke(fn_313,args_312);}());
return V{};
}),false);
// Official method Carlotta.decide_teammate, lines 182-189
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_314=bind_arguments(official_args,signature,captured);
scope_314->set("Zhezhi",V::missing());
scope_314->set("char",V::missing());
    // Carlotta.py:183
    scope_314->set("Zhezhi",import_value("src.char.Zhezhi","Zhezhi"));
    // Carlotta.py:184
    {V value_315=V(0LL);set_attr(self_value(),"press_w",value_315);}
    // Carlotta.py:185
    if(([&]()->V{V operand_316;operand_316=attr(attr(self_value(),"task"),"name");if(!operand_316.truth())return operand_316;return ([&]()->V{V compare_317=attr(attr(self_value(),"task"),"name");V compare_318;V comparison_result_319;compare_318=V("🌀 Farm 4C Echo in Dungeon/World");comparison_result_319=compare_value("==",compare_317,compare_318);return comparison_result_319;}());}()).truth()){
        // Carlotta.py:186
        {V value_320=V(1LL);set_attr(self_value(),"press_w",value_320);}
    }else{
        // Carlotta.py:187
        if(([&]()->V{V assigned_321=([&]()->V{auto fn_323=attr(attr(self_value(),"task"),"has_char");Args args_322;args_322.pos(scope_314->get("Zhezhi"));return invoke(fn_323,args_322);}());scope_314->set("char",assigned_321);return assigned_321;}()).truth()){
            // Carlotta.py:188
            {V value_324=scope_314->get("char");set_attr(self_value(),"char_zhezhi",value_324);}
            // Carlotta.py:189
            {V value_325=self_value();set_attr(attr(self_value(),"char_zhezhi"),"char_carlotta",value_325);}
        }
    }
return V{};
}),false);
// Official method Carlotta.get_forte, lines 191-196
register_method("get_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_326=bind_arguments(official_args,signature,captured);
scope_326->set("box",V::missing());
    // Carlotta.py:192
    if(([&]()->V{auto fn_328=attr(self_value(),"is_mouse_forte_full");Args args_327;return invoke(fn_328,args_327);}()).truth()){
        // Carlotta.py:193
        return V(4LL);
    }
    // Carlotta.py:194
    {V value_329=([&]()->V{auto fn_331=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_330;args_330.pos(V(5120LL));args_330.pos(V(2880LL));args_330.pos(V(2164LL));args_330.pos(V(2670LL));args_330.pos(V(2900LL));args_330.pos(V(2680LL));args_330.kw("name",V("carlotta_forte"));args_330.kw("hcenter",V(true));return invoke(fn_331,args_330);}());scope_326->set("box",value_329);}
    // Carlotta.py:195
    {V value_332=([&]()->V{auto fn_334=attr(self_value(),"calculate_forte_num");Args args_333;args_333.pos(global("carlotta_forte_color","Carlotta"));args_333.pos(scope_326->get("box"));args_333.pos(V(4LL));args_333.pos(V(9LL));args_333.pos(V(11LL));args_333.pos(V(100LL));return invoke(fn_334,args_333);}());set_attr(self_value(),"forte",value_332);}
    // Carlotta.py:196
    return attr(self_value(),"forte");
return V{};
}),false);
// Official method Carlotta.get_ready, lines 198-200
register_method("get_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_335=bind_arguments(official_args,signature,captured);
    // Carlotta.py:199
    ([&]()->V{auto fn_337=attr(attr(self_value(),"logger"),"debug");Args args_336;args_336.pos(V(std::string{}+"carlotta_state :"+format_value(attr(self_value(),"forte"),"",-1)+","+format_value(([&]()->V{auto fn_339=attr(self_value(),"resonance_available");Args args_338;return invoke(fn_339,args_338);}()),"",-1)));return invoke(fn_337,args_336);}());
    // Carlotta.py:200
    return ([&]()->V{V operand_340;operand_340=([&]()->V{V compare_341=attr(self_value(),"forte");V compare_342;V comparison_result_343;compare_342=V(2LL);comparison_result_343=compare_value(">",compare_341,compare_342);return comparison_result_343;}());if(operand_340.truth())return operand_340;operand_340=([&]()->V{V operand_344;operand_344=([&]()->V{auto fn_346=attr(self_value(),"resonance_available");Args args_345;return invoke(fn_346,args_345);}());if(!operand_344.truth())return operand_344;return ([&]()->V{V compare_347=attr(self_value(),"forte");V compare_348;V comparison_result_349;compare_348=V(0LL);comparison_result_349=compare_value(">",compare_347,compare_348);return comparison_result_349;}());}());if(operand_340.truth())return operand_340;return attr(self_value(),"liberation_ready");}());
return V{};
}),false);
// Official method Carlotta.do_perform_interlock, lines 202-235
register_method("do_perform_interlock",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_350=bind_arguments(official_args,signature,captured);
scope_350->set("auto_dodge",V::missing());
    // Carlotta.py:203
    {V value_351=V(0LL);set_attr(self_value(),"bullet",value_351);}
    // Carlotta.py:204
    if(attr(self_value(),"has_intro").truth()){
        // Carlotta.py:205
        {V value_352=V(1LL);set_attr(self_value(),"bullet",value_352);}
        // Carlotta.py:206
        ([&]()->V{auto fn_354=attr(self_value(),"continues_normal_attack");Args args_353;args_353.pos(V(1.3));return invoke(fn_354,args_353);}());
        // Carlotta.py:207
        if(([&]()->V{V compare_355=([&]()->V{auto fn_358=attr(self_value(),"check_outro");Args args_357;return invoke(fn_358,args_357);}());V compare_356;V comparison_result_359;compare_356=V::set({V("char_zhezhi")});comparison_result_359=compare_value("in",compare_355,compare_356);return comparison_result_359;}()).truth()){
            // Carlotta.py:208
            ([&]()->V{auto fn_361=attr(self_value(),"do_perform_outro");Args args_360;return invoke(fn_361,args_360);}());
            // Carlotta.py:209
            return ([&]()->V{auto fn_363=attr(self_value(),"switch_next_char");Args args_362;return invoke(fn_363,args_362);}());
        }
    }
    // Carlotta.py:210
    if(([&]()->V{V operand_364;operand_364=([&]()->V{V compare_365=([&]()->V{auto fn_368=attr(self_value(),"get_forte");Args args_367;return invoke(fn_368,args_367);}());V compare_366;V comparison_result_369;compare_366=V(4LL);comparison_result_369=compare_value("<",compare_365,compare_366);return comparison_result_369;}());if(!operand_364.truth())return operand_364;operand_364=([&]()->V{auto fn_371=attr(self_value(),"resonance_available");Args args_370;return invoke(fn_371,args_370);}());if(!operand_364.truth())return operand_364;return unary("not",attr(self_value(),"liberation_ready"));}()).truth()){
        // Carlotta.py:211
        if(([&]()->V{V compare_372=attr(self_value(),"bullet");V compare_373;V comparison_result_374;compare_373=V(0LL);comparison_result_374=compare_value("==",compare_372,compare_373);return comparison_result_374;}()).truth()){
            // Carlotta.py:212
            ([&]()->V{auto fn_376=attr(self_value(),"heavy_attack");Args args_375;return invoke(fn_376,args_375);}());
        }
        // Carlotta.py:213
        if(item(([&]()->V{auto fn_378=attr(self_value(),"click_resonance");Args args_377;return invoke(fn_378,args_377);}()),V(0LL)).truth()){
            // Carlotta.py:214
            set_attr(self_value(),"forte",official::binary("+",attr(self_value(),"forte"),V(2LL)));
            // Carlotta.py:215
            {V value_379=([&]()->V{auto fn_381=attr(global("time","Carlotta"),"time");Args args_380;return invoke(fn_381,args_380);}());set_attr(self_value(),"switch_lock",value_379);}
            // Carlotta.py:216
            return ([&]()->V{auto fn_383=attr(self_value(),"switch_next_char");Args args_382;return invoke(fn_383,args_382);}());
        }
    }
    // Carlotta.py:217
    if(([&]()->V{auto fn_385=attr(self_value(),"get_ready");Args args_384;return invoke(fn_385,args_384);}()).truth()){
        // Carlotta.py:218
        {V value_386=V(false);set_attr(self_value(),"continue_liberation",value_386);}
    }
    // Carlotta.py:219
    if(([&]()->V{auto fn_388=attr(self_value(),"heavy_click_forte");Args args_387;args_387.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_388,args_387);}()).truth()){
        // Carlotta.py:220
        {V value_389=V(true);set_attr(self_value(),"liberation_ready",value_389);}
        // Carlotta.py:221
        return ([&]()->V{auto fn_391=attr(self_value(),"switch_next_char");Args args_390;return invoke(fn_391,args_390);}());
    }
    // Carlotta.py:222
    if(([&]()->V{V operand_392;operand_392=([&]()->V{auto fn_394=attr(self_value(),"liberation_available");Args args_393;return invoke(fn_394,args_393);}());if(!operand_392.truth())return operand_392;return attr(self_value(),"continue_liberation");}()).truth()){
        // Carlotta.py:223
        {V value_395=unary("-",V(1LL));scope_350->set("auto_dodge",value_395);}
        // Carlotta.py:224
                while(([&]()->V{auto fn_421=attr(self_value(),"liberation_available");Args args_420;return invoke(fn_421,args_420);}()).truth()){
            // Carlotta.py:225
            if(([&]()->V{V operand_396;operand_396=([&]()->V{V compare_397=scope_350->get("auto_dodge");V compare_398;V comparison_result_399;compare_398=unary("-",V(1LL));comparison_result_399=compare_value("!=",compare_397,compare_398);return comparison_result_399;}());if(!operand_396.truth())return operand_396;operand_396=([&]()->V{V compare_400=([&]()->V{V left_402=([&]()->V{auto fn_405=attr(global("time","Carlotta"),"time");Args args_404;return invoke(fn_405,args_404);}());V right_403=scope_350->get("auto_dodge");return official::binary("-",left_402,right_403);}());V compare_401;V comparison_result_406;compare_401=V(0.5);comparison_result_406=compare_value(">",compare_400,compare_401);return comparison_result_406;}());if(!operand_396.truth())return operand_396;return ([&]()->V{auto fn_408=attr(self_value(),"flying");Args args_407;return invoke(fn_408,args_407);}());}()).truth()){
                // Carlotta.py:226
                ([&]()->V{auto fn_410=attr(self_value(),"shorekeeper_auto_dodge");Args args_409;return invoke(fn_410,args_409);}());
            }
            // Carlotta.py:227
            if(([&]()->V{auto fn_412=attr(self_value(),"click_liberation");Args args_411;return invoke(fn_412,args_411);}()).truth()){
                // Carlotta.py:228
                {V value_413=([&]()->V{auto fn_415=attr(global("time","Carlotta"),"time");Args args_414;return invoke(fn_415,args_414);}());scope_350->set("auto_dodge",value_413);}
                // Carlotta.py:229
                {V value_416=V(false);set_attr(self_value(),"continue_liberation",value_416);}
                // Carlotta.py:230
                {V value_417=V(false);set_attr(self_value(),"liberation_ready",value_417);}
            }
            // Carlotta.py:231
            ([&]()->V{auto fn_419=attr(self_value(),"check_combat");Args args_418;return invoke(fn_419,args_418);}());
        }
    }
    // Carlotta.py:232
    if(([&]()->V{auto fn_423=attr(self_value(),"echo_available");Args args_422;return invoke(fn_423,args_422);}()).truth()){
        // Carlotta.py:233
        ([&]()->V{auto fn_425=attr(self_value(),"click_echo");Args args_424;return invoke(fn_425,args_424);}());
    }
    // Carlotta.py:234
    ([&]()->V{auto fn_427=attr(self_value(),"continues_normal_attack");Args args_426;args_426.pos(V(0.31));return invoke(fn_427,args_426);}());
    // Carlotta.py:235
    ([&]()->V{auto fn_429=attr(self_value(),"switch_next_char");Args args_428;return invoke(fn_429,args_428);}());
return V{};
}),false);
// Official method Carlotta.do_perform_outro, lines 237-283
register_method("do_perform_outro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_430=bind_arguments(official_args,signature,captured);
scope_430->set("auto_dodge",V::missing());
scope_430->set("click",V::missing());
scope_430->set("liber",V::missing());
scope_430->set("res",V::missing());
    // Carlotta.py:238
    {V value_431=V(true);scope_430->set("res",value_431);}
    // Carlotta.py:239
    {V value_432=V(0LL);set_attr(attr(self_value(),"char_zhezhi"),"forte",value_432);}
    // Carlotta.py:240
    ([&]()->V{auto fn_434=attr(self_value(),"get_forte");Args args_433;return invoke(fn_434,args_433);}());
    // Carlotta.py:241
    if(unary("not",attr(self_value(),"liberation_ready")).truth()){
        // Carlotta.py:242
                while(unary("not",([&]()->V{auto fn_449=attr(self_value(),"is_mouse_forte_full");Args args_448;return invoke(fn_449,args_448);}())).truth()){
            // Carlotta.py:243
            if(([&]()->V{auto fn_436=attr(self_value(),"resonance_available");Args args_435;return invoke(fn_436,args_435);}()).truth()){
                // Carlotta.py:244
                ([&]()->V{auto fn_438=attr(self_value(),"click_resonance");Args args_437;return invoke(fn_438,args_437);}());
            }else{
                // Carlotta.py:246
                ([&]()->V{auto fn_440=attr(self_value(),"click_with_interval");Args args_439;return invoke(fn_440,args_439);}());
            }
            // Carlotta.py:247
            if(([&]()->V{V compare_441=([&]()->V{auto fn_444=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_443;args_443.pos(attr(self_value(),"last_perform"));return invoke(fn_444,args_443);}());V compare_442;V comparison_result_445;compare_442=V(6LL);comparison_result_445=compare_value(">",compare_441,compare_442);return comparison_result_445;}()).truth()){
                // Carlotta.py:248
                break;
            }
            // Carlotta.py:249
            ([&]()->V{auto fn_447=attr(self_value(),"check_combat");Args args_446;return invoke(fn_447,args_446);}());
        }
    }
    // Carlotta.py:250
    if(([&]()->V{auto fn_451=attr(self_value(),"heavy_click_forte");Args args_450;args_450.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_451,args_450);}()).truth()){
        // Carlotta.py:251
        {V value_452=V(true);set_attr(self_value(),"liberation_ready",value_452);}
        // Carlotta.py:252
        {V value_453=V(0LL);set_attr(self_value(),"forte",value_453);}
    }
    // Carlotta.py:253
    ([&]()->V{auto fn_455=attr(self_value(),"check_combat");Args args_454;return invoke(fn_455,args_454);}());
    // Carlotta.py:254
    ([&]()->V{V compare_456=attr(self_value(),"_liberation_available");V compare_457;V comparison_result_458;compare_457=V(false);comparison_result_458=compare_value("==",compare_456,compare_457);return comparison_result_458;}());
    // Carlotta.py:255
    ([&]()->V{V compare_459=attr(self_value(),"_resonance_available");V compare_460;V comparison_result_461;compare_460=V(false);comparison_result_461=compare_value("==",compare_459,compare_460);return comparison_result_461;}());
    // Carlotta.py:256
    {V value_462=V(false);scope_430->set("click",value_462);}
    // Carlotta.py:257
    {V value_463=V(false);scope_430->set("liber",value_463);}
    // Carlotta.py:258
    if(attr(self_value(),"liberation_ready").truth()){
        // Carlotta.py:259
                while(([&]()->V{V compare_511=([&]()->V{auto fn_514=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_513;args_513.pos(attr(self_value(),"last_perform"));return invoke(fn_514,args_513);}());V compare_512;V comparison_result_515;compare_512=V(14LL);comparison_result_515=compare_value("<",compare_511,compare_512);return comparison_result_515;}()).truth()){
            // Carlotta.py:260
            if(([&]()->V{V operand_464;operand_464=([&]()->V{auto fn_466=attr(self_value(),"liberation_available");Args args_465;return invoke(fn_466,args_465);}());if(!operand_464.truth())return operand_464;return unary("not",scope_430->get("liber"));}()).truth()){
                // Carlotta.py:261
                {V value_467=unary("-",V(1LL));scope_430->set("auto_dodge",value_467);}
                // Carlotta.py:262
                                while(([&]()->V{auto fn_494=attr(self_value(),"liberation_available");Args args_493;return invoke(fn_494,args_493);}()).truth()){
                    // Carlotta.py:263
                    if(([&]()->V{V operand_468;operand_468=([&]()->V{V compare_469=scope_430->get("auto_dodge");V compare_470;V comparison_result_471;compare_470=unary("-",V(1LL));comparison_result_471=compare_value("!=",compare_469,compare_470);return comparison_result_471;}());if(!operand_468.truth())return operand_468;operand_468=([&]()->V{V compare_472=([&]()->V{V left_474=([&]()->V{auto fn_477=attr(global("time","Carlotta"),"time");Args args_476;return invoke(fn_477,args_476);}());V right_475=scope_430->get("auto_dodge");return official::binary("-",left_474,right_475);}());V compare_473;V comparison_result_478;compare_473=V(0.5);comparison_result_478=compare_value(">",compare_472,compare_473);return comparison_result_478;}());if(!operand_468.truth())return operand_468;return ([&]()->V{auto fn_480=attr(self_value(),"flying");Args args_479;return invoke(fn_480,args_479);}());}()).truth()){
                        // Carlotta.py:264
                        ([&]()->V{auto fn_482=attr(self_value(),"shorekeeper_auto_dodge");Args args_481;return invoke(fn_482,args_481);}());
                    }
                    // Carlotta.py:265
                    if(([&]()->V{auto fn_484=attr(self_value(),"click_liberation");Args args_483;return invoke(fn_484,args_483);}()).truth()){
                        // Carlotta.py:266
                        {V value_485=V(false);set_attr(self_value(),"liberation_ready",value_485);}
                        // Carlotta.py:267
                        {V value_486=V(true);scope_430->set("liber",value_486);}
                        // Carlotta.py:268
                        {V value_487=V(0LL);set_attr(self_value(),"forte",value_487);}
                        // Carlotta.py:269
                        {V value_488=([&]()->V{auto fn_490=attr(global("time","Carlotta"),"time");Args args_489;return invoke(fn_490,args_489);}());scope_430->set("auto_dodge",value_488);}
                    }
                    // Carlotta.py:270
                    ([&]()->V{auto fn_492=attr(self_value(),"check_combat");Args args_491;return invoke(fn_492,args_491);}());
                }
                // Carlotta.py:271
                if(scope_430->get("liber").truth()){
                    // Carlotta.py:272
                    ([&]()->V{auto fn_496=attr(self_value(),"sleep");Args args_495;args_495.pos(V(0.2));return invoke(fn_496,args_495);}());
                }
            }
            // Carlotta.py:273
            if(item(([&]()->V{auto fn_498=attr(self_value(),"click_resonance");Args args_497;return invoke(fn_498,args_497);}()),V(0LL)).truth()){
                // Carlotta.py:274
                ([&]()->V{auto fn_500=attr(self_value(),"continues_normal_attack");Args args_499;args_499.pos(V(0.8));return invoke(fn_500,args_499);}());
                // Carlotta.py:275
                set_attr(self_value(),"forte",official::binary("+",attr(self_value(),"forte"),V(1LL)));
                // Carlotta.py:276
                {V value_501=V(true);scope_430->set("click",value_501);}
            }
            // Carlotta.py:277
            ([&]()->V{auto fn_503=attr(self_value(),"click_with_interval");Args args_502;args_502.pos(V(0.1));return invoke(fn_503,args_502);}());
            // Carlotta.py:278
            if(([&]()->V{V operand_504;operand_504=unary("not",([&]()->V{auto fn_506=attr(self_value(),"liberation_available");Args args_505;return invoke(fn_506,args_505);}()));if(!operand_504.truth())return operand_504;operand_504=unary("not",([&]()->V{auto fn_508=attr(self_value(),"resonance_available");Args args_507;return invoke(fn_508,args_507);}()));if(!operand_504.truth())return operand_504;return scope_430->get("click");}()).truth()){
                // Carlotta.py:279
                break;
            }
            // Carlotta.py:280
            ([&]()->V{auto fn_510=attr(self_value(),"check_combat");Args args_509;return invoke(fn_510,args_509);}());
        }
    }
    // Carlotta.py:281
    if(([&]()->V{auto fn_517=attr(self_value(),"click_echo");Args args_516;args_516.kw("time_out",V(2LL));return invoke(fn_517,args_516);}()).truth()){
        // Carlotta.py:282
        {V value_518=([&]()->V{auto fn_520=attr(global("time","Carlotta"),"time");Args args_519;return invoke(fn_520,args_519);}());set_attr(self_value(),"switch_lock",value_518);}
    }
    // Carlotta.py:283
    {V value_521=unary("not",scope_430->get("liber"));set_attr(self_value(),"continue_liberation",value_521);}
return V{};
}),false);
// Official method Carlotta.wait_switch, lines 285-288
register_method("wait_switch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_522=bind_arguments(official_args,signature,captured);
    // Carlotta.py:286
    if(([&]()->V{V operand_523;operand_523=attr(self_value(),"has_intro");if(!operand_523.truth())return operand_523;return ([&]()->V{V compare_524=([&]()->V{auto fn_527=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_526;args_526.pos(attr(self_value(),"switch_lock"));args_526.pos(V(true));return invoke(fn_527,args_526);}());V compare_525;V comparison_result_528;compare_525=V(2.5);comparison_result_528=compare_value("<",compare_524,compare_525);return comparison_result_528;}());}()).truth()){
        // Carlotta.py:287
        return V(true);
    }
    // Carlotta.py:288
    return V(false);
return V{};
}),false);
// Official method Carlotta.judge_frequncy_and_amplitude, lines 290-307
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_529=bind_arguments(official_args,signature,captured);
scope_529->set("amplitude",V::missing());
scope_529->set("frequncy",V::missing());
scope_529->set("height",V::missing());
scope_529->set("i",V::missing());
scope_529->set("n",V::missing());
scope_529->set("profile",V::missing());
scope_529->set("width",V::missing());
    // Carlotta.py:291
    {V value_530=item(attr(scope_529->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_531=unpack(value_530,2);scope_529->set("height",unpack_531[0]);scope_529->set("width",unpack_531[1]);}
    // Carlotta.py:292
    if(([&]()->V{V operand_532;operand_532=([&]()->V{V compare_533=scope_529->get("height");V compare_534;V comparison_result_535;compare_534=V(0LL);comparison_result_535=compare_value("==",compare_533,compare_534);return comparison_result_535;}());if(operand_532.truth())return operand_532;operand_532=([&]()->V{V compare_536=scope_529->get("width");V compare_537;V comparison_result_538;compare_537=V(64LL);comparison_result_538=compare_value("<",compare_536,compare_537);return comparison_result_538;}());if(operand_532.truth())return operand_532;return unary("not",([&]()->V{auto fn_540=attr(global("np","Carlotta"),"array_equal");Args args_539;args_539.pos(([&]()->V{auto fn_542=attr(global("np","Carlotta"),"unique");Args args_541;args_541.pos(scope_529->get("gray"));return invoke(fn_542,args_541);}()));args_539.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_540,args_539);}()));}()).truth()){
        // Carlotta.py:293
        return V(0LL);
    }
    // Carlotta.py:295
    {V value_543=([&]()->V{auto fn_550=attr(([&]()->V{auto fn_545=attr(global("np","Carlotta"),"sum");Args args_544;args_544.pos(([&]()->V{V compare_546=scope_529->get("gray");V compare_547;V comparison_result_548;compare_547=V(255LL);comparison_result_548=compare_value("==",compare_546,compare_547);return comparison_result_548;}()));args_544.kw("axis",V(0LL));return invoke(fn_545,args_544);}()),"astype");Args args_549;args_549.pos(attr(global("np","Carlotta"),"float32"));return invoke(fn_550,args_549);}());scope_529->set("profile",value_543);}
    // Carlotta.py:296
    scope_529->set("profile",official::binary("-",scope_529->get("profile"),([&]()->V{auto fn_552=attr(global("np","Carlotta"),"mean");Args args_551;args_551.pos(scope_529->get("profile"));return invoke(fn_552,args_551);}())));
    // Carlotta.py:297
    {V value_553=([&]()->V{auto fn_555=attr(global("np","Carlotta"),"abs");Args args_554;args_554.pos(([&]()->V{auto fn_557=attr(attr(global("np","Carlotta"),"fft"),"fft");Args args_556;args_556.pos(scope_529->get("profile"));return invoke(fn_557,args_556);}()));return invoke(fn_555,args_554);}());scope_529->set("n",value_553);}
    // Carlotta.py:298
    {V value_558=V(0LL);scope_529->set("amplitude",value_558);}
    // Carlotta.py:299
    {V value_559=V(0LL);scope_529->set("frequncy",value_559);}
    // Carlotta.py:300
    {V value_560=V(1LL);scope_529->set("i",value_560);}
    // Carlotta.py:301
        while(([&]()->V{V compare_566=scope_529->get("i");V compare_567;V comparison_result_568;compare_567=scope_529->get("width");comparison_result_568=compare_value("<",compare_566,compare_567);return comparison_result_568;}()).truth()){
        // Carlotta.py:302
        if(([&]()->V{V compare_561=item(scope_529->get("n"),scope_529->get("i"));V compare_562;V comparison_result_563;compare_562=scope_529->get("amplitude");comparison_result_563=compare_value(">",compare_561,compare_562);return comparison_result_563;}()).truth()){
            // Carlotta.py:303
            {V value_564=item(scope_529->get("n"),scope_529->get("i"));scope_529->set("amplitude",value_564);}
            // Carlotta.py:304
            {V value_565=scope_529->get("i");scope_529->set("frequncy",value_565);}
        }
        // Carlotta.py:305
        scope_529->set("i",official::binary("+",scope_529->get("i"),V(1LL)));
    }
    // Carlotta.py:306
    ([&]()->V{auto fn_570=attr(attr(self_value(),"logger"),"info");Args args_569;args_569.pos(V(std::string{}+"forte with freq "+format_value(scope_529->get("frequncy"),"",-1)+" & amp "+format_value(scope_529->get("amplitude"),"",-1)));return invoke(fn_570,args_569);}());
    // Carlotta.py:307
    return ([&]()->V{V operand_571;operand_571=([&]()->V{V compare_572=scope_529->get("min_freq");V compare_573;V comparison_result_574;compare_573=scope_529->get("frequncy");comparison_result_574=compare_value("<=",compare_572,compare_573);if(!comparison_result_574.truth())return comparison_result_574;compare_572=compare_573;compare_573=scope_529->get("max_freq");comparison_result_574=compare_value("<=",compare_572,compare_573);return comparison_result_574;}());if(operand_571.truth())return operand_571;return ([&]()->V{V compare_575=scope_529->get("amplitude");V compare_576;V comparison_result_577;compare_576=scope_529->get("min_amp");comparison_result_577=compare_value(">=",compare_575,compare_576);return comparison_result_577;}());}());
return V{};
}),false);
// Official method Carlotta.calculate_forte_num, lines 309-328
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_578=bind_arguments(official_args,signature,captured);
scope_578->set("cropped",V::missing());
scope_578->set("forte",V::missing());
scope_578->set("gray",V::missing());
scope_578->set("height",V::missing());
scope_578->set("image",V::missing());
scope_578->set("left",V::missing());
scope_578->set("lower_bound",V::missing());
scope_578->set("score",V::missing());
scope_578->set("step",V::missing());
scope_578->set("upper_bound",V::missing());
scope_578->set("width",V::missing());
    // Carlotta.py:310
    {V value_579=([&]()->V{auto fn_581=attr(scope_578->get("box"),"crop_frame");Args args_580;args_580.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_581,args_580);}());scope_578->set("cropped",value_579);}
    // Carlotta.py:311
    {V value_582=([&]()->V{auto fn_584=global("color_range_to_bound","Carlotta");Args args_583;args_583.pos(scope_578->get("forte_color"));return invoke(fn_584,args_583);}());auto unpack_585=unpack(value_582,2);scope_578->set("lower_bound",unpack_585[0]);scope_578->set("upper_bound",unpack_585[1]);}
    // Carlotta.py:312
    {V value_586=([&]()->V{auto fn_588=attr(global("cv2","Carlotta"),"inRange");Args args_587;args_587.pos(scope_578->get("cropped"));args_587.pos(scope_578->get("lower_bound"));args_587.pos(scope_578->get("upper_bound"));return invoke(fn_588,args_587);}());scope_578->set("image",value_586);}
    // Carlotta.py:314
    {V value_589=V(0LL);scope_578->set("forte",value_589);}
    // Carlotta.py:315
    {V value_590=attr(scope_578->get("image"),"shape");auto unpack_591=unpack(value_590,2);scope_578->set("height",unpack_591[0]);scope_578->set("width",unpack_591[1]);}
    // Carlotta.py:316
    {V value_592=([&]()->V{auto fn_594=global("int","Carlotta");Args args_593;args_593.pos(([&]()->V{V left_595=scope_578->get("width");V right_596=scope_578->get("num");return official::binary("/",left_595,right_596);}()));return invoke(fn_594,args_593);}());scope_578->set("step",value_592);}
    // Carlotta.py:318
    {V value_597=scope_578->get("num");scope_578->set("forte",value_597);}
    // Carlotta.py:319
    {V value_598=([&]()->V{V left_599=scope_578->get("step");V right_600=([&]()->V{V left_601=scope_578->get("forte");V right_602=V(1LL);return official::binary("-",left_601,right_602);}());return official::binary("*",left_599,right_600);}());scope_578->set("left",value_598);}
    // Carlotta.py:320
        while(([&]()->V{V compare_609=scope_578->get("forte");V compare_610;V comparison_result_611;compare_610=V(0LL);comparison_result_611=compare_value(">",compare_609,compare_610);return comparison_result_611;}()).truth()){
        // Carlotta.py:321
        {V value_603=item(scope_578->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_578->get("left"),([&]()->V{V left_604=scope_578->get("left");V right_605=scope_578->get("step");return official::binary("+",left_604,right_605);}()),V{})}));scope_578->set("gray",value_603);}
        // Carlotta.py:322
        {V value_606=([&]()->V{auto fn_608=attr(self_value(),"judge_frequncy_and_amplitude");Args args_607;args_607.pos(scope_578->get("gray"));args_607.pos(scope_578->get("min_freq"));args_607.pos(scope_578->get("max_freq"));args_607.pos(scope_578->get("min_amp"));return invoke(fn_608,args_607);}());scope_578->set("score",value_606);}
        // Carlotta.py:323
        if(scope_578->get("score").truth()){
            // Carlotta.py:324
            break;
        }
        // Carlotta.py:325
        scope_578->set("left",official::binary("-",scope_578->get("left"),scope_578->get("step")));
        // Carlotta.py:326
        scope_578->set("forte",official::binary("-",scope_578->get("forte"),V(1LL)));
    }
    // Carlotta.py:327
    ([&]()->V{auto fn_613=attr(attr(self_value(),"logger"),"info");Args args_612;args_612.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_578->get("forte"),"",-1)));return invoke(fn_613,args_612);}());
    // Carlotta.py:328
    return scope_578->get("forte");
return V{};
}),false);
// Official method Carlotta.shorekeeper_auto_dodge, lines 330-334
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_614=bind_arguments(official_args,signature,captured);
scope_614->set("ShoreKeeper",V::missing());
scope_614->set("char",V::missing());
scope_614->set("i",V::missing());
    // Carlotta.py:331
    scope_614->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Carlotta.py:332
    {auto iterator_615=official::iterate(([&]()->V{auto fn_622=global("enumerate","Carlotta");Args args_621;args_621.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_622,args_621);}()));V item_616;while(iterator_615.next(item_616)){
        auto unpack_623=unpack(item_616,2);scope_614->set("i",unpack_623[0]);scope_614->set("char",unpack_623[1]);
        // Carlotta.py:333
        if(([&]()->V{auto fn_618=global("isinstance","Carlotta");Args args_617;args_617.pos(scope_614->get("char"));args_617.pos(scope_614->get("ShoreKeeper"));return invoke(fn_618,args_617);}()).truth()){
            // Carlotta.py:334
            return ([&]()->V{auto fn_620=attr(scope_614->get("char"),"auto_dodge");Args args_619;args_619.kw("condition",attr(self_value(),"flying"));return invoke(fn_620,args_619);}());
        }
    }
    }
return V{};
}),false);
}
