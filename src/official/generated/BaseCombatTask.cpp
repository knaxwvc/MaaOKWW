#include "../OfficialTask.h"
namespace official {
// Official 0b37b5b79e771297536ff1155db1c23131297558/src/task/BaseCombatTask.py
void TaskObject::install_combat_methods(){auto scope=std::make_shared<Scope>();
set_global("lib_ready_templates",V::list({V("lib_ready_spectro"),V("lib_ready_electric"),V("lib_ready_fire"),V("lib_ready_ice"),V("lib_ready_wind"),V("lib_ready_havoc")}));
register_method("_oldest_switch_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"chars",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_1=bind_arguments(official_args,signature,captured);
scope_1->set("char",V::missing());
    // BaseCombatTask.py:429
    {V value_2=([&]()->V{auto comprehension_scope_3=std::make_shared<Scope>(scope_1);V result_4=V::list();auto iterator_5=official::iterate(comprehension_scope_3->get("chars"));V value_6;while(iterator_5.next(value_6)){comprehension_scope_3->set("char",value_6);if(!([&]()->V{V compare_7=comprehension_scope_3->get("char");V compare_8;V comparison_result_9;compare_8=V{};comparison_result_9=compare_value("is not",compare_7,compare_8);return comparison_result_9;}()).truth())continue;append(result_4,comprehension_scope_3->get("char"));}return result_4;}());scope_1->set("chars",value_2);}
    // BaseCombatTask.py:430
    if(unary("not",scope_1->get("chars")).truth()){
        // BaseCombatTask.py:431
        return V{};
    }
    // BaseCombatTask.py:432
    return ([&]()->V{auto fn_11=global("min","BaseCombatTask");Args args_10;args_10.pos(scope_1->get("chars"));args_10.kw("key",V::function([this,captured=capture_scope(scope_1,{}),signature=Signature({{"char",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_12=bind_arguments(official_args,signature,captured);
return V::tuple({attr(scope_12->get("char"),"last_switch_in_time"),attr(scope_12->get("char"),"index")});
}));return invoke(fn_11,args_10);}());
return V{};
}),false);
register_method("_unbuffed_support_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"candidates",V::missing()},{"allow_healer",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_13=bind_arguments(official_args,signature,captured);
scope_13->set("char",V::missing());
scope_13->set("role",V::missing());
scope_13->set("role_order",V::missing());
scope_13->set("target",V::missing());
    // BaseCombatTask.py:435
    {V value_14=(scope_13->get("allow_healer").truth()?V::tuple({V("is_healer"),V("is_sub_dps")}):V::tuple({V("is_sub_dps")}));scope_13->set("role_order",value_14);}
    // BaseCombatTask.py:436
    {auto iterator_15=official::iterate(scope_13->get("role_order"));V item_16;while(iterator_15.next(item_16)){
        scope_13->set("role",item_16);
        // BaseCombatTask.py:437
        {V value_17=([&]()->V{auto fn_19=attr(self_value(),"_oldest_switch_target");Args args_18;args_18.pos(([&]()->V{auto comprehension_scope_20=std::make_shared<Scope>(scope_13);V result_21=V::list();auto iterator_22=official::iterate(comprehension_scope_20->get("candidates"));V value_23;while(iterator_22.next(value_23)){comprehension_scope_20->set("char",value_23);if(!([&]()->V{V operand_24;operand_24=([&]()->V{auto fn_26=global("getattr","BaseCombatTask");Args args_25;args_25.pos(comprehension_scope_20->get("char"));args_25.pos(comprehension_scope_20->get("role"));return invoke(fn_26,args_25);}());if(!operand_24.truth())return operand_24;operand_24=([&]()->V{V compare_27=attr(comprehension_scope_20->get("char"),"buff_time");V compare_28;V comparison_result_29;compare_28=V(0LL);comparison_result_29=compare_value(">",compare_27,compare_28);return comparison_result_29;}());if(!operand_24.truth())return operand_24;return unary("not",([&]()->V{auto fn_31=attr(comprehension_scope_20->get("char"),"has_buff");Args args_30;return invoke(fn_31,args_30);}()));}()).truth())continue;append(result_21,comprehension_scope_20->get("char"));}return result_21;}()));return invoke(fn_19,args_18);}());scope_13->set("target",value_17);}
        // BaseCombatTask.py:441
        if(scope_13->get("target").truth()){
            // BaseCombatTask.py:442
            return scope_13->get("target");
        }
    }
    }
    // BaseCombatTask.py:443
    return V{};
return V{};
}),false);
register_method("_switch_rule_3_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"candidates",V::missing()},{"allow_healer",V(true)}},"","",{})](const Args& official_args)->V{
auto scope_32=bind_arguments(official_args,signature,captured);
scope_32->set("char",V::missing());
scope_32->set("main_dps",V::missing());
scope_32->set("unbuffed_support",V::missing());
    // BaseCombatTask.py:446
    {V value_33=([&]()->V{auto fn_35=attr(self_value(),"_unbuffed_support_target");Args args_34;args_34.pos(scope_32->get("candidates"));args_34.pos(scope_32->get("allow_healer"));return invoke(fn_35,args_34);}());scope_32->set("unbuffed_support",value_33);}
    // BaseCombatTask.py:447
    if(scope_32->get("unbuffed_support").truth()){
        // BaseCombatTask.py:448
        return scope_32->get("unbuffed_support");
    }
    // BaseCombatTask.py:450
    {V value_36=([&]()->V{auto comprehension_scope_37=std::make_shared<Scope>(scope_32);V result_38=V::list();auto iterator_39=official::iterate(comprehension_scope_37->get("candidates"));V value_40;while(iterator_39.next(value_40)){comprehension_scope_37->set("char",value_40);if(!attr(comprehension_scope_37->get("char"),"is_main_dps").truth())continue;append(result_38,comprehension_scope_37->get("char"));}return result_38;}());scope_32->set("main_dps",value_36);}
    // BaseCombatTask.py:451
    if(scope_32->get("main_dps").truth()){
        // BaseCombatTask.py:452
        return ([&]()->V{auto fn_42=attr(self_value(),"_oldest_switch_target");Args args_41;args_41.pos(scope_32->get("main_dps"));return invoke(fn_42,args_41);}());
    }
    // BaseCombatTask.py:454
    return ([&]()->V{auto fn_44=attr(self_value(),"_oldest_switch_target");Args args_43;args_43.pos(scope_32->get("candidates"));return invoke(fn_44,args_43);}());
return V{};
}),false);
register_method("_target_has_switch_cd",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"char",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_45=bind_arguments(official_args,signature,captured);
    // BaseCombatTask.py:457
    return ([&]()->V{V compare_46=([&]()->V{auto fn_49=attr(scope_45->get("char"),"time_elapsed_accounting_for_freeze");Args args_48;args_48.pos(attr(scope_45->get("char"),"last_switch_time"));return invoke(fn_49,args_48);}());V compare_47;V comparison_result_50;compare_47=V(1LL);comparison_result_50=compare_value("<=",compare_46,compare_47);return comparison_result_50;}());
return V{};
}),false);
register_method("_log_switch_candidate",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"char",V::missing()},{"priority",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_51=bind_arguments(official_args,signature,captured);
scope_51->set("buff_active",V::missing());
scope_51->set("buff_remaining",V::missing());
scope_51->set("switch_cd",V::missing());
    // BaseCombatTask.py:460
    {V value_52=([&]()->V{auto fn_54=attr(scope_51->get("char"),"has_buff");Args args_53;return invoke(fn_54,args_53);}());scope_51->set("buff_active",value_52);}
    // BaseCombatTask.py:461
    {V value_55=(scope_51->get("buff_active").truth()?([&]()->V{auto fn_57=attr(self_value(),"_buff_remaining");Args args_56;args_56.pos(scope_51->get("char"));return invoke(fn_57,args_56);}()):V(0LL));scope_51->set("buff_remaining",value_55);}
    // BaseCombatTask.py:462
    {V value_58=([&]()->V{V operand_59;operand_59=([&]()->V{V compare_60=attr(scope_51->get("char"),"last_switch_time");V compare_61;V comparison_result_62;compare_61=V(0LL);comparison_result_62=compare_value(">=",compare_60,compare_61);return comparison_result_62;}());if(!operand_59.truth())return operand_59;return ([&]()->V{auto fn_64=attr(self_value(),"_target_has_switch_cd");Args args_63;args_63.pos(scope_51->get("char"));return invoke(fn_64,args_63);}());}());scope_51->set("switch_cd",value_58);}
    // BaseCombatTask.py:463
    ([&]()->V{auto fn_66=attr(global("logger","BaseCombatTask"),"debug");Args args_65;args_65.pos(V(std::string{}+"switch selection candidate="+format_value(scope_51->get("char"),"",-1)+" index="+format_value(attr(scope_51->get("char"),"index"),"",-1)+" role="+format_value(attr(scope_51->get("char"),"char_type"),"",-1)+" priority="+format_value(scope_51->get("priority"),"",-1)+" buff_active="+format_value(scope_51->get("buff_active"),"",-1)+" buff_remaining="+format_value(scope_51->get("buff_remaining"),V(std::string{}+".2f").text(),-1)+" buff_time="+format_value(attr(scope_51->get("char"),"buff_time"),"",-1)+" last_buff_time="+format_value(attr(scope_51->get("char"),"last_buff_time"),V(std::string{}+".3f").text(),-1)+" switch_cd="+format_value(scope_51->get("switch_cd"),"",-1)+" last_switch_time="+format_value(attr(scope_51->get("char"),"last_switch_time"),V(std::string{}+".3f").text(),-1)));return invoke(fn_66,args_65);}());
return V{};
}),false);
register_method("_log_switch_choice",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"target",V::missing()},{"has_intro",V::missing()},{"reason",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_67=bind_arguments(official_args,signature,captured);
    // BaseCombatTask.py:470
    ([&]()->V{auto fn_69=attr(global("logger","BaseCombatTask"),"info");Args args_68;args_68.pos(V(std::string{}+"switch selection result current="+format_value(scope_67->get("current_char"),"",-1)+"("+format_value(attr(scope_67->get("current_char"),"char_type"),"",-1)+") target="+format_value(scope_67->get("target"),"",-1)+"("+format_value(attr(scope_67->get("target"),"char_type"),"",-1)+") has_intro="+format_value(scope_67->get("has_intro"),"",-1)+" reason="+format_value(scope_67->get("reason"),"",-1)));return invoke(fn_69,args_68);}());
    // BaseCombatTask.py:473
    return scope_67->get("target");
return V{};
}),false);
register_method("_buff_remaining",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"char",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_70=bind_arguments(official_args,signature,captured);
    // BaseCombatTask.py:476
    if(([&]()->V{V operand_71;operand_71=([&]()->V{V compare_72=attr(scope_70->get("char"),"buff_time");V compare_73;V comparison_result_74;compare_73=V(0LL);comparison_result_74=compare_value("<=",compare_72,compare_73);return comparison_result_74;}());if(operand_71.truth())return operand_71;return unary("not",([&]()->V{auto fn_76=attr(scope_70->get("char"),"has_buff");Args args_75;return invoke(fn_76,args_75);}()));}()).truth()){
        // BaseCombatTask.py:477
        return V(0LL);
    }
    // BaseCombatTask.py:478
    return ([&]()->V{auto fn_78=global("max","BaseCombatTask");Args args_77;args_77.pos(V(0LL));args_77.pos(([&]()->V{V left_79=attr(scope_70->get("char"),"buff_time");V right_80=([&]()->V{auto fn_82=attr(scope_70->get("char"),"time_elapsed_accounting_for_freeze");Args args_81;args_81.pos(attr(scope_70->get("char"),"last_buff_time"));return invoke(fn_82,args_81);}());return official::binary("-",left_79,right_80);}()));return invoke(fn_78,args_77);}());
return V{};
}),false);
register_method("_lowest_buff_remaining_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"candidates",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_83=bind_arguments(official_args,signature,captured);
scope_83->set("buffers",V::missing());
scope_83->set("char",V::missing());
    // BaseCombatTask.py:481
    {V value_84=([&]()->V{auto comprehension_scope_85=std::make_shared<Scope>(scope_83);V result_86=V::list();auto iterator_87=official::iterate(comprehension_scope_85->get("candidates"));V value_88;while(iterator_87.next(value_88)){comprehension_scope_85->set("char",value_88);if(!([&]()->V{V operand_89;operand_89=unary("not",attr(comprehension_scope_85->get("char"),"is_main_dps"));if(!operand_89.truth())return operand_89;return ([&]()->V{V compare_90=attr(comprehension_scope_85->get("char"),"buff_time");V compare_91;V comparison_result_92;compare_91=V(0LL);comparison_result_92=compare_value(">",compare_90,compare_91);return comparison_result_92;}());}()).truth())continue;append(result_86,comprehension_scope_85->get("char"));}return result_86;}());scope_83->set("buffers",value_84);}
    // BaseCombatTask.py:482
    if(unary("not",scope_83->get("buffers")).truth()){
        // BaseCombatTask.py:483
        return V{};
    }
    // BaseCombatTask.py:484
    return ([&]()->V{auto fn_94=global("min","BaseCombatTask");Args args_93;args_93.pos(scope_83->get("buffers"));args_93.kw("key",V::function([this,captured=capture_scope(scope_83,{}),signature=Signature({{"char",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_95=bind_arguments(official_args,signature,captured);
return V::tuple({([&]()->V{auto fn_97=attr(self_value(),"_buff_remaining");Args args_96;args_96.pos(scope_95->get("char"));return invoke(fn_97,args_96);}()),attr(scope_95->get("char"),"last_switch_in_time"),attr(scope_95->get("char"),"index")});
}));return invoke(fn_94,args_93);}());
return V{};
}),false);
register_method("_unbuffed_non_main_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"candidates",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_98=bind_arguments(official_args,signature,captured);
scope_98->set("char",V::missing());
scope_98->set("unbuffed_non_main",V::missing());
    // BaseCombatTask.py:487
    if(([&]()->V{V operand_99;operand_99=attr(scope_98->get("current_char"),"is_main_dps");if(operand_99.truth())return operand_99;return ([&]()->V{V compare_100=attr(scope_98->get("current_char"),"buff_time");V compare_101;V comparison_result_102;compare_101=V(0LL);comparison_result_102=compare_value("<=",compare_100,compare_101);return comparison_result_102;}());}()).truth()){
        // BaseCombatTask.py:488
        return V{};
    }
    // BaseCombatTask.py:489
    {V value_103=([&]()->V{auto comprehension_scope_104=std::make_shared<Scope>(scope_98);V result_105=V::list();auto iterator_106=official::iterate(comprehension_scope_104->get("candidates"));V value_107;while(iterator_106.next(value_107)){comprehension_scope_104->set("char",value_107);if(!([&]()->V{V operand_108;operand_108=unary("not",attr(comprehension_scope_104->get("char"),"is_main_dps"));if(!operand_108.truth())return operand_108;operand_108=([&]()->V{V compare_109=attr(comprehension_scope_104->get("char"),"buff_time");V compare_110;V comparison_result_111;compare_110=V(0LL);comparison_result_111=compare_value(">",compare_109,compare_110);return comparison_result_111;}());if(!operand_108.truth())return operand_108;return unary("not",([&]()->V{auto fn_113=attr(comprehension_scope_104->get("char"),"has_buff");Args args_112;return invoke(fn_113,args_112);}()));}()).truth())continue;append(result_105,comprehension_scope_104->get("char"));}return result_105;}());scope_98->set("unbuffed_non_main",value_103);}
    // BaseCombatTask.py:494
    return ([&]()->V{auto fn_115=attr(self_value(),"_oldest_switch_target");Args args_114;args_114.pos(scope_98->get("unbuffed_non_main"));return invoke(fn_115,args_114);}());
return V{};
}),false);
register_method("_choose_intro_switch_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"candidates",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_116=bind_arguments(official_args,signature,captured);
scope_116->set("char",V::missing());
scope_116->set("char_type",V::missing());
scope_116->set("role_order",V::missing());
scope_116->set("target",V::missing());
scope_116->set("unbuffed_support",V::missing());
    // BaseCombatTask.py:497
    {V value_117=([&]()->V{auto fn_119=attr(self_value(),"_unbuffed_support_target");Args args_118;args_118.pos(scope_116->get("candidates"));return invoke(fn_119,args_118);}());scope_116->set("unbuffed_support",value_117);}
    // BaseCombatTask.py:498
    if(scope_116->get("unbuffed_support").truth()){
        // BaseCombatTask.py:499
        return scope_116->get("unbuffed_support");
    }
    // BaseCombatTask.py:501
    {V value_120=V::tuple({V("is_main_dps"),V("is_sub_dps"),V("is_healer")});scope_116->set("role_order",value_120);}
    // BaseCombatTask.py:502
    {auto iterator_121=official::iterate(scope_116->get("role_order"));V item_122;while(iterator_121.next(item_122)){
        scope_116->set("char_type",item_122);
        // BaseCombatTask.py:503
        {V value_123=([&]()->V{auto fn_125=attr(self_value(),"_oldest_switch_target");Args args_124;args_124.pos(([&]()->V{auto comprehension_scope_126=std::make_shared<Scope>(scope_116);V result_127=V::list();auto iterator_128=official::iterate(comprehension_scope_126->get("candidates"));V value_129;while(iterator_128.next(value_129)){comprehension_scope_126->set("char",value_129);if(!([&]()->V{auto fn_131=global("getattr","BaseCombatTask");Args args_130;args_130.pos(comprehension_scope_126->get("char"));args_130.pos(comprehension_scope_126->get("char_type"));return invoke(fn_131,args_130);}()).truth())continue;append(result_127,comprehension_scope_126->get("char"));}return result_127;}()));return invoke(fn_125,args_124);}());scope_116->set("target",value_123);}
        // BaseCombatTask.py:504
        if(scope_116->get("target").truth()){
            // BaseCombatTask.py:505
            return scope_116->get("target");
        }
    }
    }
    // BaseCombatTask.py:506
    return V{};
return V{};
}),false);
register_method("_choose_switch_target_by_buff_time",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"candidates",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_132=bind_arguments(official_args,signature,captured);
scope_132->set("char",V::missing());
scope_132->set("lowest_buff_remaining",V::missing());
scope_132->set("main_dps",V::missing());
scope_132->set("unbuffed_non_main",V::missing());
    // BaseCombatTask.py:509
    if(unary("not",scope_132->get("candidates")).truth()){
        // BaseCombatTask.py:510
        return scope_132->get("current_char");
    }
    // BaseCombatTask.py:512
    if(attr(scope_132->get("current_char"),"is_main_dps").truth()){
        // BaseCombatTask.py:513
        {V value_133=([&]()->V{auto fn_135=attr(self_value(),"_lowest_buff_remaining_target");Args args_134;args_134.pos(scope_132->get("candidates"));return invoke(fn_135,args_134);}());scope_132->set("lowest_buff_remaining",value_133);}
        // BaseCombatTask.py:514
        if(scope_132->get("lowest_buff_remaining").truth()){
            // BaseCombatTask.py:515
            return scope_132->get("lowest_buff_remaining");
        }
    }
    // BaseCombatTask.py:517
    {V value_136=([&]()->V{auto fn_138=attr(self_value(),"_unbuffed_non_main_target");Args args_137;args_137.pos(scope_132->get("current_char"));args_137.pos(scope_132->get("candidates"));return invoke(fn_138,args_137);}());scope_132->set("unbuffed_non_main",value_136);}
    // BaseCombatTask.py:518
    if(scope_132->get("unbuffed_non_main").truth()){
        // BaseCombatTask.py:519
        return scope_132->get("unbuffed_non_main");
    }
    // BaseCombatTask.py:521
    if(([&]()->V{V operand_139;operand_139=attr(scope_132->get("current_char"),"is_sub_dps");if(operand_139.truth())return operand_139;return attr(scope_132->get("current_char"),"is_healer");}()).truth()){
        // BaseCombatTask.py:522
        {V value_140=([&]()->V{auto comprehension_scope_141=std::make_shared<Scope>(scope_132);V result_142=V::list();auto iterator_143=official::iterate(comprehension_scope_141->get("candidates"));V value_144;while(iterator_143.next(value_144)){comprehension_scope_141->set("char",value_144);if(!attr(comprehension_scope_141->get("char"),"is_main_dps").truth())continue;append(result_142,comprehension_scope_141->get("char"));}return result_142;}());scope_132->set("main_dps",value_140);}
        // BaseCombatTask.py:523
        if(scope_132->get("main_dps").truth()){
            // BaseCombatTask.py:524
            return ([&]()->V{auto fn_146=attr(self_value(),"_oldest_switch_target");Args args_145;args_145.pos(scope_132->get("main_dps"));return invoke(fn_146,args_145);}());
        }
    }
    // BaseCombatTask.py:526
    return ([&]()->V{auto fn_148=attr(self_value(),"_switch_rule_3_target");Args args_147;args_147.pos(scope_132->get("candidates"));return invoke(fn_148,args_147);}());
return V{};
}),false);
register_method("_choose_switch_target",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"has_intro",V::missing()},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_149=bind_arguments(official_args,signature,captured);
scope_149->set("_",V::missing());
scope_149->set("candidates",V::missing());
scope_149->set("candidates_without_switch_cd",V::missing());
scope_149->set("char",V::missing());
scope_149->set("highest_priority",V::missing());
scope_149->set("locked_healers",V::missing());
scope_149->set("prioritized_candidates",V::missing());
scope_149->set("priority",V::missing());
scope_149->set("reason",V::missing());
scope_149->set("switch_priority",V::missing());
scope_149->set("target",V::missing());
    // BaseCombatTask.py:529
    {V value_150=([&]()->V{auto comprehension_scope_151=std::make_shared<Scope>(scope_149);V result_152=V::list();auto iterator_153=official::iterate(attr(self_value(),"chars"));V value_154;while(iterator_153.next(value_154)){comprehension_scope_151->set("char",value_154);if(!([&]()->V{V operand_155;operand_155=([&]()->V{V compare_156=comprehension_scope_151->get("char");V compare_157;V comparison_result_158;compare_157=V{};comparison_result_158=compare_value("is not",compare_156,compare_157);return comparison_result_158;}());if(!operand_155.truth())return operand_155;return ([&]()->V{V compare_159=comprehension_scope_151->get("char");V compare_160;V comparison_result_161;compare_160=comprehension_scope_151->get("current_char");comparison_result_161=compare_value("!=",compare_159,compare_160);return comparison_result_161;}());}()).truth())continue;append(result_152,comprehension_scope_151->get("char"));}return result_152;}());scope_149->set("candidates",value_150);}
    // BaseCombatTask.py:533
    if(unary("not",scope_149->get("candidates")).truth()){
        // BaseCombatTask.py:534
        return scope_149->get("current_char");
    }
    // BaseCombatTask.py:536
    {V value_162=V::list({});scope_149->set("prioritized_candidates",value_162);}
    // BaseCombatTask.py:537
    {V value_163=V::list({});scope_149->set("locked_healers",value_163);}
    // BaseCombatTask.py:538
    {auto iterator_164=official::iterate(scope_149->get("candidates"));V item_165;while(iterator_164.next(item_165)){
        scope_149->set("char",item_165);
        // BaseCombatTask.py:539
        {V value_166=([&]()->V{auto fn_168=attr(scope_149->get("char"),"get_switch_priority");Args args_167;args_167.kw("current_char",scope_149->get("current_char"));args_167.kw("has_intro",scope_149->get("has_intro"));args_167.kw("target_low_con",scope_149->get("target_low_con"));return invoke(fn_168,args_167);}());scope_149->set("switch_priority",value_166);}
        // BaseCombatTask.py:541
        if(([&]()->V{auto fn_170=attr(scope_149->get("char"),"healer_full_con_switch_locked");Args args_169;return invoke(fn_170,args_169);}()).truth()){
            // BaseCombatTask.py:542
            if(([&]()->V{V compare_171=scope_149->get("switch_priority");V compare_172;V comparison_result_173;compare_172=attr(global("SwitchPriority","BaseCombatTask"),"NO");comparison_result_173=compare_value(">",compare_171,compare_172);return comparison_result_173;}()).truth()){
                // BaseCombatTask.py:543
                ([&]()->V{auto fn_175=attr(scope_149->get("locked_healers"),"append");Args args_174;args_174.pos(scope_149->get("char"));return invoke(fn_175,args_174);}());
            }
            // BaseCombatTask.py:544
            {V value_176=attr(global("SwitchPriority","BaseCombatTask"),"NO");scope_149->set("switch_priority",value_176);}
        }
        // BaseCombatTask.py:545
        ([&]()->V{auto fn_178=attr(self_value(),"_log_switch_candidate");Args args_177;args_177.pos(scope_149->get("char"));args_177.pos(scope_149->get("switch_priority"));return invoke(fn_178,args_177);}());
        // BaseCombatTask.py:546
        if(([&]()->V{V compare_179=scope_149->get("switch_priority");V compare_180;V comparison_result_181;compare_180=attr(global("SwitchPriority","BaseCombatTask"),"NO");comparison_result_181=compare_value(">",compare_179,compare_180);return comparison_result_181;}()).truth()){
            // BaseCombatTask.py:547
            ([&]()->V{auto fn_183=attr(scope_149->get("prioritized_candidates"),"append");Args args_182;args_182.pos(V::tuple({scope_149->get("switch_priority"),scope_149->get("char")}));return invoke(fn_183,args_182);}());
        }
    }
    }
    // BaseCombatTask.py:549
    if(unary("not",scope_149->get("prioritized_candidates")).truth()){
        // BaseCombatTask.py:550
        if(([&]()->V{V operand_184;operand_184=scope_149->get("locked_healers");if(!operand_184.truth())return operand_184;return ([&]()->V{V operand_185;operand_185=unary("not",attr(scope_149->get("current_char"),"is_healer"));if(operand_185.truth())return operand_185;return scope_149->get("has_intro");}());}()).truth()){
            // BaseCombatTask.py:551
            {V value_186=([&]()->V{auto fn_188=global("min","BaseCombatTask");Args args_187;args_187.pos(scope_149->get("locked_healers"));args_187.kw("key",V::function([this,captured=capture_scope(scope_149,{}),signature=Signature({{"char",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_189=bind_arguments(official_args,signature,captured);
return V::tuple({([&]()->V{V left_190=attr(scope_189->get("char"),"HEALER_FULL_CON_SWITCH_LOCKOUT");V right_191=([&]()->V{auto fn_193=attr(scope_189->get("char"),"time_elapsed_accounting_for_freeze");Args args_192;args_192.pos(attr(scope_189->get("char"),"last_full_con_switch_time"));return invoke(fn_193,args_192);}());return official::binary("-",left_190,right_191);}()),attr(scope_189->get("char"),"last_switch_in_time"),attr(scope_189->get("char"),"index")});
}));return invoke(fn_188,args_187);}());scope_149->set("target",value_186);}
            // BaseCombatTask.py:555
            return ([&]()->V{auto fn_195=attr(self_value(),"_log_switch_choice");Args args_194;args_194.pos(scope_149->get("current_char"));args_194.pos(scope_149->get("target"));args_194.pos(scope_149->get("has_intro"));args_194.pos(V("healer_lockout_fallback"));return invoke(fn_195,args_194);}());
        }
        // BaseCombatTask.py:556
        return ([&]()->V{auto fn_197=attr(self_value(),"_log_switch_choice");Args args_196;args_196.pos(scope_149->get("current_char"));args_196.pos(scope_149->get("current_char"));args_196.pos(scope_149->get("has_intro"));args_196.pos(V("no_candidate_above_no_priority"));return invoke(fn_197,args_196);}());
    }
    // BaseCombatTask.py:559
    {V value_198=([&]()->V{auto fn_200=global("max","BaseCombatTask");Args args_199;args_199.pos(([&]()->V{auto comprehension_scope_201=std::make_shared<Scope>(scope_149);V result_202=V::list();auto iterator_203=official::iterate(comprehension_scope_201->get("prioritized_candidates"));V value_204;while(iterator_203.next(value_204)){auto unpack_205=unpack(value_204,2);comprehension_scope_201->set("priority",unpack_205[0]);comprehension_scope_201->set("_",unpack_205[1]);append(result_202,comprehension_scope_201->get("priority"));}return result_202;}()));return invoke(fn_200,args_199);}());scope_149->set("highest_priority",value_198);}
    // BaseCombatTask.py:560
    {V value_206=([&]()->V{auto comprehension_scope_207=std::make_shared<Scope>(scope_149);V result_208=V::list();auto iterator_209=official::iterate(comprehension_scope_207->get("prioritized_candidates"));V value_210;while(iterator_209.next(value_210)){auto unpack_211=unpack(value_210,2);comprehension_scope_207->set("priority",unpack_211[0]);comprehension_scope_207->set("char",unpack_211[1]);if(!([&]()->V{V compare_212=comprehension_scope_207->get("priority");V compare_213;V comparison_result_214;compare_213=comprehension_scope_207->get("highest_priority");comparison_result_214=compare_value("==",compare_212,compare_213);return comparison_result_214;}()).truth())continue;append(result_208,comprehension_scope_207->get("char"));}return result_208;}());scope_149->set("candidates",value_206);}
    // BaseCombatTask.py:562
    if(scope_149->get("has_intro").truth()){
        // BaseCombatTask.py:563
        if(([&]()->V{V compare_215=scope_149->get("highest_priority");V compare_216;V comparison_result_217;compare_216=attr(global("SwitchPriority","BaseCombatTask"),"MUST");comparison_result_217=compare_value(">=",compare_215,compare_216);return comparison_result_217;}()).truth()){
            // BaseCombatTask.py:564
            {V value_218=([&]()->V{V operand_219;operand_219=([&]()->V{auto fn_221=attr(self_value(),"_oldest_switch_target");Args args_220;args_220.pos(scope_149->get("candidates"));return invoke(fn_221,args_220);}());if(operand_219.truth())return operand_219;return scope_149->get("current_char");}());scope_149->set("target",value_218);}
            // BaseCombatTask.py:565
            return ([&]()->V{auto fn_223=attr(self_value(),"_log_switch_choice");Args args_222;args_222.pos(scope_149->get("current_char"));args_222.pos(scope_149->get("target"));args_222.pos(scope_149->get("has_intro"));args_222.pos(V(std::string{}+"priority_"+format_value(scope_149->get("highest_priority"),"",-1)));return invoke(fn_223,args_222);}());
        }
        // BaseCombatTask.py:567
        {V value_224=([&]()->V{V operand_225;operand_225=([&]()->V{auto fn_227=attr(self_value(),"_choose_intro_switch_target");Args args_226;args_226.pos(scope_149->get("candidates"));return invoke(fn_227,args_226);}());if(operand_225.truth())return operand_225;return scope_149->get("current_char");}());scope_149->set("target",value_224);}
        // BaseCombatTask.py:568
        if(([&]()->V{V operand_228;operand_228=([&]()->V{V compare_229=scope_149->get("target");V compare_230;V comparison_result_231;compare_230=scope_149->get("current_char");comparison_result_231=compare_value("!=",compare_229,compare_230);return comparison_result_231;}());if(!operand_228.truth())return operand_228;operand_228=unary("not",attr(scope_149->get("target"),"is_main_dps"));if(!operand_228.truth())return operand_228;return unary("not",([&]()->V{auto fn_233=attr(scope_149->get("target"),"has_buff");Args args_232;return invoke(fn_233,args_232);}()));}()).truth()){
            // BaseCombatTask.py:569
            {V value_234=V(std::string{}+"intro_unbuffed_"+format_value(([&]()->V{auto fn_236=attr(attr(attr(scope_149->get("target"),"char_type"),"value"),"lower");Args args_235;return invoke(fn_236,args_235);}()),"",-1));scope_149->set("reason",value_234);}
        }else{
            // BaseCombatTask.py:571
            {V value_237=V("intro_role_order_main_sub_healer");scope_149->set("reason",value_237);}
        }
        // BaseCombatTask.py:572
        return ([&]()->V{auto fn_239=attr(self_value(),"_log_switch_choice");Args args_238;args_238.pos(scope_149->get("current_char"));args_238.pos(scope_149->get("target"));args_238.pos(scope_149->get("has_intro"));args_238.pos(scope_149->get("reason"));return invoke(fn_239,args_238);}());
    }
    // BaseCombatTask.py:574
    {V value_240=([&]()->V{auto comprehension_scope_241=std::make_shared<Scope>(scope_149);V result_242=V::list();auto iterator_243=official::iterate(comprehension_scope_241->get("candidates"));V value_244;while(iterator_243.next(value_244)){comprehension_scope_241->set("char",value_244);if(!unary("not",([&]()->V{auto fn_246=attr(self_value(),"_target_has_switch_cd");Args args_245;args_245.pos(comprehension_scope_241->get("char"));return invoke(fn_246,args_245);}())).truth())continue;append(result_242,comprehension_scope_241->get("char"));}return result_242;}());scope_149->set("candidates_without_switch_cd",value_240);}
    // BaseCombatTask.py:575
    if(scope_149->get("candidates_without_switch_cd").truth()){
        // BaseCombatTask.py:576
        {V value_247=scope_149->get("candidates_without_switch_cd");scope_149->set("candidates",value_247);}
    }
    // BaseCombatTask.py:578
    {V value_248=([&]()->V{auto fn_250=attr(self_value(),"_choose_switch_target_by_buff_time");Args args_249;args_249.pos(scope_149->get("current_char"));args_249.pos(scope_149->get("candidates"));return invoke(fn_250,args_249);}());scope_149->set("target",value_248);}
    // BaseCombatTask.py:579
    if(([&]()->V{V operand_251;operand_251=([&]()->V{V compare_252=scope_149->get("target");V compare_253;V comparison_result_254;compare_253=scope_149->get("current_char");comparison_result_254=compare_value("!=",compare_252,compare_253);return comparison_result_254;}());if(!operand_251.truth())return operand_251;operand_251=unary("not",attr(scope_149->get("target"),"is_main_dps"));if(!operand_251.truth())return operand_251;return unary("not",([&]()->V{auto fn_256=attr(scope_149->get("target"),"has_buff");Args args_255;return invoke(fn_256,args_255);}()));}()).truth()){
        // BaseCombatTask.py:580
        {V value_257=V(std::string{}+"unbuffed_"+format_value(([&]()->V{auto fn_259=attr(attr(attr(scope_149->get("target"),"char_type"),"value"),"lower");Args args_258;return invoke(fn_259,args_258);}()),"",-1));scope_149->set("reason",value_257);}
    }else{
        // BaseCombatTask.py:581
        if(([&]()->V{V operand_260;operand_260=attr(scope_149->get("current_char"),"is_main_dps");if(!operand_260.truth())return operand_260;return unary("not",attr(scope_149->get("target"),"is_main_dps"));}()).truth()){
            // BaseCombatTask.py:582
            {V value_261=V("lowest_support_buff_remaining");scope_149->set("reason",value_261);}
        }else{
            // BaseCombatTask.py:583
            if(([&]()->V{V operand_262;operand_262=unary("not",attr(scope_149->get("current_char"),"is_main_dps"));if(!operand_262.truth())return operand_262;return attr(scope_149->get("target"),"is_main_dps");}()).truth()){
                // BaseCombatTask.py:584
                {V value_263=V("support_buffs_active_return_to_main_dps");scope_149->set("reason",value_263);}
            }else{
                // BaseCombatTask.py:586
                {V value_264=V("fallback_role_order");scope_149->set("reason",value_264);}
            }
        }
    }
    // BaseCombatTask.py:587
    return ([&]()->V{auto fn_266=attr(self_value(),"_log_switch_choice");Args args_265;args_265.pos(scope_149->get("current_char"));args_265.pos(scope_149->get("target"));args_265.pos(scope_149->get("has_intro"));args_265.pos(scope_149->get("reason"));return invoke(fn_266,args_265);}());
return V{};
}),false);
register_method("_apply_intro_flags",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"switch_to",V::missing()},{"has_intro",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_267=bind_arguments(official_args,signature,captured);
    // BaseCombatTask.py:590
    {V value_268=scope_267->get("has_intro");set_attr(scope_267->get("switch_to"),"has_intro",value_268);}
    // BaseCombatTask.py:591
    {V value_269=([&]()->V{V operand_270;operand_270=scope_267->get("has_intro");if(!operand_270.truth())return operand_270;return attr(scope_267->get("current_char"),"is_sub_dps");}());set_attr(scope_267->get("switch_to"),"has_sub_dps_intro",value_269);}
return V{};
}),false);
register_method("switch_next_char",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()},{"current_char",V::missing()},{"post_action",V{}},{"free_intro",V(false)},{"target_low_con",V(false)}},"","",{})](const Args& official_args)->V{
auto scope_271=bind_arguments(official_args,signature,captured);
scope_271->set("ShoreKeeper",V::missing());
scope_271->set("_",V::missing());
scope_271->set("current_con",V::missing());
scope_271->set("current_index",V::missing());
scope_271->set("current_time",V::missing());
scope_271->set("has_intro",V::missing());
scope_271->set("in_team",V::missing());
scope_271->set("last_click",V::missing());
scope_271->set("now",V::missing());
scope_271->set("refreshed_has_intro",V::missing());
scope_271->set("size",V::missing());
scope_271->set("start",V::missing());
scope_271->set("switch_to",V::missing());
    // BaseCombatTask.py:602
    {V value_272=scope_271->get("free_intro");scope_271->set("has_intro",value_272);}
    // BaseCombatTask.py:603
    {V value_273=V(0LL);scope_271->set("current_con",value_273);}
    // BaseCombatTask.py:604
    ([&]()->V{auto fn_275=attr(self_value(),"update_lib_portrait_icon");Args args_274;return invoke(fn_275,args_274);}());
    // BaseCombatTask.py:605
    if(unary("not",scope_271->get("has_intro")).truth()){
        // BaseCombatTask.py:606
        {V value_276=([&]()->V{auto fn_278=attr(scope_271->get("current_char"),"get_current_con");Args args_277;return invoke(fn_278,args_277);}());scope_271->set("current_con",value_276);}
        // BaseCombatTask.py:607
        if(([&]()->V{V operand_279;operand_279=([&]()->V{V compare_280=scope_271->get("current_con");V compare_281;V comparison_result_282;compare_281=V(0.8);comparison_result_282=compare_value(">",compare_280,compare_281);return comparison_result_282;}());if(!operand_279.truth())return operand_279;return ([&]()->V{V compare_283=scope_271->get("current_con");V compare_284;V comparison_result_285;compare_284=V(1LL);comparison_result_285=compare_value("!=",compare_283,compare_284);return comparison_result_285;}());}()).truth()){
            // BaseCombatTask.py:608
            ([&]()->V{auto fn_287=attr(global("logger","BaseCombatTask"),"info");Args args_286;args_286.pos(V(std::string{}+"switch_next_char current_con "+format_value(scope_271->get("current_con"),V(std::string{}+".2f").text(),-1)+" almost full, sleep and check again"));return invoke(fn_287,args_286);}());
            // BaseCombatTask.py:609
            ([&]()->V{auto fn_289=attr(self_value(),"sleep");Args args_288;args_288.pos(V(0.05));return invoke(fn_289,args_288);}());
            // BaseCombatTask.py:610
            ([&]()->V{auto fn_291=attr(self_value(),"next_frame");Args args_290;return invoke(fn_291,args_290);}());
            // BaseCombatTask.py:611
            {V value_292=([&]()->V{auto fn_294=attr(scope_271->get("current_char"),"get_current_con");Args args_293;return invoke(fn_294,args_293);}());scope_271->set("current_con",value_292);}
        }
        // BaseCombatTask.py:612
        if(([&]()->V{V compare_295=scope_271->get("current_con");V compare_296;V comparison_result_297;compare_296=V(1LL);comparison_result_297=compare_value("==",compare_295,compare_296);return comparison_result_297;}()).truth()){
            // BaseCombatTask.py:613
            {V value_298=V(true);scope_271->set("has_intro",value_298);}
        }
    }
    // BaseCombatTask.py:615
    {V value_299=([&]()->V{auto fn_301=attr(self_value(),"_choose_switch_target");Args args_300;args_300.pos(scope_271->get("current_char"));args_300.pos(scope_271->get("has_intro"));args_300.kw("target_low_con",scope_271->get("target_low_con"));return invoke(fn_301,args_300);}());scope_271->set("switch_to",value_299);}
    // BaseCombatTask.py:616
    if(([&]()->V{V operand_302;operand_302=unary("not",scope_271->get("switch_to"));if(operand_302.truth())return operand_302;return ([&]()->V{V compare_303=scope_271->get("switch_to");V compare_304;V comparison_result_305;compare_304=scope_271->get("current_char");comparison_result_305=compare_value("==",compare_303,compare_304);return comparison_result_305;}());}()).truth()){
        // BaseCombatTask.py:617
        ([&]()->V{auto fn_307=attr(global("logger","BaseCombatTask"),"warning");Args args_306;args_306.pos(V(std::string{}+format_value(scope_271->get("current_char"),"",-1)+" can't find next char to switch to, performing too fast add a normal attack"));return invoke(fn_307,args_306);}());
        // BaseCombatTask.py:618
        ([&]()->V{auto fn_309=attr(scope_271->get("current_char"),"continues_normal_attack");Args args_308;args_308.pos(V(0.2));return invoke(fn_309,args_308);}());
        // BaseCombatTask.py:619
        return V{};
    }
    // BaseCombatTask.py:620
    ([&]()->V{auto fn_311=attr(self_value(),"_apply_intro_flags");Args args_310;args_310.pos(scope_271->get("current_char"));args_310.pos(scope_271->get("switch_to"));args_310.pos(scope_271->get("has_intro"));return invoke(fn_311,args_310);}());
    // BaseCombatTask.py:621
    ([&]()->V{auto fn_313=attr(global("logger","BaseCombatTask"),"info");Args args_312;args_312.pos(V(std::string{}+"switch_next_char "+format_value(scope_271->get("current_char"),"",-1)+"("+format_value(attr(scope_271->get("current_char"),"char_type"),"",-1)+") -> "+format_value(scope_271->get("switch_to"),"",-1)+"("+format_value(attr(scope_271->get("switch_to"),"char_type"),"",-1)+") has_intro "+format_value(attr(scope_271->get("switch_to"),"has_intro"),"",-1)+" has_sub_dps_intro "+format_value(attr(scope_271->get("switch_to"),"has_sub_dps_intro"),"",-1)+" current_con "+format_value(scope_271->get("current_con"),"",-1)));return invoke(fn_313,args_312);}());
    // BaseCombatTask.py:627
    scope_271->set("ShoreKeeper",import_value("src.char.ShoreKeeper","ShoreKeeper"));
    // BaseCombatTask.py:628
    {V value_314=V(0LL);scope_271->set("last_click",value_314);}
    // BaseCombatTask.py:629
    {V value_315=([&]()->V{auto fn_317=attr(global("time","BaseCombatTask"),"time");Args args_316;return invoke(fn_317,args_316);}());scope_271->set("start",value_315);}
    // BaseCombatTask.py:630
        while(V(true).truth()){
        // BaseCombatTask.py:631
        if(unary("not",([&]()->V{V operand_318;operand_318=([&]()->V{auto fn_320=global("isinstance","BaseCombatTask");Args args_319;args_319.pos(scope_271->get("switch_to"));args_319.pos(scope_271->get("ShoreKeeper"));return invoke(fn_320,args_319);}());if(!operand_318.truth())return operand_318;return scope_271->get("has_intro");}())).truth()){
            // BaseCombatTask.py:632
            ([&]()->V{auto fn_322=attr(self_value(),"check_combat");Args args_321;return invoke(fn_322,args_321);}());
        }
        // BaseCombatTask.py:633
        {V value_323=([&]()->V{auto fn_325=attr(global("time","BaseCombatTask"),"time");Args args_324;return invoke(fn_325,args_324);}());scope_271->set("now",value_323);}
        // BaseCombatTask.py:634
        {V value_326=([&]()->V{auto fn_328=attr(self_value(),"in_team");Args args_327;return invoke(fn_328,args_327);}());auto unpack_329=unpack(value_326,3);scope_271->set("_",unpack_329[0]);scope_271->set("current_index",unpack_329[1]);scope_271->set("_",unpack_329[2]);}
        // BaseCombatTask.py:635
        if(([&]()->V{V compare_330=scope_271->get("current_index");V compare_331;V comparison_result_332;compare_331=attr(scope_271->get("current_char"),"index");comparison_result_332=compare_value("==",compare_330,compare_331);return comparison_result_332;}()).truth()){
            // BaseCombatTask.py:636
            ([&]()->V{auto fn_334=attr(self_value(),"update_lib_portrait_icon");Args args_333;return invoke(fn_334,args_333);}());
            // BaseCombatTask.py:637
            {V value_335=([&]()->V{V operand_336;operand_336=scope_271->get("has_intro");if(operand_336.truth())return operand_336;return ([&]()->V{auto fn_338=attr(scope_271->get("current_char"),"is_con_full");Args args_337;return invoke(fn_338,args_337);}());}());scope_271->set("refreshed_has_intro",value_335);}
            // BaseCombatTask.py:638
            if(([&]()->V{V compare_339=scope_271->get("refreshed_has_intro");V compare_340;V comparison_result_341;compare_340=scope_271->get("has_intro");comparison_result_341=compare_value("!=",compare_339,compare_340);return comparison_result_341;}()).truth()){
                // BaseCombatTask.py:639
                {V value_342=scope_271->get("refreshed_has_intro");scope_271->set("has_intro",value_342);}
                // BaseCombatTask.py:640
                {V value_343=([&]()->V{auto fn_345=attr(self_value(),"_choose_switch_target");Args args_344;args_344.pos(scope_271->get("current_char"));args_344.pos(scope_271->get("has_intro"));args_344.kw("target_low_con",scope_271->get("target_low_con"));return invoke(fn_345,args_344);}());scope_271->set("switch_to",value_343);}
                // BaseCombatTask.py:642
                if(([&]()->V{V operand_346;operand_346=unary("not",scope_271->get("switch_to"));if(operand_346.truth())return operand_346;return ([&]()->V{V compare_347=scope_271->get("switch_to");V compare_348;V comparison_result_349;compare_348=scope_271->get("current_char");comparison_result_349=compare_value("==",compare_347,compare_348);return comparison_result_349;}());}()).truth()){
                    // BaseCombatTask.py:643
                    ([&]()->V{auto fn_351=attr(global("logger","BaseCombatTask"),"warning");Args args_350;args_350.pos(V(std::string{}+format_value(scope_271->get("current_char"),"",-1)+" can't find next char to switch to after intro refresh, performing too fast add a normal attack"));return invoke(fn_351,args_350);}());
                    // BaseCombatTask.py:646
                    ([&]()->V{auto fn_353=attr(scope_271->get("current_char"),"continues_normal_attack");Args args_352;args_352.pos(V(0.2));return invoke(fn_353,args_352);}());
                    // BaseCombatTask.py:647
                    return V{};
                }
                // BaseCombatTask.py:648
                ([&]()->V{auto fn_355=attr(global("logger","BaseCombatTask"),"info");Args args_354;args_354.pos(V(std::string{}+"switch_next_char refreshed target after intro became available: "+format_value(scope_271->get("switch_to"),"",-1)));return invoke(fn_355,args_354);}());
            }
            // BaseCombatTask.py:649
            ([&]()->V{auto fn_357=attr(self_value(),"_apply_intro_flags");Args args_356;args_356.pos(scope_271->get("current_char"));args_356.pos(scope_271->get("switch_to"));args_356.pos(scope_271->get("has_intro"));return invoke(fn_357,args_356);}());
            // BaseCombatTask.py:650
            if(scope_271->get("has_intro").truth()){
                // BaseCombatTask.py:651
                ([&]()->V{auto fn_359=attr(scope_271->get("current_char"),"f_break");Args args_358;args_358.kw("check_f_on_switch",V(true));return invoke(fn_359,args_358);}());
            }
        }
        // BaseCombatTask.py:652
        if(([&]()->V{auto fn_361=attr(scope_271->get("switch_to"),"wait_switch");Args args_360;return invoke(fn_361,args_360);}()).truth()){
            // BaseCombatTask.py:653
            ([&]()->V{auto fn_363=attr(self_value(),"click");Args args_362;return invoke(fn_363,args_362);}());
            // BaseCombatTask.py:654
            ([&]()->V{auto fn_365=attr(self_value(),"sleep");Args args_364;args_364.pos(V(0.1));return invoke(fn_365,args_364);}());
            // BaseCombatTask.py:655
            continue;
        }
        // BaseCombatTask.py:656
        if(([&]()->V{V compare_366=([&]()->V{V left_368=scope_271->get("now");V right_369=scope_271->get("last_click");return official::binary("-",left_368,right_369);}());V compare_367;V comparison_result_370;compare_367=V(0.1);comparison_result_370=compare_value(">",compare_366,compare_367);return comparison_result_370;}()).truth()){
            // BaseCombatTask.py:657
            ([&]()->V{auto fn_372=attr(self_value(),"send_key");Args args_371;args_371.pos(([&]()->V{V left_373=attr(scope_271->get("switch_to"),"index");V right_374=V(1LL);return official::binary("+",left_373,right_374);}()));return invoke(fn_372,args_371);}());
            // BaseCombatTask.py:658
            ([&]()->V{auto fn_376=attr(self_value(),"sleep");Args args_375;args_375.pos(V(0.001));return invoke(fn_376,args_375);}());
            // BaseCombatTask.py:659
            {V value_377=scope_271->get("now");scope_271->set("last_click",value_377);}
            // BaseCombatTask.py:660
            ([&]()->V{auto fn_379=attr(self_value(),"log_debug");Args args_378;args_378.pos(V("switch not detected, send click"));return invoke(fn_379,args_378);}());
            // BaseCombatTask.py:661
            ([&]()->V{auto fn_381=attr(self_value(),"click");Args args_380;return invoke(fn_381,args_380);}());
            // BaseCombatTask.py:662
            ([&]()->V{auto fn_383=attr(self_value(),"sleep");Args args_382;args_382.pos(V(0.001));return invoke(fn_383,args_382);}());
        }
        // BaseCombatTask.py:663
        {V value_384=([&]()->V{auto fn_386=attr(self_value(),"in_team");Args args_385;return invoke(fn_386,args_385);}());auto unpack_387=unpack(value_384,3);scope_271->set("in_team",unpack_387[0]);scope_271->set("current_index",unpack_387[1]);scope_271->set("size",unpack_387[2]);}
        // BaseCombatTask.py:664
        if(unary("not",scope_271->get("in_team")).truth()){
            // BaseCombatTask.py:665
            ([&]()->V{auto fn_389=attr(global("logger","BaseCombatTask"),"info");Args args_388;args_388.pos(V(std::string{}+"not in team while switching chars_"+format_value(scope_271->get("current_char"),"",-1)+"_to_"+format_value(scope_271->get("switch_to"),"",-1)+" "+format_value(([&]()->V{V left_390=scope_271->get("now");V right_391=scope_271->get("start");return official::binary("-",left_390,right_391);}()),"",-1)));return invoke(fn_389,args_388);}());
            // BaseCombatTask.py:668
            ([&]()->V{auto fn_393=attr(self_value(),"raise_not_in_combat");Args args_392;args_392.pos(V(std::string{}+"not in_team while switching"));return invoke(fn_393,args_392);}());
            // BaseCombatTask.py:669
            if(([&]()->V{V compare_394=([&]()->V{V left_396=scope_271->get("now");V right_397=scope_271->get("start");return official::binary("-",left_396,right_397);}());V compare_395;V comparison_result_398;compare_395=attr(self_value(),"switch_char_time_out");comparison_result_398=compare_value(">",compare_394,compare_395);return comparison_result_398;}()).truth()){
                // BaseCombatTask.py:670
                ([&]()->V{auto fn_400=attr(self_value(),"raise_not_in_combat");Args args_399;args_399.pos(V(std::string{}+"switch too long failed chars_"+format_value(scope_271->get("current_char"),"",-1)+"_to_"+format_value(scope_271->get("switch_to"),"",-1)+", "+format_value(([&]()->V{V left_401=scope_271->get("now");V right_402=scope_271->get("start");return official::binary("-",left_401,right_402);}()),"",-1)));return invoke(fn_400,args_399);}());
            }
            // BaseCombatTask.py:672
            ([&]()->V{auto fn_404=attr(self_value(),"next_frame");Args args_403;return invoke(fn_404,args_403);}());
            // BaseCombatTask.py:673
            continue;
        }
        // BaseCombatTask.py:674
        if(([&]()->V{V compare_405=scope_271->get("current_index");V compare_406;V comparison_result_407;compare_406=attr(scope_271->get("switch_to"),"index");comparison_result_407=compare_value("!=",compare_405,compare_406);return comparison_result_407;}()).truth()){
            // BaseCombatTask.py:675
            if(([&]()->V{V compare_408=([&]()->V{V left_410=scope_271->get("now");V right_411=scope_271->get("start");return official::binary("-",left_410,right_411);}());V compare_409;V comparison_result_412;compare_409=V(10LL);comparison_result_412=compare_value(">",compare_408,compare_409);return comparison_result_412;}()).truth()){
                // BaseCombatTask.py:676
                if(attr(self_value(),"debug").truth()){
                    // BaseCombatTask.py:677
                    ([&]()->V{auto fn_414=attr(self_value(),"screenshot");Args args_413;args_413.pos(V(std::string{}+"switch_not_detected_"+format_value(scope_271->get("current_char"),"",-1)+"_to_"+format_value(scope_271->get("switch_to"),"",-1)));return invoke(fn_414,args_413);}());
                }
                // BaseCombatTask.py:678
                ([&]()->V{auto fn_416=attr(self_value(),"raise_not_in_combat");Args args_415;args_415.pos(V("failed switch chars"));return invoke(fn_416,args_415);}());
            }
        }else{
            // BaseCombatTask.py:680
            {V value_417=V(false);set_attr(self_value(),"in_liberation",value_417);}
            // BaseCombatTask.py:681
            if(unary("not",scope_271->get("has_intro")).truth()){
                // BaseCombatTask.py:682
                ([&]()->V{auto fn_419=attr(scope_271->get("current_char"),"f_break");Args args_418;args_418.kw("check_f_on_switch",V(true));return invoke(fn_419,args_418);}());
            }
            // BaseCombatTask.py:683
            ([&]()->V{auto fn_421=attr(scope_271->get("current_char"),"switch_out");Args args_420;args_420.kw("con_full",scope_271->get("has_intro"));return invoke(fn_421,args_420);}());
            // BaseCombatTask.py:684
            {V value_422=V(true);set_attr(scope_271->get("switch_to"),"is_current_char",value_422);}
            // BaseCombatTask.py:685
            {V value_423=([&]()->V{auto fn_425=attr(global("time","BaseCombatTask"),"time");Args args_424;return invoke(fn_425,args_424);}());set_attr(scope_271->get("switch_to"),"last_switch_in_time",value_423);}
            // BaseCombatTask.py:686
            if(scope_271->get("has_intro").truth()){
                // BaseCombatTask.py:687
                {V value_426=([&]()->V{auto fn_428=attr(global("time","BaseCombatTask"),"time");Args args_427;return invoke(fn_428,args_427);}());scope_271->set("current_time",value_426);}
                // BaseCombatTask.py:688
                ([&]()->V{auto fn_430=attr(self_value(),"add_freeze_duration");Args args_429;args_429.pos(scope_271->get("current_time"));args_429.pos(attr(scope_271->get("switch_to"),"intro_motion_freeze_duration"));args_429.pos(unary("-",V(100LL)));return invoke(fn_430,args_429);}());
                // BaseCombatTask.py:689
                {V value_431=scope_271->get("current_time");set_attr(scope_271->get("current_char"),"last_outro_time",value_431);}
            }
            // BaseCombatTask.py:690
            break;
        }
        // BaseCombatTask.py:691
        ([&]()->V{auto fn_433=attr(self_value(),"next_frame");Args args_432;return invoke(fn_433,args_432);}());
    }
    // BaseCombatTask.py:693
    if(scope_271->get("post_action").truth()){
        // BaseCombatTask.py:694
        ([&]()->V{auto fn_435=attr(global("logger","BaseCombatTask"),"debug");Args args_434;args_434.pos(V(std::string{}+"post_action "+format_value(scope_271->get("post_action"),"",-1)));return invoke(fn_435,args_434);}());
        // BaseCombatTask.py:695
        ([&]()->V{auto fn_437=scope_271->get("post_action");Args args_436;args_436.pos(scope_271->get("switch_to"));args_436.pos(scope_271->get("has_intro"));return invoke(fn_437,args_436);}());
    }
    // BaseCombatTask.py:696
    ([&]()->V{auto fn_439=attr(global("logger","BaseCombatTask"),"info");Args args_438;args_438.pos(V(std::string{}+"switch_next_char end "+format_value(([&]()->V{V left_440=attr(scope_271->get("current_char"),"last_switch_time");V right_441=scope_271->get("start");return official::binary("-",left_440,right_441);}()),V(std::string{}+".3f").text(),-1)+"s"));return invoke(fn_439,args_438);}());
return V{};
}),false);
register_method("update_lib_portrait_icon",V::function([this,captured=capture_scope(scope,{}),signature=Signature({{"self",V::missing()}},"","",{})](const Args& official_args)->V{
auto scope_442=bind_arguments(official_args,signature,captured);
scope_442->set("box",V::missing());
scope_442->set("char",V::missing());
scope_442->set("char_index",V::missing());
scope_442->set("i",V::missing());
scope_442->set("match",V::missing());
    // BaseCombatTask.py:1116
    {auto iterator_443=official::iterate(([&]()->V{auto fn_467=global("range","BaseCombatTask");Args args_466;args_466.pos(([&]()->V{auto fn_469=global("len","BaseCombatTask");Args args_468;args_468.pos(attr(self_value(),"chars"));return invoke(fn_469,args_468);}()));return invoke(fn_467,args_466);}()));V item_444;while(iterator_443.next(item_444)){
        scope_442->set("i",item_444);
        // BaseCombatTask.py:1117
        {V value_445=([&]()->V{V left_446=scope_442->get("i");V right_447=V(1LL);return official::binary("+",left_446,right_447);}());scope_442->set("char_index",value_445);}
        // BaseCombatTask.py:1118
        {V value_448=item(attr(self_value(),"chars"),scope_442->get("i"));scope_442->set("char",value_448);}
        // BaseCombatTask.py:1119
        if(([&]()->V{V operand_449;operand_449=unary("not",attr(scope_442->get("char"),"is_current_char"));if(!operand_449.truth())return operand_449;operand_449=([&]()->V{V compare_450=attr(scope_442->get("char"),"ring_index");V compare_451;V comparison_result_452;compare_451=V(0LL);comparison_result_452=compare_value(">=",compare_450,compare_451);return comparison_result_452;}());if(!operand_449.truth())return operand_449;return unary("not",attr(scope_442->get("char"),"_liberation_available"));}()).truth()){
            // BaseCombatTask.py:1120
            {V value_453=([&]()->V{auto fn_455=attr(self_value(),"get_box_by_name");Args args_454;args_454.pos(([&]()->V{auto fn_457=attr(V("lib_mark_char_{}"),"format");Args args_456;args_456.pos(scope_442->get("char_index"));return invoke(fn_457,args_456);}()));return invoke(fn_455,args_454);}());scope_442->set("box",value_453);}
            // BaseCombatTask.py:1121
            {V value_458=([&]()->V{auto fn_460=attr(self_value(),"find_one");Args args_459;args_459.pos(item(global("lib_ready_templates","BaseCombatTask"),attr(scope_442->get("char"),"ring_index")));args_459.kw("box",scope_442->get("box"));args_459.kw("threshold",V(0.8));return invoke(fn_460,args_459);}());scope_442->set("match",value_458);}
            // BaseCombatTask.py:1122
            if(scope_442->get("match").truth()){
                // BaseCombatTask.py:1123
                {V value_461=V(true);set_attr(scope_442->get("char"),"_liberation_available",value_461);}
                // BaseCombatTask.py:1124
                ([&]()->V{auto fn_463=attr(self_value(),"log_debug");Args args_462;args_462.pos(([&]()->V{auto fn_465=attr(V("checking liberation_available by template {} {}"),"format");Args args_464;args_464.pos(scope_442->get("char"));args_464.pos(scope_442->get("match"));return invoke(fn_465,args_464);}()));return invoke(fn_463,args_462);}());
            }
        }
    }
    }
return V{};
}),false);
}
}
