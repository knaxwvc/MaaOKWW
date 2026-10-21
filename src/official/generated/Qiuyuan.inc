// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Qiuyuan.py
// SHA256 05d88f2baac7d3e6492697f6297d171547d755b63f5d3b877a9e3fb68995a6e0
void OfficialCharacter::install_Qiuyuan(){
auto scope=std::make_shared<Scope>();
// Official method Qiuyuan.do_perform, lines 7-28
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("start",V::missing());
scope_1->set("timeout",V::missing());
    // Qiuyuan.py:8
    if(attr(self_value(),"has_intro").truth()){
        // Qiuyuan.py:9
        ([&]()->V{auto fn_3=attr(self_value(),"continues_normal_attack");Args args_2;args_2.pos(V(1.17));return invoke(fn_3,args_2);}());
    }
    // Qiuyuan.py:10
    if(([&]()->V{auto fn_5=attr(self_value(),"flying");Args args_4;return invoke(fn_5,args_4);}()).truth()){
        // Qiuyuan.py:11
        ([&]()->V{auto fn_7=attr(self_value(),"wait_down");Args args_6;return invoke(fn_7,args_6);}());
    }
    // Qiuyuan.py:12
    {V value_8=([&]()->V{auto fn_10=attr(global("time","Qiuyuan"),"time");Args args_9;return invoke(fn_10,args_9);}());scope_1->set("start",value_8);}
    // Qiuyuan.py:13
    {V value_11=V::function([this,captured=capture_scope(scope_1,{"start"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_13=([&]()->V{V left_15=([&]()->V{auto fn_18=attr(global("time","Qiuyuan"),"time");Args args_17;return invoke(fn_18,args_17);}());V right_16=scope_12->get("start");return official::binary("-",left_15,right_16);}());V compare_14;V comparison_result_19;compare_14=V(1.2);comparison_result_19=compare_value("<",compare_13,compare_14);return comparison_result_19;}());
});scope_1->set("timeout",value_11);}
    // Qiuyuan.py:14
    if(attr(self_value(),"has_sub_dps_intro").truth()){
        // Qiuyuan.py:15
        {V value_20=V::function([this,captured=capture_scope(scope_1,{"start"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_21=bind_arguments(official_args,signature,captured);
return ([&]()->V{V compare_22=([&]()->V{V left_24=([&]()->V{auto fn_27=attr(global("time","Qiuyuan"),"time");Args args_26;return invoke(fn_27,args_26);}());V right_25=scope_21->get("start");return official::binary("-",left_24,right_25);}());V compare_23;V comparison_result_28;compare_23=V(4LL);comparison_result_28=compare_value("<",compare_22,compare_23);return comparison_result_28;}());
});scope_1->set("timeout",value_20);}
    }
    // Qiuyuan.py:16
        while(([&]()->V{auto fn_62=scope_1->get("timeout");Args args_61;return invoke(fn_62,args_61);}()).truth()){
        // Qiuyuan.py:17
        ([&]()->V{auto fn_30=attr(self_value(),"click_echo");Args args_29;args_29.kw("time_out",V(0LL));return invoke(fn_30,args_29);}());
        // Qiuyuan.py:18
        if(([&]()->V{V operand_31;operand_31=([&]()->V{V compare_32=([&]()->V{V left_34=([&]()->V{auto fn_37=attr(global("time","Qiuyuan"),"time");Args args_36;return invoke(fn_37,args_36);}());V right_35=scope_1->get("start");return official::binary("-",left_34,right_35);}());V compare_33;V comparison_result_38;compare_33=V(0.5);comparison_result_38=compare_value("<",compare_32,compare_33);return comparison_result_38;}());if(!operand_31.truth())return operand_31;return ([&]()->V{auto fn_40=attr(self_value(),"click_liberation");Args args_39;return invoke(fn_40,args_39);}());}()).truth()){
            // Qiuyuan.py:19
            {V value_41=([&]()->V{auto fn_43=attr(global("time","Qiuyuan"),"time");Args args_42;return invoke(fn_43,args_42);}());scope_1->set("start",value_41);}
        }
        // Qiuyuan.py:20
        if(([&]()->V{auto fn_45=attr(self_value(),"heavy_click_forte");Args args_44;args_44.kw("check_fun",attr(self_value(),"is_mouse_forte_full"));return invoke(fn_45,args_44);}()).truth()){
            // Qiuyuan.py:21
            return ([&]()->V{auto fn_47=attr(self_value(),"switch_next_char");Args args_46;return invoke(fn_47,args_46);}());
        }
        // Qiuyuan.py:22
        if(([&]()->V{V operand_48;operand_48=([&]()->V{auto fn_50=attr(self_value(),"flying");Args args_49;return invoke(fn_50,args_49);}());if(!operand_48.truth())return operand_48;return unary("not",([&]()->V{auto fn_52=attr(self_value(),"is_mouse_forte_full");Args args_51;return invoke(fn_52,args_51);}()));}()).truth()){
            // Qiuyuan.py:23
            ([&]()->V{auto fn_54=attr(self_value(),"shorekeeper_auto_dodge");Args args_53;return invoke(fn_54,args_53);}());
        }
        // Qiuyuan.py:24
        ([&]()->V{auto fn_56=attr(self_value(),"click");Args args_55;return invoke(fn_56,args_55);}());
        // Qiuyuan.py:25
        ([&]()->V{auto fn_58=attr(self_value(),"check_combat");Args args_57;return invoke(fn_58,args_57);}());
        // Qiuyuan.py:26
        ([&]()->V{auto fn_60=attr(attr(self_value(),"task"),"next_frame");Args args_59;return invoke(fn_60,args_59);}());
    }
    // Qiuyuan.py:27
    ([&]()->V{auto fn_64=attr(self_value(),"click_resonance");Args args_63;return invoke(fn_64,args_63);}());
    // Qiuyuan.py:28
    ([&]()->V{auto fn_66=attr(self_value(),"switch_next_char");Args args_65;return invoke(fn_66,args_65);}());
return V{};
}),false);
// Official method Qiuyuan.shorekeeper_auto_dodge, lines 30-34
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_67=bind_arguments(official_args,signature,captured);
scope_67->set("ShoreKeeper",V::missing());
scope_67->set("char",V::missing());
scope_67->set("i",V::missing());
    // Qiuyuan.py:31
    scope_67->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Qiuyuan.py:32
    {auto iterator_68=official::iterate(([&]()->V{auto fn_75=global("enumerate","Qiuyuan");Args args_74;args_74.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_75,args_74);}()));V item_69;while(iterator_68.next(item_69)){
        auto unpack_76=unpack(item_69,2);scope_67->set("i",unpack_76[0]);scope_67->set("char",unpack_76[1]);
        // Qiuyuan.py:33
        if(([&]()->V{auto fn_71=global("isinstance","Qiuyuan");Args args_70;args_70.pos(scope_67->get("char"));args_70.pos(scope_67->get("ShoreKeeper"));return invoke(fn_71,args_70);}()).truth()){
            // Qiuyuan.py:34
            return ([&]()->V{auto fn_73=attr(scope_67->get("char"),"auto_dodge");Args args_72;args_72.kw("condition",attr(self_value(),"flying"));return invoke(fn_73,args_72);}());
        }
    }
    }
return V{};
}),false);
}
