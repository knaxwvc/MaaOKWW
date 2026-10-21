// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Douling.py
// SHA256 ec2d0854c46360975061b2c810edd65e1414dd5cca1eb35d82728da977472fa9
void OfficialCharacter::install_Douling(){
auto scope=std::make_shared<Scope>();
// Official method Douling.__init__, lines 8-10
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Douling.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Douling");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Douling.py:10
    {V value_6=V(1LL);set_attr(self_value(),"_segment",value_6);}
return V{};
}),false);
// Official method Douling.do_perform, lines 12-16
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Douling.py:13
    if(([&]()->V{V compare_8=attr(self_value(),"_segment");V compare_9;V comparison_result_10;compare_9=V(1LL);comparison_result_10=compare_value("==",compare_8,compare_9);return comparison_result_10;}()).truth()){
        // Douling.py:14
        ([&]()->V{auto fn_12=attr(self_value(),"_do_segment1");Args args_11;return invoke(fn_12,args_11);}());
    }else{
        // Douling.py:16
        ([&]()->V{auto fn_14=attr(self_value(),"_do_segment2");Args args_13;return invoke(fn_14,args_13);}());
    }
return V{};
}),false);
// Official method Douling._do_segment1, lines 18-33
register_method("_do_segment1",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
scope_15->set("clicked",V::missing());
    // Douling.py:19
    ([&]()->V{auto fn_17=attr(self_value(),"_normal_attack_cycle");Args args_16;args_16.pos(V(1.2));return invoke(fn_17,args_16);}());
    // Douling.py:20
    if(([&]()->V{auto fn_19=attr(self_value(),"flying");Args args_18;return invoke(fn_19,args_18);}()).truth()){
        // Douling.py:21
        ([&]()->V{auto fn_21=attr(self_value(),"wait_down");Args args_20;return invoke(fn_21,args_20);}());
    }
    // Douling.py:22
    ([&]()->V{auto fn_23=attr(self_value(),"check_combat");Args args_22;return invoke(fn_23,args_22);}());
    // Douling.py:23
    {V value_24=item(([&]()->V{auto fn_26=attr(self_value(),"click_resonance");Args args_25;args_25.kw("send_click",V(true));args_25.kw("time_out",V(0.5));return invoke(fn_26,args_25);}()),V(0LL));scope_15->set("clicked",value_24);}
    // Douling.py:24
    if(unary("not",scope_15->get("clicked")).truth()){
        // Douling.py:25
        ([&]()->V{auto fn_28=attr(self_value(),"_finish_and_reset");Args args_27;return invoke(fn_28,args_27);}());
        // Douling.py:26
        return V{};
    }
    // Douling.py:27
    ([&]()->V{auto fn_30=attr(self_value(),"sleep");Args args_29;args_29.pos(V(0.2));return invoke(fn_30,args_29);}());
    // Douling.py:28
    if(([&]()->V{auto fn_32=attr(self_value(),"flying");Args args_31;return invoke(fn_32,args_31);}()).truth()){
        // Douling.py:29
        ([&]()->V{auto fn_34=attr(self_value(),"wait_down");Args args_33;return invoke(fn_34,args_33);}());
    }
    // Douling.py:30
    ([&]()->V{auto fn_36=attr(self_value(),"check_combat");Args args_35;return invoke(fn_36,args_35);}());
    // Douling.py:31
    ([&]()->V{auto fn_38=attr(self_value(),"_normal_attack_cycle");Args args_37;args_37.pos(V(1.0));return invoke(fn_38,args_37);}());
    // Douling.py:32
    {V value_39=V(2LL);set_attr(self_value(),"_segment",value_39);}
    // Douling.py:33
    ([&]()->V{auto fn_41=attr(self_value(),"switch_next_char");Args args_40;return invoke(fn_41,args_40);}());
return V{};
}),false);
// Official method Douling._do_segment2, lines 35-50
register_method("_do_segment2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_42=bind_arguments(official_args,signature,captured);
    // Douling.py:36
    ([&]()->V{auto fn_44=attr(self_value(),"check_combat");Args args_43;return invoke(fn_44,args_43);}());
    // Douling.py:37
    ([&]()->V{auto fn_46=attr(attr(self_value(),"task"),"jump");Args args_45;args_45.kw("after_sleep",V(0.01));return invoke(fn_46,args_45);}());
    // Douling.py:38
    ([&]()->V{auto fn_48=attr(self_value(),"sleep");Args args_47;args_47.pos(V(0.05));return invoke(fn_48,args_47);}());
    // Douling.py:39
    ([&]()->V{auto fn_50=attr(self_value(),"check_combat");Args args_49;return invoke(fn_50,args_49);}());
    // Douling.py:40
    if(([&]()->V{auto fn_52=attr(self_value(),"flying");Args args_51;return invoke(fn_52,args_51);}()).truth()){
        // Douling.py:41
        ([&]()->V{auto fn_54=attr(self_value(),"click");Args args_53;return invoke(fn_54,args_53);}());
        // Douling.py:42
        ([&]()->V{auto fn_56=attr(self_value(),"sleep");Args args_55;args_55.pos(V(0.05));return invoke(fn_56,args_55);}());
    }else{
        // Douling.py:44
        ([&]()->V{auto fn_58=attr(self_value(),"wait_down");Args args_57;return invoke(fn_58,args_57);}());
    }
    // Douling.py:45
    ([&]()->V{auto fn_60=attr(self_value(),"check_combat");Args args_59;return invoke(fn_60,args_59);}());
    // Douling.py:46
    ([&]()->V{auto fn_62=attr(self_value(),"_heavy_attack_hold");Args args_61;args_61.pos(V(2.5));return invoke(fn_62,args_61);}());
    // Douling.py:47
    ([&]()->V{auto fn_64=attr(self_value(),"click_echo");Args args_63;args_63.kw("time_out",V(0LL));return invoke(fn_64,args_63);}());
    // Douling.py:48
    ([&]()->V{auto fn_66=attr(self_value(),"click_liberation");Args args_65;return invoke(fn_66,args_65);}());
    // Douling.py:49
    {V value_67=V(1LL);set_attr(self_value(),"_segment",value_67);}
    // Douling.py:50
    ([&]()->V{auto fn_69=attr(self_value(),"switch_next_char");Args args_68;return invoke(fn_69,args_68);}());
return V{};
}),false);
// Official method Douling._finish_and_reset, lines 52-56
register_method("_finish_and_reset",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_70=bind_arguments(official_args,signature,captured);
    // Douling.py:53
    ([&]()->V{auto fn_72=attr(self_value(),"click_echo");Args args_71;args_71.kw("time_out",V(0LL));return invoke(fn_72,args_71);}());
    // Douling.py:54
    ([&]()->V{auto fn_74=attr(self_value(),"click_liberation");Args args_73;return invoke(fn_74,args_73);}());
    // Douling.py:55
    {V value_75=V(1LL);set_attr(self_value(),"_segment",value_75);}
    // Douling.py:56
    ([&]()->V{auto fn_77=attr(self_value(),"switch_next_char");Args args_76;return invoke(fn_77,args_76);}());
return V{};
}),false);
// Official method Douling._normal_attack_cycle, lines 58-66
register_method("_normal_attack_cycle",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_78=bind_arguments(official_args,signature,captured);
scope_78->set("start",V::missing());
    // Douling.py:59
    {V value_79=([&]()->V{auto fn_81=attr(global("time","Douling"),"time");Args args_80;return invoke(fn_81,args_80);}());scope_78->set("start",value_79);}
    // Douling.py:60
        while(([&]()->V{V compare_92=([&]()->V{V left_94=([&]()->V{auto fn_97=attr(global("time","Douling"),"time");Args args_96;return invoke(fn_97,args_96);}());V right_95=scope_78->get("start");return official::binary("-",left_94,right_95);}());V compare_93;V comparison_result_98;compare_93=scope_78->get("duration");comparison_result_98=compare_value("<",compare_92,compare_93);return comparison_result_98;}()).truth()){
        // Douling.py:61
        ([&]()->V{auto fn_83=attr(self_value(),"cycle_start");Args args_82;return invoke(fn_83,args_82);}());
        // Douling.py:62
        if(([&]()->V{auto fn_85=attr(self_value(),"flying");Args args_84;return invoke(fn_85,args_84);}()).truth()){
            // Douling.py:63
            ([&]()->V{auto fn_87=attr(self_value(),"wait_down");Args args_86;return invoke(fn_87,args_86);}());
            // Douling.py:64
            break;
        }
        // Douling.py:65
        ([&]()->V{auto fn_89=attr(self_value(),"click");Args args_88;return invoke(fn_89,args_88);}());
        // Douling.py:66
        ([&]()->V{auto fn_91=attr(self_value(),"cycle_sleep");Args args_90;return invoke(fn_91,args_90);}());
    }
return V{};
}),false);
// Official method Douling._heavy_attack_hold, lines 68-84
register_method("_heavy_attack_hold",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_99=bind_arguments(official_args,signature,captured);
scope_99->set("_",V::missing());
scope_99->set("interrupted",V::missing());
scope_99->set("retries",V::missing());
scope_99->set("start",V::missing());
    // Douling.py:69
    {V value_100=V(3LL);scope_99->set("retries",value_100);}
    // Douling.py:70
    {auto iterator_101=official::iterate(([&]()->V{auto fn_130=global("range","Douling");Args args_129;args_129.pos(scope_99->get("retries"));return invoke(fn_130,args_129);}()));V item_102;while(iterator_101.next(item_102)){
        scope_99->set("_",item_102);
        // Douling.py:71
        ([&]()->V{auto fn_104=attr(self_value(),"check_combat");Args args_103;return invoke(fn_104,args_103);}());
        // Douling.py:72
        ([&]()->V{auto fn_106=attr(attr(self_value(),"task"),"mouse_down");Args args_105;return invoke(fn_106,args_105);}());
        // Douling.py:73
        {V value_107=([&]()->V{auto fn_109=attr(global("time","Douling"),"time");Args args_108;return invoke(fn_109,args_108);}());scope_99->set("start",value_107);}
        // Douling.py:74
        {V value_110=V(false);scope_99->set("interrupted",value_110);}
        // Douling.py:75
                while(([&]()->V{V compare_116=([&]()->V{V left_118=([&]()->V{auto fn_121=attr(global("time","Douling"),"time");Args args_120;return invoke(fn_121,args_120);}());V right_119=scope_99->get("start");return official::binary("-",left_118,right_119);}());V compare_117;V comparison_result_122;compare_117=scope_99->get("duration");comparison_result_122=compare_value("<",compare_116,compare_117);return comparison_result_122;}()).truth()){
            // Douling.py:76
            if(([&]()->V{auto fn_112=attr(self_value(),"flying");Args args_111;return invoke(fn_112,args_111);}()).truth()){
                // Douling.py:77
                {V value_113=V(true);scope_99->set("interrupted",value_113);}
                // Douling.py:78
                break;
            }
            // Douling.py:79
            ([&]()->V{auto fn_115=attr(self_value(),"sleep");Args args_114;args_114.pos(V(0.1));return invoke(fn_115,args_114);}());
        }
        // Douling.py:80
        ([&]()->V{auto fn_124=attr(attr(self_value(),"task"),"mouse_up");Args args_123;return invoke(fn_124,args_123);}());
        // Douling.py:81
        ([&]()->V{auto fn_126=attr(self_value(),"sleep");Args args_125;args_125.pos(V(0.01));return invoke(fn_126,args_125);}());
        // Douling.py:82
        if(unary("not",scope_99->get("interrupted")).truth()){
            // Douling.py:83
            return V{};
        }
        // Douling.py:84
        ([&]()->V{auto fn_128=attr(self_value(),"wait_down");Args args_127;return invoke(fn_128,args_127);}());
    }
    }
return V{};
}),false);
// Official method Douling.get_switch_priority, lines 86-89
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_131=bind_arguments(official_args,signature,captured);
    // Douling.py:87
    if(([&]()->V{V compare_132=([&]()->V{auto fn_135=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_134;args_134.pos(attr(self_value(),"last_perform"));return invoke(fn_135,args_134);}());V compare_133;V comparison_result_136;compare_133=V(8LL);comparison_result_136=compare_value("<",compare_132,compare_133);return comparison_result_136;}()).truth()){
        // Douling.py:88
        return attr(global("SwitchPriority","Douling"),"NO");
    }
    // Douling.py:89
    return attr(global("SwitchPriority","Douling"),"NORMAL");
return V{};
}),false);
}
