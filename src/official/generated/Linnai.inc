// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Linnai.py
// SHA256 cde970f8ff513604d2cdb630da97b351f628e4b2395520323576f5f61b0f3a5d
void OfficialCharacter::install_Linnai(){
auto scope=std::make_shared<Scope>();
set_class_attribute("RES_CHECK_THRESHOLD",V(0.6));
set_class_attribute("INTRO_RES_WAIT",V(1.0));
set_class_attribute("AEMEATH_INTRO_RES_WAIT",V(1.6));
// Official method Linnai.__init__, lines 8-10
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Linnai.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Linnai");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Linnai.py:10
    {V value_6=V(0LL);set_attr(self_value(),"last_heavy",value_6);}
return V{};
}),false);
// Official method Linnai.do_perform, lines 12-19
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Linnai.py:13
    if(([&]()->V{V operand_8;operand_8=attr(self_value(),"has_intro");if(!operand_8.truth())return operand_8;return ([&]()->V{auto fn_10=attr(self_value(),"check_res");Args args_9;return invoke(fn_10,args_9);}());}()).truth()){
        // Linnai.py:14
        ([&]()->V{auto fn_12=attr(self_value(),"continues_normal_attack");Args args_11;args_11.pos(V(1.33));return invoke(fn_12,args_11);}());
    }else{
        // Linnai.py:16
        ([&]()->V{auto fn_14=attr(self_value(),"charge_heavy");Args args_13;return invoke(fn_14,args_13);}());
    }
    // Linnai.py:17
    if(([&]()->V{auto fn_16=attr(self_value(),"liberation_available");Args args_15;return invoke(fn_16,args_15);}()).truth()){
        // Linnai.py:18
        ([&]()->V{auto fn_18=attr(self_value(),"click_liberation");Args args_17;return invoke(fn_18,args_17);}());
    }
    // Linnai.py:19
    return ([&]()->V{auto fn_20=attr(self_value(),"switch_next_char");Args args_19;return invoke(fn_20,args_19);}());
return V{};
}),false);
// Official method Linnai.charge_heavy, lines 21-39
register_method("charge_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
    // Linnai.py:26
    ([&]()->V{auto fn_23=attr(self_value(),"continues_normal_attack");Args args_22;args_22.pos(V(1LL));return invoke(fn_23,args_22);}());
    // Linnai.py:27
    ([&]()->V{auto fn_25=attr(self_value(),"click_echo");Args args_24;args_24.kw("time_out",V(0LL));return invoke(fn_25,args_24);}());
    // Linnai.py:28
    if(unary("not",([&]()->V{auto fn_27=attr(self_value(),"is_con_full");Args args_26;return invoke(fn_27,args_26);}())).truth()){
        // Linnai.py:29
        ([&]()->V{auto fn_29=attr(self_value(),"click_liberation");Args args_28;return invoke(fn_29,args_28);}());
    }
    // Linnai.py:30
    if(unary("not",([&]()->V{auto fn_31=attr(self_value(),"is_mouse_forte_full");Args args_30;return invoke(fn_31,args_30);}())).truth()){
        // Linnai.py:31
        ([&]()->V{auto fn_33=attr(self_value(),"click_resonance");Args args_32;return invoke(fn_33,args_32);}());
    }
    // Linnai.py:32
    ([&]()->V{auto fn_35=attr(attr(self_value(),"task"),"wait_until");Args args_34;args_34.pos(attr(self_value(),"is_mouse_forte_full"));args_34.kw("post_action",attr(self_value(),"click"));args_34.kw("time_out",V(2LL));return invoke(fn_35,args_34);}());
    // Linnai.py:33
    ([&]()->V{auto fn_37=attr(attr(self_value(),"task"),"mouse_down");Args args_36;return invoke(fn_37,args_36);}());
    // Linnai.py:34
    if(([&]()->V{auto fn_39=attr(attr(self_value(),"task"),"wait_until");Args args_38;args_38.pos(V::function([this,captured=capture_scope(scope_21,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_40=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_42=attr(self_value(),"is_mouse_forte_full");Args args_41;return invoke(fn_42,args_41);}()));
}));args_38.kw("time_out",V(5LL));return invoke(fn_39,args_38);}()).truth()){
        // Linnai.py:35
        ([&]()->V{auto fn_44=attr(attr(self_value(),"task"),"mouse_up");Args args_43;return invoke(fn_44,args_43);}());
        // Linnai.py:36
        ([&]()->V{auto fn_46=attr(self_value(),"sleep");Args args_45;args_45.pos(V(0.4));return invoke(fn_46,args_45);}());
        // Linnai.py:37
        ([&]()->V{auto fn_48=attr(self_value(),"perform_under_intro");Args args_47;return invoke(fn_48,args_47);}());
    }else{
        // Linnai.py:39
        ([&]()->V{auto fn_50=attr(attr(self_value(),"task"),"mouse_up");Args args_49;return invoke(fn_50,args_49);}());
    }
return V{};
}),false);
// Official method Linnai.perform_under_intro, lines 41-67
register_method("perform_under_intro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_51=bind_arguments(official_args,signature,captured);
scope_51->set("click_second_resonance",V::missing());
scope_51->set("second_kick",V::missing());
    // Linnai.py:42
    if(unary("not",([&]()->V{auto fn_53=attr(self_value(),"wait_for_accelerate_ready");Args args_52;return invoke(fn_53,args_52);}())).truth()){
        // Linnai.py:43
        ([&]()->V{auto fn_55=attr(attr(self_value(),"logger"),"debug");Args args_54;args_54.pos(V(std::string{}+"Linnai fails entering accelerate mode!"));return invoke(fn_55,args_54);}());
        // Linnai.py:44
        return V(false);
    }
    // Linnai.py:45
    ([&]()->V{auto fn_57=attr(attr(self_value(),"task"),"wait_until");Args args_56;args_56.pos(V::function([this,captured=capture_scope(scope_51,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_58=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_59;operand_59=([&]()->V{auto fn_61=attr(self_value(),"is_color_full");Args args_60;return invoke(fn_61,args_60);}());if(operand_59.truth())return operand_59;return ([&]()->V{auto fn_63=attr(self_value(),"is_con_full");Args args_62;return invoke(fn_63,args_62);}());}());
}));args_56.kw("post_action",attr(self_value(),"click"));args_56.kw("time_out",V(1LL));return invoke(fn_57,args_56);}());
    // Linnai.py:47
    if(([&]()->V{auto fn_65=attr(attr(self_value(),"task"),"wait_until");Args args_64;args_64.pos(V::function([this,captured=capture_scope(scope_51,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_66=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_68=attr(self_value(),"is_forte_full");Args args_67;return invoke(fn_68,args_67);}()));
}));args_64.kw("post_action",attr(attr(self_value(),"task"),"jump"));args_64.kw("time_out",V(3LL));return invoke(fn_65,args_64);}()).truth()){
        // Linnai.py:50
        if(([&]()->V{auto fn_70=attr(attr(self_value(),"task"),"wait_until");Args args_69;args_69.pos(V::function([this,captured=capture_scope(scope_51,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_71=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_73=attr(self_value(),"click_resonance");Args args_72;return invoke(fn_73,args_72);}()),V(0LL));
}));args_69.kw("post_action",attr(self_value(),"click"));args_69.kw("time_out",V(2LL));return invoke(fn_70,args_69);}()).truth()){
            // Linnai.py:52
            ([&]()->V{auto fn_75=attr(self_value(),"wait_after_resonance_kick");Args args_74;return invoke(fn_75,args_74);}());
            // Linnai.py:53
            {V value_76=V(false);scope_51->set("second_kick",value_76);}
            // Linnai.py:55
            scope_51->set("click_second_resonance",V::function([this,captured=capture_scope(scope_51,{"second_kick"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_77=bind_arguments(official_args,signature,captured);
    // Linnai.py:57
    if(([&]()->V{auto fn_79=attr(self_value(),"is_con_full");Args args_78;return invoke(fn_79,args_78);}()).truth()){
        // Linnai.py:58
        return V(true);
    }
    // Linnai.py:59
    {V value_80=item(([&]()->V{auto fn_82=attr(self_value(),"click_resonance");Args args_81;return invoke(fn_82,args_81);}()),V(0LL));scope_77->set_nonlocal("second_kick",value_80);}
    // Linnai.py:60
    return scope_77->get("second_kick");
return V{};
}));
            // Linnai.py:62
            ([&]()->V{auto fn_84=attr(attr(self_value(),"task"),"wait_until");Args args_83;args_83.pos(scope_51->get("click_second_resonance"));args_83.kw("post_action",attr(self_value(),"click"));args_83.kw("time_out",V(3LL));return invoke(fn_84,args_83);}());
            // Linnai.py:63
            if(scope_51->get("second_kick").truth()){
                // Linnai.py:64
                ([&]()->V{auto fn_86=attr(self_value(),"wait_after_resonance_kick");Args args_85;return invoke(fn_86,args_85);}());
            }
        }
    }
    // Linnai.py:65
    if(([&]()->V{V operand_87;operand_87=unary("not",([&]()->V{auto fn_89=attr(self_value(),"is_con_full");Args args_88;return invoke(fn_89,args_88);}()));if(!operand_87.truth())return operand_87;return ([&]()->V{auto fn_91=attr(self_value(),"click_liberation");Args args_90;return invoke(fn_91,args_90);}());}()).truth()){
        // Linnai.py:66
        ([&]()->V{auto fn_93=attr(attr(self_value(),"task"),"wait_until");Args args_92;args_92.pos(attr(self_value(),"is_con_full"));args_92.kw("post_action",attr(self_value(),"click_with_interval"));args_92.kw("time_out",V(1.2));return invoke(fn_93,args_92);}());
    }
    // Linnai.py:67
    return V(true);
return V{};
}),false);
// Official method Linnai.wait_after_resonance_kick, lines 69-71
register_method("wait_after_resonance_kick",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_94=bind_arguments(official_args,signature,captured);
    // Linnai.py:70
    ([&]()->V{auto fn_96=attr(self_value(),"sleep");Args args_95;args_95.pos(V(0.3));return invoke(fn_96,args_95);}());
    // Linnai.py:71
    ([&]()->V{auto fn_98=attr(self_value(),"wait_down");Args args_97;return invoke(fn_98,args_97);}());
return V{};
}),false);
// Official method Linnai.wait_for_accelerate_ready, lines 73-80
register_method("wait_for_accelerate_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_99=bind_arguments(official_args,signature,captured);
scope_99->set("time_out",V::missing());
    // Linnai.py:75
    if(([&]()->V{auto fn_101=attr(self_value(),"check_res");Args args_100;return invoke(fn_101,args_100);}()).truth()){
        // Linnai.py:76
        return V(true);
    }
    // Linnai.py:77
    {V value_102=attr(self_value(),"INTRO_RES_WAIT");scope_99->set("time_out",value_102);}
    // Linnai.py:78
    if(([&]()->V{V operand_103;operand_103=attr(self_value(),"has_intro");if(!operand_103.truth())return operand_103;return ([&]()->V{V compare_104=([&]()->V{auto fn_107=attr(self_value(),"check_outro");Args args_106;return invoke(fn_107,args_106);}());V compare_105;V comparison_result_108;compare_105=V::set({V("char_aemeath")});comparison_result_108=compare_value("in",compare_104,compare_105);return comparison_result_108;}());}()).truth()){
        // Linnai.py:79
        {V value_109=attr(self_value(),"AEMEATH_INTRO_RES_WAIT");scope_99->set("time_out",value_109);}
    }
    // Linnai.py:80
    return ([&]()->V{auto fn_111=attr(attr(self_value(),"task"),"wait_until");Args args_110;args_110.pos(attr(self_value(),"check_res"));args_110.kw("post_action",attr(self_value(),"click_with_interval"));args_110.kw("time_out",scope_99->get("time_out"));return invoke(fn_111,args_110);}());
return V{};
}),false);
// Official method Linnai.get_target_names, lines 82-85
register_method("get_target_names",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_112=bind_arguments(official_args,signature,captured);
    // Linnai.py:83
    if(([&]()->V{auto fn_114=global("hasattr","Linnai");Args args_113;args_113.pos(attr(self_value(),"task"));args_113.pos(V("get_target_names"));return invoke(fn_114,args_113);}()).truth()){
        // Linnai.py:84
        return ([&]()->V{auto fn_116=attr(attr(self_value(),"task"),"get_target_names");Args args_115;return invoke(fn_116,args_115);}());
    }
    // Linnai.py:85
    return V::tuple({V("has_target"),V("no_target")});
return V{};
}),false);
// Official method Linnai.find_target_status_in_box, lines 87-94
register_method("find_target_status_in_box",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"box_name",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_117=bind_arguments(official_args,signature,captured);
scope_117->set("box",V::missing());
scope_117->set("e",V::missing());
    // Linnai.py:88
    {
    try{
        // Linnai.py:89
        {V value_118=([&]()->V{auto fn_120=attr(attr(self_value(),"task"),"get_box_by_name");Args args_119;args_119.pos(scope_117->get("box_name"));return invoke(fn_120,args_119);}());scope_117->set("box",value_118);}
        // Linnai.py:90
        return ([&]()->V{auto fn_122=attr(attr(self_value(),"task"),"find_best_match_in_box");Args args_121;args_121.pos(scope_117->get("box"));args_121.pos(([&]()->V{auto fn_124=global("list","Linnai");Args args_123;args_123.pos(([&]()->V{auto fn_126=attr(self_value(),"get_target_names");Args args_125;return invoke(fn_126,args_125);}()));return invoke(fn_124,args_123);}()));args_121.kw("threshold",attr(self_value(),"RES_CHECK_THRESHOLD"));return invoke(fn_122,args_121);}());
    }catch(const std::exception& official_exception){
        rethrow_control_exception(official_exception);
        scope_117->set("e",V(official_exception.what()));
        // Linnai.py:93
        ([&]()->V{auto fn_128=attr(attr(self_value(),"logger"),"debug");Args args_127;args_127.pos(V(std::string{}+"Linnai check res skipped "+format_value(scope_117->get("box_name"),"",-1)+": "+format_value(scope_117->get("e"),"",-1)));return invoke(fn_128,args_127);}());
        // Linnai.py:94
        return V{};
    }
    }
return V{};
}),false);
// Official method Linnai.check_res, lines 96-110
register_method("check_res",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_129=bind_arguments(official_args,signature,captured);
scope_129->set("best",V::missing());
scope_129->set("e",V::missing());
    // Linnai.py:97
    if(unary("not",([&]()->V{auto fn_131=attr(attr(self_value(),"task"),"in_team_and_world");Args args_130;return invoke(fn_131,args_130);}())).truth()){
        // Linnai.py:98
        return V(false);
    }
    // Linnai.py:100
    {V value_132=([&]()->V{auto fn_134=attr(self_value(),"find_target_status_in_box");Args args_133;args_133.pos(V("target_box_long2"));return invoke(fn_134,args_133);}());scope_129->set("best",value_132);}
    // Linnai.py:101
    if(unary("not",scope_129->get("best")).truth()){
        // Linnai.py:102
        {V value_135=([&]()->V{auto fn_137=attr(self_value(),"find_target_status_in_box");Args args_136;args_136.pos(V("box_target_enemy_long"));return invoke(fn_137,args_136);}());scope_129->set("best",value_135);}
    }
    // Linnai.py:103
    if(unary("not",scope_129->get("best")).truth()){
        // Linnai.py:104
        {
        try{
            // Linnai.py:105
            {V value_138=([&]()->V{auto fn_140=attr(attr(self_value(),"task"),"find_one");Args args_139;args_139.pos(V("target_box_short"));args_139.kw("threshold",attr(self_value(),"RES_CHECK_THRESHOLD"));return invoke(fn_140,args_139);}());scope_129->set("best",value_138);}
        }catch(const std::exception& official_exception){
            rethrow_control_exception(official_exception);
            scope_129->set("e",V(official_exception.what()));
            // Linnai.py:107
            ([&]()->V{auto fn_142=attr(attr(self_value(),"logger"),"debug");Args args_141;args_141.pos(V(std::string{}+"Linnai check res skipped target_box_short: "+format_value(scope_129->get("e"),"",-1)));return invoke(fn_142,args_141);}());
            // Linnai.py:108
            {V value_143=V{};scope_129->set("best",value_143);}
        }
        }
    }
    // Linnai.py:109
    ([&]()->V{auto fn_145=attr(attr(self_value(),"logger"),"debug");Args args_144;args_144.pos(V(std::string{}+"check res "+format_value(scope_129->get("best"),"",-1)));return invoke(fn_145,args_144);}());
    // Linnai.py:110
    return scope_129->get("best");
return V{};
}),false);
// Official method Linnai.is_color_full, lines 112-116
register_method("is_color_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_146=bind_arguments(official_args,signature,captured);
scope_146->set("box",V::missing());
scope_146->set("white_percent",V::missing());
    // Linnai.py:113
    {V value_147=([&]()->V{auto fn_149=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_148;args_148.pos(V(5120LL));args_148.pos(V(2880LL));args_148.pos(V(2846LL));args_148.pos(V(2602LL));args_148.pos(V(2889LL));args_148.pos(V(2690LL));args_148.kw("name",V("color_full"));args_148.kw("hcenter",V(true));return invoke(fn_149,args_148);}());scope_146->set("box",value_147);}
    // Linnai.py:114
    {V value_150=([&]()->V{auto fn_152=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_151;args_151.pos(global("forte_white_color","Linnai"));args_151.pos(scope_146->get("box"));return invoke(fn_152,args_151);}());scope_146->set("white_percent",value_150);}
    // Linnai.py:115
    ([&]()->V{auto fn_154=attr(attr(self_value(),"logger"),"debug");Args args_153;args_153.pos(V(std::string{}+"forte_color_percent "+format_value(scope_146->get("white_percent"),"",-1)));return invoke(fn_154,args_153);}());
    // Linnai.py:116
    return ([&]()->V{V compare_155=scope_146->get("white_percent");V compare_156;V comparison_result_157;compare_156=V(0.06);comparison_result_157=compare_value(">",compare_155,compare_156);return comparison_result_157;}());
return V{};
}),false);
// Official method Linnai.on_combat_end, lines 118-119
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_158=bind_arguments(official_args,signature,captured);
    // Linnai.py:119
    ([&]()->V{auto fn_160=attr(self_value(),"switch_other_char");Args args_159;return invoke(fn_160,args_159);}());
return V{};
}),false);
// Official method Linnai.get_switch_priority, lines 121-125
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_161=bind_arguments(official_args,signature,captured);
    // Linnai.py:123
    if(([&]()->V{V operand_162;operand_162=scope_161->get("current_char");if(!operand_162.truth())return operand_162;return ([&]()->V{V compare_163=attr(scope_161->get("current_char"),"char_name");V compare_164;V comparison_result_165;compare_164=V("char_moning");comparison_result_165=compare_value("==",compare_163,compare_164);return comparison_result_165;}());}()).truth()){
        // Linnai.py:124
        return attr(global("SwitchPriority","Linnai"),"MUST");
    }
    // Linnai.py:125
    return ([&]()->V{auto fn_169=attr(([&]()->V{auto fn_167=global("super","Linnai");Args args_166;return invoke(fn_167,args_166);}()),"get_switch_priority");Args args_168;args_168.pos(scope_161->get("current_char"));args_168.pos(scope_161->get("has_intro"));args_168.pos(scope_161->get("target_low_con"));return invoke(fn_169,args_168);}());
return V{};
}),false);
}
