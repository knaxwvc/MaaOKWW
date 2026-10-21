#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Taoqi.py
// SHA256 ec447aa3b4eef65fcc304f9f9f296eb5134cb9d496cf932037fd22a38c3e3ca9
void OfficialCharacter::install_Taoqi(){
auto scope=std::make_shared<Scope>();
// Official method Taoqi.do_perform, lines 5-13
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Taoqi.py:6
    if(attr(self_value(),"has_intro").truth()){
        // Taoqi.py:7
        ([&]()->V{auto fn_3=attr(self_value(),"wait_down");Args args_2;return invoke(fn_3,args_2);}());
        // Taoqi.py:8
        ([&]()->V{auto fn_5=attr(self_value(),"continues_normal_attack");Args args_4;args_4.pos(V(2.5));return invoke(fn_5,args_4);}());
    }else{
        // Taoqi.py:10
        ([&]()->V{auto fn_7=attr(self_value(),"click_liberation");Args args_6;return invoke(fn_7,args_6);}());
        // Taoqi.py:11
        ([&]()->V{auto fn_9=attr(self_value(),"click_resonance");Args args_8;return invoke(fn_9,args_8);}());
        // Taoqi.py:12
        ([&]()->V{auto fn_11=attr(self_value(),"click_echo");Args args_10;args_10.kw("sleep_time",V(0.1));return invoke(fn_11,args_10);}());
    }
    // Taoqi.py:13
    ([&]()->V{auto fn_13=attr(self_value(),"switch_next_char");Args args_12;return invoke(fn_13,args_12);}());
return V{};
}),false);
}
}
