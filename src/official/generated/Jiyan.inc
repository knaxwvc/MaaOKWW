// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Jiyan.py
// SHA256 93f4da1f1ac31b6178adf2ee5d36ae8737fed401e19d63853dcc0f8ab5ea0734
void OfficialCharacter::install_Jiyan(){
auto scope=std::make_shared<Scope>();
// Official method Jiyan.do_perform, lines 6-33
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("i",V::missing());
scope_1->set("start",V::missing());
    // Jiyan.py:7
    if(attr(self_value(),"has_intro").truth()){
        // Jiyan.py:8
        ([&]()->V{auto fn_3=attr(attr(self_value(),"logger"),"debug");Args args_2;args_2.pos(V("jiyan wait intro"));return invoke(fn_3,args_2);}());
        // Jiyan.py:9
        ([&]()->V{auto fn_5=attr(self_value(),"continues_normal_attack");Args args_4;args_4.kw("duration",V(2.0));return invoke(fn_5,args_4);}());
    }
    // Jiyan.py:11
    if(([&]()->V{auto fn_7=attr(self_value(),"click_liberation");Args args_6;return invoke(fn_7,args_6);}()).truth()){
        // Jiyan.py:12
        {V value_8=([&]()->V{auto fn_10=attr(global("time","Jiyan"),"time");Args args_9;return invoke(fn_10,args_9);}());scope_1->set("start",value_8);}
        // Jiyan.py:13
                while(([&]()->V{V compare_17=([&]()->V{V left_19=([&]()->V{auto fn_22=attr(global("time","Jiyan"),"time");Args args_21;return invoke(fn_22,args_21);}());V right_20=scope_1->get("start");return official::binary("-",left_19,right_20);}());V compare_18;V comparison_result_23;compare_18=V(12LL);comparison_result_23=compare_value("<",compare_17,compare_18);return comparison_result_23;}()).truth()){
            // Jiyan.py:14
            if(item(([&]()->V{auto fn_12=attr(self_value(),"click_resonance");Args args_11;return invoke(fn_12,args_11);}()),V(0LL)).truth()){
                // Jiyan.py:15
                ([&]()->V{auto fn_14=attr(attr(self_value(),"task"),"middle_click_relative");Args args_13;args_13.pos(V(0.5));args_13.pos(V(0.5));return invoke(fn_14,args_13);}());
            }
            // Jiyan.py:17
            ([&]()->V{auto fn_16=attr(self_value(),"normal_attack");Args args_15;return invoke(fn_16,args_15);}());
        }
        // Jiyan.py:18
        return ([&]()->V{auto fn_25=attr(self_value(),"switch_next_char");Args args_24;return invoke(fn_25,args_24);}());
    }
    // Jiyan.py:19
    {V value_26=V(0LL);scope_1->set("i",value_26);}
    // Jiyan.py:20
        while(([&]()->V{V operand_44;operand_44=unary("not",([&]()->V{auto fn_46=attr(self_value(),"is_forte_full");Args args_45;return invoke(fn_46,args_45);}()));if(!operand_44.truth())return operand_44;return unary("not",([&]()->V{auto fn_48=attr(self_value(),"is_con_full");Args args_47;return invoke(fn_48,args_47);}()));}()).truth()){
        // Jiyan.py:21
        if(([&]()->V{V compare_27=([&]()->V{V left_29=scope_1->get("i");V right_30=V(4LL);return official::binary("%",left_29,right_30);}());V compare_28;V comparison_result_31;compare_28=V(0LL);comparison_result_31=compare_value("==",compare_27,compare_28);return comparison_result_31;}()).truth()){
            // Jiyan.py:22
            ([&]()->V{auto fn_33=attr(self_value(),"heavy_attack");Args args_32;return invoke(fn_33,args_32);}());
            // Jiyan.py:23
            if(([&]()->V{V operand_34;operand_34=([&]()->V{auto fn_36=attr(self_value(),"resonance_available");Args args_35;return invoke(fn_36,args_35);}());if(operand_34.truth())return operand_34;return ([&]()->V{auto fn_38=attr(self_value(),"echo_available");Args args_37;return invoke(fn_38,args_37);}());}()).truth()){
                // Jiyan.py:24
                ([&]()->V{auto fn_40=attr(attr(self_value(),"task"),"middle_click_relative");Args args_39;args_39.pos(V(0.5));args_39.pos(V(0.5));return invoke(fn_40,args_39);}());
                // Jiyan.py:25
                break;
            }
            // Jiyan.py:26
            {V value_41=V(0LL);scope_1->set("i",value_41);}
        }
        // Jiyan.py:27
        ([&]()->V{auto fn_43=attr(self_value(),"normal_attack");Args args_42;return invoke(fn_43,args_42);}());
        // Jiyan.py:28
        scope_1->set("i",official::binary("+",scope_1->get("i"),V(1LL)));
    }
    // Jiyan.py:29
    if(([&]()->V{V operand_49;operand_49=unary("not",([&]()->V{auto fn_51=attr(self_value(),"is_forte_full");Args args_50;return invoke(fn_51,args_50);}()));if(!operand_49.truth())return operand_49;return ([&]()->V{auto fn_53=attr(self_value(),"resonance_available");Args args_52;return invoke(fn_53,args_52);}());}()).truth()){
        // Jiyan.py:30
        ([&]()->V{auto fn_55=attr(self_value(),"click_resonance");Args args_54;args_54.kw("post_sleep",V(1.0));return invoke(fn_55,args_54);}());
    }
    // Jiyan.py:31
    if(([&]()->V{auto fn_57=attr(self_value(),"echo_available");Args args_56;return invoke(fn_57,args_56);}()).truth()){
        // Jiyan.py:32
        ([&]()->V{auto fn_59=attr(self_value(),"click_echo");Args args_58;return invoke(fn_59,args_58);}());
    }
    // Jiyan.py:33
    ([&]()->V{auto fn_61=attr(self_value(),"switch_next_char");Args args_60;return invoke(fn_61,args_60);}());
return V{};
}),false);
}
