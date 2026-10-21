// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Xigelika.py
// SHA256 7f79589b0b00fc613453c3fe3a468cca4792a4f0eafdd9b37291e0cd2d845810
void OfficialCharacter::install_Xigelika(){
auto scope=std::make_shared<Scope>();
set_global("forte_white_color",([&]()->V{V dictionary_1=V::dict();set_item(dictionary_1,V("r"),V::tuple({V(244LL),V(255LL)}));set_item(dictionary_1,V("g"),V::tuple({V(246LL),V(255LL)}));set_item(dictionary_1,V("b"),V::tuple({V(250LL),V(255LL)}));return dictionary_1;}()));
// Official method Xigelika.__init__, lines 8-9
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_2=bind_arguments(official_args,signature,captured);
    // Xigelika.py:9
    ([&]()->V{auto fn_6=attr(([&]()->V{auto fn_4=global("super","Xigelika");Args args_3;return invoke(fn_4,args_3);}()),"__init__");Args args_5;args_5.spread(scope_2->get("args"));args_5.spread_keywords(scope_2->get("kwargs"));return invoke(fn_6,args_5);}());
return V{};
}),false);
// Official method Xigelika.do_perform, lines 11-17
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Xigelika.py:12
    if(attr(self_value(),"has_intro").truth()){
        // Xigelika.py:13
        ([&]()->V{auto fn_9=attr(self_value(),"continues_normal_attack");Args args_8;args_8.pos(V(0.77));return invoke(fn_9,args_8);}());
    }else{
        // Xigelika.py:15
        ([&]()->V{auto fn_11=attr(self_value(),"wait_down");Args args_10;return invoke(fn_11,args_10);}());
    }
    // Xigelika.py:16
    ([&]()->V{auto fn_13=attr(self_value(),"perform_everything");Args args_12;return invoke(fn_13,args_12);}());
    // Xigelika.py:17
    ([&]()->V{auto fn_15=attr(self_value(),"switch_next_char");Args args_14;return invoke(fn_15,args_14);}());
return V{};
}),false);
// Official method Xigelika.lib, lines 19-22
register_method("lib",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_16=bind_arguments(official_args,signature,captured);
    // Xigelika.py:20
    if(([&]()->V{auto fn_18=attr(self_value(),"click_liberation");Args args_17;args_17.kw("wait_if_cd_ready",V(0LL));return invoke(fn_18,args_17);}()).truth()){
        // Xigelika.py:21
        ([&]()->V{auto fn_20=attr(self_value(),"f_break");Args args_19;return invoke(fn_20,args_19);}());
        // Xigelika.py:22
        return V(true);
    }
return V{};
}),false);
// Official method Xigelika.perform_everything, lines 24-42
register_method("perform_everything",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
scope_21->set("start",V::missing());
scope_21->set("time_out",V::missing());
    // Xigelika.py:25
    {V value_22=([&]()->V{auto fn_24=attr(global("time","Xigelika"),"time");Args args_23;return invoke(fn_24,args_23);}());scope_21->set("start",value_22);}
    // Xigelika.py:26
    {V value_25=V(0.5);scope_21->set("time_out",value_25);}
    // Xigelika.py:27
    if(attr(self_value(),"has_sub_dps_intro").truth()){
        // Xigelika.py:28
        {V value_26=V(15LL);scope_21->set("time_out",value_26);}
    }
    // Xigelika.py:29
        while(([&]()->V{V compare_48=([&]()->V{auto fn_51=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_50;args_50.pos(scope_21->get("start"));return invoke(fn_51,args_50);}());V compare_49;V comparison_result_52;compare_49=scope_21->get("time_out");comparison_result_52=compare_value("<",compare_48,compare_49);return comparison_result_52;}()).truth()){
        // Xigelika.py:30
        ([&]()->V{auto fn_28=attr(self_value(),"click_echo");Args args_27;args_27.kw("time_out",V(0LL));return invoke(fn_28,args_27);}());
        // Xigelika.py:31
        if(([&]()->V{auto fn_30=attr(self_value(),"flying");Args args_29;return invoke(fn_30,args_29);}()).truth()){
            // Xigelika.py:32
            ([&]()->V{auto fn_32=attr(self_value(),"shorekeeper_auto_dodge");Args args_31;return invoke(fn_32,args_31);}());
        }
        // Xigelika.py:33
        if(([&]()->V{auto fn_34=attr(self_value(),"handle_heavy");Args args_33;return invoke(fn_34,args_33);}()).truth()){
            // Xigelika.py:34
            return V{};
        }else{
            // Xigelika.py:35
            if(([&]()->V{V operand_35;operand_35=unary("not",attr(self_value(),"has_intro"));if(!operand_35.truth())return operand_35;return ([&]()->V{auto fn_37=attr(self_value(),"lib");Args args_36;return invoke(fn_37,args_36);}());}()).truth()){
                // Xigelika.py:36
                {V value_38=V(15LL);scope_21->set("time_out",value_38);}
                // Xigelika.py:37
                {V value_39=([&]()->V{auto fn_41=attr(global("time","Xigelika"),"time");Args args_40;return invoke(fn_41,args_40);}());scope_21->set("start",value_39);}
            }else{
                // Xigelika.py:38
                if(item(([&]()->V{auto fn_43=attr(self_value(),"click_resonance");Args args_42;args_42.kw("send_click",V(false));args_42.kw("time_out",V(2LL));return invoke(fn_43,args_42);}()),V(0LL)).truth()){
                }else{
                    // Xigelika.py:41
                    ([&]()->V{auto fn_45=attr(self_value(),"click");Args args_44;args_44.kw("interval",V(0.1));return invoke(fn_45,args_44);}());
                }
            }
        }
        // Xigelika.py:42
        ([&]()->V{auto fn_47=attr(self_value(),"sleep");Args args_46;args_46.pos(V(0.05));return invoke(fn_47,args_46);}());
    }
return V{};
}),false);
// Official method Xigelika.heavy_wait_highlight_down, lines 44-62
register_method("heavy_wait_highlight_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_53=bind_arguments(official_args,signature,captured);
scope_53->set("ret",V::missing());
scope_53->set("use_mouse",V::missing());
scope_53->set("wait",V::missing());
    // Xigelika.py:45
    {V value_54=([&]()->V{auto fn_56=attr(self_value(),"has_long_action");Args args_55;return invoke(fn_56,args_55);}());scope_53->set("use_mouse",value_54);}
    // Xigelika.py:46
    if(scope_53->get("use_mouse").truth()){
        // Xigelika.py:47
        ([&]()->V{auto fn_58=attr(attr(self_value(),"task"),"mouse_down");Args args_57;return invoke(fn_58,args_57);}());
        // Xigelika.py:48
        {V value_59=V::function([this,captured=capture_scope(scope_53,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_60=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_62=attr(self_value(),"has_long_action");Args args_61;return invoke(fn_62,args_61);}()));
});scope_53->set("wait",value_59);}
    }else{
        // Xigelika.py:50
        if(([&]()->V{auto fn_64=attr(self_value(),"has_cd");Args args_63;args_63.pos(V("resonance"));return invoke(fn_64,args_63);}()).truth()){
            // Xigelika.py:51
            ([&]()->V{auto fn_66=attr(self_value(),"click");Args args_65;args_65.kw("interval",V(0.1));return invoke(fn_66,args_65);}());
            // Xigelika.py:52
            ([&]()->V{auto fn_68=attr(self_value(),"sleep");Args args_67;args_67.pos(V(0.05));return invoke(fn_68,args_67);}());
            // Xigelika.py:53
            return V(false);
        }
        // Xigelika.py:54
        ([&]()->V{auto fn_70=attr(attr(self_value(),"task"),"send_key_down");Args args_69;args_69.pos(([&]()->V{auto fn_72=attr(self_value(),"get_resonance_key");Args args_71;return invoke(fn_72,args_71);}()));return invoke(fn_70,args_69);}());
        // Xigelika.py:55
        {V value_73=V::function([this,captured=capture_scope(scope_53,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_74=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_76=attr(self_value(),"is_forte_full");Args args_75;return invoke(fn_76,args_75);}()));
});scope_53->set("wait",value_73);}
    }
    // Xigelika.py:56
    {V value_77=([&]()->V{auto fn_79=attr(attr(self_value(),"task"),"wait_until");Args args_78;args_78.pos(scope_53->get("wait"));args_78.kw("time_out",V(1.2));return invoke(fn_79,args_78);}());scope_53->set("ret",value_77);}
    // Xigelika.py:57
    if(scope_53->get("use_mouse").truth()){
        // Xigelika.py:58
        ([&]()->V{auto fn_81=attr(attr(self_value(),"task"),"mouse_up");Args args_80;return invoke(fn_81,args_80);}());
    }else{
        // Xigelika.py:60
        ([&]()->V{auto fn_83=attr(attr(self_value(),"task"),"send_key_up");Args args_82;args_82.pos(([&]()->V{auto fn_85=attr(self_value(),"get_resonance_key");Args args_84;return invoke(fn_85,args_84);}()));return invoke(fn_83,args_82);}());
    }
    // Xigelika.py:61
    ([&]()->V{auto fn_87=attr(self_value(),"sleep");Args args_86;args_86.pos(V(0.01));return invoke(fn_87,args_86);}());
    // Xigelika.py:62
    return scope_53->get("ret");
return V{};
}),false);
// Official method Xigelika.handle_heavy, lines 64-70
register_method("handle_heavy",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_88=bind_arguments(official_args,signature,captured);
scope_88->set("handled",V::missing());
scope_88->set("start",V::missing());
    // Xigelika.py:65
    {V value_89=V(false);scope_88->set("handled",value_89);}
    // Xigelika.py:66
    {V value_90=([&]()->V{auto fn_92=attr(global("time","Xigelika"),"time");Args args_91;return invoke(fn_92,args_91);}());scope_88->set("start",value_90);}
    // Xigelika.py:67
        while(([&]()->V{V operand_96;operand_96=([&]()->V{auto fn_98=attr(self_value(),"is_forte_full");Args args_97;return invoke(fn_98,args_97);}());if(!operand_96.truth())return operand_96;return ([&]()->V{V compare_99=([&]()->V{auto fn_102=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_101;args_101.pos(scope_88->get("start"));return invoke(fn_102,args_101);}());V compare_100;V comparison_result_103;compare_100=V(3LL);comparison_result_103=compare_value("<",compare_99,compare_100);return comparison_result_103;}());}()).truth()){
        // Xigelika.py:68
        ([&]()->V{auto fn_94=attr(self_value(),"heavy_wait_highlight_down");Args args_93;return invoke(fn_94,args_93);}());
        // Xigelika.py:69
        {V value_95=V(true);scope_88->set("handled",value_95);}
    }
    // Xigelika.py:70
    return scope_88->get("handled");
return V{};
}),false);
// Official method Xigelika.shorekeeper_auto_dodge, lines 72-76
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_104=bind_arguments(official_args,signature,captured);
scope_104->set("ShoreKeeper",V::missing());
scope_104->set("char",V::missing());
scope_104->set("i",V::missing());
    // Xigelika.py:73
    scope_104->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Xigelika.py:74
    {auto iterator_105=official::iterate(([&]()->V{auto fn_112=global("enumerate","Xigelika");Args args_111;args_111.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_112,args_111);}()));V item_106;while(iterator_105.next(item_106)){
        auto unpack_113=unpack(item_106,2);scope_104->set("i",unpack_113[0]);scope_104->set("char",unpack_113[1]);
        // Xigelika.py:75
        if(([&]()->V{auto fn_108=global("isinstance","Xigelika");Args args_107;args_107.pos(scope_104->get("char"));args_107.pos(scope_104->get("ShoreKeeper"));return invoke(fn_108,args_107);}()).truth()){
            // Xigelika.py:76
            return ([&]()->V{auto fn_110=attr(scope_104->get("char"),"auto_dodge");Args args_109;args_109.kw("condition",attr(self_value(),"flying"));return invoke(fn_110,args_109);}());
        }
    }
    }
return V{};
}),false);
// Official method Xigelika.is_forte_full, lines 78-84
register_method("is_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_114=bind_arguments(official_args,signature,captured);
scope_114->set("box",V::missing());
scope_114->set("white_percent",V::missing());
    // Xigelika.py:79
    {V value_115=([&]()->V{auto fn_117=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_116;args_116.pos(V(5120LL));args_116.pos(V(2880LL));args_116.pos(V(3032LL));args_116.pos(V(2654LL));args_116.pos(V(3076LL));args_116.pos(V(2700LL));args_116.kw("name",V("forte_full"));args_116.kw("hcenter",V(true));return invoke(fn_117,args_116);}());scope_114->set("box",value_115);}
    // Xigelika.py:80
    {V value_118=([&]()->V{auto fn_120=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_119;args_119.pos(global("forte_white_color","Xigelika"));args_119.pos(scope_114->get("box"));return invoke(fn_120,args_119);}());scope_114->set("white_percent",value_118);}
    // Xigelika.py:81
    {V value_121=scope_114->get("white_percent");set_attr(scope_114->get("box"),"confidence",value_121);}
    // Xigelika.py:82
    ([&]()->V{auto fn_123=attr(attr(self_value(),"logger"),"debug");Args args_122;args_122.pos(V(std::string{}+"sigrika find forte "+format_value(scope_114->get("white_percent"),"",-1)));return invoke(fn_123,args_122);}());
    // Xigelika.py:83
    ([&]()->V{auto fn_125=attr(attr(self_value(),"task"),"draw_boxes");Args args_124;args_124.pos(V("forte_full"));args_124.pos(scope_114->get("box"));return invoke(fn_125,args_124);}());
    // Xigelika.py:84
    return ([&]()->V{V compare_126=scope_114->get("white_percent");V compare_127;V comparison_result_128;compare_127=V(0.1);comparison_result_128=compare_value(">",compare_126,compare_127);return comparison_result_128;}());
return V{};
}),false);
}
