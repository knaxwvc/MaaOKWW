#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Sanhua.py
// SHA256 162b40dede895c2e586498ecf8f21ca07ad453b4626f82db520f3b8fea41c75f
void OfficialCharacter::install_Sanhua(){
auto scope=std::make_shared<Scope>();
// Official method Sanhua.do_perform, lines 7-35
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("liber_clicked",V::missing());
scope_1->set("sleep_time",V::missing());
scope_1->set("start",V::missing());
    // Sanhua.py:8
    {V value_2=V(false);scope_1->set("liber_clicked",value_2);}
    // Sanhua.py:9
    {V value_3=V(0.85);scope_1->set("sleep_time",value_3);}
    // Sanhua.py:10
    ([&]()->V{auto fn_5=attr(self_value(),"sleep");Args args_4;args_4.pos(V(0.02));return invoke(fn_5,args_4);}());
    // Sanhua.py:11
    {V value_6=([&]()->V{auto fn_8=attr(global("time","Sanhua"),"time");Args args_7;return invoke(fn_8,args_7);}());scope_1->set("start",value_6);}
    // Sanhua.py:12
    ([&]()->V{auto fn_10=attr(attr(self_value(),"task"),"mouse_down");Args args_9;return invoke(fn_10,args_9);}());
    // Sanhua.py:13
    ([&]()->V{auto fn_12=attr(self_value(),"wait_down");Args args_11;args_11.kw("click",V(false));return invoke(fn_12,args_11);}());
    // Sanhua.py:14
    if(([&]()->V{auto fn_14=attr(self_value(),"click_liberation");Args args_13;args_13.kw("send_click",V(false));return invoke(fn_14,args_13);}()).truth()){
        // Sanhua.py:15
        {V value_15=V(true);scope_1->set("liber_clicked",value_15);}
        // Sanhua.py:16
        scope_1->set("sleep_time",official::binary("+",scope_1->get("sleep_time"),V(0.1)));
        // Sanhua.py:17
        ([&]()->V{auto fn_17=attr(self_value(),"sleep");Args args_16;args_16.pos(V(0.15));args_16.pos(V(false));return invoke(fn_17,args_16);}());
    }else{
        // Sanhua.py:18
        if(([&]()->V{auto fn_19=attr(self_value(),"resonance_available");Args args_18;return invoke(fn_19,args_18);}()).truth()){
            // Sanhua.py:19
            ([&]()->V{auto fn_21=attr(attr(self_value(),"task"),"mouse_up");Args args_20;return invoke(fn_21,args_20);}());
            // Sanhua.py:20
            ([&]()->V{auto fn_23=attr(self_value(),"click_resonance");Args args_22;args_22.kw("send_click",V(false));return invoke(fn_23,args_22);}());
            // Sanhua.py:21
            {V value_24=([&]()->V{auto fn_26=attr(global("time","Sanhua"),"time");Args args_25;return invoke(fn_26,args_25);}());scope_1->set("start",value_24);}
            // Sanhua.py:22
            ([&]()->V{auto fn_28=attr(attr(self_value(),"task"),"mouse_down");Args args_27;return invoke(fn_28,args_27);}());
            // Sanhua.py:23
            ([&]()->V{auto fn_30=attr(self_value(),"sleep");Args args_29;args_29.pos(V(0.1));args_29.pos(V(false));return invoke(fn_30,args_29);}());
        }
    }
    // Sanhua.py:24
    scope_1->set("sleep_time",official::binary("-",scope_1->get("sleep_time"),([&]()->V{auto fn_32=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_31;args_31.pos(scope_1->get("start"));return invoke(fn_32,args_31);}())));
    // Sanhua.py:25
    ([&]()->V{auto fn_34=attr(attr(self_value(),"logger"),"info");Args args_33;args_33.pos(([&]()->V{auto fn_36=attr(V("Sanhua to_sleep {}"),"format");Args args_35;args_35.pos(scope_1->get("sleep_time"));return invoke(fn_36,args_35);}()));return invoke(fn_34,args_33);}());
    // Sanhua.py:26
    if(([&]()->V{V compare_37=scope_1->get("sleep_time");V compare_38;V comparison_result_39;compare_38=V(0LL);comparison_result_39=compare_value(">",compare_37,compare_38);return comparison_result_39;}()).truth()){
        // Sanhua.py:27
        ([&]()->V{auto fn_41=attr(self_value(),"sleep");Args args_40;args_40.pos(scope_1->get("sleep_time"));args_40.pos(V(false));return invoke(fn_41,args_40);}());
    }
    // Sanhua.py:28
    ([&]()->V{auto fn_43=attr(attr(self_value(),"task"),"mouse_up");Args args_42;return invoke(fn_43,args_42);}());
    // Sanhua.py:29
    ([&]()->V{auto fn_45=attr(self_value(),"sleep");Args args_44;args_44.pos(V(0.8));return invoke(fn_45,args_44);}());
    // Sanhua.py:30
    if(scope_1->get("liber_clicked").truth()){
        // Sanhua.py:31
        ([&]()->V{auto fn_47=attr(self_value(),"click_resonance");Args args_46;args_46.kw("send_click",V(false));return invoke(fn_47,args_46);}());
        // Sanhua.py:32
        ([&]()->V{auto fn_49=attr(self_value(),"sleep");Args args_48;args_48.pos(V(0.3));return invoke(fn_49,args_48);}());
    }
    // Sanhua.py:33
    if(([&]()->V{auto fn_51=attr(self_value(),"is_con_full");Args args_50;return invoke(fn_51,args_50);}()).truth()){
        // Sanhua.py:34
        ([&]()->V{auto fn_53=attr(self_value(),"click_echo");Args args_52;return invoke(fn_53,args_52);}());
    }
    // Sanhua.py:35
    ([&]()->V{auto fn_55=attr(self_value(),"switch_next_char");Args args_54;return invoke(fn_55,args_54);}());
return V{};
}),false);
}
}
