#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Rover.py
// SHA256 3002646896fd478c9a57d800144ebc95af507d4fa55a8fc001c42d4fb5222779
void OfficialCharacter::install_Rover(){
auto scope=std::make_shared<Scope>();
set_global("_ROVER_FORM_NAMES",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,attr(global("Elements","Rover"),"SPECTRO"),V("Rover: Spectro"));set_item(dictionary_1,attr(global("Elements","Rover"),"ELECTRIC"),V("Rover: Electro"));set_item(dictionary_1,attr(global("Elements","Rover"),"WIND"),V("Rover: Aero"));set_item(dictionary_1,attr(global("Elements","Rover"),"HAVOC"),V("Rover: Havoc"));return dictionary_1;}()));
// Official method Rover.__init__, lines 14-18
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Rover.py:15
    {V value_3=unary("-",V(1LL));set_attr(self_value(),"_last_known_form",value_3);}
    // Rover.py:16
    ([&]()->V{auto fn_7=attr(([&]()->V{auto fn_5=global("super","Rover");Args args_4;return invoke(fn_5,args_4);}()),"__init__");Args args_6;args_6.spread(scope_2->get("args"));args_6.spread_keywords(scope_2->get("kwargs"));return invoke(fn_7,args_6);}());
    // Rover.py:17
    {V value_8=V(false);set_attr(self_value(),"use_skyfall_severance",value_8);}
    // Rover.py:18
    ([&]()->V{auto fn_10=attr(self_value(),"_bind_form_logger");Args args_9;return invoke(fn_10,args_9);}());
return V{};
}),false);
// Official method Rover.reset_state, lines 20-25
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
    // Rover.py:21
    if(([&]()->V{V compare_12=attr(self_value(),"ring_index");V compare_13;V comparison_result_14;compare_13=V(0LL);comparison_result_14=compare_value(">=",compare_12,compare_13);return comparison_result_14;}()).truth()){
        // Rover.py:22
        {V value_15=attr(self_value(),"ring_index");set_attr(self_value(),"_last_known_form",value_15);}
    }
    // Rover.py:23
    {V value_16=unary("-",V(1LL));set_attr(self_value(),"ring_index",value_16);}
    // Rover.py:24
    ([&]()->V{auto fn_20=attr(([&]()->V{auto fn_18=global("super","Rover");Args args_17;return invoke(fn_18,args_17);}()),"reset_state");Args args_19;return invoke(fn_20,args_19);}());
    // Rover.py:25
    ([&]()->V{auto fn_22=attr(self_value(),"_bind_form_logger");Args args_21;return invoke(fn_22,args_21);}());
return V{};
}),false);
// Official method Rover.display_name, lines 28-29
register_method("@get:display_name",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_23=bind_arguments(official_args,signature,captured);
    // Rover.py:29
    return ([&]()->V{auto fn_25=attr(global("_ROVER_FORM_NAMES","Rover"),"get");Args args_24;args_24.pos(attr(self_value(),"ring_index"));args_24.pos(V("Rover"));return invoke(fn_25,args_24);}());
return V{};
}),false);
// Official method Rover.get_char_type, lines 31-34
register_method("get_char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_26=bind_arguments(official_args,signature,captured);
scope_26->set("form",V::missing());
    // Rover.py:32
    {V value_27=(([&]()->V{V compare_28=attr(self_value(),"ring_index");V compare_29;V comparison_result_30;compare_29=V(0LL);comparison_result_30=compare_value(">=",compare_28,compare_29);return comparison_result_30;}()).truth()?attr(self_value(),"ring_index"):attr(self_value(),"_last_known_form"));scope_26->set("form",value_27);}
    // Rover.py:34
    return (([&]()->V{V compare_31=scope_26->get("form");V compare_32;V comparison_result_33;compare_32=V::tuple({unary("-",V(1LL)),attr(global("Elements","Rover"),"ELECTRIC")});comparison_result_33=compare_value("in",compare_31,compare_32);return comparison_result_33;}()).truth()?attr(global("CharType","Rover"),"SUB_DPS"):([&]()->V{auto fn_37=attr(([&]()->V{auto fn_35=global("super","Rover");Args args_34;return invoke(fn_35,args_34);}()),"get_char_type");Args args_36;return invoke(fn_37,args_36);}()));
return V{};
}),false);
// Official method Rover.__repr__, lines 36-37
register_method("__repr__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_38=bind_arguments(official_args,signature,captured);
    // Rover.py:37
    return attr(self_value(),"display_name");
return V{};
}),false);
// Official method Rover._bind_form_logger, lines 39-40
register_method("_bind_form_logger",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_39=bind_arguments(official_args,signature,captured);
    // Rover.py:40
    {V value_40=([&]()->V{auto fn_42=attr(global("Logger","Rover"),"get_logger");Args args_41;args_41.pos(attr(self_value(),"display_name"));return invoke(fn_42,args_41);}());set_attr(self_value(),"logger",value_40);}
return V{};
}),false);
// Official method Rover._known_form, lines 42-45
register_method("_known_form",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_43=bind_arguments(official_args,signature,captured);
    // Rover.py:43
    if(([&]()->V{auto fn_45=global("hasattr","Rover");Args args_44;args_44.pos(attr(self_value(),"task"));args_44.pos(V("get_known_ring_index"));return invoke(fn_45,args_44);}()).truth()){
        // Rover.py:44
        return ([&]()->V{auto fn_47=attr(attr(self_value(),"task"),"get_known_ring_index");Args args_46;args_46.pos(self_value());return invoke(fn_47,args_46);}());
    }
    // Rover.py:45
    return attr(self_value(),"ring_index");
return V{};
}),false);
// Official method Rover.is_havoc_form, lines 47-48
register_method("is_havoc_form",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_48=bind_arguments(official_args,signature,captured);
    // Rover.py:48
    return ([&]()->V{V compare_49=([&]()->V{auto fn_52=attr(self_value(),"_known_form");Args args_51;return invoke(fn_52,args_51);}());V compare_50;V comparison_result_53;compare_50=attr(global("Elements","Rover"),"HAVOC");comparison_result_53=compare_value("==",compare_49,compare_50);return comparison_result_53;}());
return V{};
}),false);
// Official method Rover.ensure_display_form, lines 50-57
register_method("ensure_display_form",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_54=bind_arguments(official_args,signature,captured);
    // Rover.py:51
    if(([&]()->V{V compare_55=attr(self_value(),"ring_index");V compare_56;V comparison_result_57;compare_56=V(0LL);comparison_result_57=compare_value(">=",compare_55,compare_56);return comparison_result_57;}()).truth()){
        // Rover.py:52
        return V{};
    }
    // Rover.py:53
    if(unary("not",attr(self_value(),"is_current_char")).truth()){
        // Rover.py:54
        return V{};
    }
    // Rover.py:55
    if(([&]()->V{auto fn_59=global("hasattr","Rover");Args args_58;args_58.pos(attr(self_value(),"task"));args_58.pos(V("_ensure_ring_index"));return invoke(fn_59,args_58);}()).truth()){
        // Rover.py:56
        ([&]()->V{auto fn_61=attr(attr(self_value(),"task"),"_ensure_ring_index");Args args_60;return invoke(fn_61,args_60);}());
        // Rover.py:57
        ([&]()->V{auto fn_63=attr(self_value(),"_bind_form_logger");Args args_62;return invoke(fn_63,args_62);}());
    }
return V{};
}),false);
// Official method Rover.do_perform, lines 59-82
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_64=bind_arguments(official_args,signature,captured);
    // Rover.py:60
    ([&]()->V{auto fn_66=attr(self_value(),"init");Args args_65;return invoke(fn_66,args_65);}());
    // Rover.py:61
    if(unary("not",attr(self_value(),"has_intro")).truth()){
        // Rover.py:62
        ([&]()->V{auto fn_68=attr(self_value(),"sleep");Args args_67;args_67.pos(V(0.01));return invoke(fn_68,args_67);}());
    }
    // Rover.py:63
    if(([&]()->V{V compare_69=attr(self_value(),"ring_index");V compare_70;V comparison_result_71;compare_70=attr(global("Elements","Rover"),"HAVOC");comparison_result_71=compare_value("==",compare_69,compare_70);return comparison_result_71;}()).truth()){
        // Rover.py:64
        {V value_72=V(0.64);set_attr(self_value(),"intro_motion_freeze_duration",value_72);}
        // Rover.py:65
        ([&]()->V{auto fn_74=attr(attr(self_value(),"logger"),"info");Args args_73;args_73.pos(V("rover: form-dispatch ring=HAVOC routine=havoc"));return invoke(fn_74,args_73);}());
        // Rover.py:66
        if(([&]()->V{auto fn_76=attr(self_value(),"perform_havoc_routine");Args args_75;return invoke(fn_76,args_75);}()).truth()){
            // Rover.py:67
            return V{};
        }
    }else{
        // Rover.py:68
        if(([&]()->V{V compare_77=attr(self_value(),"ring_index");V compare_78;V comparison_result_79;compare_78=attr(global("Elements","Rover"),"SPECTRO");comparison_result_79=compare_value("==",compare_77,compare_78);return comparison_result_79;}()).truth()){
            // Rover.py:69
            {V value_80=V(0.92);set_attr(self_value(),"intro_motion_freeze_duration",value_80);}
            // Rover.py:70
            ([&]()->V{auto fn_82=attr(attr(self_value(),"logger"),"info");Args args_81;args_81.pos(V("rover: form-dispatch ring=SPECTRO routine=spectro"));return invoke(fn_82,args_81);}());
            // Rover.py:71
            ([&]()->V{auto fn_84=attr(self_value(),"perform_spectro_routine");Args args_83;return invoke(fn_84,args_83);}());
        }else{
            // Rover.py:72
            if(([&]()->V{V compare_85=attr(self_value(),"ring_index");V compare_86;V comparison_result_87;compare_86=attr(global("Elements","Rover"),"WIND");comparison_result_87=compare_value("==",compare_85,compare_86);return comparison_result_87;}()).truth()){
                // Rover.py:73
                {V value_88=V(0.52);set_attr(self_value(),"intro_motion_freeze_duration",value_88);}
                // Rover.py:74
                ([&]()->V{auto fn_90=attr(attr(self_value(),"logger"),"info");Args args_89;args_89.pos(V("rover: form-dispatch ring=WIND routine=wind"));return invoke(fn_90,args_89);}());
                // Rover.py:75
                ([&]()->V{auto fn_92=attr(self_value(),"perform_wind_routine");Args args_91;return invoke(fn_92,args_91);}());
            }else{
                // Rover.py:76
                if(([&]()->V{V compare_93=attr(self_value(),"ring_index");V compare_94;V comparison_result_95;compare_94=attr(global("Elements","Rover"),"ELECTRIC");comparison_result_95=compare_value("==",compare_93,compare_94);return comparison_result_95;}()).truth()){
                    // Rover.py:77
                    ([&]()->V{auto fn_97=attr(attr(self_value(),"logger"),"info");Args args_96;args_96.pos(V("rover: form-dispatch ring=ELECTRIC routine=electric"));return invoke(fn_97,args_96);}());
                    // Rover.py:78
                    ([&]()->V{auto fn_99=attr(self_value(),"perform_electric_routine");Args args_98;return invoke(fn_99,args_98);}());
                }else{
                    // Rover.py:80
                    ([&]()->V{auto fn_101=attr(attr(self_value(),"logger"),"info");Args args_100;args_100.pos(V("rover: form-dispatch ring=UNKNOWN routine=basic"));return invoke(fn_101,args_100);}());
                    // Rover.py:81
                    ([&]()->V{auto fn_103=attr(self_value(),"perform_basic_routine");Args args_102;return invoke(fn_103,args_102);}());
                }
            }
        }
    }
    // Rover.py:82
    ([&]()->V{auto fn_105=attr(self_value(),"switch_next_char");Args args_104;return invoke(fn_105,args_104);}());
return V{};
}),false);
// Official method Rover.init, lines 84-101
register_method("init",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_106=bind_arguments(official_args,signature,captured);
scope_106->set("char",V::missing());
scope_106->set("name",V::missing());
scope_106->set("names",V::missing());
scope_106->set("previous_form",V::missing());
    // Rover.py:85
    {V value_107=attr(self_value(),"ring_index");scope_106->set("previous_form",value_107);}
    // Rover.py:86
    if(([&]()->V{auto fn_109=global("hasattr","Rover");Args args_108;args_108.pos(attr(self_value(),"task"));args_108.pos(V("_ensure_ring_index"));return invoke(fn_109,args_108);}()).truth()){
        // Rover.py:87
        ([&]()->V{auto fn_111=attr(attr(self_value(),"task"),"_ensure_ring_index");Args args_110;return invoke(fn_111,args_110);}());
    }
    // Rover.py:88
    if(([&]()->V{V compare_112=attr(self_value(),"ring_index");V compare_113;V comparison_result_114;compare_113=scope_106->get("previous_form");comparison_result_114=compare_value("!=",compare_112,compare_113);return comparison_result_114;}()).truth()){
        // Rover.py:89
        ([&]()->V{auto fn_116=attr(self_value(),"_bind_form_logger");Args args_115;return invoke(fn_116,args_115);}());
        // Rover.py:90
        ([&]()->V{auto fn_118=attr(attr(self_value(),"logger"),"info");Args args_117;args_117.pos(V(std::string{}+"rover: form-corrected previous="+format_value(scope_106->get("previous_form"),"",-1)+" current="+format_value(attr(self_value(),"ring_index"),"",-1)));return invoke(fn_118,args_117);}());
        // Rover.py:93
        {V value_119=V::list({});scope_106->set("names",value_119);}
        // Rover.py:94
        {auto iterator_120=official::iterate(attr(attr(self_value(),"task"),"chars"));V item_121;while(iterator_120.next(item_121)){
            scope_106->set("char",item_121);
            // Rover.py:95
            if(([&]()->V{V compare_122=scope_106->get("char");V compare_123;V comparison_result_124;compare_123=V{};comparison_result_124=compare_value("is",compare_122,compare_123);return comparison_result_124;}()).truth()){
                // Rover.py:96
                continue;
            }
            // Rover.py:97
            {V value_125=([&]()->V{auto fn_127=global("getattr","Rover");Args args_126;args_126.pos(scope_106->get("char"));args_126.pos(V("display_name"));args_126.pos(attr(scope_106->get("char"),"name"));return invoke(fn_127,args_126);}());scope_106->set("name",value_125);}
            // Rover.py:98
            ([&]()->V{auto fn_129=attr(scope_106->get("names"),"append");Args args_128;args_128.pos((([&]()->V{V compare_130=([&]()->V{auto fn_133=global("getattr","Rover");Args args_132;args_132.pos(attr(self_value(),"task"));args_132.pos(V("_app"));args_132.pos(V{});return invoke(fn_133,args_132);}());V compare_131;V comparison_result_134;compare_131=V{};comparison_result_134=compare_value("is not",compare_130,compare_131);return comparison_result_134;}()).truth()?([&]()->V{auto fn_136=attr(attr(self_value(),"task"),"tr");Args args_135;args_135.pos(scope_106->get("name"));return invoke(fn_136,args_135);}()):scope_106->get("name")));return invoke(fn_129,args_128);}());
        }
        }
        // Rover.py:99
        ([&]()->V{auto fn_138=attr(attr(self_value(),"task"),"info_set");Args args_137;args_137.pos(V("Chars"));args_137.pos(([&]()->V{auto fn_140=attr(V(", "),"join");Args args_139;args_139.pos(scope_106->get("names"));return invoke(fn_140,args_139);}()));return invoke(fn_138,args_137);}());
    }
    // Rover.py:100
    if(([&]()->V{V compare_141=attr(self_value(),"ring_index");V compare_142;V comparison_result_143;compare_142=attr(global("Elements","Rover"),"WIND");comparison_result_143=compare_value("==",compare_141,compare_142);return comparison_result_143;}()).truth()){
        // Rover.py:101
        ([&]()->V{auto fn_145=attr(self_value(),"init_wind");Args args_144;return invoke(fn_145,args_144);}());
    }
return V{};
}),false);
// Official method Rover.electric_skill_ready, lines 103-105
register_method("electric_skill_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_146=bind_arguments(official_args,signature,captured);
    // Rover.py:105
    return ([&]()->V{V operand_147;operand_147=([&]()->V{auto fn_149=attr(self_value(),"is_forte_full");Args args_148;return invoke(fn_149,args_148);}());if(!operand_147.truth())return operand_147;return ([&]()->V{auto fn_151=global("bool","Rover");Args args_150;args_150.pos(([&]()->V{auto fn_153=attr(self_value(),"is_e_forte_full");Args args_152;return invoke(fn_153,args_152);}()));return invoke(fn_151,args_150);}());}());
return V{};
}),false);
// Official method Rover.perform_electric_routine, lines 107-129
register_method("perform_electric_routine",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_154=bind_arguments(official_args,signature,captured);
scope_154->set("duration",V::missing());
scope_154->set("start",V::missing());
    // Rover.py:108
    ([&]()->V{auto fn_156=attr(self_value(),"wait_down");Args args_155;args_155.kw("click",V(false));return invoke(fn_156,args_155);}());
    // Rover.py:109
    ([&]()->V{auto fn_158=attr(self_value(),"click_echo");Args args_157;return invoke(fn_158,args_157);}());
    // Rover.py:111
    ([&]()->V{auto fn_160=attr(self_value(),"click_liberation");Args args_159;args_159.kw("click_f",V(false));return invoke(fn_160,args_159);}());
    // Rover.py:112
    if(([&]()->V{V operand_161;operand_161=unary("not",([&]()->V{auto fn_163=attr(self_value(),"electric_skill_ready");Args args_162;return invoke(fn_163,args_162);}()));if(!operand_161.truth())return operand_161;return ([&]()->V{auto fn_165=attr(self_value(),"resonance_available");Args args_164;return invoke(fn_165,args_164);}());}()).truth()){
        // Rover.py:113
        if(item(([&]()->V{auto fn_167=attr(self_value(),"click_resonance");Args args_166;args_166.kw("send_click",V(false));args_166.kw("time_out",V(1LL));return invoke(fn_167,args_166);}()),V(0LL)).truth()){
            // Rover.py:114
            ([&]()->V{auto fn_169=attr(self_value(),"sleep");Args args_168;args_168.pos(V(0.1));return invoke(fn_169,args_168);}());
        }
    }
    // Rover.py:115
    {V value_170=([&]()->V{auto fn_172=attr(global("time","Rover"),"time");Args args_171;return invoke(fn_172,args_171);}());scope_154->set("start",value_170);}
    // Rover.py:116
    {V value_173=(attr(self_value(),"has_intro").truth()?V(8LL):V(12LL));scope_154->set("duration",value_173);}
    // Rover.py:117
        while(([&]()->V{V operand_178;operand_178=unary("not",([&]()->V{auto fn_180=attr(self_value(),"electric_skill_ready");Args args_179;return invoke(fn_180,args_179);}()));if(!operand_178.truth())return operand_178;return ([&]()->V{V compare_181=([&]()->V{auto fn_184=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_183;args_183.pos(scope_154->get("start"));return invoke(fn_184,args_183);}());V compare_182;V comparison_result_185;compare_182=scope_154->get("duration");comparison_result_185=compare_value("<",compare_181,compare_182);return comparison_result_185;}());}()).truth()){
        // Rover.py:118
        ([&]()->V{auto fn_175=attr(self_value(),"click");Args args_174;return invoke(fn_175,args_174);}());
        // Rover.py:119
        ([&]()->V{auto fn_177=attr(self_value(),"sleep");Args args_176;args_176.pos(V(0.1));return invoke(fn_177,args_176);}());
    }
    // Rover.py:120
    if(unary("not",([&]()->V{auto fn_187=attr(self_value(),"electric_skill_ready");Args args_186;return invoke(fn_187,args_186);}())).truth()){
        // Rover.py:121
        ([&]()->V{auto fn_189=attr(attr(self_value(),"logger"),"info");Args args_188;args_188.pos(V("rover: electric forte not ready before rotation timeout"));return invoke(fn_189,args_188);}());
        // Rover.py:122
        return V{};
    }
    // Rover.py:123
    if(unary("not",([&]()->V{auto fn_191=attr(self_value(),"short_electric_skill");Args args_190;return invoke(fn_191,args_190);}())).truth()){
        // Rover.py:124
        ([&]()->V{auto fn_193=attr(attr(self_value(),"logger"),"info");Args args_192;args_192.pos(V("rover: electric enhanced resonance not confirmed, switch out"));return invoke(fn_193,args_192);}());
        // Rover.py:125
        return V{};
    }
    // Rover.py:126
    if(unary("not",([&]()->V{auto fn_195=attr(self_value(),"is_con_full");Args args_194;return invoke(fn_195,args_194);}())).truth()){
        // Rover.py:127
        ([&]()->V{auto fn_197=attr(self_value(),"click_liberation");Args args_196;args_196.kw("click_f",V(false));return invoke(fn_197,args_196);}());
    }
    // Rover.py:128
    if(unary("not",([&]()->V{auto fn_199=attr(self_value(),"is_con_full");Args args_198;return invoke(fn_199,args_198);}())).truth()){
        // Rover.py:129
        ([&]()->V{auto fn_201=attr(self_value(),"continues_normal_attack");Args args_200;args_200.pos(V(2LL));args_200.kw("until_con_full",V(true));return invoke(fn_201,args_200);}());
    }
return V{};
}),false);
// Official method Rover.short_electric_skill, lines 131-147
register_method("short_electric_skill",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_202=bind_arguments(official_args,signature,captured);
scope_202->set("attempt",V::missing());
scope_202->set("consumed",V::missing());
scope_202->set("start",V::missing());
    // Rover.py:133
    {auto iterator_203=official::iterate(([&]()->V{auto fn_235=global("range","Rover");Args args_234;args_234.pos(V(2LL));return invoke(fn_235,args_234);}()));V item_204;while(iterator_203.next(item_204)){
        scope_202->set("attempt",item_204);
        // Rover.py:134
        if(unary("not",([&]()->V{auto fn_206=attr(self_value(),"electric_skill_ready");Args args_205;return invoke(fn_206,args_205);}())).truth()){
            // Rover.py:135
            return V(false);
        }
        // Rover.py:136
        {V value_207=([&]()->V{auto fn_209=attr(global("time","Rover"),"time");Args args_208;return invoke(fn_209,args_208);}());scope_202->set("start",value_207);}
        // Rover.py:137
        ([&]()->V{auto fn_211=attr(self_value(),"send_resonance_key");Args args_210;args_210.kw("down_time",V(0.05));return invoke(fn_211,args_210);}());
        // Rover.py:139
        {V value_212=([&]()->V{auto fn_214=global("bool","Rover");Args args_213;args_213.pos(([&]()->V{auto fn_216=attr(attr(self_value(),"task"),"wait_until");Args args_215;args_215.pos(V::function([this,captured=capture_scope(scope_202,{"start"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_217=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_218;operand_218=([&]()->V{V compare_219=([&]()->V{auto fn_222=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_221;args_221.pos(scope_217->get("start"));return invoke(fn_222,args_221);}());V compare_220;V comparison_result_223;compare_220=V(1.5);comparison_result_223=compare_value(">=",compare_219,compare_220);return comparison_result_223;}());if(!operand_218.truth())return operand_218;operand_218=unary("not",([&]()->V{auto fn_225=attr(self_value(),"is_forte_full");Args args_224;return invoke(fn_225,args_224);}()));if(!operand_218.truth())return operand_218;return unary("not",([&]()->V{auto fn_227=attr(self_value(),"is_e_forte_full");Args args_226;return invoke(fn_227,args_226);}()));}());
}));args_215.kw("time_out",V(2.6));args_215.kw("settle_time",V(0.2));args_215.kw("pre_action",attr(self_value(),"check_combat"));return invoke(fn_216,args_215);}()));return invoke(fn_214,args_213);}());scope_202->set("consumed",value_212);}
        // Rover.py:143
        if(scope_202->get("consumed").truth()){
            // Rover.py:144
            ([&]()->V{auto fn_229=attr(self_value(),"record_resonance_use");Args args_228;return invoke(fn_229,args_228);}());
            // Rover.py:145
            return V(true);
        }
        // Rover.py:146
        ([&]()->V{auto fn_231=attr(attr(self_value(),"logger"),"info");Args args_230;args_230.pos(V(std::string{}+"rover: electric enhanced resonance attempt "+format_value(([&]()->V{V left_232=scope_202->get("attempt");V right_233=V(1LL);return official::binary("+",left_232,right_233);}()),"",-1)+" not confirmed"));return invoke(fn_231,args_230);}());
    }
    }
    // Rover.py:147
    return V(false);
return V{};
}),false);
// Official method Rover.perform_spectro_routine, lines 149-162
register_method("perform_spectro_routine",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_236=bind_arguments(official_args,signature,captured);
    // Rover.py:150
    if(attr(self_value(),"has_intro").truth()){
        // Rover.py:151
        ([&]()->V{auto fn_238=attr(self_value(),"continues_normal_attack");Args args_237;args_237.pos(V(1LL));return invoke(fn_238,args_237);}());
    }
    // Rover.py:152
    ([&]()->V{auto fn_240=attr(self_value(),"wait_down");Args args_239;return invoke(fn_240,args_239);}());
    // Rover.py:153
    ([&]()->V{auto fn_242=attr(self_value(),"spectro_routine_aftertune_combo");Args args_241;return invoke(fn_242,args_241);}());
    // Rover.py:154
    ([&]()->V{auto fn_244=attr(self_value(),"click_echo");Args args_243;args_243.kw("time_out",V(0LL));return invoke(fn_244,args_243);}());
    // Rover.py:155
    if(([&]()->V{auto fn_246=attr(self_value(),"is_forte_full");Args args_245;return invoke(fn_246,args_245);}()).truth()){
        // Rover.py:156
        ([&]()->V{auto fn_248=attr(self_value(),"check_combat");Args args_247;return invoke(fn_248,args_247);}());
        // Rover.py:157
        if(([&]()->V{V operand_249;operand_249=([&]()->V{auto fn_251=attr(self_value(),"resonance_available");Args args_250;return invoke(fn_251,args_250);}());if(!operand_249.truth())return operand_249;return item(([&]()->V{auto fn_253=attr(self_value(),"click_resonance");Args args_252;return invoke(fn_253,args_252);}()),V(0LL));}()).truth()){
            // Rover.py:158
            ([&]()->V{auto fn_255=attr(self_value(),"continues_normal_attack");Args args_254;args_254.pos(V(1.4));return invoke(fn_255,args_254);}());
            // Rover.py:159
            ([&]()->V{auto fn_257=attr(self_value(),"sleep");Args args_256;args_256.pos(V(0.1));return invoke(fn_257,args_256);}());
        }
    }
    // Rover.py:160
    ([&]()->V{auto fn_259=attr(self_value(),"check_combat");Args args_258;return invoke(fn_259,args_258);}());
    // Rover.py:161
    if(unary("not",([&]()->V{auto fn_261=attr(self_value(),"click_liberation");Args args_260;args_260.kw("send_click",V(true));return invoke(fn_261,args_260);}())).truth()){
        // Rover.py:162
        ([&]()->V{auto fn_263=attr(self_value(),"click_resonance");Args args_262;return invoke(fn_263,args_262);}());
    }
return V{};
}),false);
// Official method Rover.spectro_routine_aftertune_combo, lines 164-167
register_method("spectro_routine_aftertune_combo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_264=bind_arguments(official_args,signature,captured);
    // Rover.py:165
    ([&]()->V{auto fn_266=attr(self_value(),"heavy_attack");Args args_265;return invoke(fn_266,args_265);}());
    // Rover.py:166
    ([&]()->V{auto fn_268=attr(self_value(),"sleep");Args args_267;args_267.pos(V(0.4));return invoke(fn_268,args_267);}());
    // Rover.py:167
    ([&]()->V{auto fn_270=attr(self_value(),"continues_normal_attack");Args args_269;args_269.pos(V(0.7));return invoke(fn_270,args_269);}());
return V{};
}),false);
// Official method Rover.perform_havoc_routine, lines 169-177
register_method("perform_havoc_routine",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_271=bind_arguments(official_args,signature,captured);
    // Rover.py:170
    ([&]()->V{auto fn_273=attr(self_value(),"wait_down");Args args_272;return invoke(fn_273,args_272);}());
    // Rover.py:171
    ([&]()->V{auto fn_275=attr(self_value(),"heavy_click_forte");Args args_274;args_274.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_275,args_274);}());
    // Rover.py:172
    ([&]()->V{auto fn_277=attr(self_value(),"click_liberation");Args args_276;args_276.kw("send_click",V(true));return invoke(fn_277,args_276);}());
    // Rover.py:173
    if(item(([&]()->V{auto fn_279=attr(self_value(),"click_resonance");Args args_278;args_278.kw("send_click",V(true));return invoke(fn_279,args_278);}()),V(0LL)).truth()){
        // Rover.py:174
        return V{};
    }
    // Rover.py:175
    if(unary("not",([&]()->V{auto fn_281=attr(self_value(),"click_echo");Args args_280;return invoke(fn_281,args_280);}())).truth()){
        // Rover.py:176
        ([&]()->V{auto fn_283=attr(self_value(),"click");Args args_282;return invoke(fn_283,args_282);}());
    }
    // Rover.py:177
    ([&]()->V{auto fn_285=attr(self_value(),"continues_normal_attack");Args args_284;args_284.pos(([&]()->V{V left_286=V(1.1);V right_287=([&]()->V{auto fn_289=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_288;args_288.pos(attr(self_value(),"last_switch_time"));return invoke(fn_289,args_288);}());return official::binary("-",left_286,right_287);}()));return invoke(fn_285,args_284);}());
return V{};
}),false);
// Official method Rover.init_wind, lines 179-182
register_method("init_wind",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_290=bind_arguments(official_args,signature,captured);
scope_290->set("Cartethyia",V::missing());
scope_290->set("Phoebe",V::missing());
    // Rover.py:180
    scope_290->set("Cartethyia",import_value("src.char.Cartethyia","Cartethyia"));
    // Rover.py:181
    scope_290->set("Phoebe",import_value("src.char.Phoebe","Phoebe"));
    // Rover.py:182
    {V value_291=([&]()->V{auto fn_293=global("bool","Rover");Args args_292;args_292.pos(([&]()->V{V operand_294;operand_294=([&]()->V{auto fn_296=attr(attr(self_value(),"task"),"has_char");Args args_295;args_295.pos(scope_290->get("Cartethyia"));return invoke(fn_296,args_295);}());if(!operand_294.truth())return operand_294;return ([&]()->V{auto fn_298=attr(attr(self_value(),"task"),"has_char");Args args_297;args_297.pos(scope_290->get("Phoebe"));return invoke(fn_298,args_297);}());}()));return invoke(fn_293,args_292);}());set_attr(self_value(),"use_skyfall_severance",value_291);}
return V{};
}),false);
// Official method Rover.perform_wind_routine, lines 184-203
register_method("perform_wind_routine",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_299=bind_arguments(official_args,signature,captured);
scope_299->set("flying",V::missing());
scope_299->set("start",V::missing());
scope_299->set("use_skyfall_severance",V::missing());
    // Rover.py:185
    if(unary("not",([&]()->V{V operand_300;operand_300=attr(self_value(),"has_intro");if(!operand_300.truth())return operand_300;return ([&]()->V{auto fn_302=attr(self_value(),"wind_routine_click_while_flying");Args args_301;args_301.pos(V(2LL));return invoke(fn_302,args_301);}());}())).truth()){
        // Rover.py:186
        ([&]()->V{auto fn_304=attr(self_value(),"wind_routine_wait_down");Args args_303;args_303.kw("check_forte_full",V(false));return invoke(fn_304,args_303);}());
        // Rover.py:187
        if(([&]()->V{V operand_305;operand_305=([&]()->V{auto fn_307=attr(self_value(),"resonance_available");Args args_306;return invoke(fn_307,args_306);}());if(!operand_305.truth())return operand_305;return unary("not",([&]()->V{auto fn_309=attr(self_value(),"is_forte_full");Args args_308;return invoke(fn_309,args_308);}()));}()).truth()){
            // Rover.py:188
            ([&]()->V{auto fn_311=attr(self_value(),"click_echo");Args args_310;args_310.kw("time_out",V(0LL));return invoke(fn_311,args_310);}());
            // Rover.py:189
            {V value_312=([&]()->V{auto fn_314=attr(global("time","Rover"),"time");Args args_313;return invoke(fn_314,args_313);}());scope_299->set("start",value_312);}
            // Rover.py:190
            {V value_315=V(false);scope_299->set("flying",value_315);}
            // Rover.py:191
                        while(([&]()->V{V compare_325=([&]()->V{V left_327=([&]()->V{auto fn_330=attr(global("time","Rover"),"time");Args args_329;return invoke(fn_330,args_329);}());V right_328=scope_299->get("start");return official::binary("-",left_327,right_328);}());V compare_326;V comparison_result_331;compare_326=V(1LL);comparison_result_331=compare_value("<",compare_325,compare_326);return comparison_result_331;}()).truth()){
                // Rover.py:192
                ([&]()->V{auto fn_317=attr(self_value(),"send_resonance_key");Args args_316;args_316.kw("interval",V(0.1));return invoke(fn_317,args_316);}());
                // Rover.py:193
                ([&]()->V{auto fn_319=attr(attr(self_value(),"task"),"next_frame");Args args_318;return invoke(fn_319,args_318);}());
                // Rover.py:194
                ([&]()->V{auto fn_321=attr(self_value(),"click");Args args_320;args_320.kw("interval",V(0.1));return invoke(fn_321,args_320);}());
                // Rover.py:195
                if(([&]()->V{V assigned_322=([&]()->V{auto fn_324=attr(self_value(),"wind_routine_flying");Args args_323;return invoke(fn_324,args_323);}());scope_299->set("flying",assigned_322);return assigned_322;}()).truth()){
                    // Rover.py:196
                    break;
                }
            }
            // Rover.py:197
            {V value_332=attr(self_value(),"use_skyfall_severance");scope_299->set("use_skyfall_severance",value_332);}
            // Rover.py:198
            if(scope_299->get("flying").truth()){
                // Rover.py:199
                ([&]()->V{auto fn_334=attr(self_value(),"wind_routine_click_while_flying");Args args_333;args_333.pos((scope_299->get("use_skyfall_severance").truth()?V(1.6):V(1.74)));return invoke(fn_334,args_333);}());
            }
            // Rover.py:200
            if(([&]()->V{V operand_335;operand_335=scope_299->get("use_skyfall_severance");if(!operand_335.truth())return operand_335;return item(([&]()->V{auto fn_337=attr(self_value(),"click_resonance");Args args_336;args_336.kw("send_click",V(false));return invoke(fn_337,args_336);}()),V(0LL));}()).truth()){
                // Rover.py:201
                ([&]()->V{auto fn_339=attr(self_value(),"wind_routine_click_while_flying");Args args_338;args_338.pos(V(1LL));return invoke(fn_339,args_338);}());
            }
        }
    }
    // Rover.py:202
    ([&]()->V{auto fn_341=attr(self_value(),"click_liberation");Args args_340;args_340.kw("send_click",V(true));return invoke(fn_341,args_340);}());
    // Rover.py:203
    ([&]()->V{auto fn_343=attr(self_value(),"wind_routine_wait_down");Args args_342;return invoke(fn_343,args_342);}());
return V{};
}),false);
// Official method Rover.wind_routine_click_while_flying, lines 205-212
register_method("wind_routine_click_while_flying",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()},{"interval",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_344=bind_arguments(official_args,signature,captured);
scope_344->set("start",V::missing());
    // Rover.py:206
    {V value_345=([&]()->V{auto fn_347=attr(global("time","Rover"),"time");Args args_346;return invoke(fn_347,args_346);}());scope_344->set("start",value_345);}
    // Rover.py:207
        while(([&]()->V{V compare_354=([&]()->V{V left_356=([&]()->V{auto fn_359=attr(global("time","Rover"),"time");Args args_358;return invoke(fn_359,args_358);}());V right_357=scope_344->get("start");return official::binary("-",left_356,right_357);}());V compare_355;V comparison_result_360;compare_355=scope_344->get("duration");comparison_result_360=compare_value("<",compare_354,compare_355);return comparison_result_360;}()).truth()){
        // Rover.py:208
        if(unary("not",([&]()->V{auto fn_349=attr(self_value(),"wind_routine_flying");Args args_348;return invoke(fn_349,args_348);}())).truth()){
            // Rover.py:209
            return V(false);
        }
        // Rover.py:210
        ([&]()->V{auto fn_351=attr(self_value(),"click");Args args_350;args_350.kw("interval",V(0.1));return invoke(fn_351,args_350);}());
        // Rover.py:211
        ([&]()->V{auto fn_353=attr(self_value(),"sleep");Args args_352;args_352.pos(scope_344->get("interval"));return invoke(fn_353,args_352);}());
    }
    // Rover.py:212
    return V(true);
return V{};
}),false);
// Official method Rover.wind_routine_flying, lines 214-218
register_method("wind_routine_flying",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_361=bind_arguments(official_args,signature,captured);
    // Rover.py:215
    if(attr(attr(self_value(),"task"),"has_lavitator").truth()){
        // Rover.py:216
        return ([&]()->V{auto fn_363=attr(self_value(),"flying");Args args_362;return invoke(fn_363,args_362);}());
    }else{
        // Rover.py:217
        if(([&]()->V{V compare_364=([&]()->V{auto fn_367=attr(self_value(),"current_resonance");Args args_366;return invoke(fn_367,args_366);}());V compare_365;V comparison_result_368;compare_365=V(0.15);comparison_result_368=compare_value(">",compare_364,compare_365);return comparison_result_368;}()).truth()){
            // Rover.py:218
            return V(true);
        }
    }
return V{};
}),false);
// Official method Rover.wind_routine_wait_down, lines 220-233
register_method("wind_routine_wait_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_forte_full",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_369=bind_arguments(official_args,signature,captured);
    // Rover.py:221
    if(([&]()->V{auto fn_371=attr(self_value(),"wind_routine_flying");Args args_370;return invoke(fn_371,args_370);}()).truth()){
        // Rover.py:222
        if(attr(attr(self_value(),"task"),"has_lavitator").truth()){
            // Rover.py:223
            ([&]()->V{auto fn_373=attr(self_value(),"wait_down");Args args_372;return invoke(fn_373,args_372);}());
        }else{
            // Rover.py:225
            ([&]()->V{auto fn_375=attr(attr(self_value(),"task"),"wait_until");Args args_374;args_374.pos(V::function([this,captured=capture_scope(scope_369,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_376=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_377=([&]()->V{auto fn_380=attr(self_value(),"current_resonance");Args args_379;return invoke(fn_380,args_379);}());V compare_378;V comparison_result_381;compare_378=V(0.15);comparison_result_381=compare_value("<",compare_377,compare_378);return comparison_result_381;}());
}));args_374.kw("post_action",V::function([this,captured=capture_scope(scope_369,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_382=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_384=attr(self_value(),"click");Args args_383;args_383.kw("interval",V(0.1));args_383.kw("after_sleep",V(0.01));return invoke(fn_384,args_383);}());
}));args_374.kw("time_out",V(2.5));return invoke(fn_375,args_374);}());
        }
    }
    // Rover.py:227
    if(scope_369->get("check_forte_full").truth()){
        // Rover.py:228
        ([&]()->V{auto fn_386=attr(self_value(),"sleep");Args args_385;args_385.pos(V(0.03));return invoke(fn_386,args_385);}());
        // Rover.py:229
        if(([&]()->V{auto fn_388=attr(self_value(),"is_forte_full");Args args_387;return invoke(fn_388,args_387);}()).truth()){
            // Rover.py:230
            ([&]()->V{auto fn_390=attr(self_value(),"send_resonance_key");Args args_389;return invoke(fn_390,args_389);}());
        }
    }else{
        // Rover.py:232
        ([&]()->V{auto fn_392=attr(self_value(),"sleep");Args args_391;args_391.pos(V(0.01));return invoke(fn_392,args_391);}());
    }
    // Rover.py:233
    return V(true);
return V{};
}),false);
// Official method Rover.perform_basic_routine, lines 235-243
register_method("perform_basic_routine",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_393=bind_arguments(official_args,signature,captured);
scope_393->set("liber",V::missing());
scope_393->set("res",V::missing());
    // Rover.py:236
    if(attr(self_value(),"has_intro").truth()){
        // Rover.py:237
        ([&]()->V{auto fn_395=attr(self_value(),"continues_normal_attack");Args args_394;args_394.pos(([&]()->V{V left_396=attr(self_value(),"intro_motion_freeze_duration");V right_397=V(0.2);return official::binary("+",left_396,right_397);}()));return invoke(fn_395,args_394);}());
    }
    // Rover.py:238
    ([&]()->V{auto fn_399=attr(self_value(),"wait_down");Args args_398;return invoke(fn_399,args_398);}());
    // Rover.py:239
    ([&]()->V{auto fn_401=attr(self_value(),"click_echo");Args args_400;return invoke(fn_401,args_400);}());
    // Rover.py:240
    {V value_402=([&]()->V{auto fn_404=attr(self_value(),"click_liberation");Args args_403;args_403.kw("send_click",V(true));return invoke(fn_404,args_403);}());scope_393->set("liber",value_402);}
    // Rover.py:241
    {V value_405=item(([&]()->V{auto fn_407=attr(self_value(),"click_resonance");Args args_406;args_406.kw("send_click",V(true));return invoke(fn_407,args_406);}()),V(0LL));scope_393->set("res",value_405);}
    // Rover.py:242
    if(unary("not",([&]()->V{V operand_408;operand_408=scope_393->get("liber");if(operand_408.truth())return operand_408;return scope_393->get("res");}())).truth()){
        // Rover.py:243
        ([&]()->V{auto fn_410=attr(self_value(),"continues_normal_attack");Args args_409;args_409.pos(V(1LL));return invoke(fn_410,args_409);}());
    }
return V{};
}),false);
}
}
