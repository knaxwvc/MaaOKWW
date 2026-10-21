#pragma once
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <Windows.h>
#include "MaaFramework/MaaAPI.h"

struct MaaRecognitionResult {
    bool hit=false;
    MaaRect box{};
    std::string detail;
};

// Run Maa's built-in recognizers synchronously inside the combat CustomAction.
// Standalone diagnostic callers retain the queued API, outside that action.
class MaaRecognitionSession {
    MaaTasker* tasker_;
    MaaContext* context_;
    decltype(&MaaContextRunRecognitionDirect) direct_;
    decltype(&MaaTaskerPostRecognition) post_;
    decltype(&MaaTaskerWait) wait_;
    decltype(&MaaTaskerGetTaskDetail) task_detail_;
    decltype(&MaaTaskerGetNodeDetail) node_detail_;
    decltype(&MaaTaskerGetRecognitionDetail) reco_detail_;
    decltype(&MaaStringBufferGet) get_;
    decltype(&MaaStringBufferDestroy) destroy_;
    MaaStringBuffer *node_,*algorithm_,*detail_;
public:
    std::uint64_t calls=0;
    double elapsed_ms=0;
    MaaRecognitionSession(HMODULE dll,MaaTasker* tasker,MaaContext* context=nullptr)
        :tasker_(tasker),context_(context),
         direct_(api<decltype(direct_)>(dll,"MaaContextRunRecognitionDirect")),
         post_(api<decltype(post_)>(dll,"MaaTaskerPostRecognition")),
         wait_(api<decltype(wait_)>(dll,"MaaTaskerWait")),
         task_detail_(api<decltype(task_detail_)>(dll,"MaaTaskerGetTaskDetail")),
         node_detail_(api<decltype(node_detail_)>(dll,"MaaTaskerGetNodeDetail")),
         reco_detail_(api<decltype(reco_detail_)>(dll,"MaaTaskerGetRecognitionDetail")),
         get_(api<decltype(get_)>(dll,"MaaStringBufferGet")),
         destroy_(api<decltype(destroy_)>(dll,"MaaStringBufferDestroy")) {
        auto create=api<decltype(&MaaStringBufferCreate)>(dll,"MaaStringBufferCreate");
        node_=create();algorithm_=create();detail_=create();
        if(!node_ || !algorithm_ || !detail_){
            if(node_)destroy_(node_);if(algorithm_)destroy_(algorithm_);if(detail_)destroy_(detail_);
            throw std::runtime_error("Maa recognition buffers unavailable");
        }
    }
    ~MaaRecognitionSession(){destroy_(detail_);destroy_(algorithm_);destroy_(node_);}
    MaaRecognitionSession(const MaaRecognitionSession&)=delete;
    MaaRecognitionSession& operator=(const MaaRecognitionSession&)=delete;
    MaaRecognitionResult run(const char* type,const char* params,const MaaImageBuffer* image) {
        const auto started=std::chrono::steady_clock::now();
        MaaRecoId reco=MaaInvalidId;
        if(context_)reco=direct_(context_,type,params,image);
        else {
            const auto task=post_(tasker_,type,params,image);
            (void)wait_(tasker_,task);
            MaaNodeId nodes[8]{};MaaSize count=8;MaaStatus status=MaaStatus_Invalid;
            MaaActId action=MaaInvalidId;MaaBool complete=false;
            if(task_detail_(tasker_,task,node_,nodes,&count,&status) && count)
                node_detail_(tasker_,nodes[std::min<MaaSize>(count,8)-1],node_,&reco,&action,&complete);
        }
        MaaRecognitionResult result;
        MaaBool hit=false;
        if(reco==MaaInvalidId || !reco_detail_(tasker_,reco,node_,algorithm_,&hit,&result.box,detail_,nullptr,nullptr))
            throw std::runtime_error(std::string("Maa recognition failed: ")+type);
        result.hit=hit!=0;
        const char* detail=get_(detail_);if(detail)result.detail=detail;
        ++calls;elapsed_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count();
        return result;
    }
};
