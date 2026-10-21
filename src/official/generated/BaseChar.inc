// Generated from official 0b37b5b79e771297536ff1155db1c23131297558/src/char/BaseChar.py
// SHA256 6d7e3d6af0da5d8642c3262e1353b84853cd881506f5095c49b832cda446dbab
void OfficialCharacter::install_BaseChar(){
auto scope=std::make_shared<Scope>();
set_global("SKILL_TIME_OUT",V(15LL));
set_global("CharType",make_namespace("CharType",{{"MAIN_DPS",V("MainDps")},{"SUB_DPS",V("SubDps")},{"HEALER",V("Healer")}}));
set_global("SwitchPriority",make_namespace("SwitchPriority",{{"NO",V(0LL)},{"LOW",V(100LL)},{"NORMAL",V(200LL)},{"HIGH",V(300LL)},{"MUST",V(400LL)}}));
set_global("Elements",make_namespace("Elements",{{"SPECTRO",V(0LL)},{"ELECTRIC",V(1LL)},{"FIRE",V(2LL)},{"ICE",V(3LL)},{"WIND",V(4LL)},{"HAVOC",V(5LL)}}));
set_global("Role",global("CharType","BaseChar"));
set_global("role_values",([&]()->V{auto comprehension_scope_1=std::make_shared<Scope>(scope);V result_2=V::list();auto iterator_3=official::iterate(global("CharType","BaseChar"));V value_4;while(iterator_3.next(value_4)){comprehension_scope_1->set("role",value_4);append(result_2,comprehension_scope_1->get("role"));}return result_2;}()));
set_global("DEFAULT_BUFF_TIME_BY_TYPE",([&]()->V{V dictionary_5=V::dict();set_item(dictionary_5,attr(global("CharType","BaseChar"),"MAIN_DPS"),V(14LL));set_item(dictionary_5,attr(global("CharType","BaseChar"),"SUB_DPS"),V(14LL));set_item(dictionary_5,attr(global("CharType","BaseChar"),"HEALER"),V(28LL));return dictionary_5;}()));
// Official module function get_default_buff_time, lines 48-49
set_global("get_default_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"char_type",attr(global("CharType","BaseChar"),"MAIN_DPS")}},"","",{})](const Args& official_args)->V{
auto scope_6=bind_arguments(official_args,signature,captured);
    // BaseChar.py:49
    return ([&]()->V{auto fn_8=attr(global("DEFAULT_BUFF_TIME_BY_TYPE","BaseChar"),"get");Args args_7;args_7.pos(([&]()->V{auto fn_10=global("CharType","BaseChar");Args args_9;args_9.pos(([&]()->V{V operand_11;operand_11=scope_6->get("char_type");if(operand_11.truth())return operand_11;return attr(global("CharType","BaseChar"),"MAIN_DPS");}()));return invoke(fn_10,args_9);}()));args_7.pos(V(0LL));return invoke(fn_8,args_7);}());
return V{};
}));
set_global("forte_white_color",([&]()->V{V dictionary_12=V::dict();set_item(dictionary_12,V("r"),V::tuple({V(244LL),V(255LL)}));set_item(dictionary_12,V("g"),V::tuple({V(246LL),V(255LL)}));set_item(dictionary_12,V("b"),V::tuple({V(250LL),V(255LL)}));return dictionary_12;}()));
set_global("dot_color",([&]()->V{V dictionary_13=V::dict();set_item(dictionary_13,V("r"),V::tuple({V(195LL),V(255LL)}));set_item(dictionary_13,V("g"),V::tuple({V(195LL),V(255LL)}));set_item(dictionary_13,V("b"),V::tuple({V(195LL),V(255LL)}));return dictionary_13;}()));
set_class_attribute("HEALER_FULL_CON_SWITCH_LOCKOUT",V(16.0));
// Official method BaseChar.__init__, lines 68-112
register_method("__init__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"task",V::missing()},{"index",V::missing()},{"char_name",V{}},{"confidence",V(1LL)},{"ring_index",unary("-",V(1LL))},{"char_type",attr(global("CharType","BaseChar"),"MAIN_DPS")},{"buff_time",V{}}},"","",{})](const Args& official_args)->V{
auto scope_14=bind_arguments(official_args,signature,captured);
    // BaseChar.py:77
    {V value_15=V(0.01);set_attr(self_value(),"white_off_threshold",value_15);}
    // BaseChar.py:78
    {V value_16=scope_14->get("task");set_attr(self_value(),"task",value_16);}
    // BaseChar.py:79
    {V value_17=V(0LL);set_attr(self_value(),"sleep_adjust",value_17);}
    // BaseChar.py:80
    {V value_18=scope_14->get("char_name");set_attr(self_value(),"char_name",value_18);}
    // BaseChar.py:81
    {V value_19=scope_14->get("index");set_attr(self_value(),"index",value_19);}
    // BaseChar.py:82
    {V value_20=scope_14->get("ring_index");set_attr(self_value(),"ring_index",value_20);}
    // BaseChar.py:83
    {V value_21=unary("-",V(1LL));set_attr(self_value(),"last_switch_time",value_21);}
    // BaseChar.py:84
    {V value_22=unary("-",V(1LL));set_attr(self_value(),"last_switch_in_time",value_22);}
    // BaseChar.py:85
    {V value_23=unary("-",V(1LL));set_attr(self_value(),"last_full_con_switch_time",value_23);}
    // BaseChar.py:86
    {V value_24=unary("-",V(1LL));set_attr(self_value(),"last_res",value_24);}
    // BaseChar.py:87
    {V value_25=unary("-",V(1LL));set_attr(self_value(),"last_echo",value_25);}
    // BaseChar.py:88
    {V value_26=unary("-",V(1LL));set_attr(self_value(),"last_liberation",value_26);}
    // BaseChar.py:89
    {V value_27=V(false);set_attr(self_value(),"has_intro",value_27);}
    // BaseChar.py:90
    {V value_28=V(false);set_attr(self_value(),"has_sub_dps_intro",value_28);}
    // BaseChar.py:91
    {V value_29=V(false);set_attr(self_value(),"is_current_char",value_29);}
    // BaseChar.py:92
    {V value_30=V(false);set_attr(self_value(),"_liberation_available",value_30);}
    // BaseChar.py:93
    {V value_31=V(false);set_attr(self_value(),"_resonance_available",value_31);}
    // BaseChar.py:94
    {V value_32=V(false);set_attr(self_value(),"_echo_available",value_32);}
    // BaseChar.py:95
    {V value_33=V(0LL);set_attr(self_value(),"full_ring_area",value_33);}
    // BaseChar.py:96
    {V value_34=V(0LL);set_attr(self_value(),"last_perform",value_34);}
    // BaseChar.py:97
    {V value_35=V(0LL);set_attr(self_value(),"current_con",value_35);}
    // BaseChar.py:98
    {V value_36=V(false);set_attr(self_value(),"has_tool_box",value_36);}
    // BaseChar.py:99
    {V value_37=V(0.9);set_attr(self_value(),"intro_motion_freeze_duration",value_37);}
    // BaseChar.py:100
    {V value_38=unary("-",V(1LL));set_attr(self_value(),"last_outro_time",value_38);}
    // BaseChar.py:101
    {V value_39=scope_14->get("confidence");set_attr(self_value(),"confidence",value_39);}
    // BaseChar.py:102
    {V value_40=V(0LL);set_attr(self_value(),"_buff_time",value_40);}
    // BaseChar.py:103
    {V value_41=V(false);set_attr(self_value(),"_buff_time_configured",value_41);}
    // BaseChar.py:104
    ([&]()->V{auto fn_43=attr(self_value(),"set_char_type");Args args_42;args_42.pos(scope_14->get("char_type"));return invoke(fn_43,args_42);}());
    // BaseChar.py:105
    ([&]()->V{auto fn_45=attr(self_value(),"set_buff_time");Args args_44;args_44.pos(scope_14->get("buff_time"));return invoke(fn_45,args_44);}());
    // BaseChar.py:106
    {V value_46=unary("-",V(1LL));set_attr(self_value(),"last_buff_time",value_46);}
    // BaseChar.py:107
    {V value_47=([&]()->V{auto fn_49=attr(global("Logger","BaseChar"),"get_logger");Args args_48;args_48.pos(attr(self_value(),"name"));return invoke(fn_49,args_48);}());set_attr(self_value(),"logger",value_47);}
    // BaseChar.py:108
    {V value_50=unary("not",attr(self_value(),"is_healer"));set_attr(self_value(),"check_f_on_switch",value_50);}
    // BaseChar.py:109
    {V value_51=V(0.0);set_attr(self_value(),"cycle_start_time",value_51);}
    // BaseChar.py:110
    {V value_52=V(1.1);set_attr(self_value(),"cycle_time_out",value_52);}
    // BaseChar.py:111
    {V value_53=V(1.2);set_attr(self_value(),"cycle_intro_time",value_53);}
    // BaseChar.py:112
    {V value_54=V(false);set_attr(self_value(),"target_box_short_combat_check",value_54);}
return V{};
}),true);
// Official method BaseChar.set_char_type, lines 114-118
register_method("set_char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"char_type",attr(global("CharType","BaseChar"),"MAIN_DPS")}},"","",{})](const Args& official_args)->V{
auto scope_55=bind_arguments(official_args,signature,captured);
    // BaseChar.py:116
    {V value_56=([&]()->V{auto fn_58=global("CharType","BaseChar");Args args_57;args_57.pos(([&]()->V{V operand_59;operand_59=scope_55->get("char_type");if(operand_59.truth())return operand_59;return attr(global("CharType","BaseChar"),"MAIN_DPS");}()));return invoke(fn_58,args_57);}());set_attr(self_value(),"_char_type",value_56);}
    // BaseChar.py:117
    if(unary("not",attr(self_value(),"_buff_time_configured")).truth()){
        // BaseChar.py:118
        {V value_60=([&]()->V{auto fn_62=global("get_default_buff_time","BaseChar");Args args_61;args_61.pos(attr(self_value(),"char_type"));return invoke(fn_62,args_61);}());set_attr(self_value(),"_buff_time",value_60);}
    }
return V{};
}),true);
// Official method BaseChar.get_char_type, lines 120-121
register_method("get_char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_63=bind_arguments(official_args,signature,captured);
    // BaseChar.py:121
    return attr(self_value(),"_char_type");
return V{};
}),true);
// Official method BaseChar.char_type, lines 124-125
register_method("@get:char_type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_64=bind_arguments(official_args,signature,captured);
    // BaseChar.py:125
    return ([&]()->V{auto fn_66=attr(self_value(),"get_char_type");Args args_65;return invoke(fn_66,args_65);}());
return V{};
}),true);
// Official method BaseChar.set_buff_time, lines 127-129
register_method("set_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"buff_time",V{}}},"","",{})](const Args& official_args)->V{
auto scope_67=bind_arguments(official_args,signature,captured);
    // BaseChar.py:128
    {V value_68=([&]()->V{V compare_69=scope_67->get("buff_time");V compare_70;V comparison_result_71;compare_70=V{};comparison_result_71=compare_value("is not",compare_69,compare_70);return comparison_result_71;}());set_attr(self_value(),"_buff_time_configured",value_68);}
    // BaseChar.py:129
    {V value_72=(([&]()->V{V compare_73=scope_67->get("buff_time");V compare_74;V comparison_result_75;compare_74=V{};comparison_result_75=compare_value("is",compare_73,compare_74);return comparison_result_75;}()).truth()?([&]()->V{auto fn_77=global("get_default_buff_time","BaseChar");Args args_76;args_76.pos(attr(self_value(),"char_type"));return invoke(fn_77,args_76);}()):([&]()->V{auto fn_79=global("float","BaseChar");Args args_78;args_78.pos(scope_67->get("buff_time"));return invoke(fn_79,args_78);}()));set_attr(self_value(),"_buff_time",value_72);}
return V{};
}),true);
// Official method BaseChar.type, lines 132-133
register_method("@get:type",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_80=bind_arguments(official_args,signature,captured);
    // BaseChar.py:133
    return attr(self_value(),"char_type");
return V{};
}),true);
// Official method BaseChar.is_healer, lines 136-137
register_method("@get:is_healer",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_81=bind_arguments(official_args,signature,captured);
    // BaseChar.py:137
    return ([&]()->V{V compare_82=attr(self_value(),"char_type");V compare_83;V comparison_result_84;compare_83=attr(global("CharType","BaseChar"),"HEALER");comparison_result_84=compare_value("==",compare_82,compare_83);return comparison_result_84;}());
return V{};
}),true);
// Official method BaseChar.is_main_dps, lines 140-141
register_method("@get:is_main_dps",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_85=bind_arguments(official_args,signature,captured);
    // BaseChar.py:141
    return ([&]()->V{V compare_86=attr(self_value(),"char_type");V compare_87;V comparison_result_88;compare_87=attr(global("CharType","BaseChar"),"MAIN_DPS");comparison_result_88=compare_value("==",compare_86,compare_87);return comparison_result_88;}());
return V{};
}),true);
// Official method BaseChar.is_sub_dps, lines 144-145
register_method("@get:is_sub_dps",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_89=bind_arguments(official_args,signature,captured);
    // BaseChar.py:145
    return ([&]()->V{V compare_90=attr(self_value(),"char_type");V compare_91;V comparison_result_92;compare_91=attr(global("CharType","BaseChar"),"SUB_DPS");comparison_result_92=compare_value("==",compare_90,compare_91);return comparison_result_92;}());
return V{};
}),true);
// Official method BaseChar.get_buff_time, lines 147-148
register_method("get_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_93=bind_arguments(official_args,signature,captured);
    // BaseChar.py:148
    return attr(self_value(),"_buff_time");
return V{};
}),true);
// Official method BaseChar.buff_time, lines 151-152
register_method("@get:buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_94=bind_arguments(official_args,signature,captured);
    // BaseChar.py:152
    return ([&]()->V{auto fn_96=attr(self_value(),"get_buff_time");Args args_95;return invoke(fn_96,args_95);}());
return V{};
}),true);
// Official method BaseChar.has_buff, lines 154-156
register_method("has_buff",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_97=bind_arguments(official_args,signature,captured);
    // BaseChar.py:155
    return ([&]()->V{V operand_98;operand_98=([&]()->V{V compare_99=attr(self_value(),"buff_time");V compare_100;V comparison_result_101;compare_100=V(0LL);comparison_result_101=compare_value(">",compare_99,compare_100);return comparison_result_101;}());if(!operand_98.truth())return operand_98;operand_98=([&]()->V{V compare_102=attr(self_value(),"last_buff_time");V compare_103;V comparison_result_104;compare_103=V(0LL);comparison_result_104=compare_value(">",compare_102,compare_103);return comparison_result_104;}());if(!operand_98.truth())return operand_98;return ([&]()->V{V compare_105=([&]()->V{auto fn_108=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_107;args_107.pos(attr(self_value(),"last_buff_time"));return invoke(fn_108,args_107);}());V compare_106;V comparison_result_109;compare_106=attr(self_value(),"buff_time");comparison_result_109=compare_value("<",compare_105,compare_106);return comparison_result_109;}());}());
return V{};
}),true);
// Official method BaseChar.has_all_buff, lines 158-163
register_method("has_all_buff",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_110=bind_arguments(official_args,signature,captured);
scope_110->set("char",V::missing());
scope_110->set("other_chars",V::missing());
    // BaseChar.py:160
    if(unary("not",attr(self_value(),"has_intro")).truth()){
        // BaseChar.py:161
        return V(false);
    }
    // BaseChar.py:162
    {V value_111=([&]()->V{auto comprehension_scope_112=std::make_shared<Scope>(scope_110);V result_113=V::list();auto iterator_114=official::iterate(([&]()->V{auto fn_117=global("getattr","BaseChar");Args args_116;args_116.pos(attr(self_value(),"task"));args_116.pos(V("chars"));args_116.pos(V::list({}));return invoke(fn_117,args_116);}()));V value_115;while(iterator_114.next(value_115)){comprehension_scope_112->set("char",value_115);if(!([&]()->V{V operand_118;operand_118=comprehension_scope_112->get("char");if(!operand_118.truth())return operand_118;return ([&]()->V{V compare_119=comprehension_scope_112->get("char");V compare_120;V comparison_result_121;compare_120=self_value();comparison_result_121=compare_value("is not",compare_119,compare_120);return comparison_result_121;}());}()).truth())continue;append(result_113,comprehension_scope_112->get("char"));}return result_113;}());scope_110->set("other_chars",value_111);}
    // BaseChar.py:163
    return ([&]()->V{V operand_122;operand_122=([&]()->V{V compare_123=([&]()->V{auto fn_126=global("len","BaseChar");Args args_125;args_125.pos(scope_110->get("other_chars"));return invoke(fn_126,args_125);}());V compare_124;V comparison_result_127;compare_124=V(2LL);comparison_result_127=compare_value("==",compare_123,compare_124);return comparison_result_127;}());if(!operand_122.truth())return operand_122;return ([&]()->V{auto generator_scope_128=std::make_shared<Scope>(scope_110);auto iterator_135=official::iterate(generator_scope_128->get("other_chars"));V value_136;while(iterator_135.next(value_136)){generator_scope_128->set("char",value_136);if(!([&]()->V{V operand_129;operand_129=([&]()->V{V compare_130=attr(generator_scope_128->get("char"),"buff_time");V compare_131;V comparison_result_132;compare_131=V(0LL);comparison_result_132=compare_value(">",compare_130,compare_131);return comparison_result_132;}());if(!operand_129.truth())return operand_129;return ([&]()->V{auto fn_134=attr(generator_scope_128->get("char"),"has_buff");Args args_133;return invoke(fn_134,args_133);}());}()).truth())return V(false);}return V(true);}());}());
return V{};
}),true);
// Official method BaseChar.cycle, lines 165-174
register_method("cycle",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_137=bind_arguments(official_args,signature,captured);
    // BaseChar.py:166
    ([&]()->V{auto fn_139=attr(self_value(),"cycle_start");Args args_138;return invoke(fn_139,args_138);}());
    // BaseChar.py:167
        while(([&]()->V{V compare_144=([&]()->V{auto fn_147=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_146;args_146.pos(attr(self_value(),"cycle_start_time"));return invoke(fn_147,args_146);}());V compare_145;V comparison_result_148;compare_145=([&]()->V{V left_149=attr(self_value(),"cycle_time_out");V right_150=attr(self_value(),"cycle_intro_time");return official::binary("+",left_149,right_150);}());comparison_result_148=compare_value("<",compare_144,compare_145);return comparison_result_148;}()).truth()){
        // BaseChar.py:169
        if(([&]()->V{auto fn_141=attr(self_value(),"do_cycle");Args args_140;return invoke(fn_141,args_140);}()).truth()){
            // BaseChar.py:170
            ([&]()->V{auto fn_143=attr(self_value(),"cycle_sleep");Args args_142;return invoke(fn_143,args_142);}());
            // BaseChar.py:171
            continue;
        }else{
            // BaseChar.py:173
            break;
        }
    }
    // BaseChar.py:174
    ([&]()->V{auto fn_152=attr(self_value(),"switch_next_char");Args args_151;return invoke(fn_152,args_151);}());
return V{};
}),true);
// Official method BaseChar.do_cycle, lines 176-177
register_method("do_cycle",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_153=bind_arguments(official_args,signature,captured);
    // BaseChar.py:177
    return V{};
return V{};
}),true);
// Official method BaseChar.cycle_start, lines 179-180
register_method("cycle_start",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_154=bind_arguments(official_args,signature,captured);
    // BaseChar.py:180
    {V value_155=([&]()->V{auto fn_157=attr(global("time","BaseChar"),"time");Args args_156;return invoke(fn_157,args_156);}());set_attr(self_value(),"cycle_start_time",value_155);}
return V{};
}),true);
// Official method BaseChar.cycle_sleep, lines 182-185
register_method("cycle_sleep",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_158=bind_arguments(official_args,signature,captured);
scope_158->set("to_sleep",V::missing());
    // BaseChar.py:183
    {V value_159=([&]()->V{V left_160=scope_158->get("duration");V right_161=([&]()->V{V left_162=([&]()->V{auto fn_165=attr(global("time","BaseChar"),"time");Args args_164;return invoke(fn_165,args_164);}());V right_163=attr(self_value(),"cycle_start_time");return official::binary("-",left_162,right_163);}());return official::binary("-",left_160,right_161);}());scope_158->set("to_sleep",value_159);}
    // BaseChar.py:184
    ([&]()->V{auto fn_167=attr(attr(self_value(),"task"),"check_f_break");Args args_166;return invoke(fn_167,args_166);}());
    // BaseChar.py:185
    ([&]()->V{auto fn_169=attr(self_value(),"sleep");Args args_168;args_168.pos(scope_158->get("to_sleep"));return invoke(fn_169,args_168);}());
return V{};
}),true);
// Official method BaseChar.flying_based_on_resonance, lines 187-189
register_method("flying_based_on_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_170=bind_arguments(official_args,signature,captured);
    // BaseChar.py:188
    if(([&]()->V{V operand_171;operand_171=unary("not",([&]()->V{auto fn_173=attr(self_value(),"has_cd");Args args_172;args_172.pos(V("resonance"));return invoke(fn_173,args_172);}()));if(!operand_171.truth())return operand_171;return unary("not",([&]()->V{auto fn_175=attr(attr(self_value(),"task"),"box_highlighted");Args args_174;args_174.pos(V("resonance"));return invoke(fn_175,args_174);}()));}()).truth()){
        // BaseChar.py:189
        return V(true);
    }
return V{};
}),true);
// Official method BaseChar.skip_combat_check, lines 191-197
register_method("skip_combat_check",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_176=bind_arguments(official_args,signature,captured);
    // BaseChar.py:197
    return V(false);
return V{};
}),true);
// Official method BaseChar.use_tool_box, lines 199-203
register_method("use_tool_box",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_177=bind_arguments(official_args,signature,captured);
    // BaseChar.py:201
    if(attr(self_value(),"has_tool_box").truth()){
        // BaseChar.py:202
        ([&]()->V{auto fn_179=attr(attr(self_value(),"task"),"send_key");Args args_178;args_178.pos(item(attr(attr(self_value(),"task"),"key_config"),V("Tool Key")));return invoke(fn_179,args_178);}());
        // BaseChar.py:203
        {V value_180=V(false);set_attr(self_value(),"has_tool_box",value_180);}
    }
return V{};
}),true);
// Official method BaseChar.name, lines 206-212
register_method("@get:name",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_181=bind_arguments(official_args,signature,captured);
    // BaseChar.py:212
    return V(std::string{}+format_value(attr(attr(self_value(),"__class__"),"__name__"),"",-1));
return V{};
}),true);
// Official method BaseChar.__eq__, lines 214-218
register_method("__eq__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"other",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_182=bind_arguments(official_args,signature,captured);
    // BaseChar.py:216
    if(([&]()->V{auto fn_184=global("isinstance","BaseChar");Args args_183;args_183.pos(scope_182->get("other"));args_183.pos(global("BaseChar","BaseChar"));return invoke(fn_184,args_183);}()).truth()){
        // BaseChar.py:217
        return ([&]()->V{V operand_185;operand_185=([&]()->V{V compare_186=attr(self_value(),"name");V compare_187;V comparison_result_188;compare_187=attr(scope_182->get("other"),"name");comparison_result_188=compare_value("==",compare_186,compare_187);return comparison_result_188;}());if(!operand_185.truth())return operand_185;return ([&]()->V{V compare_189=attr(self_value(),"index");V compare_190;V comparison_result_191;compare_190=attr(scope_182->get("other"),"index");comparison_result_191=compare_value("==",compare_189,compare_190);return comparison_result_191;}());}());
    }
    // BaseChar.py:218
    return V(false);
return V{};
}),true);
// Official method BaseChar.perform, lines 220-229
register_method("perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_192=bind_arguments(official_args,signature,captured);
    // BaseChar.py:227
    {V value_193=([&]()->V{auto fn_195=attr(global("time","BaseChar"),"time");Args args_194;return invoke(fn_195,args_194);}());set_attr(self_value(),"last_perform",value_193);}
    // BaseChar.py:228
    ([&]()->V{auto fn_197=attr(self_value(),"do_perform");Args args_196;return invoke(fn_197,args_196);}());
    // BaseChar.py:229
    ([&]()->V{auto fn_199=attr(attr(self_value(),"logger"),"debug");Args args_198;args_198.pos(V(std::string{}+"set current char false "+format_value(attr(self_value(),"index"),"",-1)));return invoke(fn_199,args_198);}());
return V{};
}),true);
// Official method BaseChar.wait_down, lines 231-245
register_method("wait_down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"click",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_200=bind_arguments(official_args,signature,captured);
scope_200->set("start",V::missing());
    // BaseChar.py:233
    if(([&]()->V{V operand_201;operand_201=unary("not",attr(attr(self_value(),"task"),"has_lavitator"));if(!operand_201.truth())return operand_201;return attr(self_value(),"has_intro");}()).truth()){
        // BaseChar.py:234
        if(scope_200->get("click").truth()){
            // BaseChar.py:235
            ([&]()->V{auto fn_203=attr(self_value(),"continues_normal_attack");Args args_202;args_202.pos(attr(self_value(),"intro_motion_freeze_duration"));return invoke(fn_203,args_202);}());
        }else{
            // BaseChar.py:237
            ([&]()->V{auto fn_205=attr(self_value(),"sleep");Args args_204;args_204.pos(attr(self_value(),"intro_motion_freeze_duration"));return invoke(fn_205,args_204);}());
        }
    }else{
        // BaseChar.py:239
        {V value_206=([&]()->V{auto fn_208=attr(global("time","BaseChar"),"time");Args args_207;return invoke(fn_208,args_207);}());scope_200->set("start",value_206);}
        // BaseChar.py:240
                while(([&]()->V{V operand_215;operand_215=([&]()->V{auto fn_217=attr(self_value(),"flying");Args args_216;return invoke(fn_217,args_216);}());if(!operand_215.truth())return operand_215;return ([&]()->V{V compare_218=([&]()->V{V left_220=([&]()->V{auto fn_223=attr(global("time","BaseChar"),"time");Args args_222;return invoke(fn_223,args_222);}());V right_221=scope_200->get("start");return official::binary("-",left_220,right_221);}());V compare_219;V comparison_result_224;compare_219=V(2.5);comparison_result_224=compare_value("<",compare_218,compare_219);return comparison_result_224;}());}()).truth()){
            // BaseChar.py:241
            if(scope_200->get("click").truth()){
                // BaseChar.py:242
                ([&]()->V{auto fn_210=attr(attr(self_value(),"task"),"click");Args args_209;args_209.kw("interval",V(0.2));return invoke(fn_210,args_209);}());
            }else{
                // BaseChar.py:244
                ([&]()->V{auto fn_212=attr(self_value(),"sleep");Args args_211;args_211.pos(V(0.2));return invoke(fn_212,args_211);}());
            }
            // BaseChar.py:245
            ([&]()->V{auto fn_214=attr(attr(self_value(),"task"),"next_frame");Args args_213;return invoke(fn_214,args_213);}());
        }
    }
return V{};
}),true);
// Official method BaseChar.wait_intro, lines 248-256
register_method("wait_intro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"time_out",V(1.2)},{"click",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_225=bind_arguments(official_args,signature,captured);
    // BaseChar.py:255
    if(attr(self_value(),"has_intro").truth()){
        // BaseChar.py:256
        ([&]()->V{auto fn_227=attr(attr(self_value(),"task"),"wait_until");Args args_226;args_226.pos(attr(self_value(),"down"));args_226.kw("post_action",(scope_225->get("click").truth()?attr(self_value(),"click_with_interval"):V{}));args_226.kw("time_out",scope_225->get("time_out"));return invoke(fn_227,args_226);}());
    }
return V{};
}),true);
// Official method BaseChar.down, lines 258-265
register_method("down",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_228=bind_arguments(official_args,signature,captured);
    // BaseChar.py:264
    return ([&]()->V{V operand_229;operand_229=([&]()->V{V operand_230;operand_230=([&]()->V{V compare_231=([&]()->V{auto fn_234=attr(self_value(),"current_resonance");Args args_233;return invoke(fn_234,args_233);}());V compare_232;V comparison_result_235;compare_232=V(0LL);comparison_result_235=compare_value(">",compare_231,compare_232);return comparison_result_235;}());if(!operand_230.truth())return operand_230;return unary("not",([&]()->V{auto fn_237=attr(self_value(),"has_cd");Args args_236;args_236.pos(V("resonance"));return invoke(fn_237,args_236);}()));}());if(operand_229.truth())return operand_229;return ([&]()->V{V operand_238;operand_238=([&]()->V{V compare_239=([&]()->V{auto fn_242=attr(self_value(),"current_liberation");Args args_241;return invoke(fn_242,args_241);}());V compare_240;V comparison_result_243;compare_240=V(0LL);comparison_result_243=compare_value(">",compare_239,compare_240);return comparison_result_243;}());if(!operand_238.truth())return operand_238;return unary("not",([&]()->V{auto fn_245=attr(self_value(),"has_cd");Args args_244;args_244.pos(V("liberation"));return invoke(fn_245,args_244);}()));}());}());
return V{};
}),true);
// Official method BaseChar.click_with_interval, lines 267-273
register_method("click_with_interval",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"interval",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_246=bind_arguments(official_args,signature,captured);
    // BaseChar.py:273
    ([&]()->V{auto fn_248=attr(self_value(),"click");Args args_247;args_247.kw("interval",scope_246->get("interval"));return invoke(fn_248,args_247);}());
return V{};
}),true);
// Official method BaseChar.click, lines 275-278
register_method("click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"args","kwargs",{})](const Args& official_args)->V{
auto scope_249=bind_arguments(official_args,signature,captured);
    // BaseChar.py:277
    {V value_250=V(0.01);set_item(scope_249->get("kwargs"),V("down_time"),value_250);}
    // BaseChar.py:278
    ([&]()->V{auto fn_252=attr(attr(self_value(),"task"),"click");Args args_251;args_251.spread(scope_249->get("args"));args_251.spread_keywords(scope_249->get("kwargs"));return invoke(fn_252,args_251);}());
return V{};
}),true);
// Official method BaseChar.do_perform, lines 280-293
register_method("do_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_253=bind_arguments(official_args,signature,captured);
    // BaseChar.py:288
    ([&]()->V{auto fn_255=attr(self_value(),"wait_intro");Args args_254;args_254.pos(V(1.2));return invoke(fn_255,args_254);}());
    // BaseChar.py:289
    ([&]()->V{auto fn_257=attr(self_value(),"click_echo");Args args_256;args_256.kw("time_out",V(0LL));return invoke(fn_257,args_256);}());
    // BaseChar.py:290
    ([&]()->V{auto fn_259=attr(self_value(),"click_liberation");Args args_258;return invoke(fn_259,args_258);}());
    // BaseChar.py:291
    if(unary("not",item(([&]()->V{auto fn_261=attr(self_value(),"click_resonance");Args args_260;return invoke(fn_261,args_260);}()),V(0LL))).truth()){
        // BaseChar.py:292
        ([&]()->V{auto fn_263=attr(self_value(),"heavy_click_forte");Args args_262;args_262.pos(attr(self_value(),"is_mouse_forte_full"));return invoke(fn_263,args_262);}());
    }
    // BaseChar.py:293
    ([&]()->V{auto fn_265=attr(self_value(),"switch_next_char");Args args_264;return invoke(fn_265,args_264);}());
return V{};
}),true);
// Official method BaseChar.has_cd, lines 295-304
register_method("has_cd",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"box_name",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_266=bind_arguments(official_args,signature,captured);
    // BaseChar.py:304
    return ([&]()->V{auto fn_268=attr(attr(self_value(),"task"),"has_cd");Args args_267;args_267.pos(scope_266->get("box_name"));return invoke(fn_268,args_267);}());
return V{};
}),true);
// Official method BaseChar.is_available, lines 306-316
register_method("is_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"percent",V::missing()},{"box_name",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_269=bind_arguments(official_args,signature,captured);
    // BaseChar.py:316
    return ([&]()->V{V operand_270;operand_270=([&]()->V{V compare_271=scope_269->get("percent");V compare_272;V comparison_result_273;compare_272=V(0LL);comparison_result_273=compare_value("==",compare_271,compare_272);return comparison_result_273;}());if(operand_270.truth())return operand_270;return unary("not",([&]()->V{auto fn_275=attr(self_value(),"has_cd");Args args_274;args_274.pos(scope_269->get("box_name"));return invoke(fn_275,args_274);}()));}());
return V{};
}),true);
// Official method BaseChar.switch_out, lines 318-331
register_method("switch_out",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_276=bind_arguments(official_args,signature,captured);
scope_276->set("switched_with_full_con",V::missing());
    // BaseChar.py:320
    {V value_277=([&]()->V{auto fn_279=attr(global("time","BaseChar"),"time");Args args_278;return invoke(fn_279,args_278);}());set_attr(self_value(),"last_switch_time",value_277);}
    // BaseChar.py:321
    {V value_280=([&]()->V{V operand_281;operand_281=scope_276->get("con_full");if(operand_281.truth())return operand_281;return ([&]()->V{V compare_282=attr(self_value(),"current_con");V compare_283;V comparison_result_284;compare_283=V(1LL);comparison_result_284=compare_value("==",compare_282,compare_283);return comparison_result_284;}());}());scope_276->set("switched_with_full_con",value_280);}
    // BaseChar.py:322
    if(([&]()->V{V operand_285;operand_285=attr(self_value(),"is_healer");if(!operand_285.truth())return operand_285;return scope_276->get("switched_with_full_con");}()).truth()){
        // BaseChar.py:323
        {V value_286=attr(self_value(),"last_switch_time");set_attr(self_value(),"last_full_con_switch_time",value_286);}
    }
    // BaseChar.py:324
    {V value_287=V(false);set_attr(self_value(),"is_current_char",value_287);}
    // BaseChar.py:325
    {V value_288=V(false);set_attr(self_value(),"has_intro",value_288);}
    // BaseChar.py:326
    {V value_289=V(false);set_attr(self_value(),"has_sub_dps_intro",value_289);}
    // BaseChar.py:327
    if(scope_276->get("switched_with_full_con").truth()){
        // BaseChar.py:328
        if(([&]()->V{V compare_290=attr(self_value(),"buff_time");V compare_291;V comparison_result_292;compare_291=V(0LL);comparison_result_292=compare_value(">",compare_290,compare_291);return comparison_result_292;}()).truth()){
            // BaseChar.py:329
            {V value_293=attr(self_value(),"last_switch_time");set_attr(self_value(),"last_buff_time",value_293);}
        }
        // BaseChar.py:330
        ([&]()->V{auto fn_295=attr(attr(self_value(),"logger"),"info");Args args_294;args_294.pos(V(std::string{}+"switch_out at full con set current_con to 0"));return invoke(fn_295,args_294);}());
        // BaseChar.py:331
        {V value_296=V(0LL);set_attr(self_value(),"current_con",value_296);}
    }
return V{};
}),true);
// Official method BaseChar.__repr__, lines 333-335
register_method("__repr__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_297=bind_arguments(official_args,signature,captured);
    // BaseChar.py:335
    return attr(attr(self_value(),"__class__"),"__name__");
return V{};
}),true);
// Official method BaseChar.switch_next_char, lines 337-356
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"post_action",V{}},{"free_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_298=bind_arguments(official_args,signature,captured);
    // BaseChar.py:350
    ([&]()->V{auto fn_300=attr(self_value(),"is_forte_full");Args args_299;return invoke(fn_300,args_299);}());
    // BaseChar.py:351
    {V value_301=V(false);set_attr(self_value(),"has_intro",value_301);}
    // BaseChar.py:352
    {V value_302=V(false);set_attr(self_value(),"has_sub_dps_intro",value_302);}
    // BaseChar.py:353
    {V value_303=([&]()->V{auto fn_305=attr(self_value(),"liberation_available");Args args_304;return invoke(fn_305,args_304);}());set_attr(self_value(),"_liberation_available",value_303);}
    // BaseChar.py:354
    ([&]()->V{auto fn_307=attr(self_value(),"use_tool_box");Args args_306;return invoke(fn_307,args_306);}());
    // BaseChar.py:355
    ([&]()->V{auto fn_309=attr(attr(self_value(),"task"),"switch_next_char");Args args_308;args_308.pos(self_value());args_308.kw("post_action",scope_298->get("post_action"));args_308.kw("free_intro",scope_298->get("free_intro"));args_308.kw("target_low_con",scope_298->get("target_low_con"));return invoke(fn_309,args_308);}());
return V{};
}),true);
// Official method BaseChar.sleep, lines 358-365
register_method("sleep",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"sec",V::missing()},{"check_combat",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_310=bind_arguments(official_args,signature,captured);
scope_310->set("previous_skip_combat_check",V::missing());
    // BaseChar.py:359
    {V value_311=([&]()->V{auto fn_313=global("getattr","BaseChar");Args args_312;args_312.pos(attr(self_value(),"task"));args_312.pos(V("skip_combat_check"));args_312.pos(V(false));return invoke(fn_313,args_312);}());scope_310->set("previous_skip_combat_check",value_311);}
    // BaseChar.py:360
    if(unary("not",scope_310->get("check_combat")).truth()){
        // BaseChar.py:361
        {V value_314=V(true);set_attr(attr(self_value(),"task"),"skip_combat_check",value_314);}
    }
    // BaseChar.py:362
    {
    auto finally_315=on_scope_exit([&](){
        // BaseChar.py:365
        {V value_316=scope_310->get("previous_skip_combat_check");set_attr(attr(self_value(),"task"),"skip_combat_check",value_316);}
    });
        // BaseChar.py:363
        ([&]()->V{auto fn_318=attr(attr(self_value(),"task"),"sleep");Args args_317;args_317.pos(scope_310->get("sec"));return invoke(fn_318,args_317);}());
    }
return V{};
}),true);
// Official method BaseChar.alert_skill_failed, lines 367-370
register_method("alert_skill_failed",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_319=bind_arguments(official_args,signature,captured);
    // BaseChar.py:368
    ([&]()->V{auto fn_321=attr(attr(self_value(),"task"),"log_error");Args args_320;args_320.pos(V(std::string{}+"Click skill failed, check if the keybinding is correct in ok-ww settings!"));args_320.kw("notify",V(true));return invoke(fn_321,args_320);}());
    // BaseChar.py:370
    ([&]()->V{auto fn_323=attr(attr(self_value(),"task"),"screenshot");Args args_322;args_322.pos(V("click_resonance too long, breaking"));return invoke(fn_323,args_322);}());
return V{};
}),true);
// Official method BaseChar.click_resonance, lines 372-461
register_method("click_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"post_sleep",V(0LL)},{"has_animation",V(false)},{"send_click",V(true)},{"animation_min_duration",V(0LL)},{"check_cd",V(false)},{"time_out",V(0LL)},{"click_f",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_324=bind_arguments(official_args,signature,captured);
scope_324->set("animation_start",V::missing());
scope_324->set("clicked",V::missing());
scope_324->set("duration",V::missing());
scope_324->set("last_click",V::missing());
scope_324->set("last_f_click",V::missing());
scope_324->set("last_op",V::missing());
scope_324->set("now",V::missing());
scope_324->set("resonance_click_time",V::missing());
scope_324->set("start",V::missing());
scope_324->set("the_time_out",V::missing());
    // BaseChar.py:387
    {V value_325=V(false);scope_324->set("clicked",value_325);}
    // BaseChar.py:388
    ([&]()->V{auto fn_327=attr(attr(self_value(),"logger"),"debug");Args args_326;args_326.pos(V(std::string{}+"click_resonance start"));return invoke(fn_327,args_326);}());
    // BaseChar.py:389
    {V value_328=V(0LL);scope_324->set("last_click",value_328);}
    // BaseChar.py:390
    {V value_329=V("click");scope_324->set("last_op",value_329);}
    // BaseChar.py:391
    {V value_330=V(0LL);scope_324->set("resonance_click_time",value_330);}
    // BaseChar.py:392
    {V value_331=([&]()->V{auto fn_333=attr(global("time","BaseChar"),"time");Args args_332;return invoke(fn_333,args_332);}());scope_324->set("start",value_331);}
    // BaseChar.py:393
    {V value_334=V(0LL);scope_324->set("animation_start",value_334);}
    // BaseChar.py:394
    {V value_335=V(0LL);scope_324->set("last_f_click",value_335);}
    // BaseChar.py:395
    if(([&]()->V{V compare_336=scope_324->get("time_out");V compare_337;V comparison_result_338;compare_337=V(0LL);comparison_result_338=compare_value("==",compare_336,compare_337);return comparison_result_338;}()).truth()){
        // BaseChar.py:396
        {V value_339=global("SKILL_TIME_OUT","BaseChar");scope_324->set("the_time_out",value_339);}
    }else{
        // BaseChar.py:398
        {V value_340=scope_324->get("time_out");scope_324->set("the_time_out",value_340);}
    }
    // BaseChar.py:399
        while(V(true).truth()){
        // BaseChar.py:400
        if(([&]()->V{V compare_341=([&]()->V{V left_343=([&]()->V{auto fn_346=attr(global("time","BaseChar"),"time");Args args_345;return invoke(fn_346,args_345);}());V right_344=scope_324->get("start");return official::binary("-",left_343,right_344);}());V compare_342;V comparison_result_347;compare_342=scope_324->get("the_time_out");comparison_result_347=compare_value(">",compare_341,compare_342);return comparison_result_347;}()).truth()){
            // BaseChar.py:401
            {V value_348=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_348);}
            // BaseChar.py:402
            if(([&]()->V{V compare_349=scope_324->get("the_time_out");V compare_350;V comparison_result_351;compare_350=V(0LL);comparison_result_351=compare_value("==",compare_349,compare_350);return comparison_result_351;}()).truth()){
                // BaseChar.py:403
                ([&]()->V{auto fn_353=attr(self_value(),"alert_skill_failed");Args args_352;return invoke(fn_353,args_352);}());
            }
            // BaseChar.py:404
            break;
        }else{
            // BaseChar.py:405
            if(([&]()->V{V operand_354;operand_354=attr(attr(self_value(),"task"),"in_liberation");if(!operand_354.truth())return operand_354;return ([&]()->V{V compare_355=([&]()->V{V left_357=([&]()->V{auto fn_360=attr(global("time","BaseChar"),"time");Args args_359;return invoke(fn_360,args_359);}());V right_358=scope_324->get("start");return official::binary("-",left_357,right_358);}());V compare_356;V comparison_result_361;compare_356=V(6LL);comparison_result_361=compare_value(">",compare_355,compare_356);return comparison_result_361;}());}()).truth()){
                // BaseChar.py:406
                {V value_362=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_362);}
                // BaseChar.py:407
                break;
            }
        }
        // BaseChar.py:408
        if(scope_324->get("has_animation").truth()){
            // BaseChar.py:409
            if(unary("not",item(([&]()->V{auto fn_364=attr(attr(self_value(),"task"),"in_team");Args args_363;return invoke(fn_364,args_363);}()),V(0LL))).truth()){
                // BaseChar.py:410
                {V value_365=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_365);}
                // BaseChar.py:411
                {V value_366=([&]()->V{auto fn_368=attr(global("time","BaseChar"),"time");Args args_367;return invoke(fn_368,args_367);}());scope_324->set("now",value_366);}
                // BaseChar.py:412
                if(([&]()->V{V compare_369=scope_324->get("animation_start");V compare_370;V comparison_result_371;compare_370=V(0LL);comparison_result_371=compare_value("==",compare_369,compare_370);return comparison_result_371;}()).truth()){
                    // BaseChar.py:413
                    {V value_372=scope_324->get("now");scope_324->set("animation_start",value_372);}
                }
                // BaseChar.py:414
                {V value_373=global("SKILL_TIME_OUT","BaseChar");scope_324->set("the_time_out",value_373);}
                // BaseChar.py:415
                if(([&]()->V{V compare_374=([&]()->V{V left_376=scope_324->get("now");V right_377=scope_324->get("resonance_click_time");return official::binary("-",left_376,right_377);}());V compare_375;V comparison_result_378;compare_375=V(6LL);comparison_result_378=compare_value(">",compare_374,compare_375);return comparison_result_378;}()).truth()){
                    // BaseChar.py:416
                    {V value_379=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_379);}
                    // BaseChar.py:417
                    ([&]()->V{auto fn_381=attr(attr(self_value(),"logger"),"error");Args args_380;args_380.pos(V(std::string{}+"resonance animation too long, breaking"));return invoke(fn_381,args_380);}());
                }
                // BaseChar.py:418
                if(([&]()->V{V operand_382;operand_382=scope_324->get("click_f");if(!operand_382.truth())return operand_382;operand_382=([&]()->V{V compare_383=([&]()->V{V left_385=scope_324->get("now");V right_386=scope_324->get("animation_start");return official::binary("-",left_385,right_386);}());V compare_384;V comparison_result_387;compare_384=scope_324->get("animation_min_duration");comparison_result_387=compare_value(">=",compare_383,compare_384);return comparison_result_387;}());if(!operand_382.truth())return operand_382;return ([&]()->V{V compare_388=([&]()->V{V left_390=scope_324->get("now");V right_391=scope_324->get("last_f_click");return official::binary("-",left_390,right_391);}());V compare_389;V comparison_result_392;compare_389=V(0.1);comparison_result_392=compare_value(">=",compare_388,compare_389);return comparison_result_392;}());}()).truth()){
                    // BaseChar.py:420
                    ([&]()->V{auto fn_394=attr(attr(self_value(),"task"),"send_key");Args args_393;args_393.pos(V("f"));return invoke(fn_394,args_393);}());
                    // BaseChar.py:421
                    {V value_395=scope_324->get("now");scope_324->set("last_f_click",value_395);}
                }
                // BaseChar.py:422
                ([&]()->V{auto fn_397=attr(attr(self_value(),"task"),"next_frame");Args args_396;return invoke(fn_397,args_396);}());
                // BaseChar.py:423
                ([&]()->V{auto fn_399=attr(self_value(),"check_combat");Args args_398;return invoke(fn_399,args_398);}());
                // BaseChar.py:424
                continue;
            }else{
                // BaseChar.py:425
                if(attr(attr(self_value(),"task"),"in_liberation").truth()){
                    // BaseChar.py:426
                    {V value_400=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_400);}
                    // BaseChar.py:427
                    ([&]()->V{auto fn_402=attr(attr(self_value(),"logger"),"debug");Args args_401;args_401.pos(V(std::string{}+"click_resonance animated break"));return invoke(fn_402,args_401);}());
                    // BaseChar.py:428
                    break;
                }
            }
        }
        // BaseChar.py:430
        ([&]()->V{auto fn_404=attr(self_value(),"check_combat");Args args_403;return invoke(fn_404,args_403);}());
        // BaseChar.py:431
        {V value_405=([&]()->V{auto fn_407=attr(global("time","BaseChar"),"time");Args args_406;return invoke(fn_407,args_406);}());scope_324->set("now",value_405);}
        // BaseChar.py:432
        if(([&]()->V{V operand_408;operand_408=unary("not",([&]()->V{auto fn_410=attr(self_value(),"resonance_available");Args args_409;return invoke(fn_410,args_409);}()));if(!operand_408.truth())return operand_408;return ([&]()->V{V operand_411;operand_411=unary("not",scope_324->get("has_animation"));if(operand_411.truth())return operand_411;return ([&]()->V{V compare_412=([&]()->V{V left_414=scope_324->get("now");V right_415=scope_324->get("start");return official::binary("-",left_414,right_415);}());V compare_413;V comparison_result_416;compare_413=scope_324->get("animation_min_duration");comparison_result_416=compare_value(">",compare_412,compare_413);return comparison_result_416;}());}());}()).truth()){
            // BaseChar.py:434
            ([&]()->V{auto fn_418=attr(attr(self_value(),"logger"),"debug");Args args_417;args_417.pos(V(std::string{}+"click_resonance not available break"));return invoke(fn_418,args_417);}());
            // BaseChar.py:435
            break;
        }
        // BaseChar.py:436
        ([&]()->V{auto fn_420=attr(attr(self_value(),"logger"),"debug");Args args_419;args_419.pos(V(std::string{}+"click_resonance resonance_available click"));return invoke(fn_420,args_419);}());
        // BaseChar.py:438
        if(([&]()->V{V compare_421=([&]()->V{V left_423=scope_324->get("now");V right_424=scope_324->get("last_click");return official::binary("-",left_423,right_424);}());V compare_422;V comparison_result_425;compare_422=V(0.1);comparison_result_425=compare_value(">",compare_421,compare_422);return comparison_result_425;}()).truth()){
            // BaseChar.py:439
            if(([&]()->V{V operand_426;operand_426=scope_324->get("send_click");if(!operand_426.truth())return operand_426;return ([&]()->V{V compare_427=scope_324->get("last_op");V compare_428;V comparison_result_429;compare_428=V("resonance");comparison_result_429=compare_value("==",compare_427,compare_428);return comparison_result_429;}());}()).truth()){
                // BaseChar.py:440
                ([&]()->V{auto fn_431=attr(attr(self_value(),"task"),"click");Args args_430;return invoke(fn_431,args_430);}());
                // BaseChar.py:441
                {V value_432=V("click");scope_324->set("last_op",value_432);}
                // BaseChar.py:442
                continue;
            }
            // BaseChar.py:443
            if(([&]()->V{auto fn_434=attr(self_value(),"resonance_available");Args args_433;return invoke(fn_434,args_433);}()).truth()){
                // BaseChar.py:444
                if(([&]()->V{V compare_435=scope_324->get("resonance_click_time");V compare_436;V comparison_result_437;compare_436=V(0LL);comparison_result_437=compare_value("==",compare_435,compare_436);return comparison_result_437;}()).truth()){
                    // BaseChar.py:445
                    {V value_438=V(true);scope_324->set("clicked",value_438);}
                    // BaseChar.py:446
                    {V value_439=scope_324->get("now");scope_324->set("resonance_click_time",value_439);}
                    // BaseChar.py:447
                    ([&]()->V{auto fn_441=attr(self_value(),"record_resonance_use");Args args_440;return invoke(fn_441,args_440);}());
                }
                // BaseChar.py:448
                {V value_442=V("resonance");scope_324->set("last_op",value_442);}
                // BaseChar.py:449
                ([&]()->V{auto fn_444=attr(self_value(),"send_resonance_key");Args args_443;return invoke(fn_444,args_443);}());
                // BaseChar.py:450
                if(scope_324->get("has_animation").truth()){
                    // BaseChar.py:451
                    ([&]()->V{auto fn_446=attr(self_value(),"sleep");Args args_445;args_445.pos(V(0.2));args_445.kw("check_combat",V(false));return invoke(fn_446,args_445);}());
                }
            }
            // BaseChar.py:452
            {V value_447=scope_324->get("now");scope_324->set("last_click",value_447);}
        }
        // BaseChar.py:453
        ([&]()->V{auto fn_449=attr(attr(self_value(),"task"),"next_frame");Args args_448;return invoke(fn_449,args_448);}());
    }
    // BaseChar.py:454
    {V value_450=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_450);}
    // BaseChar.py:455
    if(scope_324->get("clicked").truth()){
        // BaseChar.py:456
        ([&]()->V{auto fn_452=attr(self_value(),"sleep");Args args_451;args_451.pos(scope_324->get("post_sleep"));return invoke(fn_452,args_451);}());
    }
    // BaseChar.py:457
    {V value_453=(([&]()->V{V compare_454=scope_324->get("resonance_click_time");V compare_455;V comparison_result_456;compare_455=V(0LL);comparison_result_456=compare_value("!=",compare_454,compare_455);return comparison_result_456;}()).truth()?([&]()->V{V left_457=([&]()->V{auto fn_460=attr(global("time","BaseChar"),"time");Args args_459;return invoke(fn_460,args_459);}());V right_458=scope_324->get("resonance_click_time");return official::binary("-",left_457,right_458);}()):V(0LL));scope_324->set("duration",value_453);}
    // BaseChar.py:458
    if(([&]()->V{V compare_461=scope_324->get("animation_start");V compare_462;V comparison_result_463;compare_462=V(0LL);comparison_result_463=compare_value(">",compare_461,compare_462);return comparison_result_463;}()).truth()){
        // BaseChar.py:459
        ([&]()->V{auto fn_465=attr(self_value(),"add_freeze_duration");Args args_464;args_464.pos(scope_324->get("resonance_click_time"));args_464.pos(([&]()->V{V left_466=([&]()->V{auto fn_469=attr(global("time","BaseChar"),"time");Args args_468;return invoke(fn_469,args_468);}());V right_467=scope_324->get("animation_start");return official::binary("-",left_466,right_467);}()));return invoke(fn_465,args_464);}());
    }
    // BaseChar.py:460
    ([&]()->V{auto fn_471=attr(attr(self_value(),"logger"),"debug");Args args_470;args_470.pos(V(std::string{}+"click_resonance end clicked "+format_value(scope_324->get("clicked"),"",-1)+" duration "+format_value(scope_324->get("duration"),"",-1)+" animated "+format_value(([&]()->V{V compare_472=scope_324->get("animation_start");V compare_473;V comparison_result_474;compare_473=V(0LL);comparison_result_474=compare_value(">",compare_472,compare_473);return comparison_result_474;}()),"",-1)));return invoke(fn_471,args_470);}());
    // BaseChar.py:461
    return V::tuple({scope_324->get("clicked"),scope_324->get("duration"),([&]()->V{V compare_475=scope_324->get("animation_start");V compare_476;V comparison_result_477;compare_476=V(0LL);comparison_result_477=compare_value(">",compare_475,compare_476);return comparison_result_477;}())});
return V{};
}),true);
// Official method BaseChar.send_resonance_key, lines 463-472
register_method("send_resonance_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"post_sleep",V(0LL)},{"interval",unary("-",V(1LL))},{"down_time",V(0.01)}},"","",{})](const Args& official_args)->V{
auto scope_478=bind_arguments(official_args,signature,captured);
    // BaseChar.py:471
    {V value_479=V(false);set_attr(self_value(),"_resonance_available",value_479);}
    // BaseChar.py:472
    ([&]()->V{auto fn_481=attr(attr(self_value(),"task"),"send_key");Args args_480;args_480.pos(([&]()->V{auto fn_483=attr(self_value(),"get_resonance_key");Args args_482;return invoke(fn_483,args_482);}()));args_480.kw("interval",scope_478->get("interval"));args_480.kw("down_time",scope_478->get("down_time"));args_480.kw("after_sleep",scope_478->get("post_sleep"));return invoke(fn_481,args_480);}());
return V{};
}),true);
// Official method BaseChar.send_echo_key, lines 474-483
register_method("send_echo_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"after_sleep",V(0LL)},{"interval",unary("-",V(1LL))},{"down_time",V(0.01)}},"","",{})](const Args& official_args)->V{
auto scope_484=bind_arguments(official_args,signature,captured);
    // BaseChar.py:482
    {V value_485=V(false);set_attr(self_value(),"_echo_available",value_485);}
    // BaseChar.py:483
    ([&]()->V{auto fn_487=attr(attr(self_value(),"task"),"send_key");Args args_486;args_486.pos(([&]()->V{auto fn_489=attr(self_value(),"get_echo_key");Args args_488;return invoke(fn_489,args_488);}()));args_486.kw("interval",scope_484->get("interval"));args_486.kw("down_time",scope_484->get("down_time"));args_486.kw("after_sleep",scope_484->get("after_sleep"));return invoke(fn_487,args_486);}());
return V{};
}),true);
// Official method BaseChar.heavy_click_forte, lines 485-495
register_method("heavy_click_forte",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_fun",V{}}},"","",{})](const Args& official_args)->V{
auto scope_490=bind_arguments(official_args,signature,captured);
scope_490->set("success",V::missing());
    // BaseChar.py:488
    if(([&]()->V{V compare_491=scope_490->get("check_fun");V compare_492;V comparison_result_493;compare_492=V{};comparison_result_493=compare_value("is",compare_491,compare_492);return comparison_result_493;}()).truth()){
        // BaseChar.py:489
        {V value_494=attr(self_value(),"is_forte_full");scope_490->set("check_fun",value_494);}
    }
    // BaseChar.py:490
    if(([&]()->V{auto fn_496=scope_490->get("check_fun");Args args_495;return invoke(fn_496,args_495);}()).truth()){
        // BaseChar.py:491
        ([&]()->V{auto fn_498=attr(attr(self_value(),"task"),"mouse_down");Args args_497;return invoke(fn_498,args_497);}());
        // BaseChar.py:492
        {V value_499=([&]()->V{auto fn_501=attr(attr(self_value(),"task"),"wait_until");Args args_500;args_500.pos(V::function([this,captured=capture_scope(scope_490,{"check_fun"}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_502=bind_arguments(official_args,signature,captured);
return unary("not",([&]()->V{auto fn_504=scope_502->get("check_fun");Args args_503;return invoke(fn_504,args_503);}()));
}));args_500.kw("time_out",V(2LL));return invoke(fn_501,args_500);}());scope_490->set("success",value_499);}
        // BaseChar.py:493
        ([&]()->V{auto fn_506=attr(attr(self_value(),"task"),"mouse_up");Args args_505;return invoke(fn_506,args_505);}());
        // BaseChar.py:494
        ([&]()->V{auto fn_508=attr(self_value(),"sleep");Args args_507;args_507.pos(V(0.05));return invoke(fn_508,args_507);}());
        // BaseChar.py:495
        return scope_490->get("success");
    }
return V{};
}),true);
// Official method BaseChar.send_liberation_key, lines 497-506
register_method("send_liberation_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"after_sleep",V(0LL)},{"interval",unary("-",V(1LL))},{"down_time",V(0.01)}},"","",{})](const Args& official_args)->V{
auto scope_509=bind_arguments(official_args,signature,captured);
    // BaseChar.py:505
    {V value_510=V(false);set_attr(self_value(),"_liberation_available",value_510);}
    // BaseChar.py:506
    ([&]()->V{auto fn_512=attr(attr(self_value(),"task"),"send_key");Args args_511;args_511.pos(([&]()->V{auto fn_514=attr(self_value(),"get_liberation_key");Args args_513;return invoke(fn_514,args_513);}()));args_511.kw("interval",scope_509->get("interval"));args_511.kw("down_time",scope_509->get("down_time"));args_511.kw("after_sleep",scope_509->get("after_sleep"));return invoke(fn_512,args_511);}());
return V{};
}),true);
// Official method BaseChar.record_resonance_use, lines 508-510
register_method("record_resonance_use",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_515=bind_arguments(official_args,signature,captured);
    // BaseChar.py:510
    {V value_516=([&]()->V{auto fn_518=attr(global("time","BaseChar"),"time");Args args_517;return invoke(fn_518,args_517);}());set_attr(self_value(),"last_res",value_516);}
return V{};
}),true);
// Official method BaseChar.record_liberation_use, lines 512-514
register_method("record_liberation_use",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_519=bind_arguments(official_args,signature,captured);
    // BaseChar.py:514
    {V value_520=([&]()->V{auto fn_522=attr(global("time","BaseChar"),"time");Args args_521;return invoke(fn_522,args_521);}());set_attr(self_value(),"last_liberation",value_520);}
return V{};
}),true);
// Official method BaseChar.record_echo_use, lines 516-518
register_method("record_echo_use",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_523=bind_arguments(official_args,signature,captured);
    // BaseChar.py:518
    {V value_524=([&]()->V{auto fn_526=attr(global("time","BaseChar"),"time");Args args_525;return invoke(fn_526,args_525);}());set_attr(self_value(),"last_echo",value_524);}
return V{};
}),true);
// Official method BaseChar.click_echo, lines 520-569
register_method("click_echo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V(0LL)},{"sleep_time",V(0LL)},{"time_out",V(1LL)}},"","",{})](const Args& official_args)->V{
auto scope_527=bind_arguments(official_args,signature,captured);
scope_527->set("clicked",V::missing());
scope_527->set("last_click",V::missing());
scope_527->set("now",V::missing());
scope_527->set("start",V::missing());
    // BaseChar.py:531
    if(([&]()->V{V operand_528;operand_528=([&]()->V{V compare_529=scope_527->get("time_out");V compare_530;V comparison_result_531;compare_530=V(0LL);comparison_result_531=compare_value("==",compare_529,compare_530);return comparison_result_531;}());if(!operand_528.truth())return operand_528;return ([&]()->V{auto fn_533=attr(self_value(),"echo_available");Args args_532;return invoke(fn_533,args_532);}());}()).truth()){
        // BaseChar.py:532
        ([&]()->V{auto fn_535=attr(self_value(),"send_echo_key");Args args_534;return invoke(fn_535,args_534);}());
        // BaseChar.py:533
        ([&]()->V{auto fn_537=attr(self_value(),"record_echo_use");Args args_536;return invoke(fn_537,args_536);}());
        // BaseChar.py:534
        ([&]()->V{auto fn_539=attr(attr(self_value(),"logger"),"debug");Args args_538;args_538.pos(V("click echo"));return invoke(fn_539,args_538);}());
        // BaseChar.py:535
        return V(true);
    }
    // BaseChar.py:536
    if(([&]()->V{V operand_540;operand_540=([&]()->V{auto fn_542=attr(attr(self_value(),"task"),"is_open_world_auto_combat");Args args_541;return invoke(fn_542,args_541);}());if(!operand_540.truth())return operand_540;return ([&]()->V{V compare_543=attr(self_value(),"ring_index");V compare_544;V comparison_result_545;compare_544=attr(global("Elements","BaseChar"),"FIRE");comparison_result_545=compare_value("==",compare_543,compare_544);return comparison_result_545;}());}()).truth()){
        // BaseChar.py:537
        ([&]()->V{auto fn_547=attr(attr(self_value(),"logger"),"debug");Args args_546;args_546.pos(V(std::string{}+"open world do not use motorcycle echo"));return invoke(fn_547,args_546);}());
        // BaseChar.py:538
        return V(false);
    }
    // BaseChar.py:539
    ([&]()->V{auto fn_549=attr(attr(self_value(),"logger"),"debug");Args args_548;args_548.pos(V(std::string{}+"click_echo start duration: "+format_value(scope_527->get("duration"),"",-1)));return invoke(fn_549,args_548);}());
    // BaseChar.py:540
    if(([&]()->V{auto fn_551=attr(self_value(),"has_cd");Args args_550;args_550.pos(V("echo"));return invoke(fn_551,args_550);}()).truth()){
        // BaseChar.py:541
        ([&]()->V{auto fn_553=attr(attr(self_value(),"logger"),"debug");Args args_552;args_552.pos(V("click_echo has cd return "));return invoke(fn_553,args_552);}());
        // BaseChar.py:542
        return V(false);
    }
    // BaseChar.py:543
    {V value_554=V(false);scope_527->set("clicked",value_554);}
    // BaseChar.py:544
    {V value_555=([&]()->V{auto fn_557=attr(global("time","BaseChar"),"time");Args args_556;return invoke(fn_557,args_556);}());scope_527->set("start",value_555);}
    // BaseChar.py:545
    {V value_558=V(0LL);scope_527->set("last_click",value_558);}
    // BaseChar.py:546
    scope_527->set("time_out",official::binary("+",scope_527->get("time_out"),scope_527->get("duration")));
    // BaseChar.py:547
        while(V(true).truth()){
        // BaseChar.py:548
        if(([&]()->V{V compare_559=([&]()->V{V left_561=([&]()->V{auto fn_564=attr(global("time","BaseChar"),"time");Args args_563;return invoke(fn_564,args_563);}());V right_562=scope_527->get("start");return official::binary("-",left_561,right_562);}());V compare_560;V comparison_result_565;compare_560=scope_527->get("time_out");comparison_result_565=compare_value(">",compare_559,compare_560);return comparison_result_565;}()).truth()){
            // BaseChar.py:549
            ([&]()->V{auto fn_567=attr(attr(self_value(),"logger"),"info");Args args_566;args_566.pos(V("click_echo time out"));return invoke(fn_567,args_566);}());
            // BaseChar.py:550
            return V(false);
        }
        // BaseChar.py:551
        if(([&]()->V{V operand_568;operand_568=unary("not",([&]()->V{auto fn_570=attr(self_value(),"echo_available");Args args_569;return invoke(fn_570,args_569);}()));if(!operand_568.truth())return operand_568;return ([&]()->V{V operand_571;operand_571=([&]()->V{V compare_572=scope_527->get("duration");V compare_573;V comparison_result_574;compare_573=V(0LL);comparison_result_574=compare_value("==",compare_572,compare_573);return comparison_result_574;}());if(operand_571.truth())return operand_571;return unary("not",scope_527->get("clicked"));}());}()).truth()){
            // BaseChar.py:552
            break;
        }
        // BaseChar.py:553
        {V value_575=([&]()->V{auto fn_577=attr(global("time","BaseChar"),"time");Args args_576;return invoke(fn_577,args_576);}());scope_527->set("now",value_575);}
        // BaseChar.py:554
        if(([&]()->V{V operand_578;operand_578=([&]()->V{V compare_579=scope_527->get("duration");V compare_580;V comparison_result_581;compare_580=V(0LL);comparison_result_581=compare_value(">",compare_579,compare_580);return comparison_result_581;}());if(!operand_578.truth())return operand_578;return ([&]()->V{V compare_582=scope_527->get("start");V compare_583;V comparison_result_584;compare_583=V(0LL);comparison_result_584=compare_value("!=",compare_582,compare_583);return comparison_result_584;}());}()).truth()){
            // BaseChar.py:555
            if(([&]()->V{V compare_585=([&]()->V{V left_587=scope_527->get("now");V right_588=scope_527->get("start");return official::binary("-",left_587,right_588);}());V compare_586;V comparison_result_589;compare_586=scope_527->get("duration");comparison_result_589=compare_value(">",compare_585,compare_586);return comparison_result_589;}()).truth()){
                // BaseChar.py:556
                break;
            }
        }
        // BaseChar.py:557
        if(([&]()->V{V compare_590=([&]()->V{V left_592=scope_527->get("now");V right_593=scope_527->get("last_click");return official::binary("-",left_592,right_593);}());V compare_591;V comparison_result_594;compare_591=V(0.1);comparison_result_594=compare_value(">",compare_590,compare_591);return comparison_result_594;}()).truth()){
            // BaseChar.py:558
            if(unary("not",scope_527->get("clicked")).truth()){
                // BaseChar.py:559
                ([&]()->V{auto fn_596=attr(self_value(),"record_echo_use");Args args_595;return invoke(fn_596,args_595);}());
                // BaseChar.py:560
                {V value_597=V(true);scope_527->set("clicked",value_597);}
            }
            // BaseChar.py:561
            ([&]()->V{auto fn_599=attr(self_value(),"send_echo_key");Args args_598;return invoke(fn_599,args_598);}());
            // BaseChar.py:562
            {V value_600=scope_527->get("now");scope_527->set("last_click",value_600);}
        }
        // BaseChar.py:563
        if(([&]()->V{V compare_601=([&]()->V{V left_603=scope_527->get("now");V right_604=scope_527->get("start");return official::binary("-",left_603,right_604);}());V compare_602;V comparison_result_605;compare_602=global("SKILL_TIME_OUT","BaseChar");comparison_result_605=compare_value(">",compare_601,compare_602);return comparison_result_605;}()).truth()){
            // BaseChar.py:564
            ([&]()->V{auto fn_607=attr(attr(self_value(),"logger"),"error");Args args_606;args_606.pos(V(std::string{}+"click_echo too long "+format_value(scope_527->get("clicked"),"",-1)));return invoke(fn_607,args_606);}());
            // BaseChar.py:565
            ([&]()->V{auto fn_609=attr(self_value(),"alert_skill_failed");Args args_608;return invoke(fn_609,args_608);}());
            // BaseChar.py:566
            break;
        }
        // BaseChar.py:567
        ([&]()->V{auto fn_611=attr(attr(self_value(),"task"),"next_frame");Args args_610;return invoke(fn_611,args_610);}());
    }
    // BaseChar.py:568
    ([&]()->V{auto fn_613=attr(attr(self_value(),"logger"),"debug");Args args_612;args_612.pos(V(std::string{}+"click_echo end "+format_value(scope_527->get("clicked"),"",-1)));return invoke(fn_613,args_612);}());
    // BaseChar.py:569
    return scope_527->get("clicked");
return V{};
}),true);
// Official method BaseChar.is_open_world_auto_combat, lines 571-572
register_method("is_open_world_auto_combat",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_614=bind_arguments(official_args,signature,captured);
    // BaseChar.py:572
    return ([&]()->V{auto fn_616=attr(attr(self_value(),"task"),"is_open_world_auto_combat");Args args_615;return invoke(fn_616,args_615);}());
return V{};
}),true);
// Official method BaseChar.check_combat, lines 574-576
register_method("check_combat",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_617=bind_arguments(official_args,signature,captured);
    // BaseChar.py:576
    ([&]()->V{auto fn_619=attr(attr(self_value(),"task"),"check_combat");Args args_618;return invoke(fn_619,args_618);}());
return V{};
}),true);
// Official method BaseChar.reset_state, lines 578-592
register_method("reset_state",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_620=bind_arguments(official_args,signature,captured);
    // BaseChar.py:585
    {V value_621=V(false);set_attr(self_value(),"has_intro",value_621);}
    // BaseChar.py:586
    {V value_622=V(false);set_attr(self_value(),"has_sub_dps_intro",value_622);}
    // BaseChar.py:587
    {V value_623=V(0LL);set_attr(self_value(),"current_con",value_623);}
    // BaseChar.py:588
    {V value_624=unary("-",V(1LL));set_attr(self_value(),"last_full_con_switch_time",value_624);}
    // BaseChar.py:589
    {V value_625=V(false);set_attr(self_value(),"has_tool_box",value_625);}
    // BaseChar.py:590
    {V value_626=V(false);set_attr(self_value(),"_liberation_available",value_626);}
    // BaseChar.py:591
    {V value_627=V(false);set_attr(self_value(),"_echo_available",value_627);}
    // BaseChar.py:592
    {V value_628=V(false);set_attr(self_value(),"_resonance_available",value_628);}
return V{};
}),true);
// Official method BaseChar.click_liberation, lines 594-674
register_method("click_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"con_less_than",unary("-",V(1LL))},{"send_click",V(false)},{"wait_if_cd_ready",V(0.1)},{"animation_min_duration",V(0LL)},{"click_f",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_629=bind_arguments(official_args,signature,captured);
scope_629->set("clicked",V::missing());
scope_629->set("duration",V::missing());
scope_629->set("last_click",V::missing());
scope_629->set("last_f_click",V::missing());
scope_629->set("now",V::missing());
scope_629->set("start",V::missing());
    // BaseChar.py:608
    if(unary("not",attr(attr(self_value(),"task"),"use_liberation")).truth()){
        // BaseChar.py:609
        return V(false);
    }
    // BaseChar.py:610
    if(([&]()->V{V compare_630=scope_629->get("con_less_than");V compare_631;V comparison_result_632;compare_631=V(0LL);comparison_result_632=compare_value(">",compare_630,compare_631);return comparison_result_632;}()).truth()){
        // BaseChar.py:611
        if(([&]()->V{V compare_633=([&]()->V{auto fn_636=attr(self_value(),"get_current_con");Args args_635;return invoke(fn_636,args_635);}());V compare_634;V comparison_result_637;compare_634=scope_629->get("con_less_than");comparison_result_637=compare_value(">",compare_633,compare_634);return comparison_result_637;}()).truth()){
            // BaseChar.py:612
            return V(false);
        }
    }
    // BaseChar.py:613
    ([&]()->V{auto fn_639=attr(attr(self_value(),"logger"),"debug");Args args_638;args_638.pos(V(std::string{}+"click_liberation start"));return invoke(fn_639,args_638);}());
    // BaseChar.py:614
    {V value_640=([&]()->V{auto fn_642=attr(global("time","BaseChar"),"time");Args args_641;return invoke(fn_642,args_641);}());scope_629->set("start",value_640);}
    // BaseChar.py:615
    {V value_643=V(0LL);scope_629->set("last_click",value_643);}
    // BaseChar.py:616
    {V value_644=V(false);scope_629->set("clicked",value_644);}
    // BaseChar.py:617
    if(unary("not",attr(attr(self_value(),"task"),"in_liberation")).truth()){
        // BaseChar.py:618
                while(([&]()->V{auto fn_675=attr(self_value(),"liberation_available");Args args_674;return invoke(fn_675,args_674);}()).truth()){
            // BaseChar.py:619
            ([&]()->V{auto fn_646=attr(attr(self_value(),"logger"),"debug");Args args_645;args_645.pos(V(std::string{}+"click_liberation liberation_available click"));return invoke(fn_646,args_645);}());
            // BaseChar.py:620
            if(scope_629->get("send_click").truth()){
                // BaseChar.py:621
                ([&]()->V{auto fn_648=attr(self_value(),"click");Args args_647;args_647.kw("interval",V(0.1));return invoke(fn_648,args_647);}());
            }
            // BaseChar.py:622
            {V value_649=([&]()->V{auto fn_651=attr(global("time","BaseChar"),"time");Args args_650;return invoke(fn_651,args_650);}());scope_629->set("now",value_649);}
            // BaseChar.py:623
            if(([&]()->V{V compare_652=([&]()->V{V left_654=scope_629->get("now");V right_655=scope_629->get("last_click");return official::binary("-",left_654,right_655);}());V compare_653;V comparison_result_656;compare_653=V(0.1);comparison_result_656=compare_value(">",compare_652,compare_653);return comparison_result_656;}()).truth()){
                // BaseChar.py:624
                ([&]()->V{auto fn_658=attr(self_value(),"send_liberation_key");Args args_657;return invoke(fn_658,args_657);}());
                // BaseChar.py:625
                if(unary("not",scope_629->get("clicked")).truth()){
                    // BaseChar.py:626
                    {V value_659=V(true);scope_629->set("clicked",value_659);}
                }
                // BaseChar.py:627
                {V value_660=scope_629->get("now");scope_629->set("last_click",value_660);}
            }
            // BaseChar.py:628
            if(([&]()->V{V compare_661=([&]()->V{V left_663=([&]()->V{auto fn_666=attr(global("time","BaseChar"),"time");Args args_665;return invoke(fn_666,args_665);}());V right_664=scope_629->get("start");return official::binary("-",left_663,right_664);}());V compare_662;V comparison_result_667;compare_662=global("SKILL_TIME_OUT","BaseChar");comparison_result_667=compare_value(">",compare_661,compare_662);return comparison_result_667;}()).truth()){
                // BaseChar.py:629
                ([&]()->V{auto fn_669=attr(self_value(),"alert_skill_failed");Args args_668;return invoke(fn_669,args_668);}());
                // BaseChar.py:630
                ([&]()->V{auto fn_671=attr(attr(self_value(),"task"),"raise_not_in_combat");Args args_670;args_670.pos(V("too long clicking a liberation"));return invoke(fn_671,args_670);}());
            }
            // BaseChar.py:631
            ([&]()->V{auto fn_673=attr(attr(self_value(),"task"),"next_frame");Args args_672;return invoke(fn_673,args_672);}());
        }
        // BaseChar.py:632
        if(scope_629->get("clicked").truth()){
            // BaseChar.py:633
            if(([&]()->V{auto fn_677=attr(attr(self_value(),"task"),"wait_until");Args args_676;args_676.pos(V::function([this,captured=capture_scope(scope_629,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_678=bind_arguments(official_args,signature,captured);
return unary("not",item(([&]()->V{auto fn_680=attr(attr(self_value(),"task"),"in_team");Args args_679;return invoke(fn_680,args_679);}()),V(0LL)));
}));args_676.kw("time_out",V(0.4));args_676.kw("post_action",(scope_629->get("send_click").truth()?attr(self_value(),"click_with_interval"):V{}));return invoke(fn_677,args_676);}()).truth()){
                // BaseChar.py:635
                {V value_681=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_681);}
                // BaseChar.py:636
                ([&]()->V{auto fn_683=attr(attr(self_value(),"logger"),"debug");Args args_682;args_682.pos(V(std::string{}+"not in_team successfully casted liberation"));return invoke(fn_683,args_682);}());
            }else{
                // BaseChar.py:638
                {V value_684=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_684);}
                // BaseChar.py:639
                ([&]()->V{auto fn_686=attr(attr(self_value(),"logger"),"error");Args args_685;args_685.pos(V(std::string{}+"clicked liberation but no effect"));return invoke(fn_686,args_685);}());
                // BaseChar.py:640
                return V(false);
            }
        }else{
            // BaseChar.py:642
            {V value_687=([&]()->V{auto fn_689=attr(global("time","BaseChar"),"time");Args args_688;return invoke(fn_689,args_688);}());scope_629->set("start",value_687);}
            // BaseChar.py:643
                        while(([&]()->V{V operand_700;operand_700=unary("not",([&]()->V{auto fn_702=attr(self_value(),"has_cd");Args args_701;args_701.pos(V("liberation"));return invoke(fn_702,args_701);}()));if(!operand_700.truth())return operand_700;return ([&]()->V{V compare_703=([&]()->V{V left_705=([&]()->V{auto fn_708=attr(global("time","BaseChar"),"time");Args args_707;return invoke(fn_708,args_707);}());V right_706=scope_629->get("start");return official::binary("-",left_705,right_706);}());V compare_704;V comparison_result_709;compare_704=scope_629->get("wait_if_cd_ready");comparison_result_709=compare_value("<",compare_703,compare_704);return comparison_result_709;}());}()).truth()){
                // BaseChar.py:644
                ([&]()->V{auto fn_691=attr(self_value(),"send_liberation_key");Args args_690;args_690.kw("after_sleep",V(0.05));return invoke(fn_691,args_690);}());
                // BaseChar.py:645
                if(([&]()->V{auto fn_693=attr(attr(self_value(),"task"),"wait_until");Args args_692;args_692.pos(V::function([this,captured=capture_scope(scope_629,{}),signature=Signature({},"","",{})](const Args& official_args)->V{
auto scope_694=bind_arguments(official_args,signature,captured);
return unary("not",item(([&]()->V{auto fn_696=attr(attr(self_value(),"task"),"in_team");Args args_695;return invoke(fn_696,args_695);}()),V(0LL)));
}));args_692.kw("time_out",V(0.1));return invoke(fn_693,args_692);}()).truth()){
                    // BaseChar.py:646
                    {V value_697=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_697);}
                    // BaseChar.py:647
                    ([&]()->V{auto fn_699=attr(attr(self_value(),"logger"),"debug");Args args_698;args_698.pos(V(std::string{}+"not in_team successfully casted liberation"));return invoke(fn_699,args_698);}());
                }
            }
            // BaseChar.py:648
            if(unary("not",attr(attr(self_value(),"task"),"in_liberation")).truth()){
                // BaseChar.py:649
                return V(false);
            }
        }
    }
    // BaseChar.py:650
    {V value_710=([&]()->V{auto fn_712=attr(global("time","BaseChar"),"time");Args args_711;return invoke(fn_712,args_711);}());scope_629->set("start",value_710);}
    // BaseChar.py:651
    {V value_713=V(0LL);scope_629->set("last_f_click",value_713);}
    // BaseChar.py:652
        while(unary("not",item(([&]()->V{auto fn_746=attr(attr(self_value(),"task"),"in_team");Args args_745;return invoke(fn_746,args_745);}()),V(0LL))).truth()){
        // BaseChar.py:653
        {V value_714=V(true);set_attr(attr(self_value(),"task"),"in_liberation",value_714);}
        // BaseChar.py:654
        if(unary("not",scope_629->get("clicked")).truth()){
            // BaseChar.py:655
            {V value_715=V(true);scope_629->set("clicked",value_715);}
        }
        // BaseChar.py:656
        if(scope_629->get("send_click").truth()){
            // BaseChar.py:657
            ([&]()->V{auto fn_717=attr(self_value(),"click");Args args_716;args_716.kw("interval",V(0.1));return invoke(fn_717,args_716);}());
        }
        // BaseChar.py:658
        {V value_718=([&]()->V{auto fn_720=attr(global("time","BaseChar"),"time");Args args_719;return invoke(fn_720,args_719);}());scope_629->set("now",value_718);}
        // BaseChar.py:659
        if(([&]()->V{V operand_721;operand_721=scope_629->get("click_f");if(!operand_721.truth())return operand_721;operand_721=([&]()->V{V compare_722=([&]()->V{V left_724=scope_629->get("now");V right_725=scope_629->get("start");return official::binary("-",left_724,right_725);}());V compare_723;V comparison_result_726;compare_723=scope_629->get("animation_min_duration");comparison_result_726=compare_value(">=",compare_722,compare_723);return comparison_result_726;}());if(!operand_721.truth())return operand_721;return ([&]()->V{V compare_727=([&]()->V{V left_729=scope_629->get("now");V right_730=scope_629->get("last_f_click");return official::binary("-",left_729,right_730);}());V compare_728;V comparison_result_731;compare_728=V(0.1);comparison_result_731=compare_value(">=",compare_727,compare_728);return comparison_result_731;}());}()).truth()){
            // BaseChar.py:661
            ([&]()->V{auto fn_733=attr(attr(self_value(),"task"),"send_key");Args args_732;args_732.pos(V("f"));return invoke(fn_733,args_732);}());
            // BaseChar.py:662
            {V value_734=scope_629->get("now");scope_629->set("last_f_click",value_734);}
        }
        // BaseChar.py:663
        if(([&]()->V{V compare_735=([&]()->V{V left_737=scope_629->get("now");V right_738=scope_629->get("start");return official::binary("-",left_737,right_738);}());V compare_736;V comparison_result_739;compare_736=V(7LL);comparison_result_739=compare_value(">",compare_735,compare_736);return comparison_result_739;}()).truth()){
            // BaseChar.py:664
            {V value_740=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_740);}
            // BaseChar.py:665
            ([&]()->V{auto fn_742=attr(attr(self_value(),"task"),"raise_not_in_combat");Args args_741;args_741.pos(V("too long a liberation, the boss was killed by the liberation"));return invoke(fn_742,args_741);}());
        }
        // BaseChar.py:666
        ([&]()->V{auto fn_744=attr(attr(self_value(),"task"),"next_frame");Args args_743;return invoke(fn_744,args_743);}());
    }
    // BaseChar.py:667
    {V value_747=([&]()->V{V left_748=([&]()->V{auto fn_751=attr(global("time","BaseChar"),"time");Args args_750;return invoke(fn_751,args_750);}());V right_749=scope_629->get("start");return official::binary("-",left_748,right_749);}());scope_629->set("duration",value_747);}
    // BaseChar.py:668
    ([&]()->V{auto fn_753=attr(self_value(),"add_freeze_duration");Args args_752;args_752.pos(scope_629->get("start"));args_752.pos(scope_629->get("duration"));return invoke(fn_753,args_752);}());
    // BaseChar.py:669
    ([&]()->V{auto fn_755=attr(self_value(),"record_liberation_use");Args args_754;return invoke(fn_755,args_754);}());
    // BaseChar.py:670
    {V value_756=V(false);set_attr(attr(self_value(),"task"),"in_liberation",value_756);}
    // BaseChar.py:671
    {V value_757=V(false);set_attr(self_value(),"_liberation_available",value_757);}
    // BaseChar.py:672
    if(scope_629->get("clicked").truth()){
        // BaseChar.py:673
        ([&]()->V{auto fn_759=attr(attr(self_value(),"logger"),"info");Args args_758;args_758.pos(V(std::string{}+"click_liberation end "+format_value(scope_629->get("duration"),"",-1)));return invoke(fn_759,args_758);}());
    }
    // BaseChar.py:674
    return scope_629->get("clicked");
return V{};
}),true);
// Official method BaseChar.on_combat_end, lines 676-682
register_method("on_combat_end",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_760=bind_arguments(official_args,signature,captured);
return V{};
}),true);
// Official method BaseChar.add_freeze_duration, lines 684-686
register_method("add_freeze_duration",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"start",V::missing()},{"duration",unary("-",V(1.0))},{"freeze_time",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_761=bind_arguments(official_args,signature,captured);
    // BaseChar.py:686
    ([&]()->V{auto fn_763=attr(attr(self_value(),"task"),"add_freeze_duration");Args args_762;args_762.pos(scope_761->get("start"));args_762.pos(scope_761->get("duration"));args_762.pos(scope_761->get("freeze_time"));return invoke(fn_763,args_762);}());
return V{};
}),true);
// Official method BaseChar.time_elapsed_accounting_for_freeze, lines 688-690
register_method("time_elapsed_accounting_for_freeze",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"start",V::missing()},{"intro_motion_freeze",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_764=bind_arguments(official_args,signature,captured);
    // BaseChar.py:690
    return ([&]()->V{auto fn_766=attr(attr(self_value(),"task"),"time_elapsed_accounting_for_freeze");Args args_765;args_765.pos(scope_764->get("start"));args_765.pos(scope_764->get("intro_motion_freeze"));return invoke(fn_766,args_765);}());
return V{};
}),true);
// Official method BaseChar.get_liberation_key, lines 692-694
register_method("get_liberation_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_767=bind_arguments(official_args,signature,captured);
    // BaseChar.py:694
    return ([&]()->V{auto fn_769=attr(attr(self_value(),"task"),"get_liberation_key");Args args_768;return invoke(fn_769,args_768);}());
return V{};
}),true);
// Official method BaseChar.get_echo_key, lines 696-698
register_method("get_echo_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_770=bind_arguments(official_args,signature,captured);
    // BaseChar.py:698
    return ([&]()->V{auto fn_772=attr(attr(self_value(),"task"),"get_echo_key");Args args_771;return invoke(fn_772,args_771);}());
return V{};
}),true);
// Official method BaseChar.get_resonance_key, lines 700-702
register_method("get_resonance_key",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_773=bind_arguments(official_args,signature,captured);
    // BaseChar.py:702
    return ([&]()->V{auto fn_775=attr(attr(self_value(),"task"),"get_resonance_key");Args args_774;return invoke(fn_775,args_774);}());
return V{};
}),true);
// Official method BaseChar.get_switch_priority, lines 704-713
register_method("get_switch_priority",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V{}},{"has_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_776=bind_arguments(official_args,signature,captured);
    // BaseChar.py:713
    return attr(global("SwitchPriority","BaseChar"),"NORMAL");
return V{};
}),true);
// Official method BaseChar.healer_full_con_switch_locked, lines 715-721
register_method("healer_full_con_switch_locked",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_777=bind_arguments(official_args,signature,captured);
    // BaseChar.py:716
    return ([&]()->V{V operand_778;operand_778=attr(self_value(),"is_healer");if(!operand_778.truth())return operand_778;operand_778=([&]()->V{V compare_779=attr(self_value(),"last_full_con_switch_time");V compare_780;V comparison_result_781;compare_780=V(0LL);comparison_result_781=compare_value(">=",compare_779,compare_780);return comparison_result_781;}());if(!operand_778.truth())return operand_778;return ([&]()->V{V compare_782=([&]()->V{auto fn_785=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_784;args_784.pos(attr(self_value(),"last_full_con_switch_time"));return invoke(fn_785,args_784);}());V compare_783;V comparison_result_786;compare_783=attr(self_value(),"HEALER_FULL_CON_SWITCH_LOCKOUT");comparison_result_786=compare_value("<",compare_782,compare_783);return comparison_result_786;}());}());
return V{};
}),true);
// Official method BaseChar.resonance_available, lines 723-734
register_method("resonance_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_787=bind_arguments(official_args,signature,captured);
    // BaseChar.py:734
    return ([&]()->V{auto fn_789=attr(self_value(),"available");Args args_788;args_788.pos(V("resonance"));args_788.kw("check_color",V(false));return invoke(fn_789,args_788);}());
return V{};
}),true);
// Official method BaseChar.available, lines 736-740
register_method("available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"box",V::missing()},{"check_color",V(true)},{"check_cd",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_790=bind_arguments(official_args,signature,captured);
    // BaseChar.py:737
    if(attr(self_value(),"is_current_char").truth()){
        // BaseChar.py:738
        return ([&]()->V{auto fn_792=attr(attr(self_value(),"task"),"available");Args args_791;args_791.pos(scope_790->get("box"));args_791.kw("check_color",scope_790->get("check_color"));args_791.kw("check_cd",scope_790->get("check_cd"));return invoke(fn_792,args_791);}());
    }else{
        // BaseChar.py:740
        return unary("not",([&]()->V{auto fn_794=attr(attr(self_value(),"task"),"has_cd");Args args_793;args_793.pos(scope_790->get("box"));args_793.pos(attr(self_value(),"index"));return invoke(fn_794,args_793);}()));
    }
return V{};
}),true);
// Official method BaseChar.echo_available, lines 742-751
register_method("echo_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_795=bind_arguments(official_args,signature,captured);
    // BaseChar.py:751
    return ([&]()->V{auto fn_797=attr(self_value(),"available");Args args_796;args_796.pos(V("echo"));args_796.kw("check_color",V(false));return invoke(fn_797,args_796);}());
return V{};
}),true);
// Official method BaseChar.extra_action_available, lines 753-762
register_method("extra_action_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_798=bind_arguments(official_args,signature,captured);
    // BaseChar.py:762
    return ([&]()->V{auto fn_800=attr(self_value(),"available");Args args_799;args_799.pos(V("extra_action"));args_799.kw("check_color",V(true));args_799.kw("check_cd",V(false));return invoke(fn_800,args_799);}());
return V{};
}),true);
// Official method BaseChar.is_con_full, lines 764-768
register_method("is_con_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_801=bind_arguments(official_args,signature,captured);
    // BaseChar.py:765
    if(([&]()->V{V compare_802=attr(self_value(),"current_con");V compare_803;V comparison_result_804;compare_803=V(1LL);comparison_result_804=compare_value("==",compare_802,compare_803);return comparison_result_804;}()).truth()){
        // BaseChar.py:766
        return V(true);
    }
    // BaseChar.py:768
    return ([&]()->V{auto fn_806=attr(attr(self_value(),"task"),"is_con_full");Args args_805;return invoke(fn_806,args_805);}());
return V{};
}),true);
// Official method BaseChar.get_current_con, lines 770-775
register_method("get_current_con",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_807=bind_arguments(official_args,signature,captured);
    // BaseChar.py:771
    if(([&]()->V{V compare_808=attr(self_value(),"current_con");V compare_809;V comparison_result_810;compare_809=V(1LL);comparison_result_810=compare_value("==",compare_808,compare_809);return comparison_result_810;}()).truth()){
        // BaseChar.py:772
        return V(1LL);
    }
    // BaseChar.py:774
    {V value_811=([&]()->V{auto fn_813=attr(attr(self_value(),"task"),"get_current_con");Args args_812;return invoke(fn_813,args_812);}());set_attr(self_value(),"current_con",value_811);}
    // BaseChar.py:775
    return attr(self_value(),"current_con");
return V{};
}),true);
// Official method BaseChar.is_mouse_forte_full, lines 777-782
register_method("is_mouse_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_814=bind_arguments(official_args,signature,captured);
    // BaseChar.py:782
    return ([&]()->V{auto fn_816=attr(attr(self_value(),"task"),"find_mouse_forte");Args args_815;return invoke(fn_816,args_815);}());
return V{};
}),true);
// Official method BaseChar.is_e_forte_full, lines 784-785
register_method("is_e_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_817=bind_arguments(official_args,signature,captured);
    // BaseChar.py:785
    return ([&]()->V{auto fn_819=attr(attr(self_value(),"task"),"find_e_forte");Args args_818;return invoke(fn_819,args_818);}());
return V{};
}),true);
// Official method BaseChar.is_forte_full, lines 787-808
register_method("is_forte_full",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_820=bind_arguments(official_args,signature,captured);
scope_820->set("box",V::missing());
scope_820->set("white_percent",V::missing());
    // BaseChar.py:793
    {V value_821=([&]()->V{auto fn_823=attr(attr(self_value(),"task"),"box_of_screen_scaled");Args args_822;args_822.pos(V(3840LL));args_822.pos(V(2160LL));args_822.pos(V(2251LL));args_822.pos(V(1993LL));args_822.pos(V(2311LL));args_822.pos(V(2016LL));args_822.kw("name",V("forte_full"));args_822.kw("hcenter",V(true));return invoke(fn_823,args_822);}());scope_820->set("box",value_821);}
    // BaseChar.py:794
    {V value_824=([&]()->V{auto fn_826=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_825;args_825.pos(global("forte_white_color","BaseChar"));args_825.pos(scope_820->get("box"));return invoke(fn_826,args_825);}());scope_820->set("white_percent",value_824);}
    // BaseChar.py:806
    {V value_827=scope_820->get("white_percent");set_attr(scope_820->get("box"),"confidence",value_827);}
    // BaseChar.py:807
    ([&]()->V{auto fn_829=attr(attr(self_value(),"task"),"draw_boxes");Args args_828;args_828.pos(V("forte_full"));args_828.pos(scope_820->get("box"));return invoke(fn_829,args_828);}());
    // BaseChar.py:808
    return ([&]()->V{V compare_830=scope_820->get("white_percent");V compare_831;V comparison_result_832;compare_831=V(0.08);comparison_result_832=compare_value(">",compare_830,compare_831);return comparison_result_832;}());
return V{};
}),true);
// Official method BaseChar.liberation_available, lines 810-816
register_method("liberation_available",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_color",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_833=bind_arguments(official_args,signature,captured);
    // BaseChar.py:816
    return ([&]()->V{auto fn_835=attr(self_value(),"available");Args args_834;args_834.pos(V("liberation"));args_834.kw("check_color",scope_833->get("check_color"));return invoke(fn_835,args_834);}());
return V{};
}),true);
// Official method BaseChar.__str__, lines 818-820
register_method("__str__",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_836=bind_arguments(official_args,signature,captured);
    // BaseChar.py:820
    return ([&]()->V{auto fn_838=attr(self_value(),"__repr__");Args args_837;return invoke(fn_838,args_837);}());
return V{};
}),true);
// Official method BaseChar.normal_attack_until_can_switch, lines 822-826
register_method("normal_attack_until_can_switch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_839=bind_arguments(official_args,signature,captured);
    // BaseChar.py:824
    ([&]()->V{auto fn_841=attr(attr(self_value(),"task"),"click");Args args_840;return invoke(fn_841,args_840);}());
    // BaseChar.py:825
        while(([&]()->V{V compare_844=([&]()->V{auto fn_847=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_846;args_846.pos(attr(self_value(),"last_perform"));return invoke(fn_847,args_846);}());V compare_845;V comparison_result_848;compare_845=V(1.1);comparison_result_848=compare_value("<",compare_844,compare_845);return comparison_result_848;}()).truth()){
        // BaseChar.py:826
        ([&]()->V{auto fn_843=attr(attr(self_value(),"task"),"click");Args args_842;args_842.kw("interval",V(0.1));return invoke(fn_843,args_842);}());
    }
return V{};
}),true);
// Official method BaseChar.need_fast_perform, lines 828-838
register_method("need_fast_perform",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_849=bind_arguments(official_args,signature,captured);
scope_849->set("char",V::missing());
scope_849->set("current_char",V::missing());
    // BaseChar.py:829
    {V value_850=(([&]()->V{auto fn_852=global("hasattr","BaseChar");Args args_851;args_851.pos(attr(self_value(),"task"));args_851.pos(V("get_current_char"));return invoke(fn_852,args_851);}()).truth()?([&]()->V{auto fn_854=attr(attr(self_value(),"task"),"get_current_char");Args args_853;args_853.kw("raise_exception",V(false));return invoke(fn_854,args_853);}()):self_value());scope_849->set("current_char",value_850);}
    // BaseChar.py:831
    {auto iterator_855=official::iterate(([&]()->V{auto fn_872=global("getattr","BaseChar");Args args_871;args_871.pos(attr(self_value(),"task"));args_871.pos(V("chars"));args_871.pos(V::list({}));return invoke(fn_872,args_871);}()));V item_856;while(iterator_855.next(item_856)){
        scope_849->set("char",item_856);
        // BaseChar.py:832
        if(([&]()->V{V operand_857;operand_857=([&]()->V{V compare_858=scope_849->get("char");V compare_859;V comparison_result_860;compare_859=V{};comparison_result_860=compare_value("is",compare_858,compare_859);return comparison_result_860;}());if(operand_857.truth())return operand_857;return ([&]()->V{V compare_861=scope_849->get("char");V compare_862;V comparison_result_863;compare_862=scope_849->get("current_char");comparison_result_863=compare_value("==",compare_861,compare_862);return comparison_result_863;}());}()).truth()){
            // BaseChar.py:833
            continue;
        }
        // BaseChar.py:834
        if(([&]()->V{V compare_864=([&]()->V{auto fn_867=attr(scope_849->get("char"),"get_switch_priority");Args args_866;args_866.kw("current_char",scope_849->get("current_char"));args_866.kw("has_intro",V(false));args_866.kw("target_low_con",V(false));return invoke(fn_867,args_866);}());V compare_865;V comparison_result_868;compare_865=attr(global("SwitchPriority","BaseChar"),"MUST");comparison_result_868=compare_value(">=",compare_864,compare_865);return comparison_result_868;}()).truth()){
            // BaseChar.py:836
            ([&]()->V{auto fn_870=attr(attr(self_value(),"logger"),"info");Args args_869;args_869.pos(V(std::string{}+"In lock with "+format_value(scope_849->get("char"),"",-1)));return invoke(fn_870,args_869);}());
            // BaseChar.py:837
            return V(true);
        }
    }
    }
    // BaseChar.py:838
    return V(false);
return V{};
}),true);
// Official method BaseChar.wait_switch_cd, lines 840-844
register_method("wait_switch_cd",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_873=bind_arguments(official_args,signature,captured);
scope_873->set("since_last_switch",V::missing());
    // BaseChar.py:841
    {V value_874=([&]()->V{auto fn_876=attr(self_value(),"time_elapsed_accounting_for_freeze");Args args_875;args_875.pos(attr(self_value(),"last_perform"));return invoke(fn_876,args_875);}());scope_873->set("since_last_switch",value_874);}
    // BaseChar.py:842
    if(([&]()->V{V compare_877=scope_873->get("since_last_switch");V compare_878;V comparison_result_879;compare_878=V(1LL);comparison_result_879=compare_value("<=",compare_877,compare_878);return comparison_result_879;}()).truth()){
        // BaseChar.py:843
        ([&]()->V{auto fn_881=attr(attr(self_value(),"logger"),"debug");Args args_880;args_880.pos(V(std::string{}+"wait_switch_cd "+format_value(scope_873->get("since_last_switch"),"",-1)));return invoke(fn_881,args_880);}());
        // BaseChar.py:844
        ([&]()->V{auto fn_883=attr(self_value(),"continues_normal_attack");Args args_882;args_882.pos(([&]()->V{V left_884=V(1LL);V right_885=scope_873->get("since_last_switch");return official::binary("-",left_884,right_885);}()));return invoke(fn_883,args_882);}());
    }
return V{};
}),true);
// Official method BaseChar.continues_normal_attack, lines 846-864
register_method("continues_normal_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()},{"interval",V(0.1)},{"after_sleep",V(0LL)},{"click_resonance_if_ready_and_return",V(false)},{"until_con_full",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_886=bind_arguments(official_args,signature,captured);
scope_886->set("start",V::missing());
    // BaseChar.py:856
    {V value_887=([&]()->V{auto fn_889=attr(global("time","BaseChar"),"time");Args args_888;return invoke(fn_889,args_888);}());scope_886->set("start",value_887);}
    // BaseChar.py:857
        while(([&]()->V{V compare_902=([&]()->V{V left_904=([&]()->V{auto fn_907=attr(global("time","BaseChar"),"time");Args args_906;return invoke(fn_907,args_906);}());V right_905=scope_886->get("start");return official::binary("-",left_904,right_905);}());V compare_903;V comparison_result_908;compare_903=scope_886->get("duration");comparison_result_908=compare_value("<",compare_902,compare_903);return comparison_result_908;}()).truth()){
        // BaseChar.py:858
        if(([&]()->V{V operand_890;operand_890=scope_886->get("click_resonance_if_ready_and_return");if(!operand_890.truth())return operand_890;return ([&]()->V{auto fn_892=attr(self_value(),"resonance_available");Args args_891;return invoke(fn_892,args_891);}());}()).truth()){
            // BaseChar.py:859
            return ([&]()->V{auto fn_894=attr(self_value(),"click_resonance");Args args_893;return invoke(fn_894,args_893);}());
        }
        // BaseChar.py:860
        if(([&]()->V{V operand_895;operand_895=scope_886->get("until_con_full");if(!operand_895.truth())return operand_895;return ([&]()->V{auto fn_897=attr(self_value(),"is_con_full");Args args_896;return invoke(fn_897,args_896);}());}()).truth()){
            // BaseChar.py:861
            return V{};
        }
        // BaseChar.py:862
        ([&]()->V{auto fn_899=attr(attr(self_value(),"task"),"click");Args args_898;return invoke(fn_899,args_898);}());
        // BaseChar.py:863
        ([&]()->V{auto fn_901=attr(self_value(),"sleep");Args args_900;args_900.pos(scope_886->get("interval"));return invoke(fn_901,args_900);}());
    }
    // BaseChar.py:864
    ([&]()->V{auto fn_910=attr(self_value(),"sleep");Args args_909;args_909.pos(scope_886->get("after_sleep"));return invoke(fn_910,args_909);}());
return V{};
}),true);
// Official method BaseChar.continues_click, lines 866-876
register_method("continues_click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"key",V::missing()},{"duration",V::missing()},{"interval",V(0.1)}},"","",{})](const Args& official_args)->V{
auto scope_911=bind_arguments(official_args,signature,captured);
scope_911->set("start",V::missing());
    // BaseChar.py:874
    {V value_912=([&]()->V{auto fn_914=attr(global("time","BaseChar"),"time");Args args_913;return invoke(fn_914,args_913);}());scope_911->set("start",value_912);}
    // BaseChar.py:875
        while(([&]()->V{V compare_917=([&]()->V{V left_919=([&]()->V{auto fn_922=attr(global("time","BaseChar"),"time");Args args_921;return invoke(fn_922,args_921);}());V right_920=scope_911->get("start");return official::binary("-",left_919,right_920);}());V compare_918;V comparison_result_923;compare_918=scope_911->get("duration");comparison_result_923=compare_value("<",compare_917,compare_918);return comparison_result_923;}()).truth()){
        // BaseChar.py:876
        ([&]()->V{auto fn_916=attr(attr(self_value(),"task"),"send_key");Args args_915;args_915.pos(scope_911->get("key"));args_915.kw("interval",scope_911->get("interval"));return invoke(fn_916,args_915);}());
    }
return V{};
}),true);
// Official method BaseChar.continues_right_click, lines 878-893
register_method("continues_right_click",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V::missing()},{"interval",V(0.1)},{"direction_key",V{}}},"","",{})](const Args& official_args)->V{
auto scope_924=bind_arguments(official_args,signature,captured);
scope_924->set("start",V::missing());
    // BaseChar.py:886
    if(([&]()->V{V compare_925=scope_924->get("direction_key");V compare_926;V comparison_result_927;compare_926=V{};comparison_result_927=compare_value("is not",compare_925,compare_926);return comparison_result_927;}()).truth()){
        // BaseChar.py:887
        ([&]()->V{auto fn_929=attr(attr(self_value(),"task"),"send_key_down");Args args_928;args_928.pos(scope_924->get("direction_key"));return invoke(fn_929,args_928);}());
        // BaseChar.py:888
        ([&]()->V{auto fn_931=attr(attr(self_value(),"task"),"next_frame");Args args_930;return invoke(fn_931,args_930);}());
    }
    // BaseChar.py:889
    {V value_932=([&]()->V{auto fn_934=attr(global("time","BaseChar"),"time");Args args_933;return invoke(fn_934,args_933);}());scope_924->set("start",value_932);}
    // BaseChar.py:890
        while(([&]()->V{V compare_937=([&]()->V{V left_939=([&]()->V{auto fn_942=attr(global("time","BaseChar"),"time");Args args_941;return invoke(fn_942,args_941);}());V right_940=scope_924->get("start");return official::binary("-",left_939,right_940);}());V compare_938;V comparison_result_943;compare_938=scope_924->get("duration");comparison_result_943=compare_value("<",compare_937,compare_938);return comparison_result_943;}()).truth()){
        // BaseChar.py:891
        ([&]()->V{auto fn_936=attr(attr(self_value(),"task"),"click");Args args_935;args_935.kw("interval",scope_924->get("interval"));args_935.kw("key",V("right"));return invoke(fn_936,args_935);}());
    }
    // BaseChar.py:892
    if(([&]()->V{V compare_944=scope_924->get("direction_key");V compare_945;V comparison_result_946;compare_945=V{};comparison_result_946=compare_value("is not",compare_944,compare_945);return comparison_result_946;}()).truth()){
        // BaseChar.py:893
        ([&]()->V{auto fn_948=attr(attr(self_value(),"task"),"send_key_up");Args args_947;args_947.pos(scope_924->get("direction_key"));return invoke(fn_948,args_947);}());
    }
return V{};
}),true);
// Official method BaseChar.normal_attack, lines 895-899
register_method("normal_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_949=bind_arguments(official_args,signature,captured);
    // BaseChar.py:897
    ([&]()->V{auto fn_951=attr(attr(self_value(),"logger"),"debug");Args args_950;args_950.pos(V("normal attack"));return invoke(fn_951,args_950);}());
    // BaseChar.py:898
    ([&]()->V{auto fn_953=attr(self_value(),"check_combat");Args args_952;return invoke(fn_953,args_952);}());
    // BaseChar.py:899
    ([&]()->V{auto fn_955=attr(attr(self_value(),"task"),"click");Args args_954;return invoke(fn_955,args_954);}());
return V{};
}),true);
// Official method BaseChar.heavy_attack, lines 901-913
register_method("heavy_attack",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"duration",V(0.6)}},"","",{})](const Args& official_args)->V{
auto scope_956=bind_arguments(official_args,signature,captured);
    // BaseChar.py:907
    ([&]()->V{auto fn_958=attr(self_value(),"check_combat");Args args_957;return invoke(fn_958,args_957);}());
    // BaseChar.py:908
    ([&]()->V{auto fn_960=attr(attr(self_value(),"logger"),"debug");Args args_959;args_959.pos(V("heavy attack start"));return invoke(fn_960,args_959);}());
    // BaseChar.py:909
    ([&]()->V{auto fn_962=attr(attr(self_value(),"task"),"mouse_down");Args args_961;return invoke(fn_962,args_961);}());
    // BaseChar.py:910
    ([&]()->V{auto fn_964=attr(self_value(),"sleep");Args args_963;args_963.pos(scope_956->get("duration"));return invoke(fn_964,args_963);}());
    // BaseChar.py:911
    ([&]()->V{auto fn_966=attr(attr(self_value(),"task"),"mouse_up");Args args_965;return invoke(fn_966,args_965);}());
    // BaseChar.py:912
    ([&]()->V{auto fn_968=attr(self_value(),"sleep");Args args_967;args_967.pos(V(0.01));return invoke(fn_968,args_967);}());
    // BaseChar.py:913
    ([&]()->V{auto fn_970=attr(attr(self_value(),"logger"),"debug");Args args_969;args_969.pos(V("heavy attack end"));return invoke(fn_970,args_969);}());
return V{};
}),true);
// Official method BaseChar.current_resonance, lines 915-918
register_method("current_resonance",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_971=bind_arguments(official_args,signature,captured);
    // BaseChar.py:917
    return ([&]()->V{auto fn_973=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_972;args_972.pos(global("text_white_color","BaseChar"));args_972.pos(([&]()->V{auto fn_975=attr(attr(self_value(),"task"),"get_box_by_name");Args args_974;args_974.pos(V("box_resonance"));return invoke(fn_975,args_974);}()));return invoke(fn_973,args_972);}());
return V{};
}),true);
// Official method BaseChar.current_echo, lines 920-923
register_method("current_echo",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_976=bind_arguments(official_args,signature,captured);
    // BaseChar.py:922
    return ([&]()->V{auto fn_978=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_977;args_977.pos(global("text_white_color","BaseChar"));args_977.pos(([&]()->V{auto fn_980=attr(attr(self_value(),"task"),"get_box_by_name");Args args_979;args_979.pos(V("box_echo"));return invoke(fn_980,args_979);}()));return invoke(fn_978,args_977);}());
return V{};
}),true);
// Official method BaseChar.current_liberation, lines 925-927
register_method("current_liberation",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_981=bind_arguments(official_args,signature,captured);
    // BaseChar.py:927
    return ([&]()->V{auto fn_983=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_982;args_982.pos(global("text_white_color","BaseChar"));args_982.pos(([&]()->V{auto fn_985=attr(attr(self_value(),"task"),"get_box_by_name");Args args_984;args_984.pos(V("box_liberation"));return invoke(fn_985,args_984);}()));return invoke(fn_983,args_982);}());
return V{};
}),true);
// Official method BaseChar.flying, lines 929-934
register_method("flying",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_986=bind_arguments(official_args,signature,captured);
scope_986->set("percent",V::missing());
    // BaseChar.py:931
    if(unary("not",attr(attr(self_value(),"task"),"has_lavitator")).truth()){
        // BaseChar.py:932
        return V(false);
    }
    // BaseChar.py:933
    {V value_987=([&]()->V{auto fn_989=attr(attr(self_value(),"task"),"calculate_color_percentage");Args args_988;args_988.pos(global("text_white_color","BaseChar"));args_988.pos(([&]()->V{auto fn_991=attr(attr(self_value(),"task"),"get_box_by_name");Args args_990;args_990.pos(V("edge_levitator"));return invoke(fn_991,args_990);}()));return invoke(fn_989,args_988);}());scope_986->set("percent",value_987);}
    // BaseChar.py:934
    return ([&]()->V{V compare_992=scope_986->get("percent");V compare_993;V comparison_result_994;compare_993=V(0.1);comparison_result_994=compare_value("<",compare_992,compare_993);return comparison_result_994;}());
return V{};
}),true);
// Official method BaseChar.check_outro, lines 936-953
register_method("check_outro",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_995=bind_arguments(official_args,signature,captured);
scope_995->set("char",V::missing());
scope_995->set("i",V::missing());
scope_995->set("outro",V::missing());
scope_995->set("time",V::missing());
    // BaseChar.py:942
    if(unary("not",attr(self_value(),"has_intro")).truth()){
        // BaseChar.py:943
        return V("null");
    }
    // BaseChar.py:944
    {V value_996=V(0LL);scope_995->set("time",value_996);}
    // BaseChar.py:945
    {V value_997=V("null");scope_995->set("outro",value_997);}
    // BaseChar.py:946
    {auto iterator_998=official::iterate(([&]()->V{auto fn_1009=global("enumerate","BaseChar");Args args_1008;args_1008.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_1009,args_1008);}()));V item_999;while(iterator_998.next(item_999)){
        auto unpack_1010=unpack(item_999,2);scope_995->set("i",unpack_1010[0]);scope_995->set("char",unpack_1010[1]);
        // BaseChar.py:947
        if(([&]()->V{V compare_1000=scope_995->get("char");V compare_1001;V comparison_result_1002;compare_1001=self_value();comparison_result_1002=compare_value("==",compare_1000,compare_1001);return comparison_result_1002;}()).truth()){
        }else{
            // BaseChar.py:949
            if(([&]()->V{V compare_1003=attr(scope_995->get("char"),"last_switch_time");V compare_1004;V comparison_result_1005;compare_1004=scope_995->get("time");comparison_result_1005=compare_value(">",compare_1003,compare_1004);return comparison_result_1005;}()).truth()){
                // BaseChar.py:950
                {V value_1006=attr(scope_995->get("char"),"last_switch_time");scope_995->set("time",value_1006);}
                // BaseChar.py:951
                {V value_1007=attr(scope_995->get("char"),"char_name");scope_995->set("outro",value_1007);}
            }
        }
    }
    }
    // BaseChar.py:952
    ([&]()->V{auto fn_1012=attr(attr(self_value(),"logger"),"info");Args args_1011;args_1011.pos(V(std::string{}+"erned outro from "+format_value(scope_995->get("outro"),"",-1)));return invoke(fn_1012,args_1011);}());
    // BaseChar.py:953
    return scope_995->get("outro");
return V{};
}),true);
// Official method BaseChar.is_first_engage, lines 955-960
register_method("is_first_engage",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1013=bind_arguments(official_args,signature,captured);
scope_1013->set("result",V::missing());
    // BaseChar.py:957
    {V value_1014=([&]()->V{V compare_1015=V(0LL);V compare_1016;V comparison_result_1017;compare_1016=([&]()->V{V left_1018=attr(self_value(),"last_perform");V right_1019=attr(attr(self_value(),"task"),"combat_start");return official::binary("-",left_1018,right_1019);}());comparison_result_1017=compare_value("<=",compare_1015,compare_1016);if(!comparison_result_1017.truth())return comparison_result_1017;compare_1015=compare_1016;compare_1016=V(0.4);comparison_result_1017=compare_value("<",compare_1015,compare_1016);return comparison_result_1017;}());scope_1013->set("result",value_1014);}
    // BaseChar.py:958
    if(scope_1013->get("result").truth()){
        // BaseChar.py:959
        ([&]()->V{auto fn_1021=attr(attr(self_value(),"logger"),"info");Args args_1020;args_1020.pos(V("first engage"));return invoke(fn_1021,args_1020);}());
    }
    // BaseChar.py:960
    return scope_1013->get("result");
return V{};
}),true);
// Official method BaseChar.wait_switch, lines 962-964
register_method("wait_switch",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1022=bind_arguments(official_args,signature,captured);
    // BaseChar.py:964
    return V(false);
return V{};
}),true);
// Official method BaseChar.switch_other_char, lines 966-990
register_method("switch_other_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"allow_auto_combat",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_1023=bind_arguments(official_args,signature,captured);
scope_1023->set("AutoCombatTask",V::missing());
scope_1023->set("char",V::missing());
scope_1023->set("count",V::missing());
scope_1023->set("current_index",V::missing());
scope_1023->set("in_team",V::missing());
scope_1023->set("next_char",V::missing());
scope_1023->set("start",V::missing());
scope_1023->set("target_index",V::missing());
    // BaseChar.py:967
    {V value_1024=([&]()->V{V left_1025=([&]()->V{V left_1027=attr(self_value(),"index");V right_1028=V(1LL);return official::binary("+",left_1027,right_1028);}());V right_1026=([&]()->V{auto fn_1030=global("len","BaseChar");Args args_1029;args_1029.pos(attr(attr(self_value(),"task"),"chars"));return invoke(fn_1030,args_1029);}());return official::binary("%",left_1025,right_1026);}());scope_1023->set("target_index",value_1024);}
    // BaseChar.py:968
    {auto iterator_1031=official::iterate(attr(attr(self_value(),"task"),"chars"));V item_1032;while(iterator_1031.next(item_1032)){
        scope_1023->set("char",item_1032);
        // BaseChar.py:969
        if(([&]()->V{V operand_1033;operand_1033=scope_1023->get("char");if(!operand_1033.truth())return operand_1033;operand_1033=attr(scope_1023->get("char"),"is_healer");if(!operand_1033.truth())return operand_1033;return ([&]()->V{V compare_1034=attr(scope_1023->get("char"),"index");V compare_1035;V comparison_result_1036;compare_1035=attr(self_value(),"index");comparison_result_1036=compare_value("!=",compare_1034,compare_1035);return comparison_result_1036;}());}()).truth()){
            // BaseChar.py:970
            {V value_1037=attr(scope_1023->get("char"),"index");scope_1023->set("target_index",value_1037);}
            // BaseChar.py:971
            break;
        }
    }
    }
    // BaseChar.py:972
    {V value_1038=([&]()->V{auto fn_1040=global("str","BaseChar");Args args_1039;args_1039.pos(([&]()->V{V left_1041=scope_1023->get("target_index");V right_1042=V(1LL);return official::binary("+",left_1041,right_1042);}()));return invoke(fn_1040,args_1039);}());scope_1023->set("next_char",value_1038);}
    // BaseChar.py:974
    scope_1023->set("AutoCombatTask",import_value("src.task.AutoCombatTask","AutoCombatTask"));
    // BaseChar.py:975
    if(([&]()->V{V operand_1043;operand_1043=([&]()->V{auto fn_1045=global("isinstance","BaseChar");Args args_1044;args_1044.pos(attr(self_value(),"task"));args_1044.pos(scope_1023->get("AutoCombatTask"));return invoke(fn_1045,args_1044);}());if(!operand_1043.truth())return operand_1043;return unary("not",scope_1023->get("allow_auto_combat"));}()).truth()){
        // BaseChar.py:976
        ([&]()->V{auto fn_1047=attr(attr(self_value(),"logger"),"debug");Args args_1046;args_1046.pos(V("AutoCombatTask, skip switch_other_char"));return invoke(fn_1047,args_1046);}());
        // BaseChar.py:977
        return V{};
    }
    // BaseChar.py:978
    ([&]()->V{auto fn_1049=attr(attr(self_value(),"logger"),"debug");Args args_1048;args_1048.pos(V(std::string{}+format_value(attr(self_value(),"char_name"),"",-1)+" on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch next char: "+format_value(scope_1023->get("next_char"),"",-1)));return invoke(fn_1049,args_1048);}());
    // BaseChar.py:979
    {V value_1050=([&]()->V{auto fn_1052=attr(global("time","BaseChar"),"time");Args args_1051;return invoke(fn_1052,args_1051);}());scope_1023->set("start",value_1050);}
    // BaseChar.py:980
        while(([&]()->V{V compare_1071=([&]()->V{V left_1073=([&]()->V{auto fn_1076=attr(global("time","BaseChar"),"time");Args args_1075;return invoke(fn_1076,args_1075);}());V right_1074=scope_1023->get("start");return official::binary("-",left_1073,right_1074);}());V compare_1072;V comparison_result_1077;compare_1072=V(6LL);comparison_result_1077=compare_value("<",compare_1071,compare_1072);return comparison_result_1077;}()).truth()){
        // BaseChar.py:981
        {V value_1053=([&]()->V{auto fn_1055=attr(attr(self_value(),"task"),"in_team");Args args_1054;return invoke(fn_1055,args_1054);}());auto unpack_1056=unpack(value_1053,3);scope_1023->set("in_team",unpack_1056[0]);scope_1023->set("current_index",unpack_1056[1]);scope_1023->set("count",unpack_1056[2]);}
        // BaseChar.py:982
        if(([&]()->V{V operand_1057;operand_1057=scope_1023->get("in_team");if(!operand_1057.truth())return operand_1057;return ([&]()->V{V compare_1058=scope_1023->get("current_index");V compare_1059;V comparison_result_1060;compare_1059=attr(self_value(),"index");comparison_result_1060=compare_value("!=",compare_1058,compare_1059);return comparison_result_1060;}());}()).truth()){
            // BaseChar.py:983
            {auto iterator_1061=official::iterate(attr(attr(self_value(),"task"),"chars"));V item_1062;while(iterator_1061.next(item_1062)){
                scope_1023->set("char",item_1062);
                // BaseChar.py:984
                if(scope_1023->get("char").truth()){
                    // BaseChar.py:985
                    {V value_1063=([&]()->V{V compare_1064=attr(scope_1023->get("char"),"index");V compare_1065;V comparison_result_1066;compare_1065=scope_1023->get("current_index");comparison_result_1066=compare_value("==",compare_1064,compare_1065);return comparison_result_1066;}());set_attr(scope_1023->get("char"),"is_current_char",value_1063);}
                }
            }
            }
            // BaseChar.py:986
            break;
        }else{
            // BaseChar.py:988
            ([&]()->V{auto fn_1068=attr(attr(self_value(),"task"),"send_key");Args args_1067;args_1067.pos(scope_1023->get("next_char"));return invoke(fn_1068,args_1067);}());
        }
        // BaseChar.py:989
        ([&]()->V{auto fn_1070=attr(self_value(),"sleep");Args args_1069;args_1069.pos(V(0.2));args_1069.pos(V(false));return invoke(fn_1070,args_1069);}());
    }
    // BaseChar.py:990
    ([&]()->V{auto fn_1079=attr(attr(self_value(),"logger"),"debug");Args args_1078;args_1078.pos(V(std::string{}+"switch_other_char on_combat_end "+format_value(attr(self_value(),"index"),"",-1)+" switch end"));return invoke(fn_1079,args_1078);}());
return V{};
}),true);
// Official method BaseChar.has_long_action, lines 992-994
register_method("has_long_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1080=bind_arguments(official_args,signature,captured);
    // BaseChar.py:994
    return ([&]()->V{auto fn_1082=attr(attr(self_value(),"task"),"find_one");Args args_1081;args_1081.pos(item(([&]()->V{auto fn_1084=attr(attr(self_value(),"task"),"get_target_names");Args args_1083;return invoke(fn_1084,args_1083);}()),V(0LL)));args_1081.kw("box",V("box_target_enemy_long"));args_1081.kw("threshold",V(0.6));return invoke(fn_1082,args_1081);}());
return V{};
}),true);
// Official method BaseChar.has_long_action2, lines 996-998
register_method("has_long_action2",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1085=bind_arguments(official_args,signature,captured);
    // BaseChar.py:998
    return ([&]()->V{auto fn_1087=attr(attr(self_value(),"task"),"find_one");Args args_1086;args_1086.pos(item(([&]()->V{auto fn_1089=attr(attr(self_value(),"task"),"get_target_names");Args args_1088;return invoke(fn_1089,args_1088);}()),V(0LL)));args_1086.kw("box",V("target_box_long2"));args_1086.kw("threshold",V(0.6));return invoke(fn_1087,args_1086);}());
return V{};
}),true);
// Official method BaseChar.has_short_action, lines 1000-1004
register_method("has_short_action",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1090=bind_arguments(official_args,signature,captured);
    // BaseChar.py:1002
    if(([&]()->V{auto fn_1092=global("hasattr","BaseChar");Args args_1091;args_1091.pos(attr(self_value(),"task"));args_1091.pos(V("has_short_action"));return invoke(fn_1092,args_1091);}()).truth()){
        // BaseChar.py:1003
        return ([&]()->V{auto fn_1094=attr(attr(self_value(),"task"),"has_short_action");Args args_1093;return invoke(fn_1094,args_1093);}());
    }
    // BaseChar.py:1004
    return ([&]()->V{auto fn_1096=attr(attr(self_value(),"task"),"find_one");Args args_1095;args_1095.pos(item(([&]()->V{auto fn_1098=attr(attr(self_value(),"task"),"get_target_names");Args args_1097;return invoke(fn_1098,args_1097);}()),V(0LL)));args_1095.kw("box",V("target_box_short"));args_1095.kw("threshold",V(0.6));return invoke(fn_1096,args_1095);}());
return V{};
}),true);
// Official method BaseChar.f_break, lines 1006-1015
register_method("f_break",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"check_f_on_switch",V(false)},{"force",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_1099=bind_arguments(official_args,signature,captured);
    // BaseChar.py:1011
    if(scope_1099->get("force").truth()){
        // BaseChar.py:1012
        ([&]()->V{auto fn_1101=attr(attr(self_value(),"task"),"send_key");Args args_1100;args_1100.pos(V("f"));args_1100.kw("after_sleep",V(0.05));return invoke(fn_1101,args_1100);}());
    }
    // BaseChar.py:1013
    if(([&]()->V{V operand_1102;operand_1102=scope_1099->get("check_f_on_switch");if(!operand_1102.truth())return operand_1102;return unary("not",attr(self_value(),"check_f_on_switch"));}()).truth()){
        // BaseChar.py:1014
        return V(false);
    }
    // BaseChar.py:1015
    return ([&]()->V{auto fn_1104=attr(attr(self_value(),"task"),"f_break");Args args_1103;return invoke(fn_1104,args_1103);}());
return V{};
}),true);
}
