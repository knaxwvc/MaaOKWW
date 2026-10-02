#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>

// time.sleep on the original Python 3.12 Windows runtime uses a high resolution
// waitable timer. Keep sub-frame (1 ms / 10 ms) waits out of Sleep's coarse tick.
inline void original_sleep_for(double seconds) {
    if(seconds<=0)return;
    struct Timer {
        HANDLE handle=CreateWaitableTimerExW(nullptr,nullptr,0x2,TIMER_ALL_ACCESS);
        Timer(){if(!handle)handle=CreateWaitableTimerW(nullptr,TRUE,nullptr);}
        ~Timer(){if(handle)CloseHandle(handle);}
    };
    thread_local Timer timer;
    LARGE_INTEGER due;
    due.QuadPart=-static_cast<LONGLONG>(seconds*10000000.0);
    if(due.QuadPart==0)due.QuadPart=-1;
    if(timer.handle && SetWaitableTimer(timer.handle,&due,0,nullptr,nullptr,FALSE))
        WaitForSingleObject(timer.handle,INFINITE);
    else std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}
inline double original_wall_seconds() {
    return std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();
}
