#pragma once
#include <cmath>
#include <complex>
#include <numeric>
#include "CombatCheck.h"

struct OriginalColor { int b0, b1, g0, g1, r0, r1; };
inline constexpr OriginalColor original_text_white{244,255,244,255,244,255};
inline constexpr OriginalColor original_forte_white{250,255,246,255,244,255};
inline ScreenBox original_hcenter_box(const FrameState& frame, int source_width,
    int source_height, int left, int top, int right, int bottom) {
    const double scale = std::min(double(frame.width)/source_width,double(frame.height)/source_height);
    return {int(std::round(frame.width/2.0+(left-source_width/2.0)*scale)),
            frame.height-int(std::round((source_height-top)*scale)),
            int(std::round((right-left)*scale)),int(std::round((bottom-top)*scale))};
}
inline bool original_color_hit(const FrameState& frame, int x, int y, OriginalColor color) {
    if (frame.pixels.empty() || x<0 || y<0 || x>=frame.width || y>=frame.height) return false;
    const auto* p = frame.pixels.data()+(size_t(y)*frame.width+x)*frame.channels;
    return p[0]>=color.b0 && p[0]<=color.b1 && p[1]>=color.g0 && p[1]<=color.g1 &&
           p[2]>=color.r0 && p[2]<=color.r1;
}
inline double original_color_percent(const FrameState& frame, ScreenBox box, OriginalColor color,
                                      double inner_ratio=0, double outer_ratio=0) {
    int hit=0,total=0;
    const double cx=box.x+box.width/2.0, cy=box.y+box.height/2.0;
    const double radius=std::min(box.width,box.height)/2.0;
    for (int y=box.y;y<box.y+box.height;++y) for(int x=box.x;x<box.x+box.width;++x) {
        if (x<0 || y<0 || x>=frame.width || y>=frame.height) continue;
        if (outer_ratio>0) {
            const double distance=std::hypot(x-cx,y-cy);
            if(distance<radius*inner_ratio || distance>radius*outer_ratio) continue;
        }
        ++total;
        if(original_color_hit(frame,x,y,color)) ++hit;
    }
    return total ? double(hit)/total : 0;
}
// NumPy's column profile and FFT magnitude calculation, translated to native DFT.
inline int original_frequency_forte(const FrameState& frame, ScreenBox box, OriginalColor color,
    int count, int min_frequency, int max_frequency, double min_amplitude) {
    const int step=box.width/count;
    if(step<64 || box.height<=0) return 0;
    for(int segment=count;segment>0;--segment) {
        std::vector<double> profile(size_t(step),0.0);
        int white=0,total=step*box.height;
        for(int y=0;y<box.height;++y) for(int x=0;x<step;++x)
            if(original_color_hit(frame,box.x+(segment-1)*step+x,box.y+y,color)) {
                ++white; ++profile[size_t(x)];
            }
        if(white==0 || white==total) continue;
        const double mean=std::accumulate(profile.begin(),profile.end(),0.0)/step;
        double amplitude=0; int frequency=0;
        for(int k=1;k<step;++k) {
            std::complex<double> value{};
            for(int x=0;x<step;++x) {
                const double angle=-2.0*3.14159265358979323846*k*x/step;
                value+=(profile[size_t(x)]-mean)*std::complex<double>(std::cos(angle),std::sin(angle));
            }
            const double magnitude=std::abs(value);
            if(magnitude>amplitude) { amplitude=magnitude; frequency=k; }
        }
        if((frequency>=min_frequency && frequency<=max_frequency) || amplitude>=min_amplitude)
            return segment;
    }
    return 0;
}
inline double original_masked_nonblack_percent(const FrameState& frame,ScreenBox box,
    OriginalColor color,double inner_ratio,double outer_ratio){
    if(frame.pixels.empty() || box.width<=0 || box.height<=0)return 0;
    const int r1=int(std::floor(box.height*inner_ratio)),r2=int(std::ceil(box.height*outer_ratio));
    static OriginalCvContour contours;
    const auto mask=contours.ring_mask(box.width,box.height,r1,r2);
    int colored=0,nonblack=0;
    for(int y=0;y<box.height;++y)for(int x=0;x<box.width;++x){
        if(!mask[size_t(y)*box.width+x])continue;
        const int px=box.x+x,py=box.y+y;if(px<0||py<0||px>=frame.width||py>=frame.height)continue;
        const auto* p=frame.pixels.data()+(size_t(py)*frame.width+px)*frame.channels;
        if(p[0]&&p[1]&&p[2])++nonblack;
        if(original_color_hit(frame,px,py,color))++colored;
    }
    return nonblack?double(colored)/nonblack:0;
}
inline double original_masked_percent(const FrameState& frame,ScreenBox box,OriginalColor color,
    double inner_ratio,double outer_ratio) {
    const int r1=int(std::floor(box.height*inner_ratio)),r2=int(std::ceil(box.height*outer_ratio));
    int hits=0,total=0;
    if(r2<=r1 || box.width<=0 || box.height<=0)return 0;
    static OriginalCvContour contours;
    const auto mask=contours.ring_mask(box.width,box.height,r1>0?r1:-1,r2);
    for(int y=0;y<box.height;++y)for(int x=0;x<box.width;++x) {
        if(!mask[size_t(y)*box.width+x])continue;
        ++total;if(original_color_hit(frame,box.x+x,box.y+y,color))++hits;
    }
    return total?double(hits)/total:0;
}
inline double original_stripe_percent(const FrameState& frame,ScreenBox box,OriginalColor color){
    const int w=box.width,h=box.height;if(w<=0||h<=0)return 0;
    std::vector<unsigned char> gray(size_t(w)*h);int whites=0;
    for(int y=0;y<h;++y)for(int x=0;x<w;++x)if(original_color_hit(frame,box.x+x,box.y+y,color)){gray[size_t(y)*w+x]=1;++whites;}
    if(w<64)return std::min(1.0,original_color_percent(frame,box,color)*2);
    if(!whites)return 0;
    const int stripe_threshold=int(w*0.009);
    if(stripe_threshold>=1)for(int y=0;y<h;++y){int x=0;while(x<w){if(gray[size_t(y)*w+x]){const int start=x;while(x<w&&gray[size_t(y)*w+x])++x;if(x-start<stripe_threshold)std::fill(gray.begin()+size_t(y)*w+start,gray.begin()+size_t(y)*w+x,0);}else ++x;}}
    const int window=std::max(8,int(w*0.045)),step=std::max(1,int(w*0.012));
    std::vector<double> scores,ratios;std::vector<int> positions;
    for(int left=0;left+window<=w;left+=step){
        std::vector<double> profile(size_t(window),0);int white=0;
        for(int y=0;y<h;++y)for(int x=0;x<window;++x)if(gray[size_t(y)*w+left+x]){++white;++profile[size_t(x)];}
        const double ratio=double(white)/(window*h);double score=0;
        if(ratio>=0.05&&ratio<=0.75){const double mean=double(white)/window;
            for(int k=1;k<window/2;++k){std::complex<double> value{};for(int x=0;x<window;++x){const double angle=-2*3.14159265358979323846*k*x/window;value+=(profile[size_t(x)]-mean)*std::complex<double>(std::cos(angle),std::sin(angle));}score=std::max(score,std::abs(value));}}
        scores.push_back(score);ratios.push_back(ratio);positions.push_back(left);
    }
    if(scores.empty())return std::min(1.0,original_color_percent(frame,box,color)*2);
    const double maximum=*std::max_element(scores.begin(),scores.end()),threshold=std::max(1.5,maximum*0.45);
    if(maximum<1e-3)return 0;
    size_t end=0;
    for(size_t i=0;i<scores.size();++i){if(scores[i]>=threshold)end=i;else if(ratios[i]<0.375){for(size_t j=i+1;j<scores.size();++j)if(scores[j]>threshold)return -1;break;}}
    const int right=end==0?0:(positions[end]+window+step>=w?w:positions[end]);
    return double(right)/w;
}
