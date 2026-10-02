#pragma once
#include <Windows.h>
#include <filesystem>
#include <cwctype>

struct CombatConfig {
    bool auto_target=true,use_liberation=true,check_levitator=true,switch_healer=true;
    bool chisa_dps=false,iuno_c6=false,open_world=true;
    int resonance='E',echo='Q',liberation='R',tool='T',execution='F';
    int team=0;
    static int read_key(const wchar_t* key,int fallback,const std::filesystem::path& path) {
        wchar_t value[32]{};wchar_t initial[2]{wchar_t(fallback),0};
        GetPrivateProfileStringW(L"Keys",key,initial,value,32,path.c_str());
        if(wcslen(value)==1)return int(std::towupper(value[0]));
        if(_wcsicmp(value,L"SPACE")==0)return VK_SPACE;
        if(_wcsicmp(value,L"TAB")==0)return VK_TAB;
        return fallback;
    }
    static CombatConfig load(const std::filesystem::path& root) {
        CombatConfig c;const auto path=root/L"config.ini";
        c.auto_target=GetPrivateProfileIntW(L"Combat",L"AutoTarget",1,path.c_str())!=0;
        c.use_liberation=GetPrivateProfileIntW(L"Combat",L"UseLiberation",1,path.c_str())!=0;
        c.check_levitator=GetPrivateProfileIntW(L"Combat",L"CheckLevitator",1,path.c_str())!=0;
        c.switch_healer=GetPrivateProfileIntW(L"Combat",L"SwitchHealer",1,path.c_str())!=0;
        c.open_world=GetPrivateProfileIntW(L"Combat",L"OpenWorld",1,path.c_str())!=0;
        c.chisa_dps=GetPrivateProfileIntW(L"Characters",L"ChisaDPS",0,path.c_str())!=0;
        c.iuno_c6=GetPrivateProfileIntW(L"Characters",L"IunoC6",0,path.c_str())!=0;
        c.team=GetPrivateProfileIntW(L"Combat",L"Team",0,path.c_str());
        c.resonance=read_key(L"Resonance",'E',path);c.echo=read_key(L"Echo",'Q',path);
        c.liberation=read_key(L"Liberation",'R',path);c.tool=read_key(L"Tool",'T',path);c.execution=read_key(L"Execution",'F',path);
        return c;
    }
    int map_key(int key) const {
        return key=='E'?resonance:key=='Q'?echo:key=='R'?liberation:key=='T'?tool:key=='F'?execution:key;
    }
};
