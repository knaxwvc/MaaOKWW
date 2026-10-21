// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Lucy.py
// SHA256 b584e836b9e3eebc4f66bd25c8eb2745eda05bd64109543c6c70304e7342216c
void OfficialCharacter::install_Lucy(){
auto scope=std::make_shared<Scope>();
set_class_attribute("FORTE_TIMEOUT",V(8.5));
set_class_attribute("LIB_CD_WAIT",V(1.5));
set_class_attribute("NORMAL_ATTACK_DURATION",V(0.1));
set_class_attribute("HEAVY_ATTACK_DURATION",V(0.4));
set_class_attribute("CLICK_INTERVAL",V(0.1));
set_class_attribute("ENHANCED_HEAVY_INTERVAL",V(0.2));
set_class_attribute("LIB_CLICK_COUNT",V(11LL));
// Official method Lucy.do_perform, lines 13-25
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Lucy.py:15
    {
    try{
        // Lucy.py:16
        if(([&]()->V{V operand_2;operand_2=([&]()->V{auto fn_4=global("hasattr","Lucy");Args args_3;args_3.pos(attr(self_value(),"task"));args_3.pos(V("check_f_break"));return invoke(fn_4,args_3);}());if(!operand_2.truth())return operand_2;return ([&]()->V{auto fn_6=attr(attr(self_value(),"task"),"check_f_break");Args args_5;return invoke(fn_6,args_5);}());}()).truth()){
            // Lucy.py:17
            ([&]()->V{auto fn_8=attr(attr(self_value(),"task"),"f_break");Args args_7;return invoke(fn_8,args_7);}());
        }else{
            // Lucy.py:18
            if(([&]()->V{auto fn_10=global("getattr","Lucy");Args args_9;args_9.pos(attr(self_value(),"task"));args_9.pos(V("can_break"));args_9.pos(V(false));return invoke(fn_10,args_9);}()).truth()){
                // Lucy.py:19
                ([&]()->V{auto fn_12=attr(attr(self_value(),"task"),"f_break");Args args_11;return invoke(fn_12,args_11);}());
            }
        }
    }catch(const std::exception& official_exception){
        rethrow_control_exception(official_exception);
    }
    }
    // Lucy.py:22
    if(unary("not",([&]()->V{auto fn_14=attr(self_value(),"is_forte_full");Args args_13;return invoke(fn_14,args_13);}())).truth()){
        // Lucy.py:23
        ([&]()->V{auto fn_16=attr(self_value(),"perform_standard");Args args_15;return invoke(fn_16,args_15);}());
    }
    // Lucy.py:24
    ([&]()->V{auto fn_18=attr(self_value(),"perform_liberation");Args args_17;return invoke(fn_18,args_17);}());
    // Lucy.py:25
    return ([&]()->V{auto fn_20=attr(self_value(),"switch_next_char");Args args_19;return invoke(fn_20,args_19);}());
return V{};
}),false);
// Official method Lucy.perform_standard, lines 27-49
register_method("perform_standard",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
scope_21->set("start_time",V::missing());
    // Lucy.py:29
    if(([&]()->V{auto fn_23=attr(self_value(),"is_forte_full");Args args_22;return invoke(fn_23,args_22);}()).truth()){
        // Lucy.py:30
        ([&]()->V{auto fn_25=attr(attr(self_value(),"logger"),"info");Args args_24;args_24.pos(V("Lucy forte is already full, skip standard build-up."));return invoke(fn_25,args_24);}());
        // Lucy.py:31
        return V(false);
    }
    // Lucy.py:33
    {V value_26=([&]()->V{auto fn_28=attr(global("time","Lucy"),"time");Args args_27;return invoke(fn_28,args_27);}());scope_21->set("start_time",value_26);}
    // Lucy.py:34
        while(unary("not",([&]()->V{auto fn_49=attr(self_value(),"is_forte_full");Args args_48;return invoke(fn_49,args_48);}())).truth()){
        // Lucy.py:36
        if(([&]()->V{V compare_29=([&]()->V{V left_31=([&]()->V{auto fn_34=attr(global("time","Lucy"),"time");Args args_33;return invoke(fn_34,args_33);}());V right_32=scope_21->get("start_time");return official::binary("-",left_31,right_32);}());V compare_30;V comparison_result_35;compare_30=attr(self_value(),"FORTE_TIMEOUT");comparison_result_35=compare_value(">",compare_29,compare_30);return comparison_result_35;}()).truth()){
            // Lucy.py:37
            ([&]()->V{auto fn_37=attr(attr(self_value(),"logger"),"warning");Args args_36;args_36.pos(V("Lucy failed to fill forte, timeout reached."));return invoke(fn_37,args_36);}());
            // Lucy.py:38
            break;
        }
        // Lucy.py:40
        if(([&]()->V{auto fn_39=attr(self_value(),"resonance_available");Args args_38;return invoke(fn_39,args_38);}()).truth()){
            // Lucy.py:41
            ([&]()->V{auto fn_41=attr(self_value(),"click_resonance");Args args_40;return invoke(fn_41,args_40);}());
        }
        // Lucy.py:43
        ([&]()->V{auto fn_43=attr(self_value(),"heavy_attack");Args args_42;args_42.pos(attr(self_value(),"HEAVY_ATTACK_DURATION"));return invoke(fn_43,args_42);}());
        // Lucy.py:45
        if(([&]()->V{auto fn_45=attr(self_value(),"resonance_available");Args args_44;return invoke(fn_45,args_44);}()).truth()){
            // Lucy.py:46
            ([&]()->V{auto fn_47=attr(self_value(),"click_resonance");Args args_46;return invoke(fn_47,args_46);}());
        }
    }
    // Lucy.py:48
    ([&]()->V{auto fn_51=attr(self_value(),"continues_normal_attack");Args args_50;args_50.pos(attr(self_value(),"NORMAL_ATTACK_DURATION"));return invoke(fn_51,args_50);}());
    // Lucy.py:49
    return V(true);
return V{};
}),false);
// Official method Lucy.perform_liberation, lines 51-111
register_method("perform_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_52=bind_arguments(official_args,signature,captured);
scope_52->set("_",V::missing());
scope_52->set("fill_start",V::missing());
scope_52->set("liber_after",V::missing());
scope_52->set("press_start",V::missing());
scope_52->set("wait_liber_start",V::missing());
    // Lucy.py:53
    if(([&]()->V{auto fn_54=attr(self_value(),"resonance_available");Args args_53;return invoke(fn_54,args_53);}()).truth()){
        // Lucy.py:54
        ([&]()->V{auto fn_56=attr(self_value(),"click_resonance");Args args_55;return invoke(fn_56,args_55);}());
    }
    // Lucy.py:55
    ([&]()->V{auto fn_58=attr(self_value(),"f_break");Args args_57;return invoke(fn_58,args_57);}());
    // Lucy.py:56
    ([&]()->V{auto fn_60=attr(self_value(),"perform_enhanced_heavy");Args args_59;return invoke(fn_60,args_59);}());
    // Lucy.py:59
    if(unary("not",([&]()->V{auto fn_62=attr(self_value(),"is_mouse_forte_full");Args args_61;return invoke(fn_62,args_61);}())).truth()){
        // Lucy.py:60
        {V value_63=([&]()->V{auto fn_65=attr(global("time","Lucy"),"time");Args args_64;return invoke(fn_65,args_64);}());scope_52->set("fill_start",value_63);}
        // Lucy.py:61
                while(([&]()->V{V operand_74;operand_74=unary("not",([&]()->V{auto fn_76=attr(self_value(),"is_mouse_forte_full");Args args_75;return invoke(fn_76,args_75);}()));if(!operand_74.truth())return operand_74;return ([&]()->V{V compare_77=([&]()->V{V left_79=([&]()->V{auto fn_82=attr(global("time","Lucy"),"time");Args args_81;return invoke(fn_82,args_81);}());V right_80=scope_52->get("fill_start");return official::binary("-",left_79,right_80);}());V compare_78;V comparison_result_83;compare_78=V(6.0);comparison_result_83=compare_value("<",compare_77,compare_78);return comparison_result_83;}());}()).truth()){
            // Lucy.py:62
            ([&]()->V{auto fn_67=attr(attr(self_value(),"task"),"click");Args args_66;return invoke(fn_67,args_66);}());
            // Lucy.py:63
            ([&]()->V{auto fn_69=attr(self_value(),"sleep");Args args_68;args_68.pos(V(0.1));return invoke(fn_69,args_68);}());
            // Lucy.py:64
            if(([&]()->V{auto fn_71=global("hasattr","Lucy");Args args_70;args_70.pos(attr(self_value(),"task"));args_70.pos(V("next_frame"));return invoke(fn_71,args_70);}()).truth()){
                // Lucy.py:65
                {
                try{
                    // Lucy.py:66
                    ([&]()->V{auto fn_73=attr(attr(self_value(),"task"),"next_frame");Args args_72;return invoke(fn_73,args_72);}());
                }catch(const std::exception& official_exception){
                    rethrow_control_exception(official_exception);
                }
                }
            }
        }
    }
    // Lucy.py:70
    if(([&]()->V{auto fn_85=attr(self_value(),"is_mouse_forte_full");Args args_84;return invoke(fn_85,args_84);}()).truth()){
        // Lucy.py:71
        ([&]()->V{auto fn_87=attr(attr(self_value(),"task"),"mouse_down");Args args_86;return invoke(fn_87,args_86);}());
        // Lucy.py:72
        {V value_88=([&]()->V{auto fn_90=attr(global("time","Lucy"),"time");Args args_89;return invoke(fn_90,args_89);}());scope_52->set("press_start",value_88);}
        // Lucy.py:73
                while(([&]()->V{V compare_97=([&]()->V{V left_99=([&]()->V{auto fn_102=attr(global("time","Lucy"),"time");Args args_101;return invoke(fn_102,args_101);}());V right_100=scope_52->get("press_start");return official::binary("-",left_99,right_100);}());V compare_98;V comparison_result_103;compare_98=V(2.5);comparison_result_103=compare_value("<",compare_97,compare_98);return comparison_result_103;}()).truth()){
            // Lucy.py:74
            ([&]()->V{auto fn_92=attr(global("time","Lucy"),"sleep");Args args_91;args_91.pos(V(0.05));return invoke(fn_92,args_91);}());
            // Lucy.py:75
            if(([&]()->V{auto fn_94=global("hasattr","Lucy");Args args_93;args_93.pos(attr(self_value(),"task"));args_93.pos(V("next_frame"));return invoke(fn_94,args_93);}()).truth()){
                // Lucy.py:76
                {
                try{
                    // Lucy.py:77
                    ([&]()->V{auto fn_96=attr(attr(self_value(),"task"),"next_frame");Args args_95;return invoke(fn_96,args_95);}());
                }catch(const std::exception& official_exception){
                    rethrow_control_exception(official_exception);
                }
                }
            }
        }
        // Lucy.py:80
        ([&]()->V{auto fn_105=attr(attr(self_value(),"task"),"mouse_up");Args args_104;return invoke(fn_105,args_104);}());
        // Lucy.py:81
        ([&]()->V{auto fn_107=attr(self_value(),"sleep");Args args_106;args_106.pos(V(0.1));return invoke(fn_107,args_106);}());
        // Lucy.py:83
        {V value_108=([&]()->V{auto fn_110=attr(global("time","Lucy"),"time");Args args_109;return invoke(fn_110,args_109);}());scope_52->set("wait_liber_start",value_108);}
        // Lucy.py:84
        {V value_111=([&]()->V{auto fn_113=attr(self_value(),"liberation_available");Args args_112;return invoke(fn_113,args_112);}());scope_52->set("liber_after",value_111);}
        // Lucy.py:85
                while(([&]()->V{V operand_123;operand_123=([&]()->V{V compare_124=([&]()->V{V left_126=([&]()->V{auto fn_129=attr(global("time","Lucy"),"time");Args args_128;return invoke(fn_129,args_128);}());V right_127=scope_52->get("wait_liber_start");return official::binary("-",left_126,right_127);}());V compare_125;V comparison_result_130;compare_125=V(2.0);comparison_result_130=compare_value("<",compare_124,compare_125);return comparison_result_130;}());if(!operand_123.truth())return operand_123;return unary("not",scope_52->get("liber_after"));}()).truth()){
            // Lucy.py:86
            ([&]()->V{auto fn_115=attr(global("time","Lucy"),"sleep");Args args_114;args_114.pos(V(0.1));return invoke(fn_115,args_114);}());
            // Lucy.py:87
            {V value_116=([&]()->V{auto fn_118=attr(self_value(),"liberation_available");Args args_117;return invoke(fn_118,args_117);}());scope_52->set("liber_after",value_116);}
            // Lucy.py:88
            if(([&]()->V{auto fn_120=global("hasattr","Lucy");Args args_119;args_119.pos(attr(self_value(),"task"));args_119.pos(V("next_frame"));return invoke(fn_120,args_119);}()).truth()){
                // Lucy.py:89
                {
                try{
                    // Lucy.py:90
                    ([&]()->V{auto fn_122=attr(attr(self_value(),"task"),"next_frame");Args args_121;return invoke(fn_122,args_121);}());
                }catch(const std::exception& official_exception){
                    rethrow_control_exception(official_exception);
                }
                }
            }
        }
        // Lucy.py:93
        if(([&]()->V{auto fn_132=attr(self_value(),"echo_available");Args args_131;return invoke(fn_132,args_131);}()).truth()){
            // Lucy.py:94
            ([&]()->V{auto fn_134=attr(self_value(),"click_echo");Args args_133;args_133.kw("time_out",V(0LL));return invoke(fn_134,args_133);}());
        }
    }else{
        // Lucy.py:97
        if(([&]()->V{auto fn_136=attr(self_value(),"echo_available");Args args_135;return invoke(fn_136,args_135);}()).truth()){
            // Lucy.py:98
            ([&]()->V{auto fn_138=attr(self_value(),"click_echo");Args args_137;args_137.kw("time_out",V(0LL));return invoke(fn_138,args_137);}());
        }
    }
    // Lucy.py:100
    if(([&]()->V{auto fn_140=attr(self_value(),"liberation_available");Args args_139;return invoke(fn_140,args_139);}()).truth()){
        // Lucy.py:101
        ([&]()->V{auto fn_142=attr(self_value(),"click_liberation");Args args_141;args_141.kw("send_click",V(true));args_141.kw("wait_if_cd_ready",attr(self_value(),"LIB_CD_WAIT"));return invoke(fn_142,args_141);}());
        // Lucy.py:102
        ([&]()->V{auto fn_144=attr(self_value(),"record_liberation_use");Args args_143;return invoke(fn_144,args_143);}());
        // Lucy.py:103
        ([&]()->V{auto fn_146=attr(attr(self_value(),"logger"),"info");Args args_145;args_145.pos(V("Lucy perform lib: Started"));return invoke(fn_146,args_145);}());
        // Lucy.py:104
        {auto iterator_147=official::iterate(([&]()->V{auto fn_154=global("range","Lucy");Args args_153;args_153.pos(attr(self_value(),"LIB_CLICK_COUNT"));return invoke(fn_154,args_153);}()));V item_148;while(iterator_147.next(item_148)){
            scope_52->set("_",item_148);
            // Lucy.py:105
            ([&]()->V{auto fn_150=attr(self_value(),"click");Args args_149;return invoke(fn_150,args_149);}());
            // Lucy.py:106
            ([&]()->V{auto fn_152=attr(self_value(),"sleep");Args args_151;args_151.pos(attr(self_value(),"CLICK_INTERVAL"));args_151.kw("check_combat",V(false));return invoke(fn_152,args_151);}());
        }
        }
        // Lucy.py:107
        ([&]()->V{auto fn_156=attr(attr(self_value(),"logger"),"info");Args args_155;args_155.pos(V("Lucy perform lib: Ended"));return invoke(fn_156,args_155);}());
    }else{
        // Lucy.py:109
        ([&]()->V{auto fn_158=attr(attr(self_value(),"logger"),"debug");Args args_157;args_157.pos(V("Liberation not available, skipping."));return invoke(fn_158,args_157);}());
    }
    // Lucy.py:111
    return V(true);
return V{};
}),false);
// Official method Lucy.perform_enhanced_heavy, lines 113-121
register_method("perform_enhanced_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_159=bind_arguments(official_args,signature,captured);
    // Lucy.py:115
    if(([&]()->V{auto fn_161=attr(self_value(),"is_mouse_forte_full");Args args_160;return invoke(fn_161,args_160);}()).truth()){
        // Lucy.py:116
        ([&]()->V{auto fn_163=attr(self_value(),"heavy_attack");Args args_162;args_162.pos(attr(self_value(),"HEAVY_ATTACK_DURATION"));return invoke(fn_163,args_162);}());
        // Lucy.py:117
        ([&]()->V{auto fn_165=attr(attr(self_value(),"logger"),"info");Args args_164;args_164.pos(V("Lucy perform enhanced heavy attack 1"));return invoke(fn_165,args_164);}());
        // Lucy.py:118
        ([&]()->V{auto fn_167=attr(self_value(),"sleep");Args args_166;args_166.pos(attr(self_value(),"ENHANCED_HEAVY_INTERVAL"));args_166.kw("check_combat",V(false));return invoke(fn_167,args_166);}());
        // Lucy.py:120
        ([&]()->V{auto fn_169=attr(self_value(),"heavy_attack");Args args_168;args_168.pos(attr(self_value(),"HEAVY_ATTACK_DURATION"));return invoke(fn_169,args_168);}());
        // Lucy.py:121
        ([&]()->V{auto fn_171=attr(attr(self_value(),"logger"),"info");Args args_170;args_170.pos(V("Lucy perform enhanced heavy attack 2"));return invoke(fn_171,args_170);}());
    }
return V{};
}),false);
// Official method Lucy.get_switch_priority, lines 123-126
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_172=bind_arguments(official_args,signature,captured);
    // Lucy.py:124
    if(([&]()->V{V operand_173;operand_173=scope_172->get("has_intro");if(!operand_173.truth())return operand_173;operand_173=scope_172->get("current_char");if(!operand_173.truth())return operand_173;return ([&]()->V{V compare_174=attr(scope_172->get("current_char"),"char_name");V compare_175;V comparison_result_176;compare_175=V::set({V("char_rebecca")});comparison_result_176=compare_value("in",compare_174,compare_175);return comparison_result_176;}());}()).truth()){
        // Lucy.py:125
        return attr(global("SwitchPriority","Lucy"),"MUST");
    }
    // Lucy.py:126
    return ([&]()->V{auto fn_180=attr(([&]()->V{auto fn_178=global("super","Lucy");Args args_177;return invoke(fn_178,args_177);}()),"get_switch_priority");Args args_179;args_179.pos(scope_172->get("current_char"));args_179.pos(scope_172->get("has_intro"));args_179.pos(scope_172->get("target_low_con"));return invoke(fn_180,args_179);}());
return V{};
}),false);
}
