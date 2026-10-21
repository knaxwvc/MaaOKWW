#pragma once
#include <cstdint>
#include <string>
#include <string_view>

// Confirmation is based on separate captures, never repeated reads of one image.
// Equal pixels can be a legitimate stationary scene and do not imply a stale capture.
struct OriginalStableHud {
    std::uint64_t sequence=~std::uint64_t(0);
    int token=0,frames=0;
    double since=0,last=0;
    bool ready=false;
    void reset(){sequence=~std::uint64_t(0);token=frames=0;since=last=0;ready=false;}
    bool observe(std::uint64_t capture,double now,int identity,double duration=0.05,int count=2) {
        if(!identity){reset();return false;}
        if(capture==sequence)return ready;
        sequence=capture;
        if(identity!=token || now-last>0.5){token=identity;since=now;frames=0;ready=false;}
        last=now;++frames;
        ready=frames>=count && now-since+1e-9>=duration;
        return ready;
    }
};

// An unconfirmed roster never overwrites the last accepted party. In particular,
// a brief one-portrait result cannot select solo mode or discard two teammates.
struct OriginalRosterConfirmation {
    std::string accepted,candidate;
    std::uint64_t sequence=~std::uint64_t(0);
    double since=0,last=0;
    int frames=0;
    void reject(){candidate.clear();frames=0;sequence=~std::uint64_t(0);}
    bool observe(std::string_view identity,int count,std::uint64_t capture,double now) {
        if(identity.empty() || count<1 || count>3){reject();return false;}
        const std::string key=std::to_string(count)+":"+std::string(identity);
        if(key==accepted){reject();return true;}
        if(capture==sequence)return false;
        sequence=capture;
        if(key!=candidate || now-last>0.5){candidate=key;since=now;frames=0;}
        last=now;++frames;
        // Normal party startup keeps its original immediate loading behavior.
        // All roster changes, and the solo extension's initial detection, settle.
        if((accepted.empty() && count>1) || (frames>=3 && now-since+1e-9>=0.4)) {
            accepted=key;reject();return true;
        }
        return false;
    }
};
