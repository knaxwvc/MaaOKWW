// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/Mortefi.py
// SHA256 ae95f94ab840573912f9fbf9712fa141d845c499a8b369154ee0a999c0f6de9f
void OfficialCharacter::install_Mortefi(){
auto scope=std::make_shared<Scope>();
// Official method Mortefi.do_perform, lines 5-12
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("liberated",V::missing());
    // Mortefi.py:6
    ([&]()->V{auto fn_3=attr(self_value(),"wait_down");Args args_2;return invoke(fn_3,args_2);}());
    // Mortefi.py:7
    {V value_4=([&]()->V{auto fn_6=attr(self_value(),"click_liberation");Args args_5;return invoke(fn_6,args_5);}());scope_1->set("liberated",value_4);}
    // Mortefi.py:8
    ([&]()->V{auto fn_8=attr(self_value(),"click_resonance");Args args_7;return invoke(fn_8,args_7);}());
    // Mortefi.py:9
    ([&]()->V{auto fn_10=attr(self_value(),"click_echo");Args args_9;return invoke(fn_10,args_9);}());
    // Mortefi.py:10
    if(unary("not",scope_1->get("liberated")).truth()){
        // Mortefi.py:11
        ([&]()->V{auto fn_12=attr(self_value(),"click_liberation");Args args_11;args_11.kw("wait_if_cd_ready",V(1LL));return invoke(fn_12,args_11);}());
    }
    // Mortefi.py:12
    ([&]()->V{auto fn_14=attr(self_value(),"switch_next_char");Args args_13;return invoke(fn_14,args_13);}());
return V{};
}),false);
}
