// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/YangYangSp.py
// SHA256 89b56bea591452baaa1e0111cf34e00f793495a26f43d26c15d6a9b55963704f
void OfficialCharacter::install_YangYangSp(){
auto scope=std::make_shared<Scope>();
set_class_attribute("INTRO_PERFORM_DURATION",V(8.0));
set_class_attribute("PERFORM_DURATION",V(3.2));
set_class_attribute("LONG_PRESS_RELEASE_DELAY",V(0.1));
set_class_attribute("DISPLAY_NAME",V("Yangyang: Xuanling"));
// Official method YangYangSp.__init__, lines 13-15
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // YangYangSp.py:14
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","YangYangSp");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // YangYangSp.py:15
    {V value_6=([&]()->V{auto fn_8=attr(global("Logger","YangYangSp"),"get_logger");Args args_7;args_7.pos(attr(self_value(),"DISPLAY_NAME"));return invoke(fn_8,args_7);}());set_attr(self_value(),"logger",value_6);}
return V{};
}),false);
// Official method YangYangSp.display_name, lines 18-19
register_method("@get:display_name",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_9=bind_arguments(official_args,signature,captured);
    // YangYangSp.py:19
    return attr(self_value(),"DISPLAY_NAME");
return V{};
}),false);
// Official method YangYangSp.__repr__, lines 21-22
register_method("__repr__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_10=bind_arguments(official_args,signature,captured);
    // YangYangSp.py:22
    return attr(self_value(),"DISPLAY_NAME");
return V{};
}),false);
// Official method YangYangSp.do_perform, lines 24-56
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_11=bind_arguments(official_args,signature,captured);
scope_11->set("duration",V::missing());
scope_11->set("echo_used",V::missing());
scope_11->set("resonance_available",V::missing());
scope_11->set("start",V::missing());
    // YangYangSp.py:25
    {V value_12=(attr(self_value(),"has_intro").truth()?attr(self_value(),"INTRO_PERFORM_DURATION"):attr(self_value(),"PERFORM_DURATION"));scope_11->set("duration",value_12);}
    // YangYangSp.py:26
    {V value_13=([&]()->V{auto fn_15=attr(global("time","YangYangSp"),"time");Args args_14;return invoke(fn_15,args_14);}());scope_11->set("start",value_13);}
    // YangYangSp.py:27
    ([&]()->V{auto fn_17=attr(attr(self_value(),"task"),"mouse_down");Args args_16;return invoke(fn_17,args_16);}());
    // YangYangSp.py:28
    {V value_18=V(0LL);scope_11->set("resonance_available",value_18);}
    // YangYangSp.py:29
    {V value_19=V(false);scope_11->set("echo_used",value_19);}
    // YangYangSp.py:30
    {
    auto finally_20=on_scope_exit([&](){
        // YangYangSp.py:52
        ([&]()->V{auto fn_22=attr(attr(self_value(),"task"),"mouse_up");Args args_21;return invoke(fn_22,args_21);}());
        // YangYangSp.py:55
        ([&]()->V{auto fn_24=attr(self_value(),"sleep");Args args_23;args_23.pos(attr(self_value(),"LONG_PRESS_RELEASE_DELAY"));args_23.kw("check_combat",V(false));return invoke(fn_24,args_23);}());
    });
        // YangYangSp.py:31
                while(([&]()->V{V compare_63=([&]()->V{auto fn_66=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_65;args_65.pos(scope_11->get("start"));return invoke(fn_66,args_65);}());V compare_64;V comparison_result_67;compare_64=scope_11->get("duration");comparison_result_67=compare_value("<",compare_63,compare_64);return comparison_result_67;}()).truth()){
            // YangYangSp.py:32
            if(([&]()->V{auto fn_26=attr(self_value(),"liberation_available");Args args_25;return invoke(fn_26,args_25);}()).truth()){
                // YangYangSp.py:33
                ([&]()->V{auto fn_28=attr(attr(self_value(),"logger"),"debug");Args args_27;args_27.pos(V("liberation_available"));return invoke(fn_28,args_27);}());
                // YangYangSp.py:34
                if(unary("not",([&]()->V{auto fn_30=attr(self_value(),"click_liberation");Args args_29;args_29.kw("send_click",V(false));args_29.kw("wait_if_cd_ready",V(0LL));return invoke(fn_30,args_29);}())).truth()){
                }else{
                    // YangYangSp.py:37
                    scope_11->set("duration",official::binary("+",scope_11->get("duration"),V(2LL)));
                }
            }else{
                // YangYangSp.py:38
                if(([&]()->V{auto fn_32=attr(self_value(),"resonance_available");Args args_31;return invoke(fn_32,args_31);}()).truth()){
                    // YangYangSp.py:39
                    ([&]()->V{auto fn_34=attr(attr(self_value(),"logger"),"debug");Args args_33;args_33.pos(V("resonance_available"));return invoke(fn_34,args_33);}());
                    // YangYangSp.py:40
                    if(([&]()->V{V compare_35=scope_11->get("resonance_available");V compare_36;V comparison_result_37;compare_36=V(0LL);comparison_result_37=compare_value("==",compare_35,compare_36);return comparison_result_37;}()).truth()){
                        // YangYangSp.py:41
                        {V value_38=([&]()->V{auto fn_40=attr(global("time","YangYangSp"),"time");Args args_39;return invoke(fn_40,args_39);}());scope_11->set("resonance_available",value_38);}
                    }
                    // YangYangSp.py:42
                    if(([&]()->V{V operand_41;operand_41=([&]()->V{V compare_42=scope_11->get("resonance_available");V compare_43;V comparison_result_44;compare_43=V(0LL);comparison_result_44=compare_value("!=",compare_42,compare_43);return comparison_result_44;}());if(!operand_41.truth())return operand_41;return ([&]()->V{V compare_45=([&]()->V{V left_47=([&]()->V{auto fn_50=attr(global("time","YangYangSp"),"time");Args args_49;return invoke(fn_50,args_49);}());V right_48=scope_11->get("resonance_available");return official::binary("-",left_47,right_48);}());V compare_46;V comparison_result_51;compare_46=V(0.2);comparison_result_51=compare_value(">",compare_45,compare_46);return comparison_result_51;}());}()).truth()){
                        // YangYangSp.py:43
                        ([&]()->V{auto fn_53=attr(attr(self_value(),"logger"),"debug");Args args_52;args_52.pos(V("resonance available for 0.2"));return invoke(fn_53,args_52);}());
                        // YangYangSp.py:44
                        ([&]()->V{auto fn_55=attr(self_value(),"click_resonance");Args args_54;args_54.kw("send_click",V(false));args_54.kw("time_out",V(1LL));return invoke(fn_55,args_54);}());
                    }
                }else{
                    // YangYangSp.py:45
                    if(unary("not",scope_11->get("echo_used")).truth()){
                        // YangYangSp.py:46
                        {V value_56=V(0LL);scope_11->set("resonance_available",value_56);}
                        // YangYangSp.py:47
                        {V value_57=([&]()->V{auto fn_59=attr(self_value(),"click_echo");Args args_58;args_58.kw("time_out",V(0LL));return invoke(fn_59,args_58);}());scope_11->set("echo_used",value_57);}
                    }else{
                        // YangYangSp.py:49
                        {V value_60=V(0LL);scope_11->set("resonance_available",value_60);}
                    }
                }
            }
            // YangYangSp.py:50
            ([&]()->V{auto fn_62=attr(self_value(),"sleep");Args args_61;args_61.pos(V(0.05));return invoke(fn_62,args_61);}());
        }
    }
    // YangYangSp.py:56
    ([&]()->V{auto fn_69=attr(self_value(),"switch_next_char");Args args_68;return invoke(fn_69,args_68);}());
return V{};
}),false);
}
