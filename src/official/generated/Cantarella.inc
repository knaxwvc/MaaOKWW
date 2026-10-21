// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Cantarella.py
// SHA256 7ceca495543160b76f9b5020395a3d77aa111234420305b30cbbfedad2389975
void OfficialCharacter::install_Cantarella(){
auto scope=std::make_shared<Scope>();
// Official method Cantarella.__init__, lines 6-9
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Cantarella.py:7
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Cantarella");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Cantarella.py:8
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"last_heavy",value_6);}
    // Cantarella.py:9
    {V value_7=V(true);set_attr(self_value(),"check_f_on_switch",value_7);}
return V{};
}),false);
// Official method Cantarella.get_switch_priority, lines 11-14
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Cantarella.py:12
    if(([&]()->V{V operand_9;operand_9=scope_8->get("has_intro");if(!operand_9.truth())return operand_9;operand_9=scope_8->get("current_char");if(!operand_9.truth())return operand_9;return ([&]()->V{V compare_10=attr(scope_8->get("current_char"),"char_name");V compare_11;V comparison_result_12;compare_11=V::set({V("char_roccia"),V("char_sanhua")});comparison_result_12=compare_value("in",compare_10,compare_11);return comparison_result_12;}());}()).truth()){
        // Cantarella.py:13
        return attr(global("SwitchPriority","Cantarella"),"MUST");
    }
    // Cantarella.py:14
    return ([&]()->V{auto fn_16=attr(([&]()->V{auto fn_14=global("super","Cantarella");Args args_13;return invoke(fn_14,args_13);}()),"get_switch_priority");Args args_15;args_15.pos(scope_8->get("current_char"));args_15.pos(scope_8->get("has_intro"));args_15.pos(scope_8->get("target_low_con"));return invoke(fn_16,args_15);}());
return V{};
}),false);
// Official method Cantarella.do_perform, lines 16-58
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_17=bind_arguments(official_args,signature,captured);
scope_17->set("count",V::missing());
scope_17->set("forte_delay",V::missing());
scope_17->set("now",V::missing());
scope_17->set("perform_under_outro",V::missing());
    // Cantarella.py:17
    {V value_18=V(false);scope_17->set("perform_under_outro",value_18);}
    // Cantarella.py:18
    if(attr(self_value(),"has_intro").truth()){
        // Cantarella.py:19
        ([&]()->V{auto fn_20=attr(self_value(),"continues_normal_attack");Args args_19;args_19.pos(V(1.2));return invoke(fn_20,args_19);}());
        // Cantarella.py:20
        if(([&]()->V{V operand_21;operand_21=attr(self_value(),"has_sub_dps_intro");if(!operand_21.truth())return operand_21;return ([&]()->V{V compare_22=([&]()->V{auto fn_25=attr(self_value(),"check_outro");Args args_24;return invoke(fn_25,args_24);}());V compare_23;V comparison_result_26;compare_23=V::set({V("char_roccia"),V("char_sanhua")});comparison_result_26=compare_value("in",compare_22,compare_23);return comparison_result_26;}());}()).truth()){
            // Cantarella.py:21
            {V value_27=V(true);scope_17->set("perform_under_outro",value_27);}
        }
    }
    // Cantarella.py:22
    ([&]()->V{auto fn_29=attr(self_value(),"click_liberation");Args args_28;return invoke(fn_29,args_28);}());
    // Cantarella.py:23
    if(([&]()->V{V operand_30;operand_30=([&]()->V{auto fn_32=attr(self_value(),"is_mouse_forte_full");Args args_31;return invoke(fn_32,args_31);}());if(operand_30.truth())return operand_30;return unary("not",([&]()->V{auto fn_34=attr(self_value(),"is_forte_full");Args args_33;return invoke(fn_34,args_33);}()));}()).truth()){
        // Cantarella.py:24
        ([&]()->V{auto fn_36=attr(self_value(),"click_resonance");Args args_35;return invoke(fn_36,args_35);}());
        // Cantarella.py:25
        if(([&]()->V{V operand_37;operand_37=scope_17->get("perform_under_outro");if(!operand_37.truth())return operand_37;return ([&]()->V{auto fn_39=attr(self_value(),"flying");Args args_38;return invoke(fn_39,args_38);}());}()).truth()){
            // Cantarella.py:26
            ([&]()->V{auto fn_41=attr(self_value(),"wait_down");Args args_40;return invoke(fn_41,args_40);}());
        }
        // Cantarella.py:27
        if(([&]()->V{V operand_42;operand_42=unary("not",([&]()->V{auto fn_44=attr(self_value(),"flying");Args args_43;return invoke(fn_44,args_43);}()));if(!operand_42.truth())return operand_42;return ([&]()->V{auto fn_46=attr(self_value(),"is_mouse_forte_full");Args args_45;return invoke(fn_46,args_45);}());}()).truth()){
            // Cantarella.py:28
            if(([&]()->V{auto fn_48=attr(self_value(),"heavy_click_forte");Args args_47;args_47.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_48,args_47);}()).truth()){
                // Cantarella.py:29
                {V value_49=([&]()->V{auto fn_51=attr(global("time","Cantarella"),"time");Args args_50;return invoke(fn_51,args_50);}());set_attr(self_value(),"last_heavy",value_49);}
            }
        }else{
            // Cantarella.py:30
            if(([&]()->V{auto fn_53=attr(self_value(),"click_echo");Args args_52;return invoke(fn_53,args_52);}()).truth()){
                // Cantarella.py:31
                return ([&]()->V{auto fn_55=attr(self_value(),"switch_next_char");Args args_54;return invoke(fn_55,args_54);}());
            }else{
                // Cantarella.py:33
                ([&]()->V{auto fn_57=attr(self_value(),"continues_normal_attack");Args args_56;args_56.pos(V(0.1));return invoke(fn_57,args_56);}());
                // Cantarella.py:34
                return ([&]()->V{auto fn_59=attr(self_value(),"switch_next_char");Args args_58;return invoke(fn_59,args_58);}());
            }
        }
    }
    // Cantarella.py:35
    {V value_60=([&]()->V{auto fn_62=attr(global("time","Cantarella"),"time");Args args_61;return invoke(fn_62,args_61);}());scope_17->set("forte_delay",value_60);}
    // Cantarella.py:36
    {V value_63=unary("-",V(0.1));scope_17->set("count",value_63);}
    // Cantarella.py:37
        while(([&]()->V{V operand_107;operand_107=([&]()->V{V compare_108=([&]()->V{auto fn_111=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_110;args_110.pos(attr(self_value(),"last_heavy"));return invoke(fn_111,args_110);}());V compare_109;V comparison_result_112;compare_109=V(8LL);comparison_result_112=compare_value("<",compare_108,compare_109);return comparison_result_112;}());if(!operand_107.truth())return operand_107;return unary("not",([&]()->V{auto fn_114=attr(self_value(),"is_mouse_forte_full");Args args_113;return invoke(fn_114,args_113);}()));}()).truth()){
        // Cantarella.py:38
        {V value_64=([&]()->V{auto fn_66=attr(global("time","Cantarella"),"time");Args args_65;return invoke(fn_66,args_65);}());scope_17->set("now",value_64);}
        // Cantarella.py:39
        if(([&]()->V{V operand_67;operand_67=([&]()->V{auto fn_69=attr(self_value(),"resonance_available");Args args_68;return invoke(fn_69,args_68);}());if(!operand_67.truth())return operand_67;return ([&]()->V{auto fn_71=attr(self_value(),"click_resonance");Args args_70;args_70.kw("send_click",V(false));return invoke(fn_71,args_70);}());}()).truth()){
            // Cantarella.py:40
            if(unary("not",scope_17->get("perform_under_outro")).truth()){
                // Cantarella.py:41
                ([&]()->V{auto fn_73=attr(attr(self_value(),"task"),"mouse_up");Args args_72;return invoke(fn_73,args_72);}());
                // Cantarella.py:42
                return ([&]()->V{auto fn_75=attr(self_value(),"switch_next_char");Args args_74;return invoke(fn_75,args_74);}());
            }
        }
        // Cantarella.py:43
        if(([&]()->V{V operand_76;operand_76=unary("not",scope_17->get("perform_under_outro"));if(!operand_76.truth())return operand_76;operand_76=([&]()->V{auto fn_78=attr(self_value(),"need_fast_perform");Args args_77;return invoke(fn_78,args_77);}());if(!operand_76.truth())return operand_76;return ([&]()->V{V compare_79=([&]()->V{auto fn_82=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_81;args_81.pos(attr(self_value(),"last_perform"));return invoke(fn_82,args_81);}());V compare_80;V comparison_result_83;compare_80=V(1.1);comparison_result_83=compare_value(">",compare_79,compare_80);return comparison_result_83;}());}()).truth()){
            // Cantarella.py:44
            break;
        }
        // Cantarella.py:45
        if(([&]()->V{V compare_84=([&]()->V{V left_86=scope_17->get("now");V right_87=scope_17->get("forte_delay");return official::binary("-",left_86,right_87);}());V compare_85;V comparison_result_88;compare_85=scope_17->get("count");comparison_result_88=compare_value(">",compare_84,compare_85);return comparison_result_88;}()).truth()){
            // Cantarella.py:46
            ([&]()->V{auto fn_90=attr(attr(self_value(),"task"),"mouse_up");Args args_89;return invoke(fn_90,args_89);}());
            // Cantarella.py:47
            ([&]()->V{auto fn_92=attr(self_value(),"sleep");Args args_91;args_91.pos(V(0.2));return invoke(fn_92,args_91);}());
            // Cantarella.py:48
            ([&]()->V{auto fn_94=attr(attr(self_value(),"task"),"mouse_down");Args args_93;return invoke(fn_94,args_93);}());
            // Cantarella.py:49
            scope_17->set("count",official::binary("+",scope_17->get("count"),V(1LL)));
        }
        // Cantarella.py:50
        if(([&]()->V{auto fn_96=attr(self_value(),"is_forte_full");Args args_95;return invoke(fn_96,args_95);}()).truth()){
            // Cantarella.py:51
            {V value_97=scope_17->get("now");scope_17->set("forte_delay",value_97);}
        }else{
            // Cantarella.py:52
            if(([&]()->V{V compare_98=([&]()->V{V left_100=scope_17->get("now");V right_101=scope_17->get("forte_delay");return official::binary("-",left_100,right_101);}());V compare_99;V comparison_result_102;compare_99=V(0.5);comparison_result_102=compare_value(">",compare_98,compare_99);return comparison_result_102;}()).truth()){
                // Cantarella.py:53
                break;
            }
        }
        // Cantarella.py:54
        ([&]()->V{auto fn_104=attr(self_value(),"check_combat");Args args_103;return invoke(fn_104,args_103);}());
        // Cantarella.py:55
        ([&]()->V{auto fn_106=attr(attr(self_value(),"task"),"next_frame");Args args_105;return invoke(fn_106,args_105);}());
    }
    // Cantarella.py:56
    ([&]()->V{auto fn_116=attr(attr(self_value(),"task"),"mouse_up");Args args_115;return invoke(fn_116,args_115);}());
    // Cantarella.py:57
    ([&]()->V{auto fn_118=attr(self_value(),"click_echo");Args args_117;return invoke(fn_118,args_117);}());
    // Cantarella.py:58
    ([&]()->V{auto fn_120=attr(self_value(),"switch_next_char");Args args_119;return invoke(fn_120,args_119);}());
return V{};
}),false);
// Official method Cantarella.resonance_available, lines 60-63
register_method("resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current",V{}},{"check_ready",V(false)},{"check_cd",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_121=bind_arguments(official_args,signature,captured);
    // Cantarella.py:61
    if(([&]()->V{V operand_122;operand_122=unary("not",([&]()->V{auto fn_124=attr(self_value(),"is_mouse_forte_full");Args args_123;return invoke(fn_124,args_123);}()));if(!operand_122.truth())return operand_122;return ([&]()->V{auto fn_126=attr(self_value(),"is_forte_full");Args args_125;return invoke(fn_126,args_125);}());}()).truth()){
        // Cantarella.py:62
        return unary("not",([&]()->V{auto fn_128=attr(self_value(),"has_cd");Args args_127;args_127.pos(V("resonance"));return invoke(fn_128,args_127);}()));
    }
    // Cantarella.py:63
    return ([&]()->V{auto fn_132=attr(([&]()->V{auto fn_130=global("super","Cantarella");Args args_129;return invoke(fn_130,args_129);}()),"resonance_available");Args args_131;return invoke(fn_132,args_131);}());
return V{};
}),false);
// Official method Cantarella.on_combat_end, lines 65-68
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_133=bind_arguments(official_args,signature,captured);
scope_133->set("next_char",V::missing());
    // Cantarella.py:66
    {V value_134=([&]()->V{auto fn_136=global("str","Cantarella");Args args_135;args_135.pos(([&]()->V{V left_137=([&]()->V{V left_139=([&]()->V{V left_141=attr(self_value(),"index");V right_142=V(1LL);return official::binary("+",left_141,right_142);}());V right_140=([&]()->V{auto fn_144=global("len","Cantarella");Args args_143;args_143.pos(scope_133->get("chars"));return invoke(fn_144,args_143);}());return official::binary("%",left_139,right_140);}());V right_138=V(1LL);return official::binary("+",left_137,right_138);}()));return invoke(fn_136,args_135);}());scope_133->set("next_char",value_134);}
    // Cantarella.py:67
    ([&]()->V{auto fn_146=attr(attr(self_value(),"logger"),"debug");Args args_145;args_145.pos(V(std::string{}+"Cantarella on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch next char: "+format_value(scope_133->get("next_char"),"",-1)));return invoke(fn_146,args_145);}());
    // Cantarella.py:68
    ([&]()->V{auto fn_148=attr(attr(self_value(),"task"),"send_key");Args args_147;args_147.pos(scope_133->get("next_char"));return invoke(fn_148,args_147);}());
return V{};
}),false);
// Official method Cantarella.is_forte_full, lines 70-74
register_method("is_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
scope_149->set("box",V::missing());
scope_149->set("white_percent",V::missing());
    // Cantarella.py:71
    {V value_150=([&]()->V{auto fn_152=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_151;args_151.pos(V(5120LL));args_151.pos(V(2880LL));args_151.pos(V(3034LL));args_151.pos(V(2640LL));args_151.pos(V(3090LL));args_151.pos(V(2700LL));args_151.kw("name",V("forte_full"));args_151.kw("hcenter",V(true));return invoke(fn_152,args_151);}());scope_149->set("box",value_150);}
    // Cantarella.py:72
    {V value_153=([&]()->V{auto fn_155=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_154;args_154.pos(global("forte_white_color","Cantarella"));args_154.pos(scope_149->get("box"));return invoke(fn_155,args_154);}());scope_149->set("white_percent",value_153);}
    // Cantarella.py:73
    ([&]()->V{auto fn_157=attr(attr(self_value(),"logger"),"debug");Args args_156;args_156.pos(V(std::string{}+"forte_color_percent "+format_value(scope_149->get("white_percent"),"",-1)));return invoke(fn_157,args_156);}());
    // Cantarella.py:74
    return ([&]()->V{V compare_158=scope_149->get("white_percent");V compare_159;V comparison_result_160;compare_159=V(0.06);comparison_result_160=compare_value(">",compare_158,compare_159);return comparison_result_160;}());
return V{};
}),false);
}
