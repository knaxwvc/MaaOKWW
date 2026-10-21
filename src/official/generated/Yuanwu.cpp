#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Yuanwu.py
// SHA256 1b5ea7df288242b7ec40a3c0fa65eb45cd87c28dd93637d0631a4d1be84f65ba
void OfficialCharacter::install_Yuanwu(){
auto scope=std::make_shared<Scope>();
// Official method Yuanwu.do_perform, lines 6-15
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Yuanwu.py:7
    if(([&]()->V{auto fn_3=attr(self_value(),"click_liberation");Args args_2;args_2.kw("con_less_than",V(1LL));return invoke(fn_3,args_2);}()).truth()){
        // Yuanwu.py:8
        ([&]()->V{auto fn_5=attr(self_value(),"click_resonance");Args args_4;return invoke(fn_5,args_4);}());
        // Yuanwu.py:9
        return ([&]()->V{auto fn_7=attr(self_value(),"switch_next_char");Args args_6;return invoke(fn_7,args_6);}());
    }
    // Yuanwu.py:10
    if(attr(self_value(),"has_intro").truth()){
        // Yuanwu.py:11
        ([&]()->V{auto fn_9=attr(self_value(),"continues_normal_attack");Args args_8;args_8.pos(V(1.2));return invoke(fn_9,args_8);}());
        // Yuanwu.py:12
        return ([&]()->V{auto fn_11=attr(self_value(),"switch_next_char");Args args_10;return invoke(fn_11,args_10);}());
    }
    // Yuanwu.py:13
    ([&]()->V{auto fn_13=attr(self_value(),"click_resonance");Args args_12;return invoke(fn_13,args_12);}());
    // Yuanwu.py:14
    ([&]()->V{auto fn_15=attr(self_value(),"click_echo");Args args_14;return invoke(fn_15,args_14);}());
    // Yuanwu.py:15
    ([&]()->V{auto fn_17=attr(self_value(),"switch_next_char");Args args_16;return invoke(fn_17,args_16);}());
return V{};
}),false);
}
}
