// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Jinhsi.py
// SHA256 21604cef3c3e9877b0300e0925fc84a7e94872737afa313b39a8cc40c0943387
void OfficialCharacter::install_Jinhsi(){
auto scope=std::make_shared<Scope>();
// Official method Jinhsi.__init__, lines 8-14
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Jinhsi");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Jinhsi.py:10
    {V value_6=V(0LL);set_attr(self_value(),"last_free_intro",value_6);}
    // Jinhsi.py:11
    {V value_7=V(false);set_attr(self_value(),"has_free_intro",value_7);}
    // Jinhsi.py:12
    {V value_8=V(false);set_attr(self_value(),"incarnation",value_8);}
    // Jinhsi.py:13
    {V value_9=V(false);set_attr(self_value(),"incarnation_cd",value_9);}
    // Jinhsi.py:14
    {V value_10=V(0LL);set_attr(self_value(),"last_fly_e_time",value_10);}
return V{};
}),false);
// Official method Jinhsi.do_perform, lines 16-24
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:17
    if(attr(self_value(),"incarnation").truth()){
        // Jinhsi.py:18
        ([&]()->V{auto fn_13=attr(self_value(),"handle_incarnation");Args args_12;return invoke(fn_13,args_12);}());
        // Jinhsi.py:19
        return ([&]()->V{auto fn_15=attr(self_value(),"switch_next_char");Args args_14;return invoke(fn_15,args_14);}());
    }else{
        // Jinhsi.py:20
        if(([&]()->V{V operand_16;operand_16=attr(self_value(),"has_intro");if(operand_16.truth())return operand_16;return attr(self_value(),"incarnation_cd");}()).truth()){
            // Jinhsi.py:21
            ([&]()->V{auto fn_18=attr(self_value(),"handle_intro");Args args_17;return invoke(fn_18,args_17);}());
            // Jinhsi.py:22
            return ([&]()->V{auto fn_20=attr(self_value(),"switch_next_char");Args args_19;return invoke(fn_20,args_19);}());
        }
    }
    // Jinhsi.py:23
    ([&]()->V{auto fn_22=attr(self_value(),"click_echo");Args args_21;return invoke(fn_22,args_21);}());
    // Jinhsi.py:24
    return ([&]()->V{auto fn_24=attr(self_value(),"switch_next_char");Args args_23;return invoke(fn_24,args_23);}());
return V{};
}),false);
// Official method Jinhsi.reset_state, lines 26-30
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_25=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:27
    ([&]()->V{auto fn_29=attr(([&]()->V{auto fn_27=global("super","Jinhsi");Args args_26;return invoke(fn_27,args_26);}()),"reset_state");Args args_28;return invoke(fn_29,args_28);}());
    // Jinhsi.py:28
    {V value_30=V(false);set_attr(self_value(),"incarnation",value_30);}
    // Jinhsi.py:29
    {V value_31=V(false);set_attr(self_value(),"has_free_intro",value_31);}
    // Jinhsi.py:30
    {V value_32=V(false);set_attr(self_value(),"incarnation_cd",value_32);}
return V{};
}),false);
// Official method Jinhsi.get_switch_priority, lines 32-38
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_33=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:33
    if(([&]()->V{V operand_34;operand_34=scope_33->get("has_intro");if(operand_34.truth())return operand_34;operand_34=attr(self_value(),"incarnation");if(operand_34.truth())return operand_34;return attr(self_value(),"incarnation_cd");}()).truth()){
        // Jinhsi.py:34
        ([&]()->V{auto fn_36=attr(attr(self_value(),"logger"),"info");Args args_35;args_35.pos(V(std::string{}+"switch priority max because has_intro "+format_value(scope_33->get("has_intro"),"",-1)+" incarnation "+format_value(attr(self_value(),"incarnation"),"",-1)+" incarnation_cd "+format_value(attr(self_value(),"incarnation_cd"),"",-1)));return invoke(fn_36,args_35);}());
        // Jinhsi.py:37
        return attr(global("SwitchPriority","Jinhsi"),"MUST");
    }
    // Jinhsi.py:38
    return attr(global("SwitchPriority","Jinhsi"),"NO");
return V{};
}),false);
// Official method Jinhsi.switch_next_char, lines 40-42
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","args",{})](const Args& official_args)->V{
auto scope_37=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:41
    ([&]()->V{auto fn_41=attr(([&]()->V{auto fn_39=global("super","Jinhsi");Args args_38;return invoke(fn_39,args_38);}()),"switch_next_char");Args args_40;args_40.kw("free_intro",attr(self_value(),"has_free_intro"));args_40.kw("target_low_con",V(true));return invoke(fn_41,args_40);}());
    // Jinhsi.py:42
    {V value_42=V(false);set_attr(self_value(),"has_free_intro",value_42);}
return V{};
}),false);
// Official method Jinhsi.handle_incarnation, lines 44-80
register_method("handle_incarnation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_43=bind_arguments(official_args,signature,captured);
scope_43->set("animation_start",V::missing());
scope_43->set("last_op",V::missing());
scope_43->set("start",V::missing());
    // Jinhsi.py:45
    {V value_44=V(false);set_attr(self_value(),"incarnation",value_44);}
    // Jinhsi.py:46
    ([&]()->V{auto fn_46=attr(attr(self_value(),"logger"),"info");Args args_45;args_45.pos(V(std::string{}+"handle_incarnation click_resonance start"));return invoke(fn_46,args_45);}());
    // Jinhsi.py:47
    {V value_47=([&]()->V{auto fn_49=attr(global("time","Jinhsi"),"time");Args args_48;return invoke(fn_49,args_48);}());scope_43->set("start",value_47);}
    // Jinhsi.py:48
    {V value_50=V(0LL);scope_43->set("animation_start",value_50);}
    // Jinhsi.py:49
    {V value_51=V("resonance");scope_43->set("last_op",value_51);}
    // Jinhsi.py:50
    {V value_52=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_52);}
    // Jinhsi.py:51
        while(V(true).truth()){
        // Jinhsi.py:52
        if(([&]()->V{V compare_53=([&]()->V{V left_55=([&]()->V{auto fn_58=attr(global("time","Jinhsi"),"time");Args args_57;return invoke(fn_58,args_57);}());V right_56=scope_43->get("start");return official::binary("-",left_55,right_56);}());V compare_54;V comparison_result_59;compare_54=V(6LL);comparison_result_59=compare_value(">",compare_53,compare_54);return comparison_result_59;}()).truth()){
            // Jinhsi.py:53
            ([&]()->V{auto fn_61=attr(attr(self_value(),"logger"),"info");Args args_60;args_60.pos(V(std::string{}+"handle incarnation too long"));return invoke(fn_61,args_60);}());
            // Jinhsi.py:54
            break;
        }
        // Jinhsi.py:55
        if(item(([&]()->V{auto fn_63=attr(attr(self_value(),"task"),"in_team");Args args_62;return invoke(fn_63,args_62);}()),V(0LL)).truth()){
            // Jinhsi.py:56
            if(([&]()->V{V compare_64=scope_43->get("last_op");V compare_65;V comparison_result_66;compare_65=V("resonance");comparison_result_66=compare_value("==",compare_64,compare_65);return comparison_result_66;}()).truth()){
                // Jinhsi.py:57
                ([&]()->V{auto fn_68=attr(attr(self_value(),"task"),"click");Args args_67;args_67.kw("interval",V(0.1));return invoke(fn_68,args_67);}());
                // Jinhsi.py:58
                {V value_69=V("click");scope_43->set("last_op",value_69);}
            }else{
                // Jinhsi.py:60
                ([&]()->V{auto fn_71=attr(self_value(),"send_resonance_key");Args args_70;return invoke(fn_71,args_70);}());
                // Jinhsi.py:61
                {V value_72=V("resonance");scope_43->set("last_op",value_72);}
            }
            // Jinhsi.py:62
            if(([&]()->V{V compare_73=scope_43->get("animation_start");V compare_74;V comparison_result_75;compare_74=V(0LL);comparison_result_75=compare_value("!=",compare_73,compare_74);return comparison_result_75;}()).truth()){
                // Jinhsi.py:63
                ([&]()->V{auto fn_77=attr(attr(self_value(),"logger"),"info");Args args_76;args_76.pos(V(std::string{}+"Jinhsi handle_incarnation done"));return invoke(fn_77,args_76);}());
                // Jinhsi.py:64
                break;
            }
        }else{
            // Jinhsi.py:66
            if(([&]()->V{V compare_78=scope_43->get("animation_start");V compare_79;V comparison_result_80;compare_79=V(0LL);comparison_result_80=compare_value("==",compare_78,compare_79);return comparison_result_80;}()).truth()){
                // Jinhsi.py:67
                ([&]()->V{auto fn_82=attr(attr(self_value(),"logger"),"info");Args args_81;args_81.pos(V(std::string{}+"Jinhsi handle_incarnation start animation"));return invoke(fn_82,args_81);}());
                // Jinhsi.py:68
                {V value_83=([&]()->V{auto fn_85=attr(global("time","Jinhsi"),"time");Args args_84;return invoke(fn_85,args_84);}());scope_43->set("animation_start",value_83);}
            }
            // Jinhsi.py:69
            {V value_86=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_86);}
        }
        // Jinhsi.py:70
        ([&]()->V{auto fn_88=attr(self_value(),"check_combat");Args args_87;return invoke(fn_88,args_87);}());
        // Jinhsi.py:71
        ([&]()->V{auto fn_90=attr(attr(self_value(),"task"),"next_frame");Args args_89;return invoke(fn_90,args_89);}());
    }
    // Jinhsi.py:72
    {V value_91=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_91);}
    // Jinhsi.py:74
    if(unary("not",([&]()->V{auto fn_93=attr(self_value(),"click_echo");Args args_92;return invoke(fn_93,args_92);}())).truth()){
        // Jinhsi.py:75
        ([&]()->V{auto fn_95=attr(attr(self_value(),"task"),"click");Args args_94;return invoke(fn_95,args_94);}());
    }
    // Jinhsi.py:77
    ([&]()->V{auto fn_97=attr(self_value(),"add_freeze_duration");Args args_96;args_96.pos(scope_43->get("animation_start"));return invoke(fn_97,args_96);}());
    // Jinhsi.py:80
    ([&]()->V{auto fn_99=attr(attr(self_value(),"logger"),"info");Args args_98;args_98.pos(V(std::string{}+"handle_incarnation  click_resonance end "+format_value(([&]()->V{V left_100=([&]()->V{auto fn_103=attr(global("time","Jinhsi"),"time");Args args_102;return invoke(fn_103,args_102);}());V right_101=scope_43->get("start");return official::binary("-",left_100,right_101);}()),"",-1)));return invoke(fn_99,args_98);}());
return V{};
}),false);
// Official method Jinhsi.handle_intro, lines 82-110
register_method("handle_intro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_104=bind_arguments(official_args,signature,captured);
scope_104->set("elapsed",V::missing());
scope_104->set("start",V::missing());
    // Jinhsi.py:83
    ([&]()->V{auto fn_106=attr(attr(self_value(),"logger"),"info");Args args_105;args_105.pos(V(std::string{}+"handle_intro start"));return invoke(fn_106,args_105);}());
    // Jinhsi.py:84
    {V value_107=([&]()->V{auto fn_109=attr(global("time","Jinhsi"),"time");Args args_108;return invoke(fn_109,args_108);}());scope_104->set("start",value_107);}
    // Jinhsi.py:85
        while(V(true).truth()){
        // Jinhsi.py:86
        {V value_110=([&]()->V{V left_111=([&]()->V{auto fn_114=attr(global("time","Jinhsi"),"time");Args args_113;return invoke(fn_114,args_113);}());V right_112=scope_104->get("start");return official::binary("-",left_111,right_112);}());scope_104->set("elapsed",value_110);}
        // Jinhsi.py:87
        if(([&]()->V{auto fn_116=attr(self_value(),"has_cd");Args args_115;args_115.pos(V("resonance"));return invoke(fn_116,args_115);}()).truth()){
            // Jinhsi.py:88
            if(([&]()->V{V compare_117=V(0.3);V compare_118;V comparison_result_119;compare_118=scope_104->get("elapsed");comparison_result_119=compare_value("<",compare_117,compare_118);if(!comparison_result_119.truth())return comparison_result_119;compare_117=compare_118;compare_118=V(1.5);comparison_result_119=compare_value("<",compare_117,compare_118);return comparison_result_119;}()).truth()){
                // Jinhsi.py:89
                {V value_120=V(true);set_attr(self_value(),"incarnation_cd",value_120);}
                // Jinhsi.py:91
                if(unary("not",([&]()->V{auto fn_122=attr(self_value(),"click_echo");Args args_121;return invoke(fn_122,args_121);}())).truth()){
                    // Jinhsi.py:92
                    ([&]()->V{auto fn_124=attr(self_value(),"click");Args args_123;return invoke(fn_124,args_123);}());
                }
                // Jinhsi.py:93
                return V{};
            }else{
                // Jinhsi.py:94
                if(([&]()->V{V compare_125=scope_104->get("elapsed");V compare_126;V comparison_result_127;compare_126=V(1.5);comparison_result_127=compare_value(">",compare_125,compare_126);return comparison_result_127;}()).truth()){
                    // Jinhsi.py:96
                    break;
                }
            }
        }else{
            // Jinhsi.py:98
            ([&]()->V{auto fn_129=attr(self_value(),"send_resonance_key");Args args_128;args_128.kw("interval",V(0.1));return invoke(fn_129,args_128);}());
        }
        // Jinhsi.py:99
        ([&]()->V{auto fn_131=attr(attr(self_value(),"task"),"next_frame");Args args_130;return invoke(fn_131,args_130);}());
        // Jinhsi.py:100
        ([&]()->V{auto fn_133=attr(self_value(),"check_combat");Args args_132;return invoke(fn_133,args_132);}());
    }
    // Jinhsi.py:102
    {V value_134=scope_104->get("start");set_attr(self_value(),"last_fly_e_time",value_134);}
    // Jinhsi.py:103
    if(([&]()->V{auto fn_136=attr(self_value(),"click_liberation");Args args_135;args_135.kw("send_click",V(true));return invoke(fn_136,args_135);}()).truth()){
        // Jinhsi.py:104
        ([&]()->V{auto fn_138=attr(self_value(),"continues_normal_attack");Args args_137;args_137.pos(V(0.3));return invoke(fn_138,args_137);}());
    }else{
        // Jinhsi.py:106
        ([&]()->V{auto fn_140=attr(self_value(),"continues_normal_attack");Args args_139;args_139.pos(V(1.4));return invoke(fn_140,args_139);}());
    }
    // Jinhsi.py:108
    ([&]()->V{auto fn_142=attr(attr(self_value(),"logger"),"info");Args args_141;args_141.pos(V(std::string{}+"handle_intro end "+format_value(([&]()->V{V left_143=([&]()->V{auto fn_146=attr(global("time","Jinhsi"),"time");Args args_145;return invoke(fn_146,args_145);}());V right_144=scope_104->get("start");return official::binary("-",left_143,right_144);}()),"",-1)));return invoke(fn_142,args_141);}());
    // Jinhsi.py:109
    {V value_147=V(true);set_attr(self_value(),"incarnation",value_147);}
    // Jinhsi.py:110
    {V value_148=V(false);set_attr(self_value(),"incarnation_cd",value_148);}
return V{};
}),false);
// Official method Jinhsi.wait_resonance, lines 112-114
register_method("wait_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
    // Jinhsi.py:113
        while(unary("not",([&]()->V{auto fn_153=attr(self_value(),"resonance_available");Args args_152;return invoke(fn_153,args_152);}())).truth()){
        // Jinhsi.py:114
        ([&]()->V{auto fn_151=attr(self_value(),"send_resonance_key");Args args_150;args_150.kw("interval",V(0.1));return invoke(fn_151,args_150);}());
    }
return V{};
}),false);
}
