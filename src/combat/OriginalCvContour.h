#pragma once
#include <Windows.h>
#include <vector>
#include <stdexcept>

// OpenCV operations used by BaseCombatTask.count_rings, through Maa's runtime.
// Declarations follow opencv2/core/types_c.h and imgproc/imgproc_c.h.
class OriginalCvContour {
    struct Point {int x,y;};
    struct Slice {int start,end;};
    struct Scalar {double values[4];};
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
    using Release=void (__cdecl*)(void**);
    using CreateStorage=void* (__cdecl*)(int);
    using FindContours=int (__cdecl*)(void*,void*,Sequence**,int,int,int,Point);
    using ArcLength=double (__cdecl*)(const void*,Slice,int);
    using ApproxPoly=Sequence* (__cdecl*)(const void*,int,void*,int,double,int);
    using IsConvex=int (__cdecl*)(const void*);
    using Circle=void (__cdecl*)(void*,Point,int,Scalar,int,int,int);
    CreateMat create_mat;
    SetData set_data;
    Release release_mat,release_storage;
    CreateStorage create_storage;
    FindContours find_contours;
    ArcLength arc_length;
    ApproxPoly approx_poly;
    IsConvex is_convex;
    Circle circle;
    void* matrix(std::vector<unsigned char>& mask,int width,int height) const {
        void* mat=create_mat(height,width,0);
        if(!mat)throw std::runtime_error("Maa OpenCV matrix allocation failed");
        set_data(mat,mask.data(),width);return mat;
    }
public:
    OriginalCvContour() {
        const auto module=GetModuleHandleW(L"opencv_world4_maa.dll");
        if(!module)throw std::runtime_error("MaaFramework OpenCV runtime not loaded");
        create_mat=api<CreateMat>(module,"cvCreateMatHeader");
        set_data=api<SetData>(module,"cvSetData");
        release_mat=api<Release>(module,"cvReleaseMat");
        release_storage=api<Release>(module,"cvReleaseMemStorage");
        create_storage=api<CreateStorage>(module,"cvCreateMemStorage");
        find_contours=api<FindContours>(module,"cvFindContours");
        arc_length=api<ArcLength>(module,"cvArcLength");
        approx_poly=api<ApproxPoly>(module,"cvApproxPoly");
        is_convex=api<IsConvex>(module,"cvCheckContourConvexity");
        circle=api<Circle>(module,"cvCircle");
    }
    std::vector<unsigned char> ring_mask(int width,int height,int inner,int outer) const {
        std::vector<unsigned char> mask(size_t(width)*height,0);
        void* mat=matrix(mask,width,height);
        circle(mat,{width/2,height/2},outer,{{255,0,0,0}},-1,8,0);
        if(inner>=0)circle(mat,{width/2,height/2},inner,{{0,0,0,0}},-1,8,0);
        release_mat(&mat);return mask;
    }
    bool is_full_ring(const std::vector<int>& labels,int component,int width,int height) const {
        const int stride=width+2;
        std::vector<unsigned char> mask(size_t(stride)*(height+2),0);
        for(int y=0;y<height;++y)for(int x=0;x<width;++x)
            if(labels[size_t(y)*width+x]==component)mask[size_t(y+1)*stride+x+1]=255;
        void* mat=matrix(mask,stride,height+2);
        void* storage=create_storage(0);
        if(!storage){release_mat(&mat);throw std::runtime_error("Maa OpenCV contour storage failed");}
        bool full=false;
        try {
            Sequence* first=nullptr;
            // RETR_EXTERNAL, CHAIN_APPROX_SIMPLE; modern findContours zero border.
            find_contours(mat,storage,&first,int(sizeof(Contour)),0,2,{-1,-1});
            if(first && !first->h_next){
                const double epsilon=0.05*arc_length(first,{0,0x3fffffff},1);
                const auto* approx=approx_poly(first,int(sizeof(Contour)),storage,0,epsilon,0);
                full=approx && approx->total>=4 && is_convex(approx)>0;
            }
        }catch(...){release_mat(&mat);release_storage(&storage);throw;}
        release_mat(&mat);release_storage(&storage);return full;
    }
};
