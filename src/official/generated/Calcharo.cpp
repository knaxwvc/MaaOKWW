#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Calcharo.py
// SHA256 e987a65c3923a719a0cda3625b86ddbba987e54a73b34a7d6225134960270198
void OfficialCharacter::install_Calcharo(){
auto scope=std::make_shared<Scope>();
// Official method Calcharo.do_perform, lines 5-11
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Calcharo.py:6
    if(attr(self_value(),"has_intro").truth()){
        // Calcharo.py:7
        ([&]()->V{auto fn_3=attr(attr(self_value(),"logger"),"debug");Args args_2;args_2.pos(V("Calcharo wait intro animation"));return invoke(fn_3,args_2);}());
        // Calcharo.py:8
        ([&]()->V{auto fn_5=attr(self_value(),"sleep");Args args_4;args_4.pos(V(1LL));return invoke(fn_5,args_4);}());
        // Calcharo.py:9
        ([&]()->V{auto fn_7=attr(attr(self_value(),"task"),"wait_in_team_and_world");Args args_6;args_6.kw("time_out",V(3LL));args_6.kw("raise_if_not_found",V(false));return invoke(fn_7,args_6);}());
        // Calcharo.py:10
        ([&]()->V{auto fn_9=attr(self_value(),"check_combat");Args args_8;return invoke(fn_9,args_8);}());
    }
    // Calcharo.py:11
    ([&]()->V{auto fn_13=attr(([&]()->V{auto fn_11=global("super","Calcharo");Args args_10;return invoke(fn_11,args_10);}()),"do_perform");Args args_12;return invoke(fn_13,args_12);}());
return V{};
}),false);
}
}
