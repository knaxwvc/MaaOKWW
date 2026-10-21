// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Denia.py
// SHA256 7ffa85c1e2a83398bb9b2f532618e301c594421892e6cdc0fc2bd1e95fbe75cc
void OfficialCharacter::install_Denia(){
auto scope=std::make_shared<Scope>();
// Official method Denia.__init__, lines 9-12
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Denia.py:10
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Denia");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Denia.py:11
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"lib_2",value_6);}
    // Denia.py:12
    {V value_7=V(false);set_attr(self_value(),"lib_1_casted",value_7);}
return V{};
}),false);
// Official method Denia.reset_state, lines 14-17
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_8=bind_arguments(official_args,signature,captured);
    // Denia.py:15
    ([&]()->V{auto fn_12=attr(([&]()->V{auto fn_10=global("super","Denia");Args args_9;return invoke(fn_10,args_9);}()),"reset_state");Args args_11;return invoke(fn_12,args_11);}());
    // Denia.py:16
    {V value_13=unary("-",V(1LL));set_attr(self_value(),"lib_2",value_13);}
    // Denia.py:17
    {V value_14=V(false);set_attr(self_value(),"lib_1_casted",value_14);}
return V{};
}),false);
// Official method Denia.do_perform, lines 19-58
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_15=bind_arguments(official_args,signature,captured);
scope_15->set("duration",V::missing());
scope_15->set("is_lib2",V::missing());
scope_15->set("start",V::missing());
    // Denia.py:20
    if(attr(self_value(),"has_intro").truth()){
        // Denia.py:21
        ([&]()->V{auto fn_17=attr(self_value(),"continues_normal_attack");Args args_16;args_16.pos(V(2LL));return invoke(fn_17,args_16);}());
    }else{
        // Denia.py:22
        if(attr(self_value(),"lib_1_casted").truth()){
            // Denia.py:23
            ([&]()->V{auto fn_19=attr(self_value(),"continues_normal_attack");Args args_18;args_18.pos(V(1.3));return invoke(fn_19,args_18);}());
        }
    }
    // Denia.py:24
    {V value_20=V(1.2);scope_15->set("duration",value_20);}
    // Denia.py:25
    if(attr(self_value(),"lib_1_casted").truth()){
        // Denia.py:26
        {V value_21=V(4.4);scope_15->set("duration",value_21);}
    }
    // Denia.py:27
    {V value_22=([&]()->V{auto fn_24=attr(global("time","Denia"),"time");Args args_23;return invoke(fn_24,args_23);}());scope_15->set("start",value_22);}
    // Denia.py:28
        while(([&]()->V{V compare_63=([&]()->V{auto fn_66=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_65;args_65.pos(scope_15->get("start"));return invoke(fn_66,args_65);}());V compare_64;V comparison_result_67;compare_64=scope_15->get("duration");comparison_result_67=compare_value("<",compare_63,compare_64);return comparison_result_67;}()).truth()){
        // Denia.py:29
        ([&]()->V{auto fn_26=attr(self_value(),"cycle_start");Args args_25;return invoke(fn_26,args_25);}());
        // Denia.py:30
        if(([&]()->V{V operand_27;operand_27=([&]()->V{V compare_28=([&]()->V{auto fn_31=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_30;args_30.pos(attr(self_value(),"lib_2"));return invoke(fn_31,args_30);}());V compare_29;V comparison_result_32;compare_29=V(10LL);comparison_result_32=compare_value("<",compare_28,compare_29);return comparison_result_32;}());if(!operand_27.truth())return operand_27;return ([&]()->V{auto fn_34=attr(self_value(),"is_con_full");Args args_33;return invoke(fn_34,args_33);}());}()).truth()){
            // Denia.py:31
            return ([&]()->V{auto fn_36=attr(self_value(),"switch_next_char");Args args_35;return invoke(fn_36,args_35);}());
        }
        // Denia.py:32
        if(item(([&]()->V{auto fn_38=attr(self_value(),"click_resonance");Args args_37;return invoke(fn_38,args_37);}()),V(0LL)).truth()){
        }else{
            // Denia.py:34
            if(([&]()->V{auto fn_40=attr(self_value(),"liberation_available");Args args_39;return invoke(fn_40,args_39);}()).truth()){
                // Denia.py:35
                {V value_41=([&]()->V{auto fn_43=attr(attr(self_value(),"task"),"find_one");Args args_42;args_42.pos(attr(global("Labels","Denia"),"denia_end_lib"));return invoke(fn_43,args_42);}());scope_15->set("is_lib2",value_41);}
                // Denia.py:36
                if(([&]()->V{auto fn_45=attr(self_value(),"click_liberation");Args args_44;args_44.kw("wait_if_cd_ready",V(0LL));return invoke(fn_45,args_44);}()).truth()){
                    // Denia.py:37
                    if(scope_15->get("is_lib2").truth()){
                        // Denia.py:38
                        {V value_46=([&]()->V{auto fn_48=attr(global("time","Denia"),"time");Args args_47;return invoke(fn_48,args_47);}());set_attr(self_value(),"lib_2",value_46);}
                        // Denia.py:39
                        {V value_49=V(false);set_attr(self_value(),"lib_1_casted",value_49);}
                        // Denia.py:40
                        ([&]()->V{auto fn_51=attr(self_value(),"click_echo");Args args_50;args_50.kw("time_out",V(0LL));return invoke(fn_51,args_50);}());
                        // Denia.py:41
                        return ([&]()->V{auto fn_53=attr(self_value(),"switch_next_char");Args args_52;return invoke(fn_53,args_52);}());
                    }else{
                        // Denia.py:43
                        {V value_54=V(true);set_attr(self_value(),"lib_1_casted",value_54);}
                        // Denia.py:51
                        ([&]()->V{auto fn_56=attr(self_value(),"continues_normal_attack");Args args_55;args_55.pos(V(1.9));return invoke(fn_56,args_55);}());
                        // Denia.py:52
                        return ([&]()->V{auto fn_58=attr(self_value(),"switch_next_char");Args args_57;return invoke(fn_58,args_57);}());
                    }
                }
            }else{
                // Denia.py:55
                ([&]()->V{auto fn_60=attr(self_value(),"click");Args args_59;return invoke(fn_60,args_59);}());
            }
        }
        // Denia.py:56
        ([&]()->V{auto fn_62=attr(self_value(),"cycle_sleep");Args args_61;return invoke(fn_62,args_61);}());
    }
    // Denia.py:58
    ([&]()->V{auto fn_69=attr(self_value(),"switch_next_char");Args args_68;return invoke(fn_69,args_68);}());
return V{};
}),false);
// Official method Denia.get_switch_priority, lines 65-76
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_70=bind_arguments(official_args,signature,captured);
scope_70->set("Aemeath",V::missing());
scope_70->set("Qingxiao",V::missing());
    // Denia.py:66
    if(scope_70->get("has_intro").truth()){
        // Denia.py:67
        scope_70->set("Aemeath",import_value("src.char.Aemeath","Aemeath"));
        // Denia.py:68
        scope_70->set("Qingxiao",import_value("src.char.Qingxiao","Qingxiao"));
        // Denia.py:70
        if(([&]()->V{V operand_71;operand_71=([&]()->V{auto fn_73=global("isinstance","Denia");Args args_72;args_72.pos(scope_70->get("current_char"));args_72.pos(V::tuple({scope_70->get("Aemeath"),scope_70->get("Qingxiao")}));return invoke(fn_73,args_72);}());if(!operand_71.truth())return operand_71;return unary("not",([&]()->V{auto fn_75=attr(self_value(),"has_buff");Args args_74;return invoke(fn_75,args_74);}()));}()).truth()){
            // Denia.py:71
            return attr(global("SwitchPriority","Denia"),"NORMAL");
        }
        // Denia.py:72
        return ([&]()->V{V left_76=attr(global("SwitchPriority","Denia"),"NO");V right_77=V(1LL);return official::binary("+",left_76,right_77);}());
    }else{
        // Denia.py:73
        if(([&]()->V{auto fn_79=attr(self_value(),"has_buff");Args args_78;return invoke(fn_79,args_78);}()).truth()){
            // Denia.py:74
            return attr(global("SwitchPriority","Denia"),"LOW");
        }else{
            // Denia.py:76
            return ([&]()->V{auto fn_83=attr(([&]()->V{auto fn_81=global("super","Denia");Args args_80;return invoke(fn_81,args_80);}()),"get_switch_priority");Args args_82;args_82.pos(scope_70->get("current_char"));args_82.pos(scope_70->get("has_intro"));args_82.pos(scope_70->get("target_low_con"));return invoke(fn_83,args_82);}());
        }
    }
return V{};
}),false);
}
