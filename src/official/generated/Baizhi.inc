// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Baizhi.py
// SHA256 8c4064f5922fb05b8bbfffbc91b133a5aac5e37f27a4ae62bd9d2bf5adf273cb
void OfficialCharacter::install_Baizhi(){
auto scope=std::make_shared<Scope>();
// Official method Baizhi.do_perform, lines 6-13
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
    // Baizhi.py:7
    if(attr(self_value(),"has_intro").truth()){
        // Baizhi.py:8
        ([&]()->V{auto fn_3=attr(attr(self_value(),"logger"),"debug");Args args_2;args_2.pos(V("has_intro wait click 1.2 sec"));return invoke(fn_3,args_2);}());
        // Baizhi.py:9
        ([&]()->V{auto fn_5=attr(self_value(),"continues_normal_attack");Args args_4;args_4.pos(V(1.2));args_4.kw("click_resonance_if_ready_and_return",V(true));return invoke(fn_5,args_4);}());
    }
    // Baizhi.py:10
    ([&]()->V{auto fn_7=attr(self_value(),"click_liberation");Args args_6;args_6.kw("con_less_than",V(1LL));return invoke(fn_7,args_6);}());
    // Baizhi.py:11
    ([&]()->V{auto fn_9=attr(self_value(),"click_resonance");Args args_8;return invoke(fn_9,args_8);}());
    // Baizhi.py:12
    ([&]()->V{auto fn_11=attr(self_value(),"click_echo");Args args_10;return invoke(fn_11,args_10);}());
    // Baizhi.py:13
    ([&]()->V{auto fn_13=attr(self_value(),"switch_next_char");Args args_12;return invoke(fn_13,args_12);}());
return V{};
}),false);
}
