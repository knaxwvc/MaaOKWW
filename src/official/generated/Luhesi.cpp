#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Luhesi.py
// SHA256 de2bc754ffe5619d3084060ba7843d7d96675f8821a434254a2674cc2b559fc3
void OfficialCharacter::install_Luhesi(){
auto scope=std::make_shared<Scope>();
// Official method Luhesi.__init__, lines 8-10
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Luhesi.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Luhesi");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Luhesi.py:10
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"last_intro",value_6);}
return V{};
}),false);
// Official method Luhesi.do_perform, lines 12-14
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Luhesi.py:13
    ([&]()->V{auto fn_9=attr(self_value(),"perform_everything");Args args_8;return invoke(fn_9,args_8);}());
    // Luhesi.py:14
    ([&]()->V{auto fn_11=attr(self_value(),"switch_next_char");Args args_10;return invoke(fn_11,args_10);}());
return V{};
}),false);
// Official method Luhesi.lib, lines 16-19
register_method("lib",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
    // Luhesi.py:17
    if(([&]()->V{V operand_13;operand_13=([&]()->V{auto fn_15=attr(self_value(),"luhesi_lib_available");Args args_14;return invoke(fn_15,args_14);}());if(!operand_13.truth())return operand_13;return ([&]()->V{auto fn_17=attr(self_value(),"click_liberation");Args args_16;args_16.kw("wait_if_cd_ready",V(0LL));return invoke(fn_17,args_16);}());}()).truth()){
        // Luhesi.py:18
        ([&]()->V{auto fn_19=attr(self_value(),"f_break");Args args_18;return invoke(fn_19,args_18);}());
        // Luhesi.py:19
        return V(true);
    }
return V{};
}),false);
// Official method Luhesi.luhesi_lib_available, lines 21-22
register_method("luhesi_lib_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_20=bind_arguments(official_args,signature,captured);
    // Luhesi.py:22
    return ([&]()->V{V operand_21;operand_21=([&]()->V{auto fn_23=attr(self_value(),"available");Args args_22;args_22.pos(V("luhesi_lib"));args_22.kw("check_cd",V(false));return invoke(fn_23,args_22);}());if(!operand_21.truth())return operand_21;return unary("not",([&]()->V{auto fn_25=attr(self_value(),"has_cd");Args args_24;args_24.pos(V("liberation"));return invoke(fn_25,args_24);}()));}());
return V{};
}),false);
// Official method Luhesi.get_switch_priority, lines 24-27
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_26=bind_arguments(official_args,signature,captured);
    // Luhesi.py:25
    if(([&]()->V{V operand_27;operand_27=([&]()->V{V compare_28=([&]()->V{V left_30=([&]()->V{auto fn_33=attr(global("time","Luhesi"),"time");Args args_32;return invoke(fn_33,args_32);}());V right_31=attr(self_value(),"last_intro");return official::binary("-",left_30,right_31);}());V compare_29;V comparison_result_34;compare_29=V(24LL);comparison_result_34=compare_value(">",compare_28,compare_29);return comparison_result_34;}());if(!operand_27.truth())return operand_27;return scope_26->get("has_intro");}()).truth()){
        // Luhesi.py:26
        return attr(global("SwitchPriority","Luhesi"),"MUST");
    }
    // Luhesi.py:27
    return ([&]()->V{auto fn_38=attr(([&]()->V{auto fn_36=global("super","Luhesi");Args args_35;return invoke(fn_36,args_35);}()),"get_switch_priority");Args args_37;args_37.pos(scope_26->get("current_char"));args_37.pos(scope_26->get("has_intro"));args_37.pos(scope_26->get("target_low_con"));return invoke(fn_38,args_37);}());
return V{};
}),false);
// Official method Luhesi.perform_everything, lines 29-70
register_method("perform_everything",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_39=bind_arguments(official_args,signature,captured);
scope_39->set("detect_ready",V::missing());
scope_39->set("res_count",V::missing());
scope_39->set("start",V::missing());
scope_39->set("try_jump",V::missing());
    // Luhesi.py:30
    ([&]()->V{auto fn_41=attr(self_value(),"continues_normal_attack");Args args_40;args_40.pos(V(1.1));return invoke(fn_41,args_40);}());
    // Luhesi.py:31
    if(unary("not",attr(self_value(),"has_sub_dps_intro")).truth()){
        // Luhesi.py:32
        ([&]()->V{auto fn_43=attr(self_value(),"send_resonance_key");Args args_42;args_42.kw("post_sleep",V(0.1));return invoke(fn_43,args_42);}());
        // Luhesi.py:33
        return V{};
    }else{
        // Luhesi.py:35
        {V value_44=([&]()->V{auto fn_46=attr(global("time","Luhesi"),"time");Args args_45;return invoke(fn_46,args_45);}());set_attr(self_value(),"last_intro",value_44);}
    }
    // Luhesi.py:36
    if(unary("not",([&]()->V{auto fn_48=attr(self_value(),"flying");Args args_47;return invoke(fn_48,args_47);}())).truth()){
        // Luhesi.py:37
        ([&]()->V{auto fn_50=attr(attr(self_value(),"task"),"wait_until");Args args_49;args_49.pos(attr(self_value(),"flying"));args_49.kw("post_action",attr(attr(self_value(),"task"),"jump"));args_49.kw("time_out",V(0.2));return invoke(fn_50,args_49);}());
    }
    // Luhesi.py:38
    ([&]()->V{auto fn_52=attr(attr(self_value(),"logger"),"debug");Args args_51;args_51.pos(V(std::string{}+"detect "+format_value(([&]()->V{auto fn_54=attr(self_value(),"available");Args args_53;args_53.pos(V("echo"));args_53.kw("check_color",V(true));return invoke(fn_54,args_53);}()),"",-1)));return invoke(fn_52,args_51);}());
    // Luhesi.py:39
    {V value_55=([&]()->V{auto fn_57=attr(self_value(),"echo_available");Args args_56;return invoke(fn_57,args_56);}());scope_39->set("detect_ready",value_55);}
    // Luhesi.py:40
    {V value_58=([&]()->V{auto fn_60=attr(global("time","Luhesi"),"time");Args args_59;return invoke(fn_60,args_59);}());scope_39->set("start",value_58);}
    // Luhesi.py:41
    {V value_61=V(0LL);scope_39->set("res_count",value_61);}
    // Luhesi.py:42
    {V value_62=V(false);scope_39->set("try_jump",value_62);}
    // Luhesi.py:43
        while(([&]()->V{V compare_115=([&]()->V{auto fn_118=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_117;args_117.pos(scope_39->get("start"));return invoke(fn_118,args_117);}());V compare_116;V comparison_result_119;compare_116=V(12LL);comparison_result_119=compare_value("<",compare_115,compare_116);return comparison_result_119;}()).truth()){
        // Luhesi.py:44
        if(([&]()->V{auto fn_64=attr(self_value(),"detect_elbow_strike");Args args_63;args_63.pos(scope_39->get("detect_ready"));return invoke(fn_64,args_63);}()).truth()){
            // Luhesi.py:45
            ([&]()->V{auto fn_66=attr(attr(self_value(),"logger"),"debug");Args args_65;args_65.pos(V("Detected an elbow strike, attempting to reset."));return invoke(fn_66,args_65);}());
            // Luhesi.py:46
            ([&]()->V{auto fn_68=attr(attr(self_value(),"task"),"wait_until");Args args_67;args_67.pos(V::function([this,captured=capture_scope(scope_39,{"detect_ready"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_69=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_71=attr(self_value(),"detect_elbow_strike");Args args_70;args_70.pos(scope_69->get("detect_ready"));return invoke(fn_71,args_70);}()));
}));args_67.kw("post_action",V::function([this,captured=capture_scope(scope_39,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_72=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_74=attr(self_value(),"continues_right_click");Args args_73;args_73.pos(V(0.05));return invoke(fn_74,args_73);}());
}));args_67.kw("time_out",V(1.5));return invoke(fn_68,args_67);}());
        }else{
            // Luhesi.py:48
            if(([&]()->V{V operand_75;operand_75=([&]()->V{auto fn_77=attr(self_value(),"handle_heavy");Args args_76;args_76.pos(scope_39->get("res_count"));return invoke(fn_77,args_76);}());if(!operand_75.truth())return operand_75;return ([&]()->V{V compare_78=scope_39->get("res_count");V compare_79;V comparison_result_80;compare_79=V(2LL);comparison_result_80=compare_value(">",compare_78,compare_79);return comparison_result_80;}());}()).truth()){
                // Luhesi.py:49
                ([&]()->V{auto fn_82=attr(self_value(),"lib");Args args_81;return invoke(fn_82,args_81);}());
                // Luhesi.py:50
                return V{};
            }else{
                // Luhesi.py:51
                if(([&]()->V{V operand_83;operand_83=scope_39->get("try_jump");if(!operand_83.truth())return operand_83;return unary("not",([&]()->V{auto fn_85=attr(self_value(),"check_res");Args args_84;return invoke(fn_85,args_84);}()));}()).truth()){
                    // Luhesi.py:52
                    ([&]()->V{auto fn_87=attr(attr(self_value(),"task"),"wait_until");Args args_86;args_86.pos(V::function([this,captured=capture_scope(scope_39,{"detect_ready"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_88=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_89;operand_89=([&]()->V{auto fn_91=attr(attr(self_value(),"task"),"find_one");Args args_90;args_90.pos(V("luhesi_kick"));args_90.kw("threshold",V(0.7));return invoke(fn_91,args_90);}());if(operand_89.truth())return operand_89;return ([&]()->V{auto fn_93=attr(self_value(),"detect_elbow_strike");Args args_92;args_92.pos(scope_88->get("detect_ready"));return invoke(fn_93,args_92);}());}());
}));args_86.kw("post_action",attr(self_value(),"send_resonance_key"));args_86.kw("time_out",V(1LL));return invoke(fn_87,args_86);}());
                    // Luhesi.py:55
                    if(([&]()->V{auto fn_95=attr(self_value(),"detect_elbow_strike");Args args_94;args_94.pos(scope_39->get("detect_ready"));return invoke(fn_95,args_94);}()).truth()){
                        // Luhesi.py:56
                        continue;
                    }
                    // Luhesi.py:57
                    {V value_96=V(false);scope_39->set("try_jump",value_96);}
                    // Luhesi.py:58
                    if(([&]()->V{auto fn_98=attr(attr(self_value(),"task"),"find_one");Args args_97;args_97.pos(V("luhesi_kick"));args_97.kw("threshold",V(0.7));return invoke(fn_98,args_97);}()).truth()){
                        // Luhesi.py:59
                        scope_39->set("res_count",official::binary("+",scope_39->get("res_count"),V(1LL)));
                    }else{
                        // Luhesi.py:61
                        if(([&]()->V{V compare_99=scope_39->get("res_count");V compare_100;V comparison_result_101;compare_100=V(2LL);comparison_result_101=compare_value("==",compare_99,compare_100);return comparison_result_101;}()).truth()){
                            // Luhesi.py:62
                            ([&]()->V{auto fn_103=attr(self_value(),"wait_down");Args args_102;return invoke(fn_103,args_102);}());
                        }
                        // Luhesi.py:63
                        ([&]()->V{auto fn_105=attr(self_value(),"lib");Args args_104;return invoke(fn_105,args_104);}());
                        // Luhesi.py:64
                        return V{};
                    }
                }else{
                    // Luhesi.py:65
                    if(([&]()->V{auto fn_107=attr(self_value(),"check_res");Args args_106;return invoke(fn_107,args_106);}()).truth()){
                        // Luhesi.py:66
                        ([&]()->V{auto fn_109=attr(attr(self_value(),"task"),"jump");Args args_108;return invoke(fn_109,args_108);}());
                        // Luhesi.py:67
                        {V value_110=V(true);scope_39->set("try_jump",value_110);}
                    }else{
                        // Luhesi.py:69
                        ([&]()->V{auto fn_112=attr(self_value(),"click");Args args_111;return invoke(fn_112,args_111);}());
                    }
                }
            }
        }
        // Luhesi.py:70
        ([&]()->V{auto fn_114=attr(self_value(),"sleep");Args args_113;args_113.pos(V(0.01));return invoke(fn_114,args_113);}());
    }
return V{};
}),false);
// Official method Luhesi.handle_heavy, lines 72-82
register_method("handle_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"res_count",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_120=bind_arguments(official_args,signature,captured);
scope_120->set("have_kick",V::missing());
scope_120->set("start",V::missing());
    // Luhesi.py:73
    {V value_121=([&]()->V{auto fn_123=attr(global("time","Luhesi"),"time");Args args_122;return invoke(fn_123,args_122);}());scope_120->set("start",value_121);}
    // Luhesi.py:74
    {V value_124=V(false);scope_120->set("have_kick",value_124);}
    // Luhesi.py:75
        while(([&]()->V{V operand_135;operand_135=([&]()->V{auto fn_137=attr(attr(self_value(),"task"),"find_one");Args args_136;args_136.pos(V("luhesi_kick"));args_136.kw("threshold",V(0.7));return invoke(fn_137,args_136);}());if(!operand_135.truth())return operand_135;return ([&]()->V{V compare_138=([&]()->V{V left_140=([&]()->V{auto fn_143=attr(global("time","Luhesi"),"time");Args args_142;return invoke(fn_143,args_142);}());V right_141=scope_120->get("start");return official::binary("-",left_140,right_141);}());V compare_139;V comparison_result_144;compare_139=V(3LL);comparison_result_144=compare_value("<",compare_138,compare_139);return comparison_result_144;}());}()).truth()){
        // Luhesi.py:76
        if(unary("not",scope_120->get("have_kick")).truth()){
            // Luhesi.py:77
            ([&]()->V{auto fn_126=attr(attr(self_value(),"logger"),"debug");Args args_125;args_125.pos(V("handle special attack"));return invoke(fn_126,args_125);}());
        }
        // Luhesi.py:78
        {V value_127=V(true);scope_120->set("have_kick",value_127);}
        // Luhesi.py:79
        if(([&]()->V{V compare_128=scope_120->get("res_count");V compare_129;V comparison_result_130;compare_129=V(3LL);comparison_result_130=compare_value("<",compare_128,compare_129);return comparison_result_130;}()).truth()){
            // Luhesi.py:80
            ([&]()->V{auto fn_132=attr(self_value(),"f_break");Args args_131;return invoke(fn_132,args_131);}());
        }
        // Luhesi.py:81
        ([&]()->V{auto fn_134=attr(self_value(),"click");Args args_133;args_133.kw("after_sleep",V(0.1));return invoke(fn_134,args_133);}());
    }
    // Luhesi.py:82
    return scope_120->get("have_kick");
return V{};
}),false);
// Official method Luhesi.check_res, lines 84-91
register_method("check_res",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_145=bind_arguments(official_args,signature,captured);
scope_145->set("best",V::missing());
    // Luhesi.py:85
    if(unary("not",([&]()->V{auto fn_147=attr(attr(self_value(),"task"),"in_team_and_world");Args args_146;return invoke(fn_147,args_146);}())).truth()){
        // Luhesi.py:86
        return V(false);
    }
    // Luhesi.py:87
    {V value_148=([&]()->V{auto fn_150=attr(attr(self_value(),"task"),"find_best_match_in_box");Args args_149;args_149.pos(([&]()->V{auto fn_152=attr(attr(self_value(),"task"),"get_box_by_name");Args args_151;args_151.pos(V("target_box_long2"));return invoke(fn_152,args_151);}()));args_149.pos(V::list({V("has_target"),V("no_target")}));args_149.kw("threshold",V(0.6));return invoke(fn_150,args_149);}());scope_145->set("best",value_148);}
    // Luhesi.py:90
    ([&]()->V{auto fn_154=attr(attr(self_value(),"logger"),"debug");Args args_153;args_153.pos(V(std::string{}+"check res "+format_value(scope_145->get("best"),"",-1)));return invoke(fn_154,args_153);}());
    // Luhesi.py:91
    return scope_145->get("best");
return V{};
}),false);
// Official method Luhesi.detect_elbow_strike, lines 93-94
register_method("detect_elbow_strike",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"ready",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_155=bind_arguments(official_args,signature,captured);
    // Luhesi.py:94
    return ([&]()->V{V operand_156;operand_156=scope_155->get("ready");if(!operand_156.truth())return operand_156;return unary("not",([&]()->V{auto fn_158=attr(self_value(),"available");Args args_157;args_157.pos(V("echo"));args_157.kw("check_color",V(true));return invoke(fn_158,args_157);}()));}());
return V{};
}),false);
}
}
