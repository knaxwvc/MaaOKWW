// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Phrolova.py
// SHA256 403c671284bce41dd3cb6cb2b0ec2e635e0480d58a12057cd15acb7fac729e01
void OfficialCharacter::install_Phrolova(){
auto scope=std::make_shared<Scope>();
// Official method Phrolova.__init__, lines 7-11
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Phrolova.py:8
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Phrolova");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Phrolova.py:9
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_6);}
    // Phrolova.py:10
    {V value_7=V(false);set_attr(self_value(),"sp",value_7);}
    // Phrolova.py:11
    {V value_8=V(false);set_attr(self_value(),"res_ready",value_8);}
return V{};
}),false);
// Official method Phrolova.skip_combat_check, lines 13-14
register_method("skip_combat_check",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_9=bind_arguments(official_args,signature,captured);
    // Phrolova.py:14
    return ([&]()->V{V compare_10=([&]()->V{auto fn_13=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_12;args_12.pos(attr(self_value(),"last_liberation"));return invoke(fn_13,args_12);}());V compare_11;V comparison_result_14;compare_11=V(2LL);comparison_result_14=compare_value("<",compare_10,compare_11);return comparison_result_14;}());
return V{};
}),false);
// Official method Phrolova.f_break, lines 16-23
register_method("f_break",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_f_on_switch",V(false)},{"force",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
scope_15->set("_",V::missing());
scope_15->set("current_index",V::missing());
scope_15->set("in_team",V::missing());
    // Phrolova.py:17
    if(([&]()->V{V operand_16;operand_16=scope_15->get("check_f_on_switch");if(!operand_16.truth())return operand_16;operand_16=unary("not",scope_15->get("force"));if(!operand_16.truth())return operand_16;operand_16=([&]()->V{V compare_17=attr(self_value(),"last_liberation");V compare_18;V comparison_result_19;compare_18=V(0LL);comparison_result_19=compare_value(">=",compare_17,compare_18);return comparison_result_19;}());if(!operand_16.truth())return operand_16;return ([&]()->V{V compare_20=([&]()->V{auto fn_23=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_22;args_22.pos(attr(self_value(),"last_liberation"));return invoke(fn_23,args_22);}());V compare_21;V comparison_result_24;compare_21=V(24LL);comparison_result_24=compare_value("<",compare_20,compare_21);return comparison_result_24;}());}()).truth()){
        // Phrolova.py:19
        {V value_25=([&]()->V{auto fn_27=attr(attr(self_value(),"task"),"in_team");Args args_26;return invoke(fn_27,args_26);}());auto unpack_28=unpack(value_25,3);scope_15->set("in_team",unpack_28[0]);scope_15->set("current_index",unpack_28[1]);scope_15->set("_",unpack_28[2]);}
        // Phrolova.py:21
        if(([&]()->V{V operand_29;operand_29=scope_15->get("in_team");if(!operand_29.truth())return operand_29;return ([&]()->V{V compare_30=scope_15->get("current_index");V compare_31;V comparison_result_32;compare_31=attr(self_value(),"index");comparison_result_32=compare_value("==",compare_30,compare_31);return comparison_result_32;}());}()).truth()){
            // Phrolova.py:22
            return V(false);
        }
    }
    // Phrolova.py:23
    return ([&]()->V{auto fn_36=attr(([&]()->V{auto fn_34=global("super","Phrolova");Args args_33;return invoke(fn_34,args_33);}()),"f_break");Args args_35;args_35.kw("check_f_on_switch",scope_15->get("check_f_on_switch"));args_35.kw("force",scope_15->get("force"));return invoke(fn_36,args_35);}());
return V{};
}),false);
// Official method Phrolova.do_perform, lines 25-76
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_37=bind_arguments(official_args,signature,captured);
scope_37->set("perform_under_outro",V::missing());
scope_37->set("start",V::missing());
scope_37->set("timeout",V::missing());
    // Phrolova.py:26
    {V value_38=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_38);}
    // Phrolova.py:27
    {V value_39=V(false);scope_37->set("perform_under_outro",value_39);}
    // Phrolova.py:28
    {V value_40=V(false);set_attr(self_value(),"sp",value_40);}
    // Phrolova.py:29
    if(attr(self_value(),"has_intro").truth()){
        // Phrolova.py:30
        {V value_41=V(false);set_attr(self_value(),"res_ready",value_41);}
        // Phrolova.py:31
        if(([&]()->V{V compare_42=([&]()->V{auto fn_45=attr(self_value(),"check_outro");Args args_44;return invoke(fn_45,args_44);}());V compare_43;V comparison_result_46;compare_43=V::set({V("char_cantarella")});comparison_result_46=compare_value("in",compare_42,compare_43);return comparison_result_46;}()).truth()){
            // Phrolova.py:32
            {V value_47=V(true);scope_37->set("perform_under_outro",value_47);}
        }
        // Phrolova.py:33
        ([&]()->V{auto fn_49=attr(self_value(),"continues_normal_attack");Args args_48;args_48.pos(V(1.7));return invoke(fn_49,args_48);}());
        // Phrolova.py:34
        ([&]()->V{auto fn_51=attr(self_value(),"continues_right_click");Args args_50;args_50.pos(V(0.1));return invoke(fn_51,args_50);}());
    }
    // Phrolova.py:35
    if(([&]()->V{auto fn_53=attr(self_value(),"flying");Args args_52;return invoke(fn_53,args_52);}()).truth()){
        // Phrolova.py:36
        ([&]()->V{auto fn_55=attr(self_value(),"wait_down");Args args_54;return invoke(fn_55,args_54);}());
    }
    // Phrolova.py:37
    if(([&]()->V{V operand_56;operand_56=([&]()->V{auto fn_58=attr(self_value(),"liberation_available");Args args_57;return invoke(fn_58,args_57);}());if(!operand_56.truth())return operand_56;return ([&]()->V{auto fn_60=attr(self_value(),"click_liberation");Args args_59;args_59.kw("wait_if_cd_ready",V(0LL));return invoke(fn_60,args_59);}());}()).truth()){
        // Phrolova.py:38
        return ([&]()->V{auto fn_62=attr(self_value(),"switch_next_char");Args args_61;return invoke(fn_62,args_61);}());
    }
    // Phrolova.py:39
    if(([&]()->V{auto fn_64=attr(self_value(),"heavy_and_liber");Args args_63;return invoke(fn_64,args_63);}()).truth()){
        // Phrolova.py:40
        return ([&]()->V{auto fn_66=attr(self_value(),"switch_next_char");Args args_65;return invoke(fn_66,args_65);}());
    }
    // Phrolova.py:41
    if(([&]()->V{V operand_67;operand_67=([&]()->V{auto fn_69=attr(self_value(),"resonance_available");Args args_68;return invoke(fn_69,args_68);}());if(operand_67.truth())return operand_67;return attr(self_value(),"res_ready");}()).truth()){
        // Phrolova.py:42
        ([&]()->V{auto fn_71=attr(self_value(),"continues_normal_attack");Args args_70;args_70.pos(V(0.1));return invoke(fn_71,args_70);}());
        // Phrolova.py:43
        ([&]()->V{auto fn_73=attr(self_value(),"click_resonance");Args args_72;return invoke(fn_73,args_72);}());
        // Phrolova.py:44
        ([&]()->V{auto fn_75=attr(self_value(),"continues_normal_attack");Args args_74;args_74.pos(V(0.1));return invoke(fn_75,args_74);}());
        // Phrolova.py:45
        ([&]()->V{auto fn_77=attr(attr(self_value(),"task"),"wait_until");Args args_76;args_76.pos(V::function([this,captured=capture_scope(scope_37,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_78=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_80=attr(self_value(),"resonance_available");Args args_79;return invoke(fn_80,args_79);}()));
}));args_76.kw("post_action",attr(attr(self_value(),"task"),"click"));args_76.kw("time_out",V(0.3));return invoke(fn_77,args_76);}());
        // Phrolova.py:46
        if(unary("not",([&]()->V{auto fn_82=attr(self_value(),"click_echo");Args args_81;return invoke(fn_82,args_81);}())).truth()){
            // Phrolova.py:47
            ([&]()->V{auto fn_84=attr(self_value(),"continues_right_click");Args args_83;args_83.pos(V(0.1));return invoke(fn_84,args_83);}());
        }
    }
    // Phrolova.py:48
    {V value_85=V(false);set_attr(self_value(),"res_ready",value_85);}
    // Phrolova.py:49
    {V value_86=([&]()->V{auto fn_88=attr(global("time","Phrolova"),"time");Args args_87;return invoke(fn_88,args_87);}());scope_37->set("start",value_86);}
    // Phrolova.py:50
    {V value_89=V::function([this,captured=capture_scope(scope_37,{"start"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_90=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_91=([&]()->V{V left_93=([&]()->V{auto fn_96=attr(global("time","Phrolova"),"time");Args args_95;return invoke(fn_96,args_95);}());V right_94=scope_90->get("start");return official::binary("-",left_93,right_94);}());V compare_92;V comparison_result_97;compare_92=V(4LL);comparison_result_97=compare_value("<",compare_91,compare_92);return comparison_result_97;}());
});scope_37->set("timeout",value_89);}
    // Phrolova.py:51
    if(scope_37->get("perform_under_outro").truth()){
        // Phrolova.py:52
        {V value_98=V::function([this,captured=capture_scope(scope_37,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_99=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_100=([&]()->V{auto fn_103=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_102;args_102.pos(attr(self_value(),"last_perform"));return invoke(fn_103,args_102);}());V compare_101;V comparison_result_104;compare_101=V(16LL);comparison_result_104=compare_value("<",compare_100,compare_101);return comparison_result_104;}());
});scope_37->set("timeout",value_98);}
        // Phrolova.py:53
        {V value_105=V(true);set_attr(self_value(),"sp",value_105);}
    }
    // Phrolova.py:54
        while(([&]()->V{auto fn_154=scope_37->get("timeout");Args args_153;return invoke(fn_154,args_153);}()).truth()){
        // Phrolova.py:55
        if(([&]()->V{V operand_106;operand_106=([&]()->V{auto fn_108=attr(self_value(),"liberation_available");Args args_107;return invoke(fn_108,args_107);}());if(!operand_106.truth())return operand_106;return ([&]()->V{auto fn_110=attr(self_value(),"click_liberation");Args args_109;args_109.kw("wait_if_cd_ready",V(0LL));return invoke(fn_110,args_109);}());}()).truth()){
            // Phrolova.py:56
            return ([&]()->V{auto fn_112=attr(self_value(),"switch_next_char");Args args_111;return invoke(fn_112,args_111);}());
        }
        // Phrolova.py:57
        if(([&]()->V{auto fn_114=attr(self_value(),"flying");Args args_113;return invoke(fn_114,args_113);}()).truth()){
            // Phrolova.py:58
            ([&]()->V{auto fn_116=attr(self_value(),"shorekeeper_auto_dodge");Args args_115;return invoke(fn_116,args_115);}());
        }
        // Phrolova.py:59
        if(([&]()->V{auto fn_118=attr(self_value(),"heavy_and_liber");Args args_117;return invoke(fn_118,args_117);}()).truth()){
            // Phrolova.py:60
            return ([&]()->V{auto fn_120=attr(self_value(),"switch_next_char");Args args_119;return invoke(fn_120,args_119);}());
        }
        // Phrolova.py:61
        if(([&]()->V{V operand_121;operand_121=([&]()->V{auto fn_123=attr(self_value(),"resonance_available");Args args_122;return invoke(fn_123,args_122);}());if(!operand_121.truth())return operand_121;return ([&]()->V{V compare_124=V(1LL);V compare_125;V comparison_result_126;compare_125=([&]()->V{V left_127=([&]()->V{auto fn_130=attr(global("time","Phrolova"),"time");Args args_129;return invoke(fn_130,args_129);}());V right_128=scope_37->get("start");return official::binary("-",left_127,right_128);}());comparison_result_126=compare_value("<",compare_124,compare_125);return comparison_result_126;}());}()).truth()){
            // Phrolova.py:62
            if(scope_37->get("perform_under_outro").truth()){
                // Phrolova.py:63
                ([&]()->V{auto fn_132=attr(self_value(),"continues_normal_attack");Args args_131;args_131.pos(V(0.3));return invoke(fn_132,args_131);}());
                // Phrolova.py:64
                if(item(([&]()->V{auto fn_134=attr(self_value(),"click_resonance");Args args_133;return invoke(fn_134,args_133);}()),V(0LL)).truth()){
                    // Phrolova.py:65
                    ([&]()->V{auto fn_136=attr(self_value(),"continues_normal_attack");Args args_135;args_135.pos(V(0.1));return invoke(fn_136,args_135);}());
                    // Phrolova.py:66
                    ([&]()->V{auto fn_138=attr(attr(self_value(),"task"),"wait_until");Args args_137;args_137.pos(V::function([this,captured=capture_scope(scope_37,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_139=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_141=attr(self_value(),"resonance_available");Args args_140;return invoke(fn_141,args_140);}()));
}));args_137.kw("post_action",attr(attr(self_value(),"task"),"click"));args_137.kw("time_out",V(0.3));return invoke(fn_138,args_137);}());
                    // Phrolova.py:68
                    if(unary("not",([&]()->V{auto fn_143=attr(self_value(),"click_echo");Args args_142;return invoke(fn_143,args_142);}())).truth()){
                        // Phrolova.py:69
                        ([&]()->V{auto fn_145=attr(self_value(),"continues_right_click");Args args_144;args_144.pos(V(0.1));return invoke(fn_145,args_144);}());
                    }
                }
            }else{
                // Phrolova.py:71
                {V value_146=V(true);set_attr(self_value(),"res_ready",value_146);}
                // Phrolova.py:72
                break;
            }
        }
        // Phrolova.py:73
        ([&]()->V{auto fn_148=attr(attr(self_value(),"task"),"click");Args args_147;return invoke(fn_148,args_147);}());
        // Phrolova.py:74
        ([&]()->V{auto fn_150=attr(self_value(),"check_combat");Args args_149;return invoke(fn_150,args_149);}());
        // Phrolova.py:75
        ([&]()->V{auto fn_152=attr(attr(self_value(),"task"),"next_frame");Args args_151;return invoke(fn_152,args_151);}());
    }
    // Phrolova.py:76
    ([&]()->V{auto fn_156=attr(self_value(),"switch_next_char");Args args_155;return invoke(fn_156,args_155);}());
return V{};
}),false);
// Official method Phrolova._cantarella_outro_ready, lines 78-80
register_method("_cantarella_outro_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"has_intro",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_157=bind_arguments(official_args,signature,captured);
    // Phrolova.py:79
    return ([&]()->V{V operand_158;operand_158=([&]()->V{V compare_159=([&]()->V{auto fn_162=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_161;args_161.pos(attr(self_value(),"last_liberation"));return invoke(fn_162,args_161);}());V compare_160;V comparison_result_163;compare_160=V(14LL);comparison_result_163=compare_value(">",compare_159,compare_160);return comparison_result_163;}());if(!operand_158.truth())return operand_158;operand_158=scope_157->get("has_intro");if(!operand_158.truth())return operand_158;operand_158=scope_157->get("current_char");if(!operand_158.truth())return operand_158;return ([&]()->V{V compare_164=attr(scope_157->get("current_char"),"char_name");V compare_165;V comparison_result_166;compare_165=V::set({V("char_cantarella")});comparison_result_166=compare_value("in",compare_164,compare_165);return comparison_result_166;}());}());
return V{};
}),false);
// Official method Phrolova.get_switch_priority, lines 82-88
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_167=bind_arguments(official_args,signature,captured);
    // Phrolova.py:83
    ([&]()->V{auto fn_169=attr(attr(self_value(),"logger"),"debug");Args args_168;args_168.pos(V(std::string{}+"Phrolova last_liberation "+format_value(([&]()->V{auto fn_171=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_170;args_170.pos(attr(self_value(),"last_liberation"));return invoke(fn_171,args_170);}()),"",-1)));return invoke(fn_169,args_168);}());
    // Phrolova.py:84
    if(([&]()->V{auto fn_173=attr(self_value(),"_cantarella_outro_ready");Args args_172;args_172.pos(scope_167->get("current_char"));args_172.pos(scope_167->get("has_intro"));return invoke(fn_173,args_172);}()).truth()){
        // Phrolova.py:85
        return attr(global("SwitchPriority","Phrolova"),"MUST");
    }
    // Phrolova.py:86
    if(([&]()->V{V compare_174=([&]()->V{auto fn_177=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_176;args_176.pos(attr(self_value(),"last_liberation"));return invoke(fn_177,args_176);}());V compare_175;V comparison_result_178;compare_175=V(24LL);comparison_result_178=compare_value("<",compare_174,compare_175);return comparison_result_178;}()).truth()){
        // Phrolova.py:87
        return attr(global("SwitchPriority","Phrolova"),"NO");
    }
    // Phrolova.py:88
    return ([&]()->V{auto fn_182=attr(([&]()->V{auto fn_180=global("super","Phrolova");Args args_179;return invoke(fn_180,args_179);}()),"get_switch_priority");Args args_181;args_181.pos(scope_167->get("current_char"));args_181.pos(scope_167->get("has_intro"));args_181.pos(scope_167->get("target_low_con"));return invoke(fn_182,args_181);}());
return V{};
}),false);
// Official method Phrolova.resonance_available, lines 90-93
register_method("resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_183=bind_arguments(official_args,signature,captured);
    // Phrolova.py:91
    if(attr(self_value(),"sp").truth()){
        // Phrolova.py:92
        return unary("not",([&]()->V{V operand_184;operand_184=([&]()->V{auto fn_186=attr(self_value(),"flying");Args args_185;return invoke(fn_186,args_185);}());if(operand_184.truth())return operand_184;return ([&]()->V{auto fn_188=attr(self_value(),"has_cd");Args args_187;args_187.pos(V("resonance"));return invoke(fn_188,args_187);}());}()));
    }
    // Phrolova.py:93
    return ([&]()->V{auto fn_192=attr(([&]()->V{auto fn_190=global("super","Phrolova");Args args_189;return invoke(fn_190,args_189);}()),"resonance_available");Args args_191;return invoke(fn_192,args_191);}());
return V{};
}),false);
// Official method Phrolova.heavy_and_liber, lines 95-99
register_method("heavy_and_liber",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_193=bind_arguments(official_args,signature,captured);
    // Phrolova.py:96
    if(([&]()->V{auto fn_195=attr(self_value(),"heavy_click_forte");Args args_194;args_194.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_195,args_194);}()).truth()){
        // Phrolova.py:97
        ([&]()->V{auto fn_197=attr(attr(self_value(),"logger"),"debug");Args args_196;args_196.pos(V("Phrolova heavy_click_forte"));return invoke(fn_197,args_196);}());
        // Phrolova.py:98
        ([&]()->V{auto fn_199=attr(attr(self_value(),"task"),"wait_until");Args args_198;args_198.pos(V::function([this,captured=capture_scope(scope_193,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_200=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_202=attr(self_value(),"click_liberation");Args args_201;args_201.kw("wait_if_cd_ready",V(0LL));return invoke(fn_202,args_201);}());
}));args_198.kw("time_out",V(3LL));return invoke(fn_199,args_198);}());
        // Phrolova.py:99
        return V(true);
    }
return V{};
}),false);
// Official method Phrolova.shorekeeper_auto_dodge, lines 101-105
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_203=bind_arguments(official_args,signature,captured);
scope_203->set("ShoreKeeper",V::missing());
scope_203->set("char",V::missing());
scope_203->set("i",V::missing());
    // Phrolova.py:102
    scope_203->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Phrolova.py:103
    {auto iterator_204=official::iterate(([&]()->V{auto fn_211=global("enumerate","Phrolova");Args args_210;args_210.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_211,args_210);}()));V item_205;while(iterator_204.next(item_205)){
        auto unpack_212=unpack(item_205,2);scope_203->set("i",unpack_212[0]);scope_203->set("char",unpack_212[1]);
        // Phrolova.py:104
        if(([&]()->V{auto fn_207=global("isinstance","Phrolova");Args args_206;args_206.pos(scope_203->get("char"));args_206.pos(scope_203->get("ShoreKeeper"));return invoke(fn_207,args_206);}()).truth()){
            // Phrolova.py:105
            return ([&]()->V{auto fn_209=attr(scope_203->get("char"),"auto_dodge");Args args_208;args_208.kw("condition",attr(self_value(),"flying"));return invoke(fn_209,args_208);}());
        }
    }
    }
return V{};
}),false);
}
