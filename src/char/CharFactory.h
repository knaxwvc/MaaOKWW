#pragma once
#include <array>
#include <string_view>

// Generated from the original OK-WW CharFactory.py and Labels.py.
// This is character recognition metadata. Combat methods are ported separately.
enum class CharacterRole { MAIN_DPS, SUB_DPS, HEALER };
enum class CharacterElement { UNKNOWN, SPECTRO, ELECTRIC, FIRE, ICE, WIND, HAVOC };
struct CharacterDefinition {
    std::string_view class_name;
    std::string_view portrait_template;
    const char* alternate_portrait_template;
    std::string_view portrait_image;
    const char* alternate_portrait_image;
    CharacterRole role;
    CharacterElement element;
    int buff_seconds;
    bool target_box_short_combat_check;
};
inline constexpr std::array<CharacterDefinition, 51> character_definitions{{
    {"YangYangSp", "yangyang_sp", nullptr, "258_141.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::HAVOC, 14, false},
    {"Yinlin", "char_yinlin", nullptr, "98_20.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Verina", "char_verina", nullptr, "95_19.png", nullptr, CharacterRole::HEALER, CharacterElement::SPECTRO, 28, false},
    {"ShoreKeeper", "char_shorekeeper", nullptr, "93_124.png", nullptr, CharacterRole::HEALER, CharacterElement::SPECTRO, 28, false},
    {"Suisui", "char_suisui", nullptr, "264_152.png", nullptr, CharacterRole::HEALER, CharacterElement::UNKNOWN, 28, false},
    {"Taoqi", "char_taoqi", nullptr, "94_21.png", nullptr, CharacterRole::HEALER, CharacterElement::HAVOC, 28, false},
    {"Rover", "char_rover", "char_rover_male", "89_311.png", "90_159.png", CharacterRole::MAIN_DPS, CharacterElement::UNKNOWN, 14, false},
    {"Encore", "char_encore", nullptr, "74_18.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::FIRE, 14, false},
    {"Jianxin", "char_jianxin", nullptr, "77_16.png", nullptr, CharacterRole::HEALER, CharacterElement::WIND, 28, false},
    {"Sanhua", "char_sanhua", "char_sanhua2", "91_17.png", "92_388.png", CharacterRole::SUB_DPS, CharacterElement::ICE, 14, false},
    {"Jinhsi", "char_jinhsi", "char_jinhsi2", "78_14.png", "79_58.png", CharacterRole::MAIN_DPS, CharacterElement::SPECTRO, 14, false},
    {"Yuanwu", "char_yuanwu", nullptr, "100_313.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Changli", "chang_changli", "char_changli2", "50_236.png", "67_56.png", CharacterRole::MAIN_DPS, CharacterElement::FIRE, 14, false},
    {"Chixia", "char_chixia", nullptr, "69_356.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::FIRE, 14, false},
    {"Danjin", "char_danjin", nullptr, "72_354.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::HAVOC, 14, false},
    {"Baizhi", "char_baizhi", nullptr, "59_270.png", nullptr, CharacterRole::HEALER, CharacterElement::ICE, 28, false},
    {"Calcharo", "char_calcharo", nullptr, "61_271.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Jiyan", "char_jiyan", nullptr, "80_272.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::WIND, 14, false},
    {"Mortefi", "char_mortefi", nullptr, "85_355.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::FIRE, 14, false},
    {"Zhezhi", "char_zhezhi", nullptr, "103_158.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::ICE, 14, false},
    {"Xiangliyao", "char_xiangliyao", nullptr, "96_252.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Camellya", "char_camellya", nullptr, "62_154.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::HAVOC, 14, false},
    {"Youhu", "char_youhu", nullptr, "99_414.png", nullptr, CharacterRole::HEALER, CharacterElement::ICE, 28, false},
    {"Carlotta", "char_carlotta", "char_carlotta2", "64_178.png", "65_128.png", CharacterRole::MAIN_DPS, CharacterElement::ICE, 14, false},
    {"Roccia", "char_roccia", nullptr, "88_122.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::HAVOC, 14, false},
    {"Phoebe", "char_phoebe", nullptr, "86_11.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::SPECTRO, 14, false},
    {"Brant", "char_brant", nullptr, "60_136.png", nullptr, CharacterRole::HEALER, CharacterElement::FIRE, 28, false},
    {"Cantarella", "char_cantarella", nullptr, "63_404.png", nullptr, CharacterRole::HEALER, CharacterElement::HAVOC, 28, false},
    {"Zani", "char_zani", "char_zani2", "101_28.png", "102_278.png", CharacterRole::MAIN_DPS, CharacterElement::SPECTRO, 14, false},
    {"Ciaccona", "char_ciaccona", nullptr, "71_420.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::WIND, 14, false},
    {"Cartethyia", "char_cartethyia", nullptr, "66_168.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::WIND, 14, false},
    {"Lupa", "char_lupa", nullptr, "83_140.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::FIRE, 14, false},
    {"Phrolova", "char_phrolova", nullptr, "87_418.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::HAVOC, 14, false},
    {"Augusta", "Augusta", nullptr, "1_53.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Iuno", "char_iuno", nullptr, "76_342.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::WIND, 14, false},
    {"Galbrena", "char_galbrena", nullptr, "75_132.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::FIRE, 14, false},
    {"Qiuyuan", "char_chouyuan", nullptr, "70_114.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::WIND, 14, false},
    {"Chisa", "char_chisa", "char_chisa2", "68_276.png", "263_151.png", CharacterRole::HEALER, CharacterElement::HAVOC, 20, false},
    {"Denia", "char_denia", nullptr, "233_89.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::FIRE, 14, false},
    {"Douling", "char_douling", nullptr, "73_340.png", nullptr, CharacterRole::HEALER, CharacterElement::ELECTRIC, 28, false},
    {"Linnai", "char_linnai", "char_linnai2", "81_72.png", "262_150.png", CharacterRole::SUB_DPS, CharacterElement::SPECTRO, 14, false},
    {"Mornye", "char_moning", "char_moning_new", "84_352.png", "229_85.png", CharacterRole::HEALER, CharacterElement::FIRE, 28, false},
    {"Aemeath", "char_aemeath", nullptr, "58_105.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::FIRE, 14, false},
    {"Xigelika", "char_xigelika", nullptr, "97_435.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::WIND, 14, false},
    {"Luhesi", "char_luhesi", nullptr, "82_426.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::SPECTRO, 14, false},
    {"Hiyuki", "char_hiyuki", nullptr, "225_75.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::ICE, 14, false},
    {"Lucilla", "char_lucilla", nullptr, "234_98.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::ICE, 14, true},
    {"Lucy", "char_lucy", nullptr, "243_112.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::SPECTRO, 14, false},
    {"Rebecca", "char_rebecca", nullptr, "241_113.png", nullptr, CharacterRole::SUB_DPS, CharacterElement::ELECTRIC, 14, false},
    {"Qingxiao", "char_qingxiao", nullptr, "275_171.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::WIND, 14, false},
    {"Hsin", "char_hsin", nullptr, "hsin_282_183.png", nullptr, CharacterRole::MAIN_DPS, CharacterElement::ELECTRIC, 14, false},
}};
