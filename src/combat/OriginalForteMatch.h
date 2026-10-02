#pragma once
#include "MaaFrameRecognition.h"

// Original template scaling, followed by grayscale and threshold processing.
class OriginalForteMatch {
    MaaFrameRecognition& recognition;
public:
    explicit OriginalForteMatch(MaaFrameRecognition& frame):recognition(frame) {}
    bool match(MaaImageBuffer*,bool resonance) {
        const auto* source=find_original_box(resonance?"e_forte":"mouse_forte");
        if(!source)return false;
        auto box=scale_original_box(*source,recognition.width,recognition.height);
        const double dx=recognition.width*0.025,dy=recognition.height*(resonance?0.002:0.015);
        const int x1=std::max(0,original_round(box.x-dx)),y1=std::max(0,original_round(box.y-dy));
        const int x2=std::min(recognition.width,original_round(box.x+box.width+dx));
        const int y2=std::min(recognition.height,original_round(box.y+box.height+dy));
        return recognition.match(resonance?"127_436.png":"154_46.png",{x1,y1,x2-x1,y2-y1},
            0.6,false,resonance?220:244).hit;
    }
};
