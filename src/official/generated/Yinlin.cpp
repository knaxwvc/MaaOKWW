#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Yinlin.py
// SHA256 d0cf056ad3c1371ecde1fde1da3ab2d5b8ccb1ae1d0fd993026ce2a145768a25
void OfficialCharacter::install_Yinlin(){
auto scope=std::make_shared<Scope>();
// Official method Yinlin.do_perform, lines 5-20
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("liberation",V::missing());
    // Yinlin.py:6
    if(attr(self_value(),"has_intro").truth()){
        // Yinlin.py:7
        ([&]()->V{auto fn_3=attr(self_value(),"sleep");Args args_2;args_2.pos(V(0.4));return invoke(fn_3,args_2);}());
    }
    // Yinlin.py:8
    {V value_4=([&]()->V{auto fn_6=attr(self_value(),"click_liberation");Args args_5;return invoke(fn_6,args_5);}());scope_1->set("liberation",value_4);}
    // Yinlin.py:9
    if(([&]()->V{auto fn_8=attr(self_value(),"is_mouse_forte_full");Args args_7;return invoke(fn_8,args_7);}()).truth()){
        // Yinlin.py:10
        if(([&]()->V{V operand_9;operand_9=unary("not",attr(self_value(),"has_intro"));if(!operand_9.truth())return operand_9;return unary("not",scope_1->get("liberation"));}()).truth()){
            // Yinlin.py:11
            ([&]()->V{auto fn_11=attr(self_value(),"normal_attack");Args args_10;return invoke(fn_11,args_10);}());
        }
        // Yinlin.py:12
        ([&]()->V{auto fn_13=attr(self_value(),"heavy_attack");Args args_12;return invoke(fn_13,args_12);}());
        // Yinlin.py:13
        ([&]()->V{auto fn_15=attr(self_value(),"sleep");Args args_14;args_14.pos(V(0.4));return invoke(fn_15,args_14);}());
    }else{
        // Yinlin.py:14
        if(item(([&]()->V{auto fn_17=attr(self_value(),"click_resonance");Args args_16;args_16.kw("send_click",V(false));return invoke(fn_17,args_16);}()),V(0LL)).truth()){
            // Yinlin.py:15
            ([&]()->V{auto fn_19=attr(self_value(),"sleep");Args args_18;args_18.pos(V(0.1));return invoke(fn_19,args_18);}());
        }else{
            // Yinlin.py:16
            if(([&]()->V{auto fn_21=attr(self_value(),"echo_available");Args args_20;return invoke(fn_21,args_20);}()).truth()){
                // Yinlin.py:17
                ([&]()->V{auto fn_23=attr(self_value(),"click_echo");Args args_22;return invoke(fn_23,args_22);}());
            }else{
                // Yinlin.py:19
                ([&]()->V{auto fn_25=attr(self_value(),"heavy_attack");Args args_24;return invoke(fn_25,args_24);}());
            }
        }
    }
    // Yinlin.py:20
    ([&]()->V{auto fn_27=attr(self_value(),"switch_next_char");Args args_26;return invoke(fn_27,args_26);}());
return V{};
}),false);
}
}
