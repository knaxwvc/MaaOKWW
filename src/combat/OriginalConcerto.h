#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <filesystem>
#include <fstream>
#include <regex>
#include "OriginalBoxes.h"
#include "OriginalCvContour.h"

// C++ translation of BaseCombatTask.get_con_box / count_rings /
// get_current_con. The six BGR ranges, annulus geometry, 3x3 closing,
// right-center raw-mask restoration, exterior contour approximation and convex
// check are the original count_rings operations, including epsilon=0.05.
struct OriginalRingResult {
    int color_index = -1;
    int area = 0;
    double percent = 0;
    bool full = false;
};
class OriginalConcerto {
    OriginalCvContour contours;
    struct BgrRange { int b0,b1,g0,g1,r0,r1; };
    static constexpr std::array<BgrRange,6> ranges{{
        {90,130,190,222,205,235}, {210,249,95,140,150,190},
        {75,105,100,130,200,230}, {210,245,150,180,60,95},
        {155,190,215,250,70,110}, {145,175,65,105,190,220}
    }};
    // Original con_full_size.by_geometry key: ring_index:width x height.
    std::map<std::tuple<int,int,int>, int> full_area;
    std::filesystem::path calibration_file;
    void save_calibrations() const {
        if(calibration_file.empty())return;
        std::filesystem::create_directories(calibration_file.parent_path());
        std::ofstream file(calibration_file);
        file<<"{\n  \"by_geometry\": {";
        bool first=true;
        for(const auto& entry:full_area){
            if(entry.second<=0)continue;
            const auto [color,w,h]=entry.first;
            file<<(first?"\n":",\n")<<"    \""<<color<<':'<<w<<'x'<<h<<"\": "<<entry.second;first=false;
        }
        file<<"\n  }\n}\n";
    }
    int selected_index = -1;
    static bool in_range(const unsigned char* bgr, const BgrRange& c) {
        return bgr[0]>=c.b0 && bgr[0]<=c.b1 &&
               bgr[1]>=c.g0 && bgr[1]<=c.g1 &&
               bgr[2]>=c.r0 && bgr[2]<=c.r1;
    }
    static std::vector<unsigned char> close_3x3(const std::vector<unsigned char>& raw, int w, int h) {
        std::vector<unsigned char> dilated(raw.size()), closed(raw.size());
        for (int y=0;y<h;++y) for (int x=0;x<w;++x) {
            bool on=false;
            for (int dy=-1;dy<=1 && !on;++dy) for (int dx=-1;dx<=1;++dx) {
                const int xx=x+dx, yy=y+dy;
                if (xx>=0 && xx<w && yy>=0 && yy<h && raw[yy*w+xx]) { on=true; break; }
            }
            dilated[y*w+x]=on;
        }
        for (int y=0;y<h;++y) for (int x=0;x<w;++x) {
            bool on=true;
            for (int dy=-1;dy<=1 && on;++dy) for (int dx=-1;dx<=1;++dx) {
                const int xx=x+dx, yy=y+dy;
                if (xx>=0 && xx<w && yy>=0 && yy<h && !dilated[yy*w+xx]) { on=false; break; }
            }
            closed[y*w+x]=on;
        }
        const int cx=w/2, cy=h/2;
        for (int y=cy-1;y<=cy+1;++y)
            for (int x=cx+1;x<w;++x) closed[y*w+x]=raw[y*w+x];
        return closed;
    }
public:
    void load_calibrations(const std::filesystem::path& runtime,const std::filesystem::path& original) {
        calibration_file=runtime;
        std::ifstream file(std::filesystem::exists(runtime)?runtime:original);
        const std::string text((std::istreambuf_iterator<char>(file)),{});
        const std::regex entry(R"re("(\d+):(\d+)x(\d+)"\s*:\s*(\d+))re");
        for(auto it=std::sregex_iterator(text.begin(),text.end(),entry);it!=std::sregex_iterator();++it)
            full_area[{std::stoi((*it)[1]),std::stoi((*it)[2]),std::stoi((*it)[3])}]=std::stoi((*it)[4]);
    }
    void set_color_index(int index) { selected_index=index>=0 && index<6 ? index : -1; }
    OriginalRingResult measure(const unsigned char* pixels, int frame_w, int frame_h, int channels) {
        OriginalRingResult result;
        if (!pixels || channels<3) return result;
        const double scale=std::min(double(frame_w)/3840.0,double(frame_h)/2160.0);
        const int w=original_round(126*scale),h=original_round(126*scale);
        const int x0=original_round(frame_w*0.5+(1431-1920)*scale);
        const int y0=frame_h-original_round((2160-1942)*scale);
        if (w<6 || h<6 || x0<0 || y0<0 || x0+w>frame_w || y0+h>frame_h) return result;
        auto pixel=[&](int x,int y) { return pixels+((y0+y)*frame_w+x0+x)*channels; };
        if(selected_index<0){
            int best_index=0,best_count=0;
            for(int color=0;color<6;++color){
                int count=0;
                for(int y=0;y<h;++y)for(int x=0;x<w;++x)count+=in_range(pixel(x,y),ranges[color]);
                if(count>best_count){best_count=count;best_index=color;}
            }
            selected_index=best_index;
        }
        result.color_index=selected_index;
        const int first_color=selected_index,last_color=selected_index;
        const int inner=static_cast<int>(std::floor(h*0.35119));
        const int outer=static_cast<int>(std::ceil(h*0.42261));
        const auto ring_mask=contours.ring_mask(w,h,inner,outer);
        const double min_box_area=1500.0*w*h/(126.0*126.0);
        for (int color=first_color;color<=last_color;++color) {
            std::vector<unsigned char> raw(static_cast<size_t>(w*h));
            for (int y=0;y<h;++y) for (int x=0;x<w;++x) {
                raw[y*w+x]=(ring_mask[y*w+x] &&
                            in_range(pixel(x,y),ranges[color]));
            }
            const auto closed=close_3x3(raw,w,h);
            std::vector<int> labels(static_cast<size_t>(w*h));
            int next_label=0, ring_count=0, area=0;
            bool full=false;
            for (int start=0;start<w*h;++start) {
                if (!closed[start] || labels[start]) continue;
                const int component=++next_label;
                std::queue<int> queue;
                queue.push(start); labels[start]=component;
                int count=0,min_x=w,min_y=h,max_x=0,max_y=0;
                while (!queue.empty()) {
                    const int at=queue.front();queue.pop();
                    const int x=at%w,y=at/w;
                    ++count; min_x=std::min(min_x,x);min_y=std::min(min_y,y);
                    max_x=std::max(max_x,x);max_y=std::max(max_y,y);
                    for(int dy=-1;dy<=1;++dy) for(int dx=-1;dx<=1;++dx) {
                        const int xx=x+dx,yy=y+dy;
                        if(xx<0||xx>=w||yy<0||yy>=h) continue;
                        const int next=yy*w+xx;
                        if(closed[next]&&!labels[next]) { labels[next]=component;queue.push(next); }
                    }
                }
                if ((max_x-min_x+1)*(max_y-min_y+1)>=min_box_area) {
                    ++ring_count;
                    area=count;
                    full |= contours.is_full_ring(labels,component,w,h);
                }
            }
            if (ring_count>1) { area=0; full=false; }
            if (full) result.full=true;
            if (area>result.area) { result.area=area; result.color_index=color; }
        }
        const auto key=std::make_tuple(selected_index,w,h);
        if(result.full) {
            result.percent=1;
            if(full_area[key]!=result.area){full_area[key]=result.area;save_calibrations();}
        } else if(full_area[key]>0) {
            result.percent=std::min(0.99,double(result.area)/full_area[key]);
        }
        return result;
    }
};

