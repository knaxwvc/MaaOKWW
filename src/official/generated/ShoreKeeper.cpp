#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/ShoreKeeper.py
// SHA256 1471a3b0bdf060c372e605e1d00150bc4c3be4e8ba0390e32733d1d270217ba9
void OfficialCharacter::install_ShoreKeeper(){
auto scope=std::make_shared<Scope>();
// Official method ShoreKeeper.__init__, lines 7-12
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // ShoreKeeper.py:8
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","ShoreKeeper");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // ShoreKeeper.py:9
    {V value_6=unary("-",V(1LL));set_attr(self_value(),"outrotime",value_6);}
    // ShoreKeeper.py:10
    {V value_7=V(0LL);set_attr(self_value(),"dodge_count",value_7);}
    // ShoreKeeper.py:11
    {V value_8=V(0LL);set_attr(self_value(),"attribute",value_8);}
    // ShoreKeeper.py:12
    {V value_9=V(true);set_attr(self_value(),"check_f_on_switch",value_9);}
return V{};
}),false);
// Official method ShoreKeeper.get_switch_priority, lines 14-19
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_10=bind_arguments(official_args,signature,captured);
scope_10->set("current_name",V::missing());
    // ShoreKeeper.py:15
    ([&]()->V{auto fn_12=attr(self_value(),"decide_teammate");Args args_11;return invoke(fn_12,args_11);}());
    // ShoreKeeper.py:16
    {V value_13=(scope_10->get("current_char").truth()?attr(scope_10->get("current_char"),"char_name"):V{});scope_10->set("current_name",value_13);}
    // ShoreKeeper.py:17
    if(([&]()->V{V operand_14;operand_14=([&]()->V{V compare_15=attr(self_value(),"attribute");V compare_16;V comparison_result_17;compare_16=V(2LL);comparison_result_17=compare_value("==",compare_15,compare_16);return comparison_result_17;}());if(!operand_14.truth())return operand_14;operand_14=scope_10->get("has_intro");if(!operand_14.truth())return operand_14;return ([&]()->V{V compare_18=scope_10->get("current_name");V compare_19;V comparison_result_20;compare_19=V::set({V("Augusta"),V("char_augusta")});comparison_result_20=compare_value("in",compare_18,compare_19);return comparison_result_20;}());}()).truth()){
        // ShoreKeeper.py:18
        return attr(global("SwitchPriority","ShoreKeeper"),"MUST");
    }
    // ShoreKeeper.py:19
    return ([&]()->V{auto fn_24=attr(([&]()->V{auto fn_22=global("super","ShoreKeeper");Args args_21;return invoke(fn_22,args_21);}()),"get_switch_priority");Args args_23;args_23.pos(scope_10->get("current_char"));args_23.pos(scope_10->get("has_intro"));args_23.pos(scope_10->get("target_low_con"));return invoke(fn_24,args_23);}());
return V{};
}),false);
// Official method ShoreKeeper.skip_combat_check, lines 21-22
register_method("skip_combat_check",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_25=bind_arguments(official_args,signature,captured);
    // ShoreKeeper.py:22
    return ([&]()->V{V operand_26;operand_26=attr(self_value(),"has_intro");if(operand_26.truth())return operand_26;return ([&]()->V{auto fn_28=attr(self_value(),"flying");Args args_27;return invoke(fn_28,args_27);}());}());
return V{};
}),false);
// Official method ShoreKeeper.decide_teammate, lines 24-31
register_method("decide_teammate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_29=bind_arguments(official_args,signature,captured);
scope_29->set("Augusta",V::missing());
    // ShoreKeeper.py:25
    scope_29->set("Augusta",import_value("src.char.Augusta","Augusta"));
    // ShoreKeeper.py:26
    if(([&]()->V{V compare_30=attr(self_value(),"attribute");V compare_31;V comparison_result_32;compare_31=V(0LL);comparison_result_32=compare_value(">",compare_30,compare_31);return comparison_result_32;}()).truth()){
        // ShoreKeeper.py:27
        return V{};
    }
    // ShoreKeeper.py:28
    if(([&]()->V{auto fn_34=attr(attr(self_value(),"task"),"has_char");Args args_33;args_33.pos(scope_29->get("Augusta"));return invoke(fn_34,args_33);}()).truth()){
        // ShoreKeeper.py:29
        {V value_35=V(2LL);set_attr(self_value(),"attribute",value_35);}
    }else{
        // ShoreKeeper.py:31
        {V value_36=V(1LL);set_attr(self_value(),"attribute",value_36);}
    }
return V{};
}),false);
// Official method ShoreKeeper.do_perform, lines 33-49
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_37=bind_arguments(official_args,signature,captured);
    // ShoreKeeper.py:34
    if(attr(self_value(),"has_intro").truth()){
        // ShoreKeeper.py:35
        {V value_38=V(true);set_attr(attr(self_value(),"task"),"skip_combat_check",value_38);}
        // ShoreKeeper.py:36
        {
        auto finally_39=on_scope_exit([&](){
            // ShoreKeeper.py:44
            {V value_40=V(false);set_attr(attr(self_value(),"task"),"skip_combat_check",value_40);}
        });
            // ShoreKeeper.py:37
            ([&]()->V{auto fn_42=attr(attr(self_value(),"logger"),"debug");Args args_41;args_41.pos(V("ShoreKeeper wait intro animation"));return invoke(fn_42,args_41);}());
            // ShoreKeeper.py:38
            ([&]()->V{auto fn_44=attr(global("time","ShoreKeeper"),"sleep");Args args_43;args_43.pos(V(0.1));return invoke(fn_44,args_43);}());
            // ShoreKeeper.py:39
            if(unary("not",([&]()->V{auto fn_46=attr(attr(self_value(),"task"),"in_team_and_world");Args args_45;return invoke(fn_46,args_45);}())).truth()){
                // ShoreKeeper.py:40
                ([&]()->V{auto fn_48=attr(attr(self_value(),"task"),"wait_in_team_and_world");Args args_47;args_47.kw("time_out",V(4LL));args_47.kw("raise_if_not_found",V(false));return invoke(fn_48,args_47);}());
            }else{
                // ShoreKeeper.py:42
                ([&]()->V{auto fn_50=attr(self_value(),"continues_normal_attack");Args args_49;args_49.pos(V(1.2));return invoke(fn_50,args_49);}());
            }
        }
    }
    // ShoreKeeper.py:45
    ([&]()->V{auto fn_52=attr(self_value(),"click_echo");Args args_51;args_51.kw("time_out",V(0LL));return invoke(fn_52,args_51);}());
    // ShoreKeeper.py:46
    ([&]()->V{auto fn_54=attr(self_value(),"click_liberation");Args args_53;return invoke(fn_54,args_53);}());
    // ShoreKeeper.py:47
    if(unary("not",([&]()->V{auto fn_56=attr(self_value(),"click_resonance");Args args_55;return invoke(fn_56,args_55);}())).truth()){
        // ShoreKeeper.py:48
        ([&]()->V{auto fn_58=attr(self_value(),"heavy_click_forte");Args args_57;args_57.pos(attr(self_value(),"is_mouse_forte_full"));return invoke(fn_58,args_57);}());
    }
    // ShoreKeeper.py:49
    ([&]()->V{auto fn_60=attr(self_value(),"switch_next_char");Args args_59;return invoke(fn_60,args_59);}());
return V{};
}),false);
// Official method ShoreKeeper.switch_next_char, lines 51-55
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_61=bind_arguments(official_args,signature,captured);
    // ShoreKeeper.py:52
    if(([&]()->V{auto fn_63=attr(self_value(),"is_con_full");Args args_62;return invoke(fn_63,args_62);}()).truth()){
        // ShoreKeeper.py:53
        {V value_64=([&]()->V{auto fn_66=attr(global("time","ShoreKeeper"),"time");Args args_65;return invoke(fn_66,args_65);}());set_attr(self_value(),"outrotime",value_64);}
        // ShoreKeeper.py:54
        {V value_67=V(5LL);set_attr(self_value(),"dodge_count",value_67);}
    }
    // ShoreKeeper.py:55
    return ([&]()->V{auto fn_71=attr(([&]()->V{auto fn_69=global("super","ShoreKeeper");Args args_68;return invoke(fn_69,args_68);}()),"switch_next_char");Args args_70;args_70.spread(scope_61->get("args"));args_70.spread_keywords(scope_61->get("kwargs"));return invoke(fn_71,args_70);}());
return V{};
}),false);
// Official method ShoreKeeper.auto_dodge, lines 57-71
register_method("auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"condition",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_72=bind_arguments(official_args,signature,captured);
scope_72->set("clicked",V::missing());
scope_72->set("start",V::missing());
    // ShoreKeeper.py:58
    {V value_73=V(false);scope_72->set("clicked",value_73);}
    // ShoreKeeper.py:59
    if(([&]()->V{V operand_74;operand_74=([&]()->V{V compare_75=([&]()->V{auto fn_78=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_77;args_77.pos(attr(self_value(),"outrotime"));return invoke(fn_78,args_77);}());V compare_76;V comparison_result_79;compare_76=V(30LL);comparison_result_79=compare_value("<",compare_75,compare_76);return comparison_result_79;}());if(!operand_74.truth())return operand_74;return ([&]()->V{V compare_80=attr(self_value(),"dodge_count");V compare_81;V comparison_result_82;compare_81=V(0LL);comparison_result_82=compare_value(">",compare_80,compare_81);return comparison_result_82;}());}()).truth()){
        // ShoreKeeper.py:60
        {V value_83=([&]()->V{auto fn_85=attr(global("time","ShoreKeeper"),"time");Args args_84;return invoke(fn_85,args_84);}());scope_72->set("start",value_83);}
        // ShoreKeeper.py:61
                while(([&]()->V{V compare_95=([&]()->V{V left_97=([&]()->V{auto fn_100=attr(global("time","ShoreKeeper"),"time");Args args_99;return invoke(fn_100,args_99);}());V right_98=scope_72->get("start");return official::binary("-",left_97,right_98);}());V compare_96;V comparison_result_101;compare_96=V(1.5);comparison_result_101=compare_value("<",compare_95,compare_96);return comparison_result_101;}()).truth()){
            // ShoreKeeper.py:62
            if(unary("not",([&]()->V{auto fn_87=scope_72->get("condition");Args args_86;return invoke(fn_87,args_86);}())).truth()){
                // ShoreKeeper.py:63
                break;
            }
            // ShoreKeeper.py:64
            ([&]()->V{auto fn_89=attr(self_value(),"continues_right_click");Args args_88;args_88.pos(V(0.05));return invoke(fn_89,args_88);}());
            // ShoreKeeper.py:65
            ([&]()->V{auto fn_91=attr(self_value(),"sleep");Args args_90;args_90.pos(V(0.05));return invoke(fn_91,args_90);}());
            // ShoreKeeper.py:66
            {V value_92=V(true);scope_72->set("clicked",value_92);}
            // ShoreKeeper.py:67
            ([&]()->V{auto fn_94=attr(attr(self_value(),"task"),"next_frame");Args args_93;return invoke(fn_94,args_93);}());
        }
    }
    // ShoreKeeper.py:68
    if(scope_72->get("clicked").truth()){
        // ShoreKeeper.py:69
        set_attr(self_value(),"dodge_count",official::binary("-",attr(self_value(),"dodge_count"),V(1LL)));
        // ShoreKeeper.py:70
        ([&]()->V{auto fn_103=attr(attr(self_value(),"logger"),"info");Args args_102;args_102.pos(V("ShoreKeepers auto dodge success!"));return invoke(fn_103,args_102);}());
    }
    // ShoreKeeper.py:71
    return scope_72->get("clicked");
return V{};
}),false);
}
}
