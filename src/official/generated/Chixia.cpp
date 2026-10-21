#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Chixia.py
// SHA256 ffe0b8d1e20a15203331da47e6a77b5b2c46248a7bd32cbb4d5b546ddf60a847
void OfficialCharacter::install_Chixia(){
auto scope=std::make_shared<Scope>();
// Official method Chixia.__init__, lines 6-8
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Chixia.py:7
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Chixia");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
    // Chixia.py:8
    {V value_6=V(0LL);set_attr(self_value(),"bullets",value_6);}
return V{};
}),false);
}
}
