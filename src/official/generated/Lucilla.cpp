#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Lucilla.py
// SHA256 ee233cfa1a2da8d696e5917111dabbefd8c06b8090f64b6cec4a79a60f877634
void OfficialCharacter::install_Lucilla(){
auto scope=std::make_shared<Scope>();
set_class_attribute("HOLD_TIME",V(1.4));
set_class_attribute("LIBERATION_ANIMATION_TIME",V(3.0));
set_class_attribute("LIBERATION_HEAVY_TIME",V(15.0));
set_class_attribute("HEAVY_PULSE_TIME",V(0.6));
set_class_attribute("CHARGE_TIME_OUT",V(7.2));
set_class_attribute("LIBERATION_CD_SKIP",V(1.5));
set_class_attribute("SWITCH_IN_SETTLE",V(0.5));
// Official method Lucilla.do_perform, lines 20-22
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Lucilla.py:21
    if(unary("not",([&]()->V{auto fn_3=attr(self_value(),"perform_combat");Args args_2;return invoke(fn_3,args_2);}())).truth()){
        // Lucilla.py:22
        ([&]()->V{auto fn_5=attr(self_value(),"switch_next_char");Args args_4;return invoke(fn_5,args_4);}());
    }
return V{};
}),false);
// Official method Lucilla.perform_combat, lines 24-55
register_method("perform_combat",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_6=bind_arguments(official_args,signature,captured);
scope_6->set("start",V::missing());
    // Lucilla.py:30
    {V value_7=([&]()->V{auto fn_9=attr(global("time","Lucilla"),"time");Args args_8;return invoke(fn_9,args_8);}());scope_6->set("start",value_7);}
    // Lucilla.py:32
    ([&]()->V{auto fn_11=attr(attr(self_value(),"task"),"wait_until");Args args_10;args_10.pos(V::function([this,captured=capture_scope(scope_6,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_14=attr(attr(self_value(),"task"),"in_team");Args args_13;return invoke(fn_14,args_13);}()),V(0LL));
}));args_10.kw("time_out",V(0.8));return invoke(fn_11,args_10);}());
    // Lucilla.py:33
    ([&]()->V{auto fn_16=attr(self_value(),"sleep");Args args_15;args_15.pos(attr(self_value(),"SWITCH_IN_SETTLE"));args_15.kw("check_combat",V(false));return invoke(fn_16,args_15);}());
    // Lucilla.py:34
    ([&]()->V{auto fn_18=attr(attr(self_value(),"task"),"next_frame");Args args_17;return invoke(fn_18,args_17);}());
    // Lucilla.py:36
    if(([&]()->V{auto fn_20=attr(self_value(),"try_liberation");Args args_19;return invoke(fn_20,args_19);}()).truth()){
        // Lucilla.py:37
        return V(true);
    }
    // Lucilla.py:39
        while(([&]()->V{V compare_42=([&]()->V{V left_44=([&]()->V{auto fn_47=attr(global("time","Lucilla"),"time");Args args_46;return invoke(fn_47,args_46);}());V right_45=scope_6->get("start");return official::binary("-",left_44,right_45);}());V compare_43;V comparison_result_48;compare_43=attr(self_value(),"CHARGE_TIME_OUT");comparison_result_48=compare_value("<",compare_42,compare_43);return comparison_result_48;}()).truth()){
        // Lucilla.py:41
        if(([&]()->V{V operand_21;operand_21=([&]()->V{auto fn_23=attr(self_value(),"energy_full");Args args_22;return invoke(fn_23,args_22);}());if(!operand_21.truth())return operand_21;return unary("not",([&]()->V{auto fn_25=attr(self_value(),"liberation_available");Args args_24;return invoke(fn_25,args_24);}()));}()).truth()){
            // Lucilla.py:42
            ([&]()->V{auto fn_27=attr(attr(self_value(),"logger"),"info");Args args_26;args_26.pos(V("Lucilla energy full but liberation not castable, switch"));return invoke(fn_27,args_26);}());
            // Lucilla.py:43
            break;
        }
        // Lucilla.py:46
        if(([&]()->V{V operand_28;operand_28=unary("not",([&]()->V{auto fn_30=attr(self_value(),"liberation_available");Args args_29;return invoke(fn_30,args_29);}()));if(!operand_28.truth())return operand_28;return ([&]()->V{V compare_31=([&]()->V{auto fn_34=attr(attr(self_value(),"task"),"get_cd");Args args_33;args_33.pos(V("liberation"));return invoke(fn_34,args_33);}());V compare_32;V comparison_result_35;compare_32=attr(self_value(),"LIBERATION_CD_SKIP");comparison_result_35=compare_value(">",compare_31,compare_32);return comparison_result_35;}());}()).truth()){
            // Lucilla.py:47
            ([&]()->V{auto fn_37=attr(attr(self_value(),"logger"),"info");Args args_36;args_36.pos(V("Lucilla liberation on long cd, switch to save time"));return invoke(fn_37,args_36);}());
            // Lucilla.py:48
            break;
        }
        // Lucilla.py:50
        if(([&]()->V{auto fn_39=attr(self_value(),"try_liberation");Args args_38;return invoke(fn_39,args_38);}()).truth()){
            // Lucilla.py:51
            return V(true);
        }
        // Lucilla.py:53
        ([&]()->V{auto fn_41=attr(self_value(),"charge_once");Args args_40;return invoke(fn_41,args_40);}());
    }
    // Lucilla.py:55
    return V(false);
return V{};
}),false);
// Official method Lucilla.charge_once, lines 57-64
register_method("charge_once",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_49=bind_arguments(official_args,signature,captured);
    // Lucilla.py:60
    if(([&]()->V{auto fn_51=attr(self_value(),"resonance_available");Args args_50;return invoke(fn_51,args_50);}()).truth()){
        // Lucilla.py:61
        ([&]()->V{auto fn_53=attr(self_value(),"hold_resonance");Args args_52;args_52.pos(attr(self_value(),"HOLD_TIME"));return invoke(fn_53,args_52);}());
    }else{
        // Lucilla.py:63
        ([&]()->V{auto fn_55=attr(self_value(),"heavy_attack");Args args_54;args_54.pos(attr(self_value(),"HOLD_TIME"));return invoke(fn_55,args_54);}());
    }
    // Lucilla.py:64
    ([&]()->V{auto fn_57=attr(attr(self_value(),"task"),"next_frame");Args args_56;return invoke(fn_57,args_56);}());
return V{};
}),false);
// Official method Lucilla.try_liberation, lines 66-80
register_method("try_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_58=bind_arguments(official_args,signature,captured);
    // Lucilla.py:72
    if(unary("not",([&]()->V{auto fn_60=attr(self_value(),"liberation_available");Args args_59;return invoke(fn_60,args_59);}())).truth()){
        // Lucilla.py:73
        return V(false);
    }
    // Lucilla.py:75
    if(([&]()->V{auto fn_62=attr(self_value(),"echo_available");Args args_61;return invoke(fn_62,args_61);}()).truth()){
        // Lucilla.py:76
        ([&]()->V{auto fn_64=attr(self_value(),"click_echo");Args args_63;args_63.kw("time_out",V(0LL));return invoke(fn_64,args_63);}());
    }
    // Lucilla.py:78
    ([&]()->V{auto fn_66=attr(self_value(),"perform_liberation");Args args_65;return invoke(fn_66,args_65);}());
    // Lucilla.py:79
    ([&]()->V{auto fn_68=attr(self_value(),"switch_next_char");Args args_67;return invoke(fn_68,args_67);}());
    // Lucilla.py:80
    return V(true);
return V{};
}),false);
// Official method Lucilla.energy_full, lines 82-88
register_method("energy_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_69=bind_arguments(official_args,signature,captured);
    // Lucilla.py:88
    return ([&]()->V{auto fn_71=attr(self_value(),"available");Args args_70;args_70.pos(V("liberation"));args_70.kw("check_color",V(true));args_70.kw("check_cd",V(false));return invoke(fn_71,args_70);}());
return V{};
}),false);
// Official method Lucilla.perform_liberation, lines 90-112
register_method("perform_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_72=bind_arguments(official_args,signature,captured);
scope_72->set("start",V::missing());
    // Lucilla.py:98
    if(unary("not",attr(attr(self_value(),"task"),"use_liberation")).truth()){
        // Lucilla.py:99
        return V{};
    }
    // Lucilla.py:101
    {V value_73=([&]()->V{auto fn_75=attr(global("time","Lucilla"),"time");Args args_74;return invoke(fn_75,args_74);}());scope_72->set("start",value_73);}
    // Lucilla.py:102
        while(([&]()->V{V operand_80;operand_80=([&]()->V{auto fn_82=attr(self_value(),"liberation_available");Args args_81;return invoke(fn_82,args_81);}());if(!operand_80.truth())return operand_80;return ([&]()->V{V compare_83=([&]()->V{V left_85=([&]()->V{auto fn_88=attr(global("time","Lucilla"),"time");Args args_87;return invoke(fn_88,args_87);}());V right_86=scope_72->get("start");return official::binary("-",left_85,right_86);}());V compare_84;V comparison_result_89;compare_84=V(1.5);comparison_result_89=compare_value("<",compare_83,compare_84);return comparison_result_89;}());}()).truth()){
        // Lucilla.py:103
        ([&]()->V{auto fn_77=attr(self_value(),"send_liberation_key");Args args_76;return invoke(fn_77,args_76);}());
        // Lucilla.py:104
        ([&]()->V{auto fn_79=attr(self_value(),"sleep");Args args_78;args_78.pos(V(0.1));args_78.kw("check_combat",V(false));return invoke(fn_79,args_78);}());
    }
    // Lucilla.py:105
    ([&]()->V{auto fn_91=attr(self_value(),"record_liberation_use");Args args_90;return invoke(fn_91,args_90);}());
    // Lucilla.py:106
    ([&]()->V{auto fn_93=attr(attr(self_value(),"logger"),"info");Args args_92;args_92.pos(V("Lucilla perform lib"));return invoke(fn_93,args_92);}());
    // Lucilla.py:108
    ([&]()->V{auto fn_95=attr(self_value(),"sleep");Args args_94;args_94.pos(attr(self_value(),"LIBERATION_ANIMATION_TIME"));args_94.kw("check_combat",V(false));return invoke(fn_95,args_94);}());
    // Lucilla.py:111
    ([&]()->V{auto fn_97=attr(self_value(),"pulse_heavy_attack");Args args_96;args_96.pos(attr(self_value(),"LIBERATION_HEAVY_TIME"));return invoke(fn_97,args_96);}());
    // Lucilla.py:112
    ([&]()->V{auto fn_99=attr(attr(self_value(),"logger"),"info");Args args_98;args_98.pos(V("Lucilla perform lib end"));return invoke(fn_99,args_98);}());
return V{};
}),false);
// Official method Lucilla.pulse_heavy_attack, lines 114-139
register_method("pulse_heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"total_time",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_100=bind_arguments(official_args,signature,captured);
scope_100->set("con",V::missing());
scope_100->set("end",V::missing());
scope_100->set("seen_active",V::missing());
    // Lucilla.py:123
    {V value_101=([&]()->V{V left_102=([&]()->V{auto fn_105=attr(global("time","Lucilla"),"time");Args args_104;return invoke(fn_105,args_104);}());V right_103=scope_100->get("total_time");return official::binary("+",left_102,right_103);}());scope_100->set("end",value_101);}
    // Lucilla.py:124
    {V value_106=V(false);scope_100->set("seen_active",value_106);}
    // Lucilla.py:125
        while(([&]()->V{V compare_135=([&]()->V{auto fn_138=attr(global("time","Lucilla"),"time");Args args_137;return invoke(fn_138,args_137);}());V compare_136;V comparison_result_139;compare_136=scope_100->get("end");comparison_result_139=compare_value("<",compare_135,compare_136);return comparison_result_139;}()).truth()){
        // Lucilla.py:126
        ([&]()->V{auto fn_108=attr(attr(self_value(),"task"),"mouse_down");Args args_107;return invoke(fn_108,args_107);}());
        // Lucilla.py:127
        {
        auto finally_109=on_scope_exit([&](){
            // Lucilla.py:130
            ([&]()->V{auto fn_111=attr(attr(self_value(),"task"),"mouse_up");Args args_110;return invoke(fn_111,args_110);}());
        });
            // Lucilla.py:128
            ([&]()->V{auto fn_113=attr(self_value(),"sleep");Args args_112;args_112.pos(([&]()->V{auto fn_115=global("min","Lucilla");Args args_114;args_114.pos(attr(self_value(),"HEAVY_PULSE_TIME"));args_114.pos(([&]()->V{V left_116=scope_100->get("end");V right_117=([&]()->V{auto fn_119=attr(global("time","Lucilla"),"time");Args args_118;return invoke(fn_119,args_118);}());return official::binary("-",left_116,right_117);}()));return invoke(fn_115,args_114);}()));args_112.kw("check_combat",V(false));return invoke(fn_113,args_112);}());
        }
        // Lucilla.py:132
        {V value_120=([&]()->V{auto fn_122=attr(attr(self_value(),"task"),"get_current_con");Args args_121;return invoke(fn_122,args_121);}());scope_100->set("con",value_120);}
        // Lucilla.py:133
        if(([&]()->V{V compare_123=scope_100->get("con");V compare_124;V comparison_result_125;compare_124=V(0.1);comparison_result_125=compare_value(">",compare_123,compare_124);return comparison_result_125;}()).truth()){
            // Lucilla.py:134
            {V value_126=V(true);scope_100->set("seen_active",value_126);}
        }else{
            // Lucilla.py:135
            if(([&]()->V{V operand_127;operand_127=scope_100->get("seen_active");if(!operand_127.truth())return operand_127;return ([&]()->V{V compare_128=scope_100->get("con");V compare_129;V comparison_result_130;compare_129=V(0.05);comparison_result_130=compare_value("<",compare_128,compare_129);return comparison_result_130;}());}()).truth()){
                // Lucilla.py:136
                ([&]()->V{auto fn_132=attr(attr(self_value(),"logger"),"info");Args args_131;args_131.pos(V("Lucilla transform ended, stop pulse heavy early"));return invoke(fn_132,args_131);}());
                // Lucilla.py:137
                break;
            }
        }
        // Lucilla.py:139
        ([&]()->V{auto fn_134=attr(self_value(),"sleep");Args args_133;args_133.pos(V(0.02));args_133.kw("check_combat",V(false));return invoke(fn_134,args_133);}());
    }
return V{};
}),false);
// Official method Lucilla.hold_resonance, lines 141-152
register_method("hold_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_140=bind_arguments(official_args,signature,captured);
    // Lucilla.py:147
    ([&]()->V{auto fn_142=attr(attr(self_value(),"task"),"send_key_down");Args args_141;args_141.pos(([&]()->V{auto fn_144=attr(self_value(),"get_resonance_key");Args args_143;return invoke(fn_144,args_143);}()));return invoke(fn_142,args_141);}());
    // Lucilla.py:148
    {
    auto finally_145=on_scope_exit([&](){
        // Lucilla.py:151
        ([&]()->V{auto fn_147=attr(attr(self_value(),"task"),"send_key_up");Args args_146;args_146.pos(([&]()->V{auto fn_149=attr(self_value(),"get_resonance_key");Args args_148;return invoke(fn_149,args_148);}()));return invoke(fn_147,args_146);}());
    });
        // Lucilla.py:149
        ([&]()->V{auto fn_151=attr(self_value(),"sleep");Args args_150;args_150.pos(scope_140->get("duration"));args_150.kw("check_combat",V(false));return invoke(fn_151,args_150);}());
    }
    // Lucilla.py:152
    ([&]()->V{auto fn_153=attr(self_value(),"record_resonance_use");Args args_152;return invoke(fn_153,args_152);}());
return V{};
}),false);
// Official method Lucilla.get_switch_priority, lines 154-157
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_154=bind_arguments(official_args,signature,captured);
    // Lucilla.py:155
    if(([&]()->V{V operand_155;operand_155=scope_154->get("has_intro");if(!operand_155.truth())return operand_155;operand_155=scope_154->get("current_char");if(!operand_155.truth())return operand_155;return ([&]()->V{V compare_156=attr(scope_154->get("current_char"),"char_name");V compare_157;V comparison_result_158;compare_157=V::set({V("char_verina"),V("char_shorekeeper")});comparison_result_158=compare_value("in",compare_156,compare_157);return comparison_result_158;}());}()).truth()){
        // Lucilla.py:156
        return attr(global("SwitchPriority","Lucilla"),"MUST");
    }
    // Lucilla.py:157
    return ([&]()->V{auto fn_162=attr(([&]()->V{auto fn_160=global("super","Lucilla");Args args_159;return invoke(fn_160,args_159);}()),"get_switch_priority");Args args_161;args_161.pos(scope_154->get("current_char"));args_161.pos(scope_154->get("has_intro"));args_161.pos(scope_154->get("target_low_con"));return invoke(fn_162,args_161);}());
return V{};
}),false);
}
}
