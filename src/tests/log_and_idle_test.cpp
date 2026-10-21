#define wmain maa_fixture_application_main
#include "../main.cpp"
#undef wmain
#include <cassert>
#include <sstream>

// Maa's custom controller receives synthetic pixels and records requests.
// It never connects to a game window or sends Windows input.
struct LogfixController {
    HMODULE dll{};
    fs::path root;
    std::vector<unsigned char> pixels;
    int width=1920,height=1080;
    int captures=0,downs=0,releases=0,escape_downs=0;
    int stop_after=15,hidden_downs=0;
    bool stop_on_input=false;
    bool hidden_frame=false;
    std::function<void()> on_capture;
    void stop(){std::ofstream(root/"stop.flag")<<"fixture stop\n";}
    static MaaBool screencap(void* arg,MaaImageBuffer* output){
        auto& self=*static_cast<LogfixController*>(arg);
        ++self.captures;
        if(self.on_capture)self.on_capture();
        if(self.captures>=self.stop_after)self.stop();
        return api<decltype(&MaaImageBufferSetRawData)>(self.dll,"MaaImageBufferSetRawData")(
            output,self.pixels.data(),self.width,self.height,16);
    }
    static MaaBool uuid(void* arg,MaaStringBuffer* output){
        auto& self=*static_cast<LogfixController*>(arg);
        return api<decltype(&MaaStringBufferSet)>(self.dll,"MaaStringBufferSet")(output,"maa-logfix-fixture");
    }
    static MaaBool touch_down(int32_t,int32_t,int32_t,int32_t,void* arg){
        auto& self=*static_cast<LogfixController*>(arg);
        ++self.downs;if(self.hidden_frame)++self.hidden_downs;
        if(self.stop_on_input)self.stop();return true;
    }
    static MaaBool key_down(int32_t key,void* arg){
        auto& self=*static_cast<LogfixController*>(arg);
        ++self.downs;if(self.hidden_frame)++self.hidden_downs;if(key==VK_ESCAPE)++self.escape_downs;
        if(self.stop_on_input)self.stop();return true;
    }
    static MaaBool release(int32_t,void* arg){++static_cast<LogfixController*>(arg)->releases;return true;}
};

struct StoppedFixture final : OriginalBaseChar {
    using OriginalBaseChar::OriginalBaseChar;
    void verify(){check_combat();}
};

int main(int argc,char** argv){
    assert(argc==3);
    const fs::path source=fs::absolute(argv[1]),scratch=fs::absolute(argv[2]);
    assert(source!=scratch);
    const auto output_before=std::cout.rdbuf(),error_before=std::cerr.rdbuf();
    std::stringbuf stamped;
    int hidden_hud_screens=0;
    {
        MaaTimestampedLog timestamp(&stamped);
        MaaLogRedirect redirect(&timestamp);
        std::cout<<"fragment";std::cout<<"ed\nsecond\n";std::cerr<<"third\n";
    }
    assert(std::cout.rdbuf()==output_before && std::cerr.rdbuf()==error_before);
    const std::regex timestamp(R"(^\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{3}\] (fragmented|second|third)$)");
    std::istringstream lines(stamped.str());std::string line;int count=0;
    while(std::getline(lines,line)){assert(std::regex_match(line,timestamp));++count;}
    assert(count==3);
    const std::string rejected=R"({"all":[{"box":[0,0,10,10],"score":0.46}],"best":null,"filtered":[]})";
    assert(maa_match_detail_score(rejected,"best")==-1);
    assert(std::abs(maa_match_detail_score(rejected,"all")-0.46)<1e-9);
    const std::string accepted=R"({"all":[{"score":0.93}],"best":{"score":0.92}})";
    assert(std::abs(maa_match_detail_score(accepted,"best")-0.92)<1e-9);
    assert(maa_match_detail_score(R"({"all":[]})","all")==-1);
    assert(maa_match_detail_score(R"({"best":{"score":null}})","best")==-1);
    assert(maa_match_detail_score(R"({"best":{"score":1e999}})","best")==-1);
    OriginalCombatIO stopped_io;OriginalSwitchCharacter stopped_member;bool target_called=false;
    stopped_io.stop_requested=[](){return true;};
    stopped_io.target_present=[&](){target_called=true;return true;};
    StoppedFixture stopped(stopped_io,stopped_member);
    try{stopped.verify();assert(false);}catch(const OriginalCombatStopped&){}
    assert(!target_called);

    fs::create_directories(scratch);
    fs::copy(source/"resource",scratch/"resource",fs::copy_options::recursive|fs::copy_options::overwrite_existing);
    fs::copy_file(source/"config.example.ini",scratch/"config.ini",fs::copy_options::overwrite_existing);
    assert(SetDllDirectoryW((source/"bin").c_str()));
    HMODULE dll=LoadLibraryW((source/"bin"/"MaaFramework.dll").c_str());assert(dll);
    bool debug=false;
    api<decltype(&MaaGlobalSetOption)>(dll,"MaaGlobalSetOption")(MaaGlobalOption_DebugMode,&debug,sizeof(debug));
    api<decltype(&MaaGlobalSetOption)>(dll,"MaaGlobalSetOption")(MaaGlobalOption_SaveDraw,&debug,sizeof(debug));
    MaaTimerResolution timer;
    LogfixController state{dll,scratch,std::vector<unsigned char>(1920*1080*3,0)};
    MaaCustomControllerCallbacks callbacks{};
    callbacks.connect=static_connect;callbacks.connected=static_connected;
    callbacks.request_uuid=LogfixController::uuid;callbacks.get_features=static_features;
    callbacks.screencap=LogfixController::screencap;callbacks.inactive=static_inactive;
    callbacks.touch_down=LogfixController::touch_down;callbacks.touch_up=LogfixController::release;
    callbacks.key_down=LogfixController::key_down;callbacks.key_up=LogfixController::release;
    auto* controller=api<decltype(&MaaCustomControllerCreate)>(dll,"MaaCustomControllerCreate")(&callbacks,&state);assert(controller);
    assert(api<decltype(&MaaControllerWait)>(dll,"MaaControllerWait")(controller,
        api<decltype(&MaaControllerPostConnection)>(dll,"MaaControllerPostConnection")(controller))==MaaStatus_Succeeded);
    bool raw_size=true;
    assert(api<decltype(&MaaControllerSetOption)>(dll,"MaaControllerSetOption")(
        controller,MaaCtrlOption_ScreenshotUseRawSize,&raw_size,sizeof(raw_size)));
    auto* resource=api<decltype(&MaaResourceCreate)>(dll,"MaaResourceCreate")();assert(resource);
    const auto bundle=api<decltype(&MaaResourcePostBundle)>(dll,"MaaResourcePostBundle")(resource,(scratch/"resource").string().c_str());
    assert(api<decltype(&MaaResourceWait)>(dll,"MaaResourceWait")(resource,bundle)==MaaStatus_Succeeded);
    auto* tasker=api<decltype(&MaaTaskerCreate)>(dll,"MaaTaskerCreate")();assert(tasker);
    assert(api<decltype(&MaaTaskerBindController)>(dll,"MaaTaskerBindController")(tasker,controller));
    assert(api<decltype(&MaaTaskerBindResource)>(dll,"MaaTaskerBindResource")(tasker,resource));
    {
        MaaFrameRecognition image(dll,tasker,controller,source);image.width=1920;image.height=1080;
        const auto paste=[&](const char* file,const char* name){
            const auto* box=find_original_box(name);assert(box);
            const auto roi=scale_original_box(*box,1920,1080);
            const auto& original=image.prepare_template(file,false,0,1);
            assert(original.w<=roi.width && original.h<=roi.height);
            for(int y=0;y<original.h;++y)std::copy_n(original.pixels.data()+size_t(y)*original.w*3,
                original.w*3,state.pixels.data()+(size_t(roi.y+y)*1920+roi.x)*3);
        };
        paste("56_34.png","char_1_text");paste("52_27.png","char_2_text");
        // A second template may share ROI pixels; a new frame must not.
        const auto saved_pixels=state.pixels;
        const auto roi_status=run_maa_native_action(dll,resource,tasker,[&](MaaContext* ctx){
            MaaFrameRecognition observed(dll,tasker,controller,source,ctx);
            assert(observed.capture());
            auto roi=scale_original_box(*find_original_box("char_1_text"),observed.width,observed.height);
            roi.width+=4;roi.height+=4;
            const auto first=observed.match("56_34.png",roi,0.8);
            assert(first.hit && first.score>0.99);
            observed.match("52_27.png",roi,0.8);
            assert(observed.region_preparations==1 && observed.region_reuses==1);
            const auto calls_before=observed.recognition_calls();
            for(int frame=0;frame<20;++frame){
                assert(observed.capture());
                const auto repeated=observed.match("56_34.png",roi,0.8);
                assert(repeated.hit==first.hit && repeated.score==first.score && repeated.box.x==first.box.x);
                observed.match("52_27.png",roi,0.8);
            }
            assert(observed.recognition_calls()==calls_before && observed.unchanged_match_reuses==40);
            // Threshold changes cannot reuse the result from another request.
            observed.match("56_34.png",roi,0.9);
            assert(observed.recognition_calls()==calls_before+1);
            // Every BGR byte matters, even one byte outside the winning patch.
            state.pixels[(size_t(roi.y)*1920+roi.x)*3]^=1;
            assert(observed.capture());
            observed.match("56_34.png",roi,0.8);
            assert(observed.recognition_calls()==calls_before+2);
            std::fill(state.pixels.begin(),state.pixels.end(),0);
            assert(observed.capture());
            const auto removed=observed.match("56_34.png",roi,0.8);
            assert(!removed.hit && observed.region_preparations==3);
            OriginalCooldown cooldown(dll,controller,tasker,ctx);
            double now=100;
            cooldown.set_timing([&]{return now;},[&](double start){return now-start;});
            assert(cooldown.refresh_scene(1,observed.buffer()));
            assert(cooldown.recognition_calls()==1);
            assert(cooldown.refresh_scene(1,observed.buffer()) && cooldown.recognition_calls()==1);
            assert(cooldown.refresh_scene(2,observed.buffer()) && cooldown.recognition_calls()==2);
            assert(!cooldown.last_detail(1).empty() && !cooldown.last_detail(2).empty());
            assert(!cooldown.refresh_scene(0,observed.buffer()) && cooldown.recognition_calls()==2);
            cooldown.reset_scene();
            assert(cooldown.refresh_scene(2,observed.buffer()) && cooldown.recognition_calls()==3);
            std::cout<<"cache_regression identical_frames=20 template_calls_before=2 template_calls_after="
                <<calls_before<<" avoided_calls=40 changed_pixel_recomputed=1 threshold_recomputed=1 slot_ocr_reads=2\n";
            return true;
        });
        assert(roi_status==MaaStatus_Succeeded);
        state.pixels=saved_pixels;
        const auto run=[&](){
            fs::remove(scratch/"stop.flag");state.captures=state.downs=state.releases=state.escape_downs=state.hidden_downs=0;
            std::stringbuf logs;
            {
                MaaLogRedirect capture(&logs);
                const auto status=run_maa_native_action(dll,resource,tasker,[&](MaaContext* ctx){
                    return run_combat(scratch,dll,controller,tasker,"--combat-one",2,ctx)==MaaStatus_Succeeded;
                });
                assert(status==MaaStatus_Succeeded);
            }
            return logs.str();
        };
        const auto idle=run();
        assert(state.captures>=15 && state.downs==0 && state.releases>=13);
        assert(idle.find("character_slot=")==std::string::npos);
        assert(idle.find("original_combat_enter")==std::string::npos);
        std::ofstream(scratch/"idle-result.log")<<idle;
        for(int slot=1;slot<=3;++slot){
            const char* name=slot==3?"Lucilla":slot==2?"Verina":"Linnai";
            const CharacterDefinition* selected=nullptr;
            for(const auto& definition:character_definitions)if(definition.class_name==name)selected=&definition;
            assert(selected);
            const auto box="box_char_"+std::to_string(slot);
            paste(selected->portrait_image.data(),box.c_str());
        }
        paste("159_97.png","target_box_short");
        state.stop_on_input=true;
        const auto short_target=run();
        std::ofstream(scratch/"short-target-result.log")<<short_target;
        assert(short_target.find("character_slot=3 class=Lucilla")!=std::string::npos);
        assert(short_target.find("original_combat_enter slot=3")!=std::string::npos);
        assert(short_target.find("original_perform class=Lucilla slot=3")!=std::string::npos);
        assert(short_target.find("input_requests_E=1")!=std::string::npos);
        assert(state.downs>0 && state.escape_downs==0 && state.releases>=13);
        assert(short_target.find("Maa native error")==std::string::npos);
        const auto combat_pixels=state.pixels;
        for(bool recover:{false,true}){
            int hidden_captures=0;
            state.stop_on_input=false;state.stop_after=60;
            state.on_capture=[&]{
                state.hidden_frame=state.downs>0 && hidden_captures<12;
                if(state.hidden_frame){
                    ++hidden_captures;state.pixels.assign(combat_pixels.size(),0);
                    if(!recover && hidden_captures>=12)state.stop();
                }else{
                    state.pixels=combat_pixels;
                    if(recover && hidden_captures>=12)state.stop_on_input=true;
                }
            };
            const auto lost=run();
            std::ofstream(scratch/(recover?"hud-recovery-result.log":"hud-stop-result.log"))<<lost;
            assert(lost.find("original_hud_suspend")!=std::string::npos &&
                lost.find("original_combat_exit")==std::string::npos &&
                lost.find("original_team performances=")==std::string::npos);
            assert(state.hidden_downs==0 && state.releases>=26);
            if(recover)assert(lost.find("original_hud_recovered")!=std::string::npos);
            state.on_capture={};state.hidden_frame=false;state.pixels=combat_pixels;
        }
        state.stop_after=15;state.stop_on_input=true;
        // Replay the four saved problem frames through actual Maa recognition.
        // The cache directory is an optional local dataset, never a game input.
        const auto replay=source/".cache"/"hud-log-20261017";
        if(fs::exists(replay))for(const auto& file:fs::directory_iterator(replay)){
            if(file.path().extension()!=".png")continue;
            std::ifstream input(file.path(),std::ios::binary);
            std::vector<unsigned char> bytes((std::istreambuf_iterator<char>(input)),{});
            auto* buffer=api<decltype(&MaaImageBufferCreate)>(dll,"MaaImageBufferCreate")();assert(buffer);
            assert(api<decltype(&MaaImageBufferSetEncoded)>(dll,"MaaImageBufferSetEncoded")(buffer,bytes.data(),bytes.size()));
            state.width=api<decltype(&MaaImageBufferWidth)>(dll,"MaaImageBufferWidth")(buffer);
            state.height=api<decltype(&MaaImageBufferHeight)>(dll,"MaaImageBufferHeight")(buffer);
            assert(api<decltype(&MaaImageBufferChannels)>(dll,"MaaImageBufferChannels")(buffer)==3);
            const auto* raw=static_cast<const unsigned char*>(api<decltype(&MaaImageBufferGetRawData)>(dll,"MaaImageBufferGetRawData")(buffer));
            state.pixels.assign(raw,raw+size_t(state.width)*state.height*3);
            api<decltype(&MaaImageBufferDestroy)>(dll,"MaaImageBufferDestroy")(buffer);
            const auto hidden=run();
            assert(state.downs==0 && hidden.find("original_combat_enter")==std::string::npos &&
                hidden.find("character_slot=")==std::string::npos);
            std::ofstream(scratch/(file.path().stem().string()+"-result.log"))<<hidden;
            ++hidden_hud_screens;
        }
    }
    api<decltype(&MaaTaskerDestroy)>(dll,"MaaTaskerDestroy")(tasker);
    api<decltype(&MaaResourceDestroy)>(dll,"MaaResourceDestroy")(resource);
    api<decltype(&MaaControllerDestroy)>(dll,"MaaControllerDestroy")(controller);
    FreeLibrary(dll);
    std::cout<<"{\"status\":\"passed\",\"hidden_hud_screens\":"<<hidden_hud_screens
        <<",\"timestamp_lines\":3,\"raw_score_isolation\":true,"
        <<"\"active_combat_hud_loss_suspends\":true,\"hud_recovery_retains_actors\":true,"
        <<"\"hidden_hud_gameplay_inputs\":0,\"stop_while_hidden_releases_input\":true,"
        <<"\"normal_stop\":true,\"idle_portrait_loads\":0,\"idle_input_requests\":0,"
        <<"\"first_short_target_Lucilla\":true,\"held_skill_request_counted\":true,"
        <<"\"release_inputs\":true,\"roi_shared_between_templates\":true,"
        <<"\"identical_pixels_reuse_recognition\":true,\"changed_pixels_discard_recognition\":true,"
        <<"\"cooldown_cache_key_includes_slot\":true,\"game_input_sent\":false}\n";
}
