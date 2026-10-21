#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Chisa.py
// SHA256 f999ebc80ee669fcdd378c58985743118cd77d87e4b52b1e7b57a249c14ca2a3
void OfficialCharacter::install_Chisa(){
auto scope=std::make_shared<Scope>();
set_class_attribute("SUPPORT_ACTION_DURATION",V(1.2));
set_class_attribute("SUPPORT_LONG_ACTION_DURATION",V(10.0));
set_class_attribute("INTRO_NORMAL_ATTACK_DURATION",V(2.0));
// Official method Chisa.is_dps_config, lines 11-12
register_method("is_dps_config",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Chisa.py:12
    return ([&]()->V{V operand_2;operand_2=attr(self_value(),"task");if(!operand_2.truth())return operand_2;return ([&]()->V{auto fn_4=attr(attr(attr(self_value(),"task"),"char_config"),"get");Args args_3;args_3.pos(V("Chisa DPS"));return invoke(fn_4,args_3);}());}());
return V{};
}),false);
// Official method Chisa.get_char_type, lines 14-17
register_method("get_char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_5=bind_arguments(official_args,signature,captured);
    // Chisa.py:15
    if(([&]()->V{auto fn_7=attr(self_value(),"is_dps_config");Args args_6;return invoke(fn_7,args_6);}()).truth()){
        // Chisa.py:16
        return attr(global("CharType","Chisa"),"MAIN_DPS");
    }
    // Chisa.py:17
    return ([&]()->V{auto fn_11=attr(([&]()->V{auto fn_9=global("super","Chisa");Args args_8;return invoke(fn_9,args_8);}()),"get_char_type");Args args_10;return invoke(fn_11,args_10);}());
return V{};
}),false);
// Official method Chisa.get_buff_time, lines 19-22
register_method("get_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
    // Chisa.py:20
    if(([&]()->V{auto fn_14=attr(self_value(),"is_dps_config");Args args_13;return invoke(fn_14,args_13);}()).truth()){
        // Chisa.py:21
        return ([&]()->V{auto fn_16=global("get_default_buff_time","Chisa");Args args_15;args_15.pos(attr(global("CharType","Chisa"),"MAIN_DPS"));return invoke(fn_16,args_15);}());
    }
    // Chisa.py:22
    return ([&]()->V{auto fn_20=attr(([&]()->V{auto fn_18=global("super","Chisa");Args args_17;return invoke(fn_18,args_17);}()),"get_buff_time");Args args_19;return invoke(fn_20,args_19);}());
return V{};
}),false);
// Official method Chisa.do_perform, lines 24-27
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
    // Chisa.py:25
    if(([&]()->V{auto fn_23=attr(self_value(),"is_dps_config");Args args_22;return invoke(fn_23,args_22);}()).truth()){
        // Chisa.py:26
        return ([&]()->V{auto fn_25=attr(self_value(),"do_dps_perform");Args args_24;return invoke(fn_25,args_24);}());
    }
    // Chisa.py:27
    return ([&]()->V{auto fn_27=attr(self_value(),"do_support_perform");Args args_26;return invoke(fn_27,args_26);}());
return V{};
}),false);
// Official method Chisa.do_support_perform, lines 29-56
register_method("do_support_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_28=bind_arguments(official_args,signature,captured);
scope_28->set("duration",V::missing());
scope_28->set("needs_long_actions",V::missing());
scope_28->set("start",V::missing());
    // Chisa.py:30
    {V value_29=([&]()->V{V operand_30;operand_30=attr(self_value(),"has_intro");if(!operand_30.truth())return operand_30;return unary("not",([&]()->V{auto fn_32=attr(self_value(),"has_buff");Args args_31;return invoke(fn_32,args_31);}()));}());scope_28->set("needs_long_actions",value_29);}
    // Chisa.py:31
    if(attr(self_value(),"has_intro").truth()){
        // Chisa.py:32
        ([&]()->V{auto fn_34=attr(self_value(),"continues_normal_attack");Args args_33;args_33.pos(attr(self_value(),"INTRO_NORMAL_ATTACK_DURATION"));return invoke(fn_34,args_33);}());
    }
    // Chisa.py:34
    {V value_35=(scope_28->get("needs_long_actions").truth()?attr(self_value(),"SUPPORT_LONG_ACTION_DURATION"):attr(self_value(),"SUPPORT_ACTION_DURATION"));scope_28->set("duration",value_35);}
    // Chisa.py:36
    if(([&]()->V{V operand_36;operand_36=([&]()->V{auto fn_38=attr(self_value(),"flying");Args args_37;return invoke(fn_38,args_37);}());if(!operand_36.truth())return operand_36;operand_36=unary("not",([&]()->V{auto fn_40=attr(self_value(),"liberation_available");Args args_39;return invoke(fn_40,args_39);}()));if(!operand_36.truth())return operand_36;return unary("not",([&]()->V{auto fn_42=attr(self_value(),"resonance_available");Args args_41;return invoke(fn_42,args_41);}()));}()).truth()){
        // Chisa.py:37
        ([&]()->V{auto fn_44=attr(self_value(),"wait_down");Args args_43;return invoke(fn_44,args_43);}());
    }
    // Chisa.py:38
    ([&]()->V{auto fn_46=attr(self_value(),"click_echo");Args args_45;args_45.kw("time_out",V(0LL));return invoke(fn_46,args_45);}());
    // Chisa.py:40
    {V value_47=([&]()->V{auto fn_49=attr(global("time","Chisa"),"time");Args args_48;return invoke(fn_49,args_48);}());scope_28->set("start",value_47);}
    // Chisa.py:41
        while(([&]()->V{V compare_70=([&]()->V{auto fn_73=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_72;args_72.pos(scope_28->get("start"));return invoke(fn_73,args_72);}());V compare_71;V comparison_result_74;compare_71=scope_28->get("duration");comparison_result_74=compare_value("<",compare_70,compare_71);return comparison_result_74;}()).truth()){
        // Chisa.py:42
        ([&]()->V{auto fn_51=attr(self_value(),"cycle_start");Args args_50;return invoke(fn_51,args_50);}());
        // Chisa.py:43
        if(([&]()->V{auto fn_53=attr(self_value(),"is_con_full");Args args_52;return invoke(fn_53,args_52);}()).truth()){
            // Chisa.py:44
            return ([&]()->V{auto fn_55=attr(self_value(),"switch_next_char");Args args_54;return invoke(fn_55,args_54);}());
        }
        // Chisa.py:45
        if(([&]()->V{auto fn_57=attr(self_value(),"liberation_available");Args args_56;return invoke(fn_57,args_56);}()).truth()){
            // Chisa.py:46
            ([&]()->V{auto fn_59=attr(self_value(),"click_liberation");Args args_58;args_58.kw("wait_if_cd_ready",V(0LL));return invoke(fn_59,args_58);}());
        }else{
            // Chisa.py:47
            if(([&]()->V{auto fn_61=attr(self_value(),"is_forte_full");Args args_60;return invoke(fn_61,args_60);}()).truth()){
                // Chisa.py:48
                if(([&]()->V{auto fn_63=attr(self_value(),"perform_forte");Args args_62;return invoke(fn_63,args_62);}()).truth()){
                    // Chisa.py:49
                    break;
                }
            }else{
                // Chisa.py:50
                if(item(([&]()->V{auto fn_65=attr(self_value(),"click_resonance");Args args_64;args_64.kw("time_out",V(0LL));return invoke(fn_65,args_64);}()),V(0LL)).truth()){
                }else{
                    // Chisa.py:53
                    ([&]()->V{auto fn_67=attr(self_value(),"click");Args args_66;return invoke(fn_67,args_66);}());
                }
            }
        }
        // Chisa.py:54
        ([&]()->V{auto fn_69=attr(self_value(),"cycle_sleep");Args args_68;return invoke(fn_69,args_68);}());
    }
    // Chisa.py:56
    return ([&]()->V{auto fn_76=attr(self_value(),"switch_next_char");Args args_75;return invoke(fn_76,args_75);}());
return V{};
}),false);
// Official method Chisa.do_dps_perform, lines 58-85
register_method("do_dps_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_77=bind_arguments(official_args,signature,captured);
scope_77->set("start",V::missing());
scope_77->set("timeout",V::missing());
scope_77->set("under_liber",V::missing());
    // Chisa.py:59
    {V value_78=V(2.5);scope_77->set("timeout",value_78);}
    // Chisa.py:60
    {V value_79=V(true);set_attr(self_value(),"check_f_on_switch",value_79);}
    // Chisa.py:61
    if(attr(self_value(),"has_intro").truth()){
        // Chisa.py:62
        ([&]()->V{auto fn_81=attr(self_value(),"continues_normal_attack");Args args_80;args_80.pos(V(0.8));return invoke(fn_81,args_80);}());
        // Chisa.py:63
        {V value_82=V(2.3);scope_77->set("timeout",value_82);}
    }
    // Chisa.py:64
    if(([&]()->V{V operand_83;operand_83=([&]()->V{auto fn_85=attr(self_value(),"flying");Args args_84;return invoke(fn_85,args_84);}());if(!operand_83.truth())return operand_83;operand_83=unary("not",([&]()->V{auto fn_87=attr(self_value(),"liberation_available");Args args_86;return invoke(fn_87,args_86);}()));if(!operand_83.truth())return operand_83;return unary("not",([&]()->V{auto fn_89=attr(self_value(),"resonance_available");Args args_88;return invoke(fn_89,args_88);}()));}()).truth()){
        // Chisa.py:65
        ([&]()->V{auto fn_91=attr(self_value(),"wait_down");Args args_90;return invoke(fn_91,args_90);}());
    }
    // Chisa.py:66
    ([&]()->V{auto fn_93=attr(self_value(),"click_echo");Args args_92;return invoke(fn_93,args_92);}());
    // Chisa.py:67
    {V value_94=([&]()->V{auto fn_96=attr(global("time","Chisa"),"time");Args args_95;return invoke(fn_96,args_95);}());scope_77->set("start",value_94);}
    // Chisa.py:68
    {V value_97=V(false);scope_77->set("under_liber",value_97);}
    // Chisa.py:69
        while(([&]()->V{V compare_151=([&]()->V{V left_153=([&]()->V{auto fn_156=attr(global("time","Chisa"),"time");Args args_155;return invoke(fn_156,args_155);}());V right_154=scope_77->get("start");return official::binary("-",left_153,right_154);}());V compare_152;V comparison_result_157;compare_152=scope_77->get("timeout");comparison_result_157=compare_value("<",compare_151,compare_152);return comparison_result_157;}()).truth()){
        // Chisa.py:70
        if(([&]()->V{V operand_98;operand_98=([&]()->V{V compare_99=([&]()->V{V left_101=([&]()->V{auto fn_104=attr(global("time","Chisa"),"time");Args args_103;return invoke(fn_104,args_103);}());V right_102=scope_77->get("start");return official::binary("-",left_101,right_102);}());V compare_100;V comparison_result_105;compare_100=V(0.5);comparison_result_105=compare_value("<",compare_99,compare_100);return comparison_result_105;}());if(!operand_98.truth())return operand_98;return ([&]()->V{auto fn_107=attr(self_value(),"click_liberation");Args args_106;return invoke(fn_107,args_106);}());}()).truth()){
            // Chisa.py:71
            {V value_108=([&]()->V{auto fn_110=attr(global("time","Chisa"),"time");Args args_109;return invoke(fn_110,args_109);}());scope_77->set("start",value_108);}
            // Chisa.py:72
            {V value_111=V(true);scope_77->set("under_liber",value_111);}
            // Chisa.py:73
            {V value_112=V(10LL);scope_77->set("timeout",value_112);}
            // Chisa.py:74
            ([&]()->V{auto fn_114=attr(self_value(),"sleep");Args args_113;args_113.pos(V(0.2));return invoke(fn_114,args_113);}());
        }
        // Chisa.py:75
        if(([&]()->V{V operand_115;operand_115=([&]()->V{V compare_116=([&]()->V{V left_118=([&]()->V{auto fn_121=attr(global("time","Chisa"),"time");Args args_120;return invoke(fn_121,args_120);}());V right_119=scope_77->get("start");return official::binary("-",left_118,right_119);}());V compare_117;V comparison_result_122;compare_117=V(0.5);comparison_result_122=compare_value("<",compare_116,compare_117);return comparison_result_122;}());if(!operand_115.truth())return operand_115;operand_115=unary("not",([&]()->V{auto fn_124=attr(self_value(),"is_forte_full");Args args_123;return invoke(fn_124,args_123);}()));if(!operand_115.truth())return operand_115;return item(([&]()->V{auto fn_126=attr(self_value(),"click_resonance");Args args_125;return invoke(fn_126,args_125);}()),V(0LL));}()).truth()){
            // Chisa.py:76
            {V value_127=([&]()->V{auto fn_129=attr(global("time","Chisa"),"time");Args args_128;return invoke(fn_129,args_128);}());scope_77->set("start",value_127);}
            // Chisa.py:77
            if(([&]()->V{V compare_130=scope_77->get("timeout");V compare_131;V comparison_result_132;compare_131=V(10LL);comparison_result_132=compare_value("!=",compare_130,compare_131);return comparison_result_132;}()).truth()){
                // Chisa.py:78
                {V value_133=V(1.7);scope_77->set("timeout",value_133);}
            }
        }
        // Chisa.py:79
        if(([&]()->V{V operand_134;operand_134=([&]()->V{V operand_135;operand_135=scope_77->get("under_liber");if(operand_135.truth())return operand_135;return ([&]()->V{auto fn_137=attr(self_value(),"is_dps_config");Args args_136;return invoke(fn_137,args_136);}());}());if(!operand_134.truth())return operand_134;operand_134=([&]()->V{auto fn_139=attr(self_value(),"is_forte_full");Args args_138;return invoke(fn_139,args_138);}());if(!operand_134.truth())return operand_134;return ([&]()->V{auto fn_141=attr(self_value(),"perform_forte");Args args_140;return invoke(fn_141,args_140);}());}()).truth()){
            // Chisa.py:80
            {V value_142=V(false);set_attr(self_value(),"check_f_on_switch",value_142);}
            // Chisa.py:81
            return ([&]()->V{auto fn_144=attr(self_value(),"switch_next_char");Args args_143;return invoke(fn_144,args_143);}());
        }
        // Chisa.py:82
        ([&]()->V{auto fn_146=attr(self_value(),"click");Args args_145;return invoke(fn_146,args_145);}());
        // Chisa.py:83
        ([&]()->V{auto fn_148=attr(self_value(),"check_combat");Args args_147;return invoke(fn_148,args_147);}());
        // Chisa.py:84
        ([&]()->V{auto fn_150=attr(attr(self_value(),"task"),"next_frame");Args args_149;return invoke(fn_150,args_149);}());
    }
    // Chisa.py:85
    ([&]()->V{auto fn_159=attr(self_value(),"switch_next_char");Args args_158;return invoke(fn_159,args_158);}());
return V{};
}),false);
// Official method Chisa.perform_forte, lines 87-94
register_method("perform_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_160=bind_arguments(official_args,signature,captured);
    // Chisa.py:88
    if(([&]()->V{auto fn_162=attr(self_value(),"flying");Args args_161;return invoke(fn_162,args_161);}()).truth()){
        // Chisa.py:89
        ([&]()->V{auto fn_164=attr(self_value(),"wait_down");Args args_163;return invoke(fn_164,args_163);}());
    }
    // Chisa.py:90
    ([&]()->V{auto fn_166=attr(attr(self_value(),"task"),"send_key");Args args_165;args_165.pos(([&]()->V{auto fn_168=attr(self_value(),"get_resonance_key");Args args_167;return invoke(fn_168,args_167);}()));args_165.kw("down_time",V(1.2));return invoke(fn_166,args_165);}());
    // Chisa.py:91
    if(([&]()->V{auto fn_170=attr(self_value(),"is_forte_full");Args args_169;return invoke(fn_170,args_169);}()).truth()){
        // Chisa.py:92
        return V(false);
    }
    // Chisa.py:93
    ([&]()->V{auto fn_172=attr(self_value(),"heavy_attack");Args args_171;args_171.pos(V(3.5));return invoke(fn_172,args_171);}());
    // Chisa.py:94
    return V(true);
return V{};
}),false);
}
}
