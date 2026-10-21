#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Jianxin.py
// SHA256 9078752d79b735f71ff43a0681a3b85e1d871b670262d46b398c35ff8603b45a
void OfficialCharacter::install_Jianxin(){
auto scope=std::make_shared<Scope>();
// Official method Jianxin.do_perform, lines 5-13
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Jianxin.py:6
    if(attr(self_value(),"has_intro").truth()){
        // Jianxin.py:7
        ([&]()->V{auto fn_3=attr(self_value(),"continues_normal_attack");Args args_2;args_2.pos(V(1LL));return invoke(fn_3,args_2);}());
    }
    // Jianxin.py:8
    ([&]()->V{auto fn_5=attr(self_value(),"click_liberation");Args args_4;return invoke(fn_5,args_4);}());
    // Jianxin.py:9
    if(([&]()->V{auto fn_7=attr(self_value(),"resonance_available");Args args_6;return invoke(fn_7,args_6);}()).truth()){
        // Jianxin.py:10
        ([&]()->V{auto fn_9=attr(self_value(),"click_resonance");Args args_8;return invoke(fn_9,args_8);}());
    }
    // Jianxin.py:11
    if(([&]()->V{auto fn_11=attr(self_value(),"echo_available");Args args_10;return invoke(fn_11,args_10);}()).truth()){
        // Jianxin.py:12
        ([&]()->V{auto fn_13=attr(self_value(),"click_echo");Args args_12;return invoke(fn_13,args_12);}());
    }
    // Jianxin.py:13
    ([&]()->V{auto fn_15=attr(self_value(),"switch_next_char");Args args_14;return invoke(fn_15,args_14);}());
return V{};
}),false);
}
}
