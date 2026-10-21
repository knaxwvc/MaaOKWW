#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Phoebe.py
// SHA256 eb37cd37d556a81a0707d36373fe25f65ea74f4e0ae9e467ec2e14a2fa4d86f4
void OfficialCharacter::install_Phoebe(){
auto scope=std::make_shared<Scope>();
set_global("State",make_namespace("State",{{"SUCCESS",V(1LL)},{"UNAVAILABLE",V(2LL)},{"TIMEOUT",V(3LL)}}));
set_global("phoebe_blue_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(124LL),V(134LL)}));set_item(dictionary_1,V("g"),V::tuple({V(176LL),V(186LL)}));set_item(dictionary_1,V("b"),V::tuple({V(250LL),V(255LL)}));return dictionary_1;}()));
set_global("phoebe_light_color",([&]()->V{V dictionary_2=V::dict();set_item(dictionary_2,V("r"),V::tuple({V(250LL),V(255LL)}));set_item(dictionary_2,V("g"),V::tuple({V(250LL),V(255LL)}));set_item(dictionary_2,V("b"),V::tuple({V(175LL),V(185LL)}));return dictionary_2;}()));
set_global("phoebe_forte_light_color",([&]()->V{V dictionary_3=V::dict();set_item(dictionary_3,V("r"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_3,V("g"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_3,V("b"),V::tuple({V(165LL),V(195LL)}));return dictionary_3;}()));
set_global("phoebe_forte_blue_color",([&]()->V{V dictionary_4=V::dict();set_item(dictionary_4,V("r"),V::tuple({V(225LL),V(255LL)}));set_item(dictionary_4,V("g"),V::tuple({V(225LL),V(255LL)}));set_item(dictionary_4,V("b"),V::tuple({V(190LL),V(225LL)}));return dictionary_4;}()));
set_global("phoebe_star_light_color",([&]()->V{V dictionary_5=V::dict();set_item(dictionary_5,V("r"),V::tuple({V(235LL),V(255LL)}));set_item(dictionary_5,V("g"),V::tuple({V(220LL),V(250LL)}));set_item(dictionary_5,V("b"),V::tuple({V(160LL),V(190LL)}));return dictionary_5;}()));
set_global("phoebe_star_blue_color",([&]()->V{V dictionary_6=V::dict();set_item(dictionary_6,V("r"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_6,V("g"),V::tuple({V(240LL),V(255LL)}));set_item(dictionary_6,V("b"),V::tuple({V(240LL),V(255LL)}));return dictionary_6;}()));
// Official method Phoebe.__init__, lines 18-32
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Phoebe.py:19
    ([&]()->V{auto fn_11=attr(([&]()->V{auto fn_9=global("super","Phoebe");Args args_8;return invoke(fn_9,args_8);}()),"__init__");Args args_10;args_10.spread(scope_7->get("args"));args_10.spread_keywords(scope_7->get("kwargs"));return invoke(fn_11,args_10);}());
    // Phoebe.py:20
    {V value_12=V(0LL);set_attr(self_value(),"perform_intro",value_12);}
    // Phoebe.py:21
    {V value_13=V(0LL);set_attr(self_value(),"attribute",value_13);}
    // Phoebe.py:22
    {V value_14=V(false);set_attr(self_value(),"star_available",value_14);}
    // Phoebe.py:23
    {V value_15=V{};set_attr(self_value(),"char_zani",value_15);}
    // Phoebe.py:24
    {V value_16=V(false);set_attr(self_value(),"attribute_mismatch",value_16);}
    // Phoebe.py:25
    {V value_17=V(false);set_attr(self_value(),"first_rotation_done",value_17);}
    // Phoebe.py:26
    {V value_18=([&]()->V{V dictionary_19=V::dict();set_item(dictionary_19,V("enter_status"),V(0LL));set_item(dictionary_19,V("starflash_combo"),V(0LL));set_item(dictionary_19,V("liberation"),V(0LL));set_item(dictionary_19,V("outro"),V(0LL));set_item(dictionary_19,V("priority_liberation_cast"),V(0LL));return dictionary_19;}());set_attr(self_value(),"state",value_18);}
return V{};
}),false);
// Official method Phoebe.reset_state, lines 34-40
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_20=bind_arguments(official_args,signature,captured);
    // Phoebe.py:35
    ([&]()->V{auto fn_24=attr(([&]()->V{auto fn_22=global("super","Phoebe");Args args_21;return invoke(fn_22,args_21);}()),"reset_state");Args args_23;return invoke(fn_24,args_23);}());
    // Phoebe.py:36
    {V value_25=V(0LL);set_attr(self_value(),"perform_intro",value_25);}
    // Phoebe.py:37
    {V value_26=V(0LL);set_attr(self_value(),"attribute",value_26);}
    // Phoebe.py:38
    {V value_27=V(false);set_attr(self_value(),"star_available",value_27);}
    // Phoebe.py:39
    {V value_28=V{};set_attr(self_value(),"char_zani",value_28);}
    // Phoebe.py:40
    {V value_29=V(false);set_attr(self_value(),"first_rotation_done",value_29);}
return V{};
}),false);
// Official method Phoebe.do_perform, lines 42-104
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_30=bind_arguments(official_args,signature,captured);
scope_30->set("attribute_mismatch",V::missing());
scope_30->set("start",V::missing());
scope_30->set("status_entered",V::missing());
scope_30->set("wait_ui_time",V::missing());
    // Phoebe.py:43
    {V value_31=unary("-",V(1LL));set_attr(self_value(),"last_outro_time",value_31);}
    // Phoebe.py:44
    {V value_32=([&]()->V{auto fn_34=attr(global("time","Phoebe"),"time");Args args_33;return invoke(fn_34,args_33);}());scope_30->set("start",value_32);}
    // Phoebe.py:45
    if(([&]()->V{V compare_35=attr(self_value(),"attribute");V compare_36;V comparison_result_37;compare_36=V(0LL);comparison_result_37=compare_value("==",compare_35,compare_36);return comparison_result_37;}()).truth()){
        // Phoebe.py:46
        ([&]()->V{auto fn_39=attr(self_value(),"decide_teammate");Args args_38;return invoke(fn_39,args_38);}());
    }
    // Phoebe.py:47
    if(attr(self_value(),"has_intro").truth()){
        // Phoebe.py:48
        ([&]()->V{auto fn_41=attr(self_value(),"continues_normal_attack");Args args_40;args_40.pos(V(1.5));return invoke(fn_41,args_40);}());
    }else{
        // Phoebe.py:51
        ([&]()->V{auto fn_43=attr(self_value(),"sleep");Args args_42;args_42.pos(V(0.01));return invoke(fn_43,args_42);}());
    }
    // Phoebe.py:52
    ([&]()->V{auto fn_45=attr(self_value(),"_try_liberation_now");Args args_44;return invoke(fn_45,args_44);}());
    // Phoebe.py:54
    if(([&]()->V{V compare_46=attr(self_value(),"attribute");V compare_47;V comparison_result_48;compare_47=V(1LL);comparison_result_48=compare_value("==",compare_46,compare_47);return comparison_result_48;}()).truth()){
        // Phoebe.py:55
        ([&]()->V{auto fn_50=attr(self_value(),"click_echo");Args args_49;args_49.kw("time_out",V(0LL));return invoke(fn_50,args_49);}());
    }
    // Phoebe.py:56
    if(([&]()->V{auto fn_52=attr(self_value(),"flying");Args args_51;return invoke(fn_52,args_51);}()).truth()){
        // Phoebe.py:57
        ([&]()->V{auto fn_54=attr(attr(self_value(),"logger"),"info");Args args_53;args_53.pos(V("flying"));return invoke(fn_54,args_53);}());
        // Phoebe.py:58
        ([&]()->V{auto fn_56=attr(self_value(),"continues_normal_attack");Args args_55;args_55.pos(V(0.1));return invoke(fn_56,args_55);}());
        // Phoebe.py:59
        return ([&]()->V{auto fn_58=attr(self_value(),"switch_next_char");Args args_57;return invoke(fn_58,args_57);}());
    }
    // Phoebe.py:61
    {V value_59=([&]()->V{auto fn_61=attr(self_value(),"check_attribute_mismatch");Args args_60;return invoke(fn_61,args_60);}());scope_30->set("attribute_mismatch",value_59);}
    // Phoebe.py:63
    if(([&]()->V{V operand_62;operand_62=([&]()->V{V compare_63=attr(self_value(),"attribute");V compare_64;V comparison_result_65;compare_64=V(2LL);comparison_result_65=compare_value("==",compare_63,compare_64);return comparison_result_65;}());if(!operand_62.truth())return operand_62;return ([&]()->V{V compare_66=attr(self_value(),"char_zani");V compare_67;V comparison_result_68;compare_67=V{};comparison_result_68=compare_value("is not",compare_66,compare_67);return comparison_result_68;}());}()).truth()){
        // Phoebe.py:64
        if(unary("not",attr(self_value(),"star_available")).truth()){
            // Phoebe.py:65
            ([&]()->V{auto fn_70=attr(self_value(),"absolution_or_confession");Args args_69;return invoke(fn_70,args_69);}());
        }
        // Phoebe.py:66
        if(([&]()->V{auto fn_72=attr(self_value(),"zani_linkage");Args args_71;return invoke(fn_72,args_71);}()).truth()){
            // Phoebe.py:67
            return ([&]()->V{auto fn_74=attr(self_value(),"switch_next_char");Args args_73;return invoke(fn_74,args_73);}());
        }
    }
    // Phoebe.py:69
    {V value_75=([&]()->V{V left_76=V(0.35);V right_77=([&]()->V{V left_78=([&]()->V{auto fn_81=attr(global("time","Phoebe"),"time");Args args_80;return invoke(fn_81,args_80);}());V right_79=scope_30->get("start");return official::binary("-",left_78,right_79);}());return official::binary("-",left_76,right_77);}());scope_30->set("wait_ui_time",value_75);}
    // Phoebe.py:70
    if(([&]()->V{V operand_82;operand_82=([&]()->V{V compare_83=scope_30->get("wait_ui_time");V compare_84;V comparison_result_85;compare_84=V(0LL);comparison_result_85=compare_value(">",compare_83,compare_84);return comparison_result_85;}());if(!operand_82.truth())return operand_82;operand_82=attr(self_value(),"star_available");if(!operand_82.truth())return operand_82;return ([&]()->V{V compare_86=([&]()->V{auto fn_89=attr(self_value(),"judge_forte");Args args_88;return invoke(fn_89,args_88);}());V compare_87;V comparison_result_90;compare_87=V(0LL);comparison_result_90=compare_value("==",compare_86,compare_87);return comparison_result_90;}());}()).truth()){
        // Phoebe.py:71
        ([&]()->V{auto fn_92=attr(attr(self_value(),"logger"),"info");Args args_91;args_91.pos(V("wait for UI"));return invoke(fn_92,args_91);}());
        // Phoebe.py:72
        ([&]()->V{auto fn_94=attr(self_value(),"continues_normal_attack");Args args_93;args_93.pos(scope_30->get("wait_ui_time"));return invoke(fn_94,args_93);}());
    }
    // Phoebe.py:74
    {V value_95=([&]()->V{auto fn_97=attr(self_value(),"absolution_or_confession");Args args_96;return invoke(fn_97,args_96);}());scope_30->set("status_entered",value_95);}
    // Phoebe.py:75
    ([&]()->V{auto fn_99=attr(self_value(),"check_combat");Args args_98;return invoke(fn_99,args_98);}());
    // Phoebe.py:76
    if(([&]()->V{V operand_100;operand_100=([&]()->V{V operand_101;operand_101=unary("not",scope_30->get("attribute_mismatch"));if(operand_101.truth())return operand_101;return ([&]()->V{V compare_102=scope_30->get("status_entered");V compare_103;V comparison_result_104;compare_103=attr(global("State","Phoebe"),"SUCCESS");comparison_result_104=compare_value("==",compare_102,compare_103);return comparison_result_104;}());}());if(!operand_100.truth())return operand_100;operand_100=attr(self_value(),"star_available");if(!operand_100.truth())return operand_100;return ([&]()->V{auto fn_106=attr(self_value(),"click_liberation");Args args_105;args_105.kw("send_click",V(true));return invoke(fn_106,args_105);}());}()).truth()){
        // Phoebe.py:80
        set_item(attr(self_value(),"state"),V("liberation"),official::binary("+",item(attr(self_value(),"state"),V("liberation")),V(1LL)));
        // Phoebe.py:81
        {V value_107=V(1LL);set_item(attr(self_value(),"state"),V("priority_liberation_cast"),value_107);}
        // Phoebe.py:82
        ([&]()->V{auto fn_109=attr(self_value(),"check_combat");Args args_108;return invoke(fn_109,args_108);}());
    }
    // Phoebe.py:83
    if(([&]()->V{V operand_110;operand_110=([&]()->V{V compare_111=scope_30->get("status_entered");V compare_112;V comparison_result_113;compare_112=attr(global("State","Phoebe"),"SUCCESS");comparison_result_113=compare_value("==",compare_111,compare_112);return comparison_result_113;}());if(operand_110.truth())return operand_110;return ([&]()->V{V compare_114=([&]()->V{auto fn_117=attr(self_value(),"judge_forte");Args args_116;return invoke(fn_117,args_116);}());V compare_115;V comparison_result_118;compare_115=V(0LL);comparison_result_118=compare_value(">",compare_114,compare_115);return comparison_result_118;}());}()).truth()){
        // Phoebe.py:84
        ([&]()->V{auto fn_120=attr(self_value(),"starflash_combo");Args args_119;return invoke(fn_120,args_119);}());
        // Phoebe.py:86
        ([&]()->V{auto fn_122=attr(self_value(),"_try_liberation_now");Args args_121;return invoke(fn_122,args_121);}());
        // Phoebe.py:87
        if(([&]()->V{V operand_123;operand_123=([&]()->V{V compare_124=attr(self_value(),"attribute");V compare_125;V comparison_result_126;compare_125=V(2LL);comparison_result_126=compare_value("==",compare_124,compare_125);return comparison_result_126;}());if(!operand_123.truth())return operand_123;operand_123=([&]()->V{V compare_127=item(attr(self_value(),"state"),V("starflash_combo"));V compare_128;V comparison_result_129;compare_128=V(2LL);comparison_result_129=compare_value("<",compare_127,compare_128);return comparison_result_129;}());if(!operand_123.truth())return operand_123;return ([&]()->V{V compare_130=([&]()->V{auto fn_133=attr(self_value(),"get_zani_state");Args args_132;return invoke(fn_133,args_132);}());V compare_131;V comparison_result_134;compare_131=V(1LL);comparison_result_134=compare_value("!=",compare_130,compare_131);return comparison_result_134;}());}()).truth()){
            // Phoebe.py:90
            ([&]()->V{auto fn_136=attr(attr(self_value(),"logger"),"info");Args args_135;args_135.pos(V("phoebe: try second starflash_combo"));return invoke(fn_136,args_135);}());
            // Phoebe.py:91
            ([&]()->V{auto fn_138=attr(self_value(),"starflash_combo");Args args_137;return invoke(fn_138,args_137);}());
        }
    }
    // Phoebe.py:92
    ([&]()->V{auto fn_140=attr(self_value(),"_try_liberation_now");Args args_139;return invoke(fn_140,args_139);}());
    // Phoebe.py:93
    if(([&]()->V{auto fn_142=attr(self_value(),"resonance_available");Args args_141;return invoke(fn_142,args_141);}()).truth()){
        // Phoebe.py:94
        if(([&]()->V{V compare_143=attr(self_value(),"attribute");V compare_144;V comparison_result_145;compare_144=V(2LL);comparison_result_145=compare_value("==",compare_143,compare_144);return comparison_result_145;}()).truth()){
            // Phoebe.py:96
            if(([&]()->V{V operand_146;operand_146=unary("not",([&]()->V{auto fn_148=attr(self_value(),"confession_ready");Args args_147;return invoke(fn_148,args_147);}()));if(!operand_146.truth())return operand_146;return attr(self_value(),"first_rotation_done");}()).truth()){
                // Phoebe.py:97
                ([&]()->V{auto fn_150=attr(self_value(),"click_resonance_once");Args args_149;return invoke(fn_150,args_149);}());
            }
        }else{
            // Phoebe.py:99
            ([&]()->V{auto fn_152=attr(self_value(),"click_resonance");Args args_151;return invoke(fn_152,args_151);}());
        }
        // Phoebe.py:100
        ([&]()->V{auto fn_154=attr(self_value(),"_ensure_first_rotation_con");Args args_153;return invoke(fn_154,args_153);}());
        // Phoebe.py:101
        return ([&]()->V{auto fn_156=attr(self_value(),"switch_next_char");Args args_155;return invoke(fn_156,args_155);}());
    }
    // Phoebe.py:102
    ([&]()->V{auto fn_158=attr(self_value(),"continues_normal_attack");Args args_157;args_157.pos(V(0.1));return invoke(fn_158,args_157);}());
    // Phoebe.py:103
    ([&]()->V{auto fn_160=attr(self_value(),"_ensure_first_rotation_con");Args args_159;return invoke(fn_160,args_159);}());
    // Phoebe.py:104
    ([&]()->V{auto fn_162=attr(self_value(),"switch_next_char");Args args_161;return invoke(fn_162,args_161);}());
return V{};
}),false);
// Official method Phoebe._ensure_first_rotation_con, lines 106-112
register_method("_ensure_first_rotation_con",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_163=bind_arguments(official_args,signature,captured);
    // Phoebe.py:108
    if(unary("not",attr(self_value(),"first_rotation_done")).truth()){
        // Phoebe.py:109
        {V value_164=V(true);set_attr(self_value(),"first_rotation_done",value_164);}
        // Phoebe.py:110
        if(unary("not",([&]()->V{auto fn_166=attr(self_value(),"is_con_full");Args args_165;return invoke(fn_166,args_165);}())).truth()){
            // Phoebe.py:111
            ([&]()->V{auto fn_168=attr(attr(self_value(),"logger"),"info");Args args_167;args_167.pos(V("phoebe: first rotation, wait for full con"));return invoke(fn_168,args_167);}());
            // Phoebe.py:112
            ([&]()->V{auto fn_170=attr(self_value(),"continues_normal_attack");Args args_169;args_169.pos(V(5.0));args_169.kw("until_con_full",V(true));return invoke(fn_170,args_169);}());
        }
    }
return V{};
}),false);
// Official method Phoebe.zani_linkage, lines 114-129
register_method("zani_linkage",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_171=bind_arguments(official_args,signature,captured);
scope_171->set("result",V::missing());
    // Phoebe.py:115
    ([&]()->V{auto fn_173=attr(attr(self_value(),"logger"),"debug");Args args_172;args_172.pos(V("zani linkage"));return invoke(fn_173,args_172);}());
    // Phoebe.py:116
    {V value_174=([&]()->V{auto fn_176=attr(self_value(),"get_zani_state");Args args_175;return invoke(fn_176,args_175);}());scope_171->set("result",value_174);}
    // Phoebe.py:117
    if(([&]()->V{V compare_177=attr(attr(self_value(),"char_zani"),"blazes");V compare_178;V comparison_result_179;compare_178=V(0.9);comparison_result_179=compare_value(">=",compare_177,compare_178);return comparison_result_179;}()).truth()){
        // Phoebe.py:118
        ([&]()->V{auto fn_181=attr(attr(self_value(),"logger"),"info");Args args_180;args_180.pos(V("stop applying spectro frazzle"));return invoke(fn_181,args_180);}());
        // Phoebe.py:119
        if(unary("not",([&]()->V{auto fn_183=attr(self_value(),"resonance_available");Args args_182;return invoke(fn_183,args_182);}())).truth()){
            // Phoebe.py:120
            if(([&]()->V{V operand_184;operand_184=([&]()->V{V compare_185=scope_171->get("result");V compare_186;V comparison_result_187;compare_186=V(0LL);comparison_result_187=compare_value("==",compare_185,compare_186);return comparison_result_187;}());if(operand_184.truth())return operand_184;return ([&]()->V{V compare_188=([&]()->V{auto fn_191=attr(attr(self_value(),"char_zani"),"liberation_time_left");Args args_190;return invoke(fn_191,args_190);}());V compare_189;V comparison_result_192;compare_189=V(3LL);comparison_result_192=compare_value(">",compare_188,compare_189);return comparison_result_192;}());}()).truth()){
                // Phoebe.py:121
                ([&]()->V{auto fn_194=attr(self_value(),"continues_normal_attack");Args args_193;args_193.pos(V(1LL));args_193.kw("interval",V(0.15));return invoke(fn_194,args_193);}());
            }
        }else{
            // Phoebe.py:124
            if(([&]()->V{V operand_195;operand_195=attr(self_value(),"first_rotation_done");if(!operand_195.truth())return operand_195;return unary("not",([&]()->V{auto fn_197=attr(self_value(),"confession_ready");Args args_196;return invoke(fn_197,args_196);}()));}()).truth()){
                // Phoebe.py:125
                ([&]()->V{auto fn_199=attr(self_value(),"click_resonance");Args args_198;args_198.kw("send_click",V(false));return invoke(fn_199,args_198);}());
            }
        }
        // Phoebe.py:126
        return V(true);
    }
    // Phoebe.py:127
    if(([&]()->V{V compare_200=scope_171->get("result");V compare_201;V comparison_result_202;compare_201=V(1LL);comparison_result_202=compare_value("==",compare_200,compare_201);return comparison_result_202;}()).truth()){
        // Phoebe.py:128
        ([&]()->V{auto fn_204=attr(self_value(),"cast_remaining_skills");Args args_203;return invoke(fn_204,args_203);}());
        // Phoebe.py:129
        return V(true);
    }
return V{};
}),false);
// Official method Phoebe.check_attribute_mismatch, lines 131-155
register_method("check_attribute_mismatch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_205=bind_arguments(official_args,signature,captured);
scope_205->set("attribute",V::missing());
scope_205->set("box",V::missing());
scope_205->set("old_attribute",V::missing());
scope_205->set("star_blue_percent",V::missing());
scope_205->set("star_light_percent",V::missing());
    // Phoebe.py:132
    ([&]()->V{auto fn_207=attr(attr(self_value(),"logger"),"debug");Args args_206;args_206.pos(V("check attribute mismatch"));return invoke(fn_207,args_206);}());
    // Phoebe.py:133
    {V value_208=([&]()->V{auto fn_210=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_209;args_209.pos(V(3840LL));args_209.pos(V(2160LL));args_209.pos(V(1890LL));args_209.pos(V(2010LL));args_209.pos(V(1915LL));args_209.pos(V(2030LL));args_209.kw("name",V("phoebe_middle_star"));args_209.kw("hcenter",V(true));return invoke(fn_210,args_209);}());scope_205->set("box",value_208);}
    // Phoebe.py:135
    ([&]()->V{auto fn_212=attr(attr(self_value(),"task"),"draw_boxes");Args args_211;args_211.pos(attr(scope_205->get("box"),"name"));args_211.pos(scope_205->get("box"));return invoke(fn_212,args_211);}());
    // Phoebe.py:136
    {V value_213=([&]()->V{auto fn_215=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_214;args_214.pos(global("phoebe_star_light_color","Phoebe"));args_214.pos(scope_205->get("box"));return invoke(fn_215,args_214);}());scope_205->set("star_light_percent",value_213);}
    // Phoebe.py:137
    ([&]()->V{auto fn_217=attr(attr(self_value(),"logger"),"debug");Args args_216;args_216.pos(V(std::string{}+"middle_star_light_percent "+format_value(scope_205->get("star_light_percent"),"",-1)));return invoke(fn_217,args_216);}());
    // Phoebe.py:138
    {V value_218=([&]()->V{auto fn_220=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_219;args_219.pos(global("phoebe_star_blue_color","Phoebe"));args_219.pos(scope_205->get("box"));return invoke(fn_220,args_219);}());scope_205->set("star_blue_percent",value_218);}
    // Phoebe.py:139
    ([&]()->V{auto fn_222=attr(attr(self_value(),"logger"),"debug");Args args_221;args_221.pos(V(std::string{}+"middle_star_blue_percent "+format_value(scope_205->get("star_blue_percent"),"",-1)));return invoke(fn_222,args_221);}());
    // Phoebe.py:140
    if(([&]()->V{V operand_223;operand_223=([&]()->V{V compare_224=scope_205->get("star_light_percent");V compare_225;V comparison_result_226;compare_225=V(0.25);comparison_result_226=compare_value(">",compare_224,compare_225);return comparison_result_226;}());if(operand_223.truth())return operand_223;return ([&]()->V{V compare_227=scope_205->get("star_blue_percent");V compare_228;V comparison_result_229;compare_228=V(0.25);comparison_result_229=compare_value(">",compare_227,compare_228);return comparison_result_229;}());}()).truth()){
        // Phoebe.py:141
        if(([&]()->V{V compare_230=scope_205->get("star_light_percent");V compare_231;V comparison_result_232;compare_231=scope_205->get("star_blue_percent");comparison_result_232=compare_value(">",compare_230,compare_231);return comparison_result_232;}()).truth()){
            // Phoebe.py:142
            {V value_233=V(1LL);scope_205->set("attribute",value_233);}
        }else{
            // Phoebe.py:144
            {V value_234=V(2LL);scope_205->set("attribute",value_234);}
        }
    }else{
        // Phoebe.py:146
        {V value_235=V(false);set_attr(self_value(),"star_available",value_235);}
        // Phoebe.py:147
        return V(false);
    }
    // Phoebe.py:148
    if(([&]()->V{V compare_236=attr(self_value(),"attribute");V compare_237;V comparison_result_238;compare_237=scope_205->get("attribute");comparison_result_238=compare_value("!=",compare_236,compare_237);return comparison_result_238;}()).truth()){
        // Phoebe.py:149
        ([&]()->V{auto fn_240=attr(attr(self_value(),"logger"),"info");Args args_239;args_239.pos(V("attribute mismatch"));return invoke(fn_240,args_239);}());
        // Phoebe.py:150
        {V value_241=attr(self_value(),"attribute");scope_205->set("old_attribute",value_241);}
        // Phoebe.py:151
        {V value_242=scope_205->get("attribute");set_attr(self_value(),"attribute",value_242);}
        // Phoebe.py:152
        ([&]()->V{auto fn_244=attr(self_value(),"cast_remaining_skills");Args args_243;args_243.kw("liber",V(false));return invoke(fn_244,args_243);}());
        // Phoebe.py:153
        {V value_245=scope_205->get("old_attribute");set_attr(self_value(),"attribute",value_245);}
        // Phoebe.py:154
        return V(true);
    }
    // Phoebe.py:155
    return V(false);
return V{};
}),false);
// Official method Phoebe.cast_remaining_skills, lines 157-174
register_method("cast_remaining_skills",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"liber",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_246=bind_arguments(official_args,signature,captured);
scope_246->set("_",V::missing());
scope_246->set("skill_count",V::missing());
scope_246->set("start",V::missing());
    // Phoebe.py:158
    {V value_247=unary("-",V(1LL));scope_246->set("start",value_247);}
    // Phoebe.py:159
    if(([&]()->V{V compare_248=attr(self_value(),"attribute");V compare_249;V comparison_result_250;compare_249=V(1LL);comparison_result_250=compare_value("==",compare_248,compare_249);return comparison_result_250;}()).truth()){
        // Phoebe.py:160
        {V value_251=V(4LL);scope_246->set("skill_count",value_251);}
    }else{
        // Phoebe.py:161
        if(([&]()->V{V compare_252=attr(self_value(),"attribute");V compare_253;V comparison_result_254;compare_253=V(2LL);comparison_result_254=compare_value("==",compare_252,compare_253);return comparison_result_254;}()).truth()){
            // Phoebe.py:162
            {V value_255=V(2LL);scope_246->set("skill_count",value_255);}
        }else{
            // Phoebe.py:164
            return scope_246->get("start");
        }
    }
    // Phoebe.py:165
    ([&]()->V{auto fn_257=attr(attr(self_value(),"logger"),"info");Args args_256;args_256.pos(V("cast remaining skills"));return invoke(fn_257,args_256);}());
    // Phoebe.py:166
    {auto iterator_258=official::iterate(([&]()->V{auto fn_282=global("range","Phoebe");Args args_281;args_281.pos(scope_246->get("skill_count"));return invoke(fn_282,args_281);}()));V item_259;while(iterator_258.next(item_259)){
        scope_246->set("_",item_259);
        // Phoebe.py:167
        if(([&]()->V{V operand_260;operand_260=scope_246->get("liber");if(!operand_260.truth())return operand_260;return ([&]()->V{V compare_261=item(attr(self_value(),"state"),V("liberation"));V compare_262;V comparison_result_263;compare_262=V(1LL);comparison_result_263=compare_value("<",compare_261,compare_262);return comparison_result_263;}());}()).truth()){
            // Phoebe.py:168
            if(([&]()->V{V operand_264;operand_264=([&]()->V{auto fn_266=attr(self_value(),"liberation_available");Args args_265;return invoke(fn_266,args_265);}());if(!operand_264.truth())return operand_264;return ([&]()->V{auto fn_268=attr(self_value(),"click_liberation");Args args_267;args_267.kw("send_click",V(false));return invoke(fn_268,args_267);}());}()).truth()){
                // Phoebe.py:169
                set_item(attr(self_value(),"state"),V("liberation"),official::binary("+",item(attr(self_value(),"state"),V("liberation")),V(1LL)));
            }
        }
        // Phoebe.py:170
        if(([&]()->V{V compare_269=([&]()->V{auto fn_272=attr(self_value(),"judge_forte");Args args_271;return invoke(fn_272,args_271);}());V compare_270;V comparison_result_273;compare_270=V(0LL);comparison_result_273=compare_value(">",compare_269,compare_270);return comparison_result_273;}()).truth()){
            // Phoebe.py:171
            ([&]()->V{auto fn_275=attr(self_value(),"starflash_combo");Args args_274;return invoke(fn_275,args_274);}());
            // Phoebe.py:172
            ([&]()->V{auto fn_277=attr(attr(self_value(),"task"),"next_frame");Args args_276;return invoke(fn_277,args_276);}());
            // Phoebe.py:173
            {V value_278=([&]()->V{auto fn_280=attr(global("time","Phoebe"),"time");Args args_279;return invoke(fn_280,args_279);}());scope_246->set("start",value_278);}
        }
    }
    }
    // Phoebe.py:174
    return scope_246->get("start");
return V{};
}),false);
// Official method Phoebe.judge_forte, lines 176-182
register_method("judge_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_283=bind_arguments(official_args,signature,captured);
scope_283->set("box",V::missing());
scope_283->set("forte",V::missing());
    // Phoebe.py:177
    {V value_284=([&]()->V{auto fn_286=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_285;args_285.pos(V(3840LL));args_285.pos(V(2160LL));args_285.pos(V(1633LL));args_285.pos(V(2004LL));args_285.pos(V(2160LL));args_285.pos(V(2014LL));args_285.kw("name",V("phoebe_forte1"));args_285.kw("hcenter",V(true));return invoke(fn_286,args_285);}());scope_283->set("box",value_284);}
    // Phoebe.py:178
    if(([&]()->V{V compare_287=attr(self_value(),"attribute");V compare_288;V comparison_result_289;compare_288=V(1LL);comparison_result_289=compare_value("==",compare_287,compare_288);return comparison_result_289;}()).truth()){
        // Phoebe.py:179
        {V value_290=([&]()->V{auto fn_292=attr(self_value(),"calculate_forte_num");Args args_291;args_291.pos(global("phoebe_forte_light_color","Phoebe"));args_291.pos(scope_283->get("box"));args_291.pos(V(4LL));args_291.pos(V(9LL));args_291.pos(V(11LL));args_291.pos(V(25LL));return invoke(fn_292,args_291);}());scope_283->set("forte",value_290);}
    }else{
        // Phoebe.py:181
        {V value_293=([&]()->V{auto fn_295=attr(self_value(),"calculate_forte_num");Args args_294;args_294.pos(global("phoebe_forte_blue_color","Phoebe"));args_294.pos(scope_283->get("box"));args_294.pos(V(2LL));args_294.pos(V(18LL));args_294.pos(V(20LL));args_294.pos(V(50LL));return invoke(fn_295,args_294);}());scope_283->set("forte",value_293);}
    }
    // Phoebe.py:182
    return scope_283->get("forte");
return V{};
}),false);
// Official method Phoebe.starflash_combo, lines 184-205
register_method("starflash_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_296=bind_arguments(official_args,signature,captured);
scope_296->set("check_forte",V::missing());
scope_296->set("condition",V::missing());
scope_296->set("start",V::missing());
    // Phoebe.py:185
    ([&]()->V{auto fn_298=attr(attr(self_value(),"logger"),"info");Args args_297;args_297.pos(V("perform starflash_combo"));return invoke(fn_298,args_297);}());
    // Phoebe.py:186
    {V value_299=([&]()->V{auto fn_301=attr(global("time","Phoebe"),"time");Args args_300;return invoke(fn_301,args_300);}());scope_296->set("start",value_299);}
    // Phoebe.py:187
    {V value_302=scope_296->get("start");scope_296->set("check_forte",value_302);}
    // Phoebe.py:188
    {V value_303=([&]()->V{auto fn_305=attr(self_value(),"get_prayer_condition");Args args_304;return invoke(fn_305,args_304);}());scope_296->set("condition",value_303);}
    // Phoebe.py:189
    if(([&]()->V{V operand_306;operand_306=unary("not",([&]()->V{auto fn_308=scope_296->get("condition");Args args_307;return invoke(fn_308,args_307);}()));if(!operand_306.truth())return operand_306;return unary("not",([&]()->V{auto fn_310=attr(self_value(),"heavy_attack_ready");Args args_309;return invoke(fn_310,args_309);}()));}()).truth()){
        // Phoebe.py:190
                while(unary("not",([&]()->V{auto fn_347=attr(self_value(),"heavy_attack_ready");Args args_346;return invoke(fn_347,args_346);}())).truth()){
            // Phoebe.py:191
            if(([&]()->V{auto fn_312=attr(self_value(),"flying");Args args_311;return invoke(fn_312,args_311);}()).truth()){
                // Phoebe.py:192
                ([&]()->V{auto fn_314=attr(self_value(),"shorekeeper_auto_dodge");Args args_313;return invoke(fn_314,args_313);}());
            }
            // Phoebe.py:193
            ([&]()->V{auto fn_316=attr(self_value(),"click");Args args_315;return invoke(fn_316,args_315);}());
            // Phoebe.py:194
            if(([&]()->V{V compare_317=([&]()->V{V left_319=([&]()->V{auto fn_322=attr(global("time","Phoebe"),"time");Args args_321;return invoke(fn_322,args_321);}());V right_320=scope_296->get("start");return official::binary("-",left_319,right_320);}());V compare_318;V comparison_result_323;compare_318=V(5LL);comparison_result_323=compare_value(">",compare_317,compare_318);return comparison_result_323;}()).truth()){
                // Phoebe.py:195
                return V{};
            }
            // Phoebe.py:196
            if(([&]()->V{V compare_324=([&]()->V{V left_326=([&]()->V{auto fn_329=attr(global("time","Phoebe"),"time");Args args_328;return invoke(fn_329,args_328);}());V right_327=scope_296->get("check_forte");return official::binary("-",left_326,right_327);}());V compare_325;V comparison_result_330;compare_325=V(1LL);comparison_result_330=compare_value(">",compare_324,compare_325);return comparison_result_330;}()).truth()){
                // Phoebe.py:197
                if(([&]()->V{V operand_331;operand_331=([&]()->V{auto fn_333=scope_296->get("condition");Args args_332;return invoke(fn_333,args_332);}());if(operand_331.truth())return operand_331;return ([&]()->V{V compare_334=([&]()->V{auto fn_337=attr(self_value(),"judge_forte");Args args_336;return invoke(fn_337,args_336);}());V compare_335;V comparison_result_338;compare_335=V(0LL);comparison_result_338=compare_value("==",compare_334,compare_335);return comparison_result_338;}());}()).truth()){
                    // Phoebe.py:198
                    return V{};
                }
            }else{
                // Phoebe.py:200
                {V value_339=([&]()->V{auto fn_341=attr(global("time","Phoebe"),"time");Args args_340;return invoke(fn_341,args_340);}());scope_296->set("check_forte",value_339);}
            }
            // Phoebe.py:201
            ([&]()->V{auto fn_343=attr(self_value(),"check_combat");Args args_342;return invoke(fn_343,args_342);}());
            // Phoebe.py:202
            ([&]()->V{auto fn_345=attr(attr(self_value(),"task"),"next_frame");Args args_344;return invoke(fn_345,args_344);}());
        }
        // Phoebe.py:203
        ([&]()->V{auto fn_349=attr(self_value(),"continues_right_click");Args args_348;args_348.pos(V(0.05));return invoke(fn_349,args_348);}());
    }
    // Phoebe.py:204
    if(([&]()->V{auto fn_351=attr(self_value(),"perform_heavy_attack");Args args_350;return invoke(fn_351,args_350);}()).truth()){
        // Phoebe.py:205
        set_item(attr(self_value(),"state"),V("starflash_combo"),official::binary("+",item(attr(self_value(),"state"),V("starflash_combo")),V(1LL)));
    }
return V{};
}),false);
// Official method Phoebe.perform_heavy_attack, lines 207-233
register_method("perform_heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_352=bind_arguments(official_args,signature,captured);
scope_352->set("flying",V::missing());
scope_352->set("mouse_hold_start",V::missing());
scope_352->set("outer_start",V::missing());
    // Phoebe.py:208
    if(([&]()->V{V compare_353=([&]()->V{auto fn_356=attr(self_value(),"absolution_or_confession");Args args_355;return invoke(fn_356,args_355);}());V compare_354;V comparison_result_357;compare_354=attr(global("State","Phoebe"),"UNAVAILABLE");comparison_result_357=compare_value("==",compare_353,compare_354);return comparison_result_357;}()).truth()){
        // Phoebe.py:209
        ([&]()->V{auto fn_359=attr(attr(self_value(),"logger"),"info");Args args_358;args_358.pos(V("perform heavy_attack"));return invoke(fn_359,args_358);}());
        // Phoebe.py:210
        {V value_360=V(false);scope_352->set("flying",value_360);}
        // Phoebe.py:211
        {V value_361=([&]()->V{auto fn_363=attr(global("time","Phoebe"),"time");Args args_362;return invoke(fn_363,args_362);}());scope_352->set("outer_start",value_361);}
        // Phoebe.py:212
                while(([&]()->V{auto fn_412=attr(self_value(),"heavy_attack_ready");Args args_411;return invoke(fn_412,args_411);}()).truth()){
            // Phoebe.py:213
            if(([&]()->V{V compare_364=([&]()->V{V left_366=([&]()->V{auto fn_369=attr(global("time","Phoebe"),"time");Args args_368;return invoke(fn_369,args_368);}());V right_367=scope_352->get("outer_start");return official::binary("-",left_366,right_367);}());V compare_365;V comparison_result_370;compare_365=V(2LL);comparison_result_370=compare_value(">",compare_364,compare_365);return comparison_result_370;}()).truth()){
                // Phoebe.py:214
                return V(false);
            }
            // Phoebe.py:215
            ([&]()->V{auto fn_372=attr(attr(self_value(),"task"),"mouse_down");Args args_371;return invoke(fn_372,args_371);}());
            // Phoebe.py:216
            {V value_373=([&]()->V{auto fn_375=attr(global("time","Phoebe"),"time");Args args_374;return invoke(fn_375,args_374);}());scope_352->set("mouse_hold_start",value_373);}
            // Phoebe.py:217
                        while(([&]()->V{V compare_385=([&]()->V{V left_387=([&]()->V{auto fn_390=attr(global("time","Phoebe"),"time");Args args_389;return invoke(fn_390,args_389);}());V right_388=scope_352->get("mouse_hold_start");return official::binary("-",left_387,right_388);}());V compare_386;V comparison_result_391;compare_386=V(0.5);comparison_result_391=compare_value("<",compare_385,compare_386);return comparison_result_391;}()).truth()){
                // Phoebe.py:218
                if(unary("not",([&]()->V{auto fn_377=attr(self_value(),"heavy_attack_ready");Args args_376;return invoke(fn_377,args_376);}())).truth()){
                    // Phoebe.py:219
                    ([&]()->V{auto fn_379=attr(attr(self_value(),"task"),"mouse_up");Args args_378;return invoke(fn_379,args_378);}());
                    // Phoebe.py:220
                    return V(true);
                }
                // Phoebe.py:221
                if(([&]()->V{V assigned_380=([&]()->V{auto fn_382=attr(self_value(),"flying");Args args_381;return invoke(fn_382,args_381);}());scope_352->set("flying",assigned_380);return assigned_380;}()).truth()){
                    // Phoebe.py:222
                    break;
                }
                // Phoebe.py:223
                ([&]()->V{auto fn_384=attr(attr(self_value(),"task"),"next_frame");Args args_383;return invoke(fn_384,args_383);}());
            }
            // Phoebe.py:224
            ([&]()->V{auto fn_393=attr(attr(self_value(),"task"),"mouse_up");Args args_392;return invoke(fn_393,args_392);}());
            // Phoebe.py:225
            if(scope_352->get("flying").truth()){
                // Phoebe.py:226
                ([&]()->V{auto fn_395=attr(attr(self_value(),"logger"),"info");Args args_394;args_394.pos(V("flying"));return invoke(fn_395,args_394);}());
                // Phoebe.py:227
                ([&]()->V{auto fn_397=attr(attr(self_value(),"task"),"wait_until");Args args_396;args_396.pos(V::function([this,captured=capture_scope(scope_352,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_398=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_400=attr(self_value(),"flying");Args args_399;return invoke(fn_400,args_399);}()));
}));args_396.kw("post_action",V::function([this,captured=capture_scope(scope_352,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_401=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_403=attr(self_value(),"click");Args args_402;args_402.kw("interval",V(0.1));args_402.kw("after_sleep",V(0.1));return invoke(fn_403,args_402);}());
}));args_396.kw("time_out",V(2LL));return invoke(fn_397,args_396);}());
                // Phoebe.py:229
                {V value_404=([&]()->V{auto fn_406=attr(global("time","Phoebe"),"time");Args args_405;return invoke(fn_406,args_405);}());scope_352->set("outer_start",value_404);}
            }
            // Phoebe.py:230
            ([&]()->V{auto fn_408=attr(self_value(),"check_combat");Args args_407;return invoke(fn_408,args_407);}());
            // Phoebe.py:231
            ([&]()->V{auto fn_410=attr(attr(self_value(),"task"),"next_frame");Args args_409;return invoke(fn_410,args_409);}());
        }
        // Phoebe.py:232
        return V(true);
    }
    // Phoebe.py:233
    return V(false);
return V{};
}),false);
// Official method Phoebe.click_resonance_once, lines 235-243
register_method("click_resonance_once",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_413=bind_arguments(official_args,signature,captured);
scope_413->set("start",V::missing());
    // Phoebe.py:236
    {V value_414=([&]()->V{auto fn_416=attr(global("time","Phoebe"),"time");Args args_415;return invoke(fn_416,args_415);}());scope_413->set("start",value_414);}
    // Phoebe.py:237
        while(([&]()->V{auto fn_431=attr(self_value(),"resonance_available");Args args_430;return invoke(fn_431,args_430);}()).truth()){
        // Phoebe.py:238
        ([&]()->V{auto fn_418=attr(self_value(),"check_combat");Args args_417;return invoke(fn_418,args_417);}());
        // Phoebe.py:239
        if(([&]()->V{V compare_419=([&]()->V{V left_421=([&]()->V{auto fn_424=attr(global("time","Phoebe"),"time");Args args_423;return invoke(fn_424,args_423);}());V right_422=scope_413->get("start");return official::binary("-",left_421,right_422);}());V compare_420;V comparison_result_425;compare_420=V(0.5);comparison_result_425=compare_value(">",compare_419,compare_420);return comparison_result_425;}()).truth()){
            // Phoebe.py:240
            return V(true);
        }
        // Phoebe.py:241
        ([&]()->V{auto fn_427=attr(self_value(),"send_resonance_key");Args args_426;return invoke(fn_427,args_426);}());
        // Phoebe.py:242
        ([&]()->V{auto fn_429=attr(attr(self_value(),"task"),"next_frame");Args args_428;return invoke(fn_429,args_428);}());
    }
    // Phoebe.py:243
    return V(false);
return V{};
}),false);
// Official method Phoebe.confession_ready, lines 245-250
register_method("confession_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_432=bind_arguments(official_args,signature,captured);
scope_432->set("blue_percent",V::missing());
scope_432->set("box",V::missing());
    // Phoebe.py:246
    {V value_433=([&]()->V{auto fn_435=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_434;args_434.pos(V(2560LL));args_434.pos(V(1440LL));args_434.pos(V(2110LL));args_434.pos(V(1236LL));args_434.pos(V(2217LL));args_434.pos(V(1343LL));args_434.kw("name",V("phoebe_resonance"));args_434.kw("hcenter",V(false));return invoke(fn_435,args_434);}());scope_432->set("box",value_433);}
    // Phoebe.py:247
    ([&]()->V{auto fn_437=attr(attr(self_value(),"task"),"draw_boxes");Args args_436;args_436.pos(attr(scope_432->get("box"),"name"));args_436.pos(scope_432->get("box"));return invoke(fn_437,args_436);}());
    // Phoebe.py:248
    {V value_438=([&]()->V{auto fn_440=attr(self_value(),"calculate_color_percentage_in_masked");Args args_439;args_439.pos(global("phoebe_blue_color","Phoebe"));args_439.pos(scope_432->get("box"));args_439.pos(V(0.425));args_439.pos(V(0.49));return invoke(fn_440,args_439);}());scope_432->set("blue_percent",value_438);}
    // Phoebe.py:249
    ([&]()->V{auto fn_442=attr(attr(self_value(),"logger"),"debug");Args args_441;args_441.pos(V(std::string{}+"blue_percent "+format_value(scope_432->get("blue_percent"),"",-1)));return invoke(fn_442,args_441);}());
    // Phoebe.py:250
    return ([&]()->V{V compare_443=scope_432->get("blue_percent");V compare_444;V comparison_result_445;compare_444=V(0.15);comparison_result_445=compare_value(">",compare_443,compare_444);return comparison_result_445;}());
return V{};
}),false);
// Official method Phoebe.heavy_attack_ready, lines 252-253
register_method("heavy_attack_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_446=bind_arguments(official_args,signature,captured);
    // Phoebe.py:253
    return ([&]()->V{auto fn_448=attr(self_value(),"is_forte_full");Args args_447;return invoke(fn_448,args_447);}());
return V{};
}),false);
// Official method Phoebe.calculate_color_percentage_in_masked, lines 255-282
register_method("calculate_color_percentage_in_masked",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"target_color",V::missing()},{"box",V::missing()},{"mask_r1_ratio",V(0.0)},{"mask_r2_ratio",V(0.0)}},"","",{})](const Args& official_args)->V{
auto scope_449=bind_arguments(official_args,signature,captured);
scope_449->set("center",V::missing());
scope_449->set("color_mask",V::missing());
scope_449->set("combined_mask",V::missing());
scope_449->set("cropped",V::missing());
scope_449->set("h",V::missing());
scope_449->set("lower_bound",V::missing());
scope_449->set("match_count",V::missing());
scope_449->set("r1",V::missing());
scope_449->set("r2",V::missing());
scope_449->set("ring_mask",V::missing());
scope_449->set("total_mask_area",V::missing());
scope_449->set("upper_bound",V::missing());
scope_449->set("w",V::missing());
    // Phoebe.py:256
    {V value_450=([&]()->V{auto fn_452=attr(scope_449->get("box"),"crop_frame");Args args_451;args_451.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_452,args_451);}());scope_449->set("cropped",value_450);}
    // Phoebe.py:257
    if(([&]()->V{V operand_453;operand_453=([&]()->V{V compare_454=scope_449->get("cropped");V compare_455;V comparison_result_456;compare_455=V{};comparison_result_456=compare_value("is",compare_454,compare_455);return comparison_result_456;}());if(operand_453.truth())return operand_453;return ([&]()->V{V compare_457=attr(scope_449->get("cropped"),"size");V compare_458;V comparison_result_459;compare_458=V(0LL);comparison_result_459=compare_value("==",compare_457,compare_458);return comparison_result_459;}());}()).truth()){
        // Phoebe.py:258
        return V(0.0);
    }
    // Phoebe.py:259
    {V value_460=item(attr(scope_449->get("cropped"),"shape"),V::slice(V{},V(2LL),V{}));auto unpack_461=unpack(value_460,2);scope_449->set("h",unpack_461[0]);scope_449->set("w",unpack_461[1]);}
    // Phoebe.py:261
    {V value_462=([&]()->V{auto fn_464=global("int","Phoebe");Args args_463;args_463.pos(([&]()->V{auto fn_466=attr(global("math","Phoebe"),"floor");Args args_465;args_465.pos(([&]()->V{V left_467=scope_449->get("h");V right_468=scope_449->get("mask_r1_ratio");return official::binary("*",left_467,right_468);}()));return invoke(fn_466,args_465);}()));return invoke(fn_464,args_463);}());scope_449->set("r1",value_462);}
    // Phoebe.py:262
    {V value_469=([&]()->V{auto fn_471=global("int","Phoebe");Args args_470;args_470.pos(([&]()->V{auto fn_473=attr(global("math","Phoebe"),"ceil");Args args_472;args_472.pos(([&]()->V{V left_474=scope_449->get("h");V right_475=scope_449->get("mask_r2_ratio");return official::binary("*",left_474,right_475);}()));return invoke(fn_473,args_472);}()));return invoke(fn_471,args_470);}());scope_449->set("r2",value_469);}
    // Phoebe.py:263
    if(([&]()->V{V compare_476=scope_449->get("r2");V compare_477;V comparison_result_478;compare_477=scope_449->get("r1");comparison_result_478=compare_value("<=",compare_476,compare_477);return comparison_result_478;}()).truth()){
        // Phoebe.py:264
        return V(0.0);
    }
    // Phoebe.py:266
    {V value_479=V::tuple({([&]()->V{V left_480=scope_449->get("w");V right_481=V(2LL);return official::binary("//",left_480,right_481);}()),([&]()->V{V left_482=scope_449->get("h");V right_483=V(2LL);return official::binary("//",left_482,right_483);}())});scope_449->set("center",value_479);}
    // Phoebe.py:267
    {V value_484=([&]()->V{auto fn_486=attr(global("np","Phoebe"),"zeros");Args args_485;args_485.pos(V::tuple({scope_449->get("h"),scope_449->get("w")}));args_485.kw("dtype",attr(global("np","Phoebe"),"uint8"));return invoke(fn_486,args_485);}());scope_449->set("ring_mask",value_484);}
    // Phoebe.py:268
    ([&]()->V{auto fn_488=attr(global("cv2","Phoebe"),"circle");Args args_487;args_487.pos(scope_449->get("ring_mask"));args_487.pos(scope_449->get("center"));args_487.pos(scope_449->get("r2"));args_487.pos(V(255LL));args_487.pos(unary("-",V(1LL)));return invoke(fn_488,args_487);}());
    // Phoebe.py:269
    if(([&]()->V{V compare_489=scope_449->get("r1");V compare_490;V comparison_result_491;compare_490=V(0LL);comparison_result_491=compare_value(">",compare_489,compare_490);return comparison_result_491;}()).truth()){
        // Phoebe.py:270
        ([&]()->V{auto fn_493=attr(global("cv2","Phoebe"),"circle");Args args_492;args_492.pos(scope_449->get("ring_mask"));args_492.pos(scope_449->get("center"));args_492.pos(scope_449->get("r1"));args_492.pos(V(0LL));args_492.pos(unary("-",V(1LL)));return invoke(fn_493,args_492);}());
    }
    // Phoebe.py:272
    {V value_494=([&]()->V{auto fn_496=global("color_range_to_bound","Phoebe");Args args_495;args_495.pos(scope_449->get("target_color"));return invoke(fn_496,args_495);}());auto unpack_497=unpack(value_494,2);scope_449->set("lower_bound",unpack_497[0]);scope_449->set("upper_bound",unpack_497[1]);}
    // Phoebe.py:274
    {V value_498=([&]()->V{auto fn_500=attr(global("cv2","Phoebe"),"inRange");Args args_499;args_499.pos(scope_449->get("cropped"));args_499.pos(scope_449->get("lower_bound"));args_499.pos(scope_449->get("upper_bound"));return invoke(fn_500,args_499);}());scope_449->set("color_mask",value_498);}
    // Phoebe.py:276
    {V value_501=([&]()->V{auto fn_503=attr(global("cv2","Phoebe"),"bitwise_and");Args args_502;args_502.pos(scope_449->get("color_mask"));args_502.pos(scope_449->get("ring_mask"));return invoke(fn_503,args_502);}());scope_449->set("combined_mask",value_501);}
    // Phoebe.py:278
    {V value_504=([&]()->V{auto fn_506=attr(global("cv2","Phoebe"),"countNonZero");Args args_505;args_505.pos(scope_449->get("combined_mask"));return invoke(fn_506,args_505);}());scope_449->set("match_count",value_504);}
    // Phoebe.py:279
    {V value_507=([&]()->V{auto fn_509=attr(global("cv2","Phoebe"),"countNonZero");Args args_508;args_508.pos(scope_449->get("ring_mask"));return invoke(fn_509,args_508);}());scope_449->set("total_mask_area",value_507);}
    // Phoebe.py:280
    if(([&]()->V{V compare_510=scope_449->get("total_mask_area");V compare_511;V comparison_result_512;compare_511=V(0LL);comparison_result_512=compare_value("==",compare_510,compare_511);return comparison_result_512;}()).truth()){
        // Phoebe.py:281
        return V(0.0);
    }
    // Phoebe.py:282
    return ([&]()->V{V left_513=scope_449->get("match_count");V right_514=scope_449->get("total_mask_area");return official::binary("/",left_513,right_514);}());
return V{};
}),false);
// Official method Phoebe.get_prayer_condition, lines 284-290
register_method("get_prayer_condition",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_515=bind_arguments(official_args,signature,captured);
    // Phoebe.py:285
    if(unary("not",([&]()->V{auto fn_517=attr(self_value(),"check_middle_star");Args args_516;return invoke(fn_517,args_516);}())).truth()){
        // Phoebe.py:286
        return attr(self_value(),"is_forte_full");
    }else{
        // Phoebe.py:287
        if(([&]()->V{auto fn_519=attr(self_value(),"confession_ready");Args args_518;return invoke(fn_519,args_518);}()).truth()){
            // Phoebe.py:288
            return attr(self_value(),"confession_ready");
        }else{
            // Phoebe.py:290
            return V::function([this,captured=capture_scope(scope_515,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_520=bind_arguments(official_args,signature,captured);
return V(false);
});
        }
    }
return V{};
}),false);
// Official method Phoebe.absolution_or_confession, lines 292-327
register_method("absolution_or_confession",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_521=bind_arguments(official_args,signature,captured);
scope_521->set("condition",V::missing());
scope_521->set("key_down",V::missing());
scope_521->set("key_hold_start",V::missing());
scope_521->set("key_up",V::missing());
scope_521->set("outer_start",V::missing());
    // Phoebe.py:293
    ([&]()->V{auto fn_523=attr(attr(self_value(),"task"),"wait_in_team_and_world");Args args_522;args_522.kw("time_out",V(3LL));args_522.kw("raise_if_not_found",V(false));return invoke(fn_523,args_522);}());
    // Phoebe.py:294
    {V value_524=([&]()->V{auto fn_526=attr(self_value(),"get_prayer_condition");Args args_525;return invoke(fn_526,args_525);}());scope_521->set("condition",value_524);}
    // Phoebe.py:295
    if(([&]()->V{V compare_527=attr(self_value(),"attribute");V compare_528;V comparison_result_529;compare_528=V(2LL);comparison_result_529=compare_value("==",compare_527,compare_528);return comparison_result_529;}()).truth()){
        // Phoebe.py:296
        {V value_530=V::function([this,captured=capture_scope(scope_521,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_531=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_533=attr(attr(self_value(),"task"),"send_key_down");Args args_532;args_532.pos(([&]()->V{auto fn_535=attr(self_value(),"get_resonance_key");Args args_534;return invoke(fn_535,args_534);}()));return invoke(fn_533,args_532);}());
});scope_521->set("key_down",value_530);}
        // Phoebe.py:297
        {V value_536=V::function([this,captured=capture_scope(scope_521,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_537=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_539=attr(attr(self_value(),"task"),"send_key_up");Args args_538;args_538.pos(([&]()->V{auto fn_541=attr(self_value(),"get_resonance_key");Args args_540;return invoke(fn_541,args_540);}()));return invoke(fn_539,args_538);}());
});scope_521->set("key_up",value_536);}
    }else{
        // Phoebe.py:299
        {V value_542=V::tuple({attr(attr(self_value(),"task"),"mouse_down"),attr(attr(self_value(),"task"),"mouse_up")});auto unpack_543=unpack(value_542,2);scope_521->set("key_down",unpack_543[0]);scope_521->set("key_up",unpack_543[1]);}
    }
    // Phoebe.py:300
    if(([&]()->V{auto fn_545=scope_521->get("condition");Args args_544;return invoke(fn_545,args_544);}()).truth()){
        // Phoebe.py:301
        {V value_546=([&]()->V{auto fn_548=attr(global("time","Phoebe"),"time");Args args_547;return invoke(fn_548,args_547);}());scope_521->set("outer_start",value_546);}
        // Phoebe.py:302
                while(([&]()->V{auto fn_600=scope_521->get("condition");Args args_599;return invoke(fn_600,args_599);}()).truth()){
            // Phoebe.py:303
            if(([&]()->V{V compare_549=([&]()->V{V left_551=([&]()->V{auto fn_554=attr(global("time","Phoebe"),"time");Args args_553;return invoke(fn_554,args_553);}());V right_552=scope_521->get("outer_start");return official::binary("-",left_551,right_552);}());V compare_550;V comparison_result_555;compare_550=V(2LL);comparison_result_555=compare_value(">",compare_549,compare_550);return comparison_result_555;}()).truth()){
                // Phoebe.py:304
                return attr(global("State","Phoebe"),"TIMEOUT");
            }
            // Phoebe.py:305
            ([&]()->V{auto fn_557=scope_521->get("key_down");Args args_556;return invoke(fn_557,args_556);}());
            // Phoebe.py:306
            {V value_558=([&]()->V{auto fn_560=attr(global("time","Phoebe"),"time");Args args_559;return invoke(fn_560,args_559);}());scope_521->set("key_hold_start",value_558);}
            // Phoebe.py:307
                        while(([&]()->V{V operand_570;operand_570=([&]()->V{auto fn_572=scope_521->get("condition");Args args_571;return invoke(fn_572,args_571);}());if(operand_570.truth())return operand_570;return ([&]()->V{V compare_573=([&]()->V{V left_575=([&]()->V{auto fn_578=attr(global("time","Phoebe"),"time");Args args_577;return invoke(fn_578,args_577);}());V right_576=scope_521->get("key_hold_start");return official::binary("-",left_575,right_576);}());V compare_574;V comparison_result_579;compare_574=V(0.4);comparison_result_579=compare_value("<",compare_573,compare_574);return comparison_result_579;}());}()).truth()){
                // Phoebe.py:308
                if(([&]()->V{V compare_561=([&]()->V{V left_563=([&]()->V{auto fn_566=attr(global("time","Phoebe"),"time");Args args_565;return invoke(fn_566,args_565);}());V right_564=scope_521->get("key_hold_start");return official::binary("-",left_563,right_564);}());V compare_562;V comparison_result_567;compare_562=V(1LL);comparison_result_567=compare_value(">",compare_561,compare_562);return comparison_result_567;}()).truth()){
                    // Phoebe.py:309
                    break;
                }
                // Phoebe.py:310
                ([&]()->V{auto fn_569=attr(attr(self_value(),"task"),"next_frame");Args args_568;return invoke(fn_569,args_568);}());
            }
            // Phoebe.py:311
            ([&]()->V{auto fn_581=scope_521->get("key_up");Args args_580;return invoke(fn_581,args_580);}());
            // Phoebe.py:312
            if(([&]()->V{auto fn_583=attr(self_value(),"flying");Args args_582;return invoke(fn_583,args_582);}()).truth()){
                // Phoebe.py:313
                ([&]()->V{auto fn_585=attr(attr(self_value(),"logger"),"info");Args args_584;args_584.pos(V("flying"));return invoke(fn_585,args_584);}());
                // Phoebe.py:314
                ([&]()->V{auto fn_587=attr(attr(self_value(),"task"),"wait_until");Args args_586;args_586.pos(V::function([this,captured=capture_scope(scope_521,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_588=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_590=attr(self_value(),"flying");Args args_589;return invoke(fn_590,args_589);}()));
}));args_586.kw("post_action",V::function([this,captured=capture_scope(scope_521,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_591=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_593=attr(self_value(),"click");Args args_592;args_592.kw("interval",V(0.1));args_592.kw("after_sleep",V(0.1));return invoke(fn_593,args_592);}());
}));args_586.kw("time_out",V(2LL));return invoke(fn_587,args_586);}());
                // Phoebe.py:316
                {V value_594=([&]()->V{auto fn_596=attr(global("time","Phoebe"),"time");Args args_595;return invoke(fn_596,args_595);}());scope_521->set("outer_start",value_594);}
            }
            // Phoebe.py:317
            ([&]()->V{auto fn_598=attr(attr(self_value(),"task"),"next_frame");Args args_597;return invoke(fn_598,args_597);}());
        }
        // Phoebe.py:318
        if(([&]()->V{V compare_601=attr(self_value(),"attribute");V compare_602;V comparison_result_603;compare_602=V(2LL);comparison_result_603=compare_value("==",compare_601,compare_602);return comparison_result_603;}()).truth()){
            // Phoebe.py:319
            ([&]()->V{auto fn_605=attr(attr(self_value(),"logger"),"info");Args args_604;args_604.pos(V("Enters confession status"));return invoke(fn_605,args_604);}());
        }else{
            // Phoebe.py:321
            ([&]()->V{auto fn_607=attr(attr(self_value(),"logger"),"info");Args args_606;args_606.pos(V("Enters absolution status"));return invoke(fn_607,args_606);}());
        }
        // Phoebe.py:322
        ([&]()->V{auto fn_609=attr(self_value(),"continues_right_click");Args args_608;args_608.pos(V(0.05));return invoke(fn_609,args_608);}());
        // Phoebe.py:323
        {V value_610=V(true);set_attr(self_value(),"star_available",value_610);}
        // Phoebe.py:324
        ([&]()->V{auto fn_612=attr(self_value(),"reset_action");Args args_611;return invoke(fn_612,args_611);}());
        // Phoebe.py:325
        set_item(attr(self_value(),"state"),V("enter_status"),official::binary("+",item(attr(self_value(),"state"),V("enter_status")),V(1LL)));
        // Phoebe.py:326
        return attr(global("State","Phoebe"),"SUCCESS");
    }
    // Phoebe.py:327
    return attr(global("State","Phoebe"),"UNAVAILABLE");
return V{};
}),false);
// Official method Phoebe._try_liberation_now, lines 329-338
register_method("_try_liberation_now",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_613=bind_arguments(official_args,signature,captured);
    // Phoebe.py:331
    if(([&]()->V{V operand_614;operand_614=attr(self_value(),"star_available");if(!operand_614.truth())return operand_614;operand_614=unary("not",([&]()->V{auto fn_616=attr(self_value(),"flying");Args args_615;return invoke(fn_616,args_615);}()));if(!operand_614.truth())return operand_614;return ([&]()->V{auto fn_618=attr(self_value(),"liberation_available");Args args_617;return invoke(fn_618,args_617);}());}()).truth()){
        // Phoebe.py:333
        if(([&]()->V{auto fn_620=attr(self_value(),"click_liberation");Args args_619;args_619.kw("send_click",V(true));return invoke(fn_620,args_619);}()).truth()){
            // Phoebe.py:334
            set_item(attr(self_value(),"state"),V("liberation"),official::binary("+",item(attr(self_value(),"state"),V("liberation")),V(1LL)));
            // Phoebe.py:335
            {V value_621=V(1LL);set_item(attr(self_value(),"state"),V("priority_liberation_cast"),value_621);}
            // Phoebe.py:336
            ([&]()->V{auto fn_623=attr(self_value(),"check_combat");Args args_622;return invoke(fn_623,args_622);}());
            // Phoebe.py:337
            return V(true);
        }
    }
    // Phoebe.py:338
    return V(false);
return V{};
}),false);
// Official method Phoebe._try_cast_liberation_before_switch, lines 340-357
register_method("_try_cast_liberation_before_switch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_624=bind_arguments(official_args,signature,captured);
    // Phoebe.py:343
    if(([&]()->V{V compare_625=attr(self_value(),"attribute");V compare_626;V comparison_result_627;compare_626=V(2LL);comparison_result_627=compare_value("!=",compare_625,compare_626);return comparison_result_627;}()).truth()){
        // Phoebe.py:344
        return V(false);
    }
    // Phoebe.py:345
    if(([&]()->V{auto fn_629=attr(attr(self_value(),"state"),"get");Args args_628;args_628.pos(V("priority_liberation_cast"));return invoke(fn_629,args_628);}()).truth()){
        // Phoebe.py:346
        return V(false);
    }
    // Phoebe.py:347
    if(([&]()->V{V operand_630;operand_630=unary("not",attr(self_value(),"star_available"));if(operand_630.truth())return operand_630;return ([&]()->V{auto fn_632=attr(self_value(),"flying");Args args_631;return invoke(fn_632,args_631);}());}()).truth()){
        // Phoebe.py:348
        return V(false);
    }
    // Phoebe.py:349
    if(unary("not",([&]()->V{auto fn_634=attr(self_value(),"liberation_available");Args args_633;return invoke(fn_634,args_633);}())).truth()){
        // Phoebe.py:350
        return V(false);
    }
    // Phoebe.py:351
    ([&]()->V{auto fn_636=attr(attr(self_value(),"logger"),"info");Args args_635;args_635.pos(V("cast available liberation before switch"));return invoke(fn_636,args_635);}());
    // Phoebe.py:352
    if(([&]()->V{auto fn_638=attr(self_value(),"click_liberation");Args args_637;args_637.kw("send_click",V(true));return invoke(fn_638,args_637);}()).truth()){
        // Phoebe.py:353
        {V value_639=V(1LL);set_item(attr(self_value(),"state"),V("priority_liberation_cast"),value_639);}
        // Phoebe.py:354
        set_item(attr(self_value(),"state"),V("liberation"),official::binary("+",item(attr(self_value(),"state"),V("liberation")),V(1LL)));
        // Phoebe.py:355
        ([&]()->V{auto fn_641=attr(self_value(),"check_combat");Args args_640;return invoke(fn_641,args_640);}());
        // Phoebe.py:356
        return V(true);
    }
    // Phoebe.py:357
    return V(false);
return V{};
}),false);
// Official method Phoebe.switch_next_char, lines 359-364
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_642=bind_arguments(official_args,signature,captured);
    // Phoebe.py:360
    ([&]()->V{auto fn_644=attr(self_value(),"_try_cast_liberation_before_switch");Args args_643;return invoke(fn_644,args_643);}());
    // Phoebe.py:361
    if(([&]()->V{V operand_645;operand_645=([&]()->V{V compare_646=attr(self_value(),"attribute");V compare_647;V comparison_result_648;compare_647=V(2LL);comparison_result_648=compare_value("==",compare_646,compare_647);return comparison_result_648;}());if(!operand_645.truth())return operand_645;return ([&]()->V{auto fn_650=attr(self_value(),"is_con_full");Args args_649;return invoke(fn_650,args_649);}());}()).truth()){
        // Phoebe.py:362
        ([&]()->V{auto fn_652=attr(self_value(),"click_echo");Args args_651;return invoke(fn_652,args_651);}());
        // Phoebe.py:363
        set_item(attr(self_value(),"state"),V("outro"),official::binary("+",item(attr(self_value(),"state"),V("outro")),V(1LL)));
    }
    // Phoebe.py:364
    return ([&]()->V{auto fn_656=attr(([&]()->V{auto fn_654=global("super","Phoebe");Args args_653;return invoke(fn_654,args_653);}()),"switch_next_char");Args args_655;args_655.spread(scope_642->get("args"));args_655.spread_keywords(scope_642->get("kwargs"));return invoke(fn_656,args_655);}());
return V{};
}),false);
// Official method Phoebe.get_switch_priority, lines 366-371
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_657=bind_arguments(official_args,signature,captured);
    // Phoebe.py:367
    if(([&]()->V{V operand_658;operand_658=unary("not",scope_657->get("has_intro"));if(!operand_658.truth())return operand_658;operand_658=([&]()->V{V compare_659=attr(self_value(),"last_outro_time");V compare_660;V comparison_result_661;compare_660=V(0LL);comparison_result_661=compare_value(">",compare_659,compare_660);return comparison_result_661;}());if(!operand_658.truth())return operand_658;return ([&]()->V{V compare_662=([&]()->V{auto fn_665=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_664;args_664.pos(attr(self_value(),"last_outro_time"));args_664.kw("intro_motion_freeze",V(true));return invoke(fn_665,args_664);}());V compare_663;V comparison_result_666;compare_663=V(4.5);comparison_result_666=compare_value("<",compare_662,compare_663);return comparison_result_666;}());}()).truth()){
        // Phoebe.py:369
        ([&]()->V{auto fn_668=attr(attr(self_value(),"logger"),"info");Args args_667;args_667.pos(V("performing outro, switch priority no"));return invoke(fn_668,args_667);}());
        // Phoebe.py:370
        return attr(global("SwitchPriority","Phoebe"),"NO");
    }
    // Phoebe.py:371
    return ([&]()->V{auto fn_672=attr(([&]()->V{auto fn_670=global("super","Phoebe");Args args_669;return invoke(fn_670,args_669);}()),"get_switch_priority");Args args_671;args_671.pos(scope_657->get("current_char"));args_671.pos(scope_657->get("has_intro"));args_671.pos(scope_657->get("target_low_con"));return invoke(fn_672,args_671);}());
return V{};
}),false);
// Official method Phoebe.check_middle_star, lines 373-390
register_method("check_middle_star",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_673=bind_arguments(official_args,signature,captured);
scope_673->set("box",V::missing());
scope_673->set("forte_percent",V::missing());
    // Phoebe.py:374
    if(attr(self_value(),"star_available").truth()){
        // Phoebe.py:375
        return V(true);
    }
    // Phoebe.py:376
    {V value_674=([&]()->V{auto fn_676=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_675;args_675.pos(V(3840LL));args_675.pos(V(2160LL));args_675.pos(V(1890LL));args_675.pos(V(2010LL));args_675.pos(V(1915LL));args_675.pos(V(2030LL));args_675.kw("name",V("phoebe_middle_star"));args_675.kw("hcenter",V(true));return invoke(fn_676,args_675);}());scope_673->set("box",value_674);}
    // Phoebe.py:378
    if(([&]()->V{V compare_677=attr(self_value(),"attribute");V compare_678;V comparison_result_679;compare_678=V(1LL);comparison_result_679=compare_value("==",compare_677,compare_678);return comparison_result_679;}()).truth()){
        // Phoebe.py:379
        {V value_680=([&]()->V{auto fn_682=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_681;args_681.pos(global("phoebe_star_light_color","Phoebe"));args_681.pos(scope_673->get("box"));return invoke(fn_682,args_681);}());scope_673->set("forte_percent",value_680);}
        // Phoebe.py:380
        ([&]()->V{auto fn_684=attr(attr(self_value(),"logger"),"debug");Args args_683;args_683.pos(V(std::string{}+"middle_star_light_percent "+format_value(scope_673->get("forte_percent"),"",-1)));return invoke(fn_684,args_683);}());
        // Phoebe.py:381
        if(([&]()->V{V compare_685=scope_673->get("forte_percent");V compare_686;V comparison_result_687;compare_686=V(0.25);comparison_result_687=compare_value(">",compare_685,compare_686);return comparison_result_687;}()).truth()){
            // Phoebe.py:382
            {V value_688=V(true);set_attr(self_value(),"star_available",value_688);}
            // Phoebe.py:383
            return V(true);
        }
    }else{
        // Phoebe.py:384
        if(([&]()->V{V compare_689=attr(self_value(),"attribute");V compare_690;V comparison_result_691;compare_690=V(2LL);comparison_result_691=compare_value("==",compare_689,compare_690);return comparison_result_691;}()).truth()){
            // Phoebe.py:385
            {V value_692=([&]()->V{auto fn_694=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_693;args_693.pos(global("phoebe_star_blue_color","Phoebe"));args_693.pos(scope_673->get("box"));return invoke(fn_694,args_693);}());scope_673->set("forte_percent",value_692);}
            // Phoebe.py:386
            ([&]()->V{auto fn_696=attr(attr(self_value(),"logger"),"debug");Args args_695;args_695.pos(V(std::string{}+"middle_star_blue_percent "+format_value(scope_673->get("forte_percent"),"",-1)));return invoke(fn_696,args_695);}());
            // Phoebe.py:387
            if(([&]()->V{V compare_697=scope_673->get("forte_percent");V compare_698;V comparison_result_699;compare_698=V(0.25);comparison_result_699=compare_value(">",compare_697,compare_698);return comparison_result_699;}()).truth()){
                // Phoebe.py:388
                {V value_700=V(true);set_attr(self_value(),"star_available",value_700);}
                // Phoebe.py:389
                return V(true);
            }
        }
    }
    // Phoebe.py:390
    return V(false);
return V{};
}),false);
// Official method Phoebe.decide_teammate, lines 392-403
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_701=bind_arguments(official_args,signature,captured);
scope_701->set("Cartethyia",V::missing());
scope_701->set("Rover",V::missing());
scope_701->set("Zani",V::missing());
scope_701->set("char",V::missing());
    // Phoebe.py:393
    scope_701->set("Zani",import_value("src.char.Zani","Zani"));
    // Phoebe.py:394
    scope_701->set("Cartethyia",import_value("src.char.Cartethyia","Cartethyia"));
    // Phoebe.py:395
    scope_701->set("Rover",import_value("src.char.Rover","Rover"));
    // Phoebe.py:396
    if(([&]()->V{V assigned_702=([&]()->V{auto fn_704=attr(attr(self_value(),"task"),"has_char");Args args_703;args_703.pos(scope_701->get("Zani"));return invoke(fn_704,args_703);}());scope_701->set("char",assigned_702);return assigned_702;}()).truth()){
        // Phoebe.py:397
        {V value_705=scope_701->get("char");set_attr(self_value(),"char_zani",value_705);}
        // Phoebe.py:398
        {V value_706=V(2LL);set_attr(self_value(),"attribute",value_706);}
    }else{
        // Phoebe.py:399
        if(([&]()->V{V operand_707;operand_707=([&]()->V{auto fn_709=attr(attr(self_value(),"task"),"has_char");Args args_708;args_708.pos(scope_701->get("Cartethyia"));return invoke(fn_709,args_708);}());if(!operand_707.truth())return operand_707;return ([&]()->V{auto fn_711=attr(attr(self_value(),"task"),"has_char");Args args_710;args_710.pos(scope_701->get("Rover"));return invoke(fn_711,args_710);}());}()).truth()){
            // Phoebe.py:400
            {V value_712=V(2LL);set_attr(self_value(),"attribute",value_712);}
        }else{
            // Phoebe.py:402
            {V value_713=V(1LL);set_attr(self_value(),"attribute",value_713);}
        }
    }
    // Phoebe.py:403
    ([&]()->V{auto fn_715=attr(attr(self_value(),"logger"),"debug");Args args_714;args_714.pos(V(std::string{}+"set attribute: "+format_value((([&]()->V{V compare_716=attr(self_value(),"attribute");V compare_717;V comparison_result_718;compare_717=V(2LL);comparison_result_718=compare_value("==",compare_716,compare_717);return comparison_result_718;}()).truth()?V("support"):V("attacker")),"",-1)));return invoke(fn_715,args_714);}());
return V{};
}),false);
// Official method Phoebe.judge_frequncy_and_amplitude, lines 405-422
register_method("judge_frequncy_and_amplitude",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"min_freq",V::missing()},{"max_freq",V::missing()},{"min_amp",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_719=bind_arguments(official_args,signature,captured);
scope_719->set("amplitude",V::missing());
scope_719->set("frequncy",V::missing());
scope_719->set("height",V::missing());
scope_719->set("i",V::missing());
scope_719->set("n",V::missing());
scope_719->set("profile",V::missing());
scope_719->set("white_ratio",V::missing());
scope_719->set("width",V::missing());
    // Phoebe.py:406
    {V value_720=item(attr(scope_719->get("gray"),"shape"),V::slice(V{},V{},V{}));auto unpack_721=unpack(value_720,2);scope_719->set("height",unpack_721[0]);scope_719->set("width",unpack_721[1]);}
    // Phoebe.py:407
    if(([&]()->V{V operand_722;operand_722=([&]()->V{V compare_723=scope_719->get("height");V compare_724;V comparison_result_725;compare_724=V(0LL);comparison_result_725=compare_value("==",compare_723,compare_724);return comparison_result_725;}());if(operand_722.truth())return operand_722;operand_722=([&]()->V{V compare_726=scope_719->get("width");V compare_727;V comparison_result_728;compare_727=V(64LL);comparison_result_728=compare_value("<",compare_726,compare_727);return comparison_result_728;}());if(operand_722.truth())return operand_722;return unary("not",([&]()->V{auto fn_730=attr(global("np","Phoebe"),"array_equal");Args args_729;args_729.pos(([&]()->V{auto fn_732=attr(global("np","Phoebe"),"unique");Args args_731;args_731.pos(scope_719->get("gray"));return invoke(fn_732,args_731);}()));args_729.pos(V::list({V(0LL),V(255LL)}));return invoke(fn_730,args_729);}()));}()).truth()){
        // Phoebe.py:408
        return V(0LL);
    }
    // Phoebe.py:410
    {V value_733=([&]()->V{V left_734=([&]()->V{auto fn_737=attr(global("np","Phoebe"),"count_nonzero");Args args_736;args_736.pos(([&]()->V{V compare_738=scope_719->get("gray");V compare_739;V comparison_result_740;compare_739=V(255LL);comparison_result_740=compare_value("==",compare_738,compare_739);return comparison_result_740;}()));return invoke(fn_737,args_736);}());V right_735=attr(scope_719->get("gray"),"size");return official::binary("/",left_734,right_735);}());scope_719->set("white_ratio",value_733);}
    // Phoebe.py:411
    {V value_741=([&]()->V{auto fn_748=attr(([&]()->V{auto fn_743=attr(global("np","Phoebe"),"sum");Args args_742;args_742.pos(([&]()->V{V compare_744=scope_719->get("gray");V compare_745;V comparison_result_746;compare_745=V(255LL);comparison_result_746=compare_value("==",compare_744,compare_745);return comparison_result_746;}()));args_742.kw("axis",V(0LL));return invoke(fn_743,args_742);}()),"astype");Args args_747;args_747.pos(attr(global("np","Phoebe"),"float32"));return invoke(fn_748,args_747);}());scope_719->set("profile",value_741);}
    // Phoebe.py:412
    scope_719->set("profile",official::binary("-",scope_719->get("profile"),([&]()->V{auto fn_750=attr(global("np","Phoebe"),"mean");Args args_749;args_749.pos(scope_719->get("profile"));return invoke(fn_750,args_749);}())));
    // Phoebe.py:413
    {V value_751=([&]()->V{auto fn_753=attr(global("np","Phoebe"),"abs");Args args_752;args_752.pos(([&]()->V{auto fn_755=attr(attr(global("np","Phoebe"),"fft"),"fft");Args args_754;args_754.pos(scope_719->get("profile"));return invoke(fn_755,args_754);}()));return invoke(fn_753,args_752);}());scope_719->set("n",value_751);}
    // Phoebe.py:414
    {V value_756=V(0LL);scope_719->set("amplitude",value_756);}
    // Phoebe.py:415
    {V value_757=V(0LL);scope_719->set("frequncy",value_757);}
    // Phoebe.py:416
    {V value_758=V(1LL);scope_719->set("i",value_758);}
    // Phoebe.py:417
        while(([&]()->V{V compare_764=scope_719->get("i");V compare_765;V comparison_result_766;compare_765=scope_719->get("width");comparison_result_766=compare_value("<",compare_764,compare_765);return comparison_result_766;}()).truth()){
        // Phoebe.py:418
        if(([&]()->V{V compare_759=item(scope_719->get("n"),scope_719->get("i"));V compare_760;V comparison_result_761;compare_760=scope_719->get("amplitude");comparison_result_761=compare_value(">",compare_759,compare_760);return comparison_result_761;}()).truth()){
            // Phoebe.py:419
            {V value_762=item(scope_719->get("n"),scope_719->get("i"));scope_719->set("amplitude",value_762);}
            // Phoebe.py:420
            {V value_763=scope_719->get("i");scope_719->set("frequncy",value_763);}
        }
        // Phoebe.py:421
        scope_719->set("i",official::binary("+",scope_719->get("i"),V(1LL)));
    }
    // Phoebe.py:422
    return ([&]()->V{V operand_767;operand_767=([&]()->V{V compare_768=scope_719->get("min_freq");V compare_769;V comparison_result_770;compare_769=scope_719->get("i");comparison_result_770=compare_value("<=",compare_768,compare_769);if(!comparison_result_770.truth())return comparison_result_770;compare_768=compare_769;compare_769=scope_719->get("max_freq");comparison_result_770=compare_value("<=",compare_768,compare_769);return comparison_result_770;}());if(operand_767.truth())return operand_767;return ([&]()->V{V compare_771=scope_719->get("amplitude");V compare_772;V comparison_result_773;compare_772=scope_719->get("min_amp");comparison_result_773=compare_value(">=",compare_771,compare_772);return comparison_result_773;}());}());
return V{};
}),false);
// Official method Phoebe.calculate_forte_num, lines 424-452
register_method("calculate_forte_num",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()},{"num",V(1LL)},{"min_freq",V(39LL)},{"max_freq",V(41LL)},{"min_amp",V(50LL)}},"","",{})](const Args& official_args)->V{
auto scope_774=bind_arguments(official_args,signature,captured);
scope_774->set("cropped",V::missing());
scope_774->set("fail_count",V::missing());
scope_774->set("forte",V::missing());
scope_774->set("gray",V::missing());
scope_774->set("height",V::missing());
scope_774->set("image",V::missing());
scope_774->set("left",V::missing());
scope_774->set("lower_bound",V::missing());
scope_774->set("score",V::missing());
scope_774->set("step",V::missing());
scope_774->set("upper_bound",V::missing());
scope_774->set("warning",V::missing());
scope_774->set("width",V::missing());
    // Phoebe.py:425
    {V value_775=([&]()->V{auto fn_777=attr(scope_774->get("box"),"crop_frame");Args args_776;args_776.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_777,args_776);}());scope_774->set("cropped",value_775);}
    // Phoebe.py:426
    {V value_778=([&]()->V{auto fn_780=global("color_range_to_bound","Phoebe");Args args_779;args_779.pos(scope_774->get("forte_color"));return invoke(fn_780,args_779);}());auto unpack_781=unpack(value_778,2);scope_774->set("lower_bound",unpack_781[0]);scope_774->set("upper_bound",unpack_781[1]);}
    // Phoebe.py:427
    {V value_782=([&]()->V{auto fn_784=attr(global("cv2","Phoebe"),"inRange");Args args_783;args_783.pos(scope_774->get("cropped"));args_783.pos(scope_774->get("lower_bound"));args_783.pos(scope_774->get("upper_bound"));return invoke(fn_784,args_783);}());scope_774->set("image",value_782);}
    // Phoebe.py:429
    {V value_785=V(0LL);scope_774->set("forte",value_785);}
    // Phoebe.py:430
    {V value_786=attr(scope_774->get("image"),"shape");auto unpack_787=unpack(value_786,2);scope_774->set("height",unpack_787[0]);scope_774->set("width",unpack_787[1]);}
    // Phoebe.py:431
    {V value_788=([&]()->V{auto fn_790=global("int","Phoebe");Args args_789;args_789.pos(([&]()->V{V left_791=scope_774->get("width");V right_792=scope_774->get("num");return official::binary("/",left_791,right_792);}()));return invoke(fn_790,args_789);}());scope_774->set("step",value_788);}
    // Phoebe.py:432
    {V value_793=V(0LL);scope_774->set("left",value_793);}
    // Phoebe.py:433
    {V value_794=V(0LL);scope_774->set("fail_count",value_794);}
    // Phoebe.py:434
    {V value_795=V(false);scope_774->set("warning",value_795);}
    // Phoebe.py:435
        while(([&]()->V{V compare_806=([&]()->V{V left_808=scope_774->get("left");V right_809=scope_774->get("step");return official::binary("+",left_808,right_809);}());V compare_807;V comparison_result_810;compare_807=scope_774->get("width");comparison_result_810=compare_value("<",compare_806,compare_807);return comparison_result_810;}()).truth()){
        // Phoebe.py:436
        {V value_796=item(scope_774->get("image"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_774->get("left"),([&]()->V{V left_797=scope_774->get("left");V right_798=scope_774->get("step");return official::binary("+",left_797,right_798);}()),V{})}));scope_774->set("gray",value_796);}
        // Phoebe.py:437
        {V value_799=([&]()->V{auto fn_801=attr(self_value(),"judge_frequncy_and_amplitude");Args args_800;args_800.pos(scope_774->get("gray"));args_800.pos(scope_774->get("min_freq"));args_800.pos(scope_774->get("max_freq"));args_800.pos(scope_774->get("min_amp"));return invoke(fn_801,args_800);}());scope_774->set("score",value_799);}
        // Phoebe.py:438
        if(([&]()->V{V compare_802=scope_774->get("fail_count");V compare_803;V comparison_result_804;compare_803=V(0LL);comparison_result_804=compare_value("==",compare_802,compare_803);return comparison_result_804;}()).truth()){
            // Phoebe.py:439
            if(scope_774->get("score").truth()){
                // Phoebe.py:440
                scope_774->set("forte",official::binary("+",scope_774->get("forte"),V(1LL)));
            }else{
                // Phoebe.py:442
                scope_774->set("fail_count",official::binary("+",scope_774->get("fail_count"),V(1LL)));
            }
        }else{
            // Phoebe.py:444
            if(scope_774->get("score").truth()){
                // Phoebe.py:445
                {V value_805=V(true);scope_774->set("warning",value_805);}
            }else{
                // Phoebe.py:447
                scope_774->set("fail_count",official::binary("+",scope_774->get("fail_count"),V(1LL)));
            }
        }
        // Phoebe.py:448
        scope_774->set("left",official::binary("+",scope_774->get("left"),scope_774->get("step")));
    }
    // Phoebe.py:449
    if(scope_774->get("warning").truth()){
        // Phoebe.py:450
        ([&]()->V{auto fn_812=attr(attr(self_value(),"logger"),"debug");Args args_811;args_811.pos(V("Frequncy analysis error, return the forte before mistake."));return invoke(fn_812,args_811);}());
    }
    // Phoebe.py:451
    ([&]()->V{auto fn_814=attr(attr(self_value(),"logger"),"debug");Args args_813;args_813.pos(V(std::string{}+"Frequncy analysis with forte "+format_value(scope_774->get("forte"),"",-1)));return invoke(fn_814,args_813);}());
    // Phoebe.py:452
    return scope_774->get("forte");
return V{};
}),false);
// Official method Phoebe.get_zani_state, lines 454-456
register_method("get_zani_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_815=bind_arguments(official_args,signature,captured);
    // Phoebe.py:455
    if(([&]()->V{V operand_816;operand_816=([&]()->V{V compare_817=attr(self_value(),"attribute");V compare_818;V comparison_result_819;compare_818=V(2LL);comparison_result_819=compare_value("==",compare_817,compare_818);return comparison_result_819;}());if(!operand_816.truth())return operand_816;return ([&]()->V{V compare_820=attr(self_value(),"char_zani");V compare_821;V comparison_result_822;compare_821=V{};comparison_result_822=compare_value("is not",compare_820,compare_821);return comparison_result_822;}());}()).truth()){
        // Phoebe.py:456
        return ([&]()->V{auto fn_824=attr(attr(self_value(),"char_zani"),"get_state");Args args_823;return invoke(fn_824,args_823);}());
    }
return V{};
}),false);
// Official method Phoebe.is_action_complete, lines 458-465
register_method("is_action_complete",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_825=bind_arguments(official_args,signature,captured);
    // Phoebe.py:459
    if(([&]()->V{V compare_826=attr(self_value(),"attribute");V compare_827;V comparison_result_828;compare_827=V(2LL);comparison_result_828=compare_value("!=",compare_826,compare_827);return comparison_result_828;}()).truth()){
        // Phoebe.py:460
        return V(false);
    }
    // Phoebe.py:461
    ([&]()->V{auto fn_830=attr(attr(self_value(),"logger"),"debug");Args args_829;args_829.pos(V(std::string{}+"state_liberation "+format_value(item(attr(self_value(),"state"),V("liberation")),"",-1)+" state_starflash_combo "+format_value(item(attr(self_value(),"state"),V("starflash_combo")),"",-1)));return invoke(fn_830,args_829);}());
    // Phoebe.py:463
    if(([&]()->V{V operand_831;operand_831=([&]()->V{V compare_832=item(attr(self_value(),"state"),V("liberation"));V compare_833;V comparison_result_834;compare_833=V(1LL);comparison_result_834=compare_value(">=",compare_832,compare_833);return comparison_result_834;}());if(!operand_831.truth())return operand_831;return ([&]()->V{V compare_835=item(attr(self_value(),"state"),V("starflash_combo"));V compare_836;V comparison_result_837;compare_836=V(2LL);comparison_result_837=compare_value(">=",compare_835,compare_836);return comparison_result_837;}());}()).truth()){
        // Phoebe.py:464
        return V(true);
    }
    // Phoebe.py:465
    return V(false);
return V{};
}),false);
// Official method Phoebe.reset_action, lines 467-476
register_method("reset_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_838=bind_arguments(official_args,signature,captured);
    // Phoebe.py:468
    if(([&]()->V{V compare_839=attr(self_value(),"attribute");V compare_840;V comparison_result_841;compare_840=V(2LL);comparison_result_841=compare_value("==",compare_839,compare_840);return comparison_result_841;}()).truth()){
        // Phoebe.py:469
        ([&]()->V{auto fn_843=attr(attr(self_value(),"logger"),"info");Args args_842;args_842.pos(V("reset action"));return invoke(fn_843,args_842);}());
        // Phoebe.py:470
        {V value_844=([&]()->V{V dictionary_845=V::dict();set_item(dictionary_845,V("enter_status"),V(0LL));set_item(dictionary_845,V("starflash_combo"),V(0LL));set_item(dictionary_845,V("liberation"),V(0LL));set_item(dictionary_845,V("outro"),V(0LL));set_item(dictionary_845,V("priority_liberation_cast"),V(0LL));return dictionary_845;}());set_attr(self_value(),"state",value_844);}
    }
return V{};
}),false);
// Official method Phoebe.is_forte_full, lines 478-481
register_method("is_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_846=bind_arguments(official_args,signature,captured);
    // Phoebe.py:479
    if(unary("not",attr(self_value(),"star_available")).truth()){
        // Phoebe.py:480
        return ([&]()->V{auto fn_850=attr(([&]()->V{auto fn_848=global("super","Phoebe");Args args_847;return invoke(fn_848,args_847);}()),"is_forte_full");Args args_849;return invoke(fn_850,args_849);}());
    }
    // Phoebe.py:481
    return ([&]()->V{auto fn_852=attr(self_value(),"is_mouse_forte_full");Args args_851;return invoke(fn_852,args_851);}());
return V{};
}),false);
// Official method Phoebe.shorekeeper_auto_dodge, lines 483-487
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_853=bind_arguments(official_args,signature,captured);
scope_853->set("ShoreKeeper",V::missing());
scope_853->set("char",V::missing());
scope_853->set("i",V::missing());
    // Phoebe.py:484
    scope_853->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Phoebe.py:485
    {auto iterator_854=official::iterate(([&]()->V{auto fn_861=global("enumerate","Phoebe");Args args_860;args_860.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_861,args_860);}()));V item_855;while(iterator_854.next(item_855)){
        auto unpack_862=unpack(item_855,2);scope_853->set("i",unpack_862[0]);scope_853->set("char",unpack_862[1]);
        // Phoebe.py:486
        if(([&]()->V{auto fn_857=global("isinstance","Phoebe");Args args_856;args_856.pos(scope_853->get("char"));args_856.pos(scope_853->get("ShoreKeeper"));return invoke(fn_857,args_856);}()).truth()){
            // Phoebe.py:487
            return ([&]()->V{auto fn_859=attr(scope_853->get("char"),"auto_dodge");Args args_858;args_858.kw("condition",attr(self_value(),"flying"));return invoke(fn_859,args_858);}());
        }
    }
    }
return V{};
}),false);
}
}
