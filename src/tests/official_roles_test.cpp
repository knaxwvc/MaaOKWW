#define NOMINMAX
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include "MaaFramework/MaaAPI.h"
#define MAAOKWW_API_HELPER_DEFINED
template<class F>F api(HMODULE m,const char* name){return reinterpret_cast<F>(GetProcAddress(m,name));}
#include "../official/OfficialCharacter.h"
#include "OfficialFixture.h"
#include <cassert>
using namespace official;
int main(int argc,char** argv){try{
    SetDllDirectoryW(L"bin");if(!LoadLibraryW(L"opencv_world4_maa.dll"))throw std::runtime_error("offline Maa OpenCV load failed");
    if(argc>2&&std::string(argv[2])=="--team-size"){std::ofstream output(argv[1]);for(const std::string name:{"Aemeath","Qingxiao","Camellya","Hsin","Rover"})for(int count:{1,2})for(const auto& d:character_definitions)if(d.class_name==name){official_test::Fixture fixture(d,1,count);auto row=fixture.run();set_item(row,V("team_size"),V(count));output<<official_test::json(row)<<'\n';}return 0;}
    if(argc>2&&std::string(argv[2])=="--vision"){std::ofstream output(argv[1]);const CharacterDefinition* definition=nullptr;for(const auto& d:character_definitions)if(d.class_name=="Camellya")definition=&d;
        for(int width:{64,128,512})for(int pattern=0;pattern<5;++pattern){official_test::Fixture fixture(*definition,0);auto gray=std::make_shared<Array>(std::vector<int>{12,width},"uint8");
            for(int y=0;y<12;++y)for(int x=0;x<width;++x){bool white=pattern==1||pattern==2&&x%8<4||pattern==3&&x<width/2&&x%12<6||pattern==4&&((x*17+y*31)%11<3);gray->number_put(size_t(y)*width+x,white?255:0);}
            V row=V::dict();set_item(row,V("width"),V(width));set_item(row,V("pattern"),V(pattern));set_item(row,V("result"),fixture.actors[0]->call_official("detect_stripe_region",{gray->value()}));output<<official_test::json(row)<<'\n';
        }
        for(int pattern=0;pattern<3;++pattern){official_test::Fixture fixture(*definition,0);for(int y=0;y<64;++y)for(int x=0;x<64;++x){auto* p=fixture.image.pixels.bytes->data()+(size_t(y)*1280+x)*3;p[0]=pattern==0?0:x%3==0?60:10;p[1]=pattern==0?0:70;p[2]=pattern==0?0:80;}
            V color=V::dict();set_item(color,V("b"),V::tuple({V(50),V(65)}));set_item(color,V("g"),V::tuple({V(60),V(80)}));set_item(color,V("r"),V::tuple({V(70),V(90)}));
            V row=V::dict();set_item(row,V("mask_pattern"),V(pattern));set_item(row,V("result"),fixture.actors[0]->call_official("calculate_color_percentage_in_masked",{color,box_value({0,0,64,64},"fixture"),V(pattern==2?0.395:0.1),V(0.496)}));output<<official_test::json(row)<<'\n';
        }return 0;
    }
    if(argc>1){std::ofstream output(argv[1]);for(const auto& d:character_definitions)for(int scenario=0;scenario<3;++scenario){official_test::Fixture fixture(d,scenario);output<<official_test::json(fixture.run())<<'\n';}return 0;}
    int count=0;
    for(const auto& definition:character_definitions){
        OriginalCombatIO io{};OriginalSwitchCharacter member{};member.definition=&definition;member.index=0;member.ring_index=static_cast<int>(definition.element)-1;
        FrameState frame{};frame.width=1280;frame.height=720;frame.channels=3;frame.pixels.bytes=std::make_shared<std::vector<unsigned char>>(1280*720*3,0);
        io.seconds=[](){return 100.0;};io.stop_requested=[](){return false;};io.frame=[&](){return frame;};io.team_size=[](){return 1;};io.member_at=[&](int slot){return slot==1?&member:nullptr;};
        io.find_character=[](std::string_view)->OriginalBaseChar*{return nullptr;};
        io.template_frame=[](std::string_view){FrameState out{};out.width=48;out.height=48;out.channels=3;out.pixels.bytes=std::make_shared<std::vector<unsigned char>>(48*48*3,0);return out;};
        OfficialCharacter actor(io,member,std::string(definition.class_name));
        assert(actor.get("index").integral()==0);actor.reset_state();
        std::cout<<"constructed "<<definition.class_name<<" role="<<actor.get("char_type").text()<<" buff="<<actor.get("buff_time").text()<<'\n';++count;
    }
    std::cout<<"official_native_constructor_check roles="<<count<<" game_input_sent=0\n";
    const auto& definition=character_definitions[0];
    for(bool previous:{false,true})for(bool check:{false,true}){official_test::Fixture fixture(definition,0);fixture.io.skip_combat_check=previous;bool seen=false,raised=false;
        fixture.io.pause=[&](double,bool){seen=true;assert(fixture.io.skip_combat_check==(previous||!check));throw OriginalCombatStopped();};
        Args args;args.pos(V(0.1));args.kw("check_combat",V(check));try{fixture.actors[0]->call_official("sleep",args);}catch(const OriginalCombatStopped&){raised=true;}
        assert(seen&&raised&&fixture.io.skip_combat_check==previous);
    }
    {official_test::Fixture fixture(definition,0);int depth=0,seen=0;fixture.io.pause=[&](double,bool){assert(fixture.io.skip_combat_check);++seen;if(depth==0){++depth;fixture.actors[0]->call_official("sleep",{V(0.05)});assert(fixture.io.skip_combat_check);++seen;}};
        Args args;args.pos(V(0.1));args.kw("check_combat",V(false));fixture.actors[0]->call_official("sleep",args);assert(seen==3&&!fixture.io.skip_combat_check);
    }
    std::cout<<"official_sleep_restore_check cases=5 game_input_sent=0\n";
    return count==52?0:1;
}catch(const std::exception& error){std::cerr<<"FAIL "<<error.what()<<'\n';return 1;}}
