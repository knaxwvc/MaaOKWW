#pragma once
#include <memory>
#include <string_view>
#include "YangYangSpOriginal.h"
#include "Yinlin.h"
#include "Verina.h"
#include "OriginalShoreKeeper.h"
#include "HsinOriginal.h"
#include "SuisuiOriginal.h"
#include "Taoqi.h"
#include "RoverOriginal.h"
#include "Encore.h"
#include "Jianxin.h"
#include "Sanhua.h"
#include "JinhsiOriginal.h"
#include "Yuanwu.h"
#include "ChangliOriginal.h"
#include "Chixia.h"
#include "Danjin.h"
#include "Baizhi.h"
#include "Calcharo.h"
#include "Jiyan.h"
#include "Mortefi.h"
#include "ZhezhiOriginal.h"
#include "Xiangliyao.h"
#include "CamellyaOriginal.h"
#include "Youhu.h"
#include "CarlottaOriginal.h"
#include "Roccia.h"
#include "PhoebeOriginal.h"
#include "BrantOriginal.h"
#include "CantarellaOriginal.h"
#include "ZaniOriginal.h"
#include "CiacconaOriginal.h"
#include "CartethyiaOriginal.h"
#include "LupaOriginal.h"
#include "Phrolova.h"
#include "AugustaOriginal.h"
#include "IunoOriginal.h"
#include "Galbrena.h"
#include "Qiuyuan.h"
#include "ChisaOriginal.h"
#include "DeniaOriginal.h"
#include "DoulingOriginal.h"
#include "LinnaiOriginal.h"
#include "MornyeOriginal.h"
#include "AemeathOriginal.h"
#include "XigelikaOriginal.h"
#include "LuhesiOriginal.h"
#include "HiyukiOriginal.h"
#include "LucillaOriginal.h"
#include "LucyOriginal.h"
#include "RebeccaOriginal.h"
#include "QingxiaoOriginal.h"

inline bool has_original_strategy(std::string_view name) {
    for (const auto& definition : character_definitions) if (name == definition.class_name) return true;
    return false;
}
inline std::unique_ptr<OriginalBaseChar> make_original_character(
    std::string_view name, OriginalCombatIO& io, OriginalSwitchCharacter& state) {
    if (name == "YangYangSp") return std::make_unique<YangYangSpOriginal>(io, state);
    if (name == "Yinlin") return std::make_unique<Yinlin>(io, state);
    if (name == "Verina") return std::make_unique<Verina>(io, state);
    if (name == "ShoreKeeper") return std::make_unique<OriginalShoreKeeper>(io, state);
    if (name == "Suisui") return std::make_unique<SuisuiOriginal>(io, state);
    if (name == "Taoqi") return std::make_unique<Taoqi>(io, state);
    if (name == "Rover") return std::make_unique<RoverOriginal>(io, state);
    if (name == "Encore") return std::make_unique<Encore>(io, state);
    if (name == "Jianxin") return std::make_unique<Jianxin>(io, state);
    if (name == "Sanhua") return std::make_unique<Sanhua>(io, state);
    if (name == "Jinhsi") return std::make_unique<JinhsiOriginal>(io, state);
    if (name == "Yuanwu") return std::make_unique<Yuanwu>(io, state);
    if (name == "Changli") return std::make_unique<ChangliOriginal>(io, state);
    if (name == "Chixia") return std::make_unique<Chixia>(io, state);
    if (name == "Danjin") return std::make_unique<Danjin>(io, state);
    if (name == "Baizhi") return std::make_unique<Baizhi>(io, state);
    if (name == "Calcharo") return std::make_unique<Calcharo>(io, state);
    if (name == "Jiyan") return std::make_unique<Jiyan>(io, state);
    if (name == "Mortefi") return std::make_unique<Mortefi>(io, state);
    if (name == "Zhezhi") return std::make_unique<ZhezhiOriginal>(io, state);
    if (name == "Xiangliyao") return std::make_unique<Xiangliyao>(io, state);
    if (name == "Camellya") return std::make_unique<CamellyaOriginal>(io, state);
    if (name == "Youhu") return std::make_unique<Youhu>(io, state);
    if (name == "Carlotta") return std::make_unique<CarlottaOriginal>(io, state);
    if (name == "Roccia") return std::make_unique<Roccia>(io, state);
    if (name == "Phoebe") return std::make_unique<PhoebeOriginal>(io, state);
    if (name == "Brant") return std::make_unique<BrantOriginal>(io, state);
    if (name == "Cantarella") return std::make_unique<CantarellaOriginal>(io, state);
    if (name == "Zani") return std::make_unique<ZaniOriginal>(io, state);
    if (name == "Ciaccona") return std::make_unique<CiacconaOriginal>(io, state);
    if (name == "Cartethyia") return std::make_unique<CartethyiaOriginal>(io, state);
    if (name == "Lupa") return std::make_unique<LupaOriginal>(io, state);
    if (name == "Phrolova") return std::make_unique<Phrolova>(io, state);
    if (name == "Augusta") return std::make_unique<AugustaOriginal>(io, state);
    if (name == "Iuno") return std::make_unique<IunoOriginal>(io, state);
    if (name == "Galbrena") return std::make_unique<Galbrena>(io, state);
    if (name == "Qiuyuan") return std::make_unique<Qiuyuan>(io, state);
    if (name == "Chisa") return std::make_unique<ChisaOriginal>(io, state);
    if (name == "Denia") return std::make_unique<DeniaOriginal>(io, state);
    if (name == "Douling") return std::make_unique<DoulingOriginal>(io, state);
    if (name == "Linnai") return std::make_unique<LinnaiOriginal>(io, state);
    if (name == "Mornye") return std::make_unique<MornyeOriginal>(io, state);
    if (name == "Aemeath") return std::make_unique<AemeathOriginal>(io, state);
    if (name == "Xigelika") return std::make_unique<XigelikaOriginal>(io, state);
    if (name == "Luhesi") return std::make_unique<LuhesiOriginal>(io, state);
    if (name == "Hiyuki") return std::make_unique<HiyukiOriginal>(io, state);
    if (name == "Lucilla") return std::make_unique<LucillaOriginal>(io, state);
    if (name == "Lucy") return std::make_unique<LucyOriginal>(io, state);
    if (name == "Rebecca") return std::make_unique<RebeccaOriginal>(io, state);
    if (name == "Qingxiao") return std::make_unique<QingxiaoOriginal>(io, state);
    if (name == "Hsin") return std::make_unique<HsinOriginal>(io, state);
    return std::make_unique<OriginalBaseChar>(io,state);
}
