#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Hsin.py
// SHA256 319fcde254eee526b4d7340b9ef5b9e41021503a2d1b3af7e10863425c276337
void OfficialCharacter::install_Hsin(){
auto scope=std::make_shared<Scope>();
// Official method Hsin.__init__, lines 8-14
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Hsin.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Hsin");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Hsin.py:10
    {V value_6=V(false);set_attr(self_value(),"lib2_cast_this_turn",value_6);}
    // Hsin.py:11
    {V value_7=V{};set_attr(self_value(),"finisher_start",value_7);}
    // Hsin.py:12
    {V value_8=V(false);set_attr(self_value(),"finisher_e_sent",value_8);}
    // Hsin.py:13
    {V value_9=V(false);set_attr(self_value(),"h2_completed",value_9);}
    // Hsin.py:14
    {V value_10=V(0.0);set_attr(self_value(),"h2_guard_until",value_10);}
return V{};
}),false);
// Official method Hsin.skip_combat_check, lines 16-20
register_method("skip_combat_check",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
    // Hsin.py:17
    if(([&]()->V{V operand_12;operand_12=attr(self_value(),"h2_guard_until");if(!operand_12.truth())return operand_12;return ([&]()->V{V compare_13=([&]()->V{auto fn_16=attr(global("time","Hsin"),"time");Args args_15;return invoke(fn_16,args_15);}());V compare_14;V comparison_result_17;compare_14=attr(self_value(),"h2_guard_until");comparison_result_17=compare_value(">=",compare_13,compare_14);return comparison_result_17;}());}()).truth()){
        // Hsin.py:18
        ([&]()->V{auto fn_19=attr(attr(self_value(),"logger"),"info");Args args_18;args_18.pos(V("Hsin H2 protection expired; resume combat checks"));return invoke(fn_19,args_18);}());
        // Hsin.py:19
        {V value_20=V(0.0);set_attr(self_value(),"h2_guard_until",value_20);}
    }
    // Hsin.py:20
    return ([&]()->V{V compare_21=attr(self_value(),"h2_guard_until");V compare_22;V comparison_result_23;compare_22=V(0LL);comparison_result_23=compare_value(">",compare_21,compare_22);return comparison_result_23;}());
return V{};
}),false);
// Official method Hsin.do_perform, lines 22-35
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_24=bind_arguments(official_args,signature,captured);
    // Hsin.py:23
    {V value_25=V(false);set_attr(self_value(),"lib2_cast_this_turn",value_25);}
    // Hsin.py:24
    {V value_26=V{};set_attr(self_value(),"finisher_start",value_26);}
    // Hsin.py:25
    {V value_27=V(false);set_attr(self_value(),"finisher_e_sent",value_27);}
    // Hsin.py:26
    {V value_28=V(false);set_attr(self_value(),"h2_completed",value_28);}
    // Hsin.py:27
    {V value_29=V(0.0);set_attr(self_value(),"h2_guard_until",value_29);}
    // Hsin.py:28
    ([&]()->V{auto fn_31=attr(attr(self_value(),"logger"),"debug");Args args_30;args_30.pos(V(std::string{}+"Hsin perform start: has_intro="+format_value(attr(self_value(),"has_intro"),"",-1)));return invoke(fn_31,args_30);}());
    // Hsin.py:29
    {
    auto finally_32=on_scope_exit([&](){
        // Hsin.py:32
        {V value_33=V(0.0);set_attr(self_value(),"h2_guard_until",value_33);}
    });
        // Hsin.py:30
        ([&]()->V{auto fn_35=attr(self_value(),"perform_everything");Args args_34;return invoke(fn_35,args_34);}());
    }
    // Hsin.py:33
    ([&]()->V{auto fn_37=attr(attr(self_value(),"logger"),"debug");Args args_36;args_36.pos(V(std::string{}+"Hsin switch_next_char start: lib2_cast="+format_value(attr(self_value(),"lib2_cast_this_turn"),"",-1)));return invoke(fn_37,args_36);}());
    // Hsin.py:34
    ([&]()->V{auto fn_39=attr(self_value(),"switch_next_char");Args args_38;return invoke(fn_39,args_38);}());
    // Hsin.py:35
    ([&]()->V{auto fn_41=attr(attr(self_value(),"logger"),"debug");Args args_40;args_40.pos(V("Hsin switch_next_char end"));return invoke(fn_41,args_40);}());
return V{};
}),false);
// Official method Hsin.perform_everything, lines 37-139
register_method("perform_everything",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_42=bind_arguments(official_args,signature,captured);
scope_42->set("confirmed",V::missing());
scope_42->set("duration",V::missing());
scope_42->set("echoed",V::missing());
scope_42->set("heavy_type",V::missing());
scope_42->set("last_e_ready",V::missing());
scope_42->set("phase_duration",V::missing());
scope_42->set("phase_start",V::missing());
scope_42->set("ready",V::missing());
scope_42->set("remaining",V::missing());
scope_42->set("resonance",V::missing());
scope_42->set("resonance_start",V::missing());
scope_42->set("start",V::missing());
    // Hsin.py:38
    {V value_43=([&]()->V{auto fn_45=attr(global("time","Hsin"),"time");Args args_44;return invoke(fn_45,args_44);}());scope_42->set("start",value_43);}
    // Hsin.py:39
    {V value_46=(attr(self_value(),"has_intro").truth()?V(12LL):V(6LL));scope_42->set("duration",value_46);}
    // Hsin.py:40
    {V value_47=V{};scope_42->set("last_e_ready",value_47);}
    // Hsin.py:41
    ([&]()->V{auto fn_49=attr(attr(self_value(),"logger"),"debug");Args args_48;args_48.pos(V(std::string{}+"Hsin rotation start: duration="+format_value(scope_42->get("duration"),"",-1)));return invoke(fn_49,args_48);}());
    // Hsin.py:42
        while(V(true).truth()){
        // Hsin.py:43
        {V value_50=(([&]()->V{V compare_51=attr(self_value(),"finisher_start");V compare_52;V comparison_result_53;compare_52=V{};comparison_result_53=compare_value("is not",compare_51,compare_52);return comparison_result_53;}()).truth()?attr(self_value(),"finisher_start"):scope_42->get("start"));scope_42->set("phase_start",value_50);}
        // Hsin.py:44
        {V value_54=(([&]()->V{V compare_55=attr(self_value(),"finisher_start");V compare_56;V comparison_result_57;compare_56=V{};comparison_result_57=compare_value("is not",compare_55,compare_56);return comparison_result_57;}()).truth()?V(18LL):scope_42->get("duration"));scope_42->set("phase_duration",value_54);}
        // Hsin.py:45
        if(([&]()->V{V compare_58=([&]()->V{auto fn_61=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_60;args_60.pos(scope_42->get("phase_start"));return invoke(fn_61,args_60);}());V compare_59;V comparison_result_62;compare_59=scope_42->get("phase_duration");comparison_result_62=compare_value(">=",compare_58,compare_59);return comparison_result_62;}()).truth()){
            // Hsin.py:46
            ([&]()->V{auto fn_64=attr(attr(self_value(),"logger"),"debug");Args args_63;args_63.pos(V(std::string{}+"Hsin rotation timeout: finisher="+format_value(([&]()->V{V compare_65=attr(self_value(),"finisher_start");V compare_66;V comparison_result_67;compare_66=V{};comparison_result_67=compare_value("is not",compare_65,compare_66);return comparison_result_67;}()),"",-1)+", enhanced_e="+format_value(attr(self_value(),"finisher_e_sent"),"",-1)+", h2="+format_value(attr(self_value(),"h2_completed"),"",-1)));return invoke(fn_64,args_63);}());
            // Hsin.py:48
            if(unary("not",attr(self_value(),"h2_completed")).truth()){
                // Hsin.py:49
                ([&]()->V{auto fn_69=attr(attr(self_value(),"logger"),"debug");Args args_68;args_68.pos(V("Hsin heavy end: duration reached"));return invoke(fn_69,args_68);}());
            }
            // Hsin.py:50
            ([&]()->V{auto fn_71=attr(attr(self_value(),"logger"),"debug");Args args_70;args_70.pos(V("Hsin rotation end: duration reached"));return invoke(fn_71,args_70);}());
            // Hsin.py:51
            ([&]()->V{auto fn_73=attr(attr(self_value(),"logger"),"info");Args args_72;args_72.pos(V(std::string{}+"Hsin rotation end: timeout, finisher="+format_value(([&]()->V{V compare_74=attr(self_value(),"finisher_start");V compare_75;V comparison_result_76;compare_75=V{};comparison_result_76=compare_value("is not",compare_74,compare_75);return comparison_result_76;}()),"",-1)+", enhanced_e="+format_value(attr(self_value(),"finisher_e_sent"),"",-1)+", h2="+format_value(attr(self_value(),"h2_completed"),"",-1)));return invoke(fn_73,args_72);}());
            // Hsin.py:53
            return V{};
        }
        // Hsin.py:54
        ([&]()->V{auto fn_78=attr(self_value(),"cycle_start");Args args_77;return invoke(fn_78,args_77);}());
        // Hsin.py:55
        ([&]()->V{auto fn_80=attr(attr(self_value(),"logger"),"debug");Args args_79;args_79.pos(V(std::string{}+"Hsin cycle: elapsed="+format_value(([&]()->V{auto fn_82=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_81;args_81.pos(scope_42->get("phase_start"));return invoke(fn_82,args_81);}()),V(std::string{}+".2f").text(),-1)+", wall_elapsed="+format_value(([&]()->V{V left_83=([&]()->V{auto fn_86=attr(global("time","Hsin"),"time");Args args_85;return invoke(fn_86,args_85);}());V right_84=scope_42->get("start");return official::binary("-",left_83,right_84);}()),V(std::string{}+".2f").text(),-1)+", finisher="+format_value(([&]()->V{V compare_87=attr(self_value(),"finisher_start");V compare_88;V comparison_result_89;compare_88=V{};comparison_result_89=compare_value("is not",compare_87,compare_88);return comparison_result_89;}()),"",-1)+", duration="+format_value(scope_42->get("phase_duration"),"",-1)));return invoke(fn_80,args_79);}());
        // Hsin.py:60
        if(attr(self_value(),"h2_completed").truth()){
            // Hsin.py:61
            if(([&]()->V{auto fn_91=attr(self_value(),"lib");Args args_90;args_90.kw("after_heavy",V(true));return invoke(fn_91,args_90);}()).truth()){
                // Hsin.py:62
                ([&]()->V{auto fn_93=attr(attr(self_value(),"logger"),"debug");Args args_92;args_92.pos(V("Hsin rotation end: lib2 cast"));return invoke(fn_93,args_92);}());
                // Hsin.py:63
                return V{};
            }
            // Hsin.py:64
            ([&]()->V{auto fn_95=attr(attr(self_value(),"logger"),"debug");Args args_94;args_94.pos(V("Hsin cycle_sleep start"));return invoke(fn_95,args_94);}());
            // Hsin.py:65
            ([&]()->V{auto fn_97=attr(self_value(),"cycle_sleep");Args args_96;return invoke(fn_97,args_96);}());
            // Hsin.py:66
            ([&]()->V{auto fn_99=attr(attr(self_value(),"logger"),"debug");Args args_98;args_98.pos(V("Hsin cycle_sleep end"));return invoke(fn_99,args_98);}());
            // Hsin.py:67
            continue;
        }
        // Hsin.py:68
        if(([&]()->V{auto fn_101=attr(attr(self_value(),"task"),"find_one");Args args_100;args_100.pos(attr(global("Labels","Hsin"),"hsin_lib2"));args_100.kw("threshold",V(0.7));return invoke(fn_101,args_100);}()).truth()){
            // Hsin.py:69
            ([&]()->V{auto fn_103=attr(self_value(),"lib");Args args_102;return invoke(fn_103,args_102);}());
            // Hsin.py:70
            if(attr(self_value(),"lib2_cast_this_turn").truth()){
                // Hsin.py:71
                ([&]()->V{auto fn_105=attr(attr(self_value(),"logger"),"debug");Args args_104;args_104.pos(V("Hsin rotation end: lib2 cast"));return invoke(fn_105,args_104);}());
                // Hsin.py:72
                return V{};
            }
        }
        // Hsin.py:73
        {V value_106=([&]()->V{auto fn_108=attr(self_value(),"heavy_available");Args args_107;return invoke(fn_108,args_107);}());scope_42->set("heavy_type",value_106);}
        // Hsin.py:74
        if(([&]()->V{V compare_109=scope_42->get("heavy_type");V compare_110;V comparison_result_111;compare_110=V(2LL);comparison_result_111=compare_value("==",compare_109,compare_110);return comparison_result_111;}()).truth()){
            // Hsin.py:75
            {V value_112=([&]()->V{V left_113=scope_42->get("phase_duration");V right_114=([&]()->V{auto fn_116=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_115;args_115.pos(scope_42->get("phase_start"));return invoke(fn_116,args_115);}());return official::binary("-",left_113,right_114);}());scope_42->set("remaining",value_112);}
            // Hsin.py:76
            {V value_117=([&]()->V{auto fn_119=attr(self_value(),"handle_heavy");Args args_118;args_118.pos(scope_42->get("heavy_type"));return invoke(fn_119,args_118);}());scope_42->set("confirmed",value_117);}
            // Hsin.py:77
            ([&]()->V{auto fn_121=attr(attr(self_value(),"logger"),"debug");Args args_120;args_120.pos(V(std::string{}+"Hsin heavy end: remaining_before_hold="+format_value(scope_42->get("remaining"),V(std::string{}+".2f").text(),-1)));return invoke(fn_121,args_120);}());
            // Hsin.py:78
            if(([&]()->V{V operand_122;operand_122=scope_42->get("confirmed");if(!operand_122.truth())return operand_122;return ([&]()->V{auto fn_124=attr(self_value(),"wait_for_lib2");Args args_123;args_123.kw("after_heavy",V(true));return invoke(fn_124,args_123);}());}()).truth()){
                // Hsin.py:79
                ([&]()->V{auto fn_126=attr(attr(self_value(),"logger"),"debug");Args args_125;args_125.pos(V("Hsin rotation end: lib2 cast"));return invoke(fn_126,args_125);}());
                // Hsin.py:80
                return V{};
            }
            // Hsin.py:81
            ([&]()->V{auto fn_128=attr(attr(self_value(),"logger"),"debug");Args args_127;args_127.pos(V("Hsin cycle_sleep start"));return invoke(fn_128,args_127);}());
            // Hsin.py:82
            ([&]()->V{auto fn_130=attr(self_value(),"cycle_sleep");Args args_129;return invoke(fn_130,args_129);}());
            // Hsin.py:83
            ([&]()->V{auto fn_132=attr(attr(self_value(),"logger"),"debug");Args args_131;args_131.pos(V("Hsin cycle_sleep end"));return invoke(fn_132,args_131);}());
            // Hsin.py:84
            continue;
        }
        // Hsin.py:86
        if(([&]()->V{V compare_133=attr(self_value(),"finisher_start");V compare_134;V comparison_result_135;compare_134=V{};comparison_result_135=compare_value("is not",compare_133,compare_134);return comparison_result_135;}()).truth()){
            // Hsin.py:87
            {V value_136=([&]()->V{auto fn_138=attr(self_value(),"enhanced_e_ready");Args args_137;return invoke(fn_138,args_137);}());scope_42->set("ready",value_136);}
            // Hsin.py:88
            if(([&]()->V{V compare_139=scope_42->get("ready");V compare_140;V comparison_result_141;compare_140=scope_42->get("last_e_ready");comparison_result_141=compare_value("!=",compare_139,compare_140);return comparison_result_141;}()).truth()){
                // Hsin.py:89
                ([&]()->V{auto fn_143=attr(attr(self_value(),"logger"),"info");Args args_142;args_142.pos(V(std::string{}+"Hsin enhanced E prompt: ready="+format_value(scope_42->get("ready"),"",-1)+", previously_confirmed="+format_value(attr(self_value(),"finisher_e_sent"),"",-1)));return invoke(fn_143,args_142);}());
                // Hsin.py:91
                {V value_144=scope_42->get("ready");scope_42->set("last_e_ready",value_144);}
            }
            // Hsin.py:92
            if(scope_42->get("ready").truth()){
                // Hsin.py:93
                if(attr(self_value(),"finisher_e_sent").truth()){
                    // Hsin.py:94
                    ([&]()->V{auto fn_146=attr(attr(self_value(),"logger"),"info");Args args_145;args_145.pos(V("Hsin enhanced E prompt returned; retry E"));return invoke(fn_146,args_145);}());
                }
                // Hsin.py:95
                {V value_147=V(false);set_attr(self_value(),"finisher_e_sent",value_147);}
                // Hsin.py:96
                ([&]()->V{auto fn_149=attr(self_value(),"cast_enhanced_e");Args args_148;return invoke(fn_149,args_148);}());
            }else{
                // Hsin.py:98
                ([&]()->V{auto fn_151=attr(attr(self_value(),"logger"),"debug");Args args_150;args_150.pos(V(std::string{}+"Hsin enhanced E skipped: consumed="+format_value(attr(self_value(),"finisher_e_sent"),"",-1)));return invoke(fn_151,args_150);}());
                // Hsin.py:99
                ([&]()->V{auto fn_153=attr(attr(self_value(),"logger"),"debug");Args args_152;args_152.pos(V("Hsin normal attack start"));return invoke(fn_153,args_152);}());
                // Hsin.py:100
                ([&]()->V{auto fn_155=attr(self_value(),"click");Args args_154;return invoke(fn_155,args_154);}());
                // Hsin.py:101
                ([&]()->V{auto fn_157=attr(attr(self_value(),"logger"),"debug");Args args_156;args_156.pos(V("Hsin normal attack end"));return invoke(fn_157,args_156);}());
            }
            // Hsin.py:102
            ([&]()->V{auto fn_159=attr(attr(self_value(),"logger"),"debug");Args args_158;args_158.pos(V("Hsin cycle_sleep start"));return invoke(fn_159,args_158);}());
            // Hsin.py:103
            ([&]()->V{auto fn_161=attr(self_value(),"cycle_sleep");Args args_160;return invoke(fn_161,args_160);}());
            // Hsin.py:104
            ([&]()->V{auto fn_163=attr(attr(self_value(),"logger"),"debug");Args args_162;args_162.pos(V("Hsin cycle_sleep end"));return invoke(fn_163,args_162);}());
            // Hsin.py:105
            continue;
        }
        // Hsin.py:106
        ([&]()->V{auto fn_165=attr(attr(self_value(),"logger"),"debug");Args args_164;args_164.pos(V("Hsin resonance start"));return invoke(fn_165,args_164);}());
        // Hsin.py:107
        {V value_166=([&]()->V{auto fn_168=attr(global("time","Hsin"),"time");Args args_167;return invoke(fn_168,args_167);}());scope_42->set("resonance_start",value_166);}
        // Hsin.py:108
        if(([&]()->V{auto fn_170=attr(self_value(),"resonance_available");Args args_169;return invoke(fn_170,args_169);}()).truth()){
            // Hsin.py:109
            {V value_171=([&]()->V{auto fn_173=attr(self_value(),"click_resonance");Args args_172;args_172.kw("has_animation",V(false));args_172.kw("send_click",V(true));args_172.kw("time_out",V(0LL));return invoke(fn_173,args_172);}());scope_42->set("resonance",value_171);}
        }else{
            // Hsin.py:111
            {V value_174=V::tuple({V(false),V(0LL),V(false)});scope_42->set("resonance",value_174);}
            // Hsin.py:112
            ([&]()->V{auto fn_176=attr(attr(self_value(),"logger"),"debug");Args args_175;args_175.pos(V("Hsin resonance skipped: unavailable"));return invoke(fn_176,args_175);}());
        }
        // Hsin.py:113
        ([&]()->V{auto fn_178=attr(attr(self_value(),"logger"),"debug");Args args_177;args_177.pos(V(std::string{}+"Hsin resonance check/cast duration="+format_value(([&]()->V{V left_179=([&]()->V{auto fn_182=attr(global("time","Hsin"),"time");Args args_181;return invoke(fn_182,args_181);}());V right_180=scope_42->get("resonance_start");return official::binary("-",left_179,right_180);}()),V(std::string{}+".3f").text(),-1)+"s"));return invoke(fn_178,args_177);}());
        // Hsin.py:114
        ([&]()->V{auto fn_184=attr(attr(self_value(),"logger"),"debug");Args args_183;args_183.pos(V(std::string{}+"Hsin resonance end: result="+format_value(scope_42->get("resonance"),"",-1)));return invoke(fn_184,args_183);}());
        // Hsin.py:115
        if(item(scope_42->get("resonance"),V(0LL)).truth()){
        }else{
            // Hsin.py:117
            if(([&]()->V{auto fn_186=attr(self_value(),"lib");Args args_185;return invoke(fn_186,args_185);}()).truth()){
                // Hsin.py:118
                if(attr(self_value(),"lib2_cast_this_turn").truth()){
                    // Hsin.py:119
                    ([&]()->V{auto fn_188=attr(attr(self_value(),"logger"),"debug");Args args_187;args_187.pos(V("Hsin rotation end: lib2 cast"));return invoke(fn_188,args_187);}());
                    // Hsin.py:120
                    return V{};
                }
            }else{
                // Hsin.py:121
                if(scope_42->get("heavy_type").truth()){
                    // Hsin.py:122
                    {V value_189=([&]()->V{V left_190=scope_42->get("phase_duration");V right_191=([&]()->V{auto fn_193=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_192;args_192.pos(scope_42->get("phase_start"));return invoke(fn_193,args_192);}());return official::binary("-",left_190,right_191);}());scope_42->set("remaining",value_189);}
                    // Hsin.py:123
                    ([&]()->V{auto fn_195=attr(self_value(),"handle_heavy");Args args_194;args_194.pos(scope_42->get("heavy_type"));return invoke(fn_195,args_194);}());
                    // Hsin.py:124
                    ([&]()->V{auto fn_197=attr(attr(self_value(),"logger"),"debug");Args args_196;args_196.pos(V(std::string{}+"Hsin heavy end: remaining_before_hold="+format_value(scope_42->get("remaining"),V(std::string{}+".2f").text(),-1)));return invoke(fn_197,args_196);}());
                }else{
                    // Hsin.py:125
                    if(([&]()->V{V compare_198=attr(self_value(),"finisher_start");V compare_199;V comparison_result_200;compare_199=V{};comparison_result_200=compare_value("is not",compare_198,compare_199);return comparison_result_200;}()).truth()){
                        // Hsin.py:126
                        ([&]()->V{auto fn_202=attr(attr(self_value(),"logger"),"debug");Args args_201;args_201.pos(V("Hsin normal attack start"));return invoke(fn_202,args_201);}());
                        // Hsin.py:127
                        ([&]()->V{auto fn_204=attr(self_value(),"click");Args args_203;return invoke(fn_204,args_203);}());
                        // Hsin.py:128
                        ([&]()->V{auto fn_206=attr(attr(self_value(),"logger"),"debug");Args args_205;args_205.pos(V("Hsin normal attack end"));return invoke(fn_206,args_205);}());
                    }else{
                        // Hsin.py:130
                        ([&]()->V{auto fn_208=attr(attr(self_value(),"logger"),"debug");Args args_207;args_207.pos(V("Hsin echo start"));return invoke(fn_208,args_207);}());
                        // Hsin.py:131
                        {V value_209=([&]()->V{auto fn_211=attr(self_value(),"click_echo");Args args_210;args_210.kw("time_out",V(0LL));return invoke(fn_211,args_210);}());scope_42->set("echoed",value_209);}
                        // Hsin.py:132
                        ([&]()->V{auto fn_213=attr(attr(self_value(),"logger"),"debug");Args args_212;args_212.pos(V(std::string{}+"Hsin echo end: cast="+format_value(scope_42->get("echoed"),"",-1)));return invoke(fn_213,args_212);}());
                        // Hsin.py:133
                        if(unary("not",scope_42->get("echoed")).truth()){
                            // Hsin.py:134
                            ([&]()->V{auto fn_215=attr(attr(self_value(),"logger"),"debug");Args args_214;args_214.pos(V("Hsin normal attack start"));return invoke(fn_215,args_214);}());
                            // Hsin.py:135
                            ([&]()->V{auto fn_217=attr(self_value(),"click");Args args_216;return invoke(fn_217,args_216);}());
                            // Hsin.py:136
                            ([&]()->V{auto fn_219=attr(attr(self_value(),"logger"),"debug");Args args_218;args_218.pos(V("Hsin normal attack end"));return invoke(fn_219,args_218);}());
                        }
                    }
                }
            }
        }
        // Hsin.py:137
        ([&]()->V{auto fn_221=attr(attr(self_value(),"logger"),"debug");Args args_220;args_220.pos(V("Hsin cycle_sleep start"));return invoke(fn_221,args_220);}());
        // Hsin.py:138
        ([&]()->V{auto fn_223=attr(self_value(),"cycle_sleep");Args args_222;return invoke(fn_223,args_222);}());
        // Hsin.py:139
        ([&]()->V{auto fn_225=attr(attr(self_value(),"logger"),"debug");Args args_224;args_224.pos(V("Hsin cycle_sleep end"));return invoke(fn_225,args_224);}());
    }
return V{};
}),false);
// Official method Hsin.enhanced_e_ready, lines 141-142
register_method("enhanced_e_ready",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_226=bind_arguments(official_args,signature,captured);
    // Hsin.py:142
    return ([&]()->V{auto fn_228=global("bool","Hsin");Args args_227;args_227.pos(([&]()->V{auto fn_230=attr(self_value(),"is_e_forte_full");Args args_229;return invoke(fn_230,args_229);}()));return invoke(fn_228,args_227);}());
return V{};
}),false);
// Official method Hsin.cast_enhanced_e, lines 144-175
register_method("cast_enhanced_e",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_231=bind_arguments(official_args,signature,captured);
scope_231->set("gone_since",V::missing());
scope_231->set("last_send",V::missing());
scope_231->set("now",V::missing());
scope_231->set("sends",V::missing());
scope_231->set("start",V::missing());
    // Hsin.py:145
    ([&]()->V{auto fn_233=attr(attr(self_value(),"logger"),"debug");Args args_232;args_232.pos(V("Hsin enhanced E start"));return invoke(fn_233,args_232);}());
    // Hsin.py:146
    ([&]()->V{auto fn_235=attr(attr(self_value(),"logger"),"info");Args args_234;args_234.pos(V("Hsin enhanced E start: generic prompt ready"));return invoke(fn_235,args_234);}());
    // Hsin.py:147
    {V value_236=([&]()->V{auto fn_238=attr(global("time","Hsin"),"time");Args args_237;return invoke(fn_238,args_237);}());scope_231->set("start",value_236);}
    // Hsin.py:148
    {V value_239=unary("-",V(1.0));scope_231->set("last_send",value_239);}
    // Hsin.py:149
    {V value_240=V(0LL);scope_231->set("sends",value_240);}
    // Hsin.py:150
    {V value_241=V{};scope_231->set("gone_since",value_241);}
    // Hsin.py:151
        while(([&]()->V{V compare_287=([&]()->V{V left_289=([&]()->V{auto fn_292=attr(global("time","Hsin"),"time");Args args_291;return invoke(fn_292,args_291);}());V right_290=scope_231->get("start");return official::binary("-",left_289,right_290);}());V compare_288;V comparison_result_293;compare_288=V(1.5);comparison_result_293=compare_value("<",compare_287,compare_288);return comparison_result_293;}()).truth()){
        // Hsin.py:152
        ([&]()->V{auto fn_243=attr(self_value(),"check_combat");Args args_242;return invoke(fn_243,args_242);}());
        // Hsin.py:153
        {V value_244=([&]()->V{auto fn_246=attr(global("time","Hsin"),"time");Args args_245;return invoke(fn_246,args_245);}());scope_231->set("now",value_244);}
        // Hsin.py:154
        if(([&]()->V{auto fn_248=attr(self_value(),"enhanced_e_ready");Args args_247;return invoke(fn_248,args_247);}()).truth()){
            // Hsin.py:155
            {V value_249=V{};scope_231->set("gone_since",value_249);}
            // Hsin.py:156
            if(([&]()->V{V compare_250=([&]()->V{V left_252=scope_231->get("now");V right_253=scope_231->get("last_send");return official::binary("-",left_252,right_253);}());V compare_251;V comparison_result_254;compare_251=V(0.25);comparison_result_254=compare_value(">=",compare_250,compare_251);return comparison_result_254;}()).truth()){
                // Hsin.py:157
                ([&]()->V{auto fn_256=attr(self_value(),"send_resonance_key");Args args_255;return invoke(fn_256,args_255);}());
                // Hsin.py:158
                {V value_257=scope_231->get("now");scope_231->set("last_send",value_257);}
                // Hsin.py:159
                scope_231->set("sends",official::binary("+",scope_231->get("sends"),V(1LL)));
                // Hsin.py:160
                ([&]()->V{auto fn_259=attr(attr(self_value(),"logger"),"info");Args args_258;args_258.pos(V(std::string{}+"Hsin enhanced E key: send="+format_value(scope_231->get("sends"),"",-1)+", elapsed="+format_value(([&]()->V{V left_260=scope_231->get("now");V right_261=scope_231->get("start");return official::binary("-",left_260,right_261);}()),V(std::string{}+".3f").text(),-1)+"s"));return invoke(fn_259,args_258);}());
            }
        }else{
            // Hsin.py:161
            if(([&]()->V{V compare_262=scope_231->get("last_send");V compare_263;V comparison_result_264;compare_263=V(0LL);comparison_result_264=compare_value(">=",compare_262,compare_263);return comparison_result_264;}()).truth()){
                // Hsin.py:162
                if(([&]()->V{V compare_265=scope_231->get("gone_since");V compare_266;V comparison_result_267;compare_266=V{};comparison_result_267=compare_value("is",compare_265,compare_266);return comparison_result_267;}()).truth()){
                    // Hsin.py:163
                    {V value_268=scope_231->get("now");scope_231->set("gone_since",value_268);}
                }else{
                    // Hsin.py:164
                    if(([&]()->V{V compare_269=([&]()->V{V left_271=scope_231->get("now");V right_272=scope_231->get("gone_since");return official::binary("-",left_271,right_272);}());V compare_270;V comparison_result_273;compare_270=V(0.25);comparison_result_273=compare_value(">=",compare_269,compare_270);return comparison_result_273;}()).truth()){
                        // Hsin.py:165
                        {V value_274=V(true);set_attr(self_value(),"finisher_e_sent",value_274);}
                        // Hsin.py:166
                        ([&]()->V{auto fn_276=attr(self_value(),"record_resonance_use");Args args_275;return invoke(fn_276,args_275);}());
                        // Hsin.py:167
                        ([&]()->V{auto fn_278=attr(attr(self_value(),"logger"),"debug");Args args_277;args_277.pos(V("Hsin enhanced E consumed; continue normal attacks"));return invoke(fn_278,args_277);}());
                        // Hsin.py:168
                        ([&]()->V{auto fn_280=attr(attr(self_value(),"logger"),"info");Args args_279;args_279.pos(V(std::string{}+"Hsin enhanced E result: confirmed=True, sends="+format_value(scope_231->get("sends"),"",-1)+", elapsed="+format_value(([&]()->V{V left_281=([&]()->V{auto fn_284=attr(global("time","Hsin"),"time");Args args_283;return invoke(fn_284,args_283);}());V right_282=scope_231->get("start");return official::binary("-",left_281,right_282);}()),V(std::string{}+".3f").text(),-1)+"s"));return invoke(fn_280,args_279);}());
                        // Hsin.py:170
                        return V(true);
                    }
                }
            }
        }
        // Hsin.py:171
        ([&]()->V{auto fn_286=attr(attr(self_value(),"task"),"next_frame");Args args_285;return invoke(fn_286,args_285);}());
    }
    // Hsin.py:172
    ([&]()->V{auto fn_295=attr(attr(self_value(),"logger"),"debug");Args args_294;args_294.pos(V("Hsin enhanced E not confirmed; retry when ready"));return invoke(fn_295,args_294);}());
    // Hsin.py:173
    ([&]()->V{auto fn_297=attr(attr(self_value(),"logger"),"info");Args args_296;args_296.pos(V(std::string{}+"Hsin enhanced E result: confirmed=False, sends="+format_value(scope_231->get("sends"),"",-1)+", elapsed="+format_value(([&]()->V{V left_298=([&]()->V{auto fn_301=attr(global("time","Hsin"),"time");Args args_300;return invoke(fn_301,args_300);}());V right_299=scope_231->get("start");return official::binary("-",left_298,right_299);}()),V(std::string{}+".3f").text(),-1)+"s"));return invoke(fn_297,args_296);}());
    // Hsin.py:175
    return V(false);
return V{};
}),false);
// Official method Hsin.lib, lines 177-199
register_method("lib",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"after_heavy",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_302=bind_arguments(official_args,signature,captured);
scope_302->set("available",V::missing());
scope_302->set("has_feature",V::missing());
scope_302->set("is_lib2",V::missing());
scope_302->set("liberated",V::missing());
    // Hsin.py:178
    ([&]()->V{auto fn_304=attr(attr(self_value(),"logger"),"debug");Args args_303;args_303.pos(V("Hsin liberation start"));return invoke(fn_304,args_303);}());
    // Hsin.py:180
    {V value_305=([&]()->V{V operand_306;operand_306=scope_302->get("after_heavy");if(operand_306.truth())return operand_306;return ([&]()->V{auto fn_308=global("bool","Hsin");Args args_307;args_307.pos(([&]()->V{auto fn_310=attr(attr(self_value(),"task"),"find_one");Args args_309;args_309.pos(attr(global("Labels","Hsin"),"hsin_lib2"));args_309.kw("threshold",V(0.7));return invoke(fn_310,args_309);}()));return invoke(fn_308,args_307);}());}());scope_302->set("is_lib2",value_305);}
    // Hsin.py:181
    {V value_311=([&]()->V{V operand_312;operand_312=scope_302->get("is_lib2");if(operand_312.truth())return operand_312;return ([&]()->V{auto fn_314=global("bool","Hsin");Args args_313;args_313.pos(([&]()->V{auto fn_316=attr(attr(self_value(),"task"),"find_one");Args args_315;args_315.pos(attr(global("Labels","Hsin"),"hsin_lib1"));args_315.kw("threshold",V(0.7));return invoke(fn_316,args_315);}()));return invoke(fn_314,args_313);}());}());scope_302->set("has_feature",value_311);}
    // Hsin.py:182
    {V value_317=(scope_302->get("has_feature").truth()?([&]()->V{auto fn_319=attr(self_value(),"liberation_available");Args args_318;return invoke(fn_319,args_318);}()):V{});scope_302->set("available",value_317);}
    // Hsin.py:183
    ([&]()->V{auto fn_321=attr(attr(self_value(),"logger"),"debug");Args args_320;args_320.pos(V(std::string{}+"Hsin liberation indicator: feature="+format_value(scope_302->get("has_feature"),"",-1)+", lib2="+format_value(scope_302->get("is_lib2"),"",-1)+", available="+format_value(scope_302->get("available"),"",-1)));return invoke(fn_321,args_320);}());
    // Hsin.py:184
    if(([&]()->V{V operand_322;operand_322=unary("not",scope_302->get("has_feature"));if(operand_322.truth())return operand_322;return unary("not",scope_302->get("available"));}()).truth()){
        // Hsin.py:185
        ([&]()->V{auto fn_324=attr(attr(self_value(),"logger"),"debug");Args args_323;args_323.pos(V("Hsin liberation end: feature missing or unavailable"));return invoke(fn_324,args_323);}());
        // Hsin.py:186
        return V(false);
    }
    // Hsin.py:187
    {V value_325=([&]()->V{auto fn_327=global("bool","Hsin");Args args_326;args_326.pos(([&]()->V{auto fn_329=attr(self_value(),"click_liberation");Args args_328;args_328.kw("wait_if_cd_ready",V(0LL));return invoke(fn_329,args_328);}()));return invoke(fn_327,args_326);}());scope_302->set("liberated",value_325);}
    // Hsin.py:188
    ([&]()->V{auto fn_331=attr(attr(self_value(),"logger"),"debug");Args args_330;args_330.pos(V(std::string{}+"Hsin liberation: lib2="+format_value(scope_302->get("is_lib2"),"",-1)+", cast="+format_value(scope_302->get("liberated"),"",-1)));return invoke(fn_331,args_330);}());
    // Hsin.py:189
    if(scope_302->get("liberated").truth()){
        // Hsin.py:190
        if(scope_302->get("is_lib2").truth()){
            // Hsin.py:191
            {V value_332=V(true);set_attr(self_value(),"lib2_cast_this_turn",value_332);}
            // Hsin.py:192
            {V value_333=V(0.0);set_attr(self_value(),"h2_guard_until",value_333);}
        }else{
            // Hsin.py:193
            if(([&]()->V{V compare_334=attr(self_value(),"finisher_start");V compare_335;V comparison_result_336;compare_335=V{};comparison_result_336=compare_value("is",compare_334,compare_335);return comparison_result_336;}()).truth()){
                // Hsin.py:195
                {V value_337=([&]()->V{auto fn_339=attr(global("time","Hsin"),"time");Args args_338;return invoke(fn_339,args_338);}());set_attr(self_value(),"finisher_start",value_337);}
                // Hsin.py:196
                ([&]()->V{auto fn_341=attr(attr(self_value(),"logger"),"debug");Args args_340;args_340.pos(V("Hsin finisher start: duration=18"));return invoke(fn_341,args_340);}());
                // Hsin.py:197
                ([&]()->V{auto fn_343=attr(attr(self_value(),"logger"),"info");Args args_342;args_342.pos(V("Hsin finisher start: R1 confirmed, duration=18"));return invoke(fn_343,args_342);}());
            }
        }
    }
    // Hsin.py:198
    ([&]()->V{auto fn_345=attr(attr(self_value(),"logger"),"debug");Args args_344;args_344.pos(V(std::string{}+"Hsin liberation end: cast="+format_value(scope_302->get("liberated"),"",-1)+", lib2="+format_value(scope_302->get("is_lib2"),"",-1)));return invoke(fn_345,args_344);}());
    // Hsin.py:199
    return scope_302->get("liberated");
return V{};
}),false);
// Official method Hsin.heavy_available, lines 201-206
register_method("heavy_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_346=bind_arguments(official_args,signature,captured);
    // Hsin.py:202
    if(([&]()->V{auto fn_348=attr(attr(self_value(),"task"),"find_one");Args args_347;args_347.pos(attr(global("Labels","Hsin"),"hsin_h2"));args_347.kw("threshold",V(0.7));return invoke(fn_348,args_347);}()).truth()){
        // Hsin.py:203
        return V(2LL);
    }
    // Hsin.py:204
    if(([&]()->V{auto fn_350=attr(attr(self_value(),"task"),"find_one");Args args_349;args_349.pos(attr(global("Labels","Hsin"),"hsin_h1"));args_349.kw("threshold",V(0.7));return invoke(fn_350,args_349);}()).truth()){
        // Hsin.py:205
        return V(1LL);
    }
    // Hsin.py:206
    return V(0LL);
return V{};
}),false);
// Official method Hsin.heavy_wait_highlight_down, lines 208-230
register_method("heavy_wait_highlight_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V::missing()},{"protect_animation",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_351=bind_arguments(official_args,signature,captured);
scope_351->set("confirmed",V::missing());
    // Hsin.py:209
    ([&]()->V{auto fn_353=attr(attr(self_value(),"logger"),"debug");Args args_352;args_352.pos(V(std::string{}+"Hsin heavy hold start: timeout="+format_value(scope_351->get("time_out"),V(std::string{}+".2f").text(),-1)));return invoke(fn_353,args_352);}());
    // Hsin.py:210
    ([&]()->V{auto fn_355=attr(self_value(),"check_combat");Args args_354;return invoke(fn_355,args_354);}());
    // Hsin.py:211
    ([&]()->V{auto fn_357=attr(attr(self_value(),"task"),"mouse_down");Args args_356;return invoke(fn_357,args_356);}());
    // Hsin.py:212
    if(scope_351->get("protect_animation").truth()){
        // Hsin.py:214
        {V value_358=([&]()->V{V left_359=([&]()->V{auto fn_362=attr(global("time","Hsin"),"time");Args args_361;return invoke(fn_362,args_361);}());V right_360=V(4LL);return official::binary("+",left_359,right_360);}());set_attr(self_value(),"h2_guard_until",value_358);}
        // Hsin.py:215
        ([&]()->V{auto fn_364=attr(attr(self_value(),"logger"),"info");Args args_363;args_363.pos(V("Hsin H2 protection start: at most 4s through R2 transition"));return invoke(fn_364,args_363);}());
    }
    // Hsin.py:216
    {
    auto finally_365=on_scope_exit([&](){
        // Hsin.py:224
        ([&]()->V{auto fn_367=attr(attr(self_value(),"task"),"mouse_up");Args args_366;return invoke(fn_367,args_366);}());
        // Hsin.py:225
        ([&]()->V{auto fn_369=attr(attr(self_value(),"logger"),"debug");Args args_368;args_368.pos(V("Hsin heavy hold: mouse released"));return invoke(fn_369,args_368);}());
    });
    try{
        // Hsin.py:217
        {V value_370=([&]()->V{auto fn_372=global("bool","Hsin");Args args_371;args_371.pos(([&]()->V{auto fn_374=attr(attr(self_value(),"task"),"wait_until");Args args_373;args_373.pos(V::function([this,captured=capture_scope(scope_351,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_375=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_377=attr(self_value(),"heavy_available");Args args_376;return invoke(fn_377,args_376);}()));
}));args_373.kw("time_out",scope_351->get("time_out"));args_373.kw("settle_time",V(0.25));args_373.kw("pre_action",attr(self_value(),"check_combat"));return invoke(fn_374,args_373);}()));return invoke(fn_372,args_371);}());scope_351->set("confirmed",value_370);}
    }catch(const std::exception& official_exception){
        // Hsin.py:221
        {V value_378=V(0.0);set_attr(self_value(),"h2_guard_until",value_378);}
        // Hsin.py:222
        throw;
    }
    }
    // Hsin.py:226
    if(unary("not",scope_351->get("confirmed")).truth()){
        // Hsin.py:227
        {V value_379=V(0.0);set_attr(self_value(),"h2_guard_until",value_379);}
    }
    // Hsin.py:228
    ([&]()->V{auto fn_381=attr(self_value(),"sleep");Args args_380;args_380.pos(V(0.01));return invoke(fn_381,args_380);}());
    // Hsin.py:229
    ([&]()->V{auto fn_383=attr(attr(self_value(),"logger"),"debug");Args args_382;args_382.pos(V(std::string{}+"Hsin heavy hold end: indicator_disappeared="+format_value(scope_351->get("confirmed"),"",-1)));return invoke(fn_383,args_382);}());
    // Hsin.py:230
    return scope_351->get("confirmed");
return V{};
}),false);
// Official method Hsin.handle_heavy, lines 232-243
register_method("handle_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"heavy_type",V(0LL)}},"","",{})](const Args& official_args)->V{
auto scope_384=bind_arguments(official_args,signature,captured);
scope_384->set("confirmed",V::missing());
    // Hsin.py:233
    ([&]()->V{auto fn_386=attr(attr(self_value(),"logger"),"debug");Args args_385;args_385.pos(V("Hsin heavy check start"));return invoke(fn_386,args_385);}());
    // Hsin.py:234
    {V value_387=([&]()->V{V operand_388;operand_388=scope_384->get("heavy_type");if(operand_388.truth())return operand_388;return ([&]()->V{auto fn_390=attr(self_value(),"heavy_available");Args args_389;return invoke(fn_390,args_389);}());}());scope_384->set("heavy_type",value_387);}
    // Hsin.py:235
    if(unary("not",scope_384->get("heavy_type")).truth()){
        // Hsin.py:236
        ([&]()->V{auto fn_392=attr(attr(self_value(),"logger"),"debug");Args args_391;args_391.pos(V("Hsin heavy end: unavailable"));return invoke(fn_392,args_391);}());
        // Hsin.py:237
        return V(false);
    }
    // Hsin.py:239
    {V value_393=([&]()->V{auto fn_395=attr(self_value(),"heavy_wait_highlight_down");Args args_394;args_394.pos(V(1.2));args_394.kw("protect_animation",([&]()->V{V compare_396=scope_384->get("heavy_type");V compare_397;V comparison_result_398;compare_397=V(2LL);comparison_result_398=compare_value("==",compare_396,compare_397);return comparison_result_398;}()));return invoke(fn_395,args_394);}());scope_384->set("confirmed",value_393);}
    // Hsin.py:240
    ([&]()->V{auto fn_400=attr(attr(self_value(),"logger"),"debug");Args args_399;args_399.pos(V(std::string{}+"Hsin heavy: type="+format_value(scope_384->get("heavy_type"),"",-1)+", confirmed="+format_value(scope_384->get("confirmed"),"",-1)));return invoke(fn_400,args_399);}());
    // Hsin.py:241
    if(([&]()->V{V operand_401;operand_401=scope_384->get("confirmed");if(!operand_401.truth())return operand_401;return ([&]()->V{V compare_402=scope_384->get("heavy_type");V compare_403;V comparison_result_404;compare_403=V(2LL);comparison_result_404=compare_value("==",compare_402,compare_403);return comparison_result_404;}());}()).truth()){
        // Hsin.py:242
        {V value_405=V(true);set_attr(self_value(),"h2_completed",value_405);}
    }
    // Hsin.py:243
    return scope_384->get("confirmed");
return V{};
}),false);
// Official method Hsin.wait_for_lib2, lines 245-252
register_method("wait_for_lib2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"after_heavy",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_406=bind_arguments(official_args,signature,captured);
scope_406->set("confirmed",V::missing());
    // Hsin.py:246
    ([&]()->V{auto fn_408=attr(attr(self_value(),"logger"),"debug");Args args_407;args_407.pos(V(std::string{}+"Hsin lib2 wait start: after_heavy="+format_value(scope_406->get("after_heavy"),"",-1)));return invoke(fn_408,args_407);}());
    // Hsin.py:247
    {V value_409=([&]()->V{auto fn_411=global("bool","Hsin");Args args_410;args_410.pos(([&]()->V{auto fn_413=attr(attr(self_value(),"task"),"wait_until");Args args_412;args_412.pos(V::function([this,captured=capture_scope(scope_406,{"after_heavy"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_414=bind_arguments(official_args,signature,captured);
return ([&]()->V{V operand_415;operand_415=([&]()->V{V operand_416;operand_416=scope_414->get("after_heavy");if(operand_416.truth())return operand_416;return ([&]()->V{auto fn_418=global("bool","Hsin");Args args_417;args_417.pos(([&]()->V{auto fn_420=attr(attr(self_value(),"task"),"find_one");Args args_419;args_419.pos(attr(global("Labels","Hsin"),"hsin_lib2"));args_419.kw("threshold",V(0.7));return invoke(fn_420,args_419);}()));return invoke(fn_418,args_417);}());}());if(!operand_415.truth())return operand_415;operand_415=([&]()->V{auto fn_422=attr(self_value(),"lib");Args args_421;args_421.kw("after_heavy",scope_414->get("after_heavy"));return invoke(fn_422,args_421);}());if(!operand_415.truth())return operand_415;return attr(self_value(),"lib2_cast_this_turn");}());
}));args_412.kw("time_out",V(1.5));args_412.kw("pre_action",attr(self_value(),"check_combat"));return invoke(fn_413,args_412);}()));return invoke(fn_411,args_410);}());scope_406->set("confirmed",value_409);}
    // Hsin.py:251
    ([&]()->V{auto fn_424=attr(attr(self_value(),"logger"),"debug");Args args_423;args_423.pos(V(std::string{}+"Hsin lib2 wait end: cast="+format_value(scope_406->get("confirmed"),"",-1)+", pending="+format_value(([&]()->V{V operand_425;operand_425=attr(self_value(),"h2_completed");if(!operand_425.truth())return operand_425;return unary("not",scope_406->get("confirmed"));}()),"",-1)));return invoke(fn_424,args_423);}());
    // Hsin.py:252
    return scope_406->get("confirmed");
return V{};
}),false);
}
}
