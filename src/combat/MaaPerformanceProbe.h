#pragma once
#include "MaaFrameRecognition.h"
#include "OriginalCooldown.h"
#include "../task/MaaNativeAction.h"

// Read-only comparison of the queued and synchronous Maa paths on one image.
// This mode sends no game input and does not exercise a combat rotation.
inline MaaStatus run_maa_performance_probe(const fs::path& root,HMODULE dll,MaaResource* resource,
    MaaTasker* tasker,MaaController* controller) {
    bool raw=true;
    api<decltype(&MaaControllerSetOption)>(dll,"MaaControllerSetOption")(
        controller,MaaCtrlOption_ScreenshotUseRawSize,&raw,sizeof(raw));
    MaaFrameRecognition queued(dll,tasker,controller,root);
    if(!queued.capture())throw std::runtime_error("Performance screenshot failed");
    const auto observations=[](MaaFrameRecognition& frame){
        std::array<MaaFrameMatch,5> result{};
        const char* files[]={"56_34.png","52_27.png","54_33.png"};
        for(int i=0;i<3;++i){
            auto box=scale_original_box(*find_original_box("char_"+std::to_string(i+1)+"_text"),frame.width,frame.height);
            const int x=std::max(0,original_round(box.x-frame.width*0.002));
            const int y=std::max(0,original_round(box.y-frame.height*0.002));
            const int x2=std::min(frame.width,original_round(box.x+box.width+frame.width*0.002));
            const int y2=std::min(frame.height,original_round(box.y+box.height+frame.height*0.002));
            result[size_t(i)]=frame.match(files[i],{x,y,x2-x,y2-y},0.8);
        }
        const bool special=frame.width==1600;
        const char* target_box=special?"has_target_169":"has_target";
        result[3]=frame.match_box(special?"160_370.png":"159_97.png",target_box,0.6);
        result[4]=frame.match_box(special?"191_300.png":"190_80.png",target_box,0.6);
        return result;
    };
    constexpr int rounds=12;
    const auto expected=observations(queued);
    const auto measure=[&](MaaFrameRecognition& frame,bool clear){
        const auto started=std::chrono::steady_clock::now();
        for(int i=0;i<rounds;++i){if(clear)frame.clear_matches();observations(frame);}
        return std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count()/rounds;
    };
    const double queued_ms=measure(queued,true);
    OriginalCooldown queued_cd(dll,controller,tasker);
    queued_cd.refresh(1,queued.buffer());
    const double ocr_cold_ms=queued_cd.recognition_ms();
    for(int i=0;i<3;++i)queued_cd.refresh(1,queued.buffer());
    const double queued_ocr_ms=(queued_cd.recognition_ms()-ocr_cold_ms)/3;
    return run_maa_native_action(dll,resource,tasker,[&](MaaContext* context){
        MaaFrameRecognition direct(dll,tasker,controller,root,context);
        auto set=api<decltype(&MaaImageBufferSetRawData)>(dll,"MaaImageBufferSetRawData");
        auto get=api<decltype(&MaaImageBufferGetRawData)>(dll,"MaaImageBufferGetRawData");
        auto type=api<decltype(&MaaImageBufferType)>(dll,"MaaImageBufferType");
        if(!set(direct.buffer(),get(queued.buffer()),queued.width,queued.height,type(queued.buffer())))
            throw std::runtime_error("Performance image copy failed");
        direct.width=queued.width;direct.height=queued.height;
        const auto actual=observations(direct);
        for(size_t i=0;i<actual.size();++i){
            const auto& a=actual[i];const auto& b=expected[i];
            if(a.hit!=b.hit || std::abs(a.score-b.score)>0.000001 || a.box.x!=b.box.x ||
               a.box.y!=b.box.y || a.box.width!=b.box.width || a.box.height!=b.box.height)
                throw std::runtime_error("Queued/direct Maa recognition mismatch");
        }
        const double direct_ms=measure(direct,true);
        const auto calls_before=direct.recognition_calls();
        const double cached_ms=measure(direct,false);
        if(direct.recognition_calls()!=calls_before)throw std::runtime_error("Same-image Maa cache missed");
        OriginalCooldown direct_cd(dll,controller,tasker,context);
        direct_cd.refresh(1,direct.buffer());
        if(queued_cd.last_detail(1)!=direct_cd.last_detail(1))throw std::runtime_error("Queued/direct Maa OCR mismatch");
        const double direct_first=direct_cd.recognition_ms();
        for(int i=0;i<3;++i)direct_cd.refresh(1,direct.buffer());
        const double direct_ocr_ms=(direct_cd.recognition_ms()-direct_first)/3;
        std::cout<<"performance_probe frame="<<direct.width<<'x'<<direct.height<<" rounds="<<rounds
            <<" matches_per_round="<<actual.size()<<" queued_ms="<<queued_ms<<" direct_ms="<<direct_ms
            <<" same_frame_ms="<<cached_ms<<" ocr_cold_ms="<<ocr_cold_ms<<" queued_ocr_ms="<<queued_ocr_ms
            <<" direct_ocr_ms="<<direct_ocr_ms<<" results_equal=1 input_sent=0\n"<<std::flush;
        std::cout<<"roi_preparation_probe preparations="<<direct.region_preparations
            <<" reuses="<<direct.region_reuses<<" copy_bytes="<<direct.region_copy_bytes
            <<" frames=1 results_equal=1 input_sent=0\n"<<std::flush;
        return true;
    });
}
