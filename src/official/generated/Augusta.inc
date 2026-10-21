// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Augusta.py
// SHA256 e1854ced9585ecdafdb227ba992af420c68a3245871f01776f6380652867a74f
void OfficialCharacter::install_Augusta(){
auto scope=std::make_shared<Scope>();
set_global("switch_time",V(3LL));
// Official method Augusta.do_perform, lines 13-62
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("now",V::missing());
scope_1->set("start",V::missing());
scope_1->set("time_out",V::missing());
scope_1->set("timeout",V::missing());
    // Augusta.py:14
    {V value_2=global("switch_time","Augusta");scope_1->set("time_out",value_2);}
    // Augusta.py:15
    if(attr(self_value(),"has_intro").truth()){
        // Augusta.py:16
        ([&]()->V{auto fn_4=attr(self_value(),"continues_normal_attack");Args args_3;args_3.pos(V(1.13));return invoke(fn_4,args_3);}());
        // Augusta.py:17
        if(([&]()->V{V operand_5;operand_5=attr(self_value(),"has_sub_dps_intro");if(!operand_5.truth())return operand_5;return ([&]()->V{V compare_6=([&]()->V{auto fn_9=attr(self_value(),"check_outro");Args args_8;return invoke(fn_9,args_8);}());V compare_7;V comparison_result_10;compare_7=V::set({V("char_iuno")});comparison_result_10=compare_value("in",compare_6,compare_7);return comparison_result_10;}());}()).truth()){
            // Augusta.py:18
            {V value_11=V(14LL);scope_1->set("time_out",value_11);}
        }
    }
    // Augusta.py:19
    if(([&]()->V{auto fn_13=attr(self_value(),"flying");Args args_12;return invoke(fn_13,args_12);}()).truth()){
        // Augusta.py:20
        ([&]()->V{auto fn_15=attr(self_value(),"wait_down");Args args_14;return invoke(fn_15,args_14);}());
    }
    // Augusta.py:21
    {V value_16=([&]()->V{auto fn_18=attr(global("time","Augusta"),"time");Args args_17;return invoke(fn_18,args_17);}());scope_1->set("start",value_16);}
    // Augusta.py:22
    {V value_19=V::function([this,captured=capture_scope(scope_1,{"start","time_out"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_20=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_21=([&]()->V{V left_23=([&]()->V{auto fn_26=attr(global("time","Augusta"),"time");Args args_25;return invoke(fn_26,args_25);}());V right_24=scope_20->get("start");return official::binary("-",left_23,right_24);}());V compare_22;V comparison_result_27;compare_22=([&]()->V{V left_28=scope_20->get("time_out");V right_29=V(3LL);return official::binary("+",left_28,right_29);}());comparison_result_27=compare_value("<",compare_21,compare_22);return comparison_result_27;}());
});scope_1->set("timeout",value_19);}
    // Augusta.py:23
        while(([&]()->V{auto fn_132=scope_1->get("timeout");Args args_131;return invoke(fn_132,args_131);}()).truth()){
        // Augusta.py:24
        ([&]()->V{auto fn_31=attr(self_value(),"cycle_start");Args args_30;return invoke(fn_31,args_30);}());
        // Augusta.py:25
        if(([&]()->V{auto fn_33=attr(self_value(),"check_majesty");Args args_32;return invoke(fn_33,args_32);}()).truth()){
            // Augusta.py:26
            ([&]()->V{auto fn_35=attr(attr(self_value(),"logger"),"debug");Args args_34;args_34.pos(V("Augusta performs majesty"));return invoke(fn_35,args_34);}());
            // Augusta.py:27
            if(([&]()->V{auto fn_37=attr(self_value(),"perform_majesty");Args args_36;return invoke(fn_37,args_36);}()).truth()){
                // Augusta.py:28
                ([&]()->V{auto fn_39=attr(self_value(),"send_echo_key");Args args_38;return invoke(fn_39,args_38);}());
                // Augusta.py:29
                return ([&]()->V{auto fn_41=attr(self_value(),"switch_next_char");Args args_40;return invoke(fn_41,args_40);}());
            }
        }
        // Augusta.py:30
        if(([&]()->V{auto fn_43=attr(self_value(),"flying");Args args_42;return invoke(fn_43,args_42);}()).truth()){
            // Augusta.py:31
            ([&]()->V{auto fn_45=attr(self_value(),"shorekeeper_auto_dodge");Args args_44;return invoke(fn_45,args_44);}());
        }
        // Augusta.py:32
        if(([&]()->V{V operand_46;operand_46=([&]()->V{auto fn_48=attr(self_value(),"check_prowess");Args args_47;return invoke(fn_48,args_47);}());if(!operand_46.truth())return operand_46;return ([&]()->V{auto fn_50=attr(self_value(),"perform_prowess");Args args_49;return invoke(fn_50,args_49);}());}()).truth()){
            // Augusta.py:33
            if(([&]()->V{V compare_51=([&]()->V{V left_53=([&]()->V{auto fn_56=attr(global("time","Augusta"),"time");Args args_55;return invoke(fn_56,args_55);}());V right_54=scope_1->get("start");return official::binary("-",left_53,right_54);}());V compare_52;V comparison_result_57;compare_52=scope_1->get("time_out");comparison_result_57=compare_value(">",compare_51,compare_52);return comparison_result_57;}()).truth()){
                // Augusta.py:34
                return ([&]()->V{auto fn_59=attr(self_value(),"switch_next_char");Args args_58;return invoke(fn_59,args_58);}());
            }
        }
        // Augusta.py:35
        if(([&]()->V{auto fn_61=attr(self_value(),"resonance_available");Args args_60;return invoke(fn_61,args_60);}()).truth()){
            // Augusta.py:36
            ([&]()->V{auto fn_63=attr(attr(self_value(),"logger"),"debug");Args args_62;args_62.pos(V("Augusta performs single resonance"));return invoke(fn_63,args_62);}());
            // Augusta.py:37
            {V value_64=([&]()->V{auto fn_66=attr(global("time","Augusta"),"time");Args args_65;return invoke(fn_66,args_65);}());scope_1->set("now",value_64);}
            // Augusta.py:38
            ([&]()->V{auto fn_68=attr(self_value(),"click_resonance");Args args_67;return invoke(fn_68,args_67);}());
            // Augusta.py:39
            ([&]()->V{auto fn_70=attr(attr(self_value(),"logger"),"debug");Args args_69;args_69.pos(V(std::string{}+"time = "+format_value(([&]()->V{V left_71=([&]()->V{auto fn_74=attr(global("time","Augusta"),"time");Args args_73;return invoke(fn_74,args_73);}());V right_72=scope_1->get("now");return official::binary("-",left_71,right_72);}()),"",-1)));return invoke(fn_70,args_69);}());
            // Augusta.py:40
            if(([&]()->V{V compare_75=([&]()->V{V left_77=([&]()->V{auto fn_80=attr(global("time","Augusta"),"time");Args args_79;return invoke(fn_80,args_79);}());V right_78=scope_1->get("now");return official::binary("-",left_77,right_78);}());V compare_76;V comparison_result_81;compare_76=V(1.4);comparison_result_81=compare_value("<",compare_75,compare_76);return comparison_result_81;}()).truth()){
                // Augusta.py:41
                if(([&]()->V{auto fn_83=attr(self_value(),"flying");Args args_82;return invoke(fn_83,args_82);}()).truth()){
                    // Augusta.py:42
                    continue;
                }
                // Augusta.py:43
                if(([&]()->V{V operand_84;operand_84=([&]()->V{auto fn_86=attr(attr(self_value(),"task"),"wait_until");Args args_85;args_85.pos(attr(self_value(),"check_prowess"));args_85.kw("time_out",V(1LL));return invoke(fn_86,args_85);}());if(!operand_84.truth())return operand_84;return ([&]()->V{auto fn_88=attr(self_value(),"perform_prowess");Args args_87;return invoke(fn_88,args_87);}());}()).truth()){
                    // Augusta.py:44
                    if(([&]()->V{V operand_89;operand_89=([&]()->V{V compare_90=([&]()->V{V left_92=([&]()->V{auto fn_95=attr(global("time","Augusta"),"time");Args args_94;return invoke(fn_95,args_94);}());V right_93=scope_1->get("start");return official::binary("-",left_92,right_93);}());V compare_91;V comparison_result_96;compare_91=scope_1->get("time_out");comparison_result_96=compare_value(">",compare_90,compare_91);return comparison_result_96;}());if(!operand_89.truth())return operand_89;return unary("not",([&]()->V{auto fn_98=attr(self_value(),"flying");Args args_97;return invoke(fn_98,args_97);}()));}()).truth()){
                        // Augusta.py:45
                        return ([&]()->V{auto fn_100=attr(self_value(),"switch_next_char");Args args_99;return invoke(fn_100,args_99);}());
                    }
                }
            }else{
                // Augusta.py:47
                if(([&]()->V{auto fn_102=attr(self_value(),"check_majesty");Args args_101;return invoke(fn_102,args_101);}()).truth()){
                    // Augusta.py:48
                    ([&]()->V{auto fn_104=attr(self_value(),"wait_down");Args args_103;return invoke(fn_104,args_103);}());
                    // Augusta.py:49
                    if(([&]()->V{auto fn_106=attr(self_value(),"perform_majesty");Args args_105;return invoke(fn_106,args_105);}()).truth()){
                        // Augusta.py:50
                        ([&]()->V{auto fn_108=attr(self_value(),"send_echo_key");Args args_107;return invoke(fn_108,args_107);}());
                    }
                    // Augusta.py:51
                    return ([&]()->V{auto fn_110=attr(self_value(),"switch_next_char");Args args_109;return invoke(fn_110,args_109);}());
                }
            }
        }
        // Augusta.py:52
        if(([&]()->V{auto fn_112=attr(self_value(),"liberation_available");Args args_111;return invoke(fn_112,args_111);}()).truth()){
            // Augusta.py:53
            ([&]()->V{auto fn_114=attr(attr(self_value(),"logger"),"debug");Args args_113;args_113.pos(V("Augusta performs single liberation"));return invoke(fn_114,args_113);}());
            // Augusta.py:54
            if(([&]()->V{auto fn_116=attr(attr(self_value(),"task"),"wait_until");Args args_115;args_115.pos(V::function([this,captured=capture_scope(scope_1,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_117=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_119=attr(self_value(),"liberation_available");Args args_118;return invoke(fn_119,args_118);}()));
}));args_115.kw("post_action",attr(self_value(),"send_liberation_key"));args_115.kw("time_out",V(2LL));return invoke(fn_116,args_115);}()).truth()){
                // Augusta.py:56
                ([&]()->V{auto fn_121=attr(self_value(),"record_liberation_use");Args args_120;return invoke(fn_121,args_120);}());
                // Augusta.py:57
                if(([&]()->V{V compare_122=scope_1->get("time_out");V compare_123;V comparison_result_124;compare_123=V(14LL);comparison_result_124=compare_value("<",compare_122,compare_123);return comparison_result_124;}()).truth()){
                    // Augusta.py:58
                    return ([&]()->V{auto fn_126=attr(self_value(),"switch_next_char");Args args_125;return invoke(fn_126,args_125);}());
                }
            }
        }
        // Augusta.py:59
        ([&]()->V{auto fn_128=attr(self_value(),"click");Args args_127;return invoke(fn_128,args_127);}());
        // Augusta.py:60
        ([&]()->V{auto fn_130=attr(self_value(),"cycle_sleep");Args args_129;return invoke(fn_130,args_129);}());
    }
    // Augusta.py:61
    ([&]()->V{auto fn_134=attr(self_value(),"send_echo_key");Args args_133;return invoke(fn_134,args_133);}());
    // Augusta.py:62
    ([&]()->V{auto fn_136=attr(self_value(),"switch_next_char");Args args_135;return invoke(fn_136,args_135);}());
return V{};
}),false);
// Official method Augusta.perform_prowess, lines 64-69
register_method("perform_prowess",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_137=bind_arguments(official_args,signature,captured);
    // Augusta.py:65
    ([&]()->V{auto fn_139=attr(attr(self_value(),"logger"),"debug");Args args_138;args_138.pos(V("Augusta performs prowess"));return invoke(fn_139,args_138);}());
    // Augusta.py:66
    if(unary("not",([&]()->V{auto fn_141=attr(self_value(),"heavy_click_forte");Args args_140;args_140.pos(attr(self_value(),"check_prowess"));return invoke(fn_141,args_140);}())).truth()){
        // Augusta.py:67
        return V(false);
    }
    // Augusta.py:68
    ([&]()->V{auto fn_143=attr(self_value(),"continues_normal_attack");Args args_142;args_142.pos(V(0.3));return invoke(fn_143,args_142);}());
    // Augusta.py:69
    return V(true);
return V{};
}),false);
// Official method Augusta.perform_majesty, lines 71-88
register_method("perform_majesty",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(0.6)},{"wait_down",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_144=bind_arguments(official_args,signature,captured);
scope_144->set("start",V::missing());
    // Augusta.py:72
    ([&]()->V{auto fn_146=attr(attr(self_value(),"task"),"send_key_down");Args args_145;args_145.pos(([&]()->V{auto fn_148=attr(self_value(),"get_liberation_key");Args args_147;return invoke(fn_148,args_147);}()));return invoke(fn_146,args_145);}());
    // Augusta.py:73
    {V value_149=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_149);}
    // Augusta.py:74
    if(scope_144->get("wait_down").truth()){
        // Augusta.py:75
        {V value_150=V(0.2);scope_144->set("time_out",value_150);}
        // Augusta.py:76
        ([&]()->V{auto fn_152=attr(attr(self_value(),"task"),"wait_until");Args args_151;args_151.pos(V::function([this,captured=capture_scope(scope_144,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_153=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_154;operand_154=unary("not",item(([&]()->V{auto fn_156=attr(attr(self_value(),"task"),"in_team");Args args_155;return invoke(fn_156,args_155);}()),V(0LL)));if(operand_154.truth())return operand_154;return unary("not",([&]()->V{auto fn_158=attr(self_value(),"flying");Args args_157;return invoke(fn_158,args_157);}()));}());
}));args_151.kw("time_out",V(2LL));return invoke(fn_152,args_151);}());
    }
    // Augusta.py:77
    ([&]()->V{auto fn_160=attr(attr(self_value(),"task"),"wait_until");Args args_159;args_159.pos(V::function([this,captured=capture_scope(scope_144,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_161=bind_arguments(official_args,signature,captured);
return unary("not",item(([&]()->V{auto fn_163=attr(attr(self_value(),"task"),"in_team");Args args_162;return invoke(fn_163,args_162);}()),V(0LL)));
}));args_159.kw("time_out",scope_144->get("time_out"));return invoke(fn_160,args_159);}());
    // Augusta.py:78
    {V value_164=([&]()->V{auto fn_166=attr(global("time","Augusta"),"time");Args args_165;return invoke(fn_166,args_165);}());scope_144->set("start",value_164);}
    // Augusta.py:79
    ([&]()->V{auto fn_168=attr(attr(self_value(),"task"),"send_key_up");Args args_167;args_167.pos(([&]()->V{auto fn_170=attr(self_value(),"get_liberation_key");Args args_169;return invoke(fn_170,args_169);}()));return invoke(fn_168,args_167);}());
    // Augusta.py:80
    if(item(([&]()->V{auto fn_172=attr(attr(self_value(),"task"),"in_team");Args args_171;return invoke(fn_172,args_171);}()),V(0LL)).truth()){
        // Augusta.py:81
        ([&]()->V{auto fn_174=attr(attr(self_value(),"logger"),"debug");Args args_173;args_173.pos(V("Augusta performs majesty failed: not in animation"));return invoke(fn_174,args_173);}());
        // Augusta.py:82
        {V value_175=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_175);}
        // Augusta.py:83
        return V(false);
    }
    // Augusta.py:84
    ([&]()->V{auto fn_177=attr(attr(self_value(),"task"),"wait_until");Args args_176;args_176.pos(V::function([this,captured=capture_scope(scope_144,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_178=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_180=attr(attr(self_value(),"task"),"in_team");Args args_179;return invoke(fn_180,args_179);}()),V(0LL));
}));args_176.kw("post_action",attr(self_value(),"click"));args_176.kw("time_out",V(10LL));return invoke(fn_177,args_176);}());
    // Augusta.py:85
    ([&]()->V{auto fn_182=attr(self_value(),"add_freeze_duration");Args args_181;args_181.pos(scope_144->get("start"));args_181.pos(([&]()->V{V left_183=([&]()->V{auto fn_186=attr(global("time","Augusta"),"time");Args args_185;return invoke(fn_186,args_185);}());V right_184=scope_144->get("start");return official::binary("-",left_183,right_184);}()));return invoke(fn_182,args_181);}());
    // Augusta.py:86
    ([&]()->V{auto fn_188=attr(attr(self_value(),"logger"),"info");Args args_187;args_187.pos(V(std::string{}+"click_liberation end "+format_value(([&]()->V{V left_189=([&]()->V{auto fn_192=attr(global("time","Augusta"),"time");Args args_191;return invoke(fn_192,args_191);}());V right_190=scope_144->get("start");return official::binary("-",left_189,right_190);}()),"",-1)));return invoke(fn_188,args_187);}());
    // Augusta.py:88
    return V(true);
return V{};
}),false);
// Official method Augusta.check_ascendancy, lines 90-91
register_method("check_ascendancy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_193=bind_arguments(official_args,signature,captured);
    // Augusta.py:91
    return V(false);
return V{};
}),false);
// Official method Augusta.liberation_available, lines 93-94
register_method("liberation_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_color",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_194=bind_arguments(official_args,signature,captured);
    // Augusta.py:94
    return ([&]()->V{V operand_195;operand_195=([&]()->V{V compare_196=([&]()->V{auto fn_199=attr(self_value(),"current_liberation");Args args_198;return invoke(fn_199,args_198);}());V compare_197;V comparison_result_200;compare_197=V(0LL);comparison_result_200=compare_value(">",compare_196,compare_197);return comparison_result_200;}());if(!operand_195.truth())return operand_195;return ([&]()->V{auto fn_202=global("bool","Augusta");Args args_201;args_201.pos(([&]()->V{auto fn_204=attr(attr(self_value(),"task"),"find_one");Args args_203;args_203.pos(V("Augusta_lib1"));args_203.kw("threshold",V(0.5));return invoke(fn_204,args_203);}()));return invoke(fn_202,args_201);}());}());
return V{};
}),false);
// Official method Augusta.check_majesty, lines 96-97
register_method("check_majesty",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_205=bind_arguments(official_args,signature,captured);
    // Augusta.py:97
    return ([&]()->V{V operand_206;operand_206=([&]()->V{V compare_207=([&]()->V{auto fn_210=attr(self_value(),"current_liberation");Args args_209;return invoke(fn_210,args_209);}());V compare_208;V comparison_result_211;compare_208=V(0LL);comparison_result_211=compare_value(">",compare_207,compare_208);return comparison_result_211;}());if(!operand_206.truth())return operand_206;return ([&]()->V{auto fn_213=global("bool","Augusta");Args args_212;args_212.pos(([&]()->V{auto fn_215=attr(attr(self_value(),"task"),"find_one");Args args_214;args_214.pos(V("Augusta_lib2"));args_214.kw("threshold",V(0.5));return invoke(fn_215,args_214);}()));return invoke(fn_213,args_212);}());}());
return V{};
}),false);
// Official method Augusta.check_prowess, lines 99-102
register_method("check_prowess",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_216=bind_arguments(official_args,signature,captured);
scope_216->set("long_inner_box",V::missing());
    // Augusta.py:100
    {V value_217=V("target_enemy_long_inner");scope_216->set("long_inner_box",value_217);}
    // Augusta.py:101
    if(([&]()->V{auto fn_219=attr(attr(self_value(),"task"),"find_one");Args args_218;args_218.pos(scope_216->get("long_inner_box"));args_218.kw("threshold",V(0.8));return invoke(fn_219,args_218);}()).truth()){
        // Augusta.py:102
        return V(true);
    }
return V{};
}),false);
// Official method Augusta.resonance_available, lines 104-105
register_method("resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_220=bind_arguments(official_args,signature,captured);
    // Augusta.py:105
    return unary("not",([&]()->V{auto fn_222=attr(self_value(),"has_cd");Args args_221;args_221.pos(V("resonance"));return invoke(fn_222,args_221);}()));
return V{};
}),false);
// Official method Augusta.shorekeeper_auto_dodge, lines 107-111
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_223=bind_arguments(official_args,signature,captured);
scope_223->set("ShoreKeeper",V::missing());
scope_223->set("char",V::missing());
scope_223->set("i",V::missing());
    // Augusta.py:108
    scope_223->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Augusta.py:109
    {auto iterator_224=official::iterate(([&]()->V{auto fn_231=global("enumerate","Augusta");Args args_230;args_230.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_231,args_230);}()));V item_225;while(iterator_224.next(item_225)){
        auto unpack_232=unpack(item_225,2);scope_223->set("i",unpack_232[0]);scope_223->set("char",unpack_232[1]);
        // Augusta.py:110
        if(([&]()->V{auto fn_227=global("isinstance","Augusta");Args args_226;args_226.pos(scope_223->get("char"));args_226.pos(scope_223->get("ShoreKeeper"));return invoke(fn_227,args_226);}()).truth()){
            // Augusta.py:111
            return ([&]()->V{auto fn_229=attr(scope_223->get("char"),"auto_dodge");Args args_228;args_228.kw("condition",attr(self_value(),"flying"));return invoke(fn_229,args_228);}());
        }
    }
    }
return V{};
}),false);
// Official method Augusta.on_combat_end, lines 113-116
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_233=bind_arguments(official_args,signature,captured);
scope_233->set("next_char",V::missing());
    // Augusta.py:114
    {V value_234=([&]()->V{auto fn_236=global("str","Augusta");Args args_235;args_235.pos(([&]()->V{V left_237=([&]()->V{V left_239=([&]()->V{V left_241=attr(self_value(),"index");V right_242=V(1LL);return official::binary("+",left_241,right_242);}());V right_240=([&]()->V{auto fn_244=global("len","Augusta");Args args_243;args_243.pos(scope_233->get("chars"));return invoke(fn_244,args_243);}());return official::binary("%",left_239,right_240);}());V right_238=V(1LL);return official::binary("+",left_237,right_238);}()));return invoke(fn_236,args_235);}());scope_233->set("next_char",value_234);}
    // Augusta.py:115
    ([&]()->V{auto fn_246=attr(attr(self_value(),"logger"),"debug");Args args_245;args_245.pos(V(std::string{}+"Augusta on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch next char: "+format_value(scope_233->get("next_char"),"",-1)));return invoke(fn_246,args_245);}());
    // Augusta.py:116
    ([&]()->V{auto fn_248=attr(attr(self_value(),"task"),"send_key");Args args_247;args_247.pos(scope_233->get("next_char"));return invoke(fn_248,args_247);}());
return V{};
}),false);
}
