#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Ciaccona.py
// SHA256 e3dffbf5fa56ceee7948ede66f74b72a7f5b3f650f9c37acb5968403cb5d2a2f
void OfficialCharacter::install_Ciaccona(){
auto scope=std::make_shared<Scope>();
set_global("ciaccona_forte_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(70LL),V(100LL)}));set_item(dictionary_1,V("g"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_1,V("b"),V::tuple({V(180LL),V(210LL)}));return dictionary_1;}()));
// Official method Ciaccona.__init__, lines 10-18
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:11
    ([&]()->V{auto fn_6=attr(([&]()->V{auto fn_4=global("super","Ciaccona");Args args_3;return invoke(fn_4,args_3);}()),"__init__");Args args_5;args_5.spread(scope_2->get("args"));args_5.spread_keywords(scope_2->get("kwargs"));return invoke(fn_6,args_5);}());
    // Ciaccona.py:12
    {V value_7=V(0.73);set_attr(self_value(),"intro_motion_freeze_duration",value_7);}
    // Ciaccona.py:13
    {V value_8=V(0LL);set_attr(self_value(),"attribute",value_8);}
    // Ciaccona.py:14
    {V value_9=V(false);set_attr(self_value(),"in_liberation",value_9);}
    // Ciaccona.py:15
    {V value_10=V{};set_attr(self_value(),"cartethyia",value_10);}
    // Ciaccona.py:16
    {V value_11=unary("-",V(1LL));set_attr(self_value(),"outrotime",value_11);}
    // Ciaccona.py:18
    {V value_12=V(false);set_attr(self_value(),"recital_on_field",value_12);}
return V{};
}),false);
// Official method Ciaccona.skip_combat_check, lines 20-21
register_method("skip_combat_check",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_13=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:21
    return ([&]()->V{V compare_14=([&]()->V{auto fn_17=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_16;args_16.pos(attr(self_value(),"last_liberation"));return invoke(fn_17,args_16);}());V compare_15;V comparison_result_18;compare_15=V(2LL);comparison_result_18=compare_value("<",compare_14,compare_15);return comparison_result_18;}());
return V{};
}),false);
// Official method Ciaccona.reset_state, lines 23-27
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_19=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:24
    ([&]()->V{auto fn_23=attr(([&]()->V{auto fn_21=global("super","Ciaccona");Args args_20;return invoke(fn_21,args_20);}()),"reset_state");Args args_22;return invoke(fn_23,args_22);}());
    // Ciaccona.py:25
    {V value_24=V(0LL);set_attr(self_value(),"attribute",value_24);}
    // Ciaccona.py:26
    {V value_25=V{};set_attr(self_value(),"cartethyia",value_25);}
    // Ciaccona.py:27
    {V value_26=V(false);set_attr(self_value(),"recital_on_field",value_26);}
return V{};
}),false);
// Official method Ciaccona.do_perform, lines 29-67
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_27=bind_arguments(official_args,signature,captured);
scope_27->set("jump",V::missing());
scope_27->set("start",V::missing());
scope_27->set("wait",V::missing());
    // Ciaccona.py:30
    {V value_28=V(false);set_attr(self_value(),"in_liberation",value_28);}
    // Ciaccona.py:31
    {V value_29=V(false);scope_27->set("wait",value_29);}
    // Ciaccona.py:32
    {V value_30=V(true);scope_27->set("jump",value_30);}
    // Ciaccona.py:33
    if(([&]()->V{V compare_31=attr(self_value(),"attribute");V compare_32;V comparison_result_33;compare_32=V(0LL);comparison_result_33=compare_value("==",compare_31,compare_32);return comparison_result_33;}()).truth()){
        // Ciaccona.py:34
        ([&]()->V{auto fn_35=attr(self_value(),"decide_teammate");Args args_34;return invoke(fn_35,args_34);}());
    }
    // Ciaccona.py:35
    if(attr(self_value(),"has_intro").truth()){
        // Ciaccona.py:36
        ([&]()->V{auto fn_37=attr(self_value(),"continues_normal_attack");Args args_36;args_36.pos(V(0.8));return invoke(fn_37,args_36);}());
        // Ciaccona.py:37
        if(unary("not",([&]()->V{auto fn_39=attr(self_value(),"need_fast_perform");Args args_38;return invoke(fn_39,args_38);}())).truth()){
            // Ciaccona.py:38
            ([&]()->V{auto fn_41=attr(self_value(),"continues_normal_attack");Args args_40;args_40.pos(V(0.7));return invoke(fn_41,args_40);}());
        }
    }
    // Ciaccona.py:39
    if(([&]()->V{V compare_42=([&]()->V{auto fn_45=attr(self_value(),"current_echo");Args args_44;return invoke(fn_45,args_44);}());V compare_43;V comparison_result_46;compare_43=V(0.22);comparison_result_46=compare_value("<",compare_42,compare_43);return comparison_result_46;}()).truth()){
        // Ciaccona.py:40
        ([&]()->V{auto fn_48=attr(self_value(),"click_echo");Args args_47;args_47.kw("time_out",V(0LL));return invoke(fn_48,args_47);}());
    }
    // Ciaccona.py:41
    if(([&]()->V{V operand_49;operand_49=unary("not",attr(self_value(),"has_intro"));if(!operand_49.truth())return operand_49;operand_49=unary("not",([&]()->V{auto fn_51=attr(self_value(),"need_fast_perform");Args args_50;return invoke(fn_51,args_50);}()));if(!operand_49.truth())return operand_49;return unary("not",([&]()->V{auto fn_53=attr(self_value(),"is_mouse_forte_full");Args args_52;return invoke(fn_53,args_52);}()));}()).truth()){
        // Ciaccona.py:42
        ([&]()->V{auto fn_55=attr(self_value(),"click_jump_with_click");Args args_54;args_54.pos(V(0.4));return invoke(fn_55,args_54);}());
        // Ciaccona.py:43
        ([&]()->V{auto fn_57=attr(attr(self_value(),"task"),"wait_until");Args args_56;args_56.pos(V::function([this,captured=capture_scope(scope_27,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_58=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_60=attr(self_value(),"flying");Args args_59;return invoke(fn_60,args_59);}()));
}));args_56.kw("post_action",attr(self_value(),"click_with_interval"));args_56.kw("time_out",V(1.2));return invoke(fn_57,args_56);}());
        // Ciaccona.py:44
        ([&]()->V{auto fn_62=attr(self_value(),"continues_normal_attack");Args args_61;args_61.pos(V(0.2));return invoke(fn_62,args_61);}());
    }
    // Ciaccona.py:45
    if(item(([&]()->V{auto fn_64=attr(self_value(),"click_resonance");Args args_63;return invoke(fn_64,args_63);}()),V(0LL)).truth()){
        // Ciaccona.py:46
        {V value_65=V(false);scope_27->set("jump",value_65);}
        // Ciaccona.py:47
        {V value_66=V(true);scope_27->set("wait",value_66);}
    }
    // Ciaccona.py:48
    if(([&]()->V{V compare_67=([&]()->V{auto fn_70=attr(self_value(),"judge_forte");Args args_69;return invoke(fn_70,args_69);}());V compare_68;V comparison_result_71;compare_68=V(3LL);comparison_result_71=compare_value(">=",compare_67,compare_68);return comparison_result_71;}()).truth()){
        // Ciaccona.py:49
        if(scope_27->get("jump").truth()){
            // Ciaccona.py:50
            {V value_72=([&]()->V{auto fn_74=attr(global("time","Ciaccona"),"time");Args args_73;return invoke(fn_74,args_73);}());scope_27->set("start",value_72);}
            // Ciaccona.py:51
                        while(unary("not",([&]()->V{auto fn_87=attr(self_value(),"flying");Args args_86;return invoke(fn_87,args_86);}())).truth()){
                // Ciaccona.py:52
                ([&]()->V{auto fn_76=attr(attr(self_value(),"task"),"jump");Args args_75;args_75.kw("after_sleep",V(0.01));return invoke(fn_76,args_75);}());
                // Ciaccona.py:53
                if(([&]()->V{V compare_77=([&]()->V{V left_79=([&]()->V{auto fn_82=attr(global("time","Ciaccona"),"time");Args args_81;return invoke(fn_82,args_81);}());V right_80=scope_27->get("start");return official::binary("-",left_79,right_80);}());V compare_78;V comparison_result_83;compare_78=V(0.3);comparison_result_83=compare_value(">",compare_77,compare_78);return comparison_result_83;}()).truth()){
                    // Ciaccona.py:54
                    break;
                }
                // Ciaccona.py:55
                ([&]()->V{auto fn_85=attr(attr(self_value(),"task"),"next_frame");Args args_84;return invoke(fn_85,args_84);}());
            }
        }
        // Ciaccona.py:56
        ([&]()->V{auto fn_89=attr(self_value(),"heavy_click_forte");Args args_88;args_88.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_89,args_88);}());
        // Ciaccona.py:57
        {V value_90=V(true);scope_27->set("wait",value_90);}
    }
    // Ciaccona.py:58
    if(([&]()->V{auto fn_92=attr(self_value(),"liberation_available");Args args_91;return invoke(fn_92,args_91);}()).truth()){
        // Ciaccona.py:59
        if(scope_27->get("wait").truth()){
            // Ciaccona.py:60
            ([&]()->V{auto fn_94=attr(self_value(),"sleep");Args args_93;args_93.pos(V(0.4));return invoke(fn_94,args_93);}());
        }
        // Ciaccona.py:61
        if(([&]()->V{auto fn_96=attr(self_value(),"click_liberation");Args args_95;return invoke(fn_96,args_95);}()).truth()){
            // Ciaccona.py:62
            {V value_97=V(true);set_attr(self_value(),"in_liberation",value_97);}
            // Ciaccona.py:63
            if(([&]()->V{V compare_98=attr(self_value(),"attribute");V compare_99;V comparison_result_100;compare_99=V(2LL);comparison_result_100=compare_value("==",compare_98,compare_99);return comparison_result_100;}()).truth()){
                // Ciaccona.py:64
                ([&]()->V{auto fn_102=attr(self_value(),"continues_click_a");Args args_101;args_101.pos(V(0.6));return invoke(fn_102,args_101);}());
            }
        }
    }
    // Ciaccona.py:65
    if(([&]()->V{V operand_103;operand_103=unary("not",attr(self_value(),"in_liberation"));if(!operand_103.truth())return operand_103;return ([&]()->V{V compare_104=([&]()->V{auto fn_107=attr(self_value(),"current_echo");Args args_106;return invoke(fn_107,args_106);}());V compare_105;V comparison_result_108;compare_105=V(0.25);comparison_result_108=compare_value(">",compare_104,compare_105);return comparison_result_108;}());}()).truth()){
        // Ciaccona.py:66
        ([&]()->V{auto fn_110=attr(self_value(),"click_echo");Args args_109;return invoke(fn_110,args_109);}());
    }
    // Ciaccona.py:67
    ([&]()->V{auto fn_112=attr(self_value(),"switch_next_char");Args args_111;return invoke(fn_112,args_111);}());
return V{};
}),false);
// Official method Ciaccona.get_switch_priority, lines 69-78
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_113=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:70
    if(([&]()->V{V operand_114;operand_114=([&]()->V{V compare_115=attr(self_value(),"attribute");V compare_116;V comparison_result_117;compare_116=V(2LL);comparison_result_117=compare_value("==",compare_115,compare_116);return comparison_result_117;}());if(!operand_114.truth())return operand_114;operand_114=attr(self_value(),"in_liberation");if(!operand_114.truth())return operand_114;return ([&]()->V{V compare_118=([&]()->V{auto fn_121=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_120;args_120.pos(attr(self_value(),"last_liberation"));return invoke(fn_121,args_120);}());V compare_119;V comparison_result_122;compare_119=V(20LL);comparison_result_122=compare_value("<",compare_118,compare_119);return comparison_result_122;}());}()).truth()){
        // Ciaccona.py:72
        return attr(global("SwitchPriority","Ciaccona"),"NO");
    }
    // Ciaccona.py:73
    if(([&]()->V{V compare_123=attr(self_value(),"attribute");V compare_124;V comparison_result_125;compare_124=V(3LL);comparison_result_125=compare_value("==",compare_123,compare_124);return comparison_result_125;}()).truth()){
        // Ciaccona.py:74
        ([&]()->V{auto fn_127=attr(attr(self_value(),"logger"),"debug");Args args_126;args_126.pos(V(std::string{}+"ciaccona cond: "+format_value(attr(attr(self_value(),"cartethyia"),"is_cartethyia"),"",-1)));return invoke(fn_127,args_126);}());
    }
    // Ciaccona.py:75
    if(([&]()->V{V operand_128;operand_128=([&]()->V{V compare_129=attr(self_value(),"attribute");V compare_130;V comparison_result_131;compare_130=V(3LL);comparison_result_131=compare_value("==",compare_129,compare_130);return comparison_result_131;}());if(!operand_128.truth())return operand_128;operand_128=attr(self_value(),"in_liberation");if(!operand_128.truth())return operand_128;return ([&]()->V{V operand_132;operand_132=([&]()->V{V compare_133=([&]()->V{auto fn_136=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_135;args_135.pos(attr(self_value(),"last_liberation"));return invoke(fn_136,args_135);}());V compare_134;V comparison_result_137;compare_134=V(8LL);comparison_result_137=compare_value("<",compare_133,compare_134);return comparison_result_137;}());if(operand_132.truth())return operand_132;return unary("not",attr(attr(self_value(),"cartethyia"),"is_cartethyia"));}());}()).truth()){
        // Ciaccona.py:77
        return attr(global("SwitchPriority","Ciaccona"),"NO");
    }
    // Ciaccona.py:78
    return ([&]()->V{auto fn_141=attr(([&]()->V{auto fn_139=global("super","Ciaccona");Args args_138;return invoke(fn_139,args_138);}()),"get_switch_priority");Args args_140;args_140.pos(scope_113->get("current_char"));args_140.pos(scope_113->get("has_intro"));args_140.pos(scope_113->get("target_low_con"));return invoke(fn_141,args_140);}());
return V{};
}),false);
// Official method Ciaccona.click_jump_with_click, lines 80-92
register_method("click_jump_with_click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"delay",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_142=bind_arguments(official_args,signature,captured);
scope_142->set("click",V::missing());
scope_142->set("start",V::missing());
    // Ciaccona.py:81
    {V value_143=([&]()->V{auto fn_145=attr(global("time","Ciaccona"),"time");Args args_144;return invoke(fn_145,args_144);}());scope_142->set("start",value_143);}
    // Ciaccona.py:82
    {V value_146=V(1LL);scope_142->set("click",value_146);}
    // Ciaccona.py:83
        while(V(true).truth()){
        // Ciaccona.py:84
        if(([&]()->V{V compare_147=([&]()->V{V left_149=([&]()->V{auto fn_152=attr(global("time","Ciaccona"),"time");Args args_151;return invoke(fn_152,args_151);}());V right_150=scope_142->get("start");return official::binary("-",left_149,right_150);}());V compare_148;V comparison_result_153;compare_148=scope_142->get("delay");comparison_result_153=compare_value(">",compare_147,compare_148);return comparison_result_153;}()).truth()){
            // Ciaccona.py:85
            break;
        }
        // Ciaccona.py:86
        if(([&]()->V{V compare_154=scope_142->get("click");V compare_155;V comparison_result_156;compare_155=V(0LL);comparison_result_156=compare_value("==",compare_154,compare_155);return comparison_result_156;}()).truth()){
            // Ciaccona.py:87
            ([&]()->V{auto fn_158=attr(attr(self_value(),"task"),"jump");Args args_157;args_157.kw("after_sleep",V(0.01));return invoke(fn_158,args_157);}());
        }else{
            // Ciaccona.py:89
            ([&]()->V{auto fn_160=attr(self_value(),"click");Args args_159;return invoke(fn_160,args_159);}());
        }
        // Ciaccona.py:90
        {V value_161=([&]()->V{V left_162=V(1LL);V right_163=scope_142->get("click");return official::binary("-",left_162,right_163);}());scope_142->set("click",value_161);}
        // Ciaccona.py:91
        ([&]()->V{auto fn_165=attr(self_value(),"check_combat");Args args_164;return invoke(fn_165,args_164);}());
        // Ciaccona.py:92
        ([&]()->V{auto fn_167=attr(attr(self_value(),"task"),"next_frame");Args args_166;return invoke(fn_167,args_166);}());
    }
return V{};
}),false);
// Official method Ciaccona.continues_click_a, lines 94-97
register_method("continues_click_a",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V(0.6)}},"","",{})](const Args& official_args)->V{
auto scope_168=bind_arguments(official_args,signature,captured);
scope_168->set("start",V::missing());
    // Ciaccona.py:95
    {V value_169=([&]()->V{auto fn_171=attr(global("time","Ciaccona"),"time");Args args_170;return invoke(fn_171,args_170);}());scope_168->set("start",value_169);}
    // Ciaccona.py:96
        while(([&]()->V{V compare_174=([&]()->V{V left_176=([&]()->V{auto fn_179=attr(global("time","Ciaccona"),"time");Args args_178;return invoke(fn_179,args_178);}());V right_177=scope_168->get("start");return official::binary("-",left_176,right_177);}());V compare_175;V comparison_result_180;compare_175=scope_168->get("duration");comparison_result_180=compare_value("<",compare_174,compare_175);return comparison_result_180;}()).truth()){
        // Ciaccona.py:97
        ([&]()->V{auto fn_173=attr(attr(self_value(),"task"),"send_key");Args args_172;args_172.kw("key",V("a"));return invoke(fn_173,args_172);}());
    }
return V{};
}),false);
// Official method Ciaccona.judge_forte, lines 99-104
register_method("judge_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_181=bind_arguments(official_args,signature,captured);
scope_181->set("box",V::missing());
scope_181->set("forte",V::missing());
    // Ciaccona.py:100
    if(([&]()->V{auto fn_183=attr(self_value(),"is_mouse_forte_full");Args args_182;return invoke(fn_183,args_182);}()).truth()){
        // Ciaccona.py:101
        return V(3LL);
    }
    // Ciaccona.py:102
    {V value_184=([&]()->V{auto fn_186=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_185;args_185.pos(V(3840LL));args_185.pos(V(2160LL));args_185.pos(V(1612LL));args_185.pos(V(1987LL));args_185.pos(V(2188LL));args_185.pos(V(2008LL));args_185.kw("name",V("ciaccona_forte"));args_185.kw("hcenter",V(true));return invoke(fn_186,args_185);}());scope_181->set("box",value_184);}
    // Ciaccona.py:103
    {V value_187=([&]()->V{auto fn_189=attr(self_value(),"calculate_forte_num");Args args_188;args_188.pos(global("ciaccona_forte_color","Ciaccona"));args_188.pos(scope_181->get("box"));args_188.pos(V(3LL));args_188.pos(V(12LL));args_188.pos(V(14LL));args_188.pos(V(100LL));return invoke(fn_189,args_188);}());scope_181->set("forte",value_187);}
    // Ciaccona.py:104
    return scope_181->get("forte");
return V{};
}),false);
// Official method Ciaccona.decide_teammate, lines 106-123
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_190=bind_arguments(official_args,signature,captured);
scope_190->set("Cartethyia",V::missing());
scope_190->set("Phoebe",V::missing());
scope_190->set("Zani",V::missing());
scope_190->set("char",V::missing());
scope_190->set("i",V::missing());
    // Ciaccona.py:107
    scope_190->set("Phoebe",import_value("src.char.Phoebe","Phoebe"));
    // Ciaccona.py:108
    scope_190->set("Zani",import_value("src.char.Zani","Zani"));
    // Ciaccona.py:109
    scope_190->set("Cartethyia",import_value("src.char.Cartethyia","Cartethyia"));
    // Ciaccona.py:110
    {auto iterator_191=official::iterate(([&]()->V{auto fn_207=global("enumerate","Ciaccona");Args args_206;args_206.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_207,args_206);}()));V item_192;while(iterator_191.next(item_192)){
        auto unpack_208=unpack(item_192,2);scope_190->set("i",unpack_208[0]);scope_190->set("char",unpack_208[1]);
        // Ciaccona.py:111
        ([&]()->V{auto fn_194=attr(attr(self_value(),"logger"),"debug");Args args_193;args_193.pos(V(std::string{}+"ciaccona teammate char: "+format_value(attr(scope_190->get("char"),"char_name"),"",-1)));return invoke(fn_194,args_193);}());
        // Ciaccona.py:112
        if(([&]()->V{auto fn_196=global("isinstance","Ciaccona");Args args_195;args_195.pos(scope_190->get("char"));args_195.pos(scope_190->get("Cartethyia"));return invoke(fn_196,args_195);}()).truth()){
            // Ciaccona.py:113
            ([&]()->V{auto fn_198=attr(attr(self_value(),"logger"),"debug");Args args_197;args_197.pos(V("ciaccona set attribute: wind dot"));return invoke(fn_198,args_197);}());
            // Ciaccona.py:114
            {V value_199=scope_190->get("char");set_attr(self_value(),"cartethyia",value_199);}
            // Ciaccona.py:115
            {V value_200=V(3LL);set_attr(self_value(),"attribute",value_200);}
            // Ciaccona.py:116
            return V{};
        }
        // Ciaccona.py:117
        if(([&]()->V{auto fn_202=global("isinstance","Ciaccona");Args args_201;args_201.pos(scope_190->get("char"));args_201.pos(V::tuple({scope_190->get("Phoebe"),scope_190->get("Zani")}));return invoke(fn_202,args_201);}()).truth()){
            // Ciaccona.py:118
            ([&]()->V{auto fn_204=attr(attr(self_value(),"logger"),"debug");Args args_203;args_203.pos(V("ciaccona set attribute: light dot"));return invoke(fn_204,args_203);}());
            // Ciaccona.py:119
            {V value_205=V(2LL);set_attr(self_value(),"attribute",value_205);}
            // Ciaccona.py:120
            return V{};
        }
    }
    }
    // Ciaccona.py:121
    ([&]()->V{auto fn_210=attr(attr(self_value(),"logger"),"debug");Args args_209;args_209.pos(V("ciaccona set attribute: wind dot"));return invoke(fn_210,args_209);}());
    // Ciaccona.py:122
    {V value_211=V(1LL);set_attr(self_value(),"attribute",value_211);}
    // Ciaccona.py:123
    return V{};
return V{};
}),false);
// Official method Ciaccona.judge_frequncy_and_amplitude, lines 125-141
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_212=bind_arguments(official_args,signature,captured);
scope_212->set("amplitude",V::missing());
scope_212->set("frequncy",V::missing());
scope_212->set("height",V::missing());
scope_212->set("i",V::missing());
scope_212->set("n",V::missing());
scope_212->set("profile",V::missing());
scope_212->set("width",V::missing());
    // Ciaccona.py:126
    {V value_213=item(attr(scope_212->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_214=unpack(value_213,2);scope_212->set("height",unpack_214[0]);scope_212->set("width",unpack_214[1]);}
    // Ciaccona.py:127
    if(([&]()->V{V operand_215;operand_215=([&]()->V{V compare_216=scope_212->get("height");V compare_217;V comparison_result_218;compare_217=V(0LL);comparison_result_218=compare_value("==",compare_216,compare_217);return comparison_result_218;}());if(operand_215.truth())return operand_215;operand_215=([&]()->V{V compare_219=scope_212->get("width");V compare_220;V comparison_result_221;compare_220=V(64LL);comparison_result_221=compare_value("<",compare_219,compare_220);return comparison_result_221;}());if(operand_215.truth())return operand_215;return unary("not",([&]()->V{auto fn_223=attr(global("np","Ciaccona"),"array_equal");Args args_222;args_222.pos(([&]()->V{auto fn_225=attr(global("np","Ciaccona"),"unique");Args args_224;args_224.pos(scope_212->get("gray"));return invoke(fn_225,args_224);}()));args_222.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_223,args_222);}()));}()).truth()){
        // Ciaccona.py:128
        return V(0LL);
    }
    // Ciaccona.py:129
    {V value_226=([&]()->V{auto fn_233=attr(([&]()->V{auto fn_228=attr(global("np","Ciaccona"),"sum");Args args_227;args_227.pos(([&]()->V{V compare_229=scope_212->get("gray");V compare_230;V comparison_result_231;compare_230=V(255LL);comparison_result_231=compare_value("==",compare_229,compare_230);return comparison_result_231;}()));args_227.kw("axis",V(0LL));return invoke(fn_228,args_227);}()),"astype");Args args_232;args_232.pos(attr(global("np","Ciaccona"),"float32"));return invoke(fn_233,args_232);}());scope_212->set("profile",value_226);}
    // Ciaccona.py:130
    scope_212->set("profile",official::binary("-",scope_212->get("profile"),([&]()->V{auto fn_235=attr(global("np","Ciaccona"),"mean");Args args_234;args_234.pos(scope_212->get("profile"));return invoke(fn_235,args_234);}())));
    // Ciaccona.py:131
    {V value_236=([&]()->V{auto fn_238=attr(global("np","Ciaccona"),"abs");Args args_237;args_237.pos(([&]()->V{auto fn_240=attr(attr(global("np","Ciaccona"),"fft"),"fft");Args args_239;args_239.pos(scope_212->get("profile"));return invoke(fn_240,args_239);}()));return invoke(fn_238,args_237);}());scope_212->set("n",value_236);}
    // Ciaccona.py:132
    {V value_241=V(0LL);scope_212->set("amplitude",value_241);}
    // Ciaccona.py:133
    {V value_242=V(0LL);scope_212->set("frequncy",value_242);}
    // Ciaccona.py:134
    {V value_243=V(1LL);scope_212->set("i",value_243);}
    // Ciaccona.py:135
        while(([&]()->V{V compare_249=scope_212->get("i");V compare_250;V comparison_result_251;compare_250=scope_212->get("width");comparison_result_251=compare_value("<",compare_249,compare_250);return comparison_result_251;}()).truth()){
        // Ciaccona.py:136
        if(([&]()->V{V compare_244=item(scope_212->get("n"),scope_212->get("i"));V compare_245;V comparison_result_246;compare_245=scope_212->get("amplitude");comparison_result_246=compare_value(">",compare_244,compare_245);return comparison_result_246;}()).truth()){
            // Ciaccona.py:137
            {V value_247=item(scope_212->get("n"),scope_212->get("i"));scope_212->set("amplitude",value_247);}
            // Ciaccona.py:138
            {V value_248=scope_212->get("i");scope_212->set("frequncy",value_248);}
        }
        // Ciaccona.py:139
        scope_212->set("i",official::binary("+",scope_212->get("i"),V(1LL)));
    }
    // Ciaccona.py:140
    ([&]()->V{auto fn_253=attr(attr(self_value(),"logger"),"debug");Args args_252;args_252.pos(V(std::string{}+"forte with freq "+format_value(scope_212->get("frequncy"),"",-1)+" & amp "+format_value(scope_212->get("amplitude"),"",-1)));return invoke(fn_253,args_252);}());
    // Ciaccona.py:141
    return ([&]()->V{V operand_254;operand_254=([&]()->V{V compare_255=scope_212->get("min_freq");V compare_256;V comparison_result_257;compare_256=scope_212->get("frequncy");comparison_result_257=compare_value("<=",compare_255,compare_256);if(!comparison_result_257.truth())return comparison_result_257;compare_255=compare_256;compare_256=scope_212->get("max_freq");comparison_result_257=compare_value("<=",compare_255,compare_256);return comparison_result_257;}());if(operand_254.truth())return operand_254;return ([&]()->V{V compare_258=scope_212->get("amplitude");V compare_259;V comparison_result_260;compare_259=scope_212->get("min_amp");comparison_result_260=compare_value(">=",compare_258,compare_259);return comparison_result_260;}());}());
return V{};
}),false);
// Official method Ciaccona.calculate_forte_num, lines 143-162
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_261=bind_arguments(official_args,signature,captured);
scope_261->set("cropped",V::missing());
scope_261->set("forte",V::missing());
scope_261->set("gray",V::missing());
scope_261->set("height",V::missing());
scope_261->set("image",V::missing());
scope_261->set("left",V::missing());
scope_261->set("lower_bound",V::missing());
scope_261->set("score",V::missing());
scope_261->set("step",V::missing());
scope_261->set("upper_bound",V::missing());
scope_261->set("width",V::missing());
    // Ciaccona.py:144
    {V value_262=([&]()->V{auto fn_264=attr(scope_261->get("box"),"crop_frame");Args args_263;args_263.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_264,args_263);}());scope_261->set("cropped",value_262);}
    // Ciaccona.py:145
    {V value_265=([&]()->V{auto fn_267=global("color_range_to_bound","Ciaccona");Args args_266;args_266.pos(scope_261->get("forte_color"));return invoke(fn_267,args_266);}());auto unpack_268=unpack(value_265,2);scope_261->set("lower_bound",unpack_268[0]);scope_261->set("upper_bound",unpack_268[1]);}
    // Ciaccona.py:146
    {V value_269=([&]()->V{auto fn_271=attr(global("cv2","Ciaccona"),"inRange");Args args_270;args_270.pos(scope_261->get("cropped"));args_270.pos(scope_261->get("lower_bound"));args_270.pos(scope_261->get("upper_bound"));return invoke(fn_271,args_270);}());scope_261->set("image",value_269);}
    // Ciaccona.py:148
    {V value_272=V(0LL);scope_261->set("forte",value_272);}
    // Ciaccona.py:149
    {V value_273=attr(scope_261->get("image"),"shape");auto unpack_274=unpack(value_273,2);scope_261->set("height",unpack_274[0]);scope_261->set("width",unpack_274[1]);}
    // Ciaccona.py:150
    {V value_275=([&]()->V{auto fn_277=global("int","Ciaccona");Args args_276;args_276.pos(([&]()->V{V left_278=scope_261->get("width");V right_279=scope_261->get("num");return official::binary("/",left_278,right_279);}()));return invoke(fn_277,args_276);}());scope_261->set("step",value_275);}
    // Ciaccona.py:152
    {V value_280=scope_261->get("num");scope_261->set("forte",value_280);}
    // Ciaccona.py:153
    {V value_281=([&]()->V{V left_282=scope_261->get("step");V right_283=([&]()->V{V left_284=scope_261->get("forte");V right_285=V(1LL);return official::binary("-",left_284,right_285);}());return official::binary("*",left_282,right_283);}());scope_261->set("left",value_281);}
    // Ciaccona.py:154
        while(([&]()->V{V compare_292=scope_261->get("forte");V compare_293;V comparison_result_294;compare_293=V(0LL);comparison_result_294=compare_value(">",compare_292,compare_293);return comparison_result_294;}()).truth()){
        // Ciaccona.py:155
        {V value_286=item(scope_261->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_261->get("left"),([&]()->V{V left_287=scope_261->get("left");V right_288=scope_261->get("step");return official::binary("+",left_287,right_288);}()),V{})}));scope_261->set("gray",value_286);}
        // Ciaccona.py:156
        {V value_289=([&]()->V{auto fn_291=attr(self_value(),"judge_frequncy_and_amplitude");Args args_290;args_290.pos(scope_261->get("gray"));args_290.pos(scope_261->get("min_freq"));args_290.pos(scope_261->get("max_freq"));args_290.pos(scope_261->get("min_amp"));return invoke(fn_291,args_290);}());scope_261->set("score",value_289);}
        // Ciaccona.py:157
        if(scope_261->get("score").truth()){
            // Ciaccona.py:158
            break;
        }
        // Ciaccona.py:159
        scope_261->set("left",official::binary("-",scope_261->get("left"),scope_261->get("step")));
        // Ciaccona.py:160
        scope_261->set("forte",official::binary("-",scope_261->get("forte"),V(1LL)));
    }
    // Ciaccona.py:161
    ([&]()->V{auto fn_296=attr(attr(self_value(),"logger"),"info");Args args_295;args_295.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_261->get("forte"),"",-1)));return invoke(fn_296,args_295);}());
    // Ciaccona.py:162
    return scope_261->get("forte");
return V{};
}),false);
// Official method Ciaccona.switch_next_char, lines 164-167
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_297=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:165
    if(([&]()->V{auto fn_299=attr(self_value(),"is_con_full");Args args_298;return invoke(fn_299,args_298);}()).truth()){
        // Ciaccona.py:166
        {V value_300=([&]()->V{auto fn_302=attr(global("time","Ciaccona"),"time");Args args_301;return invoke(fn_302,args_301);}());set_attr(self_value(),"outrotime",value_300);}
    }
    // Ciaccona.py:167
    return ([&]()->V{auto fn_306=attr(([&]()->V{auto fn_304=global("super","Ciaccona");Args args_303;return invoke(fn_304,args_303);}()),"switch_next_char");Args args_305;args_305.spread(scope_297->get("args"));args_305.spread_keywords(scope_297->get("kwargs"));return invoke(fn_306,args_305);}());
return V{};
}),false);
// Official method Ciaccona.send_liberation_key, lines 169-172
register_method("send_liberation_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_307=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:171
    {V value_308=V(true);set_attr(self_value(),"recital_on_field",value_308);}
    // Ciaccona.py:172
    ([&]()->V{auto fn_312=attr(([&]()->V{auto fn_310=global("super","Ciaccona");Args args_309;return invoke(fn_310,args_309);}()),"send_liberation_key");Args args_311;args_311.spread(scope_307->get("args"));args_311.spread_keywords(scope_307->get("kwargs"));return invoke(fn_312,args_311);}());
return V{};
}),false);
// Official method Ciaccona.switch_out, lines 174-176
register_method("switch_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_313=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:175
    {V value_314=V(false);set_attr(self_value(),"recital_on_field",value_314);}
    // Ciaccona.py:176
    ([&]()->V{auto fn_318=attr(([&]()->V{auto fn_316=global("super","Ciaccona");Args args_315;return invoke(fn_316,args_315);}()),"switch_out");Args args_317;args_317.kw("con_full",scope_313->get("con_full"));return invoke(fn_318,args_317);}());
return V{};
}),false);
// Official method Ciaccona.on_combat_end, lines 178-183
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_319=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:180
    if(attr(self_value(),"recital_on_field").truth()){
        // Ciaccona.py:181
        ([&]()->V{auto fn_321=attr(attr(self_value(),"logger"),"info");Args args_320;args_320.pos(V("ciaccona: combat ended while still on field after liberation, switch out"));return invoke(fn_321,args_320);}());
        // Ciaccona.py:182
        {V value_322=V(false);set_attr(self_value(),"recital_on_field",value_322);}
        // Ciaccona.py:183
        ([&]()->V{auto fn_324=attr(self_value(),"switch_other_char");Args args_323;return invoke(fn_324,args_323);}());
    }
return V{};
}),false);
// Official method Ciaccona.in_outro, lines 185-186
register_method("in_outro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_325=bind_arguments(official_args,signature,captured);
    // Ciaccona.py:186
    return ([&]()->V{V compare_326=([&]()->V{auto fn_329=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_328;args_328.pos(attr(self_value(),"outrotime"));return invoke(fn_329,args_328);}());V compare_327;V comparison_result_330;compare_327=V(30LL);comparison_result_330=compare_value("<",compare_326,compare_327);return comparison_result_330;}());
return V{};
}),false);
// Official method Ciaccona.need_fast_perform, lines 188-192
register_method("need_fast_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_331=bind_arguments(official_args,signature,captured);
scope_331->set("Cartethyia",V::missing());
    // Ciaccona.py:189
    scope_331->set("Cartethyia",import_value("src.char.Cartethyia","Cartethyia"));
    // Ciaccona.py:190
    if(([&]()->V{V operand_332;operand_332=([&]()->V{auto fn_334=attr(attr(self_value(),"task"),"has_char");Args args_333;args_333.pos(scope_331->get("Cartethyia"));return invoke(fn_334,args_333);}());if(!operand_332.truth())return operand_332;return ([&]()->V{auto fn_336=global("hasattr","Ciaccona");Args args_335;args_335.pos(scope_331->get("Cartethyia"));args_335.pos(V("is_cartethyia"));return invoke(fn_336,args_335);}());}()).truth()){
        // Ciaccona.py:191
        return attr(scope_331->get("Cartethyia"),"is_cartethyia");
    }
    // Ciaccona.py:192
    return V(false);
return V{};
}),false);
}
}
