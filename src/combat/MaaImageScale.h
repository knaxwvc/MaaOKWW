#pragma once
#include <vector>
// Shared OpenCV runtime supplied by MaaFramework, cvResize / INTER_LINEAR.
inline std::vector<unsigned char> maa_resize_pixels(const unsigned char* source,
    int width,int height,int channels,int output_width,int output_height,int interpolation=-1) {
    std::vector<unsigned char> result(size_t(output_width)*output_height*channels);
    if(width==output_width && height==output_height){
        std::copy(source,source+result.size(),result.data());return result;
    }
    const auto module=GetModuleHandleW(L"opencv_world4_maa.dll");
    auto create=api<void* (__cdecl*)(int,int,int)>(module,"cvCreateMatHeader");
    auto set=api<void (__cdecl*)(void*,void*,int)>(module,"cvSetData");
    auto release=api<void (__cdecl*)(void**)>(module,"cvReleaseMat");
    auto resize=api<void (__cdecl*)(const void*,void*,int)>(module,"cvResize");
    void* input=create(height,width,(channels-1)<<3);
    void* output=create(output_height,output_width,(channels-1)<<3);
    if(!input || !output){
        if(input)release(&input);if(output)release(&output);
        throw std::runtime_error("Maa OpenCV resize allocation failed");
    }
    try{
        set(input,const_cast<unsigned char*>(source),width*channels);
        set(output,result.data(),output_width*channels);
        resize(input,output,interpolation<0?(output_height<height?3:1):interpolation);
    }catch(...){release(&input);release(&output);throw;}
    release(&input);release(&output);return result;
}
