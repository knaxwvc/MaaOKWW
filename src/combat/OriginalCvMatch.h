#pragma once
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

// Direct port of working/ok/feature/vision.py:shape_match. The OpenCV runtime
// and screenshot are supplied by MaaFramework; there is no Python runtime.
class OriginalCvMatch {
    struct Point {int x,y;};
    using Create=void* (__cdecl*)(int,int,int);
    using Set=void (__cdecl*)(void*,void*,int);
    using Release=void (__cdecl*)(void**);
    using Convert=void (__cdecl*)(const void*,void*,int);
    using Match=void (__cdecl*)(const void*,const void*,void*,int);
    using MinMax=void (__cdecl*)(const void*,double*,double*,Point*,Point*,const void*);
    using Sobel=void (__cdecl*)(const void*,void*,int,int,int);
    using Polar=void (__cdecl*)(const void*,const void*,void*,void*,int);
    Create create;Set set;Release release;Convert convert;Match match;MinMax minmax;Sobel sobel;Polar polar;
    struct Matrix {
        void* value;Release release;
        Matrix(Create c,Set s,Release r,void* data,int w,int h,int type,int stride):release(r) {
            value=c(h,w,type);
            if(!value)throw std::runtime_error("Maa OpenCV match allocation failed");
            s(value,data,stride);
        }
        ~Matrix(){if(value)release(&value);}
    };
    template<class T> static double deviation(const std::vector<T>& values) {
        double mean=0,variance=0;
        for(auto value:values)mean+=value;mean/=values.size();
        for(auto value:values)variance+=(double(value)-mean)*(double(value)-mean);
        return std::sqrt(variance/values.size());
    }
    template<class T> double correlate(std::vector<T>& source,int sw,int sh,std::vector<T>& templ,int tw,int th,
                                      int type,int& x,int& y) const {
        const int rw=sw-tw+1,rh=sh-th+1;
        if(rw<=0 || rh<=0)return 0;
        std::vector<float> result(size_t(rw)*rh);
        Matrix a(create,set,release,source.data(),sw,sh,type,sw*sizeof(T));
        Matrix b(create,set,release,templ.data(),tw,th,type,tw*sizeof(T));
        Matrix c(create,set,release,result.data(),rw,rh,5,rw*sizeof(float));
        match(a.value,b.value,c.value,5);
        for(auto& value:result)if(!std::isfinite(value))value=0;
        double score=0;Point location{};
        minmax(c.value,nullptr,&score,nullptr,&location,nullptr);x=location.x;y=location.y;
        return score;
    }
    std::vector<float> edges(const std::vector<unsigned char>& input,int w,int h) const {
        const int pw=w+2,ph=h+2;
        std::vector<float> padded(size_t(pw)*ph),dx(padded.size()),dy(padded.size()),magnitude(padded.size());
        for(int y=0;y<ph;++y)for(int x=0;x<pw;++x){
            const int sx=x==0?1:x==w+1?w-2:x-1,sy=y==0?1:y==h+1?h-2:y-1;
            padded[size_t(y)*pw+x]=input[size_t(sy)*w+sx];
        }
        Matrix a(create,set,release,padded.data(),pw,ph,5,pw*sizeof(float));
        Matrix b(create,set,release,dx.data(),pw,ph,5,pw*sizeof(float));
        Matrix c(create,set,release,dy.data(),pw,ph,5,pw*sizeof(float));
        Matrix d(create,set,release,magnitude.data(),pw,ph,5,pw*sizeof(float));
        sobel(a.value,b.value,1,0,3);sobel(a.value,c.value,0,1,3);
        polar(b.value,c.value,d.value,nullptr,0);
        std::vector<float> out(size_t(w)*h);
        for(int y=0;y<h;++y)std::copy_n(magnitude.data()+size_t(y+1)*pw+1,w,out.data()+size_t(y)*w);
        return out;
    }
public:
    OriginalCvMatch() {
        auto module=GetModuleHandleW(L"opencv_world4_maa.dll");
        create=api<Create>(module,"cvCreateMatHeader");set=api<Set>(module,"cvSetData");release=api<Release>(module,"cvReleaseMat");
        convert=api<Convert>(module,"cvCvtColor");match=api<Match>(module,"cvMatchTemplate");minmax=api<MinMax>(module,"cvMinMaxLoc");
        sobel=api<Sobel>(module,"cvSobel");polar=api<Polar>(module,"cvCartToPolar");
    }
    std::vector<unsigned char> gray(std::vector<unsigned char>& bgr,int w,int h) const {
        std::vector<unsigned char> out(size_t(w)*h);
        Matrix a(create,set,release,bgr.data(),w,h,16,w*3),b(create,set,release,out.data(),w,h,0,w);
        convert(a.value,b.value,6);return out;
    }
    bool shape(std::vector<unsigned char> search,int sw,int sh,std::vector<unsigned char> templ,int tw,int th,
               double threshold,double& score,int& x,int& y) const {
        if(sw*sh>250000 || tw<5 || th<5 || sw<tw || sh<th)return false;
        auto a=gray(search,sw,sh),b=gray(templ,tw,th);
        if(deviation(b)<5)return false;
        score=correlate(a,sw,sh,b,tw,th,0,x,y);
        if(score<std::max(0.90,threshold))return false;
        std::vector<unsigned char> patch(size_t(tw)*th);
        for(int row=0;row<th;++row)std::copy_n(a.data()+size_t(y+row)*sw+x,tw,patch.data()+size_t(row)*tw);
        auto edge_template=edges(b,tw,th),edge_patch=edges(patch,tw,th);
        if(deviation(edge_template)<1 || deviation(edge_patch)<1)return false;
        int ex=0,ey=0;const double edge_score=correlate(edge_patch,tw,th,edge_template,tw,th,5,ex,ey);
        return std::isfinite(edge_score) && edge_score>=0.75;
    }
};
