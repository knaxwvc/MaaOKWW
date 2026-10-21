// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Encore.py
// SHA256 44bbb90a97e16e241c5ecd45f432710a1c165ebed3736ce31a9b1cd6fd568470
void OfficialCharacter::install_Encore(){
auto scope=std::make_shared<Scope>();
// Official method Encore.__init__, lines 8-12
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Encore.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Encore");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Encore.py:10
    {V value_6=V(0LL);set_attr(self_value(),"last_heavy",value_6);}
    // Encore.py:11
    {V value_7=V(0LL);set_attr(self_value(),"liberation_time",value_7);}
    // Encore.py:12
    {V value_8=V(0LL);set_attr(self_value(),"last_resonance",value_8);}
return V{};
}),false);
// Official method Encore.still_in_liberation, lines 14-15
register_method("still_in_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_9=bind_arguments(official_args,signature,captured);
    // Encore.py:15
    return ([&]()->V{V compare_10=([&]()->V{auto fn_13=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_12;args_12.pos(attr(self_value(),"liberation_time"));return invoke(fn_13,args_12);}());V compare_11;V comparison_result_14;compare_11=V(9.5);comparison_result_14=compare_value("<",compare_10,compare_11);return comparison_result_14;}());
return V{};
}),false);
// Official method Encore.switch_out, lines 17-19
register_method("switch_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
    // Encore.py:18
    ([&]()->V{auto fn_19=attr(([&]()->V{auto fn_17=global("super","Encore");Args args_16;return invoke(fn_17,args_16);}()),"switch_out");Args args_18;args_18.kw("con_full",scope_15->get("con_full"));return invoke(fn_19,args_18);}());
    // Encore.py:19
    {V value_20=V(0LL);set_attr(self_value(),"last_resonance",value_20);}
return V{};
}),false);
// Official method Encore.get_switch_priority, lines 21-29
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
    // Encore.py:22
    ([&]()->V{auto fn_23=attr(attr(self_value(),"logger"),"debug");Args args_22;args_22.pos(V(std::string{}+"encore last heavy time "+format_value(attr(self_value(),"last_heavy"),"",-1)+" "+format_value(([&]()->V{auto fn_25=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_24;args_24.pos(attr(self_value(),"last_heavy"));args_24.pos(V(true));return invoke(fn_25,args_24);}()),"",-1)));return invoke(fn_23,args_22);}());
    // Encore.py:24
    if(([&]()->V{V compare_26=([&]()->V{auto fn_29=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_28;args_28.pos(attr(self_value(),"last_heavy"));args_28.pos(V(true));return invoke(fn_29,args_28);}());V compare_27;V comparison_result_30;compare_27=V(4.6);comparison_result_30=compare_value("<",compare_26,compare_27);return comparison_result_30;}()).truth()){
        // Encore.py:25
        return attr(global("SwitchPriority","Encore"),"NO");
    }
    // Encore.py:26
    if(([&]()->V{V operand_31;operand_31=([&]()->V{auto fn_33=attr(self_value(),"still_in_liberation");Args args_32;return invoke(fn_33,args_32);}());if(operand_31.truth())return operand_31;return ([&]()->V{auto fn_35=attr(self_value(),"can_resonance_step2");Args args_34;return invoke(fn_35,args_34);}());}()).truth()){
        // Encore.py:27
        ([&]()->V{auto fn_37=attr(attr(self_value(),"logger"),"info");Args args_36;args_36.pos(V(std::string{}+"switch priority MAX because still in liberation"));return invoke(fn_37,args_36);}());
        // Encore.py:28
        return attr(global("SwitchPriority","Encore"),"MUST");
    }
    // Encore.py:29
    return ([&]()->V{auto fn_41=attr(([&]()->V{auto fn_39=global("super","Encore");Args args_38;return invoke(fn_39,args_38);}()),"get_switch_priority");Args args_40;args_40.pos(scope_21->get("current_char"));args_40.pos(scope_21->get("has_intro"));args_40.pos(scope_21->get("target_low_con"));return invoke(fn_41,args_40);}());
return V{};
}),false);
// Official method Encore.do_perform, lines 31-61
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_42=bind_arguments(official_args,signature,captured);
scope_42->set("elapsed",V::missing());
    // Encore.py:32
    if(attr(self_value(),"has_intro").truth()){
        // Encore.py:33
        {V value_43=([&]()->V{auto fn_45=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_44;args_44.pos(attr(self_value(),"liberation_time"));return invoke(fn_45,args_44);}());scope_42->set("elapsed",value_43);}
        // Encore.py:34
        ([&]()->V{auto fn_47=attr(attr(self_value(),"logger"),"debug");Args args_46;args_46.pos(V(std::string{}+"encore wait intro "+format_value(scope_42->get("elapsed"),"",-1)));return invoke(fn_47,args_46);}());
        // Encore.py:35
        if(([&]()->V{V operand_48;operand_48=([&]()->V{V compare_49=V(6LL);V compare_50;V comparison_result_51;compare_50=scope_42->get("elapsed");comparison_result_51=compare_value("<",compare_49,compare_50);if(!comparison_result_51.truth())return comparison_result_51;compare_49=compare_50;compare_50=V(10LL);comparison_result_51=compare_value("<",compare_49,compare_50);return comparison_result_51;}());if(!operand_48.truth())return operand_48;return ([&]()->V{auto fn_53=attr(self_value(),"is_mouse_forte_full");Args args_52;return invoke(fn_53,args_52);}());}()).truth()){
            // Encore.py:36
            ([&]()->V{auto fn_55=attr(attr(self_value(),"logger"),"debug");Args args_54;args_54.pos(V("encore heavy attack after intro"));return invoke(fn_55,args_54);}());
            // Encore.py:37
            ([&]()->V{auto fn_57=attr(self_value(),"heavy_attack");Args args_56;args_56.pos(V(1.2));return invoke(fn_57,args_56);}());
            // Encore.py:38
            ([&]()->V{auto fn_59=attr(self_value(),"sleep");Args args_58;args_58.pos(V(0.1));return invoke(fn_59,args_58);}());
            // Encore.py:39
            {V value_60=([&]()->V{auto fn_62=attr(global("time","Encore"),"time");Args args_61;return invoke(fn_62,args_61);}());set_attr(self_value(),"last_heavy",value_60);}
            // Encore.py:40
            return ([&]()->V{auto fn_64=attr(self_value(),"switch_next_char");Args args_63;return invoke(fn_64,args_63);}());
        }else{
            // Encore.py:42
            ([&]()->V{auto fn_66=attr(self_value(),"wait_down");Args args_65;return invoke(fn_66,args_65);}());
        }
    }
    // Encore.py:43
    if(([&]()->V{auto fn_68=attr(self_value(),"still_in_liberation");Args args_67;return invoke(fn_68,args_67);}()).truth()){
        // Encore.py:44
        ([&]()->V{auto fn_70=attr(self_value(),"n4");Args args_69;return invoke(fn_70,args_69);}());
        // Encore.py:45
        return ([&]()->V{auto fn_72=attr(self_value(),"switch_next_char");Args args_71;return invoke(fn_72,args_71);}());
    }
    // Encore.py:46
    if(item(([&]()->V{auto fn_74=attr(self_value(),"click_resonance");Args args_73;return invoke(fn_74,args_73);}()),V(0LL)).truth()){
        // Encore.py:47
        if(unary("not",([&]()->V{auto fn_76=attr(self_value(),"can_resonance_step2");Args args_75;args_75.kw("delay",V(4LL));return invoke(fn_76,args_75);}())).truth()){
            // Encore.py:48
            {V value_77=([&]()->V{auto fn_79=attr(global("time","Encore"),"time");Args args_78;return invoke(fn_79,args_78);}());set_attr(self_value(),"last_resonance",value_77);}
            // Encore.py:49
            return ([&]()->V{auto fn_81=attr(self_value(),"switch_next_char");Args args_80;return invoke(fn_81,args_80);}());
        }
    }
    // Encore.py:50
    if(([&]()->V{V operand_82;operand_82=unary("not",([&]()->V{auto fn_84=attr(self_value(),"need_fast_perform");Args args_83;return invoke(fn_84,args_83);}()));if(!operand_82.truth())return operand_82;operand_82=unary("not",([&]()->V{auto fn_86=attr(self_value(),"is_open_world_auto_combat");Args args_85;return invoke(fn_86,args_85);}()));if(!operand_82.truth())return operand_82;return ([&]()->V{auto fn_88=attr(self_value(),"click_liberation");Args args_87;args_87.kw("wait_if_cd_ready",V(0.4));return invoke(fn_88,args_87);}());}()).truth()){
        // Encore.py:52
        {V value_89=([&]()->V{auto fn_91=attr(global("time","Encore"),"time");Args args_90;return invoke(fn_91,args_90);}());set_attr(self_value(),"liberation_time",value_89);}
        // Encore.py:53
        ([&]()->V{auto fn_93=attr(self_value(),"n4");Args args_92;return invoke(fn_93,args_92);}());
        // Encore.py:54
        return ([&]()->V{auto fn_95=attr(self_value(),"switch_next_char");Args args_94;return invoke(fn_95,args_94);}());
    }else{
        // Encore.py:56
        ([&]()->V{auto fn_97=attr(attr(self_value(),"logger"),"info");Args args_96;args_96.pos(V("Encore nothing is available"));return invoke(fn_97,args_96);}());
    }
    // Encore.py:57
    if(([&]()->V{auto fn_99=attr(self_value(),"echo_available");Args args_98;return invoke(fn_99,args_98);}()).truth()){
        // Encore.py:58
        ([&]()->V{auto fn_101=attr(attr(self_value(),"logger"),"debug");Args args_100;args_100.pos(V("click_echo"));return invoke(fn_101,args_100);}());
        // Encore.py:59
        ([&]()->V{auto fn_103=attr(self_value(),"click_echo");Args args_102;return invoke(fn_103,args_102);}());
        // Encore.py:60
        return ([&]()->V{auto fn_105=attr(self_value(),"switch_next_char");Args args_104;return invoke(fn_105,args_104);}());
    }
    // Encore.py:61
    ([&]()->V{auto fn_107=attr(self_value(),"switch_next_char");Args args_106;return invoke(fn_107,args_106);}());
return V{};
}),false);
// Official method Encore.can_resonance_step2, lines 63-64
register_method("can_resonance_step2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"delay",V(2LL)}},"","",{})](const Args& official_args)->V{
auto scope_108=bind_arguments(official_args,signature,captured);
    // Encore.py:64
    return ([&]()->V{V compare_109=([&]()->V{auto fn_112=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_111;args_111.pos(attr(self_value(),"last_resonance"));args_111.pos(V(true));return invoke(fn_112,args_111);}());V compare_110;V comparison_result_113;compare_110=scope_108->get("delay");comparison_result_113=compare_value("<",compare_109,compare_110);return comparison_result_113;}());
return V{};
}),false);
// Official method Encore.n4, lines 66-77
register_method("n4",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V(2.0)}},"","",{})](const Args& official_args)->V{
auto scope_114=bind_arguments(official_args,signature,captured);
    // Encore.py:67
    {V value_115=(item(([&]()->V{auto fn_117=attr(self_value(),"click_resonance");Args args_116;return invoke(fn_117,args_116);}()),V(0LL)).truth()?V(2.7):V(2.4));scope_114->set("duration",value_115);}
    // Encore.py:68
    if(([&]()->V{V compare_118=([&]()->V{auto fn_121=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_120;args_120.pos(attr(self_value(),"liberation_time"));return invoke(fn_121,args_120);}());V compare_119;V comparison_result_122;compare_119=V(6LL);comparison_result_122=compare_value("<",compare_118,compare_119);return comparison_result_122;}()).truth()){
        // Encore.py:69
        ([&]()->V{auto fn_124=attr(attr(self_value(),"logger"),"debug");Args args_123;args_123.pos(V("encore liberation n4"));return invoke(fn_124,args_123);}());
        // Encore.py:70
        ([&]()->V{auto fn_126=attr(self_value(),"continues_normal_attack");Args args_125;args_125.kw("duration",scope_114->get("duration"));return invoke(fn_126,args_125);}());
    }else{
        // Encore.py:71
        if(([&]()->V{auto fn_128=attr(self_value(),"is_mouse_forte_full");Args args_127;return invoke(fn_128,args_127);}()).truth()){
            // Encore.py:72
            ([&]()->V{auto fn_130=attr(self_value(),"heavy_attack");Args args_129;return invoke(fn_130,args_129);}());
            // Encore.py:73
            ([&]()->V{auto fn_132=attr(attr(self_value(),"logger"),"debug");Args args_131;args_131.pos(V("encore liberation heavy"));return invoke(fn_132,args_131);}());
            // Encore.py:74
            {V value_133=([&]()->V{auto fn_135=attr(global("time","Encore"),"time");Args args_134;return invoke(fn_135,args_134);}());set_attr(self_value(),"last_heavy",value_133);}
        }else{
            // Encore.py:76
            ([&]()->V{auto fn_137=attr(attr(self_value(),"logger"),"debug");Args args_136;args_136.pos(V("encore liberation nothing to do"));return invoke(fn_137,args_136);}());
            // Encore.py:77
            ([&]()->V{auto fn_139=attr(self_value(),"click_resonance");Args args_138;return invoke(fn_139,args_138);}());
        }
    }
return V{};
}),false);
}
