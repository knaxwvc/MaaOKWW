// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Roccia.py
// SHA256 f6f8aec3a56a7401bcfee3a64bc474615b48d03b24ebfc0213952058f52629a8
void OfficialCharacter::install_Roccia(){
auto scope=std::make_shared<Scope>();
// Official method Roccia.__init__, lines 8-13
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Roccia.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Roccia");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Roccia.py:10
    {V value_6=V(0LL);set_attr(self_value(),"plunge_count",value_6);}
    // Roccia.py:11
    {V value_7=V(0LL);set_attr(self_value(),"last_e",value_7);}
    // Roccia.py:12
    {V value_8=V(0LL);set_attr(self_value(),"last_intro",value_8);}
    // Roccia.py:13
    {V value_9=V(false);set_attr(self_value(),"can_plunge",value_9);}
return V{};
}),false);
// Official method Roccia.do_perform, lines 15-28
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_10=bind_arguments(official_args,signature,captured);
scope_10->set("liberated",V::missing());
    // Roccia.py:16
    if(attr(self_value(),"has_intro").truth()){
        // Roccia.py:17
        ([&]()->V{auto fn_12=attr(self_value(),"heavy_attack");Args args_11;args_11.pos(V(1.6));return invoke(fn_12,args_11);}());
        // Roccia.py:18
        ([&]()->V{auto fn_14=attr(self_value(),"sleep");Args args_13;args_13.pos(V(0.1));return invoke(fn_14,args_13);}());
        // Roccia.py:19
        {V value_15=([&]()->V{auto fn_17=attr(global("time","Roccia"),"time");Args args_16;return invoke(fn_17,args_16);}());set_attr(self_value(),"last_intro",value_15);}
        // Roccia.py:20
        ([&]()->V{auto fn_19=attr(self_value(),"plunge");Args args_18;return invoke(fn_19,args_18);}());
        // Roccia.py:21
        if(([&]()->V{V operand_20;operand_20=unary("not",([&]()->V{auto fn_22=attr(self_value(),"liberation_available");Args args_21;return invoke(fn_22,args_21);}()));if(!operand_20.truth())return operand_20;return unary("not",([&]()->V{auto fn_24=attr(self_value(),"resonance_available");Args args_23;return invoke(fn_24,args_23);}()));}()).truth()){
            // Roccia.py:22
            return ([&]()->V{auto fn_26=attr(self_value(),"switch_next_char");Args args_25;return invoke(fn_26,args_25);}());
        }
    }
    // Roccia.py:23
    {V value_27=([&]()->V{auto fn_29=attr(self_value(),"click_liberation");Args args_28;return invoke(fn_29,args_28);}());scope_10->set("liberated",value_27);}
    // Roccia.py:24
    if(([&]()->V{V operand_30;operand_30=item(([&]()->V{auto fn_32=attr(self_value(),"click_resonance");Args args_31;return invoke(fn_32,args_31);}()),V(0LL));if(operand_30.truth())return operand_30;return unary("not",scope_10->get("liberated"));}()).truth()){
        // Roccia.py:25
        ([&]()->V{auto fn_34=attr(self_value(),"plunge");Args args_33;return invoke(fn_34,args_33);}());
        // Roccia.py:26
        return ([&]()->V{auto fn_36=attr(self_value(),"switch_next_char");Args args_35;return invoke(fn_36,args_35);}());
    }
    // Roccia.py:27
    ([&]()->V{auto fn_38=attr(self_value(),"click_echo");Args args_37;return invoke(fn_38,args_37);}());
    // Roccia.py:28
    return ([&]()->V{auto fn_40=attr(self_value(),"switch_next_char");Args args_39;return invoke(fn_40,args_39);}());
return V{};
}),false);
// Official method Roccia.switch_next_char, lines 30-32
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"post_action",V{}},{"free_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_41=bind_arguments(official_args,signature,captured);
    // Roccia.py:31
    ([&]()->V{auto fn_45=attr(([&]()->V{auto fn_43=global("super","Roccia");Args args_42;return invoke(fn_43,args_42);}()),"switch_next_char");Args args_44;args_44.kw("post_action",attr(self_value(),"update_tool_box"));args_44.kw("free_intro",scope_41->get("free_intro"));args_44.kw("target_low_con",scope_41->get("target_low_con"));return invoke(fn_45,args_44);}());
return V{};
}),false);
// Official method Roccia.update_tool_box, lines 34-36
register_method("update_tool_box",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"next_char",V::missing()},{"has_intro",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_46=bind_arguments(official_args,signature,captured);
    // Roccia.py:35
    if(scope_46->get("has_intro").truth()){
        // Roccia.py:36
        {V value_47=V(true);set_attr(scope_46->get("next_char"),"has_tool_box",value_47);}
    }
return V{};
}),false);
// Official method Roccia.plunge, lines 38-52
register_method("plunge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_48=bind_arguments(official_args,signature,captured);
scope_48->set("start",V::missing());
    // Roccia.py:39
    if(([&]()->V{auto fn_50=attr(self_value(),"need_fast_perform");Args args_49;return invoke(fn_50,args_49);}()).truth()){
        // Roccia.py:40
        ([&]()->V{auto fn_52=attr(self_value(),"normal_attack_until_can_switch");Args args_51;return invoke(fn_52,args_51);}());
        // Roccia.py:41
        return V{};
    }
    // Roccia.py:42
    {V value_53=([&]()->V{auto fn_55=attr(global("time","Roccia"),"time");Args args_54;return invoke(fn_55,args_54);}());scope_48->set("start",value_53);}
    // Roccia.py:43
    ([&]()->V{auto fn_57=attr(attr(self_value(),"task"),"send_key_down");Args args_56;args_56.pos(V("w"));return invoke(fn_57,args_56);}());
    // Roccia.py:44
        while(([&]()->V{V operand_79;operand_79=([&]()->V{auto fn_81=attr(self_value(),"is_mouse_forte_full");Args args_80;return invoke(fn_81,args_80);}());if(!operand_79.truth())return operand_79;return ([&]()->V{V compare_82=([&]()->V{V left_84=([&]()->V{auto fn_87=attr(global("time","Roccia"),"time");Args args_86;return invoke(fn_87,args_86);}());V right_85=scope_48->get("start");return official::binary("-",left_84,right_85);}());V compare_83;V comparison_result_88;compare_83=V(6LL);comparison_result_88=compare_value("<",compare_82,compare_83);return comparison_result_88;}());}()).truth()){
        // Roccia.py:45
        if(([&]()->V{V operand_58;operand_58=([&]()->V{V compare_59=([&]()->V{V left_61=([&]()->V{auto fn_64=attr(global("time","Roccia"),"time");Args args_63;return invoke(fn_64,args_63);}());V right_62=scope_48->get("start");return official::binary("-",left_61,right_62);}());V compare_60;V comparison_result_65;compare_60=V(2LL);comparison_result_65=compare_value(">",compare_59,compare_60);return comparison_result_65;}());if(!operand_58.truth())return operand_58;operand_58=unary("not",([&]()->V{auto fn_67=attr(self_value(),"has_cd");Args args_66;args_66.pos(V("resonance"));return invoke(fn_67,args_66);}()));if(!operand_58.truth())return operand_58;return unary("not",([&]()->V{auto fn_69=attr(self_value(),"has_cd");Args args_68;args_68.pos(V("liberation"));return invoke(fn_69,args_68);}()));}()).truth()){
            // Roccia.py:46
            if(([&]()->V{auto fn_71=attr(self_value(),"click_liberation");Args args_70;return invoke(fn_71,args_70);}()).truth()){
                // Roccia.py:47
                ([&]()->V{auto fn_73=attr(self_value(),"click_resonance");Args args_72;return invoke(fn_73,args_72);}());
                // Roccia.py:48
                {V value_74=([&]()->V{auto fn_76=attr(global("time","Roccia"),"time");Args args_75;return invoke(fn_76,args_75);}());scope_48->set("start",value_74);}
                // Roccia.py:49
                continue;
            }
        }
        // Roccia.py:50
        ([&]()->V{auto fn_78=attr(self_value(),"click");Args args_77;args_77.kw("interval",V(0.1));return invoke(fn_78,args_77);}());
    }
    // Roccia.py:51
    ([&]()->V{auto fn_90=attr(attr(self_value(),"task"),"send_key_up");Args args_89;args_89.pos(V("w"));return invoke(fn_90,args_89);}());
    // Roccia.py:52
    return V(true);
return V{};
}),false);
}
