#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Xiangliyao.py
// SHA256 2ceb903c1a3f5041c0ab92e6265369e155edac1d5ff214a7694e2ca2f1921b8a
void OfficialCharacter::install_Xiangliyao(){
auto scope=std::make_shared<Scope>();
// Official method Xiangliyao.__init__, lines 8-10
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Xiangliyao.py:9
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Xiangliyao");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Xiangliyao.py:10
    {V value_6=V(0LL);set_attr(self_value(),"liberation_time",value_6);}
return V{};
}),false);
// Official method Xiangliyao.do_perform, lines 12-24
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_7=bind_arguments(official_args,signature,captured);
    // Xiangliyao.py:13
    ([&]()->V{auto fn_9=attr(self_value(),"wait_down");Args args_8;return invoke(fn_9,args_8);}());
    // Xiangliyao.py:14
    if(([&]()->V{auto fn_11=attr(self_value(),"click_liberation");Args args_10;return invoke(fn_11,args_10);}()).truth()){
        // Xiangliyao.py:15
        {V value_12=([&]()->V{auto fn_14=attr(global("time","Xiangliyao"),"time");Args args_13;return invoke(fn_14,args_13);}());set_attr(self_value(),"liberation_time",value_12);}
    }
    // Xiangliyao.py:16
    if(([&]()->V{auto fn_16=attr(self_value(),"still_in_liberation");Args args_15;return invoke(fn_16,args_15);}()).truth()){
        // Xiangliyao.py:17
                while(unary("not",item(([&]()->V{auto fn_20=attr(self_value(),"click_resonance");Args args_19;args_19.kw("send_click",V(true));return invoke(fn_20,args_19);}()),V(0LL))).truth()){
            // Xiangliyao.py:18
            ([&]()->V{auto fn_18=attr(self_value(),"continues_normal_attack");Args args_17;args_17.pos(V(1LL));return invoke(fn_18,args_17);}());
        }
    }else{
        // Xiangliyao.py:19
        if(([&]()->V{auto fn_22=attr(self_value(),"echo_available");Args args_21;return invoke(fn_22,args_21);}()).truth()){
            // Xiangliyao.py:20
            ([&]()->V{auto fn_24=attr(attr(self_value(),"logger"),"debug");Args args_23;args_23.pos(V("click_echo"));return invoke(fn_24,args_23);}());
            // Xiangliyao.py:21
            ([&]()->V{auto fn_26=attr(self_value(),"click_echo");Args args_25;return invoke(fn_26,args_25);}());
        }else{
            // Xiangliyao.py:23
            ([&]()->V{auto fn_28=attr(self_value(),"click_resonance");Args args_27;args_27.kw("send_click",V(true));return invoke(fn_28,args_27);}());
        }
    }
    // Xiangliyao.py:24
    ([&]()->V{auto fn_30=attr(self_value(),"switch_next_char");Args args_29;return invoke(fn_30,args_29);}());
return V{};
}),false);
// Official method Xiangliyao.still_in_liberation, lines 26-27
register_method("still_in_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_31=bind_arguments(official_args,signature,captured);
    // Xiangliyao.py:27
    return ([&]()->V{V compare_32=([&]()->V{auto fn_35=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_34;args_34.pos(attr(self_value(),"liberation_time"));return invoke(fn_35,args_34);}());V compare_33;V comparison_result_36;compare_33=V(25LL);comparison_result_36=compare_value("<",compare_32,compare_33);return comparison_result_36;}());
return V{};
}),false);
}
}
