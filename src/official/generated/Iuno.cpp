#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Iuno.py
// SHA256 099426924efb831c4b9abd6fb49b4b16c78ff3500a5fd04b4e6a41c76d18e09d
void OfficialCharacter::install_Iuno(){
auto scope=std::make_shared<Scope>();
// Official method Iuno.__init__, lines 8-10
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Iuno.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Iuno");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Iuno.py:10
    {V value_6=V(0LL);set_attr(self_value(),"last_heavy",value_6);}
return V{};
}),false);
// Official method Iuno.is_c6, lines 12-13
register_method("is_c6",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Iuno.py:13
    return ([&]()->V{V operand_8;operand_8=attr(self_value(),"task");if(!operand_8.truth())return operand_8;return ([&]()->V{auto fn_10=attr(attr(attr(self_value(),"task"),"char_config"),"get");Args args_9;args_9.pos(V("Iuno C6"));return invoke(fn_10,args_9);}());}());
return V{};
}),false);
// Official method Iuno.get_char_type, lines 15-18
register_method("get_char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
    // Iuno.py:16
    if(([&]()->V{auto fn_13=attr(self_value(),"is_c6");Args args_12;return invoke(fn_13,args_12);}()).truth()){
        // Iuno.py:17
        return attr(global("CharType","Iuno"),"MAIN_DPS");
    }
    // Iuno.py:18
    return ([&]()->V{auto fn_17=attr(([&]()->V{auto fn_15=global("super","Iuno");Args args_14;return invoke(fn_15,args_14);}()),"get_char_type");Args args_16;return invoke(fn_17,args_16);}());
return V{};
}),false);
// Official method Iuno.get_buff_time, lines 20-23
register_method("get_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_18=bind_arguments(official_args,signature,captured);
    // Iuno.py:21
    if(([&]()->V{auto fn_20=attr(self_value(),"is_c6");Args args_19;return invoke(fn_20,args_19);}()).truth()){
        // Iuno.py:22
        return ([&]()->V{auto fn_22=global("get_default_buff_time","Iuno");Args args_21;args_21.pos(attr(global("CharType","Iuno"),"MAIN_DPS"));return invoke(fn_22,args_21);}());
    }
    // Iuno.py:23
    return ([&]()->V{auto fn_26=attr(([&]()->V{auto fn_24=global("super","Iuno");Args args_23;return invoke(fn_24,args_23);}()),"get_buff_time");Args args_25;return invoke(fn_26,args_25);}());
return V{};
}),false);
// Official method Iuno.do_perform, lines 25-28
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_27=bind_arguments(official_args,signature,captured);
    // Iuno.py:26
    ([&]()->V{auto fn_29=attr(self_value(),"wait_down");Args args_28;return invoke(fn_29,args_28);}());
    // Iuno.py:27
    ([&]()->V{auto fn_31=attr(self_value(),"do_everything");Args args_30;return invoke(fn_31,args_30);}());
    // Iuno.py:28
    ([&]()->V{auto fn_33=attr(self_value(),"switch_next_char");Args args_32;return invoke(fn_33,args_32);}());
return V{};
}),false);
// Official method Iuno.do_everything, lines 30-82
register_method("do_everything",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(1.5)}},"","",{})](const Args& official_args)->V{
auto scope_34=bind_arguments(official_args,signature,captured);
scope_34->set("c6_performed",V::missing());
scope_34->set("cycle_start",V::missing());
scope_34->set("heavy_success",V::missing());
scope_34->set("jumped",V::missing());
scope_34->set("last_action",V::missing());
scope_34->set("start",V::missing());
    // Iuno.py:31
    if(attr(self_value(),"has_intro").truth()){
        // Iuno.py:32
        scope_34->set("time_out",official::binary("+",scope_34->get("time_out"),V(4LL)));
    }
    // Iuno.py:33
    {V value_35=([&]()->V{auto fn_37=attr(global("time","Iuno"),"time");Args args_36;return invoke(fn_37,args_36);}());scope_34->set("start",value_35);}
    // Iuno.py:34
    {V value_38=V("click");scope_34->set("last_action",value_38);}
    // Iuno.py:35
    ([&]()->V{auto fn_40=attr(self_value(),"click_echo");Args args_39;return invoke(fn_40,args_39);}());
    // Iuno.py:36
    {V value_41=V(false);scope_34->set("c6_performed",value_41);}
    // Iuno.py:37
    {V value_42=V(false);scope_34->set("jumped",value_42);}
    // Iuno.py:38
        while(([&]()->V{V compare_112=([&]()->V{auto fn_115=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_114;args_114.pos(scope_34->get("start"));return invoke(fn_115,args_114);}());V compare_113;V comparison_result_116;compare_113=scope_34->get("time_out");comparison_result_116=compare_value("<",compare_112,compare_113);return comparison_result_116;}()).truth()){
        // Iuno.py:39
        {V value_43=([&]()->V{auto fn_45=attr(global("time","Iuno"),"time");Args args_44;return invoke(fn_45,args_44);}());scope_34->set("cycle_start",value_43);}
        // Iuno.py:40
        {V value_46=V(false);scope_34->set("heavy_success",value_46);}
        // Iuno.py:41
                while(([&]()->V{V operand_54;operand_54=([&]()->V{V compare_55=([&]()->V{auto fn_58=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_57;args_57.pos(attr(self_value(),"last_heavy"));return invoke(fn_58,args_57);}());V compare_56;V comparison_result_59;compare_56=V(20LL);comparison_result_59=compare_value(">",compare_55,compare_56);return comparison_result_59;}());if(!operand_54.truth())return operand_54;return ([&]()->V{auto fn_61=attr(attr(self_value(),"task"),"find_feature");Args args_60;args_60.pos(V("iuno_heavy"));args_60.kw("box",V("box_extra_action"));args_60.kw("threshold",V(0.6));return invoke(fn_61,args_60);}());}()).truth()){
            // Iuno.py:46
            ([&]()->V{auto fn_48=attr(self_value(),"sleep");Args args_47;args_47.pos(V(0.05));return invoke(fn_48,args_47);}());
            // Iuno.py:47
            ([&]()->V{auto fn_50=attr(self_value(),"heavy_attack");Args args_49;return invoke(fn_50,args_49);}());
            // Iuno.py:48
            ([&]()->V{auto fn_52=attr(self_value(),"sleep");Args args_51;args_51.pos(V(0.05));return invoke(fn_52,args_51);}());
            // Iuno.py:49
            {V value_53=V(true);scope_34->set("heavy_success",value_53);}
        }
        // Iuno.py:50
        if(scope_34->get("heavy_success").truth()){
            // Iuno.py:51
            {V value_62=([&]()->V{auto fn_64=attr(global("time","Iuno"),"time");Args args_63;return invoke(fn_64,args_63);}());set_attr(self_value(),"last_heavy",value_62);}
            // Iuno.py:52
            if(([&]()->V{V operand_65;operand_65=unary("not",scope_34->get("c6_performed"));if(!operand_65.truth())return operand_65;return ([&]()->V{auto fn_67=attr(self_value(),"is_c6");Args args_66;return invoke(fn_67,args_66);}());}()).truth()){
                // Iuno.py:53
                {V value_68=V(true);scope_34->set("c6_performed",value_68);}
                // Iuno.py:54
                {V value_69=([&]()->V{auto fn_71=attr(global("time","Iuno"),"time");Args args_70;return invoke(fn_71,args_70);}());scope_34->set("start",value_69);}
                // Iuno.py:55
                {V value_72=V(5LL);scope_34->set("time_out",value_72);}
                // Iuno.py:57
                ([&]()->V{auto fn_74=attr(attr(self_value(),"logger"),"debug");Args args_73;args_73.pos(V("iuno c6 continue"));return invoke(fn_74,args_73);}());
            }else{
                // Iuno.py:59
                return V(true);
            }
        }
        // Iuno.py:60
        if(([&]()->V{V operand_75;operand_75=unary("not",scope_34->get("jumped"));if(!operand_75.truth())return operand_75;return ([&]()->V{auto fn_77=attr(attr(self_value(),"task"),"find_feature");Args args_76;args_76.pos(V("iuno_jump"));args_76.kw("box",V("box_extra_action"));args_76.kw("threshold",V(0.6));return invoke(fn_77,args_76);}());}()).truth()){
            // Iuno.py:62
                        while(([&]()->V{auto fn_81=attr(attr(self_value(),"task"),"find_feature");Args args_80;args_80.pos(V("iuno_jump"));args_80.kw("box",V("box_extra_action"));args_80.kw("threshold",V(0.6));return invoke(fn_81,args_80);}()).truth()){
                // Iuno.py:63
                ([&]()->V{auto fn_79=attr(attr(self_value(),"task"),"jump");Args args_78;args_78.kw("after_sleep",V(0.1));return invoke(fn_79,args_78);}());
            }
            // Iuno.py:64
            scope_34->set("time_out",official::binary("+",scope_34->get("time_out"),V(3LL)));
            // Iuno.py:65
            {V value_82=V(true);scope_34->set("jumped",value_82);}
            // Iuno.py:66
            if(attr(self_value(),"has_intro").truth()){
                // Iuno.py:67
                continue;
            }else{
                // Iuno.py:69
                return V{};
            }
        }
        // Iuno.py:70
        if(([&]()->V{V operand_83;operand_83=([&]()->V{V compare_84=([&]()->V{auto fn_87=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_86;args_86.pos(attr(self_value(),"last_liberation"));return invoke(fn_87,args_86);}());V compare_85;V comparison_result_88;compare_85=V(20LL);comparison_result_88=compare_value(">",compare_84,compare_85);return comparison_result_88;}());if(!operand_83.truth())return operand_83;return ([&]()->V{auto fn_90=attr(self_value(),"click_liberation");Args args_89;args_89.kw("wait_if_cd_ready",V(0LL));return invoke(fn_90,args_89);}());}()).truth()){
            // Iuno.py:74
            {V value_91=([&]()->V{auto fn_93=attr(global("time","Iuno"),"time");Args args_92;return invoke(fn_93,args_92);}());scope_34->set("start",value_91);}
            // Iuno.py:75
            {V value_94=V(3LL);scope_34->set("time_out",value_94);}
        }
        // Iuno.py:76
        if(([&]()->V{V compare_95=scope_34->get("last_action");V compare_96;V comparison_result_97;compare_96=V("click");comparison_result_97=compare_value("==",compare_95,compare_96);return comparison_result_97;}()).truth()){
            // Iuno.py:77
            {V value_98=V("resonance");scope_34->set("last_action",value_98);}
            // Iuno.py:78
            ([&]()->V{auto fn_100=attr(self_value(),"send_resonance_key");Args args_99;return invoke(fn_100,args_99);}());
        }else{
            // Iuno.py:80
            {V value_101=V("click");scope_34->set("last_action",value_101);}
            // Iuno.py:81
            ([&]()->V{auto fn_103=attr(self_value(),"click");Args args_102;return invoke(fn_103,args_102);}());
        }
        // Iuno.py:82
        ([&]()->V{auto fn_105=attr(self_value(),"sleep");Args args_104;args_104.pos(([&]()->V{V left_106=V(0.1);V right_107=([&]()->V{V left_108=([&]()->V{auto fn_111=attr(global("time","Iuno"),"time");Args args_110;return invoke(fn_111,args_110);}());V right_109=scope_34->get("cycle_start");return official::binary("-",left_108,right_109);}());return official::binary("-",left_106,right_107);}()));return invoke(fn_105,args_104);}());
    }
return V{};
}),false);
// Official method Iuno.on_combat_end, lines 84-85
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_117=bind_arguments(official_args,signature,captured);
    // Iuno.py:85
    ([&]()->V{auto fn_119=attr(self_value(),"switch_other_char");Args args_118;return invoke(fn_119,args_118);}());
return V{};
}),false);
}
}
