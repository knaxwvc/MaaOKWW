#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Cartethyia.py
// SHA256 0b9e70249763675990c85cf621f021754473370ccb8ba61affe26d9ba475c901
void OfficialCharacter::install_Cartethyia(){
auto scope=std::make_shared<Scope>();
// Official method Cartethyia.__init__, lines 7-16
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:8
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Cartethyia");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Cartethyia.py:9
    {V value_6=V(true);set_attr(self_value(),"is_cartethyia",value_6);}
    // Cartethyia.py:10
    {V value_7=([&]()->V{V dictionary_8=V::dict();set_item(dictionary_8,V("sword1"),V{});set_item(dictionary_8,V("sword2"),V{});set_item(dictionary_8,V("sword3"),V{});return dictionary_8;}());set_attr(self_value(),"buffs",value_7);}
    // Cartethyia.py:11
    {V value_9=V{};set_attr(self_value(),"template_shape",value_9);}
    // Cartethyia.py:12
    {V value_10=V(false);set_attr(self_value(),"try_mid_air_attack_once",value_10);}
    // Cartethyia.py:13
    {V value_11=V(false);set_attr(self_value(),"transform",value_11);}
    // Cartethyia.py:14
    {V value_12=unary("-",V(1LL));set_attr(self_value(),"res_time",value_12);}
    // Cartethyia.py:15
    {V value_13=unary("-",V(1LL));set_attr(self_value(),"n4_time",value_13);}
    // Cartethyia.py:16
    ([&]()->V{auto fn_15=attr(self_value(),"init_template");Args args_14;return invoke(fn_15,args_14);}());
return V{};
}),false);
// Official method Cartethyia.intro_motion_freeze_duration, lines 19-20
register_method("@get:intro_motion_freeze_duration",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_16=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:20
    return (attr(self_value(),"is_cartethyia").truth()?V(0.6):V(0.78));
return V{};
}),false);
// Official method Cartethyia.intro_motion_freeze_duration, lines 23-24
register_method("@set:intro_motion_freeze_duration",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"_",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_17=bind_arguments(official_args,signature,captured);
return V{};
}),false);
// Official method Cartethyia.init_template, lines 26-34
register_method("init_template",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_18=bind_arguments(official_args,signature,captured);
scope_18->set("h",V::missing());
scope_18->set("original_mat",V::missing());
scope_18->set("target_box",V::missing());
scope_18->set("template",V::missing());
    // Cartethyia.py:27
    {V value_19=item(attr(attr(attr(self_value(),"task"),"frame"),"shape"),V::slice(V{},V(2LL),V{}));set_attr(self_value(),"template_shape",value_19);}
    // Cartethyia.py:28
    {V value_20=([&]()->V{auto fn_22=attr(attr(self_value(),"task"),"get_feature_by_name");Args args_21;args_21.pos(V("forte_cartethyia_sword3"));return invoke(fn_22,args_21);}());scope_18->set("template",value_20);}
    // Cartethyia.py:29
    {V value_23=attr(scope_18->get("template"),"mat");scope_18->set("original_mat",value_23);}
    // Cartethyia.py:30
    {V value_24=item(attr(scope_18->get("original_mat"),"shape"),V(0LL));scope_18->set("h",value_24);}
    // Cartethyia.py:31
    {V value_25=item(scope_18->get("original_mat"),V::slice(V{},([&]()->V{auto fn_27=global("int","Cartethyia");Args args_26;args_26.pos(([&]()->V{V left_28=scope_18->get("h");V right_29=V(0.5);return official::binary("*",left_28,right_29);}()));return invoke(fn_27,args_26);}()),V{}));set_attr(self_value(),"sword3_half_mat",value_25);}
    // Cartethyia.py:32
    {V value_30=([&]()->V{auto fn_32=attr(attr(self_value(),"task"),"get_box_by_name");Args args_31;args_31.pos(V("forte_cartethyia_sword3"));return invoke(fn_32,args_31);}());scope_18->set("target_box",value_30);}
    // Cartethyia.py:33
    {V value_33=([&]()->V{auto fn_35=global("int","Cartethyia");Args args_34;args_34.pos(([&]()->V{V left_36=scope_18->get("h");V right_37=V(0.6);return official::binary("*",left_36,right_37);}()));return invoke(fn_35,args_34);}());set_attr(scope_18->get("target_box"),"height",value_33);}
    // Cartethyia.py:34
    {V value_38=scope_18->get("target_box");set_attr(self_value(),"sword3_half_box",value_38);}
return V{};
}),false);
// Official method Cartethyia.on_combat_end, lines 36-49
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_39=bind_arguments(official_args,signature,captured);
scope_39->set("current_char",V::missing());
scope_39->set("next_char",V::missing());
scope_39->set("start",V::missing());
    // Cartethyia.py:37
    if(unary("not",attr(self_value(),"is_cartethyia")).truth()){
        // Cartethyia.py:38
        {V value_40=([&]()->V{auto fn_42=global("str","Cartethyia");Args args_41;args_41.pos(([&]()->V{V left_43=([&]()->V{V left_45=([&]()->V{V left_47=attr(self_value(),"index");V right_48=V(1LL);return official::binary("+",left_47,right_48);}());V right_46=([&]()->V{auto fn_50=global("len","Cartethyia");Args args_49;args_49.pos(scope_39->get("chars"));return invoke(fn_50,args_49);}());return official::binary("%",left_45,right_46);}());V right_44=V(1LL);return official::binary("+",left_43,right_44);}()));return invoke(fn_42,args_41);}());scope_39->set("next_char",value_40);}
        // Cartethyia.py:39
        ([&]()->V{auto fn_52=attr(attr(self_value(),"logger"),"debug");Args args_51;args_51.pos(V(std::string{}+"on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch next char: "+format_value(scope_39->get("next_char"),"",-1)));return invoke(fn_52,args_51);}());
        // Cartethyia.py:40
        {V value_53=([&]()->V{auto fn_55=attr(global("time","Cartethyia"),"time");Args args_54;return invoke(fn_55,args_54);}());scope_39->set("start",value_53);}
        // Cartethyia.py:41
                while(([&]()->V{V compare_69=([&]()->V{V left_71=([&]()->V{auto fn_74=attr(global("time","Cartethyia"),"time");Args args_73;return invoke(fn_74,args_73);}());V right_72=scope_39->get("start");return official::binary("-",left_71,right_72);}());V compare_70;V comparison_result_75;compare_70=V(6LL);comparison_result_75=compare_value("<",compare_69,compare_70);return comparison_result_75;}()).truth()){
            // Cartethyia.py:42
            ([&]()->V{auto fn_57=attr(attr(self_value(),"task"),"load_chars");Args args_56;return invoke(fn_57,args_56);}());
            // Cartethyia.py:43
            {V value_58=([&]()->V{auto fn_60=attr(attr(self_value(),"task"),"get_current_char");Args args_59;args_59.kw("raise_exception",V(false));return invoke(fn_60,args_59);}());scope_39->set("current_char",value_58);}
            // Cartethyia.py:44
            if(unary("not",([&]()->V{auto fn_62=global("isinstance","Cartethyia");Args args_61;args_61.pos(scope_39->get("current_char"));args_61.pos(([&]()->V{auto fn_64=global("type","Cartethyia");Args args_63;args_63.pos(self_value());return invoke(fn_64,args_63);}()));return invoke(fn_62,args_61);}())).truth()){
                // Cartethyia.py:45
                break;
            }else{
                // Cartethyia.py:47
                ([&]()->V{auto fn_66=attr(attr(self_value(),"task"),"send_key");Args args_65;args_65.pos(scope_39->get("next_char"));return invoke(fn_66,args_65);}());
            }
            // Cartethyia.py:48
            ([&]()->V{auto fn_68=attr(self_value(),"sleep");Args args_67;args_67.pos(V(0.2));args_67.pos(V(false));return invoke(fn_68,args_67);}());
        }
        // Cartethyia.py:49
        ([&]()->V{auto fn_77=attr(attr(self_value(),"logger"),"debug");Args args_76;args_76.pos(V(std::string{}+"on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch end"));return invoke(fn_77,args_76);}());
    }
return V{};
}),false);
// Official method Cartethyia.get_switch_priority, lines 51-54
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_78=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:52
    if(unary("not",attr(self_value(),"is_cartethyia")).truth()){
        // Cartethyia.py:53
        return attr(global("SwitchPriority","Cartethyia"),"MUST");
    }
    // Cartethyia.py:54
    return ([&]()->V{auto fn_82=attr(([&]()->V{auto fn_80=global("super","Cartethyia");Args args_79;return invoke(fn_80,args_79);}()),"get_switch_priority");Args args_81;args_81.pos(scope_78->get("current_char"));args_81.pos(scope_78->get("has_intro"));args_81.pos(scope_78->get("target_low_con"));return invoke(fn_82,args_81);}());
return V{};
}),false);
// Official method Cartethyia.do_perform, lines 56-91
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_83=bind_arguments(official_args,signature,captured);
scope_83->set("start",V::missing());
scope_83->set("time_out",V::missing());
    // Cartethyia.py:57
    {V value_84=V(false);set_attr(self_value(),"transform",value_84);}
    // Cartethyia.py:58
    if(attr(self_value(),"has_intro").truth()){
        // Cartethyia.py:59
        ([&]()->V{auto fn_86=attr(self_value(),"continues_normal_attack");Args args_85;args_85.pos(V(1.2));return invoke(fn_86,args_85);}());
    }else{
        // Cartethyia.py:61
        ([&]()->V{auto fn_88=attr(self_value(),"click_echo");Args args_87;args_87.kw("time_out",V(0LL));return invoke(fn_88,args_87);}());
    }
    // Cartethyia.py:62
    if(([&]()->V{auto fn_90=attr(self_value(),"is_small");Args args_89;return invoke(fn_90,args_89);}()).truth()){
        // Cartethyia.py:63
        ([&]()->V{auto fn_92=attr(attr(self_value(),"logger"),"info");Args args_91;args_91.pos(V(std::string{}+"is cartethyia"));return invoke(fn_92,args_91);}());
        // Cartethyia.py:64
        ([&]()->V{auto fn_94=attr(self_value(),"wait_down");Args args_93;return invoke(fn_94,args_93);}());
        // Cartethyia.py:65
        if(([&]()->V{auto fn_96=attr(self_value(),"acquire_missing_buffs");Args args_95;return invoke(fn_96,args_95);}()).truth()){
            // Cartethyia.py:66
            return ([&]()->V{auto fn_98=attr(self_value(),"switch_next_char");Args args_97;return invoke(fn_98,args_97);}());
        }
        // Cartethyia.py:67
        ([&]()->V{auto fn_100=attr(self_value(),"check_combat");Args args_99;return invoke(fn_100,args_99);}());
        // Cartethyia.py:68
        ([&]()->V{auto fn_102=attr(self_value(),"try_mid_air_attack");Args args_101;return invoke(fn_102,args_101);}());
        // Cartethyia.py:69
        ([&]()->V{auto fn_104=attr(self_value(),"check_combat");Args args_103;return invoke(fn_104,args_103);}());
        // Cartethyia.py:70
        if(([&]()->V{auto fn_106=attr(self_value(),"click_liberation");Args args_105;return invoke(fn_106,args_105);}()).truth()){
            // Cartethyia.py:71
            {V value_107=V(false);set_attr(self_value(),"is_cartethyia",value_107);}
            // Cartethyia.py:72
            {V value_108=unary("-",V(1LL));set_attr(self_value(),"last_res",value_108);}
            // Cartethyia.py:73
            {V value_109=V(true);set_attr(self_value(),"transform",value_109);}
        }else{
            // Cartethyia.py:74
            if(unary("not",([&]()->V{auto fn_111=attr(self_value(),"is_small");Args args_110;return invoke(fn_111,args_110);}())).truth()){
                // Cartethyia.py:75
                {V value_112=V(true);set_attr(self_value(),"transform",value_112);}
            }
        }
    }else{
        // Cartethyia.py:77
        ([&]()->V{auto fn_114=attr(attr(self_value(),"logger"),"info");Args args_113;args_113.pos(V(std::string{}+"is fleurdelys"));return invoke(fn_114,args_113);}());
    }
    // Cartethyia.py:78
    if(([&]()->V{auto fn_116=attr(self_value(),"click_resonance_with_lib_big");Args args_115;return invoke(fn_116,args_115);}()).truth()){
    }else{
        // Cartethyia.py:81
        {V value_117=(([&]()->V{auto fn_119=attr(self_value(),"is_small");Args args_118;return invoke(fn_119,args_118);}()).truth()?V(1.1):([&]()->V{auto fn_121=attr(self_value(),"fleurdelys_n4_duration");Args args_120;return invoke(fn_121,args_120);}()));scope_83->set("time_out",value_117);}
        // Cartethyia.py:82
        {V value_122=([&]()->V{auto fn_124=attr(global("time","Cartethyia"),"time");Args args_123;return invoke(fn_124,args_123);}());scope_83->set("start",value_122);}
        // Cartethyia.py:83
                while(([&]()->V{V compare_135=([&]()->V{V left_137=([&]()->V{auto fn_140=attr(global("time","Cartethyia"),"time");Args args_139;return invoke(fn_140,args_139);}());V right_138=scope_83->get("start");return official::binary("-",left_137,right_138);}());V compare_136;V comparison_result_141;compare_136=scope_83->get("time_out");comparison_result_141=compare_value("<",compare_135,compare_136);return comparison_result_141;}()).truth()){
            // Cartethyia.py:84
            if(([&]()->V{auto fn_126=attr(self_value(),"try_lib_big");Args args_125;return invoke(fn_126,args_125);}()).truth()){
                // Cartethyia.py:85
                return ([&]()->V{auto fn_128=attr(self_value(),"switch_next_char");Args args_127;return invoke(fn_128,args_127);}());
            }
            // Cartethyia.py:86
            ([&]()->V{auto fn_130=attr(self_value(),"click_with_interval");Args args_129;return invoke(fn_130,args_129);}());
            // Cartethyia.py:87
            ([&]()->V{auto fn_132=attr(self_value(),"check_combat");Args args_131;return invoke(fn_132,args_131);}());
            // Cartethyia.py:88
            ([&]()->V{auto fn_134=attr(attr(self_value(),"task"),"next_frame");Args args_133;return invoke(fn_134,args_133);}());
        }
        // Cartethyia.py:89
        {V value_142=([&]()->V{auto fn_144=attr(global("time","Cartethyia"),"time");Args args_143;return invoke(fn_144,args_143);}());set_attr(self_value(),"n4_time",value_142);}
    }
    // Cartethyia.py:90
    ([&]()->V{auto fn_146=attr(self_value(),"try_lib_big");Args args_145;return invoke(fn_146,args_145);}());
    // Cartethyia.py:91
    ([&]()->V{auto fn_148=attr(self_value(),"switch_next_char");Args args_147;return invoke(fn_148,args_147);}());
return V{};
}),false);
// Official method Cartethyia.fleurdelys_n4_duration, lines 93-106
register_method("fleurdelys_n4_duration",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
scope_149->set("backswing",V::missing());
scope_149->set("duration",V::missing());
    // Cartethyia.py:94
    if(([&]()->V{V operand_150;operand_150=unary("not",attr(self_value(),"transform"));if(!operand_150.truth())return operand_150;return attr(self_value(),"has_intro");}()).truth()){
        // Cartethyia.py:95
        {V value_151=([&]()->V{V left_152=V(3.9);V right_153=([&]()->V{V left_154=([&]()->V{auto fn_157=attr(global("time","Cartethyia"),"time");Args args_156;return invoke(fn_157,args_156);}());V right_155=attr(self_value(),"last_perform");return official::binary("-",left_154,right_155);}());return official::binary("-",left_152,right_153);}());scope_149->set("duration",value_151);}
    }else{
        // Cartethyia.py:96
        if(([&]()->V{V operand_158;operand_158=attr(self_value(),"transform");if(operand_158.truth())return operand_158;operand_158=([&]()->V{auto fn_160=attr(self_value(),"is_first_engage");Args args_159;return invoke(fn_160,args_159);}());if(operand_158.truth())return operand_158;return ([&]()->V{V compare_161=([&]()->V{auto fn_164=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_163;args_163.pos(attr(self_value(),"n4_time"));args_163.kw("intro_motion_freeze",V(true));return invoke(fn_164,args_163);}());V compare_162;V comparison_result_165;compare_162=V(1.5);comparison_result_165=compare_value("<",compare_161,compare_162);return comparison_result_165;}());}()).truth()){
            // Cartethyia.py:98
            {V value_166=V(3.25);scope_149->set("duration",value_166);}
        }else{
            // Cartethyia.py:99
            if(([&]()->V{V compare_167=([&]()->V{V assigned_169=([&]()->V{auto fn_171=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_170;args_170.pos(attr(self_value(),"res_time"));args_170.kw("intro_motion_freeze",V(true));return invoke(fn_171,args_170);}());scope_149->set("backswing",assigned_169);return assigned_169;}());V compare_168;V comparison_result_172;compare_168=V(2.5);comparison_result_172=compare_value("<",compare_167,compare_168);return comparison_result_172;}()).truth()){
                // Cartethyia.py:100
                {V value_173=([&]()->V{V left_174=V(2LL);V right_175=([&]()->V{auto fn_177=global("max","Cartethyia");Args args_176;args_176.pos(V(0LL));args_176.pos(([&]()->V{V left_178=V(1.6);V right_179=scope_149->get("backswing");return official::binary("-",left_178,right_179);}()));return invoke(fn_177,args_176);}());return official::binary("+",left_174,right_175);}());scope_149->set("duration",value_173);}
            }else{
                // Cartethyia.py:102
                {V value_180=([&]()->V{V left_181=V(1.9);V right_182=([&]()->V{V left_183=([&]()->V{auto fn_186=attr(global("time","Cartethyia"),"time");Args args_185;return invoke(fn_186,args_185);}());V right_184=attr(self_value(),"last_perform");return official::binary("-",left_183,right_184);}());return official::binary("-",left_181,right_182);}());scope_149->set("duration",value_180);}
            }
        }
    }
    // Cartethyia.py:103
    {V value_187=unary("-",V(1LL));set_attr(self_value(),"n4_time",value_187);}
    // Cartethyia.py:104
    {V value_188=unary("-",V(1LL));set_attr(self_value(),"res_time",value_188);}
    // Cartethyia.py:105
    ([&]()->V{auto fn_190=attr(attr(self_value(),"logger"),"debug");Args args_189;args_189.pos(V(std::string{}+"fleurdelys_n4_duration "+format_value(scope_149->get("duration"),"",-1)));return invoke(fn_190,args_189);}());
    // Cartethyia.py:106
    return scope_149->get("duration");
return V{};
}),false);
// Official method Cartethyia.click_resonance_with_lib_big, lines 108-145
register_method("click_resonance_with_lib_big",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_191=bind_arguments(official_args,signature,captured);
scope_191->set("clicked",V::missing());
scope_191->set("current_resonance",V::missing());
scope_191->set("last_click",V::missing());
scope_191->set("now",V::missing());
scope_191->set("resonance_click_time",V::missing());
    // Cartethyia.py:109
    if(([&]()->V{auto fn_193=attr(self_value(),"has_cd");Args args_192;args_192.pos(V("resonance"));return invoke(fn_193,args_192);}()).truth()){
        // Cartethyia.py:110
        return V(false);
    }
    // Cartethyia.py:111
    {V value_194=V(false);scope_191->set("clicked",value_194);}
    // Cartethyia.py:112
    ([&]()->V{auto fn_196=attr(attr(self_value(),"logger"),"debug");Args args_195;args_195.pos(V(std::string{}+"click_resonance start"));return invoke(fn_196,args_195);}());
    // Cartethyia.py:113
    {V value_197=V(0LL);scope_191->set("last_click",value_197);}
    // Cartethyia.py:114
    {V value_198=V(0LL);scope_191->set("resonance_click_time",value_198);}
    // Cartethyia.py:115
        while(V(true).truth()){
        // Cartethyia.py:116
        if(([&]()->V{V operand_199;operand_199=([&]()->V{V compare_200=scope_191->get("resonance_click_time");V compare_201;V comparison_result_202;compare_201=V(0LL);comparison_result_202=compare_value("!=",compare_200,compare_201);return comparison_result_202;}());if(!operand_199.truth())return operand_199;return ([&]()->V{V compare_203=([&]()->V{V left_205=([&]()->V{auto fn_208=attr(global("time","Cartethyia"),"time");Args args_207;return invoke(fn_208,args_207);}());V right_206=scope_191->get("resonance_click_time");return official::binary("-",left_205,right_206);}());V compare_204;V comparison_result_209;compare_204=V(8LL);comparison_result_209=compare_value(">",compare_203,compare_204);return comparison_result_209;}());}()).truth()){
            // Cartethyia.py:117
            {V value_210=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_210);}
            // Cartethyia.py:118
            ([&]()->V{auto fn_212=attr(attr(self_value(),"logger"),"error");Args args_211;args_211.pos(V(std::string{}+"click_resonance too long, breaking "+format_value(([&]()->V{V left_213=([&]()->V{auto fn_216=attr(global("time","Cartethyia"),"time");Args args_215;return invoke(fn_216,args_215);}());V right_214=scope_191->get("resonance_click_time");return official::binary("-",left_213,right_214);}()),"",-1)));return invoke(fn_212,args_211);}());
            // Cartethyia.py:119
            ([&]()->V{auto fn_218=attr(attr(self_value(),"task"),"screenshot");Args args_217;args_217.pos(V("click_resonance too long, breaking"));return invoke(fn_218,args_217);}());
            // Cartethyia.py:120
            break;
        }
        // Cartethyia.py:121
        ([&]()->V{auto fn_220=attr(self_value(),"check_combat");Args args_219;return invoke(fn_220,args_219);}());
        // Cartethyia.py:122
        {V value_221=([&]()->V{auto fn_223=attr(global("time","Cartethyia"),"time");Args args_222;return invoke(fn_223,args_222);}());scope_191->set("now",value_221);}
        // Cartethyia.py:123
        {V value_224=([&]()->V{auto fn_226=attr(self_value(),"current_resonance");Args args_225;return invoke(fn_226,args_225);}());scope_191->set("current_resonance",value_224);}
        // Cartethyia.py:124
        if(unary("not",([&]()->V{auto fn_228=attr(self_value(),"resonance_available");Args args_227;return invoke(fn_228,args_227);}())).truth()){
            // Cartethyia.py:125
            ([&]()->V{auto fn_230=attr(attr(self_value(),"logger"),"debug");Args args_229;args_229.pos(V(std::string{}+"click_resonance not available break"));return invoke(fn_230,args_229);}());
            // Cartethyia.py:126
            break;
        }
        // Cartethyia.py:127
        ([&]()->V{auto fn_232=attr(attr(self_value(),"logger"),"debug");Args args_231;args_231.pos(V(std::string{}+"click_resonance resonance_available click "+format_value(scope_191->get("current_resonance"),"",-1)));return invoke(fn_232,args_231);}());
        // Cartethyia.py:129
        if(([&]()->V{V compare_233=([&]()->V{V left_235=scope_191->get("now");V right_236=scope_191->get("last_click");return official::binary("-",left_235,right_236);}());V compare_234;V comparison_result_237;compare_234=V(0.1);comparison_result_237=compare_value(">",compare_233,compare_234);return comparison_result_237;}()).truth()){
            // Cartethyia.py:130
            if(([&]()->V{V operand_238;operand_238=([&]()->V{V compare_239=scope_191->get("current_resonance");V compare_240;V comparison_result_241;compare_240=V(0LL);comparison_result_241=compare_value(">",compare_239,compare_240);return comparison_result_241;}());if(!operand_238.truth())return operand_238;return ([&]()->V{auto fn_243=attr(self_value(),"resonance_available");Args args_242;return invoke(fn_243,args_242);}());}()).truth()){
                // Cartethyia.py:131
                if(([&]()->V{V operand_244;operand_244=([&]()->V{V compare_245=scope_191->get("current_resonance");V compare_246;V comparison_result_247;compare_246=V(0.17);comparison_result_247=compare_value("<",compare_245,compare_246);return comparison_result_247;}());if(!operand_244.truth())return operand_244;return ([&]()->V{V compare_248=([&]()->V{V left_250=([&]()->V{auto fn_253=attr(global("time","Cartethyia"),"time");Args args_252;return invoke(fn_253,args_252);}());V right_251=scope_191->get("resonance_click_time");return official::binary("-",left_250,right_251);}());V compare_249;V comparison_result_254;compare_249=V(2.5);comparison_result_254=compare_value("<",compare_248,compare_249);return comparison_result_254;}());}()).truth()){
                    // Cartethyia.py:132
                    ([&]()->V{auto fn_256=attr(self_value(),"click");Args args_255;return invoke(fn_256,args_255);}());
                    // Cartethyia.py:133
                    continue;
                }
                // Cartethyia.py:134
                if(([&]()->V{V compare_257=scope_191->get("resonance_click_time");V compare_258;V comparison_result_259;compare_258=V(0LL);comparison_result_259=compare_value("==",compare_257,compare_258);return comparison_result_259;}()).truth()){
                    // Cartethyia.py:135
                    {V value_260=V(true);scope_191->set("clicked",value_260);}
                    // Cartethyia.py:136
                    {V value_261=scope_191->get("now");scope_191->set("resonance_click_time",value_261);}
                }
                // Cartethyia.py:137
                ([&]()->V{auto fn_263=attr(self_value(),"send_resonance_key");Args args_262;return invoke(fn_263,args_262);}());
            }
            // Cartethyia.py:138
            {V value_264=scope_191->get("now");scope_191->set("last_click",value_264);}
        }
        // Cartethyia.py:139
        if(([&]()->V{auto fn_266=attr(self_value(),"try_lib_big");Args args_265;return invoke(fn_266,args_265);}()).truth()){
            // Cartethyia.py:140
            break;
        }
        // Cartethyia.py:141
        ([&]()->V{auto fn_268=attr(attr(self_value(),"task"),"next_frame");Args args_267;return invoke(fn_268,args_267);}());
    }
    // Cartethyia.py:142
    if(scope_191->get("clicked").truth()){
        // Cartethyia.py:143
        ([&]()->V{auto fn_270=attr(self_value(),"record_resonance_use");Args args_269;return invoke(fn_270,args_269);}());
        // Cartethyia.py:144
        {V value_271=([&]()->V{auto fn_273=attr(global("time","Cartethyia"),"time");Args args_272;return invoke(fn_273,args_272);}());set_attr(self_value(),"res_time",value_271);}
    }
    // Cartethyia.py:145
    return scope_191->get("clicked");
return V{};
}),false);
// Official method Cartethyia.is_mid_air_attack_available, lines 147-158
register_method("is_mid_air_attack_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_274=bind_arguments(official_args,signature,captured);
scope_274->set("box",V::missing());
scope_274->set("contrast_val",V::missing());
scope_274->set("cropped",V::missing());
scope_274->set("gray",V::missing());
scope_274->set("mean_val",V::missing());
    // Cartethyia.py:148
    if(attr(self_value(),"is_cartethyia").truth()){
        // Cartethyia.py:149
        {V value_275=([&]()->V{auto fn_277=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_276;args_276.pos(V(3840LL));args_276.pos(V(2160LL));args_276.pos(V(2298LL));args_276.pos(V(1997LL));args_276.pos(V(2361LL));args_276.pos(V(2022LL));args_276.kw("name",V("inner_cartethyia_space"));args_276.kw("hcenter",V(true));return invoke(fn_277,args_276);}());scope_274->set("box",value_275);}
        // Cartethyia.py:151
        ([&]()->V{auto fn_279=attr(attr(self_value(),"task"),"draw_boxes");Args args_278;args_278.pos(attr(scope_274->get("box"),"name"));args_278.pos(scope_274->get("box"));return invoke(fn_279,args_278);}());
        // Cartethyia.py:152
        if(([&]()->V{V compare_280=([&]()->V{auto fn_283=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_282;args_282.pos(global("forte_white_color","Cartethyia"));args_282.pos(scope_274->get("box"));return invoke(fn_283,args_282);}());V compare_281;V comparison_result_284;compare_281=V(0.15);comparison_result_284=compare_value(">",compare_280,compare_281);return comparison_result_284;}()).truth()){
            // Cartethyia.py:153
            {V value_285=([&]()->V{auto fn_287=attr(scope_274->get("box"),"crop_frame");Args args_286;args_286.pos(attr(attr(self_value(),"task"),"frame"));return invoke(fn_287,args_286);}());scope_274->set("cropped",value_285);}
            // Cartethyia.py:154
            {V value_288=([&]()->V{auto fn_290=attr(global("cv2","Cartethyia"),"cvtColor");Args args_289;args_289.pos(scope_274->get("cropped"));args_289.pos(attr(global("cv2","Cartethyia"),"COLOR_BGR2GRAY"));return invoke(fn_290,args_289);}());scope_274->set("gray",value_288);}
            // Cartethyia.py:155
            {V value_291=([&]()->V{auto fn_293=attr(global("np","Cartethyia"),"mean");Args args_292;args_292.pos(scope_274->get("gray"));return invoke(fn_293,args_292);}());scope_274->set("mean_val",value_291);}
            // Cartethyia.py:156
            {V value_294=([&]()->V{auto fn_296=attr(global("np","Cartethyia"),"std");Args args_295;args_295.pos(scope_274->get("gray"));return invoke(fn_296,args_295);}());scope_274->set("contrast_val",value_294);}
            // Cartethyia.py:157
            ([&]()->V{auto fn_298=attr(attr(self_value(),"logger"),"debug");Args args_297;args_297.pos(V(std::string{}+"cartethyia_space mean "+format_value(scope_274->get("mean_val"),"",-1)+" contrast "+format_value(scope_274->get("contrast_val"),"",-1)));return invoke(fn_298,args_297);}());
            // Cartethyia.py:158
            return ([&]()->V{V operand_299;operand_299=([&]()->V{V compare_300=scope_274->get("mean_val");V compare_301;V comparison_result_302;compare_301=V(190LL);comparison_result_302=compare_value(">",compare_300,compare_301);return comparison_result_302;}());if(!operand_299.truth())return operand_299;return ([&]()->V{V compare_303=scope_274->get("contrast_val");V compare_304;V comparison_result_305;compare_304=V(45LL);comparison_result_305=compare_value("<",compare_303,compare_304);return comparison_result_305;}());}());
        }
    }
return V{};
}),false);
// Official method Cartethyia.try_mid_air_attack, lines 160-187
register_method("try_mid_air_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"timeout",V(2LL)}},"","",{})](const Args& official_args)->V{
auto scope_306=bind_arguments(official_args,signature,captured);
scope_306->set("start",V::missing());
    // Cartethyia.py:161
    ([&]()->V{auto fn_308=attr(self_value(),"get_sword_buffs");Args args_307;return invoke(fn_308,args_307);}());
    // Cartethyia.py:162
    if(([&]()->V{V operand_309;operand_309=([&]()->V{auto fn_311=attr(self_value(),"liberation_available");Args args_310;return invoke(fn_311,args_310);}());if(operand_309.truth())return operand_309;operand_309=([&]()->V{auto fn_313=global("all","Cartethyia");Args args_312;args_312.pos(([&]()->V{auto fn_315=attr(attr(self_value(),"buffs"),"values");Args args_314;return invoke(fn_315,args_314);}()));return invoke(fn_313,args_312);}());if(operand_309.truth())return operand_309;return attr(self_value(),"try_mid_air_attack_once");}()).truth()){
    }else{
        // Cartethyia.py:165
        return V{};
    }
    // Cartethyia.py:166
    if(([&]()->V{auto fn_317=attr(self_value(),"is_mid_air_attack_available");Args args_316;return invoke(fn_317,args_316);}()).truth()){
        // Cartethyia.py:167
        ([&]()->V{auto fn_319=attr(attr(self_value(),"logger"),"info");Args args_318;args_318.pos(V("perform mid-air attack"));return invoke(fn_319,args_318);}());
        // Cartethyia.py:168
        {V value_320=([&]()->V{auto fn_322=attr(global("time","Cartethyia"),"time");Args args_321;return invoke(fn_322,args_321);}());scope_306->set("start",value_320);}
        // Cartethyia.py:169
                while(V(true).truth()){
            // Cartethyia.py:170
            ([&]()->V{auto fn_324=attr(attr(self_value(),"task"),"jump");Args args_323;args_323.kw("after_sleep",V(0.1));return invoke(fn_324,args_323);}());
            // Cartethyia.py:171
            if(([&]()->V{auto fn_326=attr(self_value(),"echo_available");Args args_325;return invoke(fn_326,args_325);}()).truth()){
                // Cartethyia.py:172
                ([&]()->V{auto fn_328=attr(self_value(),"click_echo");Args args_327;args_327.kw("time_out",V(0LL));return invoke(fn_328,args_327);}());
            }
            // Cartethyia.py:173
            ([&]()->V{auto fn_330=attr(attr(self_value(),"task"),"click");Args args_329;args_329.kw("after_sleep",V(0.1));return invoke(fn_330,args_329);}());
            // Cartethyia.py:174
            if(unary("not",([&]()->V{auto fn_332=attr(self_value(),"is_mid_air_attack_available");Args args_331;return invoke(fn_332,args_331);}())).truth()){
                // Cartethyia.py:175
                ([&]()->V{auto fn_334=attr(self_value(),"sleep");Args args_333;args_333.pos(V(0.4));return invoke(fn_334,args_333);}());
                // Cartethyia.py:176
                break;
            }
            // Cartethyia.py:177
            if(([&]()->V{V compare_335=([&]()->V{V left_337=([&]()->V{auto fn_340=attr(global("time","Cartethyia"),"time");Args args_339;return invoke(fn_340,args_339);}());V right_338=scope_306->get("start");return official::binary("-",left_337,right_338);}());V compare_336;V comparison_result_341;compare_336=scope_306->get("timeout");comparison_result_341=compare_value(">",compare_335,compare_336);return comparison_result_341;}()).truth()){
                // Cartethyia.py:178
                break;
            }
            // Cartethyia.py:179
            ([&]()->V{auto fn_343=attr(self_value(),"sleep");Args args_342;args_342.pos(V(0.1));return invoke(fn_343,args_342);}());
        }
    }else{
        // Cartethyia.py:180
        if(attr(self_value(),"try_mid_air_attack_once").truth()){
            // Cartethyia.py:181
            {V value_344=([&]()->V{auto fn_346=attr(global("time","Cartethyia"),"time");Args args_345;return invoke(fn_346,args_345);}());scope_306->set("start",value_344);}
            // Cartethyia.py:182
                        while(([&]()->V{V compare_355=([&]()->V{V left_357=([&]()->V{auto fn_360=attr(global("time","Cartethyia"),"time");Args args_359;return invoke(fn_360,args_359);}());V right_358=scope_306->get("start");return official::binary("-",left_357,right_358);}());V compare_356;V comparison_result_361;compare_356=V(0.8);comparison_result_361=compare_value("<",compare_355,compare_356);return comparison_result_361;}()).truth()){
                // Cartethyia.py:183
                ([&]()->V{auto fn_348=attr(attr(self_value(),"task"),"jump");Args args_347;args_347.kw("after_sleep",V(0.1));return invoke(fn_348,args_347);}());
                // Cartethyia.py:184
                if(([&]()->V{auto fn_350=attr(self_value(),"echo_available");Args args_349;return invoke(fn_350,args_349);}()).truth()){
                    // Cartethyia.py:185
                    ([&]()->V{auto fn_352=attr(self_value(),"click_echo");Args args_351;args_351.kw("time_out",V(0LL));return invoke(fn_352,args_351);}());
                }
                // Cartethyia.py:186
                ([&]()->V{auto fn_354=attr(attr(self_value(),"task"),"click");Args args_353;args_353.kw("after_sleep",V(0.1));return invoke(fn_354,args_353);}());
            }
        }
    }
    // Cartethyia.py:187
    {V value_362=V(false);set_attr(self_value(),"try_mid_air_attack_once",value_362);}
return V{};
}),false);
// Official method Cartethyia.is_small, lines 189-194
register_method("is_small",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_363=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:190
    if(([&]()->V{V compare_364=attr(self_value(),"template_shape");V compare_365;V comparison_result_366;compare_365=item(attr(attr(attr(self_value(),"task"),"frame"),"shape"),V::slice(V{},V(2LL),V{}));comparison_result_366=compare_value("!=",compare_364,compare_365);return comparison_result_366;}()).truth()){
        // Cartethyia.py:191
        ([&]()->V{auto fn_368=attr(self_value(),"init_template");Args args_367;return invoke(fn_368,args_367);}());
    }
    // Cartethyia.py:192
    {V value_369=([&]()->V{auto fn_371=global("bool","Cartethyia");Args args_370;args_370.pos(([&]()->V{auto fn_373=attr(attr(self_value(),"task"),"find_one");Args args_372;args_372.kw("template",attr(self_value(),"sword3_half_mat"));args_372.kw("box",attr(self_value(),"sword3_half_box"));args_372.kw("threshold",V(0.5));return invoke(fn_373,args_372);}()));return invoke(fn_371,args_370);}());set_attr(self_value(),"is_cartethyia",value_369);}
    // Cartethyia.py:194
    return attr(self_value(),"is_cartethyia");
return V{};
}),false);
// Official method Cartethyia.try_lib_big, lines 196-201
register_method("try_lib_big",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_374=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:197
    if(([&]()->V{auto fn_376=attr(self_value(),"is_lib_big_available");Args args_375;return invoke(fn_376,args_375);}()).truth()){
        // Cartethyia.py:198
        if(([&]()->V{auto fn_378=attr(self_value(),"click_liberation");Args args_377;return invoke(fn_378,args_377);}()).truth()){
            // Cartethyia.py:199
            {V value_379=V(true);set_attr(self_value(),"is_cartethyia",value_379);}
            // Cartethyia.py:200
            ([&]()->V{auto fn_381=attr(self_value(),"click_resonance");Args args_380;return invoke(fn_381,args_380);}());
            // Cartethyia.py:201
            return V(true);
        }
    }
return V{};
}),false);
// Official method Cartethyia.is_lib_big_available, lines 203-207
register_method("is_lib_big_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_382=bind_arguments(official_args,signature,captured);
scope_382->set("big",V::missing());
    // Cartethyia.py:204
    if(([&]()->V{V assigned_383=([&]()->V{auto fn_385=attr(attr(self_value(),"task"),"find_one");Args args_384;args_384.pos(V("lib_cartethyia_big"));return invoke(fn_385,args_384);}());scope_382->set("big",assigned_383);return assigned_383;}()).truth()){
        // Cartethyia.py:205
        ([&]()->V{auto fn_387=attr(attr(self_value(),"logger"),"debug");Args args_386;args_386.pos(([&]()->V{auto fn_389=attr(V("lib cartethyia big available {}"),"format");Args args_388;args_388.pos(attr(scope_382->get("big"),"confidence"));return invoke(fn_389,args_388);}()));return invoke(fn_387,args_386);}());
        // Cartethyia.py:206
        {V value_390=V(true);set_attr(self_value(),"_liberation_available",value_390);}
        // Cartethyia.py:207
        return V(true);
    }
return V{};
}),false);
// Official method Cartethyia.get_sword_buffs, lines 209-216
register_method("get_sword_buffs",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_391=bind_arguments(official_args,signature,captured);
    // Cartethyia.py:210
    {V value_392=([&]()->V{V dictionary_393=V::dict();set_item(dictionary_393,V("sword1"),([&]()->V{auto fn_395=global("bool","Cartethyia");Args args_394;args_394.pos(([&]()->V{auto fn_397=attr(attr(self_value(),"task"),"find_one");Args args_396;args_396.pos(V("forte_cartethyia_sword1"));args_396.kw("threshold",V(0.9));return invoke(fn_397,args_396);}()));return invoke(fn_395,args_394);}()));set_item(dictionary_393,V("sword2"),([&]()->V{auto fn_399=global("bool","Cartethyia");Args args_398;args_398.pos(([&]()->V{auto fn_401=attr(attr(self_value(),"task"),"find_one");Args args_400;args_400.pos(V("forte_cartethyia_sword2"));args_400.kw("threshold",V(0.9));return invoke(fn_401,args_400);}()));return invoke(fn_399,args_398);}()));set_item(dictionary_393,V("sword3"),([&]()->V{auto fn_403=global("bool","Cartethyia");Args args_402;args_402.pos(([&]()->V{auto fn_405=attr(attr(self_value(),"task"),"find_one");Args args_404;args_404.pos(V("forte_cartethyia_sword3"));args_404.kw("threshold",V(0.9));return invoke(fn_405,args_404);}()));return invoke(fn_403,args_402);}()));return dictionary_393;}());set_attr(self_value(),"buffs",value_392);}
    // Cartethyia.py:215
    ([&]()->V{auto fn_407=attr(attr(self_value(),"logger"),"debug");Args args_406;args_406.pos(V(std::string{}+"buffs "+format_value(attr(self_value(),"buffs"),"",-1)));return invoke(fn_407,args_406);}());
    // Cartethyia.py:216
    return attr(self_value(),"buffs");
return V{};
}),false);
// Official method Cartethyia.acquire_missing_buffs, lines 218-269
register_method("acquire_missing_buffs",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_408=bind_arguments(official_args,signature,captured);
scope_408->set("h",V::missing());
scope_408->set("half_box",V::missing());
scope_408->set("half_mat",V::missing());
scope_408->set("has_perform_action",V::missing());
scope_408->set("interrupt_handled",V::missing());
scope_408->set("k",V::missing());
scope_408->set("res",V::missing());
scope_408->set("start",V::missing());
scope_408->set("template",V::missing());
scope_408->set("time_out",V::missing());
scope_408->set("try_once",V::missing());
    // Cartethyia.py:219
    ([&]()->V{auto fn_410=attr(self_value(),"get_sword_buffs");Args args_409;return invoke(fn_410,args_409);}());
    // Cartethyia.py:220
    if(([&]()->V{auto fn_412=global("all","Cartethyia");Args args_411;args_411.pos(([&]()->V{auto fn_414=attr(attr(self_value(),"buffs"),"values");Args args_413;return invoke(fn_414,args_413);}()));return invoke(fn_412,args_411);}()).truth()){
        // Cartethyia.py:221
        return V(false);
    }
    // Cartethyia.py:222
    if(([&]()->V{V assigned_415=unary("not",([&]()->V{auto generator_scope_416=std::make_shared<Scope>(scope_408);auto iterator_417=official::iterate(V::list({V("sword2"),V("sword3")}));V value_418;while(iterator_417.next(value_418)){generator_scope_416->set("k",value_418);if(!item(attr(self_value(),"buffs"),generator_scope_416->get("k")).truth())return V(false);}return V(true);}()));scope_408->set("has_perform_action",assigned_415);return assigned_415;}()).truth()){
        // Cartethyia.py:223
        ([&]()->V{auto fn_420=attr(attr(self_value(),"logger"),"info");Args args_419;args_419.pos(V("acquire missing buffs"));return invoke(fn_420,args_419);}());
    }
    // Cartethyia.py:224
    if(unary("not",([&]()->V{auto fn_422=attr(attr(self_value(),"buffs"),"get");Args args_421;args_421.pos(V("sword2"));return invoke(fn_422,args_421);}())).truth()){
        // Cartethyia.py:225
        {V value_423=([&]()->V{auto fn_425=attr(attr(self_value(),"task"),"get_feature_by_name");Args args_424;args_424.pos(V("forte_cartethyia_sword2"));return invoke(fn_425,args_424);}());scope_408->set("template",value_423);}
        // Cartethyia.py:226
        {V value_426=item(attr(attr(scope_408->get("template"),"mat"),"shape"),V(0LL));scope_408->set("h",value_426);}
        // Cartethyia.py:227
        {V value_427=item(attr(scope_408->get("template"),"mat"),V::slice(V{},([&]()->V{auto fn_429=global("int","Cartethyia");Args args_428;args_428.pos(([&]()->V{V left_430=scope_408->get("h");V right_431=V(0.5);return official::binary("*",left_430,right_431);}()));return invoke(fn_429,args_428);}()),V{}));scope_408->set("half_mat",value_427);}
        // Cartethyia.py:228
        {V value_432=([&]()->V{auto fn_434=attr(attr(self_value(),"task"),"get_box_by_name");Args args_433;args_433.pos(V("forte_cartethyia_sword2"));return invoke(fn_434,args_433);}());scope_408->set("half_box",value_432);}
        // Cartethyia.py:229
        {V value_435=([&]()->V{auto fn_437=global("int","Cartethyia");Args args_436;args_436.pos(([&]()->V{V left_438=scope_408->get("h");V right_439=V(0.6);return official::binary("*",left_438,right_439);}()));return invoke(fn_437,args_436);}());set_attr(scope_408->get("half_box"),"height",value_435);}
        // Cartethyia.py:230
        {V value_440=V(3.5);scope_408->set("time_out",value_440);}
        // Cartethyia.py:231
        if(([&]()->V{V assigned_441=([&]()->V{auto fn_443=global("bool","Cartethyia");Args args_442;args_442.pos(([&]()->V{auto fn_445=attr(attr(self_value(),"task"),"find_one");Args args_444;args_444.kw("template",scope_408->get("half_mat"));args_444.kw("box",scope_408->get("half_box"));args_444.kw("threshold",V(0.85));return invoke(fn_445,args_444);}()));return invoke(fn_443,args_442);}());scope_408->set("try_once",assigned_441);return assigned_441;}()).truth()){
            // Cartethyia.py:232
            {V value_446=(unary("not",([&]()->V{auto fn_448=attr(self_value(),"is_first_engage");Args args_447;return invoke(fn_448,args_447);}())).truth()?V(2LL):V(2.5));scope_408->set("time_out",value_446);}
        }
        // Cartethyia.py:233
        {V value_449=([&]()->V{auto fn_451=attr(global("time","Cartethyia"),"time");Args args_450;return invoke(fn_451,args_450);}());scope_408->set("start",value_449);}
        // Cartethyia.py:234
        {V value_452=V(false);scope_408->set("interrupt_handled",value_452);}
        // Cartethyia.py:235
                while(([&]()->V{V compare_478=([&]()->V{V left_480=([&]()->V{auto fn_483=attr(global("time","Cartethyia"),"time");Args args_482;return invoke(fn_483,args_482);}());V right_481=scope_408->get("start");return official::binary("-",left_480,right_481);}());V compare_479;V comparison_result_484;compare_479=scope_408->get("time_out");comparison_result_484=compare_value("<",compare_478,compare_479);return comparison_result_484;}()).truth()){
            // Cartethyia.py:236
            if(([&]()->V{V operand_453;operand_453=unary("not",scope_408->get("try_once"));if(!operand_453.truth())return operand_453;return ([&]()->V{auto fn_455=attr(attr(self_value(),"task"),"find_one");Args args_454;args_454.kw("template",scope_408->get("half_mat"));args_454.kw("box",scope_408->get("half_box"));args_454.kw("threshold",V(0.85));return invoke(fn_455,args_454);}());}()).truth()){
                // Cartethyia.py:237
                break;
            }
            // Cartethyia.py:238
            if(([&]()->V{V operand_456;operand_456=unary("not",scope_408->get("interrupt_handled"));if(!operand_456.truth())return operand_456;return ([&]()->V{auto fn_458=attr(self_value(),"flying");Args args_457;return invoke(fn_458,args_457);}());}()).truth()){
                // Cartethyia.py:239
                {V value_459=(([&]()->V{V compare_460=scope_408->get("time_out");V compare_461;V comparison_result_462;compare_461=V(2LL);comparison_result_462=compare_value("==",compare_460,compare_461);return comparison_result_462;}()).truth()?V(2.5):scope_408->get("time_out"));scope_408->set("time_out",value_459);}
                // Cartethyia.py:240
                {V value_463=V(true);scope_408->set("interrupt_handled",value_463);}
                // Cartethyia.py:241
                ([&]()->V{auto fn_465=attr(attr(self_value(),"task"),"wait_until");Args args_464;args_464.pos(V::function([this,captured=capture_scope(scope_408,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_466=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_468=attr(self_value(),"flying");Args args_467;return invoke(fn_468,args_467);}()));
}));args_464.kw("time_out",V(3LL));return invoke(fn_465,args_464);}());
                // Cartethyia.py:242
                {V value_469=([&]()->V{auto fn_471=attr(global("time","Cartethyia"),"time");Args args_470;return invoke(fn_471,args_470);}());scope_408->set("start",value_469);}
            }
            // Cartethyia.py:243
            ([&]()->V{auto fn_473=attr(self_value(),"click");Args args_472;args_472.kw("interval",V(0.1));args_472.kw("after_sleep",V(0.01));return invoke(fn_473,args_472);}());
            // Cartethyia.py:244
            ([&]()->V{auto fn_475=attr(self_value(),"check_combat");Args args_474;return invoke(fn_475,args_474);}());
            // Cartethyia.py:245
            ([&]()->V{auto fn_477=attr(attr(self_value(),"task"),"next_frame");Args args_476;return invoke(fn_477,args_476);}());
        }
        // Cartethyia.py:246
        ([&]()->V{auto fn_486=attr(attr(self_value(),"logger"),"debug");Args args_485;args_485.pos(V(std::string{}+"sword2: click duration "+format_value(([&]()->V{V left_487=([&]()->V{auto fn_490=attr(global("time","Cartethyia"),"time");Args args_489;return invoke(fn_490,args_489);}());V right_488=scope_408->get("start");return official::binary("-",left_487,right_488);}()),"",-1)));return invoke(fn_486,args_485);}());
    }
    // Cartethyia.py:247
    {V value_491=V(false);scope_408->set("res",value_491);}
    // Cartethyia.py:248
    if(unary("not",([&]()->V{auto fn_493=attr(attr(self_value(),"buffs"),"get");Args args_492;args_492.pos(V("sword3"));return invoke(fn_493,args_492);}())).truth()){
        // Cartethyia.py:249
        {V value_494=item(([&]()->V{auto fn_496=attr(self_value(),"click_resonance");Args args_495;return invoke(fn_496,args_495);}()),V(0LL));scope_408->set("res",value_494);}
        // Cartethyia.py:250
        ([&]()->V{auto fn_498=attr(self_value(),"check_combat");Args args_497;return invoke(fn_498,args_497);}());
    }
    // Cartethyia.py:251
    if(([&]()->V{auto fn_500=attr(self_value(),"liberation_available");Args args_499;return invoke(fn_500,args_499);}()).truth()){
        // Cartethyia.py:252
        ([&]()->V{V operand_501;operand_501=scope_408->get("res");if(!operand_501.truth())return operand_501;return ([&]()->V{auto fn_503=attr(self_value(),"sleep");Args args_502;args_502.pos(V(0.2));return invoke(fn_503,args_502);}());}());
    }else{
        // Cartethyia.py:253
        if(scope_408->get("has_perform_action").truth()){
            // Cartethyia.py:254
            return V(true);
        }
    }
    // Cartethyia.py:255
    if(unary("not",([&]()->V{auto fn_505=attr(attr(self_value(),"buffs"),"get");Args args_504;args_504.pos(V("sword1"));return invoke(fn_505,args_504);}())).truth()){
        // Cartethyia.py:256
        if(unary("not",scope_408->get("has_perform_action")).truth()){
            // Cartethyia.py:257
            ([&]()->V{auto fn_507=attr(attr(self_value(),"logger"),"info");Args args_506;args_506.pos(V("acquire missing buffs"));return invoke(fn_507,args_506);}());
        }
        // Cartethyia.py:258
        ([&]()->V{auto fn_509=attr(attr(self_value(),"task"),"mouse_down");Args args_508;return invoke(fn_509,args_508);}());
        // Cartethyia.py:259
        {V value_510=([&]()->V{auto fn_512=attr(global("time","Cartethyia"),"time");Args args_511;return invoke(fn_512,args_511);}());scope_408->set("start",value_510);}
        // Cartethyia.py:260
                while(([&]()->V{V compare_517=([&]()->V{V left_519=([&]()->V{auto fn_522=attr(global("time","Cartethyia"),"time");Args args_521;return invoke(fn_522,args_521);}());V right_520=scope_408->get("start");return official::binary("-",left_519,right_520);}());V compare_518;V comparison_result_523;compare_518=V(1.5);comparison_result_523=compare_value("<",compare_517,compare_518);return comparison_result_523;}()).truth()){
            // Cartethyia.py:261
            if(([&]()->V{auto fn_514=attr(attr(self_value(),"task"),"find_one");Args args_513;args_513.pos(V("forte_cartethyia_sword1"));args_513.kw("threshold",V(0.9));return invoke(fn_514,args_513);}()).truth()){
                // Cartethyia.py:262
                break;
            }
            // Cartethyia.py:263
            ([&]()->V{auto fn_516=attr(attr(self_value(),"task"),"next_frame");Args args_515;return invoke(fn_516,args_515);}());
        }
        // Cartethyia.py:264
        ([&]()->V{auto fn_525=attr(attr(self_value(),"task"),"mouse_up");Args args_524;return invoke(fn_525,args_524);}());
        // Cartethyia.py:265
        ([&]()->V{auto fn_527=attr(self_value(),"check_combat");Args args_526;return invoke(fn_527,args_526);}());
        // Cartethyia.py:266
        ([&]()->V{auto fn_529=attr(attr(self_value(),"logger"),"debug");Args args_528;args_528.pos(V(std::string{}+"sword1: heavy_att duration "+format_value(([&]()->V{V left_530=([&]()->V{auto fn_533=attr(global("time","Cartethyia"),"time");Args args_532;return invoke(fn_533,args_532);}());V right_531=scope_408->get("start");return official::binary("-",left_530,right_531);}()),"",-1)));return invoke(fn_529,args_528);}());
    }
    // Cartethyia.py:267
    if(unary("not",([&]()->V{auto fn_535=global("any","Cartethyia");Args args_534;args_534.pos(([&]()->V{auto fn_537=attr(attr(self_value(),"buffs"),"values");Args args_536;return invoke(fn_537,args_536);}()));return invoke(fn_535,args_534);}())).truth()){
        // Cartethyia.py:268
        {V value_538=V(true);set_attr(self_value(),"try_mid_air_attack_once",value_538);}
    }
    // Cartethyia.py:269
    return unary("not",([&]()->V{auto fn_540=attr(self_value(),"liberation_available");Args args_539;return invoke(fn_540,args_539);}()));
return V{};
}),false);
}
}
