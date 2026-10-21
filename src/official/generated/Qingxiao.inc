// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Qingxiao.py
// SHA256 66fd24e3cff4bc68d567c206609630894b173211d206e5a11e9a0d048d06ae15
void OfficialCharacter::install_Qingxiao(){
auto scope=std::make_shared<Scope>();
set_class_attribute("HEAVY_TIMEOUT",V(2LL));
set_class_attribute("HEAVY_CONFIRM",V(0.25));
// Official method Qingxiao.__init__, lines 12-14
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Qingxiao.py:13
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Qingxiao");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Qingxiao.py:14
    {V value_6=V(false);set_attr(self_value(),"must_cast_lib_this_turn",value_6);}
return V{};
}),false);
// Official method Qingxiao.do_perform, lines 16-49
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
scope_7->set("broke_on_h2",V::missing());
scope_7->set("heavy",V::missing());
scope_7->set("start",V::missing());
    // Qingxiao.py:17
    {V value_8=([&]()->V{V operand_9;operand_9=([&]()->V{auto fn_11=attr(self_value(),"has_all_buff");Args args_10;return invoke(fn_11,args_10);}());if(!operand_9.truth())return operand_9;return attr(self_value(),"has_intro");}());set_attr(self_value(),"must_cast_lib_this_turn",value_8);}
    // Qingxiao.py:19
    if(unary("not",attr(self_value(),"must_cast_lib_this_turn")).truth()){
        // Qingxiao.py:20
        ([&]()->V{auto fn_13=attr(self_value(),"cast_enhanced_resonance");Args args_12;return invoke(fn_13,args_12);}());
        // Qingxiao.py:21
        return ([&]()->V{auto fn_15=attr(self_value(),"switch_next_char");Args args_14;return invoke(fn_15,args_14);}());
    }
    // Qingxiao.py:23
    {V value_16=([&]()->V{auto fn_18=attr(global("time","Qingxiao"),"time");Args args_17;return invoke(fn_18,args_17);}());scope_7->set("start",value_16);}
    // Qingxiao.py:24
    {V value_19=V(false);scope_7->set("broke_on_h2",value_19);}
    // Qingxiao.py:25
    if(attr(self_value(),"must_cast_lib_this_turn").truth()){
        // Qingxiao.py:26
                while(([&]()->V{V compare_50=([&]()->V{auto fn_53=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_52;args_52.pos(scope_7->get("start"));return invoke(fn_53,args_52);}());V compare_51;V comparison_result_54;compare_51=V(18LL);comparison_result_54=compare_value("<",compare_50,compare_51);return comparison_result_54;}()).truth()){
            // Qingxiao.py:27
            ([&]()->V{auto fn_21=attr(self_value(),"cycle_start");Args args_20;return invoke(fn_21,args_20);}());
            // Qingxiao.py:28
            if(([&]()->V{V assigned_22=([&]()->V{auto fn_24=attr(self_value(),"handle_heavy");Args args_23;return invoke(fn_24,args_23);}());scope_7->set("heavy",assigned_22);return assigned_22;}()).truth()){
                // Qingxiao.py:29
                ([&]()->V{auto fn_26=attr(self_value(),"f_break");Args args_25;return invoke(fn_26,args_25);}());
                // Qingxiao.py:30
                if(([&]()->V{V compare_27=scope_7->get("heavy");V compare_28;V comparison_result_29;compare_28=attr(global("Labels","Qingxiao"),"qingxiao_h2");comparison_result_29=compare_value("==",compare_27,compare_28);return comparison_result_29;}()).truth()){
                    // Qingxiao.py:32
                    if(([&]()->V{V operand_30;operand_30=([&]()->V{V compare_31=attr(self_value(),"task");V compare_32;V comparison_result_33;compare_32=V{};comparison_result_33=compare_value("is not",compare_31,compare_32);return comparison_result_33;}());if(!operand_30.truth())return operand_30;return unary("not",([&]()->V{auto fn_35=attr(self_value(),"liberation_available");Args args_34;return invoke(fn_35,args_34);}()));}()).truth()){
                        // Qingxiao.py:34
                        ([&]()->V{auto fn_37=attr(attr(self_value(),"task"),"wait_until");Args args_36;args_36.pos(V::function([this,captured=capture_scope(scope_7,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_38=bind_arguments(official_args,signature,captured);
return ([&]()->V{auto fn_40=attr(self_value(),"liberation_available");Args args_39;return invoke(fn_40,args_39);}());
}));args_36.kw("time_out",V(1.5));return invoke(fn_37,args_36);}());
                    }
                    // Qingxiao.py:35
                    ([&]()->V{auto fn_42=attr(self_value(),"click_liberation");Args args_41;return invoke(fn_42,args_41);}());
                    // Qingxiao.py:36
                    {V value_43=V(true);scope_7->set("broke_on_h2",value_43);}
                    // Qingxiao.py:37
                    break;
                }
            }else{
                // Qingxiao.py:38
                if(([&]()->V{auto fn_45=attr(self_value(),"cast_enhanced_resonance");Args args_44;return invoke(fn_45,args_44);}()).truth()){
                }else{
                    // Qingxiao.py:41
                    ([&]()->V{auto fn_47=attr(self_value(),"click");Args args_46;return invoke(fn_47,args_46);}());
                }
            }
            // Qingxiao.py:42
            ([&]()->V{auto fn_49=attr(self_value(),"cycle_sleep");Args args_48;return invoke(fn_49,args_48);}());
        }
        // Qingxiao.py:43
        if(unary("not",scope_7->get("broke_on_h2")).truth()){
            // Qingxiao.py:44
            ([&]()->V{auto fn_56=attr(self_value(),"handle_heavy");Args args_55;return invoke(fn_56,args_55);}());
        }
    }
    // Qingxiao.py:46
    if(([&]()->V{V operand_57;operand_57=scope_7->get("broke_on_h2");if(!operand_57.truth())return operand_57;return ([&]()->V{V compare_58=attr(self_value(),"task");V compare_59;V comparison_result_60;compare_59=V{};comparison_result_60=compare_value("is not",compare_58,compare_59);return comparison_result_60;}());}()).truth()){
        // Qingxiao.py:48
        ([&]()->V{auto fn_62=attr(attr(self_value(),"task"),"wait_until");Args args_61;args_61.pos(V::function([this,captured=capture_scope(scope_7,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_63=bind_arguments(official_args,signature,captured);
return item(([&]()->V{auto fn_65=attr(attr(self_value(),"task"),"in_team");Args args_64;return invoke(fn_65,args_64);}()),V(0LL));
}));args_61.kw("time_out",V(1.0));return invoke(fn_62,args_61);}());
    }
    // Qingxiao.py:49
    ([&]()->V{auto fn_67=attr(self_value(),"switch_next_char");Args args_66;return invoke(fn_67,args_66);}());
return V{};
}),false);
// Official method Qingxiao.enhanced_resonance_available, lines 51-52
register_method("enhanced_resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_68=bind_arguments(official_args,signature,captured);
    // Qingxiao.py:52
    return ([&]()->V{auto fn_70=global("bool","Qingxiao");Args args_69;args_69.pos(([&]()->V{auto fn_72=attr(attr(self_value(),"task"),"find_one");Args args_71;args_71.pos(attr(global("Labels","Qingxiao"),"qingxiao_e"));args_71.kw("threshold",V(0.7));return invoke(fn_72,args_71);}()));return invoke(fn_70,args_69);}());
return V{};
}),false);
// Official method Qingxiao.cast_enhanced_resonance, lines 54-61
register_method("cast_enhanced_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_73=bind_arguments(official_args,signature,captured);
    // Qingxiao.py:55
    if(unary("not",([&]()->V{auto fn_75=attr(self_value(),"enhanced_resonance_available");Args args_74;return invoke(fn_75,args_74);}())).truth()){
        // Qingxiao.py:56
        return V(false);
    }
    // Qingxiao.py:57
    return item(([&]()->V{auto fn_77=attr(self_value(),"click_resonance");Args args_76;args_76.kw("has_animation",V(true));args_76.kw("animation_min_duration",V(0.5));args_76.kw("time_out",V(1.5));return invoke(fn_77,args_76);}()),V(0LL));
return V{};
}),false);
// Official method Qingxiao.heavy_available, lines 63-65
register_method("heavy_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_78=bind_arguments(official_args,signature,captured);
    // Qingxiao.py:64
    return ([&]()->V{V operand_79;operand_79=([&]()->V{auto fn_81=attr(attr(self_value(),"task"),"find_one");Args args_80;args_80.pos(attr(global("Labels","Qingxiao"),"qingxiao_h1"));args_80.kw("threshold",V(0.7));return invoke(fn_81,args_80);}());if(operand_79.truth())return operand_79;return ([&]()->V{auto fn_83=attr(attr(self_value(),"task"),"find_one");Args args_82;args_82.pos(attr(global("Labels","Qingxiao"),"qingxiao_h2"));args_82.kw("threshold",V(0.7));return invoke(fn_83,args_82);}());}());
return V{};
}),false);
// Official method Qingxiao.handle_heavy, lines 67-96
register_method("handle_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_84=bind_arguments(official_args,signature,captured);
scope_84->set("dark_since",V::missing());
scope_84->set("exited_confirm",V::missing());
scope_84->set("heavy",V::missing());
scope_84->set("start",V::missing());
    // Qingxiao.py:68
    {V value_85=([&]()->V{auto fn_87=attr(self_value(),"heavy_available");Args args_86;return invoke(fn_87,args_86);}());scope_84->set("heavy",value_85);}
    // Qingxiao.py:69
    if(unary("not",scope_84->get("heavy")).truth()){
        // Qingxiao.py:70
        return V(false);
    }
    // Qingxiao.py:72
    {V value_88=([&]()->V{auto fn_90=attr(global("time","Qingxiao"),"time");Args args_89;return invoke(fn_90,args_89);}());scope_84->set("start",value_88);}
    // Qingxiao.py:73
    {V value_91=V{};scope_84->set("dark_since",value_91);}
    // Qingxiao.py:74
    {V value_92=V(false);scope_84->set("exited_confirm",value_92);}
    // Qingxiao.py:75
    ([&]()->V{auto fn_94=attr(attr(self_value(),"task"),"mouse_down");Args args_93;return invoke(fn_94,args_93);}());
    // Qingxiao.py:76
    {
    auto finally_95=on_scope_exit([&](){
        // Qingxiao.py:92
        ([&]()->V{auto fn_97=attr(attr(self_value(),"task"),"mouse_up");Args args_96;return invoke(fn_97,args_96);}());
    });
        // Qingxiao.py:78
                while(([&]()->V{V compare_117=([&]()->V{auto fn_120=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_119;args_119.pos(scope_84->get("start"));return invoke(fn_120,args_119);}());V compare_118;V comparison_result_121;compare_118=attr(self_value(),"HEAVY_TIMEOUT");comparison_result_121=compare_value("<",compare_117,compare_118);return comparison_result_121;}()).truth()){
            // Qingxiao.py:79
            if(([&]()->V{auto fn_99=attr(self_value(),"heavy_available");Args args_98;return invoke(fn_99,args_98);}()).truth()){
                // Qingxiao.py:80
                {V value_100=V{};scope_84->set("dark_since",value_100);}
                // Qingxiao.py:81
                ([&]()->V{auto fn_102=attr(attr(self_value(),"task"),"next_frame");Args args_101;return invoke(fn_102,args_101);}());
            }else{
                // Qingxiao.py:83
                if(([&]()->V{V compare_103=scope_84->get("dark_since");V compare_104;V comparison_result_105;compare_104=V{};comparison_result_105=compare_value("is",compare_103,compare_104);return comparison_result_105;}()).truth()){
                    // Qingxiao.py:84
                    {V value_106=([&]()->V{auto fn_108=attr(global("time","Qingxiao"),"time");Args args_107;return invoke(fn_108,args_107);}());scope_84->set("dark_since",value_106);}
                }
                // Qingxiao.py:85
                ([&]()->V{auto fn_110=attr(self_value(),"sleep");Args args_109;args_109.pos(attr(self_value(),"HEAVY_CONFIRM"));return invoke(fn_110,args_109);}());
                // Qingxiao.py:86
                ([&]()->V{auto fn_112=attr(attr(self_value(),"task"),"next_frame");Args args_111;return invoke(fn_112,args_111);}());
                // Qingxiao.py:87
                if(unary("not",([&]()->V{auto fn_114=attr(self_value(),"heavy_available");Args args_113;return invoke(fn_114,args_113);}())).truth()){
                    // Qingxiao.py:88
                    {V value_115=V(true);scope_84->set("exited_confirm",value_115);}
                    // Qingxiao.py:89
                    break;
                }
                // Qingxiao.py:90
                {V value_116=V{};scope_84->set("dark_since",value_116);}
            }
        }
    }
    // Qingxiao.py:93
    ([&]()->V{auto fn_123=attr(self_value(),"sleep");Args args_122;args_122.pos(V(0.01));return invoke(fn_123,args_122);}());
    // Qingxiao.py:94
    if(scope_84->get("exited_confirm").truth()){
        // Qingxiao.py:95
        return attr(scope_84->get("heavy"),"name");
    }
    // Qingxiao.py:96
    return V(false);
return V{};
}),false);
}
