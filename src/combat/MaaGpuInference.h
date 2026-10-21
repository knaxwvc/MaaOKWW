#pragma once
#include <dxgi1_2.h>
#include <cstdint>
#include <string>

struct MaaGpuSelection {
    MaaInferenceExecutionProvider provider=MaaInferenceExecutionProvider_CPU;
    MaaInferenceDevice adapter=MaaInferenceDevice_CPU;
    std::string name="CPU",reason;
    std::uint64_t dedicated_bytes=0;
    unsigned vendor=0;
    bool gpu() const {return provider==MaaInferenceExecutionProvider_DirectML;}
};

inline MaaGpuSelection maa_choose_ocr_gpu(int requested=-1){
    MaaGpuSelection selected;
    auto module=LoadLibraryExW(L"dxgi.dll",nullptr,LOAD_LIBRARY_SEARCH_SYSTEM32);
    if(!module){selected.reason="dxgi_unavailable";return selected;}
    using CreateFactory=HRESULT(WINAPI*)(REFIID,void**);
    const auto create=reinterpret_cast<CreateFactory>(GetProcAddress(module,"CreateDXGIFactory1"));
    IDXGIFactory1* factory=nullptr;
    if(!create || FAILED(create(__uuidof(IDXGIFactory1),reinterpret_cast<void**>(&factory)))){
        FreeLibrary(module);selected.reason="adapter_enumeration_failed";return selected;
    }
    for(unsigned index=0;index<32;++index){
        IDXGIAdapter1* adapter=nullptr;
        const auto result=factory->EnumAdapters1(index,&adapter);
        if(result==DXGI_ERROR_NOT_FOUND)break;
        if(FAILED(result) || !adapter)continue;
        DXGI_ADAPTER_DESC1 description{};
        const auto described=adapter->GetDesc1(&description);adapter->Release();
        if(FAILED(described) || (description.Flags&DXGI_ADAPTER_FLAG_SOFTWARE))continue;
        if(requested>=0 && unsigned(requested)!=index)continue;
        const bool nvidia=description.VendorId==0x10de,previous_nvidia=selected.vendor==0x10de;
        const bool better=!selected.gpu() || (nvidia&&!previous_nvidia) ||
            (nvidia==previous_nvidia && description.DedicatedVideoMemory>selected.dedicated_bytes);
        if(!better)continue;
        const int count=WideCharToMultiByte(CP_UTF8,0,description.Description,-1,nullptr,0,nullptr,nullptr);
        std::string name(size_t(std::max(1,count)),0);
        if(count>0){WideCharToMultiByte(CP_UTF8,0,description.Description,-1,name.data(),count,nullptr,nullptr);name.pop_back();}
        else name="Unknown GPU";
        selected.provider=MaaInferenceExecutionProvider_DirectML;selected.adapter=int(index);
        selected.name=std::move(name);selected.dedicated_bytes=description.DedicatedVideoMemory;
        selected.vendor=description.VendorId;
    }
    factory->Release();FreeLibrary(module);
    if(!selected.gpu())selected.reason=requested>=0?"requested_adapter_not_found":"no_hardware_adapter";
    return selected;
}

inline void maa_set_inference(HMODULE dll,MaaResource* resource,MaaGpuSelection selection){
    const auto set=api<decltype(&MaaResourceSetOption)>(dll,"MaaResourceSetOption");
    if(!set(resource,MaaResOption_InferenceExecutionProvider,&selection.provider,sizeof(selection.provider)) ||
       !set(resource,MaaResOption_InferenceDevice,&selection.adapter,sizeof(selection.adapter)))
        throw std::runtime_error("Maa OCR inference device configuration failed");
}

inline MaaGpuSelection maa_configure_ocr_gpu(const fs::path& root,HMODULE dll,MaaResource* resource){
    const auto config=root/L"config.ini";
    MaaGpuSelection selected;
    if(GetPrivateProfileIntW(L"Inference",L"UseGPU",1,config.c_str())){
        selected=maa_choose_ocr_gpu(GetPrivateProfileIntW(L"Inference",L"GPUAdapter",-1,config.c_str()));
        const auto runtime=GetModuleHandleW(L"onnxruntime_maa.dll");
        if(selected.gpu() && (!runtime || !GetProcAddress(runtime,"OrtSessionOptionsAppendExecutionProvider_DML"))){
            selected={};selected.reason="directml_provider_unavailable";
        }
    }else selected.reason="disabled_in_config";
    // Must precede PostBundle: Maa selects the backend when resources load.
    maa_set_inference(dll,resource,selected);
    std::cout<<"ocr_backend provider="<<(selected.gpu()?"DirectML":"CPU")<<" dxgi_adapter="<<selected.adapter
        <<" name="<<selected.name<<" dedicated_mb="<<selected.dedicated_bytes/(1024*1024)
        <<" configured=1"<<(selected.reason.empty()?"":" reason=")<<selected.reason<<'\n'<<std::flush;
    return selected;
}
