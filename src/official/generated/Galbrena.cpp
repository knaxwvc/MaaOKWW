#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Galbrena.py
// SHA256 c64fa7401297906272452fc3faa00b553f195e2568b76d6ffbfebe7cecf79e5c
void OfficialCharacter::install_Galbrena(){
auto scope=std::make_shared<Scope>();
// Official method Galbrena.do_perform, lines 8-37
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("start",V::missing());
    // Galbrena.py:9
    if(attr(self_value(),"has_intro").truth()){
        // Galbrena.py:10
        ([&]()->V{auto fn_3=attr(attr(self_value(),"logger"),"debug");Args args_2;args_2.pos(V("has_intro wait and heavy attack for 86F and dodge"));return invoke(fn_3,args_2);}());
        // Galbrena.py:11
        ([&]()->V{auto fn_5=attr(attr(self_value(),"task"),"mouse_down");Args args_4;return invoke(fn_5,args_4);}());
        // Galbrena.py:12
        ([&]()->V{auto fn_7=attr(self_value(),"sleep");Args args_6;args_6.pos(V(1LL));return invoke(fn_7,args_6);}());
        // Galbrena.py:13
        if(([&]()->V{auto fn_9=attr(self_value(),"need_fast_perform");Args args_8;return invoke(fn_9,args_8);}()).truth()){
            // Galbrena.py:14
            ([&]()->V{auto fn_11=attr(attr(self_value(),"task"),"mouse_up");Args args_10;return invoke(fn_11,args_10);}());
            // Galbrena.py:15
            return ([&]()->V{auto fn_13=attr(self_value(),"switch_next_char");Args args_12;return invoke(fn_13,args_12);}());
        }
        // Galbrena.py:16
        ([&]()->V{auto fn_15=attr(self_value(),"sleep");Args args_14;args_14.pos(V(0.44));return invoke(fn_15,args_14);}());
        // Galbrena.py:17
        ([&]()->V{auto fn_17=attr(attr(self_value(),"task"),"mouse_up");Args args_16;return invoke(fn_17,args_16);}());
        // Galbrena.py:18
        ([&]()->V{auto fn_19=attr(self_value(),"continues_right_click");Args args_18;args_18.pos(V(0.6));return invoke(fn_19,args_18);}());
    }else{
        // Galbrena.py:19
        if(([&]()->V{auto fn_21=attr(self_value(),"flying");Args args_20;return invoke(fn_21,args_20);}()).truth()){
            // Galbrena.py:20
            ([&]()->V{auto fn_23=attr(self_value(),"wait_down");Args args_22;return invoke(fn_23,args_22);}());
        }
    }
    // Galbrena.py:21
    ([&]()->V{auto fn_25=attr(self_value(),"click_echo");Args args_24;args_24.kw("time_out",V(0LL));return invoke(fn_25,args_24);}());
    // Galbrena.py:22
    if(([&]()->V{V operand_26;operand_26=([&]()->V{auto fn_28=attr(self_value(),"is_forte_full");Args args_27;return invoke(fn_28,args_27);}());if(!operand_26.truth())return operand_26;return unary("not",([&]()->V{auto fn_30=attr(self_value(),"need_fast_perform");Args args_29;return invoke(fn_30,args_29);}()));}()).truth()){
        // Galbrena.py:23
        ([&]()->V{auto fn_32=attr(self_value(),"click_resonance");Args args_31;return invoke(fn_32,args_31);}());
        // Galbrena.py:24
        if(([&]()->V{auto fn_34=attr(self_value(),"click_liberation");Args args_33;return invoke(fn_34,args_33);}()).truth()){
            // Galbrena.py:25
            ([&]()->V{auto fn_36=attr(self_value(),"continues_normal_attack");Args args_35;args_35.pos(V(1LL));return invoke(fn_36,args_35);}());
        }
    }
    // Galbrena.py:26
    if(([&]()->V{V operand_37;operand_37=([&]()->V{auto fn_39=attr(self_value(),"check_res");Args args_38;return invoke(fn_39,args_38);}());if(!operand_37.truth())return operand_37;return unary("not",([&]()->V{auto fn_41=attr(self_value(),"need_fast_perform");Args args_40;return invoke(fn_41,args_40);}()));}()).truth()){
        // Galbrena.py:27
        ([&]()->V{auto fn_43=attr(self_value(),"click_liberation");Args args_42;return invoke(fn_43,args_42);}());
        // Galbrena.py:28
        {V value_44=([&]()->V{auto fn_46=attr(global("time","Galbrena"),"time");Args args_45;return invoke(fn_46,args_45);}());scope_1->set("start",value_44);}
        // Galbrena.py:29
                while(([&]()->V{V operand_55;operand_55=([&]()->V{auto fn_57=attr(self_value(),"check_res");Args args_56;return invoke(fn_57,args_56);}());if(!operand_55.truth())return operand_55;return ([&]()->V{V compare_58=([&]()->V{V left_60=([&]()->V{auto fn_63=attr(global("time","Galbrena"),"time");Args args_62;return invoke(fn_63,args_62);}());V right_61=scope_1->get("start");return official::binary("-",left_60,right_61);}());V compare_59;V comparison_result_64;compare_59=V(10LL);comparison_result_64=compare_value("<",compare_58,compare_59);return comparison_result_64;}());}()).truth()){
            // Galbrena.py:30
            if(([&]()->V{auto fn_48=attr(self_value(),"flying");Args args_47;return invoke(fn_48,args_47);}()).truth()){
                // Galbrena.py:31
                ([&]()->V{auto fn_50=attr(self_value(),"shorekeeper_auto_dodge");Args args_49;return invoke(fn_50,args_49);}());
            }
            // Galbrena.py:32
            ([&]()->V{auto fn_52=attr(self_value(),"click");Args args_51;args_51.kw("after_sleep",V(0.1));return invoke(fn_52,args_51);}());
            // Galbrena.py:33
            ([&]()->V{auto fn_54=attr(self_value(),"check_combat");Args args_53;return invoke(fn_54,args_53);}());
        }
        // Galbrena.py:34
        return ([&]()->V{auto fn_66=attr(self_value(),"switch_next_char");Args args_65;return invoke(fn_66,args_65);}());
    }
    // Galbrena.py:35
    ([&]()->V{auto fn_68=attr(self_value(),"continues_normal_attack");Args args_67;args_67.pos(V(1LL));return invoke(fn_68,args_67);}());
    // Galbrena.py:36
    ([&]()->V{auto fn_70=attr(self_value(),"click_resonance");Args args_69;return invoke(fn_70,args_69);}());
    // Galbrena.py:37
    return ([&]()->V{auto fn_72=attr(self_value(),"switch_next_char");Args args_71;return invoke(fn_72,args_71);}());
return V{};
}),false);
// Official method Galbrena.check_res, lines 39-46
register_method("check_res",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_73=bind_arguments(official_args,signature,captured);
scope_73->set("best",V::missing());
    // Galbrena.py:40
    if(unary("not",([&]()->V{auto fn_75=attr(attr(self_value(),"task"),"in_team_and_world");Args args_74;return invoke(fn_75,args_74);}())).truth()){
        // Galbrena.py:41
        return V(false);
    }
    // Galbrena.py:42
    {V value_76=([&]()->V{auto fn_78=attr(attr(self_value(),"task"),"find_best_match_in_box");Args args_77;args_77.pos(([&]()->V{auto fn_80=attr(attr(self_value(),"task"),"get_box_by_name");Args args_79;args_79.pos(V("box_target_enemy_long"));return invoke(fn_80,args_79);}()));args_77.pos(V::list({V("has_target"),V("no_target")}));args_77.kw("threshold",V(0.6));return invoke(fn_78,args_77);}());scope_73->set("best",value_76);}
    // Galbrena.py:45
    ([&]()->V{auto fn_82=attr(attr(self_value(),"logger"),"debug");Args args_81;args_81.pos(V(std::string{}+"check res "+format_value(scope_73->get("best"),"",-1)));return invoke(fn_82,args_81);}());
    // Galbrena.py:46
    return scope_73->get("best");
return V{};
}),false);
// Official method Galbrena.shorekeeper_auto_dodge, lines 48-52
register_method("shorekeeper_auto_dodge",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_83=bind_arguments(official_args,signature,captured);
scope_83->set("ShoreKeeper",V::missing());
scope_83->set("char",V::missing());
scope_83->set("i",V::missing());
    // Galbrena.py:49
    scope_83->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // Galbrena.py:50
    {auto iterator_84=official::iterate(([&]()->V{auto fn_91=global("enumerate","Galbrena");Args args_90;args_90.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_91,args_90);}()));V item_85;while(iterator_84.next(item_85)){
        auto unpack_92=unpack(item_85,2);scope_83->set("i",unpack_92[0]);scope_83->set("char",unpack_92[1]);
        // Galbrena.py:51
        if(([&]()->V{auto fn_87=global("isinstance","Galbrena");Args args_86;args_86.pos(scope_83->get("char"));args_86.pos(scope_83->get("ShoreKeeper"));return invoke(fn_87,args_86);}()).truth()){
            // Galbrena.py:52
            return ([&]()->V{auto fn_89=attr(scope_83->get("char"),"auto_dodge");Args args_88;args_88.kw("condition",attr(self_value(),"flying"));return invoke(fn_89,args_88);}());
        }
    }
    }
return V{};
}),false);
}
}
