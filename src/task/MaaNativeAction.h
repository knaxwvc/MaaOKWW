#pragma once
#include <exception>
#include <functional>

// The registered C++ action owns the synchronous MaaContext for its lifetime.
// Never post another Tasker task and wait on that queue inside this callback.
struct MaaNativeAction {
    std::function<MaaBool(MaaContext*)> run;
    std::exception_ptr error;
    static MaaBool MAA_CALL callback(MaaContext* context,MaaTaskId,const char*,const char*,
        const char*,MaaRecoId,const MaaRect*,void* arg) noexcept {
        auto& action=*static_cast<MaaNativeAction*>(arg);
        try{return action.run(context);}
        catch(...){action.error=std::current_exception();return false;}
    }
};

inline MaaStatus run_maa_native_action(HMODULE dll,MaaResource* resource,MaaTasker* tasker,
    std::function<MaaBool(MaaContext*)> run) {
    MaaNativeAction action{std::move(run),{}};
    if(!api<decltype(&MaaResourceRegisterCustomAction)>(dll,"MaaResourceRegisterCustomAction")(
        resource,"OKWW_NativeAction",MaaNativeAction::callback,&action))
        throw std::runtime_error("Maa combat action registration failed");
    struct Unregister {
        HMODULE dll;MaaResource* resource;
        ~Unregister(){api<decltype(&MaaResourceUnregisterCustomAction)>(dll,"MaaResourceUnregisterCustomAction")(
            resource,"OKWW_NativeAction");}
    } unregister{dll,resource};
    const auto id=api<decltype(&MaaTaskerPostTask)>(dll,"MaaTaskerPostTask")(tasker,"OKWW_NativeLoop","{}");
    const auto status=api<decltype(&MaaTaskerWait)>(dll,"MaaTaskerWait")(tasker,id);
    if(action.error)std::rethrow_exception(action.error);
    return status;
}
