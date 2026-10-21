#pragma once
#include "MaaGpuInference.h"
#include "OriginalCooldown.h"
#include "../task/MaaNativeAction.h"

struct MaaGpuOcrMeasurement {
    double cold_ms=0,mean_ms=0,median_ms=0;
    std::array<double,3> cooldowns{};
    int width=0,height=0;
};

// Fixed screenshot, synchronous Maa OCR, eight warm runs. No game input.
inline MaaGpuOcrMeasurement maa_measure_ocr(const fs::path& root,HMODULE dll,MaaResource* resource,
    MaaTasker* tasker,MaaController* controller){
    MaaGpuOcrMeasurement measured;
    constexpr int rounds=8;
    const auto status=run_maa_native_action(dll,resource,tasker,[&](MaaContext* context){
        bool raw=true;
        api<decltype(&MaaControllerSetOption)>(dll,"MaaControllerSetOption")(
            controller,MaaCtrlOption_ScreenshotUseRawSize,&raw,sizeof(raw));
        MaaFrameRecognition image(dll,tasker,controller,root,context);
        if(!image.capture())throw std::runtime_error("GPU OCR probe image unavailable");
        measured.width=image.width;measured.height=image.height;
        OriginalCooldown ocr(dll,controller,tasker,context);
        ocr.set_timing([](){return 0.0;},[](double){return 0.0;});
        const auto refresh=[&](){if(!ocr.refresh(1,image.buffer()))throw std::runtime_error("GPU OCR probe failed");};
        const auto cold=std::chrono::steady_clock::now();refresh();
        measured.cold_ms=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-cold).count();
        refresh();refresh();
        std::array<double,8> samples{};
        const char* keys="EQR";
        for(int index=0;index<rounds;++index){
            const auto started=std::chrono::steady_clock::now();refresh();
            samples[index]=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count();
            for(int key=0;key<3;++key){
                const double cd=ocr.remaining(keys[key],1,false);
                if(index>0 && std::abs(cd-measured.cooldowns[key])>0.00001)
                    throw std::runtime_error("OCR repeated result changed on a fixed image");
                measured.cooldowns[key]=cd;
            }
            measured.mean_ms+=samples[index]/rounds;
        }
        std::sort(samples.begin(),samples.end());measured.median_ms=(samples[3]+samples[4])/2;
        return true;
    });
    if(status!=MaaStatus_Succeeded)throw std::runtime_error("GPU OCR probe action failed");
    return measured;
}

inline MaaStatus run_gpu_ocr_probe(const fs::path& root,HMODULE dll,MaaResource* gpu_resource,
    MaaTasker* gpu_tasker,MaaController* controller,const MaaGpuSelection& gpu){
    if(!gpu.gpu())throw std::runtime_error("GPU OCR probe requires a DirectML GPU");
    const auto gpu_result=maa_measure_ocr(root,dll,gpu_resource,gpu_tasker,controller);
    auto* cpu_resource=api<decltype(&MaaResourceCreate)>(dll,"MaaResourceCreate")();
    auto* cpu_tasker=api<decltype(&MaaTaskerCreate)>(dll,"MaaTaskerCreate")();
    struct Release {
        HMODULE dll;MaaResource* resource;MaaTasker* tasker;
        ~Release(){
            if(tasker)api<decltype(&MaaTaskerDestroy)>(dll,"MaaTaskerDestroy")(tasker);
            if(resource)api<decltype(&MaaResourceDestroy)>(dll,"MaaResourceDestroy")(resource);
        }
    } release{dll,cpu_resource,cpu_tasker};
    if(!cpu_resource || !cpu_tasker)throw std::runtime_error("CPU comparison resource unavailable");
    maa_set_inference(dll,cpu_resource,MaaGpuSelection{});
    const auto bundle=api<decltype(&MaaResourcePostBundle)>(dll,"MaaResourcePostBundle")(cpu_resource,(root/"resource").string().c_str());
    if(api<decltype(&MaaResourceWait)>(dll,"MaaResourceWait")(cpu_resource,bundle)!=MaaStatus_Succeeded ||
       !api<decltype(&MaaTaskerBindResource)>(dll,"MaaTaskerBindResource")(cpu_tasker,cpu_resource) ||
       !api<decltype(&MaaTaskerBindController)>(dll,"MaaTaskerBindController")(cpu_tasker,controller))
        throw std::runtime_error("CPU comparison initialization failed");
    const auto cpu_result=maa_measure_ocr(root,dll,cpu_resource,cpu_tasker,controller);
    for(int key=0;key<3;++key)if(std::abs(cpu_result.cooldowns[key]-gpu_result.cooldowns[key])>0.00001)
        throw std::runtime_error("CPU/GPU OCR cooldown results differ");
    std::cout<<"gpu_ocr_probe {\"provider\":\"DirectML\",\"adapter\":"<<gpu.adapter<<",\"gpu\":\""<<gpu.name
        <<"\",\"frame\":["<<gpu_result.width<<','<<gpu_result.height<<"],\"rounds\":8,\"cpu_mean_ms\":"<<cpu_result.mean_ms
        <<",\"gpu_mean_ms\":"<<gpu_result.mean_ms<<",\"cpu_median_ms\":"<<cpu_result.median_ms
        <<",\"gpu_median_ms\":"<<gpu_result.median_ms<<",\"gpu_cold_ms\":"<<gpu_result.cold_ms
        <<",\"cpu_cold_ms\":"<<cpu_result.cold_ms<<",\"cooldowns_EQR\":["<<gpu_result.cooldowns[0]<<','
        <<gpu_result.cooldowns[1]<<','<<gpu_result.cooldowns[2]<<"],\"results_equal\":true,\"game_input_sent\":false}\n"<<std::flush;
    return MaaStatus_Succeeded;
}
