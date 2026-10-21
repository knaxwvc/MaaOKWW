#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Camellya.py
// SHA256 ff0bd3bb4d8638467dfb7e13494aea3d9282208159ee1feba4c69bfa81f59562
void OfficialCharacter::install_Camellya(){
auto scope=std::make_shared<Scope>();
set_global("camellya_red_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(234LL),V(245LL)}));set_item(dictionary_1,V("g"),V::tuple({V(71LL),V(82LL)}));set_item(dictionary_1,V("b"),V::tuple({V(168LL),V(179LL)}));return dictionary_1;}()));
set_global("camellya_forte_color",([&]()->V{V dictionary_2=V::dict();set_item(dictionary_2,V("r"),V::tuple({V(193LL),V(255LL)}));set_item(dictionary_2,V("g"),V::tuple({V(46LL),V(93LL)}));set_item(dictionary_2,V("b"),V::tuple({V(127LL),V(163LL)}));return dictionary_2;}()));
set_global("camellya_budding_forte_color",([&]()->V{V dictionary_3=V::dict();set_item(dictionary_3,V("r"),V::tuple({V(220LL),V(255LL)}));set_item(dictionary_3,V("g"),V::tuple({V(161LL),V(213LL)}));set_item(dictionary_3,V("b"),V::tuple({V(168LL),V(225LL)}));return dictionary_3;}()));
// Official method Camellya.__init__, lines 11-17
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_4=bind_arguments(official_args,signature,captured);
    // Camellya.py:12
    ([&]()->V{auto fn_8=attr(([&]()->V{auto fn_6=global("super","Camellya");Args args_5;return invoke(fn_6,args_5);}()),"__init__");Args args_7;args_7.spread(scope_4->get("args"));args_7.spread_keywords(scope_4->get("kwargs"));return invoke(fn_8,args_7);}());
    // Camellya.py:13
    {V value_9=V(0LL);set_attr(self_value(),"last_heavy",value_9);}
    // Camellya.py:14
    {V value_10=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_10);}
    // Camellya.py:15
    {V value_11=V(0LL);set_attr(self_value(),"forte_drop_timestamp",value_11);}
    // Camellya.py:16
    {V value_12=V::list({});set_attr(self_value(),"forte_diff_buffer",value_12);}
    // Camellya.py:17
    {V value_13=V(0LL);set_attr(self_value(),"last_forte",value_13);}
return V{};
}),false);
// Official method Camellya.reset_state, lines 19-21
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_14=bind_arguments(official_args,signature,captured);
    // Camellya.py:20
    ([&]()->V{auto fn_18=attr(([&]()->V{auto fn_16=global("super","Camellya");Args args_15;return invoke(fn_16,args_15);}()),"reset_state");Args args_17;return invoke(fn_18,args_17);}());
    // Camellya.py:21
    {V value_19=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_19);}
return V{};
}),false);
// Official method Camellya.get_switch_priority, lines 23-26
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_20=bind_arguments(official_args,signature,captured);
    // Camellya.py:24
    if(scope_20->get("has_intro").truth()){
        // Camellya.py:25
        return attr(global("SwitchPriority","Camellya"),"MUST");
    }
    // Camellya.py:26
    return ([&]()->V{auto fn_24=attr(([&]()->V{auto fn_22=global("super","Camellya");Args args_21;return invoke(fn_22,args_21);}()),"get_switch_priority");Args args_23;args_23.pos(scope_20->get("current_char"));args_23.pos(scope_20->get("has_intro"));args_23.pos(scope_20->get("target_low_con"));return invoke(fn_24,args_23);}());
return V{};
}),false);
// Official method Camellya.wait_resonance_not_gray, lines 28-34
register_method("wait_resonance_not_gray",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"timeout",V(5LL)}},"","",{})](const Args& official_args)->V{
auto scope_25=bind_arguments(official_args,signature,captured);
scope_25->set("start",V::missing());
    // Camellya.py:29
    {V value_26=([&]()->V{auto fn_28=attr(global("time","Camellya"),"time");Args args_27;return invoke(fn_28,args_27);}());scope_25->set("start",value_26);}
    // Camellya.py:30
        while(([&]()->V{V compare_42=([&]()->V{auto fn_45=attr(self_value(),"current_resonance");Args args_44;return invoke(fn_45,args_44);}());V compare_43;V comparison_result_46;compare_43=V(0LL);comparison_result_46=compare_value("==",compare_42,compare_43);return comparison_result_46;}()).truth()){
        // Camellya.py:31
        ([&]()->V{auto fn_30=attr(self_value(),"click");Args args_29;return invoke(fn_30,args_29);}());
        // Camellya.py:32
        ([&]()->V{auto fn_32=attr(self_value(),"sleep");Args args_31;args_31.pos(V(0.1));return invoke(fn_32,args_31);}());
        // Camellya.py:33
        if(([&]()->V{V compare_33=([&]()->V{V left_35=([&]()->V{auto fn_38=attr(global("time","Camellya"),"time");Args args_37;return invoke(fn_38,args_37);}());V right_36=scope_25->get("start");return official::binary("-",left_35,right_36);}());V compare_34;V comparison_result_39;compare_34=scope_25->get("timeout");comparison_result_39=compare_value(">",compare_33,compare_34);return comparison_result_39;}()).truth()){
            // Camellya.py:34
            ([&]()->V{auto fn_41=attr(attr(self_value(),"logger"),"error");Args args_40;args_40.pos(V("wait wait_resonance_not_gray timed out"));return invoke(fn_41,args_40);}());
        }
    }
return V{};
}),false);
// Official method Camellya.on_combat_end, lines 36-37
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_47=bind_arguments(official_args,signature,captured);
    // Camellya.py:37
    ([&]()->V{auto fn_49=attr(self_value(),"switch_other_char");Args args_48;return invoke(fn_49,args_48);}());
return V{};
}),false);
// Official method Camellya.do_perform, lines 39-104
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_50=bind_arguments(official_args,signature,captured);
scope_50->set("budding",V::missing());
scope_50->set("budding_start_time",V::missing());
scope_50->set("current_con",V::missing());
scope_50->set("freeze_forte_check",V::missing());
scope_50->set("freeze_forte_time",V::missing());
scope_50->set("heavy_att",V::missing());
scope_50->set("loop_time",V::missing());
scope_50->set("start_con",V::missing());
    // Camellya.py:40
    if(attr(self_value(),"has_intro").truth()){
        // Camellya.py:41
        ([&]()->V{auto fn_52=attr(self_value(),"continues_normal_attack");Args args_51;args_51.pos(V(1.2));return invoke(fn_52,args_51);}());
        // Camellya.py:42
        ([&]()->V{auto fn_54=attr(self_value(),"sleep");Args args_53;args_53.pos(V(0.1));return invoke(fn_54,args_53);}());
        // Camellya.py:43
        ([&]()->V{auto fn_56=attr(self_value(),"heavy_attack");Args args_55;args_55.pos(V(4.6));args_55.kw("until_con_full",V(true));return invoke(fn_56,args_55);}());
    }
    // Camellya.py:44
    if(([&]()->V{auto fn_58=attr(self_value(),"liberation_available");Args args_57;return invoke(fn_58,args_57);}()).truth()){
        // Camellya.py:45
        ([&]()->V{auto fn_60=attr(self_value(),"click_liberation");Args args_59;args_59.kw("con_less_than",V(0.82));return invoke(fn_60,args_59);}());
    }
    // Camellya.py:46
    {V value_61=([&]()->V{auto fn_63=attr(self_value(),"get_current_con");Args args_62;return invoke(fn_63,args_62);}());scope_50->set("start_con",value_61);}
    // Camellya.py:47
    if(([&]()->V{V compare_64=scope_50->get("start_con");V compare_65;V comparison_result_66;compare_65=V(0.82);comparison_result_66=compare_value("<",compare_64,compare_65);return comparison_result_66;}()).truth()){
        // Camellya.py:48
        {V value_67=V(1.1);scope_50->set("loop_time",value_67);}
        // Camellya.py:49
        if(([&]()->V{auto fn_69=attr(self_value(),"resonance_available");Args args_68;return invoke(fn_69,args_68);}()).truth()){
            // Camellya.py:50
            ([&]()->V{auto fn_71=attr(self_value(),"click_resonance");Args args_70;return invoke(fn_71,args_70);}());
        }
    }else{
        // Camellya.py:52
        {V value_72=V(4.6);scope_50->set("loop_time",value_72);}
    }
    // Camellya.py:53
    {V value_73=([&]()->V{auto fn_75=attr(global("time","Camellya"),"time");Args args_74;return invoke(fn_75,args_74);}());scope_50->set("budding_start_time",value_73);}
    // Camellya.py:54
    {V value_76=V(false);scope_50->set("budding",value_76);}
    // Camellya.py:55
    {V value_77=V(false);scope_50->set("heavy_att",value_77);}
    // Camellya.py:56
    {V value_78=V(false);scope_50->set("freeze_forte_check",value_78);}
    // Camellya.py:57
    {V value_79=V(0LL);scope_50->set("freeze_forte_time",value_79);}
    // Camellya.py:58
    {V value_80=V(0LL);set_attr(self_value(),"last_forte",value_80);}
    // Camellya.py:59
        while(([&]()->V{V operand_161;operand_161=([&]()->V{V compare_162=([&]()->V{V left_164=([&]()->V{auto fn_167=attr(global("time","Camellya"),"time");Args args_166;return invoke(fn_167,args_166);}());V right_165=scope_50->get("budding_start_time");return official::binary("-",left_164,right_165);}());V compare_163;V comparison_result_168;compare_163=scope_50->get("loop_time");comparison_result_168=compare_value("<",compare_162,compare_163);return comparison_result_168;}());if(operand_161.truth())return operand_161;return ([&]()->V{auto fn_170=attr(attr(self_value(),"task"),"find_one");Args args_169;args_169.pos(V("camellya_budding"));args_169.kw("threshold",V(0.7));return invoke(fn_170,args_169);}());}()).truth()){
        // Camellya.py:60
        if(unary("not",scope_50->get("budding")).truth()){
            // Camellya.py:61
            if(([&]()->V{V operand_81;operand_81=([&]()->V{auto fn_83=attr(self_value(),"ephemeral_ready");Args args_82;return invoke(fn_83,args_82);}());if(!operand_81.truth())return operand_81;return ([&]()->V{auto fn_85=attr(self_value(),"is_con_full");Args args_84;return invoke(fn_85,args_84);}());}()).truth()){
                // Camellya.py:62
                ([&]()->V{auto fn_87=attr(self_value(),"ephemeral_cast");Args args_86;return invoke(fn_87,args_86);}());
                // Camellya.py:63
                {V value_88=V(true);scope_50->set("budding",value_88);}
            }else{
                // Camellya.py:65
                ([&]()->V{auto fn_90=attr(self_value(),"click");Args args_89;args_89.kw("interval",V(0.1));return invoke(fn_90,args_89);}());
                // Camellya.py:66
                {V value_91=([&]()->V{auto fn_93=attr(self_value(),"get_current_con");Args args_92;return invoke(fn_93,args_92);}());scope_50->set("current_con",value_91);}
                // Camellya.py:67
                if(([&]()->V{V compare_94=scope_50->get("current_con");V compare_95;V comparison_result_96;compare_95=V(0.82);comparison_result_96=compare_value("<",compare_94,compare_95);return comparison_result_96;}()).truth()){
                    // Camellya.py:68
                    if(unary("not",([&]()->V{auto fn_98=attr(self_value(),"is_con_full");Args args_97;return invoke(fn_98,args_97);}())).truth()){
                        // Camellya.py:69
                        ([&]()->V{auto fn_100=attr(self_value(),"click_echo");Args args_99;return invoke(fn_100,args_99);}());
                        // Camellya.py:70
                        return ([&]()->V{auto fn_102=attr(self_value(),"switch_next_char");Args args_101;return invoke(fn_102,args_101);}());
                    }else{
                        // Camellya.py:71
                        if(([&]()->V{V compare_103=scope_50->get("loop_time");V compare_104;V comparison_result_105;compare_104=V(3.1);comparison_result_105=compare_value("<",compare_103,compare_104);return comparison_result_105;}()).truth()){
                            // Camellya.py:72
                            scope_50->set("loop_time",official::binary("+",scope_50->get("loop_time"),V(1LL)));
                        }
                    }
                }
            }
            // Camellya.py:73
            if(scope_50->get("budding").truth()){
                // Camellya.py:74
                ([&]()->V{auto fn_107=attr(attr(self_value(),"logger"),"info");Args args_106;args_106.pos(V(std::string{}+"start budding"));return invoke(fn_107,args_106);}());
                // Camellya.py:75
                ([&]()->V{auto fn_109=attr(self_value(),"check_target");Args args_108;return invoke(fn_109,args_108);}());
                // Camellya.py:76
                {V value_110=([&]()->V{auto fn_112=attr(global("time","Camellya"),"time");Args args_111;return invoke(fn_112,args_111);}());scope_50->set("budding_start_time",value_110);}
                // Camellya.py:77
                {V value_113=V(5.1);scope_50->set("loop_time",value_113);}
            }
        }
        // Camellya.py:78
        if(scope_50->get("budding").truth()){
            // Camellya.py:79
            if(unary("not",scope_50->get("heavy_att")).truth()){
                // Camellya.py:80
                {V value_114=V(true);scope_50->set("heavy_att",value_114);}
                // Camellya.py:81
                ([&]()->V{auto fn_116=attr(attr(self_value(),"task"),"mouse_down");Args args_115;return invoke(fn_116,args_115);}());
            }
            // Camellya.py:82
            if(([&]()->V{V operand_117;operand_117=([&]()->V{V compare_118=([&]()->V{V left_120=([&]()->V{auto fn_123=attr(global("time","Camellya"),"time");Args args_122;return invoke(fn_123,args_122);}());V right_121=scope_50->get("budding_start_time");return official::binary("-",left_120,right_121);}());V compare_119;V comparison_result_124;compare_119=V(1.5);comparison_result_124=compare_value("<",compare_118,compare_119);return comparison_result_124;}());if(!operand_117.truth())return operand_117;return ([&]()->V{auto fn_126=attr(self_value(),"liberation_available");Args args_125;return invoke(fn_126,args_125);}());}()).truth()){
                // Camellya.py:83
                if(([&]()->V{V operand_127;operand_127=([&]()->V{auto fn_129=attr(self_value(),"click_liberation");Args args_128;return invoke(fn_129,args_128);}());if(!operand_127.truth())return operand_127;return scope_50->get("heavy_att");}()).truth()){
                    // Camellya.py:84
                    ([&]()->V{auto fn_131=attr(attr(self_value(),"logger"),"info");Args args_130;args_130.pos(V(std::string{}+"liberation retry heavy att"));return invoke(fn_131,args_130);}());
                    // Camellya.py:85
                    ([&]()->V{auto fn_133=attr(attr(self_value(),"task"),"mouse_up");Args args_132;return invoke(fn_133,args_132);}());
                    // Camellya.py:86
                    ([&]()->V{auto fn_135=attr(self_value(),"sleep");Args args_134;args_134.pos(V(0.2));args_134.pos(V(false));return invoke(fn_135,args_134);}());
                    // Camellya.py:87
                    ([&]()->V{auto fn_137=attr(attr(self_value(),"task"),"mouse_down");Args args_136;return invoke(fn_137,args_136);}());
                }
            }
        }
        // Camellya.py:88
        ([&]()->V{auto fn_139=attr(self_value(),"check_target");Args args_138;args_138.pos(scope_50->get("heavy_att"));return invoke(fn_139,args_138);}());
        // Camellya.py:89
        ([&]()->V{auto fn_141=attr(attr(self_value(),"task"),"next_frame");Args args_140;return invoke(fn_141,args_140);}());
        // Camellya.py:90
        if(([&]()->V{V operand_142;operand_142=scope_50->get("freeze_forte_check");if(!operand_142.truth())return operand_142;return ([&]()->V{V compare_143=([&]()->V{V left_145=([&]()->V{auto fn_148=attr(global("time","Camellya"),"time");Args args_147;return invoke(fn_148,args_147);}());V right_146=scope_50->get("freeze_forte_time");return official::binary("-",left_145,right_146);}());V compare_144;V comparison_result_149;compare_144=V(0.2);comparison_result_149=compare_value(">=",compare_143,compare_144);return comparison_result_149;}());}()).truth()){
            // Camellya.py:91
            {V value_150=V(false);scope_50->set("freeze_forte_check",value_150);}
        }
        // Camellya.py:92
        if(([&]()->V{V operand_151;operand_151=unary("not",scope_50->get("freeze_forte_check"));if(!operand_151.truth())return operand_151;return scope_50->get("heavy_att");}()).truth()){
            // Camellya.py:93
            if(([&]()->V{V compare_152=([&]()->V{auto fn_155=attr(self_value(),"should_retry_heavy_attack");Args args_154;args_154.pos(scope_50->get("budding"));return invoke(fn_155,args_154);}());V compare_153;V comparison_result_156;compare_153=V(0LL);comparison_result_156=compare_value("<",compare_152,compare_153);return comparison_result_156;}()).truth()){
                // Camellya.py:94
                {V value_157=V(true);scope_50->set("freeze_forte_check",value_157);}
                // Camellya.py:95
                {V value_158=([&]()->V{auto fn_160=attr(global("time","Camellya"),"time");Args args_159;return invoke(fn_160,args_159);}());scope_50->set("freeze_forte_time",value_158);}
            }
        }
    }
    // Camellya.py:96
    {V value_171=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_171);}
    // Camellya.py:97
    if(scope_50->get("heavy_att").truth()){
        // Camellya.py:98
        ([&]()->V{auto fn_173=attr(attr(self_value(),"task"),"mouse_up");Args args_172;return invoke(fn_173,args_172);}());
        // Camellya.py:99
        ([&]()->V{auto fn_175=attr(self_value(),"sleep");Args args_174;args_174.pos(V(0.1));return invoke(fn_175,args_174);}());
    }
    // Camellya.py:100
    if(scope_50->get("budding").truth()){
        // Camellya.py:101
        ([&]()->V{auto fn_177=attr(self_value(),"click_resonance");Args args_176;return invoke(fn_177,args_176);}());
        // Camellya.py:102
        ([&]()->V{auto fn_179=attr(self_value(),"sleep");Args args_178;args_178.pos(V(0.1));return invoke(fn_179,args_178);}());
    }
    // Camellya.py:103
    ([&]()->V{auto fn_181=attr(self_value(),"click_echo");Args args_180;return invoke(fn_181,args_180);}());
    // Camellya.py:104
    ([&]()->V{auto fn_183=attr(self_value(),"switch_next_char");Args args_182;return invoke(fn_183,args_182);}());
return V{};
}),false);
// Official method Camellya.click_echo, lines 106-109
register_method("click_echo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_184=bind_arguments(official_args,signature,captured);
    // Camellya.py:107
    if(([&]()->V{auto fn_186=attr(self_value(),"echo_available");Args args_185;return invoke(fn_186,args_185);}()).truth()){
        // Camellya.py:108
        ([&]()->V{auto fn_188=attr(self_value(),"send_echo_key");Args args_187;return invoke(fn_188,args_187);}());
        // Camellya.py:109
        return V(true);
    }
return V{};
}),false);
// Official method Camellya.ephemeral_ready, lines 111-116
register_method("ephemeral_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_189=bind_arguments(official_args,signature,captured);
scope_189->set("box",V::missing());
scope_189->set("red_percent",V::missing());
    // Camellya.py:112
    {V value_190=([&]()->V{auto fn_192=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_191;args_191.pos(V(2560LL));args_191.pos(V(1440LL));args_191.pos(V(2110LL));args_191.pos(V(1236LL));args_191.pos(V(2217LL));args_191.pos(V(1343LL));args_191.kw("name",V("camellya_resonance"));args_191.kw("hcenter",V(true));return invoke(fn_192,args_191);}());scope_189->set("box",value_190);}
    // Camellya.py:114
    {V value_193=([&]()->V{auto fn_195=attr(self_value(),"calculate_color_percentage_in_masked");Args args_194;args_194.pos(global("camellya_red_color","Camellya"));args_194.pos(scope_189->get("box"));args_194.pos(V(0.395));args_194.pos(V(0.496));return invoke(fn_195,args_194);}());scope_189->set("red_percent",value_193);}
    // Camellya.py:115
    ([&]()->V{auto fn_197=attr(attr(self_value(),"logger"),"debug");Args args_196;args_196.pos(V(std::string{}+"red_percent "+format_value(scope_189->get("red_percent"),"",-1)));return invoke(fn_197,args_196);}());
    // Camellya.py:116
    return ([&]()->V{V compare_198=scope_189->get("red_percent");V compare_199;V comparison_result_200;compare_199=V(0.1);comparison_result_200=compare_value(">",compare_198,compare_199);return comparison_result_200;}());
return V{};
}),false);
// Official method Camellya.calculate_color_percentage_in_masked, lines 118-150
register_method("calculate_color_percentage_in_masked",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"target_color",V::missing()},{"box",V::missing()},{"mask_r1_ratio",V(0.0)},{"mask_r2_ratio",V(0.0)}},"","",{})](const Args& official_args)->V{
auto scope_201=bind_arguments(official_args,signature,captured);
scope_201->set("center",V::missing());
scope_201->set("color_percent",V::missing());
scope_201->set("colored_pixels",V::missing());
scope_201->set("cropped",V::missing());
scope_201->set("free_space",V::missing());
scope_201->set("gray",V::missing());
scope_201->set("h",V::missing());
scope_201->set("lower_bound",V::missing());
scope_201->set("masked_image",V::missing());
scope_201->set("non_black_mask",V::missing());
scope_201->set("r1",V::missing());
scope_201->set("r2",V::missing());
scope_201->set("ring_mask",V::missing());
scope_201->set("upper_bound",V::missing());
scope_201->set("w",V::missing());
    // Camellya.py:119
    {V value_202=([&]()->V{auto fn_206=attr(([&]()->V{auto fn_204=attr(scope_201->get("box"),"crop_frame");Args args_203;args_203.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_204,args_203);}()),"copy");Args args_205;return invoke(fn_206,args_205);}());scope_201->set("cropped",value_202);}
    // Camellya.py:120
    if(([&]()->V{V operand_207;operand_207=([&]()->V{V compare_208=scope_201->get("cropped");V compare_209;V comparison_result_210;compare_209=V{};comparison_result_210=compare_value("is",compare_208,compare_209);return comparison_result_210;}());if(operand_207.truth())return operand_207;return ([&]()->V{V compare_211=attr(scope_201->get("cropped"),"size");V compare_212;V comparison_result_213;compare_212=V(0LL);comparison_result_213=compare_value("==",compare_211,compare_212);return comparison_result_213;}());}()).truth()){
        // Camellya.py:121
        return V(0.0);
    }
    // Camellya.py:122
    {V value_214=item(attr(scope_201->get("cropped"),"shape"),V::slice(V{},V(2LL),V{}));auto unpack_215=unpack(value_214,2);scope_201->set("h",unpack_215[0]);scope_201->set("w",unpack_215[1]);}
    // Camellya.py:124
    {V value_216=V::tuple({([&]()->V{V left_217=scope_201->get("w");V right_218=V(2LL);return official::binary("//",left_217,right_218);}()),([&]()->V{V left_219=scope_201->get("h");V right_220=V(2LL);return official::binary("//",left_219,right_220);}())});scope_201->set("center",value_216);}
    // Camellya.py:125
    {V value_221=V::tuple({([&]()->V{V left_222=scope_201->get("h");V right_223=scope_201->get("mask_r1_ratio");return official::binary("*",left_222,right_223);}()),([&]()->V{V left_224=scope_201->get("h");V right_225=scope_201->get("mask_r2_ratio");return official::binary("*",left_224,right_225);}())});auto unpack_226=unpack(value_221,2);scope_201->set("r1",unpack_226[0]);scope_201->set("r2",unpack_226[1]);}
    // Camellya.py:126
    {V value_227=([&]()->V{auto fn_233=attr(([&]()->V{auto fn_229=global("Decimal","Camellya");Args args_228;args_228.pos(([&]()->V{auto fn_231=global("str","Camellya");Args args_230;args_230.pos(scope_201->get("r1"));return invoke(fn_231,args_230);}()));return invoke(fn_229,args_228);}()),"quantize");Args args_232;args_232.pos(([&]()->V{auto fn_235=global("Decimal","Camellya");Args args_234;args_234.pos(V("0"));return invoke(fn_235,args_234);}()));args_232.kw("rounding",global("ROUND_DOWN","Camellya"));return invoke(fn_233,args_232);}());scope_201->set("r1",value_227);}
    // Camellya.py:127
    {V value_236=([&]()->V{auto fn_242=attr(([&]()->V{auto fn_238=global("Decimal","Camellya");Args args_237;args_237.pos(([&]()->V{auto fn_240=global("str","Camellya");Args args_239;args_239.pos(scope_201->get("r2"));return invoke(fn_240,args_239);}()));return invoke(fn_238,args_237);}()),"quantize");Args args_241;args_241.pos(([&]()->V{auto fn_244=global("Decimal","Camellya");Args args_243;args_243.pos(V("0"));return invoke(fn_244,args_243);}()));args_241.kw("rounding",global("ROUND_UP","Camellya"));return invoke(fn_242,args_241);}());scope_201->set("r2",value_236);}
    // Camellya.py:129
    {V value_245=([&]()->V{auto fn_247=attr(global("np","Camellya"),"zeros");Args args_246;args_246.pos(V::tuple({scope_201->get("h"),scope_201->get("w")}));args_246.kw("dtype",attr(global("np","Camellya"),"uint8"));return invoke(fn_247,args_246);}());scope_201->set("ring_mask",value_245);}
    // Camellya.py:130
    if(([&]()->V{V compare_248=scope_201->get("r2");V compare_249;V comparison_result_250;compare_249=V(0LL);comparison_result_250=compare_value(">",compare_248,compare_249);return comparison_result_250;}()).truth()){
        // Camellya.py:131
        ([&]()->V{auto fn_252=attr(global("cv2","Camellya"),"circle");Args args_251;args_251.pos(scope_201->get("ring_mask"));args_251.pos(scope_201->get("center"));args_251.pos(([&]()->V{auto fn_254=global("int","Camellya");Args args_253;args_253.pos(scope_201->get("r2"));return invoke(fn_254,args_253);}()));args_251.pos(V(255LL));args_251.pos(unary("-",V(1LL)));return invoke(fn_252,args_251);}());
    }
    // Camellya.py:132
    if(([&]()->V{V compare_255=scope_201->get("r1");V compare_256;V comparison_result_257;compare_256=V(0LL);comparison_result_257=compare_value(">",compare_255,compare_256);return comparison_result_257;}()).truth()){
        // Camellya.py:133
        ([&]()->V{auto fn_259=attr(global("cv2","Camellya"),"circle");Args args_258;args_258.pos(scope_201->get("ring_mask"));args_258.pos(scope_201->get("center"));args_258.pos(([&]()->V{auto fn_261=global("int","Camellya");Args args_260;args_260.pos(scope_201->get("r1"));return invoke(fn_261,args_260);}()));args_258.pos(V(0LL));args_258.pos(unary("-",V(1LL)));return invoke(fn_259,args_258);}());
    }
    // Camellya.py:134
    {V value_262=([&]()->V{auto fn_264=attr(global("cv2","Camellya"),"bitwise_and");Args args_263;args_263.pos(scope_201->get("cropped"));args_263.pos(scope_201->get("cropped"));args_263.kw("mask",scope_201->get("ring_mask"));return invoke(fn_264,args_263);}());scope_201->set("masked_image",value_262);}
    // Camellya.py:136
    if(([&]()->V{V compare_265=attr(scope_201->get("masked_image"),"ndim");V compare_266;V comparison_result_267;compare_266=V(3LL);comparison_result_267=compare_value("==",compare_265,compare_266);return comparison_result_267;}()).truth()){
        // Camellya.py:137
        {V value_268=([&]()->V{auto fn_270=attr(global("np","Camellya"),"all");Args args_269;args_269.pos(([&]()->V{V compare_271=scope_201->get("masked_image");V compare_272;V comparison_result_273;compare_272=V(0LL);comparison_result_273=compare_value("!=",compare_271,compare_272);return comparison_result_273;}()));args_269.kw("axis",V(2LL));return invoke(fn_270,args_269);}());scope_201->set("non_black_mask",value_268);}
    }else{
        // Camellya.py:139
        return V(0.0);
    }
    // Camellya.py:141
    {V value_274=([&]()->V{auto fn_276=attr(global("np","Camellya"),"count_nonzero");Args args_275;args_275.pos(scope_201->get("non_black_mask"));return invoke(fn_276,args_275);}());scope_201->set("free_space",value_274);}
    // Camellya.py:142
    if(([&]()->V{V compare_277=scope_201->get("free_space");V compare_278;V comparison_result_279;compare_278=V(0LL);comparison_result_279=compare_value("==",compare_277,compare_278);return comparison_result_279;}()).truth()){
        // Camellya.py:143
        return V(0.0);
    }
    // Camellya.py:145
    {V value_280=([&]()->V{auto fn_282=global("color_range_to_bound","Camellya");Args args_281;args_281.pos(scope_201->get("target_color"));return invoke(fn_282,args_281);}());auto unpack_283=unpack(value_280,2);scope_201->set("lower_bound",unpack_283[0]);scope_201->set("upper_bound",unpack_283[1]);}
    // Camellya.py:146
    {V value_284=([&]()->V{auto fn_286=attr(global("cv2","Camellya"),"inRange");Args args_285;args_285.pos(scope_201->get("masked_image"));args_285.pos(scope_201->get("lower_bound"));args_285.pos(scope_201->get("upper_bound"));return invoke(fn_286,args_285);}());scope_201->set("gray",value_284);}
    // Camellya.py:147
    {V value_287=([&]()->V{auto fn_289=attr(global("np","Camellya"),"count_nonzero");Args args_288;args_288.pos(([&]()->V{V compare_290=scope_201->get("gray");V compare_291;V comparison_result_292;compare_291=V(255LL);comparison_result_292=compare_value("==",compare_290,compare_291);return comparison_result_292;}()));return invoke(fn_289,args_288);}());scope_201->set("colored_pixels",value_287);}
    // Camellya.py:149
    {V value_293=([&]()->V{V left_294=scope_201->get("colored_pixels");V right_295=scope_201->get("free_space");return official::binary("/",left_294,right_295);}());scope_201->set("color_percent",value_293);}
    // Camellya.py:150
    return scope_201->get("color_percent");
return V{};
}),false);
// Official method Camellya.ephemeral_cast, lines 152-157
register_method("ephemeral_cast",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_296=bind_arguments(official_args,signature,captured);
    // Camellya.py:153
    ([&]()->V{auto fn_298=attr(self_value(),"check_combat");Args args_297;return invoke(fn_298,args_297);}());
    // Camellya.py:154
        while(([&]()->V{auto fn_304=attr(self_value(),"ephemeral_ready");Args args_303;return invoke(fn_304,args_303);}()).truth()){
        // Camellya.py:155
        ([&]()->V{auto fn_300=attr(self_value(),"send_resonance_key");Args args_299;return invoke(fn_300,args_299);}());
        // Camellya.py:156
        ([&]()->V{auto fn_302=attr(self_value(),"sleep");Args args_301;args_301.pos(V(0.1));return invoke(fn_302,args_301);}());
    }
    // Camellya.py:157
    ([&]()->V{auto fn_306=attr(self_value(),"sleep");Args args_305;args_305.pos(V(1.1));return invoke(fn_306,args_305);}());
return V{};
}),false);
// Official method Camellya.get_forte, lines 159-169
register_method("get_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"budding",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_307=bind_arguments(official_args,signature,captured);
scope_307->set("box",V::missing());
scope_307->set("forte_percent",V::missing());
    // Camellya.py:160
    {V value_308=([&]()->V{auto fn_310=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_309;args_309.pos(V(3840LL));args_309.pos(V(2160LL));args_309.pos(V(1630LL));args_309.pos(V(2002LL));args_309.pos(V(2176LL));args_309.pos(V(2004LL));args_309.kw("name",V("camellya_forte"));args_309.kw("hcenter",V(true));return invoke(fn_310,args_309);}());scope_307->set("box",value_308);}
    // Camellya.py:161
    {V value_311=V(0LL);scope_307->set("forte_percent",value_311);}
    // Camellya.py:162
    if(unary("not",scope_307->get("budding")).truth()){
        // Camellya.py:163
        {V value_312=([&]()->V{auto fn_314=attr(self_value(),"calculate_forte_percent");Args args_313;args_313.pos(global("camellya_forte_color","Camellya"));args_313.pos(scope_307->get("box"));return invoke(fn_314,args_313);}());scope_307->set("forte_percent",value_312);}
    }else{
        // Camellya.py:165
        {V value_315=([&]()->V{auto fn_317=attr(self_value(),"calculate_forte_percent");Args args_316;args_316.pos(global("camellya_budding_forte_color","Camellya"));args_316.pos(scope_307->get("box"));return invoke(fn_317,args_316);}());scope_307->set("forte_percent",value_315);}
    }
    // Camellya.py:166
    {V value_318=([&]()->V{auto fn_324=attr(([&]()->V{auto fn_320=global("Decimal","Camellya");Args args_319;args_319.pos(([&]()->V{auto fn_322=global("str","Camellya");Args args_321;args_321.pos(scope_307->get("forte_percent"));return invoke(fn_322,args_321);}()));return invoke(fn_320,args_319);}()),"quantize");Args args_323;args_323.pos(([&]()->V{auto fn_326=global("Decimal","Camellya");Args args_325;args_325.pos(V("0.001"));return invoke(fn_326,args_325);}()));args_323.kw("rounding",global("ROUND_HALF_UP","Camellya"));return invoke(fn_324,args_323);}());scope_307->set("forte_percent",value_318);}
    // Camellya.py:167
    if(([&]()->V{V compare_327=scope_307->get("forte_percent");V compare_328;V comparison_result_329;compare_328=V(0LL);comparison_result_329=compare_value(">=",compare_327,compare_328);return comparison_result_329;}()).truth()){
        // Camellya.py:168
        ([&]()->V{auto fn_331=attr(attr(self_value(),"logger"),"debug");Args args_330;args_330.pos(V(std::string{}+"forte_percent "+format_value(([&]()->V{V left_332=scope_307->get("forte_percent");V right_333=V(100LL);return official::binary("*",left_332,right_333);}()),V(std::string{}+".2f").text(),-1)+"% budding "+format_value(scope_307->get("budding"),"",-1)));return invoke(fn_331,args_330);}());
    }
    // Camellya.py:169
    return scope_307->get("forte_percent");
return V{};
}),false);
// Official method Camellya.detect_stripe_region, lines 171-262
register_method("detect_stripe_region",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"gray",V::missing()},{"white_ratio_range",V::tuple({V(0.05),V(0.75)})},{"fft_thresh_ratio",V(0.45)},{"max_fail_count",V(1LL)}},"","",{})](const Args& official_args)->V{
auto scope_334=bind_arguments(official_args,signature,captured);
scope_334->set("a",V::missing());
scope_334->set("b",V::missing());
scope_334->set("end_idx",V::missing());
scope_334->set("end_x",V::missing());
scope_334->set("fail_count",V::missing());
scope_334->set("fft_thresh",V::missing());
scope_334->set("height",V::missing());
scope_334->set("i",V::missing());
scope_334->set("keep",V::missing());
scope_334->set("max_score",V::missing());
scope_334->set("positions",V::missing());
scope_334->set("profile",V::missing());
scope_334->set("remove_short_stripes",V::missing());
scope_334->set("score",V::missing());
scope_334->set("scores",V::missing());
scope_334->set("spectrum",V::missing());
scope_334->set("start_x",V::missing());
scope_334->set("step",V::missing());
scope_334->set("white_ratio",V::missing());
scope_334->set("width",V::missing());
scope_334->set("win_w",V::missing());
scope_334->set("window",V::missing());
scope_334->set("x",V::missing());
    // Camellya.py:173
    {V value_335=item(attr(scope_334->get("gray"),"shape"),V::slice(V{},V(2LL),V{}));auto unpack_336=unpack(value_335,2);scope_334->set("height",unpack_336[0]);scope_334->set("width",unpack_336[1]);}
    // Camellya.py:174
    if(([&]()->V{V operand_337;operand_337=([&]()->V{V compare_338=scope_334->get("height");V compare_339;V comparison_result_340;compare_339=V(0LL);comparison_result_340=compare_value("==",compare_338,compare_339);return comparison_result_340;}());if(operand_337.truth())return operand_337;operand_337=([&]()->V{V compare_341=scope_334->get("width");V compare_342;V comparison_result_343;compare_342=V(64LL);comparison_result_343=compare_value("<",compare_341,compare_342);return comparison_result_343;}());if(operand_337.truth())return operand_337;return unary("not",([&]()->V{auto fn_345=attr(global("np","Camellya"),"any");Args args_344;args_344.pos(([&]()->V{V left_346=([&]()->V{V compare_348=scope_334->get("gray");V compare_349;V comparison_result_350;compare_349=V(0LL);comparison_result_350=compare_value("==",compare_348,compare_349);return comparison_result_350;}());V right_347=([&]()->V{V compare_351=scope_334->get("gray");V compare_352;V comparison_result_353;compare_352=V(255LL);comparison_result_353=compare_value("==",compare_351,compare_352);return comparison_result_353;}());return official::binary("|",left_346,right_347);}()));return invoke(fn_345,args_344);}()));}()).truth()){
        // Camellya.py:175
        return V::tuple({unary("-",V(1LL)),unary("-",V(1LL))});
    }
    // Camellya.py:176
    if(unary("not",([&]()->V{auto fn_355=attr(global("np","Camellya"),"any");Args args_354;args_354.pos(([&]()->V{V compare_356=scope_334->get("gray");V compare_357;V comparison_result_358;compare_357=V(255LL);comparison_result_358=compare_value("==",compare_356,compare_357);return comparison_result_358;}()));return invoke(fn_355,args_354);}())).truth()){
        // Camellya.py:177
        return V::tuple({V(0LL),V(0LL)});
    }
    // Camellya.py:179
    scope_334->set("remove_short_stripes",V::function([this,captured=capture_scope(scope_334,{}),signature=Signature({{"gray",V::missing()},{"threshold",V(3LL)}},"","",{})](const Args& official_args)->V{
auto scope_359=bind_arguments(official_args,signature,captured);
scope_359->set("height",V::missing());
scope_359->set("length",V::missing());
scope_359->set("result",V::missing());
scope_359->set("row",V::missing());
scope_359->set("start",V::missing());
scope_359->set("width",V::missing());
scope_359->set("x",V::missing());
scope_359->set("y",V::missing());
    // Camellya.py:180
    if(([&]()->V{V compare_360=scope_359->get("threshold");V compare_361;V comparison_result_362;compare_361=V(1LL);comparison_result_362=compare_value("<",compare_360,compare_361);return comparison_result_362;}()).truth()){
        // Camellya.py:181
        return scope_359->get("gray");
    }
    // Camellya.py:183
    {V value_363=([&]()->V{auto fn_365=attr(scope_359->get("gray"),"copy");Args args_364;return invoke(fn_365,args_364);}());scope_359->set("result",value_363);}
    // Camellya.py:184
    {V value_366=attr(scope_359->get("gray"),"shape");auto unpack_367=unpack(value_366,2);scope_359->set("height",unpack_367[0]);scope_359->set("width",unpack_367[1]);}
    // Camellya.py:186
    {auto iterator_368=official::iterate(([&]()->V{auto fn_394=global("range","Camellya");Args args_393;args_393.pos(scope_359->get("height"));return invoke(fn_394,args_393);}()));V item_369;while(iterator_368.next(item_369)){
        scope_359->set("y",item_369);
        // Camellya.py:187
        {V value_370=item(scope_359->get("gray"),scope_359->get("y"));scope_359->set("row",value_370);}
        // Camellya.py:188
        {V value_371=V(0LL);scope_359->set("x",value_371);}
        // Camellya.py:189
                while(([&]()->V{V compare_390=scope_359->get("x");V compare_391;V comparison_result_392;compare_391=scope_359->get("width");comparison_result_392=compare_value("<",compare_390,compare_391);return comparison_result_392;}()).truth()){
            // Camellya.py:190
            if(([&]()->V{V compare_372=item(scope_359->get("row"),scope_359->get("x"));V compare_373;V comparison_result_374;compare_373=V(255LL);comparison_result_374=compare_value("==",compare_372,compare_373);return comparison_result_374;}()).truth()){
                // Camellya.py:191
                {V value_375=scope_359->get("x");scope_359->set("start",value_375);}
                // Camellya.py:192
                                while(([&]()->V{V operand_376;operand_376=([&]()->V{V compare_377=scope_359->get("x");V compare_378;V comparison_result_379;compare_378=scope_359->get("width");comparison_result_379=compare_value("<",compare_377,compare_378);return comparison_result_379;}());if(!operand_376.truth())return operand_376;return ([&]()->V{V compare_380=item(scope_359->get("row"),scope_359->get("x"));V compare_381;V comparison_result_382;compare_381=V(255LL);comparison_result_382=compare_value("==",compare_380,compare_381);return comparison_result_382;}());}()).truth()){
                    // Camellya.py:193
                    scope_359->set("x",official::binary("+",scope_359->get("x"),V(1LL)));
                }
                // Camellya.py:194
                {V value_383=([&]()->V{V left_384=scope_359->get("x");V right_385=scope_359->get("start");return official::binary("-",left_384,right_385);}());scope_359->set("length",value_383);}
                // Camellya.py:195
                if(([&]()->V{V compare_386=scope_359->get("length");V compare_387;V comparison_result_388;compare_387=scope_359->get("threshold");comparison_result_388=compare_value("<",compare_386,compare_387);return comparison_result_388;}()).truth()){
                    // Camellya.py:196
                    {V value_389=V(0LL);set_item(scope_359->get("result"),V::tuple({scope_359->get("y"),V::slice(scope_359->get("start"),scope_359->get("x"),V{})}),value_389);}
                }
            }else{
                // Camellya.py:198
                scope_359->set("x",official::binary("+",scope_359->get("x"),V(1LL)));
            }
        }
    }
    }
    // Camellya.py:199
    return scope_359->get("result");
return V{};
}));
    // Camellya.py:201
    {V value_395=([&]()->V{auto fn_397=global("max","Camellya");Args args_396;args_396.pos(V(8LL));args_396.pos(([&]()->V{auto fn_399=global("int","Camellya");Args args_398;args_398.pos(([&]()->V{V left_400=scope_334->get("width");V right_401=V(0.045);return official::binary("*",left_400,right_401);}()));return invoke(fn_399,args_398);}()));return invoke(fn_397,args_396);}());scope_334->set("win_w",value_395);}
    // Camellya.py:202
    {V value_402=([&]()->V{auto fn_404=global("max","Camellya");Args args_403;args_403.pos(V(1LL));args_403.pos(([&]()->V{auto fn_406=global("int","Camellya");Args args_405;args_405.pos(([&]()->V{V left_407=scope_334->get("width");V right_408=V(0.012);return official::binary("*",left_407,right_408);}()));return invoke(fn_406,args_405);}()));return invoke(fn_404,args_403);}());scope_334->set("step",value_402);}
    // Camellya.py:203
    {V value_409=([&]()->V{auto fn_411=scope_334->get("remove_short_stripes");Args args_410;args_410.pos(scope_334->get("gray"));args_410.pos(([&]()->V{auto fn_413=global("int","Camellya");Args args_412;args_412.pos(([&]()->V{V left_414=scope_334->get("width");V right_415=V(0.009);return official::binary("*",left_414,right_415);}()));return invoke(fn_413,args_412);}()));return invoke(fn_411,args_410);}());scope_334->set("gray",value_409);}
    // Camellya.py:205
    {V value_416=V::list({});scope_334->set("scores",value_416);}
    // Camellya.py:206
    {V value_417=V::list({});scope_334->set("positions",value_417);}
    // Camellya.py:207
    {V value_418=V{};scope_334->set("start_x",value_418);}
    // Camellya.py:208
    {V value_419=V{};scope_334->set("end_x",value_419);}
    // Camellya.py:209
    {V value_420=V(0LL);scope_334->set("fail_count",value_420);}
    // Camellya.py:210
    {V value_421=V(0LL);scope_334->set("x",value_421);}
    // Camellya.py:211
        while(([&]()->V{V compare_463=([&]()->V{V left_465=scope_334->get("x");V right_466=scope_334->get("win_w");return official::binary("+",left_465,right_466);}());V compare_464;V comparison_result_467;compare_464=scope_334->get("width");comparison_result_467=compare_value("<=",compare_463,compare_464);return comparison_result_467;}()).truth()){
        // Camellya.py:212
        {V value_422=item(scope_334->get("gray"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_334->get("x"),([&]()->V{V left_423=scope_334->get("x");V right_424=scope_334->get("win_w");return official::binary("+",left_423,right_424);}()),V{})}));scope_334->set("window",value_422);}
        // Camellya.py:213
        {V value_425=([&]()->V{V left_426=([&]()->V{auto fn_429=attr(global("np","Camellya"),"count_nonzero");Args args_428;args_428.pos(([&]()->V{V compare_430=scope_334->get("window");V compare_431;V comparison_result_432;compare_431=V(255LL);comparison_result_432=compare_value("==",compare_430,compare_431);return comparison_result_432;}()));return invoke(fn_429,args_428);}());V right_427=attr(scope_334->get("window"),"size");return official::binary("/",left_426,right_427);}());scope_334->set("white_ratio",value_425);}
        // Camellya.py:214
        if(unary("not",([&]()->V{V compare_433=item(scope_334->get("white_ratio_range"),V(0LL));V compare_434;V comparison_result_435;compare_434=scope_334->get("white_ratio");comparison_result_435=compare_value("<=",compare_433,compare_434);if(!comparison_result_435.truth())return comparison_result_435;compare_433=compare_434;compare_434=item(scope_334->get("white_ratio_range"),V(1LL));comparison_result_435=compare_value("<=",compare_433,compare_434);return comparison_result_435;}())).truth()){
            // Camellya.py:215
            {V value_436=V(0LL);scope_334->set("score",value_436);}
        }else{
            // Camellya.py:217
            {V value_437=([&]()->V{auto fn_444=attr(([&]()->V{auto fn_439=attr(global("np","Camellya"),"sum");Args args_438;args_438.pos(([&]()->V{V compare_440=scope_334->get("window");V compare_441;V comparison_result_442;compare_441=V(255LL);comparison_result_442=compare_value("==",compare_440,compare_441);return comparison_result_442;}()));args_438.kw("axis",V(0LL));return invoke(fn_439,args_438);}()),"astype");Args args_443;args_443.pos(attr(global("np","Camellya"),"float32"));return invoke(fn_444,args_443);}());scope_334->set("profile",value_437);}
            // Camellya.py:218
            scope_334->set("profile",official::binary("-",scope_334->get("profile"),([&]()->V{auto fn_446=attr(global("np","Camellya"),"mean");Args args_445;args_445.pos(scope_334->get("profile"));return invoke(fn_446,args_445);}())));
            // Camellya.py:219
            {V value_447=item(([&]()->V{auto fn_449=attr(global("np","Camellya"),"abs");Args args_448;args_448.pos(([&]()->V{auto fn_451=attr(attr(global("np","Camellya"),"fft"),"fft");Args args_450;args_450.pos(scope_334->get("profile"));return invoke(fn_451,args_450);}()));return invoke(fn_449,args_448);}()),V::slice(V{},([&]()->V{V left_452=scope_334->get("win_w");V right_453=V(2LL);return official::binary("//",left_452,right_453);}()),V{}));scope_334->set("spectrum",value_447);}
            // Camellya.py:220
            {V value_454=([&]()->V{auto fn_456=attr(global("np","Camellya"),"max");Args args_455;args_455.pos(item(scope_334->get("spectrum"),V::slice(V(1LL),V{},V{})));return invoke(fn_456,args_455);}());scope_334->set("score",value_454);}
        }
        // Camellya.py:221
        ([&]()->V{auto fn_458=attr(scope_334->get("scores"),"append");Args args_457;args_457.pos(scope_334->get("score"));return invoke(fn_458,args_457);}());
        // Camellya.py:222
        ([&]()->V{auto fn_460=attr(scope_334->get("positions"),"append");Args args_459;args_459.pos(V::tuple({scope_334->get("x"),([&]()->V{V left_461=scope_334->get("x");V right_462=scope_334->get("win_w");return official::binary("+",left_461,right_462);}())}));return invoke(fn_460,args_459);}());
        // Camellya.py:223
        scope_334->set("x",official::binary("+",scope_334->get("x"),scope_334->get("step")));
    }
    // Camellya.py:225
    if(([&]()->V{V compare_468=([&]()->V{auto fn_471=global("len","Camellya");Args args_470;args_470.pos(scope_334->get("scores"));return invoke(fn_471,args_470);}());V compare_469;V comparison_result_472;compare_469=V(0LL);comparison_result_472=compare_value("==",compare_468,compare_469);return comparison_result_472;}()).truth()){
        // Camellya.py:226
        return V::tuple({unary("-",V(1LL)),unary("-",V(1LL))});
    }
    // Camellya.py:228
    {V value_473=([&]()->V{auto fn_475=attr(global("np","Camellya"),"array");Args args_474;args_474.pos(scope_334->get("scores"));return invoke(fn_475,args_474);}());scope_334->set("scores",value_473);}
    // Camellya.py:229
    {V value_476=([&]()->V{auto fn_478=attr(global("np","Camellya"),"max");Args args_477;args_477.pos(scope_334->get("scores"));return invoke(fn_478,args_477);}());scope_334->set("max_score",value_476);}
    // Camellya.py:230
    {V value_479=([&]()->V{auto fn_481=global("max","Camellya");Args args_480;args_480.pos(V(1.5));args_480.pos(([&]()->V{V left_482=scope_334->get("max_score");V right_483=scope_334->get("fft_thresh_ratio");return official::binary("*",left_482,right_483);}()));return invoke(fn_481,args_480);}());scope_334->set("fft_thresh",value_479);}
    // Camellya.py:232
    if(([&]()->V{V compare_484=scope_334->get("max_score");V compare_485;V comparison_result_486;compare_485=V(0.001);comparison_result_486=compare_value("<",compare_484,compare_485);return comparison_result_486;}()).truth()){
        // Camellya.py:233
        return V::tuple({V(0LL),V(0LL)});
    }
    // Camellya.py:235
    {V value_487=([&]()->V{V compare_488=scope_334->get("scores");V compare_489;V comparison_result_490;compare_489=scope_334->get("fft_thresh");comparison_result_490=compare_value(">=",compare_488,compare_489);return comparison_result_490;}());scope_334->set("keep",value_487);}
    // Camellya.py:237
    {V value_491=V(0LL);scope_334->set("fail_count",value_491);}
    // Camellya.py:238
    {V value_492=V(0LL);scope_334->set("end_idx",value_492);}
    // Camellya.py:239
    {auto iterator_493=official::iterate(([&]()->V{auto fn_522=global("range","Camellya");Args args_521;args_521.pos(([&]()->V{auto fn_524=global("len","Camellya");Args args_523;args_523.pos(scope_334->get("keep"));return invoke(fn_524,args_523);}()));return invoke(fn_522,args_521);}()));V item_494;while(iterator_493.next(item_494)){
        scope_334->set("i",item_494);
        // Camellya.py:240
        if(item(scope_334->get("keep"),scope_334->get("i")).truth()){
            // Camellya.py:241
            {V value_495=scope_334->get("i");scope_334->set("end_idx",value_495);}
            // Camellya.py:242
            {V value_496=V(0LL);scope_334->set("fail_count",value_496);}
        }else{
            // Camellya.py:244
            {V value_497=item(scope_334->get("positions"),scope_334->get("i"));auto unpack_498=unpack(value_497,2);scope_334->set("a",unpack_498[0]);scope_334->set("b",unpack_498[1]);}
            // Camellya.py:245
            {V value_499=item(scope_334->get("gray"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_334->get("a"),scope_334->get("b"),V{})}));scope_334->set("window",value_499);}
            // Camellya.py:246
            {V value_500=([&]()->V{V left_501=([&]()->V{auto fn_504=attr(global("np","Camellya"),"count_nonzero");Args args_503;args_503.pos(([&]()->V{V compare_505=scope_334->get("window");V compare_506;V comparison_result_507;compare_506=V(255LL);comparison_result_507=compare_value("==",compare_505,compare_506);return comparison_result_507;}()));return invoke(fn_504,args_503);}());V right_502=attr(scope_334->get("window"),"size");return official::binary("/",left_501,right_502);}());scope_334->set("white_ratio",value_500);}
            // Camellya.py:247
            if(([&]()->V{V compare_508=scope_334->get("white_ratio");V compare_509;V comparison_result_510;compare_509=V(0.375);comparison_result_510=compare_value("<",compare_508,compare_509);return comparison_result_510;}()).truth()){
                // Camellya.py:248
                if(([&]()->V{auto fn_512=attr(global("np","Camellya"),"any");Args args_511;args_511.pos(([&]()->V{V compare_513=item(scope_334->get("scores"),V::slice(([&]()->V{V left_515=scope_334->get("i");V right_516=V(1LL);return official::binary("+",left_515,right_516);}()),V{},V{}));V compare_514;V comparison_result_517;compare_514=scope_334->get("fft_thresh");comparison_result_517=compare_value(">",compare_513,compare_514);return comparison_result_517;}()));return invoke(fn_512,args_511);}()).truth()){
                    // Camellya.py:249
                    return V::tuple({unary("-",V(2LL)),unary("-",V(2LL))});
                }
                // Camellya.py:250
                scope_334->set("fail_count",official::binary("+",scope_334->get("fail_count"),V(1LL)));
                // Camellya.py:251
                if(([&]()->V{V compare_518=scope_334->get("fail_count");V compare_519;V comparison_result_520;compare_519=scope_334->get("max_fail_count");comparison_result_520=compare_value(">=",compare_518,compare_519);return comparison_result_520;}()).truth()){
                    // Camellya.py:252
                    break;
                }
            }
        }
    }
    }
    // Camellya.py:254
    {V value_525=V(0LL);scope_334->set("start_x",value_525);}
    // Camellya.py:255
    if(([&]()->V{V compare_526=scope_334->get("end_idx");V compare_527;V comparison_result_528;compare_527=V(0LL);comparison_result_528=compare_value("==",compare_526,compare_527);return comparison_result_528;}()).truth()){
        // Camellya.py:256
        {V value_529=V(0LL);scope_334->set("end_x",value_529);}
    }else{
        // Camellya.py:258
        if(([&]()->V{V compare_530=([&]()->V{V left_532=item(item(scope_334->get("positions"),scope_334->get("end_idx")),V(1LL));V right_533=scope_334->get("step");return official::binary("+",left_532,right_533);}());V compare_531;V comparison_result_534;compare_531=scope_334->get("width");comparison_result_534=compare_value(">=",compare_530,compare_531);return comparison_result_534;}()).truth()){
            // Camellya.py:259
            {V value_535=scope_334->get("width");scope_334->set("end_x",value_535);}
        }else{
            // Camellya.py:261
            {V value_536=item(item(scope_334->get("positions"),scope_334->get("end_idx")),V(0LL));scope_334->set("end_x",value_536);}
        }
    }
    // Camellya.py:262
    return V::tuple({scope_334->get("start_x"),scope_334->get("end_x")});
return V{};
}),false);
// Official method Camellya.calculate_forte_percent, lines 264-281
register_method("calculate_forte_percent",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"forte_color",V::missing()},{"box",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_537=bind_arguments(official_args,signature,captured);
scope_537->set("cropped",V::missing());
scope_537->set("end_x",V::missing());
scope_537->set("gray",V::missing());
scope_537->set("lower_bound",V::missing());
scope_537->set("ratio",V::missing());
scope_537->set("start_x",V::missing());
scope_537->set("stripe_area",V::missing());
scope_537->set("total_pixels",V::missing());
scope_537->set("upper_bound",V::missing());
scope_537->set("white_pixels",V::missing());
    // Camellya.py:265
    {V value_538=([&]()->V{auto fn_540=attr(scope_537->get("box"),"crop_frame");Args args_539;args_539.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_540,args_539);}());scope_537->set("cropped",value_538);}
    // Camellya.py:266
    {V value_541=([&]()->V{auto fn_543=global("color_range_to_bound","Camellya");Args args_542;args_542.pos(scope_537->get("forte_color"));return invoke(fn_543,args_542);}());auto unpack_544=unpack(value_541,2);scope_537->set("lower_bound",unpack_544[0]);scope_537->set("upper_bound",unpack_544[1]);}
    // Camellya.py:267
    {V value_545=([&]()->V{auto fn_547=attr(global("cv2","Camellya"),"inRange");Args args_546;args_546.pos(scope_537->get("cropped"));args_546.pos(scope_537->get("lower_bound"));args_546.pos(scope_537->get("upper_bound"));return invoke(fn_547,args_546);}());scope_537->set("gray",value_545);}
    // Camellya.py:268
    {V value_548=([&]()->V{auto fn_550=attr(self_value(),"detect_stripe_region");Args args_549;args_549.pos(scope_537->get("gray"));return invoke(fn_550,args_549);}());auto unpack_551=unpack(value_548,2);scope_537->set("start_x",unpack_551[0]);scope_537->set("end_x",unpack_551[1]);}
    // Camellya.py:269
    if(([&]()->V{V compare_552=scope_537->get("start_x");V compare_553;V comparison_result_554;compare_553=unary("-",V(2LL));comparison_result_554=compare_value("==",compare_552,compare_553);return comparison_result_554;}()).truth()){
        // Camellya.py:270
        ([&]()->V{auto fn_556=attr(attr(self_value(),"logger"),"debug");Args args_555;args_555.pos(V(std::string{}+"calculate_forte_percent failed due to interference"));return invoke(fn_556,args_555);}());
        // Camellya.py:271
        return unary("-",V(1LL));
    }
    // Camellya.py:272
    if(([&]()->V{V compare_557=scope_537->get("start_x");V compare_558;V comparison_result_559;compare_558=unary("-",V(1LL));comparison_result_559=compare_value("!=",compare_557,compare_558);return comparison_result_559;}()).truth()){
        // Camellya.py:273
        {V value_560=item(scope_537->get("gray"),V::tuple({V::slice(V{},V{},V{}),V::slice(scope_537->get("start_x"),scope_537->get("end_x"),V{})}));scope_537->set("stripe_area",value_560);}
        // Camellya.py:274
        {V value_561=attr(scope_537->get("stripe_area"),"size");scope_537->set("white_pixels",value_561);}
        // Camellya.py:275
        {V value_562=attr(scope_537->get("gray"),"size");scope_537->set("total_pixels",value_562);}
        // Camellya.py:276
        {V value_563=(([&]()->V{V compare_564=scope_537->get("total_pixels");V compare_565;V comparison_result_566;compare_565=V(0LL);comparison_result_566=compare_value(">",compare_564,compare_565);return comparison_result_566;}()).truth()?([&]()->V{V left_567=scope_537->get("white_pixels");V right_568=scope_537->get("total_pixels");return official::binary("/",left_567,right_568);}()):V(0LL));scope_537->set("ratio",value_563);}
    }else{
        // Camellya.py:278
        ([&]()->V{auto fn_570=attr(attr(self_value(),"logger"),"debug");Args args_569;args_569.pos(V(std::string{}+"using calculate_color_percentage"));return invoke(fn_570,args_569);}());
        // Camellya.py:279
        {V value_571=([&]()->V{V left_572=([&]()->V{auto fn_575=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_574;args_574.pos(scope_537->get("forte_color"));args_574.pos(scope_537->get("box"));return invoke(fn_575,args_574);}());V right_573=V(2LL);return official::binary("*",left_572,right_573);}());scope_537->set("ratio",value_571);}
        // Camellya.py:280
        {V value_576=(([&]()->V{V compare_577=scope_537->get("ratio");V compare_578;V comparison_result_579;compare_578=V(1LL);comparison_result_579=compare_value("<=",compare_577,compare_578);return comparison_result_579;}()).truth()?scope_537->get("ratio"):V(1LL));scope_537->set("ratio",value_576);}
    }
    // Camellya.py:281
    return scope_537->get("ratio");
return V{};
}),false);
// Official method Camellya.heavy_attack, lines 283-304
register_method("heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()},{"check_combat",V(true)},{"until_con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_580=bind_arguments(official_args,signature,captured);
scope_580->set("freeze_forte_check",V::missing());
scope_580->set("freeze_forte_time",V::missing());
scope_580->set("start",V::missing());
    // Camellya.py:284
    ([&]()->V{auto fn_582=attr(attr(self_value(),"logger"),"info");Args args_581;args_581.pos(V(std::string{}+"start heavy_attack"));return invoke(fn_582,args_581);}());
    // Camellya.py:285
    {V value_583=V(0LL);set_attr(self_value(),"last_forte",value_583);}
    // Camellya.py:286
    {V value_584=V(false);scope_580->set("freeze_forte_check",value_584);}
    // Camellya.py:287
    {V value_585=V(0LL);scope_580->set("freeze_forte_time",value_585);}
    // Camellya.py:288
    ([&]()->V{auto fn_587=attr(attr(self_value(),"task"),"mouse_down");Args args_586;return invoke(fn_587,args_586);}());
    // Camellya.py:289
    {V value_588=([&]()->V{auto fn_590=attr(global("time","Camellya"),"time");Args args_589;return invoke(fn_590,args_589);}());scope_580->set("start",value_588);}
    // Camellya.py:290
        while(([&]()->V{V compare_622=([&]()->V{V left_624=([&]()->V{auto fn_627=attr(global("time","Camellya"),"time");Args args_626;return invoke(fn_627,args_626);}());V right_625=scope_580->get("start");return official::binary("-",left_624,right_625);}());V compare_623;V comparison_result_628;compare_623=scope_580->get("duration");comparison_result_628=compare_value("<",compare_622,compare_623);return comparison_result_628;}()).truth()){
        // Camellya.py:291
        if(([&]()->V{V operand_591;operand_591=([&]()->V{V operand_592;operand_592=scope_580->get("until_con_full");if(!operand_592.truth())return operand_592;return ([&]()->V{auto fn_594=attr(self_value(),"is_con_full");Args args_593;return invoke(fn_594,args_593);}());}());if(operand_591.truth())return operand_591;return ([&]()->V{V compare_595=V(0LL);V compare_596;V comparison_result_597;compare_596=([&]()->V{auto fn_599=attr(self_value(),"get_forte");Args args_598;return invoke(fn_599,args_598);}());comparison_result_597=compare_value("<=",compare_595,compare_596);if(!comparison_result_597.truth())return comparison_result_597;compare_595=compare_596;compare_596=V(0.01);comparison_result_597=compare_value("<=",compare_595,compare_596);return comparison_result_597;}());}()).truth()){
            // Camellya.py:292
            break;
        }
        // Camellya.py:293
        if(scope_580->get("check_combat").truth()){
            // Camellya.py:294
            ([&]()->V{auto fn_601=attr(self_value(),"check_target");Args args_600;args_600.pos(V(true));return invoke(fn_601,args_600);}());
        }
        // Camellya.py:295
        ([&]()->V{auto fn_603=attr(attr(self_value(),"task"),"next_frame");Args args_602;return invoke(fn_603,args_602);}());
        // Camellya.py:296
        if(([&]()->V{V operand_604;operand_604=scope_580->get("freeze_forte_check");if(!operand_604.truth())return operand_604;return ([&]()->V{V compare_605=([&]()->V{V left_607=([&]()->V{auto fn_610=attr(global("time","Camellya"),"time");Args args_609;return invoke(fn_610,args_609);}());V right_608=scope_580->get("freeze_forte_time");return official::binary("-",left_607,right_608);}());V compare_606;V comparison_result_611;compare_606=V(0.2);comparison_result_611=compare_value(">=",compare_605,compare_606);return comparison_result_611;}());}()).truth()){
            // Camellya.py:297
            {V value_612=V(false);scope_580->set("freeze_forte_check",value_612);}
        }
        // Camellya.py:298
        if(unary("not",scope_580->get("freeze_forte_check")).truth()){
            // Camellya.py:299
            if(([&]()->V{V compare_613=([&]()->V{auto fn_616=attr(self_value(),"should_retry_heavy_attack");Args args_615;return invoke(fn_616,args_615);}());V compare_614;V comparison_result_617;compare_614=V(0LL);comparison_result_617=compare_value("<",compare_613,compare_614);return comparison_result_617;}()).truth()){
                // Camellya.py:300
                {V value_618=V(true);scope_580->set("freeze_forte_check",value_618);}
                // Camellya.py:301
                {V value_619=([&]()->V{auto fn_621=attr(global("time","Camellya"),"time");Args args_620;return invoke(fn_621,args_620);}());scope_580->set("freeze_forte_time",value_619);}
            }
        }
    }
    // Camellya.py:302
    ([&]()->V{auto fn_630=attr(self_value(),"sleep");Args args_629;args_629.pos(V(0.1));args_629.pos(V(false));return invoke(fn_630,args_629);}());
    // Camellya.py:303
    ([&]()->V{auto fn_632=attr(attr(self_value(),"task"),"mouse_up");Args args_631;return invoke(fn_632,args_631);}());
    // Camellya.py:304
    {V value_633=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_633);}
return V{};
}),false);
// Official method Camellya.should_retry_heavy_attack, lines 306-329
register_method("should_retry_heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"budding",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_634=bind_arguments(official_args,signature,captured);
scope_634->set("current_forte",V::missing());
scope_634->set("diff",V::missing());
    // Camellya.py:307
    {V value_635=([&]()->V{auto fn_637=attr(self_value(),"get_forte");Args args_636;args_636.pos(scope_634->get("budding"));return invoke(fn_637,args_636);}());scope_634->set("current_forte",value_635);}
    // Camellya.py:308
    if(([&]()->V{V compare_638=scope_634->get("current_forte");V compare_639;V comparison_result_640;compare_639=V(0LL);comparison_result_640=compare_value("<",compare_638,compare_639);return comparison_result_640;}()).truth()){
        // Camellya.py:309
        return unary("-",V(1LL));
    }
    // Camellya.py:310
    {V value_641=([&]()->V{V left_642=attr(self_value(),"last_forte");V right_643=scope_634->get("current_forte");return official::binary("-",left_642,right_643);}());scope_634->set("diff",value_641);}
    // Camellya.py:311
    ([&]()->V{auto fn_645=attr(attr(self_value(),"logger"),"debug");Args args_644;args_644.pos(V(std::string{}+"diff "+format_value(scope_634->get("diff"),"",-1)));return invoke(fn_645,args_644);}());
    // Camellya.py:312
    if(([&]()->V{V operand_646;operand_646=unary("not",attr(self_value(),"waiting_for_forte_drop"));if(!operand_646.truth())return operand_646;return ([&]()->V{V compare_647=V(0LL);V compare_648;V comparison_result_649;compare_648=scope_634->get("diff");comparison_result_649=compare_value("<=",compare_647,compare_648);if(!comparison_result_649.truth())return comparison_result_649;compare_647=compare_648;compare_648=V(0.01);comparison_result_649=compare_value("<=",compare_647,compare_648);return comparison_result_649;}());}()).truth()){
        // Camellya.py:313
        {V value_650=V(true);set_attr(self_value(),"waiting_for_forte_drop",value_650);}
        // Camellya.py:314
        {V value_651=([&]()->V{auto fn_653=attr(global("time","Camellya"),"time");Args args_652;return invoke(fn_653,args_652);}());set_attr(self_value(),"forte_drop_timestamp",value_651);}
        // Camellya.py:315
        {V value_654=V::list({});set_attr(self_value(),"forte_diff_buffer",value_654);}
    }
    // Camellya.py:316
    if(attr(self_value(),"waiting_for_forte_drop").truth()){
        // Camellya.py:317
        ([&]()->V{auto fn_656=attr(attr(self_value(),"forte_diff_buffer"),"append");Args args_655;args_655.pos(scope_634->get("diff"));return invoke(fn_656,args_655);}());
        // Camellya.py:318
        if(([&]()->V{V compare_657=([&]()->V{auto fn_662=attr(([&]()->V{auto fn_660=attr(global("np","Camellya"),"array");Args args_659;args_659.pos(attr(self_value(),"forte_diff_buffer"));return invoke(fn_660,args_659);}()),"sum");Args args_661;return invoke(fn_662,args_661);}());V compare_658;V comparison_result_663;compare_658=V(0.01);comparison_result_663=compare_value(">",compare_657,compare_658);return comparison_result_663;}()).truth()){
            // Camellya.py:319
            {V value_664=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_664);}
            // Camellya.py:320
            ([&]()->V{auto fn_666=attr(attr(self_value(),"logger"),"debug");Args args_665;args_665.pos(V(std::string{}+"diff "+format_value(scope_634->get("diff"),"",-1)));return invoke(fn_666,args_665);}());
        }
    }
    // Camellya.py:321
    if(([&]()->V{V operand_667;operand_667=attr(self_value(),"waiting_for_forte_drop");if(!operand_667.truth())return operand_667;return ([&]()->V{V compare_668=([&]()->V{auto fn_671=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_670;args_670.pos(attr(self_value(),"forte_drop_timestamp"));return invoke(fn_671,args_670);}());V compare_669;V comparison_result_672;compare_669=V(0.6);comparison_result_672=compare_value(">",compare_668,compare_669);return comparison_result_672;}());}()).truth()){
        // Camellya.py:322
        {V value_673=V(false);set_attr(self_value(),"waiting_for_forte_drop",value_673);}
        // Camellya.py:323
        ([&]()->V{auto fn_675=attr(attr(self_value(),"logger"),"info");Args args_674;args_674.pos(V(std::string{}+"retry heavy attack"));return invoke(fn_675,args_674);}());
        // Camellya.py:324
        ([&]()->V{auto fn_677=attr(attr(self_value(),"task"),"mouse_up");Args args_676;return invoke(fn_677,args_676);}());
        // Camellya.py:325
        ([&]()->V{auto fn_679=attr(self_value(),"sleep");Args args_678;args_678.pos(V(0.1));args_678.pos(V(false));return invoke(fn_679,args_678);}());
        // Camellya.py:326
        ([&]()->V{auto fn_681=attr(attr(self_value(),"task"),"mouse_down");Args args_680;return invoke(fn_681,args_680);}());
        // Camellya.py:327
        ([&]()->V{auto fn_683=attr(self_value(),"sleep");Args args_682;args_682.pos(V(0.1));args_682.pos(V(false));return invoke(fn_683,args_682);}());
    }
    // Camellya.py:328
    {V value_684=scope_634->get("current_forte");set_attr(self_value(),"last_forte",value_684);}
    // Camellya.py:329
    return V(0LL);
return V{};
}),false);
// Official method Camellya.check_target, lines 331-341
register_method("check_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"is_heavy_att",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_685=bind_arguments(official_args,signature,captured);
    // Camellya.py:332
    if(unary("not",([&]()->V{auto fn_687=attr(attr(self_value(),"task"),"has_target");Args args_686;return invoke(fn_687,args_686);}())).truth()){
        // Camellya.py:333
        if(scope_685->get("is_heavy_att").truth()){
            // Camellya.py:334
            ([&]()->V{auto fn_689=attr(attr(self_value(),"logger"),"info");Args args_688;args_688.pos(V(std::string{}+"check_target Release"));return invoke(fn_689,args_688);}());
            // Camellya.py:335
            ([&]()->V{auto fn_691=attr(attr(self_value(),"task"),"mouse_up");Args args_690;return invoke(fn_691,args_690);}());
        }
        // Camellya.py:336
        ([&]()->V{auto fn_693=attr(attr(self_value(),"logger"),"info");Args args_692;args_692.pos(V(std::string{}+"check_combat"));return invoke(fn_693,args_692);}());
        // Camellya.py:337
        ([&]()->V{auto fn_695=attr(self_value(),"check_combat");Args args_694;return invoke(fn_695,args_694);}());
        // Camellya.py:338
        ([&]()->V{auto fn_697=attr(attr(self_value(),"task"),"next_frame");Args args_696;return invoke(fn_697,args_696);}());
        // Camellya.py:339
        if(scope_685->get("is_heavy_att").truth()){
            // Camellya.py:340
            ([&]()->V{auto fn_699=attr(attr(self_value(),"logger"),"info");Args args_698;args_698.pos(V(std::string{}+"check_target Retry"));return invoke(fn_699,args_698);}());
            // Camellya.py:341
            ([&]()->V{auto fn_701=attr(attr(self_value(),"task"),"mouse_down");Args args_700;return invoke(fn_701,args_700);}());
        }
    }
return V{};
}),false);
}
}
