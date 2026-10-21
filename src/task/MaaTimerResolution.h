#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>

// Maa's WGC FramePool polls every 2 ms. A coarse Windows timer tick can turn
// each poll into a whole display frame; OKWW's WGC event wait wakes directly.
// Request a 1 ms tick for this process and release the request at shutdown.
class MaaTimerResolution {
    HMODULE module_=LoadLibraryW(L"winmm.dll");
    using Period=UINT(WINAPI*)(UINT);
    Period end_=module_?reinterpret_cast<Period>(GetProcAddress(module_,"timeEndPeriod")):nullptr;
    bool enabled_=false;
    PROCESS_POWER_THROTTLING_STATE previous_{};
    bool restore_power_=false,background_precision_=false;
public:
    MaaTimerResolution(){
        // Win11 otherwise ignores timer requests from an occluded/hidden BOT.
        previous_.Version=PROCESS_POWER_THROTTLING_CURRENT_VERSION;
        restore_power_=GetProcessInformation(GetCurrentProcess(),ProcessPowerThrottling,&previous_,sizeof(previous_))!=0;
        PROCESS_POWER_THROTTLING_STATE precise{};
        precise.Version=PROCESS_POWER_THROTTLING_CURRENT_VERSION;
        precise.ControlMask=PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION;
        precise.StateMask=0;
        background_precision_=SetProcessInformation(GetCurrentProcess(),ProcessPowerThrottling,&precise,sizeof(precise))!=0;
        const auto begin=module_?reinterpret_cast<Period>(GetProcAddress(module_,"timeBeginPeriod")):nullptr;
        enabled_=begin && end_ && begin(1)==0;
    }
    ~MaaTimerResolution(){
        if(enabled_)end_(1);
        if(background_precision_ && restore_power_)SetProcessInformation(GetCurrentProcess(),ProcessPowerThrottling,&previous_,sizeof(previous_));
        if(module_)FreeLibrary(module_);
    }
    bool enabled() const{return enabled_;}
    bool background_precision() const{return background_precision_;}
    static double poll_sleep_ms(){
        const auto started=std::chrono::steady_clock::now();
        constexpr int count=12;
        for(int i=0;i<count;++i)std::this_thread::sleep_for(std::chrono::milliseconds(2));
        return std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count()/count;
    }
};
