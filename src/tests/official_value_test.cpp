#define NOMINMAX
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <regex>
#include <iostream>
#include "MaaFramework/MaaAPI.h"
template<class F>F api(HMODULE m,const char* name){return reinterpret_cast<F>(GetProcAddress(m,name));}
#include "../char/OriginalBaseChar.h"
#include "../official/OfficialBuiltins.h"
#include <cassert>
using namespace official;
int main(){
    const auto globals=standard_globals();
    assert(V::tuple({V(false),V(0),V(false)}).truth());
    assert(!V::list().truth() && !V::dict().truth() && !V{}.truth());
    Args a;a.kw("duration",V(1.5));auto scope=bind_arguments(a,Signature({{"duration",V::missing()},{"interval",V(0.1)}},"","",{}),{});
    assert(scope->get("duration").numeric()==1.5 && scope->get("interval").numeric()==0.1);
    auto child=std::make_shared<Scope>(scope);child->set_nonlocal("duration",V(0.25));assert(scope->get("duration").numeric()==0.25);
    V seq=V::list({V(1),V(2),V(3)});assert(item(seq,V(-1)).integral()==3);
    assert(length(item(seq,V::slice(V(1),V{},V{})))==2);
    auto image=std::make_shared<Array>(std::vector<int>{2,3},"uint8");for(size_t i=0;i<6;++i)image->number_put(i,i%3==0?255:0);
    auto whites=array(compare_value("==",image->value(),V(255)));assert(whites->number_at(0)==1 && whites->number_at(1)==0);
    const auto columns=array(whites->reduce("sum",V(0)));assert(columns->number_at(0)==2 && columns->number_at(1)==0);
    auto copied=image->copy();copied->put(V::tuple({V(0),V::slice(V(0),V(2),V{})}),V(0));assert(image->number_at(0)==255 && copied->number_at(0)==0);
    assert(DecimalValue::quantized("0.145",2,"ROUND_HALF_UP")=="0.15");
    assert(DecimalValue::quantized("0.14001",2,"ROUND_UP")=="0.15");
    assert(DecimalValue::quantized("0.14999",2,"ROUND_DOWN")=="0.14");
    assert(DecimalValue::quantized("0.999",2,"ROUND_HALF_UP")=="1.00");
    std::cout<<"official_value_semantics passed tuple_truth=1 keyword_binding=1 nonlocal_callback=1 array_slice_alias=1 mask_profile=1 decimal_rounding=1 game_input_sent=0\n";
}
