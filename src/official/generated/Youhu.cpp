#include "../OfficialCharacter.h"
namespace official {
// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Youhu.py
// SHA256 bf5ce66d7270eb3e4d8390b41022b4adc9eda4b9e68ec8b975fcacdda61e0eb6
void OfficialCharacter::install_Youhu(){
auto scope=std::make_shared<Scope>();
// Official method Youhu.__init__, lines 6-7
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Youhu.py:7
    ([&]()->V{auto fn_5=attr(([&]()->V{auto fn_3=global("super","Youhu");Args args_2;return invoke(fn_3,args_2);}()),"__init__");Args args_4;args_4.spread(scope_1->get("args"));args_4.spread_keywords(scope_1->get("kwargs"));return invoke(fn_5,args_4);}());
return V{};
}),false);
}
}
