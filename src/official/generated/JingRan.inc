// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/JingRan.py
// SHA256 77b302f66fa4c2d8f56c8a9895a44766d508d29518bdc78b345be56f1ffc4189
void OfficialCharacter::install_JingRan(){
auto scope=std::make_shared<Scope>();
set_class_attribute("BUILD_TIMEOUT",V(8LL));
set_class_attribute("YINGHUO_DURATION",V(15LL));
// Official method JingRan.do_perform, lines 10-37
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("liberation_start",V::missing());
scope_1->set("start",V::missing());
    // JingRan.py:12
    ([&]()->V{auto fn_3=attr(self_value(),"wait_intro");Args args_2;return invoke(fn_3,args_2);}());
    // JingRan.py:13
    ([&]()->V{auto fn_5=attr(self_value(),"click_echo");Args args_4;args_4.kw("time_out",V(0LL));return invoke(fn_5,args_4);}());
    // JingRan.py:15
    {V value_6=([&]()->V{auto fn_8=attr(global("time","JingRan"),"time");Args args_7;return invoke(fn_8,args_7);}());scope_1->set("start",value_6);}
    // JingRan.py:16
    {V value_9=V{};scope_1->set("liberation_start",value_9);}
    // JingRan.py:17
        while(([&]()->V{V compare_46=([&]()->V{auto fn_49=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_48;args_48.pos(scope_1->get("start"));return invoke(fn_49,args_48);}());V compare_47;V comparison_result_50;compare_47=([&]()->V{V left_51=attr(self_value(),"BUILD_TIMEOUT");V right_52=attr(self_value(),"YINGHUO_DURATION");return official::binary("+",left_51,right_52);}());comparison_result_50=compare_value("<",compare_46,compare_47);return comparison_result_50;}()).truth()){
        // JingRan.py:18
        if(([&]()->V{V compare_10=scope_1->get("liberation_start");V compare_11;V comparison_result_12;compare_11=V{};comparison_result_12=compare_value("is",compare_10,compare_11);return comparison_result_12;}()).truth()){
            // JingRan.py:19
            if(([&]()->V{V compare_13=([&]()->V{auto fn_16=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_15;args_15.pos(scope_1->get("start"));return invoke(fn_16,args_15);}());V compare_14;V comparison_result_17;compare_14=attr(self_value(),"BUILD_TIMEOUT");comparison_result_17=compare_value(">=",compare_13,compare_14);return comparison_result_17;}()).truth()){
                // JingRan.py:20
                break;
            }
        }else{
            // JingRan.py:21
            if(([&]()->V{V compare_18=([&]()->V{auto fn_21=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_20;args_20.pos(scope_1->get("liberation_start"));return invoke(fn_21,args_20);}());V compare_19;V comparison_result_22;compare_19=attr(self_value(),"YINGHUO_DURATION");comparison_result_22=compare_value(">=",compare_18,compare_19);return comparison_result_22;}()).truth()){
                // JingRan.py:22
                break;
            }
        }
        // JingRan.py:24
        ([&]()->V{auto fn_24=attr(self_value(),"cycle_start");Args args_23;return invoke(fn_24,args_23);}());
        // JingRan.py:26
        if(([&]()->V{auto fn_26=attr(self_value(),"is_forte_full");Args args_25;return invoke(fn_26,args_25);}()).truth()){
            // JingRan.py:27
            ([&]()->V{auto fn_28=attr(self_value(),"heavy_click_forte");Args args_27;return invoke(fn_28,args_27);}());
        }else{
            // JingRan.py:28
            if(([&]()->V{V operand_29;operand_29=([&]()->V{V compare_30=scope_1->get("liberation_start");V compare_31;V comparison_result_32;compare_31=V{};comparison_result_32=compare_value("is",compare_30,compare_31);return comparison_result_32;}());if(!operand_29.truth())return operand_29;return ([&]()->V{auto fn_34=attr(self_value(),"click_liberation");Args args_33;args_33.kw("wait_if_cd_ready",V(0LL));return invoke(fn_34,args_33);}());}()).truth()){
                // JingRan.py:29
                {V value_35=([&]()->V{auto fn_37=attr(global("time","JingRan"),"time");Args args_36;return invoke(fn_37,args_36);}());scope_1->set("liberation_start",value_35);}
            }else{
                // JingRan.py:30
                if(item(([&]()->V{auto fn_39=attr(self_value(),"click_resonance");Args args_38;args_38.kw("send_click",V(false));args_38.kw("time_out",V(1LL));return invoke(fn_39,args_38);}()),V(0LL)).truth()){
                    // JingRan.py:32
                    ([&]()->V{auto fn_41=attr(self_value(),"continues_normal_attack");Args args_40;args_40.pos(V(0.8));return invoke(fn_41,args_40);}());
                }else{
                    // JingRan.py:34
                    ([&]()->V{auto fn_43=attr(self_value(),"click");Args args_42;args_42.kw("interval",V(0.1));return invoke(fn_43,args_42);}());
                }
            }
        }
        // JingRan.py:35
        ([&]()->V{auto fn_45=attr(self_value(),"cycle_sleep");Args args_44;return invoke(fn_45,args_44);}());
    }
    // JingRan.py:37
    ([&]()->V{auto fn_54=attr(self_value(),"switch_next_char");Args args_53;return invoke(fn_54,args_53);}());
return V{};
}),false);
}
