// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Rebecca.py
// SHA256 9723d296e1523205a033f16c1a964c7dbf55c946797be18951c6a3eafefb6bd0
void OfficialCharacter::install_Rebecca(){
auto scope=std::make_shared<Scope>();
set_class_attribute("LIB_HOLD_DURATION",V(5.2));
set_class_attribute("LIB_ENTER_DURATION",V(0.8));
set_class_attribute("LIB_REENTER_WINDOW",V(17.0));
set_class_attribute("NORMAL_ATTACK_DURATION",V(0.5));
set_class_attribute("ATTACK_DURATION",V(1.0));
set_class_attribute("ATTACK_TIMEOUT",V(2.2));
// Official method Rebecca.__init__, lines 15-18
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Rebecca.py:16
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Rebecca");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Rebecca.py:17
    {V value_6=V(false);set_attr(self_value(),"check_f_on_switch",value_6);}
    // Rebecca.py:18
    {V value_7=unary("-",V(999.0));set_attr(self_value(),"_last_liberation_at",value_7);}
return V{};
}),false);
// Official method Rebecca._in_reenter_window, lines 20-21
register_method("_in_reenter_window",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Rebecca.py:21
    return ([&]()->V{V compare_9=([&]()->V{V left_11=([&]()->V{auto fn_14=attr(global("time","Rebecca"),"time");Args args_13;return invoke(fn_14,args_13);}());V right_12=attr(self_value(),"_last_liberation_at");return official::binary("-",left_11,right_12);}());V compare_10;V comparison_result_15;compare_10=attr(self_value(),"LIB_REENTER_WINDOW");comparison_result_15=compare_value("<",compare_9,compare_10);return comparison_result_15;}());
return V{};
}),false);
// Official method Rebecca.do_perform, lines 23-31
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_16=bind_arguments(official_args,signature,captured);
scope_16->set("start",V::missing());
    // Rebecca.py:24
    if(([&]()->V{auto fn_18=attr(self_value(),"perform_combat");Args args_17;return invoke(fn_18,args_17);}()).truth()){
        // Rebecca.py:26
        if(([&]()->V{auto fn_20=attr(self_value(),"_in_reenter_window");Args args_19;return invoke(fn_20,args_19);}()).truth()){
            // Rebecca.py:27
            {V value_21=([&]()->V{auto fn_23=attr(global("time","Rebecca"),"time");Args args_22;return invoke(fn_23,args_22);}());scope_16->set("start",value_21);}
            // Rebecca.py:28
                        while(([&]()->V{V operand_28;operand_28=unary("not",([&]()->V{auto fn_30=attr(self_value(),"is_con_full");Args args_29;return invoke(fn_30,args_29);}()));if(!operand_28.truth())return operand_28;return ([&]()->V{V compare_31=([&]()->V{V left_33=([&]()->V{auto fn_36=attr(global("time","Rebecca"),"time");Args args_35;return invoke(fn_36,args_35);}());V right_34=scope_16->get("start");return official::binary("-",left_33,right_34);}());V compare_32;V comparison_result_37;compare_32=attr(self_value(),"ATTACK_TIMEOUT");comparison_result_37=compare_value("<",compare_31,compare_32);return comparison_result_37;}());}()).truth()){
                // Rebecca.py:29
                ([&]()->V{auto fn_25=attr(self_value(),"continues_normal_attack");Args args_24;args_24.pos(attr(self_value(),"ATTACK_DURATION"));return invoke(fn_25,args_24);}());
                // Rebecca.py:30
                ([&]()->V{auto fn_27=attr(global("time","Rebecca"),"sleep");Args args_26;args_26.pos(V(0.1));return invoke(fn_27,args_26);}());
            }
        }
        // Rebecca.py:31
        return ([&]()->V{auto fn_39=attr(self_value(),"switch_next_char");Args args_38;return invoke(fn_39,args_38);}());
    }
return V{};
}),false);
// Official method Rebecca.perform_combat, lines 33-41
register_method("perform_combat",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_40=bind_arguments(official_args,signature,captured);
    // Rebecca.py:35
    if(([&]()->V{auto fn_42=attr(self_value(),"_in_reenter_window");Args args_41;return invoke(fn_42,args_41);}()).truth()){
        // Rebecca.py:36
        ([&]()->V{auto fn_44=attr(self_value(),"click_resonance");Args args_43;return invoke(fn_44,args_43);}());
        // Rebecca.py:37
        ([&]()->V{auto fn_46=attr(self_value(),"continues_normal_attack");Args args_45;args_45.pos(attr(self_value(),"NORMAL_ATTACK_DURATION"));return invoke(fn_46,args_45);}());
        // Rebecca.py:38
        return V(true);
    }
    // Rebecca.py:40
    ([&]()->V{auto fn_48=attr(self_value(),"_build_forte_sequence");Args args_47;return invoke(fn_48,args_47);}());
    // Rebecca.py:41
    return V(true);
return V{};
}),false);
// Official method Rebecca._build_forte_sequence, lines 43-76
register_method("_build_forte_sequence",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_49=bind_arguments(official_args,signature,captured);
scope_49->set("wait_start",V::missing());
    // Rebecca.py:45
    if(attr(self_value(),"has_intro").truth()){
        // Rebecca.py:46
        ([&]()->V{auto fn_51=attr(self_value(),"continues_normal_attack");Args args_50;args_50.pos(V(1.3));return invoke(fn_51,args_50);}());
    }else{
        // Rebecca.py:48
        ([&]()->V{auto fn_53=attr(self_value(),"continues_normal_attack");Args args_52;args_52.pos(V(1.8));return invoke(fn_53,args_52);}());
    }
    // Rebecca.py:50
    if(attr(self_value(),"has_intro").truth()){
        // Rebecca.py:51
        ([&]()->V{auto fn_55=attr(attr(self_value(),"task"),"wait_until");Args args_54;args_54.pos(V::function([this,captured=capture_scope(scope_49,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_56=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_58=attr(self_value(),"resonance_available");Args args_57;return invoke(fn_58,args_57);}());
}));args_54.pos(V(2LL));return invoke(fn_55,args_54);}());
        // Rebecca.py:52
        ([&]()->V{auto fn_60=attr(self_value(),"click_resonance");Args args_59;args_59.kw("post_sleep",V(1.5));return invoke(fn_60,args_59);}());
        // Rebecca.py:53
        ([&]()->V{auto fn_62=attr(self_value(),"click_resonance");Args args_61;args_61.kw("post_sleep",V(1.5));return invoke(fn_62,args_61);}());
    }else{
        // Rebecca.py:55
        ([&]()->V{auto fn_64=attr(attr(self_value(),"task"),"wait_until");Args args_63;args_63.pos(V::function([this,captured=capture_scope(scope_49,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_65=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_67=attr(self_value(),"resonance_available");Args args_66;return invoke(fn_67,args_66);}());
}));args_63.pos(V(2LL));return invoke(fn_64,args_63);}());
        // Rebecca.py:56
        ([&]()->V{auto fn_69=attr(self_value(),"click_resonance");Args args_68;args_68.kw("post_sleep",V(1.5));return invoke(fn_69,args_68);}());
        // Rebecca.py:57
        ([&]()->V{auto fn_71=attr(self_value(),"click_resonance");Args args_70;args_70.kw("post_sleep",V(1.5));return invoke(fn_71,args_70);}());
        // Rebecca.py:58
        ([&]()->V{auto fn_73=attr(self_value(),"click_resonance");Args args_72;args_72.kw("post_sleep",V(1LL));return invoke(fn_73,args_72);}());
    }
    // Rebecca.py:61
    ([&]()->V{auto fn_75=attr(self_value(),"send_resonance_key");Args args_74;return invoke(fn_75,args_74);}());
    // Rebecca.py:62
    {V value_76=([&]()->V{auto fn_78=attr(global("time","Rebecca"),"time");Args args_77;return invoke(fn_78,args_77);}());scope_49->set("wait_start",value_76);}
    // Rebecca.py:63
        while(([&]()->V{V operand_87;operand_87=unary("not",([&]()->V{auto fn_89=attr(self_value(),"is_mouse_forte_full");Args args_88;return invoke(fn_89,args_88);}()));if(!operand_87.truth())return operand_87;return ([&]()->V{V compare_90=([&]()->V{V left_92=([&]()->V{auto fn_95=attr(global("time","Rebecca"),"time");Args args_94;return invoke(fn_95,args_94);}());V right_93=scope_49->get("wait_start");return official::binary("-",left_92,right_93);}());V compare_91;V comparison_result_96;compare_91=V(4.0);comparison_result_96=compare_value("<",compare_90,compare_91);return comparison_result_96;}());}()).truth()){
        // Rebecca.py:64
        ([&]()->V{auto fn_80=attr(attr(self_value(),"task"),"click");Args args_79;return invoke(fn_80,args_79);}());
        // Rebecca.py:65
        ([&]()->V{auto fn_82=attr(self_value(),"sleep");Args args_81;args_81.pos(V(0.1));return invoke(fn_82,args_81);}());
        // Rebecca.py:66
        if(([&]()->V{auto fn_84=global("hasattr","Rebecca");Args args_83;args_83.pos(attr(self_value(),"task"));args_83.pos(V("next_frame"));return invoke(fn_84,args_83);}()).truth()){
            // Rebecca.py:67
            {
            try{
                // Rebecca.py:68
                ([&]()->V{auto fn_86=attr(attr(self_value(),"task"),"next_frame");Args args_85;return invoke(fn_86,args_85);}());
            }catch(const std::exception& official_exception){
                rethrow_control_exception(official_exception);
            }
            }
        }
    }
    // Rebecca.py:72
    if(([&]()->V{auto fn_98=attr(self_value(),"is_mouse_forte_full");Args args_97;return invoke(fn_98,args_97);}()).truth()){
        // Rebecca.py:73
        ([&]()->V{auto fn_100=attr(self_value(),"heavy_attack");Args args_99;args_99.pos(V(1.5));return invoke(fn_100,args_99);}());
    }
    // Rebecca.py:75
    ([&]()->V{auto fn_102=attr(self_value(),"click_echo");Args args_101;return invoke(fn_102,args_101);}());
    // Rebecca.py:76
    ([&]()->V{auto fn_104=attr(self_value(),"perform_hmg_mode");Args args_103;return invoke(fn_104,args_103);}());
return V{};
}),false);
// Official method Rebecca.perform_enhanced_heavy, lines 78-81
register_method("perform_enhanced_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_105=bind_arguments(official_args,signature,captured);
    // Rebecca.py:80
    if(([&]()->V{auto fn_107=attr(self_value(),"is_mouse_forte_full");Args args_106;return invoke(fn_107,args_106);}()).truth()){
        // Rebecca.py:81
        ([&]()->V{auto fn_109=attr(self_value(),"heavy_attack");Args args_108;args_108.pos(V(0.5));return invoke(fn_109,args_108);}());
    }
return V{};
}),false);
// Official method Rebecca.perform_hmg_mode, lines 83-99
register_method("perform_hmg_mode",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_110=bind_arguments(official_args,signature,captured);
scope_110->set("enter_start",V::missing());
scope_110->set("last_liberation",V::missing());
scope_110->set("now",V::missing());
scope_110->set("start",V::missing());
    // Rebecca.py:84
    {V value_111=([&]()->V{auto fn_113=attr(global("time","Rebecca"),"time");Args args_112;return invoke(fn_113,args_112);}());scope_110->set("enter_start",value_111);}
    // Rebecca.py:85
        while(([&]()->V{V compare_118=([&]()->V{V left_120=([&]()->V{auto fn_123=attr(global("time","Rebecca"),"time");Args args_122;return invoke(fn_123,args_122);}());V right_121=scope_110->get("enter_start");return official::binary("-",left_120,right_121);}());V compare_119;V comparison_result_124;compare_119=attr(self_value(),"LIB_ENTER_DURATION");comparison_result_124=compare_value("<",compare_118,compare_119);return comparison_result_124;}()).truth()){
        // Rebecca.py:86
        ([&]()->V{auto fn_115=attr(self_value(),"send_liberation_key");Args args_114;return invoke(fn_115,args_114);}());
        // Rebecca.py:87
        ([&]()->V{auto fn_117=attr(self_value(),"sleep");Args args_116;args_116.pos(V(0.1));args_116.kw("check_combat",V(false));return invoke(fn_117,args_116);}());
    }
    // Rebecca.py:88
    ([&]()->V{auto fn_126=attr(self_value(),"record_liberation_use");Args args_125;return invoke(fn_126,args_125);}());
    // Rebecca.py:89
    {V value_127=([&]()->V{auto fn_129=attr(global("time","Rebecca"),"time");Args args_128;return invoke(fn_129,args_128);}());scope_110->set("start",value_127);}
    // Rebecca.py:90
    {V value_130=([&]()->V{auto fn_132=attr(global("time","Rebecca"),"time");Args args_131;return invoke(fn_132,args_131);}());scope_110->set("last_liberation",value_130);}
    // Rebecca.py:91
        while(([&]()->V{V compare_148=([&]()->V{V left_150=([&]()->V{auto fn_153=attr(global("time","Rebecca"),"time");Args args_152;return invoke(fn_153,args_152);}());V right_151=scope_110->get("start");return official::binary("-",left_150,right_151);}());V compare_149;V comparison_result_154;compare_149=attr(self_value(),"LIB_HOLD_DURATION");comparison_result_154=compare_value("<",compare_148,compare_149);return comparison_result_154;}()).truth()){
        // Rebecca.py:92
        ([&]()->V{auto fn_134=attr(self_value(),"click");Args args_133;args_133.kw("interval",V(0.08));return invoke(fn_134,args_133);}());
        // Rebecca.py:93
        {V value_135=([&]()->V{auto fn_137=attr(global("time","Rebecca"),"time");Args args_136;return invoke(fn_137,args_136);}());scope_110->set("now",value_135);}
        // Rebecca.py:94
        if(([&]()->V{V compare_138=([&]()->V{V left_140=scope_110->get("now");V right_141=scope_110->get("last_liberation");return official::binary("-",left_140,right_141);}());V compare_139;V comparison_result_142;compare_139=V(0.9);comparison_result_142=compare_value(">",compare_138,compare_139);return comparison_result_142;}()).truth()){
            // Rebecca.py:95
            ([&]()->V{auto fn_144=attr(self_value(),"send_liberation_key");Args args_143;return invoke(fn_144,args_143);}());
            // Rebecca.py:96
            {V value_145=scope_110->get("now");scope_110->set("last_liberation",value_145);}
        }
        // Rebecca.py:97
        ([&]()->V{auto fn_147=attr(self_value(),"sleep");Args args_146;args_146.pos(V(0.01));args_146.kw("check_combat",V(false));return invoke(fn_147,args_146);}());
    }
    // Rebecca.py:99
    {V value_155=([&]()->V{auto fn_157=attr(global("time","Rebecca"),"time");Args args_156;return invoke(fn_157,args_156);}());set_attr(self_value(),"_last_liberation_at",value_155);}
return V{};
}),false);
}
