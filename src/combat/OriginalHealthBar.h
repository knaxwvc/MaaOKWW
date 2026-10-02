#pragma once
#include "CombatCheck.h"

// ok.util.color.find_color_rectangles: inRange -> RETR_LIST contours ->
// boundingRect -> dimensions -> 95% matching pixels. Use the OpenCV runtime
// already shipped with MaaFramework so the original contour algorithm remains.
// C ABI layouts: opencv2/core/types_c.h, CV_SEQUENCE_FIELDS/CV_CONTOUR_FIELDS.
class OriginalHealthBar {
    struct Point {int x,y;};
    struct Rect {int x,y,width,height;};
    struct Sequence {
        int flags,header_size;
        Sequence *h_prev,*h_next,*v_prev,*v_next;
        int total,elem_size;
        signed char *block_max,*ptr;
        int delta_elems;
        void *storage,*free_blocks,*first;
    };
    struct Contour {Sequence sequence;Rect rect;int color,reserved[3];};
    using CreateMat=void* (__cdecl*)(int,int,int);
    using SetData=void (__cdecl*)(void*,void*,int);
    using ReleaseMat=void (__cdecl*)(void**);
    using CreateStorage=void* (__cdecl*)(int);
    using ReleaseStorage=void (__cdecl*)(void**);
    using FindContours=int (__cdecl*)(void*,void*,Sequence**,int,int,int,Point);
    using BoundingRect=Rect (__cdecl*)(const void*,int);
    CreateMat create_mat;
    SetData set_data;
    ReleaseMat release_mat;
    CreateStorage create_storage;
    ReleaseStorage release_storage;
    FindContours find_contours;
    BoundingRect bounding_rect;
public:
    OriginalHealthBar() {
        const auto module=GetModuleHandleW(L"opencv_world4_maa.dll");
        if(!module)throw std::runtime_error("MaaFramework OpenCV runtime not loaded");
        create_mat=api<CreateMat>(module,"cvCreateMatHeader");
        set_data=api<SetData>(module,"cvSetData");
        release_mat=api<ReleaseMat>(module,"cvReleaseMat");
        create_storage=api<CreateStorage>(module,"cvCreateMemStorage");
        release_storage=api<ReleaseStorage>(module,"cvReleaseMemStorage");
        find_contours=api<FindContours>(module,"cvFindContours");
        bounding_rect=api<BoundingRect>(module,"cvBoundingRect");
    }
    std::vector<ScreenBox> rectangles(const FrameState& frame,ScreenBox box,
        bool boss,double min_width,double min_height,double max_height=-1) const {
        std::vector<ScreenBox> result;
        if(frame.pixels.empty() || frame.channels<3 || box.width<=0 || box.height<=0)return result;
        const int stride=box.width+2;
        std::vector<unsigned char> mask(size_t(stride)*(box.height+2),0);
        for(int y=0;y<box.height;++y)for(int x=0;x<box.width;++x){
            const auto* p=frame.pixels.data()+(size_t(y+box.y)*frame.width+x+box.x)*frame.channels;
            const bool hit=boss?p[2]>=245 && p[1]>=30 && p[1]<=185 && p[0]>=4 && p[0]<=75:
                p[2]>=174 && p[2]<=225 && p[1]>=55 && p[1]<=85 && p[0]>=55 && p[0]<=76;
            if(hit)mask[size_t(y+1)*stride+x+1]=255;
        }
        // Modern cv::findContours pads the image by one zero pixel. Keep the
        // unmodified mask for the original matching_pixels/total_pixels ratio.
        auto contour_mask=mask;
        void* matrix=create_mat(box.height+2,stride,0); // CV_8UC1
        void* storage=create_storage(0);
        if(!matrix || !storage){
            if(matrix)release_mat(&matrix);if(storage)release_storage(&storage);
            throw std::runtime_error("Maa OpenCV contour allocation failed");
        }
        try{
            set_data(matrix,contour_mask.data(),stride);
            Sequence* first=nullptr;
            find_contours(matrix,storage,&first,int(sizeof(Contour)),1,2,{-1,-1});
            for(auto* contour=first;contour;contour=contour->h_next){
                const auto r=bounding_rect(contour,0);
                if(r.width<min_width || r.height<min_height ||
                    (max_height>=0 && r.height>max_height))continue;
                size_t matching=0;
                for(int y=r.y;y<r.y+r.height;++y)for(int x=r.x;x<r.x+r.width;++x)
                    matching+=mask[size_t(y+1)*stride+x+1]==255;
                if(double(matching)/(r.width*r.height)>=0.95)
                    result.push_back({r.x+box.x,r.y+box.y,r.width,r.height});
            }
        }catch(...){release_mat(&matrix);release_storage(&storage);throw;}
        release_mat(&matrix);release_storage(&storage);
        return result;
    }
    bool has_health_bar(const FrameState& frame,bool already_in_combat) const {
        if(frame.pixels.empty())return false;
        const double min_height=int(frame.height*9.0/2160);
        const double min_width=int(frame.width*(already_in_combat?12.0:100.0)/3840);
        if(!rectangles(frame,{0,0,frame.width,frame.height},false,min_width,min_height,min_height*3).empty())return true;
        const double scale=std::min(frame.width/3840.0,frame.height/2160.0);
        const ScreenBox boss_box{
            int(std::round(frame.width*0.5+(1269-1920)*scale)),
            int(std::round(frame.height*0.5+(58-1080)*scale)),
            int(std::round((2533-1269)*scale)),int(std::round((200-58)*scale))};
        return rectangles(frame,boss_box,true,min_width,min_height*1.3).size()==1;
    }
};
