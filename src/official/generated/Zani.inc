// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Zani.py
// SHA256 060d76b1cea1e56f03678cec26d0d9ab4360d3f348a61a5d72cda099882c150d
void OfficialCharacter::install_Zani(){
auto scope=std::make_shared<Scope>();
set_global("State",make_namespace("State",{{"FORTE_FULL",V(1LL)},{"CON_FULL",V(2LL)},{"DONE",V(3LL)},{"FAILED",V(4LL)},{"INTERRUPTED",V(5LL)}}));
set_global("zani_light_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(245LL),V(255LL)}));set_item(dictionary_1,V("g"),V::tuple({V(245LL),V(255LL)}));set_item(dictionary_1,V("b"),V::tuple({V(205LL),V(225LL)}));return dictionary_1;}()));
set_global("zani_blazes_color",([&]()->V{V dictionary_2=V::dict();set_item(dictionary_2,V("r"),V::tuple({V(231LL),V(257LL)}));set_item(dictionary_2,V("g"),V::tuple({V(239LL),V(255LL)}));set_item(dictionary_2,V("b"),V::tuple({V(171LL),V(201LL)}));return dictionary_2;}()));
set_global("zani_forte_color",([&]()->V{V dictionary_3=V::dict();set_item(dictionary_3,V("r"),V::tuple({V(239LL),V(255LL)}));set_item(dictionary_3,V("g"),V::tuple({V(222LL),V(255LL)}));set_item(dictionary_3,V("b"),V::tuple({V(156LL),V(196LL)}));return dictionary_3;}()));
// Official method Zani.__init__, lines 21-36
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_4=bind_arguments(official_args,signature,captured);
    // Zani.py:22
    ([&]()->V{auto fn_8=attr(([&]()->V{auto fn_6=global("super","Zani");Args args_5;return invoke(fn_6,args_5);}()),"__init__");Args args_7;args_7.spread(scope_4->get("args"));args_7.spread_keywords(scope_4->get("kwargs"));return invoke(fn_8,args_7);}());
    // Zani.py:23
    {V value_9=V(1.42);set_attr(self_value(),"intro_motion_freeze_duration",value_9);}
    // Zani.py:24
    {V value_10=V(0LL);set_attr(self_value(),"liberation_time",value_10);}
    // Zani.py:25
    {V value_11=V(false);set_attr(self_value(),"in_liberation",value_11);}
    // Zani.py:26
    {V value_12=unary("-",V(1LL));set_attr(self_value(),"blazes",value_12);}
    // Zani.py:27
    {V value_13=unary("-",V(1LL));set_attr(self_value(),"blazes_threshold",value_13);}
    // Zani.py:28
    {V value_14=V{};set_attr(self_value(),"char_phoebe",value_14);}
    // Zani.py:29
    {V value_15=unary("-",V(1LL));set_attr(self_value(),"crisis_time",value_15);}
    // Zani.py:30
    {V value_16=unary("-",V(1LL));set_attr(self_value(),"nightfall_time",value_16);}
    // Zani.py:31
    {V value_17=V(0LL);set_attr(self_value(),"state",value_17);}
    // Zani.py:32
    {V value_18=unary("-",V(1LL));set_attr(self_value(),"chair_time",value_18);}
    // Zani.py:33
    {V value_19=unary("-",V(1LL));set_attr(self_value(),"last_liber2",value_19);}
    // Zani.py:34
    {V value_20=unary("-",V(1LL));set_attr(self_value(),"dodge_time",value_20);}
    // Zani.py:35
    {V value_21=unary("-",V(1LL));set_attr(self_value(),"attack_breakthrough_time",value_21);}
    // Zani.py:36
    {V value_22=V(false);set_attr(self_value(),"check_f_on_switch",value_22);}
return V{};
}),false);
// Official method Zani.reset_state, lines 38-42
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_23=bind_arguments(official_args,signature,captured);
    // Zani.py:39
    {V value_24=V{};set_attr(self_value(),"char_phoebe",value_24);}
    // Zani.py:40
    {V value_25=unary("-",V(1LL));set_attr(self_value(),"blazes_threshold",value_25);}
    // Zani.py:41
    {V value_26=unary("-",V(1LL));set_attr(self_value(),"chair_time",value_26);}
    // Zani.py:42
    ([&]()->V{auto fn_30=attr(([&]()->V{auto fn_28=global("super","Zani");Args args_27;return invoke(fn_28,args_27);}()),"reset_state");Args args_29;return invoke(fn_30,args_29);}());
return V{};
}),false);
// Official method Zani.do_perform, lines 44-119
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_31=bind_arguments(official_args,signature,captured);
scope_31->set("e_available",V::missing());
scope_31->set("forte_full",V::missing());
scope_31->set("liber_avail",V::missing());
scope_31->set("predicted",V::missing());
scope_31->set("should_liberate",V::missing());
scope_31->set("success",V::missing());
    // Zani.py:45
    if(([&]()->V{V compare_32=attr(self_value(),"blazes_threshold");V compare_33;V comparison_result_34;compare_33=unary("-",V(1LL));comparison_result_34=compare_value("==",compare_32,compare_33);return comparison_result_34;}()).truth()){
        // Zani.py:46
        ([&]()->V{auto fn_36=attr(self_value(),"decide_teammate");Args args_35;return invoke(fn_36,args_35);}());
    }
    // Zani.py:49
    ([&]()->V{auto fn_38=attr(self_value(),"wait_down");Args args_37;return invoke(fn_38,args_37);}());
    // Zani.py:50
    ([&]()->V{auto fn_40=attr(self_value(),"check_liber");Args args_39;return invoke(fn_40,args_39);}());
    // Zani.py:53
    if(attr(self_value(),"in_liberation").truth()){
        // Zani.py:54
        ([&]()->V{auto fn_42=attr(attr(self_value(),"logger"),"info");Args args_41;args_41.pos(V("in liberation"));return invoke(fn_42,args_41);}());
        // Zani.py:55
        {V value_43=V(1LL);set_attr(self_value(),"state",value_43);}
        // Zani.py:56
        if(([&]()->V{auto fn_45=attr(self_value(),"should_end_liberation");Args args_44;return invoke(fn_45,args_44);}()).truth()){
            // Zani.py:57
            ([&]()->V{auto fn_47=attr(self_value(),"click_liber2");Args args_46;return invoke(fn_47,args_46);}());
        }else{
            // Zani.py:59
            ([&]()->V{auto fn_49=attr(self_value(),"nightfall_combo");Args args_48;return invoke(fn_49,args_48);}());
        }
        // Zani.py:60
        return ([&]()->V{auto fn_51=attr(self_value(),"switch_next_char");Args args_50;return invoke(fn_51,args_50);}());
    }
    // Zani.py:62
    {V value_52=V(0LL);set_attr(self_value(),"state",value_52);}
    // Zani.py:63
    ([&]()->V{auto fn_54=attr(self_value(),"f_break");Args args_53;return invoke(fn_54,args_53);}());
    // Zani.py:64
    {V value_55=unary("-",V(1LL));set_attr(self_value(),"crisis_time",value_55);}
    // Zani.py:67
    ([&]()->V{auto fn_57=attr(self_value(),"update_blazes");Args args_56;return invoke(fn_57,args_56);}());
    // Zani.py:68
    {V value_58=([&]()->V{auto fn_60=attr(self_value(),"is_e_forte_full");Args args_59;return invoke(fn_60,args_59);}());scope_31->set("forte_full",value_58);}
    // Zani.py:69
    {V value_61=([&]()->V{V compare_62=([&]()->V{auto fn_65=attr(self_value(),"current_resonance");Args args_64;return invoke(fn_65,args_64);}());V compare_63;V comparison_result_66;compare_63=V(0.05);comparison_result_66=compare_value(">",compare_62,compare_63);return comparison_result_66;}());scope_31->set("e_available",value_61);}
    // Zani.py:70
    {V value_67=([&]()->V{auto fn_69=attr(self_value(),"liberation_available");Args args_68;return invoke(fn_69,args_68);}());scope_31->set("liber_avail",value_67);}
    // Zani.py:71
    if(([&]()->V{V operand_70;operand_70=attr(self_value(),"has_intro");if(!operand_70.truth())return operand_70;operand_70=([&]()->V{V compare_71=attr(self_value(),"blazes");V compare_72;V comparison_result_73;compare_72=V(1LL);comparison_result_73=compare_value(">=",compare_71,compare_72);return comparison_result_73;}());if(!operand_70.truth())return operand_70;return unary("not",scope_31->get("liber_avail"));}()).truth()){
        // Zani.py:72
        ([&]()->V{auto fn_75=attr(self_value(),"sleep");Args args_74;args_74.pos(V(0.2));args_74.kw("check_combat",V(false));return invoke(fn_75,args_74);}());
        // Zani.py:73
        {V value_76=([&]()->V{auto fn_78=attr(self_value(),"liberation_available");Args args_77;return invoke(fn_78,args_77);}());scope_31->set("liber_avail",value_76);}
        // Zani.py:74
        {V value_79=([&]()->V{V compare_80=([&]()->V{auto fn_83=attr(self_value(),"current_resonance");Args args_82;return invoke(fn_83,args_82);}());V compare_81;V comparison_result_84;compare_81=V(0.05);comparison_result_84=compare_value(">",compare_80,compare_81);return comparison_result_84;}());scope_31->set("e_available",value_79);}
    }
    // Zani.py:75
    {V value_85=([&]()->V{V left_86=([&]()->V{auto fn_89=global("float","Zani");Args args_88;args_88.pos(attr(self_value(),"blazes"));return invoke(fn_89,args_88);}());V right_87=V(0.1);return official::binary("+",left_86,right_87);}());scope_31->set("predicted",value_85);}
    // Zani.py:77
    ([&]()->V{auto fn_91=attr(attr(self_value(),"logger"),"info");Args args_90;args_90.pos(V(std::string{}+"Zani entry: blazes="+format_value(attr(self_value(),"blazes"),"",-1)+" threshold="+format_value(attr(self_value(),"blazes_threshold"),"",-1)+" forte_full="+format_value(scope_31->get("forte_full"),"",-1)+" e_avail="+format_value(scope_31->get("e_available"),"",-1)+" predicted="+format_value(scope_31->get("predicted"),V(std::string{}+".2f").text(),-1)+" liber_avail="+format_value(scope_31->get("liber_avail"),"",-1)+" has_intro="+format_value(attr(self_value(),"has_intro"),"",-1)));return invoke(fn_91,args_90);}());
    // Zani.py:85
    if(([&]()->V{V operand_92;operand_92=([&]()->V{V compare_93=attr(self_value(),"blazes");V compare_94;V comparison_result_95;compare_94=V(1LL);comparison_result_95=compare_value(">=",compare_93,compare_94);return comparison_result_95;}());if(!operand_92.truth())return operand_92;return scope_31->get("liber_avail");}()).truth()){
        // Zani.py:86
        ([&]()->V{auto fn_97=attr(attr(self_value(),"logger"),"info");Args args_96;args_96.pos(V("scene3: blazes full, liberation available, direct liberation"));return invoke(fn_97,args_96);}());
        // Zani.py:87
        if(unary("not",([&]()->V{auto fn_99=attr(self_value(),"_try_liberation");Args args_98;return invoke(fn_99,args_98);}())).truth()){
            // Zani.py:88
            ([&]()->V{auto fn_101=attr(self_value(),"sleep");Args args_100;args_100.pos(V(0.1));return invoke(fn_101,args_100);}());
            // Zani.py:89
            ([&]()->V{auto fn_103=attr(self_value(),"_try_liberation");Args args_102;return invoke(fn_103,args_102);}());
        }
        // Zani.py:90
        return ([&]()->V{auto fn_105=attr(self_value(),"switch_next_char");Args args_104;return invoke(fn_105,args_104);}());
    }
    // Zani.py:93
    if(scope_31->get("forte_full").truth()){
        // Zani.py:94
        ([&]()->V{auto fn_107=attr(attr(self_value(),"logger"),"info");Args args_106;args_106.pos(V(std::string{}+"scene4: enhanced E ready, predicted="+format_value(scope_31->get("predicted"),V(std::string{}+".2f").text(),-1)));return invoke(fn_107,args_106);}());
        // Zani.py:95
        {V value_108=([&]()->V{V compare_109=scope_31->get("predicted");V compare_110;V comparison_result_111;compare_110=attr(self_value(),"blazes_threshold");comparison_result_111=compare_value(">=",compare_109,compare_110);return comparison_result_111;}());scope_31->set("should_liberate",value_108);}
        // Zani.py:96
        {V value_112=([&]()->V{auto fn_114=attr(self_value(),"crisis_response_protocol_combo");Args args_113;return invoke(fn_114,args_113);}());scope_31->set("success",value_112);}
        // Zani.py:97
        if(([&]()->V{V operand_115;operand_115=scope_31->get("success");if(!operand_115.truth())return operand_115;operand_115=scope_31->get("should_liberate");if(!operand_115.truth())return operand_115;return ([&]()->V{auto fn_117=attr(self_value(),"liberation_available");Args args_116;return invoke(fn_117,args_116);}());}()).truth()){
            // Zani.py:98
            ([&]()->V{auto fn_119=attr(attr(self_value(),"logger"),"info");Args args_118;args_118.pos(V("scene4: enhanced E -> liberate"));return invoke(fn_119,args_118);}());
            // Zani.py:99
            ([&]()->V{auto fn_121=attr(self_value(),"_try_liberation");Args args_120;args_120.kw("wait_crisis",V(true));return invoke(fn_121,args_120);}());
        }else{
            // Zani.py:101
            ([&]()->V{auto fn_123=attr(attr(self_value(),"logger"),"info");Args args_122;args_122.pos(V("scene4: enhanced E -> switch"));return invoke(fn_123,args_122);}());
        }
        // Zani.py:102
        return ([&]()->V{auto fn_125=attr(self_value(),"switch_next_char");Args args_124;return invoke(fn_125,args_124);}());
    }
    // Zani.py:106
    if(scope_31->get("e_available").truth()){
        // Zani.py:107
        ([&]()->V{auto fn_127=attr(attr(self_value(),"logger"),"info");Args args_126;args_126.pos(V(std::string{}+"scene1: normal E available, predicted="+format_value(scope_31->get("predicted"),V(std::string{}+".2f").text(),-1)));return invoke(fn_127,args_126);}());
        // Zani.py:108
        {V value_128=([&]()->V{auto fn_130=attr(self_value(),"crisis_response_protocol_combo");Args args_129;return invoke(fn_130,args_129);}());scope_31->set("success",value_128);}
        // Zani.py:110
        if(([&]()->V{V operand_131;operand_131=scope_31->get("success");if(!operand_131.truth())return operand_131;return ([&]()->V{V compare_132=attr(self_value(),"blazes");V compare_133;V comparison_result_134;compare_133=attr(self_value(),"blazes_threshold");comparison_result_134=compare_value(">=",compare_132,compare_133);return comparison_result_134;}());}()).truth()){
            // Zani.py:111
            if(([&]()->V{auto fn_136=attr(self_value(),"liberation_available");Args args_135;return invoke(fn_136,args_135);}()).truth()){
                // Zani.py:112
                ([&]()->V{auto fn_138=attr(attr(self_value(),"logger"),"info");Args args_137;args_137.pos(V("scene1: liberate after enhanced E"));return invoke(fn_138,args_137);}());
                // Zani.py:113
                ([&]()->V{auto fn_140=attr(self_value(),"_try_liberation");Args args_139;args_139.kw("wait_crisis",V(true));return invoke(fn_140,args_139);}());
            }
        }
        // Zani.py:114
        return ([&]()->V{auto fn_142=attr(self_value(),"switch_next_char");Args args_141;return invoke(fn_142,args_141);}());
    }
    // Zani.py:117
    ([&]()->V{auto fn_144=attr(attr(self_value(),"logger"),"info");Args args_143;args_143.pos(V("scene2: E on CD, normal attack until can switch"));return invoke(fn_144,args_143);}());
    // Zani.py:118
    ([&]()->V{auto fn_146=attr(self_value(),"normal_attack_until_can_switch");Args args_145;return invoke(fn_146,args_145);}());
    // Zani.py:119
    return ([&]()->V{auto fn_148=attr(self_value(),"switch_next_char");Args args_147;return invoke(fn_148,args_147);}());
return V{};
}),false);
// Official method Zani._try_liberation, lines 122-131
register_method("_try_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"wait_crisis",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
    // Zani.py:123
    if(scope_149->get("wait_crisis").truth()){
        // Zani.py:124
        ([&]()->V{auto fn_151=attr(self_value(),"wait_crisis_protocol_end");Args args_150;return invoke(fn_151,args_150);}());
        // Zani.py:125
        ([&]()->V{auto fn_153=attr(self_value(),"update_blazes");Args args_152;return invoke(fn_153,args_152);}());
    }
    // Zani.py:126
    if(([&]()->V{auto fn_155=attr(self_value(),"echo_available");Args args_154;return invoke(fn_155,args_154);}()).truth()){
        // Zani.py:127
        ([&]()->V{auto fn_157=attr(self_value(),"click_echo");Args args_156;args_156.kw("time_out",V(0LL));return invoke(fn_157,args_156);}());
    }
    // Zani.py:128
    if(([&]()->V{auto fn_159=attr(self_value(),"click_liberation");Args args_158;args_158.kw("send_click",V(true));return invoke(fn_159,args_158);}()).truth()){
        // Zani.py:129
        ([&]()->V{auto fn_161=attr(self_value(),"_liberation_followup");Args args_160;return invoke(fn_161,args_160);}());
        // Zani.py:130
        return V(true);
    }
    // Zani.py:131
    return V(false);
return V{};
}),false);
// Official method Zani._liberation_followup, lines 133-145
register_method("_liberation_followup",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_162=bind_arguments(official_args,signature,captured);
    // Zani.py:135
    {V value_163=unary("-",V(1LL));set_attr(self_value(),"crisis_time",value_163);}
    // Zani.py:136
    {V value_164=V(1LL);set_attr(self_value(),"state",value_164);}
    // Zani.py:137
    {V value_165=V(true);set_attr(self_value(),"in_liberation",value_165);}
    // Zani.py:138
    {V value_166=([&]()->V{auto fn_168=attr(global("time","Zani"),"time");Args args_167;return invoke(fn_168,args_167);}());set_attr(self_value(),"liberation_time",value_166);}
    // Zani.py:139
    ([&]()->V{auto fn_170=attr(self_value(),"check_liber");Args args_169;return invoke(fn_170,args_169);}());
    // Zani.py:140
    ([&]()->V{auto fn_172=attr(self_value(),"continues_right_click");Args args_171;args_171.pos(V(0.05));return invoke(fn_172,args_171);}());
    // Zani.py:141
    ([&]()->V{auto fn_174=attr(self_value(),"continues_normal_attack");Args args_173;args_173.pos(V(0.15));return invoke(fn_174,args_173);}());
    // Zani.py:142
    ([&]()->V{auto fn_176=attr(self_value(),"nightfall_combo");Args args_175;args_175.kw("cancel_last_smash",V(true));return invoke(fn_176,args_175);}());
    // Zani.py:143
    ([&]()->V{auto fn_178=attr(self_value(),"sleep");Args args_177;args_177.pos(V(0.1));return invoke(fn_178,args_177);}());
    // Zani.py:144
    if(([&]()->V{auto fn_180=attr(self_value(),"is_mouse_forte_full");Args args_179;return invoke(fn_180,args_179);}()).truth()){
        // Zani.py:145
        ([&]()->V{auto fn_182=attr(self_value(),"nightfall_combo");Args args_181;return invoke(fn_182,args_181);}());
    }
return V{};
}),false);
// Official method Zani.basic_attack_breakthrough_combo, lines 149-156
register_method("basic_attack_breakthrough_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_183=bind_arguments(official_args,signature,captured);
scope_183->set("result",V::missing());
    // Zani.py:150
    if(([&]()->V{auto fn_185=attr(self_value(),"is_e_forte_full");Args args_184;return invoke(fn_185,args_184);}()).truth()){
        // Zani.py:151
        return attr(global("State","Zani"),"FORTE_FULL");
    }
    // Zani.py:152
    ([&]()->V{auto fn_187=attr(attr(self_value(),"logger"),"info");Args args_186;args_186.pos(V("basic attack - breakthrough"));return invoke(fn_187,args_186);}());
    // Zani.py:153
    if(([&]()->V{V compare_188=([&]()->V{V assigned_190=([&]()->V{auto fn_192=attr(self_value(),"basic_attack_breakthrough");Args args_191;return invoke(fn_192,args_191);}());scope_183->set("result",assigned_190);return assigned_190;}());V compare_189;V comparison_result_193;compare_189=attr(global("State","Zani"),"DONE");comparison_result_193=compare_value("!=",compare_188,compare_189);return comparison_result_193;}()).truth()){
        // Zani.py:154
        return scope_183->get("result");
    }
    // Zani.py:155
    {V value_194=([&]()->V{auto fn_196=attr(global("time","Zani"),"time");Args args_195;return invoke(fn_196,args_195);}());set_attr(self_value(),"attack_breakthrough_time",value_194);}
    // Zani.py:156
    return attr(global("State","Zani"),"DONE");
return V{};
}),false);
// Official method Zani.click_liber2, lines 158-186
register_method("click_liber2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_197=bind_arguments(official_args,signature,captured);
scope_197->set("current",V::missing());
scope_197->set("duration",V::missing());
scope_197->set("not_liber_box",V::missing());
scope_197->set("send_key",V::missing());
scope_197->set("start",V::missing());
    // Zani.py:159
    {V value_198=([&]()->V{auto fn_200=attr(global("time","Zani"),"time");Args args_199;return invoke(fn_200,args_199);}());scope_197->set("start",value_198);}
    // Zani.py:160
    {V value_201=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_201);}
    // Zani.py:161
    {V value_202=V(true);scope_197->set("send_key",value_202);}
    // Zani.py:162
    {V value_203=([&]()->V{auto fn_205=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_204;args_204.pos(V(2560LL));args_204.pos(V(1440LL));args_204.pos(V(1909LL));args_204.pos(V(1274LL));args_204.pos(V(1957LL));args_204.pos(V(1322LL));args_204.kw("name",V("zani_not_liber_box"));args_204.kw("hcenter",V(true));return invoke(fn_205,args_204);}());scope_197->set("not_liber_box",value_203);}
    // Zani.py:163
        while(unary("not",([&]()->V{auto fn_239=attr(attr(self_value(),"task"),"find_one");Args args_238;args_238.pos(V("box_target_enemy_inner"));args_238.kw("box",scope_197->get("not_liber_box"));args_238.kw("threshold",V(0.75));return invoke(fn_239,args_238);}())).truth()){
        // Zani.py:164
        if(([&]()->V{V compare_206=([&]()->V{V left_208=([&]()->V{auto fn_211=attr(global("time","Zani"),"time");Args args_210;return invoke(fn_211,args_210);}());V right_209=scope_197->get("start");return official::binary("-",left_208,right_209);}());V compare_207;V comparison_result_212;compare_207=V(6LL);comparison_result_212=compare_value(">",compare_206,compare_207);return comparison_result_212;}()).truth()){
            // Zani.py:165
            {V value_213=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_213);}
            // Zani.py:166
            if(unary("not",([&]()->V{auto fn_215=attr(self_value(),"check_liber");Args args_214;return invoke(fn_215,args_214);}())).truth()){
                // Zani.py:167
                ([&]()->V{auto fn_217=attr(self_value(),"update_blazes");Args args_216;return invoke(fn_217,args_216);}());
            }
            // Zani.py:168
            return V{};
        }
        // Zani.py:169
        if(([&]()->V{V compare_218=([&]()->V{auto fn_221=attr(self_value(),"current_resonance");Args args_220;return invoke(fn_221,args_220);}());V compare_219;V comparison_result_222;compare_219=V(0LL);comparison_result_222=compare_value("==",compare_218,compare_219);return comparison_result_222;}()).truth()){
            // Zani.py:170
            {V value_223=([&]()->V{auto fn_225=attr(global("time","Zani"),"time");Args args_224;return invoke(fn_225,args_224);}());scope_197->set("start",value_223);}
        }else{
            // Zani.py:171
            if(([&]()->V{V compare_226=([&]()->V{V left_228=([&]()->V{auto fn_231=attr(global("time","Zani"),"time");Args args_230;return invoke(fn_231,args_230);}());V right_229=scope_197->get("start");return official::binary("-",left_228,right_229);}());V compare_227;V comparison_result_232;compare_227=V(1.5);comparison_result_232=compare_value(">",compare_226,compare_227);return comparison_result_232;}()).truth()){
                // Zani.py:172
                {V value_233=V(false);scope_197->set("send_key",value_233);}
            }
        }
        // Zani.py:173
        if(scope_197->get("send_key").truth()){
            // Zani.py:174
            ([&]()->V{auto fn_235=attr(self_value(),"send_liberation_key");Args args_234;return invoke(fn_235,args_234);}());
        }
        // Zani.py:175
        ([&]()->V{auto fn_237=attr(attr(self_value(),"task"),"next_frame");Args args_236;return invoke(fn_237,args_236);}());
    }
    // Zani.py:176
    {V value_240=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_240);}
    // Zani.py:177
    {V value_241=([&]()->V{auto fn_243=attr(global("time","Zani"),"time");Args args_242;return invoke(fn_243,args_242);}());scope_197->set("current",value_241);}
    // Zani.py:178
    {V value_244=V(2.25);scope_197->set("duration",value_244);}
    // Zani.py:179
    if(([&]()->V{V compare_245=([&]()->V{V left_247=scope_197->get("current");V right_248=scope_197->get("start");return official::binary("-",left_247,right_248);}());V compare_246;V comparison_result_249;compare_246=scope_197->get("duration");comparison_result_249=compare_value(">=",compare_245,compare_246);return comparison_result_249;}()).truth()){
        // Zani.py:180
        {V value_250=scope_197->get("current");set_attr(self_value(),"last_liber2",value_250);}
        // Zani.py:181
        ([&]()->V{auto fn_252=attr(self_value(),"add_freeze_duration");Args args_251;args_251.pos(([&]()->V{V left_253=scope_197->get("current");V right_254=scope_197->get("duration");return official::binary("-",left_253,right_254);}()));args_251.pos(scope_197->get("duration"));args_251.pos(V(0LL));return invoke(fn_252,args_251);}());
        // Zani.py:182
        ([&]()->V{auto fn_256=attr(attr(self_value(),"logger"),"info");Args args_255;args_255.pos(V("clicked liber2"));return invoke(fn_256,args_255);}());
    }
    // Zani.py:183
    {V value_257=V(false);set_attr(self_value(),"in_liberation",value_257);}
    // Zani.py:184
    {V value_258=unary("-",V(1LL));set_attr(self_value(),"blazes",value_258);}
    // Zani.py:185
    {V value_259=unary("-",V(1LL));set_attr(self_value(),"liberation_time",value_259);}
    // Zani.py:186
    {V value_260=V(0LL);set_attr(self_value(),"state",value_260);}
return V{};
}),false);
// Official method Zani.should_end_liberation, lines 188-200
register_method("should_end_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_only",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_261=bind_arguments(official_args,signature,captured);
    // Zani.py:189
    if(([&]()->V{V compare_262=([&]()->V{auto fn_265=attr(self_value(),"liberation_time_left");Args args_264;return invoke(fn_265,args_264);}());V compare_263;V comparison_result_266;compare_263=V(1.7);comparison_result_266=compare_value("<",compare_262,compare_263);return comparison_result_266;}()).truth()){
        // Zani.py:190
        ([&]()->V{auto fn_268=attr(attr(self_value(),"logger"),"info");Args args_267;args_267.pos(V("Liberation is about to end, perform liberation2"));return invoke(fn_268,args_267);}());
        // Zani.py:191
        return V(true);
    }
    // Zani.py:192
    if(([&]()->V{V operand_269;operand_269=scope_261->get("time_only");if(operand_269.truth())return operand_269;return ([&]()->V{auto fn_271=attr(self_value(),"is_nightfall_ready");Args args_270;return invoke(fn_271,args_270);}());}()).truth()){
        // Zani.py:193
        return V(false);
    }
    // Zani.py:194
    if(([&]()->V{V compare_272=([&]()->V{auto fn_275=attr(self_value(),"wait_resonance_not_gray");Args args_274;args_274.kw("send_click",V(true));args_274.kw("liber_time_check",V(true));return invoke(fn_275,args_274);}());V compare_273;V comparison_result_276;compare_273=attr(global("State","Zani"),"INTERRUPTED");comparison_result_276=compare_value("==",compare_272,compare_273);return comparison_result_276;}()).truth()){
        // Zani.py:195
        ([&]()->V{auto fn_278=attr(attr(self_value(),"logger"),"info");Args args_277;args_277.pos(V("Nightfall interrupted, perform liberation2"));return invoke(fn_278,args_277);}());
        // Zani.py:196
        return V(true);
    }
    // Zani.py:197
    if(unary("not",([&]()->V{auto fn_280=attr(self_value(),"is_mouse_forte_full");Args args_279;return invoke(fn_280,args_279);}())).truth()){
        // Zani.py:198
        ([&]()->V{auto fn_282=attr(attr(self_value(),"logger"),"info");Args args_281;args_281.pos(V("Cannot perform another nightfall, perform liberation2"));return invoke(fn_282,args_281);}());
        // Zani.py:199
        return V(true);
    }
    // Zani.py:200
    return V(false);
return V{};
}),false);
// Official method Zani.liberation_time_left, lines 202-207
register_method("liberation_time_left",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_283=bind_arguments(official_args,signature,captured);
scope_283->set("result",V::missing());
    // Zani.py:203
    if(([&]()->V{V operand_284;operand_284=unary("not",attr(self_value(),"in_liberation"));if(operand_284.truth())return operand_284;return ([&]()->V{V compare_285=attr(self_value(),"liberation_time");V compare_286;V comparison_result_287;compare_286=V(0LL);comparison_result_287=compare_value("<=",compare_285,compare_286);return comparison_result_287;}());}()).truth()){
        // Zani.py:204
        return V(0LL);
    }
    // Zani.py:205
    {V value_288=([&]()->V{V left_289=V(20LL);V right_290=([&]()->V{auto fn_292=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_291;args_291.pos(attr(self_value(),"liberation_time"));return invoke(fn_292,args_291);}());return official::binary("-",left_289,right_290);}());scope_283->set("result",value_288);}
    // Zani.py:206
    ([&]()->V{auto fn_294=attr(attr(self_value(),"logger"),"debug");Args args_293;args_293.pos(V(std::string{}+"liberation_lasted: "+format_value(scope_283->get("result"),"",-1)));return invoke(fn_294,args_293);}());
    // Zani.py:207
    return scope_283->get("result");
return V{};
}),false);
// Official method Zani.nightfall_combo, lines 209-233
register_method("nightfall_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"cancel_last_smash",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_295=bind_arguments(official_args,signature,captured);
scope_295->set("start",V::missing());
    // Zani.py:210
    ([&]()->V{auto fn_297=attr(attr(self_value(),"logger"),"info");Args args_296;args_296.pos(V("perform nightfall_combo"));return invoke(fn_297,args_296);}());
    // Zani.py:211
    {V value_298=([&]()->V{auto fn_300=attr(global("time","Zani"),"time");Args args_299;return invoke(fn_300,args_299);}());scope_295->set("start",value_298);}
    // Zani.py:212
    if(unary("not",([&]()->V{auto fn_302=attr(self_value(),"is_nightfall_ready");Args args_301;return invoke(fn_302,args_301);}())).truth()){
        // Zani.py:213
                while(([&]()->V{V operand_322;operand_322=unary("not",([&]()->V{auto fn_324=attr(self_value(),"is_nightfall_ready");Args args_323;return invoke(fn_324,args_323);}()));if(operand_322.truth())return operand_322;return ([&]()->V{V compare_325=([&]()->V{V left_327=([&]()->V{auto fn_330=attr(global("time","Zani"),"time");Args args_329;return invoke(fn_330,args_329);}());V right_328=scope_295->get("start");return official::binary("-",left_327,right_328);}());V compare_326;V comparison_result_331;compare_326=V(1.6);comparison_result_331=compare_value("<",compare_325,compare_326);return comparison_result_331;}());}()).truth()){
            // Zani.py:214
            ([&]()->V{auto fn_304=attr(self_value(),"click");Args args_303;return invoke(fn_304,args_303);}());
            // Zani.py:215
            if(([&]()->V{V operand_305;operand_305=([&]()->V{V compare_306=([&]()->V{V left_308=([&]()->V{auto fn_311=attr(global("time","Zani"),"time");Args args_310;return invoke(fn_311,args_310);}());V right_309=scope_295->get("start");return official::binary("-",left_308,right_309);}());V compare_307;V comparison_result_312;compare_307=V(3.5);comparison_result_312=compare_value(">",compare_306,compare_307);return comparison_result_312;}());if(operand_305.truth())return operand_305;return unary("not",attr(self_value(),"in_liberation"));}()).truth()){
                // Zani.py:216
                return V{};
            }
            // Zani.py:217
            if(([&]()->V{V operand_313;operand_313=([&]()->V{auto fn_315=attr(self_value(),"should_end_liberation");Args args_314;args_314.kw("time_only",V(true));return invoke(fn_315,args_314);}());if(!operand_313.truth())return operand_313;return ([&]()->V{auto fn_317=attr(self_value(),"click_liber2");Args args_316;return invoke(fn_317,args_316);}());}()).truth()){
                // Zani.py:218
                return V{};
            }
            // Zani.py:219
            ([&]()->V{auto fn_319=attr(self_value(),"check_combat");Args args_318;return invoke(fn_319,args_318);}());
            // Zani.py:220
            ([&]()->V{auto fn_321=attr(attr(self_value(),"task"),"next_frame");Args args_320;return invoke(fn_321,args_320);}());
        }
    }
    // Zani.py:221
    ([&]()->V{auto fn_333=attr(self_value(),"continues_normal_attack");Args args_332;args_332.pos(V(0.5));return invoke(fn_333,args_332);}());
    // Zani.py:222
    if(scope_295->get("cancel_last_smash").truth()){
        // Zani.py:223
        ([&]()->V{auto fn_335=attr(attr(self_value(),"logger"),"info");Args args_334;args_334.pos(V("cancel nightfall last smash"));return invoke(fn_335,args_334);}());
        // Zani.py:224
        {V value_336=([&]()->V{auto fn_338=attr(global("time","Zani"),"time");Args args_337;return invoke(fn_338,args_337);}());scope_295->set("start",value_336);}
        // Zani.py:225
                while(([&]()->V{auto fn_351=attr(self_value(),"is_nightfall_ready");Args args_350;args_350.kw("threshold",V(0.035));return invoke(fn_351,args_350);}()).truth()){
            // Zani.py:226
            if(([&]()->V{V compare_339=([&]()->V{V left_341=([&]()->V{auto fn_344=attr(global("time","Zani"),"time");Args args_343;return invoke(fn_344,args_343);}());V right_342=scope_295->get("start");return official::binary("-",left_341,right_342);}());V compare_340;V comparison_result_345;compare_340=V(2.5);comparison_result_345=compare_value(">",compare_339,compare_340);return comparison_result_345;}()).truth()){
                // Zani.py:227
                break;
            }
            // Zani.py:228
            ([&]()->V{auto fn_347=attr(self_value(),"click");Args args_346;return invoke(fn_347,args_346);}());
            // Zani.py:229
            ([&]()->V{auto fn_349=attr(attr(self_value(),"task"),"next_frame");Args args_348;return invoke(fn_349,args_348);}());
        }
        // Zani.py:230
        ([&]()->V{auto fn_353=attr(self_value(),"sleep");Args args_352;args_352.pos(V(0.25));args_352.kw("check_combat",V(false));return invoke(fn_353,args_352);}());
        // Zani.py:231
        ([&]()->V{auto fn_355=attr(self_value(),"continues_right_click");Args args_354;args_354.pos(V(0.1));return invoke(fn_355,args_354);}());
    }else{
        // Zani.py:233
        {V value_356=([&]()->V{auto fn_358=attr(global("time","Zani"),"time");Args args_357;return invoke(fn_358,args_357);}());set_attr(self_value(),"nightfall_time",value_356);}
    }
return V{};
}),false);
// Official method Zani.is_nightfall_ready, lines 235-242
register_method("is_nightfall_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"threshold",V(0.15)}},"","",{})](const Args& official_args)->V{
auto scope_359=bind_arguments(official_args,signature,captured);
scope_359->set("box",V::missing());
scope_359->set("light_percent",V::missing());
    // Zani.py:236
    {V value_360=([&]()->V{auto fn_362=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_361;args_361.pos(V(2560LL));args_361.pos(V(1440LL));args_361.pos(V(1853LL));args_361.pos(V(1233LL));args_361.pos(V(1964LL));args_361.pos(V(1344LL));args_361.kw("name",V("zani_attack"));args_361.kw("hcenter",V(true));return invoke(fn_362,args_361);}());scope_359->set("box",value_360);}
    // Zani.py:237
    ([&]()->V{auto fn_364=attr(attr(self_value(),"task"),"draw_boxes");Args args_363;args_363.pos(attr(scope_359->get("box"),"name"));args_363.pos(scope_359->get("box"));return invoke(fn_364,args_363);}());
    // Zani.py:238
    {V value_365=([&]()->V{auto fn_367=attr(self_value(),"calculate_color_percentage_in_masked");Args args_366;args_366.pos(global("zani_light_color","Zani"));args_366.pos(scope_359->get("box"));args_366.pos(V(0.425));args_366.pos(V(0.49));return invoke(fn_367,args_366);}());scope_359->set("light_percent",value_365);}
    // Zani.py:239
    ([&]()->V{auto fn_369=attr(attr(self_value(),"logger"),"debug");Args args_368;args_368.pos(V(std::string{}+"nightfall_percent "+format_value(scope_359->get("light_percent"),"",-1)));return invoke(fn_369,args_368);}());
    // Zani.py:240
    if(([&]()->V{V compare_370=scope_359->get("light_percent");V compare_371;V comparison_result_372;compare_371=scope_359->get("threshold");comparison_result_372=compare_value(">",compare_370,compare_371);return comparison_result_372;}()).truth()){
        // Zani.py:241
        return V(true);
    }
    // Zani.py:242
    return V(false);
return V{};
}),false);
// Official method Zani.calculate_color_percentage_in_masked, lines 244-270
register_method("calculate_color_percentage_in_masked",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"target_color",V::missing()},{"box",V::missing()},{"mask_r1_ratio",V(0.0)},{"mask_r2_ratio",V(0.0)}},"","",{})](const Args& official_args)->V{
auto scope_373=bind_arguments(official_args,signature,captured);
scope_373->set("center",V::missing());
scope_373->set("color_mask",V::missing());
scope_373->set("combined_mask",V::missing());
scope_373->set("cropped",V::missing());
scope_373->set("h",V::missing());
scope_373->set("lower_bound",V::missing());
scope_373->set("match_count",V::missing());
scope_373->set("r1",V::missing());
scope_373->set("r2",V::missing());
scope_373->set("ring_mask",V::missing());
scope_373->set("total_mask_area",V::missing());
scope_373->set("upper_bound",V::missing());
scope_373->set("w",V::missing());
    // Zani.py:245
    {V value_374=([&]()->V{auto fn_376=attr(scope_373->get("box"),"crop_frame");Args args_375;args_375.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_376,args_375);}());scope_373->set("cropped",value_374);}
    // Zani.py:246
    if(([&]()->V{V operand_377;operand_377=([&]()->V{V compare_378=scope_373->get("cropped");V compare_379;V comparison_result_380;compare_379=V{};comparison_result_380=compare_value("is",compare_378,compare_379);return comparison_result_380;}());if(operand_377.truth())return operand_377;return ([&]()->V{V compare_381=attr(scope_373->get("cropped"),"size");V compare_382;V comparison_result_383;compare_382=V(0LL);comparison_result_383=compare_value("==",compare_381,compare_382);return comparison_result_383;}());}()).truth()){
        // Zani.py:247
        return V(0.0);
    }
    // Zani.py:248
    {V value_384=item(attr(scope_373->get("cropped"),"shape"),V::slice(V{},V(2LL),V{}));auto unpack_385=unpack(value_384,2);scope_373->set("h",unpack_385[0]);scope_373->set("w",unpack_385[1]);}
    // Zani.py:250
    {V value_386=([&]()->V{auto fn_388=global("int","Zani");Args args_387;args_387.pos(([&]()->V{auto fn_390=attr(global("math","Zani"),"floor");Args args_389;args_389.pos(([&]()->V{V left_391=scope_373->get("h");V right_392=scope_373->get("mask_r1_ratio");return official::binary("*",left_391,right_392);}()));return invoke(fn_390,args_389);}()));return invoke(fn_388,args_387);}());scope_373->set("r1",value_386);}
    // Zani.py:251
    {V value_393=([&]()->V{auto fn_395=global("int","Zani");Args args_394;args_394.pos(([&]()->V{auto fn_397=attr(global("math","Zani"),"ceil");Args args_396;args_396.pos(([&]()->V{V left_398=scope_373->get("h");V right_399=scope_373->get("mask_r2_ratio");return official::binary("*",left_398,right_399);}()));return invoke(fn_397,args_396);}()));return invoke(fn_395,args_394);}());scope_373->set("r2",value_393);}
    // Zani.py:252
    if(([&]()->V{V compare_400=scope_373->get("r2");V compare_401;V comparison_result_402;compare_401=scope_373->get("r1");comparison_result_402=compare_value("<=",compare_400,compare_401);return comparison_result_402;}()).truth()){
        // Zani.py:253
        return V(0.0);
    }
    // Zani.py:255
    {V value_403=V::tuple({([&]()->V{V left_404=scope_373->get("w");V right_405=V(2LL);return official::binary("//",left_404,right_405);}()),([&]()->V{V left_406=scope_373->get("h");V right_407=V(2LL);return official::binary("//",left_406,right_407);}())});scope_373->set("center",value_403);}
    // Zani.py:256
    {V value_408=([&]()->V{auto fn_410=attr(global("np","Zani"),"zeros");Args args_409;args_409.pos(V::tuple({scope_373->get("h"),scope_373->get("w")}));args_409.kw("dtype",attr(global("np","Zani"),"uint8"));return invoke(fn_410,args_409);}());scope_373->set("ring_mask",value_408);}
    // Zani.py:257
    ([&]()->V{auto fn_412=attr(global("cv2","Zani"),"circle");Args args_411;args_411.pos(scope_373->get("ring_mask"));args_411.pos(scope_373->get("center"));args_411.pos(scope_373->get("r2"));args_411.pos(V(255LL));args_411.pos(unary("-",V(1LL)));return invoke(fn_412,args_411);}());
    // Zani.py:258
    if(([&]()->V{V compare_413=scope_373->get("r1");V compare_414;V comparison_result_415;compare_414=V(0LL);comparison_result_415=compare_value(">",compare_413,compare_414);return comparison_result_415;}()).truth()){
        // Zani.py:259
        ([&]()->V{auto fn_417=attr(global("cv2","Zani"),"circle");Args args_416;args_416.pos(scope_373->get("ring_mask"));args_416.pos(scope_373->get("center"));args_416.pos(scope_373->get("r1"));args_416.pos(V(0LL));args_416.pos(unary("-",V(1LL)));return invoke(fn_417,args_416);}());
    }
    // Zani.py:261
    {V value_418=([&]()->V{auto fn_420=global("color_range_to_bound","Zani");Args args_419;args_419.pos(scope_373->get("target_color"));return invoke(fn_420,args_419);}());auto unpack_421=unpack(value_418,2);scope_373->set("lower_bound",unpack_421[0]);scope_373->set("upper_bound",unpack_421[1]);}
    // Zani.py:263
    {V value_422=([&]()->V{auto fn_424=attr(global("cv2","Zani"),"inRange");Args args_423;args_423.pos(scope_373->get("cropped"));args_423.pos(scope_373->get("lower_bound"));args_423.pos(scope_373->get("upper_bound"));return invoke(fn_424,args_423);}());scope_373->set("color_mask",value_422);}
    // Zani.py:265
    {V value_425=([&]()->V{auto fn_427=attr(global("cv2","Zani"),"bitwise_and");Args args_426;args_426.pos(scope_373->get("color_mask"));args_426.pos(scope_373->get("ring_mask"));return invoke(fn_427,args_426);}());scope_373->set("combined_mask",value_425);}
    // Zani.py:266
    {V value_428=([&]()->V{auto fn_430=attr(global("cv2","Zani"),"countNonZero");Args args_429;args_429.pos(scope_373->get("combined_mask"));return invoke(fn_430,args_429);}());scope_373->set("match_count",value_428);}
    // Zani.py:267
    {V value_431=([&]()->V{auto fn_433=attr(global("cv2","Zani"),"countNonZero");Args args_432;args_432.pos(scope_373->get("ring_mask"));return invoke(fn_433,args_432);}());scope_373->set("total_mask_area",value_431);}
    // Zani.py:268
    if(([&]()->V{V compare_434=scope_373->get("total_mask_area");V compare_435;V comparison_result_436;compare_435=V(0LL);comparison_result_436=compare_value("==",compare_434,compare_435);return comparison_result_436;}()).truth()){
        // Zani.py:269
        return V(0.0);
    }
    // Zani.py:270
    return ([&]()->V{V left_437=scope_373->get("match_count");V right_438=scope_373->get("total_mask_area");return official::binary("/",left_437,right_438);}());
return V{};
}),false);
// Official method Zani.nightfall_time_left, lines 272-280
register_method("nightfall_time_left",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_439=bind_arguments(official_args,signature,captured);
scope_439->set("result",V::missing());
    // Zani.py:273
    if(([&]()->V{V compare_440=attr(self_value(),"nightfall_time");V compare_441;V comparison_result_442;compare_441=V(0LL);comparison_result_442=compare_value("<=",compare_440,compare_441);return comparison_result_442;}()).truth()){
        // Zani.py:274
        return V(0LL);
    }
    // Zani.py:275
    {V value_443=([&]()->V{V left_444=V(2.2);V right_445=([&]()->V{auto fn_447=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_446;args_446.pos(attr(self_value(),"nightfall_time"));args_446.kw("intro_motion_freeze",V(true));return invoke(fn_447,args_446);}());return official::binary("-",left_444,right_445);}());scope_439->set("result",value_443);}
    // Zani.py:276
    if(([&]()->V{V compare_448=attr(self_value(),"nightfall_time");V compare_449;V comparison_result_450;compare_449=V(0LL);comparison_result_450=compare_value("<=",compare_448,compare_449);return comparison_result_450;}()).truth()){
        // Zani.py:277
        {V value_451=unary("-",V(1LL));set_attr(self_value(),"nightfall_time",value_451);}
        // Zani.py:278
        return V(0LL);
    }
    // Zani.py:279
    ([&]()->V{auto fn_453=attr(attr(self_value(),"logger"),"debug");Args args_452;args_452.pos(V(std::string{}+"nightfall_time_left: "+format_value(scope_439->get("result"),"",-1)));return invoke(fn_453,args_452);}());
    // Zani.py:280
    return scope_439->get("result");
return V{};
}),false);
// Official method Zani.standard_defense_protocol_combo, lines 282-291
register_method("standard_defense_protocol_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_454=bind_arguments(official_args,signature,captured);
    // Zani.py:283
    if(([&]()->V{auto fn_456=attr(self_value(),"is_e_forte_full");Args args_455;return invoke(fn_456,args_455);}()).truth()){
        // Zani.py:284
        return attr(global("State","Zani"),"FORTE_FULL");
    }
    // Zani.py:285
    if(([&]()->V{auto fn_458=attr(self_value(),"resonance_available");Args args_457;return invoke(fn_458,args_457);}()).truth()){
        // Zani.py:286
        ([&]()->V{auto fn_460=attr(attr(self_value(),"logger"),"info");Args args_459;args_459.pos(V("perform standard_defense_protocol"));return invoke(fn_460,args_459);}());
        // Zani.py:287
        ([&]()->V{auto fn_462=attr(self_value(),"click_resonance");Args args_461;args_461.kw("send_click",V(false));return invoke(fn_462,args_461);}());
        // Zani.py:288
        ([&]()->V{auto fn_464=attr(self_value(),"sleep");Args args_463;args_463.pos(V(0.2));return invoke(fn_464,args_463);}());
        // Zani.py:289
        ([&]()->V{auto fn_466=attr(self_value(),"continues_normal_attack");Args args_465;args_465.pos(V(0.2));return invoke(fn_466,args_465);}());
        // Zani.py:290
        return attr(global("State","Zani"),"DONE");
    }
    // Zani.py:291
    return attr(global("State","Zani"),"FAILED");
return V{};
}),false);
// Official method Zani.basic_attack_breakthrough, lines 293-316
register_method("basic_attack_breakthrough",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_467=bind_arguments(official_args,signature,captured);
scope_467->set("result",V::missing());
scope_467->set("sleep",V::missing());
scope_467->set("wait_chair",V::missing());
    // Zani.py:294
    {V value_468=V(1.2);scope_467->set("wait_chair",value_468);}
    // Zani.py:295
    if(([&]()->V{V compare_469=attr(self_value(),"chair_time");V compare_470;V comparison_result_471;compare_470=unary("-",V(1LL));comparison_result_471=compare_value("==",compare_469,compare_470);return comparison_result_471;}()).truth()){
        // Zani.py:296
        {V value_472=([&]()->V{auto fn_474=attr(self_value(),"standard_defense_protocol_combo");Args args_473;return invoke(fn_474,args_473);}());scope_467->set("result",value_472);}
        // Zani.py:297
        if(([&]()->V{V compare_475=scope_467->get("result");V compare_476;V comparison_result_477;compare_476=attr(global("State","Zani"),"FAILED");comparison_result_477=compare_value("==",compare_475,compare_476);return comparison_result_477;}()).truth()){
            // Zani.py:298
            {V value_478=([&]()->V{V left_479=V(0.3);V right_480=([&]()->V{V left_481=([&]()->V{auto fn_484=attr(global("time","Zani"),"time");Args args_483;return invoke(fn_484,args_483);}());V right_482=attr(self_value(),"dodge_time");return official::binary("-",left_481,right_482);}());return official::binary("-",left_479,right_480);}());scope_467->set("sleep",value_478);}
            // Zani.py:299
            if(([&]()->V{V compare_485=([&]()->V{V assigned_487=([&]()->V{auto fn_489=attr(self_value(),"wait_forte_full");Args args_488;args_488.pos(scope_467->get("sleep"));return invoke(fn_489,args_488);}());scope_467->set("result",assigned_487);return assigned_487;}());V compare_486;V comparison_result_490;compare_486=attr(global("State","Zani"),"DONE");comparison_result_490=compare_value("!=",compare_485,compare_486);return comparison_result_490;}()).truth()){
                // Zani.py:300
                return scope_467->get("result");
            }
            // Zani.py:301
            ([&]()->V{auto fn_492=attr(attr(self_value(),"task"),"mouse_down");Args args_491;return invoke(fn_492,args_491);}());
            // Zani.py:302
            if(([&]()->V{V compare_493=([&]()->V{V assigned_495=([&]()->V{auto fn_497=attr(self_value(),"wait_forte_full");Args args_496;args_496.pos(V(0.6));return invoke(fn_497,args_496);}());scope_467->set("result",assigned_495);return assigned_495;}());V compare_494;V comparison_result_498;compare_494=attr(global("State","Zani"),"DONE");comparison_result_498=compare_value("!=",compare_493,compare_494);return comparison_result_498;}()).truth()){
                // Zani.py:303
                return scope_467->get("result");
            }
            // Zani.py:304
            ([&]()->V{auto fn_500=attr(attr(self_value(),"task"),"mouse_up");Args args_499;return invoke(fn_500,args_499);}());
            // Zani.py:305
            {V value_501=V(1.15);scope_467->set("wait_chair",value_501);}
            // Zani.py:306
            if(([&]()->V{V compare_502=([&]()->V{V assigned_504=([&]()->V{auto fn_506=attr(self_value(),"wait_forte_full");Args args_505;args_505.pos(V(0.85));args_505.kw("send_click",V(true));return invoke(fn_506,args_505);}());scope_467->set("result",assigned_504);return assigned_504;}());V compare_503;V comparison_result_507;compare_503=attr(global("State","Zani"),"DONE");comparison_result_507=compare_value("!=",compare_502,compare_503);return comparison_result_507;}()).truth()){
                // Zani.py:307
                return scope_467->get("result");
            }
        }else{
            // Zani.py:308
            if(([&]()->V{V compare_508=scope_467->get("result");V compare_509;V comparison_result_510;compare_509=attr(global("State","Zani"),"FORTE_FULL");comparison_result_510=compare_value("==",compare_508,compare_509);return comparison_result_510;}()).truth()){
                // Zani.py:309
                return attr(global("State","Zani"),"FORTE_FULL");
            }
        }
    }else{
        // Zani.py:311
        scope_467->set("wait_chair",official::binary("-",scope_467->get("wait_chair"),([&]()->V{V left_511=([&]()->V{auto fn_514=attr(global("time","Zani"),"time");Args args_513;return invoke(fn_514,args_513);}());V right_512=attr(self_value(),"chair_time");return official::binary("-",left_511,right_512);}())));
        // Zani.py:312
        {V value_515=unary("-",V(1LL));set_attr(self_value(),"chair_time",value_515);}
    }
    // Zani.py:313
    if(([&]()->V{V compare_516=([&]()->V{V assigned_518=([&]()->V{auto fn_520=attr(self_value(),"wait_forte_full");Args args_519;args_519.pos(scope_467->get("wait_chair"));return invoke(fn_520,args_519);}());scope_467->set("result",assigned_518);return assigned_518;}());V compare_517;V comparison_result_521;compare_517=attr(global("State","Zani"),"DONE");comparison_result_521=compare_value("!=",compare_516,compare_517);return comparison_result_521;}()).truth()){
        // Zani.py:314
        return scope_467->get("result");
    }
    // Zani.py:315
    ([&]()->V{auto fn_523=attr(self_value(),"continues_normal_attack");Args args_522;args_522.pos(V(0.2));return invoke(fn_523,args_522);}());
    // Zani.py:316
    return scope_467->get("result");
return V{};
}),false);
// Official method Zani.crisis_response_protocol_combo, lines 318-341
register_method("crisis_response_protocol_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_524=bind_arguments(official_args,signature,captured);
scope_524->set("_",V::missing());
scope_524->set("current",V::missing());
scope_524->set("result",V::missing());
scope_524->set("start",V::missing());
    // Zani.py:319
    ([&]()->V{auto fn_526=attr(attr(self_value(),"logger"),"info");Args args_525;args_525.pos(V("perform crisis_response_protocol"));return invoke(fn_526,args_525);}());
    // Zani.py:320
    ([&]()->V{auto fn_528=attr(self_value(),"check_combat");Args args_527;return invoke(fn_528,args_527);}());
    // Zani.py:321
    if(unary("not",([&]()->V{auto fn_530=attr(self_value(),"is_e_forte_full");Args args_529;return invoke(fn_530,args_529);}())).truth()){
        // Zani.py:322
        {auto iterator_531=official::iterate(([&]()->V{auto fn_551=global("range","Zani");Args args_550;args_550.pos(V(1LL));return invoke(fn_551,args_550);}()));V item_532;while(iterator_531.next(item_532)){
            scope_524->set("_",item_532);
            // Zani.py:323
            if(([&]()->V{V compare_533=([&]()->V{V assigned_535=([&]()->V{auto fn_537=attr(self_value(),"basic_attack_breakthrough");Args args_536;return invoke(fn_537,args_536);}());scope_524->set("result",assigned_535);return assigned_535;}());V compare_534;V comparison_result_538;compare_534=attr(global("State","Zani"),"DONE");comparison_result_538=compare_value("!=",compare_533,compare_534);return comparison_result_538;}()).truth()){
                // Zani.py:324
                break;
            }
            // Zani.py:325
            if(([&]()->V{V compare_539=([&]()->V{V assigned_541=([&]()->V{auto fn_543=attr(self_value(),"wait_forte_full");Args args_542;args_542.pos(V(2.2));args_542.kw("check_forte",V(true));return invoke(fn_543,args_542);}());scope_524->set("result",assigned_541);return assigned_541;}());V compare_540;V comparison_result_544;compare_540=attr(global("State","Zani"),"DONE");comparison_result_544=compare_value("!=",compare_539,compare_540);return comparison_result_544;}()).truth()){
                // Zani.py:326
                break;
            }else{
                // Zani.py:328
                ([&]()->V{auto fn_546=attr(self_value(),"continues_right_click");Args args_545;args_545.pos(V(0.05));return invoke(fn_546,args_545);}());
                // Zani.py:329
                {V value_547=([&]()->V{auto fn_549=attr(global("time","Zani"),"time");Args args_548;return invoke(fn_549,args_548);}());set_attr(self_value(),"dodge_time",value_547);}
            }
        }
        }
        // Zani.py:330
        if(([&]()->V{V operand_552;operand_552=([&]()->V{V compare_553=scope_524->get("result");V compare_554;V comparison_result_555;compare_554=attr(global("State","Zani"),"FORTE_FULL");comparison_result_555=compare_value("!=",compare_553,compare_554);return comparison_result_555;}());if(!operand_552.truth())return operand_552;return unary("not",([&]()->V{auto fn_557=attr(self_value(),"is_e_forte_full");Args args_556;return invoke(fn_557,args_556);}()));}()).truth()){
            // Zani.py:331
            ([&]()->V{auto fn_559=attr(attr(self_value(),"logger"),"info");Args args_558;args_558.pos(V("crisis_response_protocol not FORTE_FULL"));return invoke(fn_559,args_558);}());
            // Zani.py:332
            return V(false);
        }
    }
    // Zani.py:333
    {V value_560=([&]()->V{auto fn_562=attr(global("time","Zani"),"time");Args args_561;return invoke(fn_562,args_561);}());scope_524->set("start",value_560);}
    // Zani.py:334
    ([&]()->V{auto fn_564=attr(self_value(),"wait_until");Args args_563;args_563.pos(V::function([this,captured=capture_scope(scope_524,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_565=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_567=attr(self_value(),"is_e_forte_full");Args args_566;return invoke(fn_567,args_566);}()));
}));args_563.kw("post_action",attr(self_value(),"send_resonance_key"));args_563.kw("time_out",V(1LL));return invoke(fn_564,args_563);}());
    // Zani.py:335
    {V value_568=([&]()->V{auto fn_570=attr(global("time","Zani"),"time");Args args_569;return invoke(fn_570,args_569);}());scope_524->set("current",value_568);}
    // Zani.py:336
    ([&]()->V{auto fn_572=attr(attr(self_value(),"logger"),"debug");Args args_571;args_571.pos(V(std::string{}+"cast resonance duration "+format_value(([&]()->V{V left_573=scope_524->get("current");V right_574=scope_524->get("start");return official::binary("-",left_573,right_574);}()),"",-1)));return invoke(fn_572,args_571);}());
    // Zani.py:337
    if(([&]()->V{V compare_575=([&]()->V{V left_577=scope_524->get("current");V right_578=scope_524->get("start");return official::binary("-",left_577,right_578);}());V compare_576;V comparison_result_579;compare_576=V(0.35);comparison_result_579=compare_value("<",compare_575,compare_576);return comparison_result_579;}()).truth()){
        // Zani.py:338
        ([&]()->V{auto fn_581=attr(attr(self_value(),"logger"),"info");Args args_580;args_580.pos(V(std::string{}+"failed casting crisis_response_protocol, duration "+format_value(([&]()->V{V left_582=scope_524->get("current");V right_583=scope_524->get("start");return official::binary("-",left_582,right_583);}()),"",-1)));return invoke(fn_581,args_580);}());
        // Zani.py:339
        return V(false);
    }
    // Zani.py:340
    {V value_584=scope_524->get("current");set_attr(self_value(),"crisis_time",value_584);}
    // Zani.py:341
    return V(true);
return V{};
}),false);
// Official method Zani.get_forte, lines 343-349
register_method("get_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_585=bind_arguments(official_args,signature,captured);
scope_585->set("box",V::missing());
scope_585->set("forte_percent",V::missing());
    // Zani.py:344
    {V value_586=([&]()->V{auto fn_588=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_587;args_587.pos(V(3840LL));args_587.pos(V(2160LL));args_587.pos(V(1628LL));args_587.pos(V(1997LL));args_587.pos(V(2183LL));args_587.pos(V(2003LL));args_587.kw("name",V("zani_forte"));args_587.kw("hcenter",V(true));return invoke(fn_588,args_587);}());scope_585->set("box",value_586);}
    // Zani.py:345
    ([&]()->V{auto fn_590=attr(attr(self_value(),"task"),"draw_boxes");Args args_589;args_589.pos(attr(scope_585->get("box"),"name"));args_589.pos(scope_585->get("box"));return invoke(fn_590,args_589);}());
    // Zani.py:346
    {V value_591=([&]()->V{auto fn_593=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_592;args_592.pos(global("zani_forte_color","Zani"));args_592.pos(scope_585->get("box"));return invoke(fn_593,args_592);}());scope_585->set("forte_percent",value_591);}
    // Zani.py:347
    {V value_594=([&]()->V{auto fn_600=attr(([&]()->V{auto fn_596=global("Decimal","Zani");Args args_595;args_595.pos(([&]()->V{auto fn_598=global("str","Zani");Args args_597;args_597.pos(scope_585->get("forte_percent"));return invoke(fn_598,args_597);}()));return invoke(fn_596,args_595);}()),"quantize");Args args_599;args_599.pos(([&]()->V{auto fn_602=global("Decimal","Zani");Args args_601;args_601.pos(V("0.001"));return invoke(fn_602,args_601);}()));args_599.kw("rounding",global("ROUND_HALF_UP","Zani"));return invoke(fn_600,args_599);}());scope_585->set("forte_percent",value_594);}
    // Zani.py:348
    ([&]()->V{auto fn_604=attr(attr(self_value(),"logger"),"debug");Args args_603;args_603.pos(V(std::string{}+"forte_percent "+format_value(scope_585->get("forte_percent"),"",-1)));return invoke(fn_604,args_603);}());
    // Zani.py:349
    return scope_585->get("forte_percent");
return V{};
}),false);
// Official method Zani.check_forte_action, lines 351-377
register_method("check_forte_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_605=bind_arguments(official_args,signature,captured);
scope_605->set("last_check_time",V::missing());
scope_605->set("last_value",V::missing());
scope_605->set("pre_action",V::missing());
scope_605->set("start_time",V::missing());
scope_605->set("started_checking",V::missing());
    // Zani.py:352
    {V value_606=V::list({V(0LL)});scope_605->set("last_check_time",value_606);}
    // Zani.py:353
    {V value_607=V::list({unary("-",V(1LL))});scope_605->set("last_value",value_607);}
    // Zani.py:354
    {V value_608=V::list({V(false)});scope_605->set("started_checking",value_608);}
    // Zani.py:356
    scope_605->set("pre_action",V::function([this,captured=capture_scope(scope_605,{"last_check_time","last_value","start_time","started_checking"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_609=bind_arguments(official_args,signature,captured);
scope_609->set("current_time",V::missing());
scope_609->set("current_value",V::missing());
scope_609->set("elapsed",V::missing());
scope_609->set("gap",V::missing());
    // Zani.py:357
    {V value_610=([&]()->V{auto fn_612=attr(global("time","Zani"),"time");Args args_611;return invoke(fn_612,args_611);}());scope_609->set("current_time",value_610);}
    // Zani.py:358
    {V value_613=([&]()->V{V left_614=scope_609->get("current_time");V right_615=item(scope_609->get("start_time"),V(0LL));return official::binary("-",left_614,right_615);}());scope_609->set("elapsed",value_613);}
    // Zani.py:359
    if(([&]()->V{V compare_616=scope_609->get("elapsed");V compare_617;V comparison_result_618;compare_617=V(0.8);comparison_result_618=compare_value(">",compare_616,compare_617);return comparison_result_618;}()).truth()){
        // Zani.py:360
        {V value_619=V(true);set_item(scope_609->get("started_checking"),V(0LL),value_619);}
    }
    // Zani.py:361
    if(unary("not",item(scope_609->get("started_checking"),V(0LL))).truth()){
        // Zani.py:362
        return V(false);
    }
    // Zani.py:363
    if(([&]()->V{V compare_620=([&]()->V{V left_622=scope_609->get("current_time");V right_623=item(scope_609->get("last_check_time"),V(0LL));return official::binary("-",left_622,right_623);}());V compare_621;V comparison_result_624;compare_621=V(0.2);comparison_result_624=compare_value(">=",compare_620,compare_621);return comparison_result_624;}()).truth()){
        // Zani.py:364
        {V value_625=([&]()->V{auto fn_627=attr(self_value(),"get_forte");Args args_626;return invoke(fn_627,args_626);}());scope_609->set("current_value",value_625);}
        // Zani.py:365
        if(([&]()->V{V compare_628=item(scope_609->get("last_value"),V(0LL));V compare_629;V comparison_result_630;compare_629=V(0LL);comparison_result_630=compare_value(">",compare_628,compare_629);return comparison_result_630;}()).truth()){
            // Zani.py:366
            {V value_631=([&]()->V{V left_632=scope_609->get("current_value");V right_633=item(scope_609->get("last_value"),V(0LL));return official::binary("-",left_632,right_633);}());scope_609->set("gap",value_631);}
            // Zani.py:367
            ([&]()->V{auto fn_635=attr(attr(self_value(),"logger"),"info");Args args_634;args_634.pos(V(std::string{}+"check_forte gap: "+format_value(scope_609->get("gap"),"",-1)+" current_value: "+format_value(scope_609->get("current_value"),"",-1)));return invoke(fn_635,args_634);}());
            // Zani.py:368
            if(([&]()->V{V operand_636;operand_636=([&]()->V{V compare_637=scope_609->get("gap");V compare_638;V comparison_result_639;compare_638=V(0.01);comparison_result_639=compare_value("<",compare_637,compare_638);return comparison_result_639;}());if(!operand_636.truth())return operand_636;return unary("not",([&]()->V{auto fn_641=attr(self_value(),"is_e_forte_full");Args args_640;return invoke(fn_641,args_640);}()));}()).truth()){
                // Zani.py:369
                ([&]()->V{auto fn_643=attr(self_value(),"continues_right_click");Args args_642;args_642.pos(V(0.05));return invoke(fn_643,args_642);}());
                // Zani.py:370
                {V value_644=([&]()->V{auto fn_646=attr(global("time","Zani"),"time");Args args_645;return invoke(fn_646,args_645);}());set_attr(self_value(),"dodge_time",value_644);}
                // Zani.py:371
                return V(true);
            }
        }
        // Zani.py:372
        {V value_647=scope_609->get("current_value");set_item(scope_609->get("last_value"),V(0LL),value_647);}
        // Zani.py:373
        {V value_648=scope_609->get("current_time");set_item(scope_609->get("last_check_time"),V(0LL),value_648);}
    }
    // Zani.py:374
    return V(false);
return V{};
}));
    // Zani.py:376
    {V value_649=V::list({([&]()->V{auto fn_651=attr(global("time","Zani"),"time");Args args_650;return invoke(fn_651,args_650);}())});scope_605->set("start_time",value_649);}
    // Zani.py:377
    return scope_605->get("pre_action");
return V{};
}),false);
// Official method Zani.wait_forte_full, lines 379-400
register_method("wait_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"timeout",V(1LL)},{"send_click",V(false)},{"check_forte",V(false)},{"settle_time",V(0LL)}},"","",{})](const Args& official_args)->V{
auto scope_652=bind_arguments(official_args,signature,captured);
scope_652->set("kwargs",V::missing());
scope_652->set("pre_action_fn",V::missing());
scope_652->set("result",V::missing());
    // Zani.py:380
    if(([&]()->V{V compare_653=scope_652->get("timeout");V compare_654;V comparison_result_655;compare_654=V(0LL);comparison_result_655=compare_value("<=",compare_653,compare_654);return comparison_result_655;}()).truth()){
        // Zani.py:381
        return attr(global("State","Zani"),"DONE");
    }
    // Zani.py:382
    {V value_656=([&]()->V{V dictionary_657=V::dict();set_item(dictionary_657,V("condition"),attr(self_value(),"is_e_forte_full"));set_item(dictionary_657,V("condition2"),attr(self_value(),"flying"));set_item(dictionary_657,V("time_out"),scope_652->get("timeout"));set_item(dictionary_657,V("settle_time"),scope_652->get("settle_time"));return dictionary_657;}());scope_652->set("kwargs",value_656);}
    // Zani.py:388
    if(scope_652->get("send_click").truth()){
        // Zani.py:389
        {V value_658=attr(self_value(),"click_with_interval");set_item(scope_652->get("kwargs"),V("post_action"),value_658);}
    }
    // Zani.py:390
    if(scope_652->get("check_forte").truth()){
        // Zani.py:391
        {V value_659=([&]()->V{auto fn_661=attr(self_value(),"check_forte_action");Args args_660;return invoke(fn_661,args_660);}());scope_652->set("pre_action_fn",value_659);}
        // Zani.py:392
        {V value_662=V::function([this,captured=capture_scope(scope_652,{"pre_action_fn"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_663=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_664;operand_664=([&]()->V{auto fn_666=attr(self_value(),"flying");Args args_665;return invoke(fn_666,args_665);}());if(operand_664.truth())return operand_664;return ([&]()->V{auto fn_668=scope_663->get("pre_action_fn");Args args_667;return invoke(fn_668,args_667);}());}());
});set_item(scope_652->get("kwargs"),V("condition2"),value_662);}
    }
    // Zani.py:393
    {V value_669=([&]()->V{auto fn_671=attr(self_value(),"wait_until");Args args_670;args_670.spread_keywords(scope_652->get("kwargs"));return invoke(fn_671,args_670);}());scope_652->set("result",value_669);}
    // Zani.py:394
    if(([&]()->V{V compare_672=scope_652->get("result");V compare_673;V comparison_result_674;compare_673=attr(global("State","Zani"),"INTERRUPTED");comparison_result_674=compare_value("==",compare_672,compare_673);return comparison_result_674;}()).truth()){
    }else{
        // Zani.py:396
        if(scope_652->get("result").truth()){
            // Zani.py:397
            {V value_675=attr(global("State","Zani"),"FORTE_FULL");scope_652->set("result",value_675);}
        }else{
            // Zani.py:399
            {V value_676=attr(global("State","Zani"),"DONE");scope_652->set("result",value_676);}
        }
    }
    // Zani.py:400
    return scope_652->get("result");
return V{};
}),false);
// Official method Zani.wait_until, lines 402-426
register_method("wait_until",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"condition",V::missing()},{"condition2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_678=bind_arguments(official_args,signature,captured);
return V{};
})},{"post_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_679=bind_arguments(official_args,signature,captured);
return V{};
})},{"time_out",V(0LL)},{"settle_time",V(0LL)}},"","",{})](const Args& official_args)->V{
auto scope_677=bind_arguments(official_args,signature,captured);
scope_677->set("once",V::missing());
scope_677->set("stable_start",V::missing());
scope_677->set("start",V::missing());
    // Zani.py:404
    if(([&]()->V{V compare_680=scope_677->get("time_out");V compare_681;V comparison_result_682;compare_681=V(0LL);comparison_result_682=compare_value("<=",compare_680,compare_681);return comparison_result_682;}()).truth()){
        // Zani.py:405
        return V(false);
    }
    // Zani.py:406
    {V value_683=([&]()->V{auto fn_685=attr(global("time","Zani"),"time");Args args_684;return invoke(fn_685,args_684);}());scope_677->set("start",value_683);}
    // Zani.py:407
    {V value_686=V{};scope_677->set("stable_start",value_686);}
    // Zani.py:408
    {V value_687=V(true);scope_677->set("once",value_687);}
    // Zani.py:409
        while(([&]()->V{V compare_716=([&]()->V{V left_718=([&]()->V{auto fn_721=attr(global("time","Zani"),"time");Args args_720;return invoke(fn_721,args_720);}());V right_719=scope_677->get("start");return official::binary("-",left_718,right_719);}());V compare_717;V comparison_result_722;compare_717=scope_677->get("time_out");comparison_result_722=compare_value("<",compare_716,compare_717);return comparison_result_722;}()).truth()){
        // Zani.py:410
        if(([&]()->V{auto fn_689=scope_677->get("condition");Args args_688;return invoke(fn_689,args_688);}()).truth()){
            // Zani.py:411
            if(([&]()->V{V compare_690=scope_677->get("settle_time");V compare_691;V comparison_result_692;compare_691=V(0LL);comparison_result_692=compare_value("==",compare_690,compare_691);return comparison_result_692;}()).truth()){
                // Zani.py:412
                return V(true);
            }
            // Zani.py:413
            if(([&]()->V{V compare_693=scope_677->get("stable_start");V compare_694;V comparison_result_695;compare_694=V{};comparison_result_695=compare_value("is",compare_693,compare_694);return comparison_result_695;}()).truth()){
                // Zani.py:414
                {V value_696=([&]()->V{auto fn_698=attr(global("time","Zani"),"time");Args args_697;return invoke(fn_698,args_697);}());scope_677->set("stable_start",value_696);}
            }else{
                // Zani.py:415
                if(([&]()->V{V compare_699=([&]()->V{V left_701=([&]()->V{auto fn_704=attr(global("time","Zani"),"time");Args args_703;return invoke(fn_704,args_703);}());V right_702=scope_677->get("stable_start");return official::binary("-",left_701,right_702);}());V compare_700;V comparison_result_705;compare_700=scope_677->get("settle_time");comparison_result_705=compare_value(">=",compare_699,compare_700);return comparison_result_705;}()).truth()){
                    // Zani.py:416
                    return V(true);
                }
            }
        }else{
            // Zani.py:418
            {V value_706=V{};scope_677->set("stable_start",value_706);}
        }
        // Zani.py:419
        if(([&]()->V{auto fn_708=scope_677->get("condition2");Args args_707;return invoke(fn_708,args_707);}()).truth()){
            // Zani.py:420
            return attr(global("State","Zani"),"INTERRUPTED");
        }
        // Zani.py:421
        if(scope_677->get("once").truth()){
            // Zani.py:422
            ([&]()->V{auto fn_710=attr(self_value(),"check_combat");Args args_709;return invoke(fn_710,args_709);}());
            // Zani.py:423
            {V value_711=V(false);scope_677->set("once",value_711);}
        }
        // Zani.py:424
        ([&]()->V{auto fn_713=scope_677->get("post_action");Args args_712;return invoke(fn_713,args_712);}());
        // Zani.py:425
        ([&]()->V{auto fn_715=attr(attr(self_value(),"task"),"next_frame");Args args_714;return invoke(fn_715,args_714);}());
    }
    // Zani.py:426
    return V(false);
return V{};
}),false);
// Official method Zani.crisis_time_left, lines 428-433
register_method("crisis_time_left",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_723=bind_arguments(official_args,signature,captured);
scope_723->set("result",V::missing());
    // Zani.py:429
    if(([&]()->V{V compare_724=attr(self_value(),"crisis_time");V compare_725;V comparison_result_726;compare_725=V(0LL);comparison_result_726=compare_value("<=",compare_724,compare_725);return comparison_result_726;}()).truth()){
        // Zani.py:430
        return V(0LL);
    }
    // Zani.py:431
    {V value_727=([&]()->V{V left_728=V(1.6);V right_729=([&]()->V{auto fn_731=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_730;args_730.pos(attr(self_value(),"crisis_time"));args_730.kw("intro_motion_freeze",V(true));return invoke(fn_731,args_730);}());return official::binary("-",left_728,right_729);}());scope_723->set("result",value_727);}
    // Zani.py:432
    ([&]()->V{auto fn_733=attr(attr(self_value(),"logger"),"debug");Args args_732;args_732.pos(V(std::string{}+"crisis_time_left: "+format_value(scope_723->get("result"),"",-1)));return invoke(fn_733,args_732);}());
    // Zani.py:433
    return scope_723->get("result");
return V{};
}),false);
// Official method Zani.wait_crisis_protocol_end, lines 435-441
register_method("wait_crisis_protocol_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_734=bind_arguments(official_args,signature,captured);
    // Zani.py:436
    if(([&]()->V{V compare_735=([&]()->V{auto fn_738=attr(self_value(),"crisis_time_left");Args args_737;return invoke(fn_738,args_737);}());V compare_736;V comparison_result_739;compare_736=V(0LL);comparison_result_739=compare_value("<=",compare_735,compare_736);return comparison_result_739;}()).truth()){
        // Zani.py:437
        return attr(global("State","Zani"),"DONE");
    }
    // Zani.py:438
    if(([&]()->V{V operand_740;operand_740=([&]()->V{V compare_741=attr(self_value(),"last_res");V compare_742;V comparison_result_743;compare_742=V(0LL);comparison_result_743=compare_value(">",compare_741,compare_742);return comparison_result_743;}());if(!operand_740.truth())return operand_740;return ([&]()->V{V compare_744=([&]()->V{auto fn_747=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_746;args_746.pos(attr(self_value(),"last_res"));return invoke(fn_747,args_746);}());V compare_745;V comparison_result_748;compare_745=V(5LL);comparison_result_748=compare_value("<",compare_744,compare_745);return comparison_result_748;}());}()).truth()){
        // Zani.py:439
        ([&]()->V{auto fn_750=attr(self_value(),"wait_until");Args args_749;args_749.pos(V::function([this,captured=capture_scope(scope_734,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_751=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_752=([&]()->V{auto fn_755=attr(self_value(),"crisis_time_left");Args args_754;return invoke(fn_755,args_754);}());V compare_753;V comparison_result_756;compare_753=V(0LL);comparison_result_756=compare_value("<=",compare_752,compare_753);return comparison_result_756;}());
}));args_749.kw("time_out",V(2LL));return invoke(fn_750,args_749);}());
    }else{
        // Zani.py:441
        ([&]()->V{auto fn_758=attr(self_value(),"wait_resonance_not_gray");Args args_757;return invoke(fn_758,args_757);}());
    }
return V{};
}),false);
// Official method Zani.decide_teammate, lines 443-449
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_759=bind_arguments(official_args,signature,captured);
scope_759->set("Phoebe",V::missing());
scope_759->set("char",V::missing());
    // Zani.py:444
    scope_759->set("Phoebe",import_value("src.char.Phoebe","Phoebe"));
    // Zani.py:445
    if(([&]()->V{V assigned_760=([&]()->V{auto fn_762=attr(attr(self_value(),"task"),"has_char");Args args_761;args_761.pos(scope_759->get("Phoebe"));return invoke(fn_762,args_761);}());scope_759->set("char",assigned_760);return assigned_760;}()).truth()){
        // Zani.py:446
        {V value_763=scope_759->get("char");set_attr(self_value(),"char_phoebe",value_763);}
        // Zani.py:447
        {V value_764=V(0.6);set_attr(self_value(),"blazes_threshold",value_764);}
    }else{
        // Zani.py:449
        {V value_765=V(0.4);set_attr(self_value(),"blazes_threshold",value_765);}
    }
return V{};
}),false);
// Official method Zani.update_blazes, lines 451-456
register_method("update_blazes",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_766=bind_arguments(official_args,signature,captured);
scope_766->set("blazes_percent",V::missing());
scope_766->set("box",V::missing());
    // Zani.py:452
    {V value_767=([&]()->V{auto fn_769=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_768;args_768.pos(V(3840LL));args_768.pos(V(2160LL));args_768.pos(V(1627LL));args_768.pos(V(2014LL));args_768.pos(V(2176LL));args_768.pos(V(2017LL));args_768.kw("name",V("zani_blazes"));args_768.kw("hcenter",V(true));return invoke(fn_769,args_768);}());scope_766->set("box",value_767);}
    // Zani.py:453
    {V value_770=([&]()->V{auto fn_772=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_771;args_771.pos(global("zani_blazes_color","Zani"));args_771.pos(scope_766->get("box"));return invoke(fn_772,args_771);}());scope_766->set("blazes_percent",value_770);}
    // Zani.py:454
    {V value_773=([&]()->V{auto fn_779=attr(([&]()->V{auto fn_775=global("Decimal","Zani");Args args_774;args_774.pos(([&]()->V{auto fn_777=global("str","Zani");Args args_776;args_776.pos(scope_766->get("blazes_percent"));return invoke(fn_777,args_776);}()));return invoke(fn_775,args_774);}()),"quantize");Args args_778;args_778.pos(([&]()->V{auto fn_781=global("Decimal","Zani");Args args_780;args_780.pos(V("0.01"));return invoke(fn_781,args_780);}()));args_778.kw("rounding",global("ROUND_UP","Zani"));return invoke(fn_779,args_778);}());scope_766->set("blazes_percent",value_773);}
    // Zani.py:455
    {V value_782=scope_766->get("blazes_percent");set_attr(self_value(),"blazes",value_782);}
    // Zani.py:456
    ([&]()->V{auto fn_784=attr(attr(self_value(),"logger"),"debug");Args args_783;args_783.pos(V(std::string{}+"blazes_percent "+format_value(scope_766->get("blazes_percent"),"",-1)));return invoke(fn_784,args_783);}());
return V{};
}),false);
// Official method Zani.is_prepared, lines 458-468
register_method("is_prepared",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_785=bind_arguments(official_args,signature,captured);
    // Zani.py:459
    if(attr(self_value(),"is_current_char").truth()){
        // Zani.py:460
        ([&]()->V{auto fn_787=attr(self_value(),"update_blazes");Args args_786;return invoke(fn_787,args_786);}());
    }
    // Zani.py:461
    if(([&]()->V{V compare_788=attr(self_value(),"blazes");V compare_789;V comparison_result_790;compare_789=attr(self_value(),"blazes_threshold");comparison_result_790=compare_value(">=",compare_788,compare_789);return comparison_result_790;}()).truth()){
        // Zani.py:462
        return V(true);
    }
    // Zani.py:463
    if(([&]()->V{V operand_791;operand_791=([&]()->V{V compare_792=attr(self_value(),"char_phoebe");V compare_793;V comparison_result_794;compare_793=V{};comparison_result_794=compare_value("is not",compare_792,compare_793);return comparison_result_794;}());if(!operand_791.truth())return operand_791;operand_791=([&]()->V{V compare_795=item(attr(attr(self_value(),"char_phoebe"),"state"),V("outro"));V compare_796;V comparison_result_797;compare_796=V(1LL);comparison_result_797=compare_value(">=",compare_795,compare_796);return comparison_result_797;}());if(!operand_791.truth())return operand_791;return ([&]()->V{V compare_798=attr(self_value(),"blazes");V compare_799;V comparison_result_800;compare_799=V(0.4);comparison_result_800=compare_value(">=",compare_798,compare_799);return comparison_result_800;}());}()).truth()){
        // Zani.py:467
        return V(true);
    }
    // Zani.py:468
    return V(false);
return V{};
}),false);
// Official method Zani.wait_resonance_not_gray, lines 470-480
register_method("wait_resonance_not_gray",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"send_click",V(false)},{"liber_time_check",V(false)},{"timeout",V(2.5)}},"","",{})](const Args& official_args)->V{
auto scope_801=bind_arguments(official_args,signature,captured);
scope_801->set("kwargs",V::missing());
    // Zani.py:471
    {V value_802=([&]()->V{V dictionary_803=V::dict();set_item(dictionary_803,V("condition"),V::function([this,captured=capture_scope(scope_801,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_804=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_805=([&]()->V{auto fn_808=attr(self_value(),"current_resonance");Args args_807;return invoke(fn_808,args_807);}());V compare_806;V comparison_result_809;compare_806=V(0LL);comparison_result_809=compare_value("!=",compare_805,compare_806);return comparison_result_809;}());
}));set_item(dictionary_803,V("time_out"),scope_801->get("timeout"));set_item(dictionary_803,V("settle_time"),V(0.1));return dictionary_803;}());scope_801->set("kwargs",value_802);}
    // Zani.py:476
    if(scope_801->get("send_click").truth()){
        // Zani.py:477
        {V value_810=attr(self_value(),"click_with_interval");set_item(scope_801->get("kwargs"),V("post_action"),value_810);}
    }
    // Zani.py:478
    if(scope_801->get("liber_time_check").truth()){
        // Zani.py:479
        {V value_811=V::function([this,captured=capture_scope(scope_801,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_812=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_813=([&]()->V{auto fn_816=attr(self_value(),"liberation_time_left");Args args_815;return invoke(fn_816,args_815);}());V compare_814;V comparison_result_817;compare_814=V(1.7);comparison_result_817=compare_value("<",compare_813,compare_814);return comparison_result_817;}());
});set_item(scope_801->get("kwargs"),V("condition2"),value_811);}
    }
    // Zani.py:480
    ([&]()->V{auto fn_819=attr(self_value(),"wait_until");Args args_818;args_818.spread_keywords(scope_801->get("kwargs"));return invoke(fn_819,args_818);}());
return V{};
}),false);
// Official method Zani.get_switch_priority, lines 482-487
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_820=bind_arguments(official_args,signature,captured);
    // Zani.py:483
    if(attr(self_value(),"in_liberation").truth()){
        // Zani.py:484
        return attr(global("SwitchPriority","Zani"),"MUST");
    }
    // Zani.py:485
    if(([&]()->V{V operand_821;operand_821=scope_820->get("has_intro");if(!operand_821.truth())return operand_821;return ([&]()->V{V compare_822=([&]()->V{auto fn_825=attr(self_value(),"crisis_time_left");Args args_824;return invoke(fn_825,args_824);}());V compare_823;V comparison_result_826;compare_823=V(0LL);comparison_result_826=compare_value(">",compare_822,compare_823);return comparison_result_826;}());}()).truth()){
        // Zani.py:486
        return attr(global("SwitchPriority","Zani"),"NO");
    }
    // Zani.py:487
    return ([&]()->V{auto fn_830=attr(([&]()->V{auto fn_828=global("super","Zani");Args args_827;return invoke(fn_828,args_827);}()),"get_switch_priority");Args args_829;args_829.pos(scope_820->get("current_char"));args_829.pos(scope_820->get("has_intro"));args_829.pos(scope_820->get("target_low_con"));return invoke(fn_830,args_829);}());
return V{};
}),false);
// Official method Zani.wait_switch, lines 489-494
register_method("wait_switch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_831=bind_arguments(official_args,signature,captured);
    // Zani.py:490
    if(([&]()->V{V operand_832;operand_832=attr(self_value(),"has_intro");if(!operand_832.truth())return operand_832;return ([&]()->V{V compare_833=([&]()->V{auto fn_836=attr(self_value(),"nightfall_time_left");Args args_835;return invoke(fn_836,args_835);}());V compare_834;V comparison_result_837;compare_834=V(0LL);comparison_result_837=compare_value(">",compare_833,compare_834);return comparison_result_837;}());}()).truth()){
        // Zani.py:491
        ([&]()->V{auto fn_839=attr(attr(self_value(),"logger"),"debug");Args args_838;args_838.pos(V(std::string{}+"has_intro "+format_value(attr(self_value(),"has_intro"),"",-1)+", wait nightfall end"));return invoke(fn_839,args_838);}());
        // Zani.py:492
        if(([&]()->V{V operand_840;operand_840=([&]()->V{V compare_841=([&]()->V{auto fn_844=attr(self_value(),"nightfall_time_left");Args args_843;return invoke(fn_844,args_843);}());V compare_842;V comparison_result_845;compare_842=V(0LL);comparison_result_845=compare_value(">",compare_841,compare_842);return comparison_result_845;}());if(!operand_840.truth())return operand_840;return ([&]()->V{V compare_846=([&]()->V{auto fn_849=attr(self_value(),"liberation_time_left");Args args_848;return invoke(fn_849,args_848);}());V compare_847;V comparison_result_850;compare_847=V(2LL);comparison_result_850=compare_value(">=",compare_846,compare_847);return comparison_result_850;}());}()).truth()){
            // Zani.py:493
            return V(true);
        }
    }
    // Zani.py:494
    return V(false);
return V{};
}),false);
// Official method Zani.check_liber, lines 496-505
register_method("check_liber",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_851=bind_arguments(official_args,signature,captured);
scope_851->set("liber_box",V::missing());
scope_851->set("not_liber_box",V::missing());
    // Zani.py:497
    if(unary("not",([&]()->V{auto fn_853=attr(attr(self_value(),"task"),"in_team_and_world");Args args_852;return invoke(fn_853,args_852);}())).truth()){
        // Zani.py:498
        return attr(self_value(),"in_liberation");
    }
    // Zani.py:499
    {V value_854=([&]()->V{auto fn_856=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_855;args_855.pos(V(2560LL));args_855.pos(V(1440LL));args_855.pos(V(1909LL));args_855.pos(V(1274LL));args_855.pos(V(1957LL));args_855.pos(V(1322LL));args_855.kw("name",V("zani_not_liber_box"));args_855.kw("hcenter",V(true));return invoke(fn_856,args_855);}());scope_851->set("not_liber_box",value_854);}
    // Zani.py:500
    {V value_857=([&]()->V{auto fn_859=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_858;args_858.pos(V(2560LL));args_858.pos(V(1440LL));args_858.pos(V(1779LL));args_858.pos(V(1273LL));args_858.pos(V(1830LL));args_858.pos(V(1322LL));args_858.kw("name",V("zani_liber_box"));args_858.kw("hcenter",V(true));return invoke(fn_859,args_858);}());scope_851->set("liber_box",value_857);}
    // Zani.py:501
    if(([&]()->V{auto fn_861=attr(attr(self_value(),"task"),"find_one");Args args_860;args_860.pos(V("box_target_enemy_inner"));args_860.kw("box",scope_851->get("not_liber_box"));args_860.kw("threshold",V(0.75));return invoke(fn_861,args_860);}()).truth()){
        // Zani.py:502
        {V value_862=V(false);set_attr(self_value(),"in_liberation",value_862);}
    }else{
        // Zani.py:503
        if(([&]()->V{auto fn_864=attr(attr(self_value(),"task"),"find_one");Args args_863;args_863.pos(V("box_target_enemy_inner"));args_863.kw("box",scope_851->get("liber_box"));args_863.kw("threshold",V(0.75));return invoke(fn_864,args_863);}()).truth()){
            // Zani.py:504
            {V value_865=V(true);set_attr(self_value(),"in_liberation",value_865);}
        }
    }
    // Zani.py:505
    return attr(self_value(),"in_liberation");
return V{};
}),false);
// Official method Zani.get_state, lines 507-511
register_method("get_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_866=bind_arguments(official_args,signature,captured);
    // Zani.py:508
    if(([&]()->V{V operand_867;operand_867=([&]()->V{V compare_868=attr(self_value(),"state");V compare_869;V comparison_result_870;compare_869=V(1LL);comparison_result_870=compare_value("==",compare_868,compare_869);return comparison_result_870;}());if(!operand_867.truth())return operand_867;return ([&]()->V{V compare_871=([&]()->V{auto fn_874=attr(self_value(),"liberation_time_left");Args args_873;return invoke(fn_874,args_873);}());V compare_872;V comparison_result_875;compare_872=V(0LL);comparison_result_875=compare_value("<=",compare_871,compare_872);return comparison_result_875;}());}()).truth()){
        // Zani.py:509
        {V value_876=unary("-",V(1LL));set_attr(self_value(),"blazes",value_876);}
        // Zani.py:510
        {V value_877=V(0LL);set_attr(self_value(),"state",value_877);}
    }
    // Zani.py:511
    return attr(self_value(),"state");
return V{};
}),false);
}
