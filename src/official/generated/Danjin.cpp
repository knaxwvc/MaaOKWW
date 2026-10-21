#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Danjin.py
// SHA256 03e2c2d80068b5c0b0b412a958718ff7dc6a4ae509922abe44ac95bcbfccfb77
void OfficialCharacter::install_Danjin(){
auto scope=std::make_shared<Scope>();
// Official method Danjin.__init__, lines 6-7
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Danjin.py:7
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Danjin");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
return V{};
}),false);
// Official method Danjin.do_perform, lines 9-30
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_6=bind_arguments(official_args,signature,captured);
scope_6->set("duration",V::missing());
scope_6->set("liberated",V::missing());
    // Danjin.py:10
    {V value_7=([&]()->V{auto fn_9=attr(self_value(),"click_liberation");Args args_8;return invoke(fn_9,args_8);}());scope_6->set("liberated",value_7);}
    // Danjin.py:11
    if(scope_6->get("liberated").truth()){
        // Danjin.py:12
        ([&]()->V{auto fn_11=attr(self_value(),"sleep");Args args_10;args_10.pos(V(1.2));return invoke(fn_11,args_10);}());
        // Danjin.py:13
        ([&]()->V{auto fn_13=attr(self_value(),"click_echo");Args args_12;args_12.kw("time_out",V(2LL));return invoke(fn_13,args_12);}());
        // Danjin.py:14
        return ([&]()->V{auto fn_15=attr(self_value(),"switch_next_char");Args args_14;return invoke(fn_15,args_14);}());
    }
    // Danjin.py:15
    if(([&]()->V{V operand_16;operand_16=([&]()->V{auto fn_18=attr(self_value(),"is_forte_full");Args args_17;return invoke(fn_18,args_17);}());if(!operand_16.truth())return operand_16;return attr(self_value(),"has_intro");}()).truth()){
        // Danjin.py:16
        {V value_19=V(0.8);scope_6->set("duration",value_19);}
        // Danjin.py:17
        if(attr(attr(self_value(),"task"),"debug").truth()){
            // Danjin.py:18
            ([&]()->V{auto fn_21=attr(attr(self_value(),"task"),"screenshot");Args args_20;args_20.pos(V("danjin_heavy"));return invoke(fn_21,args_20);}());
        }
        // Danjin.py:19
        ([&]()->V{auto fn_23=attr(self_value(),"heavy_attack");Args args_22;args_22.pos(scope_6->get("duration"));return invoke(fn_23,args_22);}());
        // Danjin.py:20
        ([&]()->V{auto fn_25=attr(self_value(),"sleep");Args args_24;args_24.pos(V(0.2));return invoke(fn_25,args_24);}());
        // Danjin.py:21
        ([&]()->V{auto fn_27=attr(self_value(),"normal_attack");Args args_26;return invoke(fn_27,args_26);}());
        // Danjin.py:22
        ([&]()->V{auto fn_29=attr(self_value(),"sleep");Args args_28;args_28.pos(V(0.1));return invoke(fn_29,args_28);}());
        // Danjin.py:23
        return ([&]()->V{auto fn_31=attr(self_value(),"switch_next_char");Args args_30;return invoke(fn_31,args_30);}());
    }
    // Danjin.py:24
    if(attr(self_value(),"has_intro").truth()){
        // Danjin.py:25
        ([&]()->V{auto fn_33=attr(self_value(),"continues_normal_attack");Args args_32;args_32.pos(V(1.1));return invoke(fn_33,args_32);}());
    }else{
        // Danjin.py:27
        ([&]()->V{auto fn_35=attr(self_value(),"wait_down");Args args_34;return invoke(fn_35,args_34);}());
        // Danjin.py:28
        ([&]()->V{auto fn_37=attr(self_value(),"continues_normal_attack");Args args_36;args_36.pos(V(0.4));args_36.kw("interval",V(0.1));return invoke(fn_37,args_36);}());
    }
    // Danjin.py:29
    ([&]()->V{auto fn_39=attr(self_value(),"continues_click");Args args_38;args_38.pos(([&]()->V{auto fn_41=attr(self_value(),"get_resonance_key");Args args_40;return invoke(fn_41,args_40);}()));args_38.pos(V(1.1));args_38.kw("interval",V(0.2));return invoke(fn_39,args_38);}());
    // Danjin.py:30
    ([&]()->V{auto fn_43=attr(self_value(),"switch_next_char");Args args_42;return invoke(fn_43,args_42);}());
return V{};
}),false);
}
}
