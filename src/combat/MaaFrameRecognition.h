#pragma once
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>
#include "OriginalBoxes.h"
#include "MaaImageScale.h"
#include "OriginalTemplates.h"
#include "OriginalCvMatch.h"
#include <map>

struct MaaFrameMatch {
    bool hit=false;
    double score=-1;
    MaaRect box{};
};

// Keep one immutable Maa screenshot for every observation in a HUD snapshot.
// Direct recognition avoids action delays and extra captures between labels.
class MaaFrameRecognition {
    HMODULE dll;
    MaaTasker* tasker;
    MaaController* controller;
    MaaImageBuffer* image=nullptr;
    MaaImageBuffer* recognition_image=nullptr;
    std::filesystem::path root;
    OriginalCvMatch cv;
    struct Template {std::vector<unsigned char> pixels;int w=0,h=0;std::string key;std::string_view name;};
    std::map<std::string,Template> loaded_templates,prepared_templates;
    template<class F> F fn(const char* name) const {return api<F>(dll,name);}
public:
    int width=0,height=0;
    int team_count=0;
    MaaFrameRecognition(HMODULE module,MaaTasker* t,MaaController* c,const std::filesystem::path& directory):dll(module),tasker(t),controller(c),root(directory) {
        image=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
        recognition_image=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
    }
    ~MaaFrameRecognition(){
        if(image)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(image);
        if(recognition_image)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(recognition_image);
    }
    MaaFrameRecognition(const MaaFrameRecognition&)=delete;
    MaaFrameRecognition& operator=(const MaaFrameRecognition&)=delete;
    bool capture() {
        if(!image)return false;
        auto wait=fn<decltype(&MaaControllerWait)>("MaaControllerWait");
        if(wait(controller,fn<decltype(&MaaControllerPostScreencap)>("MaaControllerPostScreencap")(controller))!=MaaStatus_Succeeded ||
           !fn<decltype(&MaaControllerCachedImage)>("MaaControllerCachedImage")(controller,image))return false;
        width=fn<decltype(&MaaImageBufferWidth)>("MaaImageBufferWidth")(image);
        height=fn<decltype(&MaaImageBufferHeight)>("MaaImageBufferHeight")(image);
        return width>0 && height>0;
    }
    MaaImageBuffer* buffer() const {return image;}
    MaaImageBuffer* recognition_buffer() const {return image;}
    bool save(const std::filesystem::path& path) {
        if(!image)return false;
        const auto* data=fn<decltype(&MaaImageBufferGetEncoded)>("MaaImageBufferGetEncoded")(image);
        const auto size=fn<decltype(&MaaImageBufferGetEncodedSize)>("MaaImageBufferGetEncodedSize")(image);
        if(!data || !size)return false;
        std::ofstream file(path,std::ios::binary);
        file.write(reinterpret_cast<const char*>(data),std::streamsize(size));return bool(file);
    }
    const Template& prepare_template(const char* filename,bool bw,int gray_threshold,double match_scale) {
        const std::string requested=filename;
        const bool half=requested=="cartethyia_sword2_half.png" || requested=="cartethyia_sword3_half.png";
        std::string original_filename=filename;
        if(half){
            const auto name=requested=="cartethyia_sword2_half.png"?"forte_cartethyia_sword2":"forte_cartethyia_sword3";
            for(const auto& original:original_templates)if(original.name==name){original_filename=original.file;break;}
        }
        const auto* source=find_original_template(original_filename);
        if(!source)throw std::runtime_error(std::string("Original template missing: ")+filename);
        auto found=loaded_templates.find(original_filename);
        if(found==loaded_templates.end()){
            std::ifstream in(root/"resource"/"image"/"original"/original_filename,std::ios::binary);
            std::vector<unsigned char> encoded((std::istreambuf_iterator<char>(in)),{});
            auto buffer=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
            if(!buffer || encoded.empty() || !fn<decltype(&MaaImageBufferSetEncoded)>("MaaImageBufferSetEncoded")(buffer,encoded.data(),encoded.size())){
                if(buffer)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);
                throw std::runtime_error(std::string("Original image decode failed: ")+filename);
            }
            Template item;item.w=source->width;item.h=source->height;item.name=source->name;
            const int channels=fn<decltype(&MaaImageBufferChannels)>("MaaImageBufferChannels")(buffer);
            const auto* raw=static_cast<const unsigned char*>(fn<decltype(&MaaImageBufferGetRawData)>("MaaImageBufferGetRawData")(buffer));
            if(!raw || channels<3){fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);throw std::runtime_error("Original template pixels missing");}
            item.pixels.resize(size_t(item.w)*item.h*3);
            for(size_t i=0;i<size_t(item.w)*item.h;++i)std::copy_n(raw+i*channels,3,item.pixels.data()+i*3);
            fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);
            found=loaded_templates.emplace(original_filename,std::move(item)).first;
        }
        const double source_scale=std::min(double(width)/source->source_width,double(height)/source->source_height);
        const int tw=std::max(1,original_round(source->width*source_scale)),full_height=std::max(1,original_round(source->height*source_scale));
        const int th=half?std::max(1,int(full_height*0.5)):full_height;
        const int mw=std::max(1,original_round(tw*match_scale)),mh=std::max(1,original_round(th*match_scale));
        const auto key=std::string("okww_original_")+filename+"_"+std::to_string(tw)+"x"+std::to_string(th)+"_"+
            std::to_string(mw)+"x"+std::to_string(mh)+"_"+std::to_string(bw?1:gray_threshold)+".png";
        auto prepared=prepared_templates.find(key);if(prepared!=prepared_templates.end())return prepared->second;
        Template item;item.w=tw;item.h=th;item.name=source->name;item.key=key;
        item.pixels=maa_resize_pixels(found->second.pixels.data(),source->width,source->height,3,tw,full_height,1);
        if(half)item.pixels.resize(size_t(tw)*th*3);
        process(item.pixels,tw,th,bw,gray_threshold);
        if(match_scale!=1){item.pixels=maa_resize_pixels(item.pixels.data(),tw,th,3,mw,mh,3);item.w=mw;item.h=mh;}
        auto buffer=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
        const auto resource=fn<decltype(&MaaTaskerGetResource)>("MaaTaskerGetResource")(tasker);
        const bool okay=buffer && fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData")(buffer,item.pixels.data(),item.w,item.h,16) &&
            fn<decltype(&MaaResourceOverrideImage)>("MaaResourceOverrideImage")(resource,key.c_str(),buffer);
        if(buffer)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);
        if(!okay)throw std::runtime_error("Maa original template override failed");
        return prepared_templates.emplace(key,std::move(item)).first->second;
    }
    void process(std::vector<unsigned char>& pixels,int w,int h,bool bw,int gray_threshold) {
        if(bw)for(size_t i=0;i<size_t(w)*h;++i){auto* p=pixels.data()+i*3;p[0]=p[1]=p[2]=p[0]>=244 && p[1]>=244 && p[2]>=244?255:0;}
        if(gray_threshold){auto gray=cv.gray(pixels,w,h);for(size_t i=0;i<gray.size();++i)pixels[i*3]=pixels[i*3+1]=pixels[i*3+2]=gray[i]>gray_threshold?255:0;}
    }
    MaaFrameMatch match(const char* filename,ScreenBox region,double threshold,bool convert_bw=false,int gray_threshold=0,int target_height=0) {
        MaaFrameMatch result;
        const int x1=std::clamp(region.x,0,width),y1=std::clamp(region.y,0,height);
        const int x2=std::clamp(region.x+std::max(0,region.width),0,width),y2=std::clamp(region.y+std::max(0,region.height),0,height);
        if(x2<=x1 || y2<=y1)return result;
        const int sw=x2-x1,sh=y2-y1;
        const int channels=fn<decltype(&MaaImageBufferChannels)>("MaaImageBufferChannels")(image);
        const auto* raw=static_cast<const unsigned char*>(fn<decltype(&MaaImageBufferGetRawData)>("MaaImageBufferGetRawData")(image));
        if(!raw || channels<3)return result;
        std::vector<unsigned char> search(size_t(sw)*sh*3);
        for(int y=0;y<sh;++y)for(int x=0;x<sw;++x)std::copy_n(raw+(size_t(y1+y)*width+x1+x)*channels,3,search.data()+(size_t(y)*sw+x)*3);
        process(search,sw,sh,convert_bw,gray_threshold);
        const double scale=target_height>0 && height>=1.5*target_height?double(target_height)/height:1;
        const int mw=std::max(1,original_round(sw*scale)),mh=std::max(1,original_round(sh*scale));
        if(scale!=1)search=maa_resize_pixels(search.data(),sw,sh,3,mw,mh,3);
        const auto& templ=prepare_template(filename,convert_bw,gray_threshold,scale);
        if(templ.w>mw || templ.h>mh)return result;
        if(!fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData")(recognition_image,search.data(),mw,mh,16))
            throw std::runtime_error("Maa original search image failed");
        const std::string params="{\"template\":\""+templ.key+
            "\",\"threshold\":"+std::to_string(threshold)+",\"method\":5,\"green_mask\":false,\"order_by\":\"Score\",\"roi\":[0,0,"+
            std::to_string(mw)+","+std::to_string(mh)+"]}";
        auto post=fn<decltype(&MaaTaskerPostRecognition)>("MaaTaskerPostRecognition");
        auto wait=fn<decltype(&MaaTaskerWait)>("MaaTaskerWait");
        const auto id=post(tasker,"TemplateMatch",params.c_str(),recognition_image);(void)wait(tasker,id);
        auto create=fn<decltype(&MaaStringBufferCreate)>("MaaStringBufferCreate");
        auto destroy=fn<decltype(&MaaStringBufferDestroy)>("MaaStringBufferDestroy");
        auto get=fn<decltype(&MaaStringBufferGet)>("MaaStringBufferGet");
        MaaStringBuffer* node=create();MaaStringBuffer* algorithm=create();MaaStringBuffer* detail=create();
        MaaNodeId nodes[8]{};MaaSize count=8;MaaStatus status=MaaStatus_Invalid;
        if(node && algorithm && detail && fn<decltype(&MaaTaskerGetTaskDetail)>("MaaTaskerGetTaskDetail")(tasker,id,node,nodes,&count,&status) && count>0) {
            MaaRecoId reco=MaaInvalidId;MaaActId action=MaaInvalidId;MaaBool complete=false,hit=false;
            if(fn<decltype(&MaaTaskerGetNodeDetail)>("MaaTaskerGetNodeDetail")(tasker,nodes[std::min<MaaSize>(count,8)-1],node,&reco,&action,&complete) &&
               reco!=MaaInvalidId && fn<decltype(&MaaTaskerGetRecognitionDetail)>("MaaTaskerGetRecognitionDetail")(
                   tasker,reco,node,algorithm,&hit,&result.box,detail,nullptr,nullptr)) {
                result.hit=hit!=0;
                const char* detail_text=get(detail);const std::string json=detail_text?detail_text:"";
                // Read the selected best result, not an arbitrary entry in all[].
                auto best=json.find("\"best\"");
                if(best!=std::string::npos) {
                    auto end=json.find('}',best);auto key=json.find("\"score\"",best);
                    if(key!=std::string::npos && (end==std::string::npos || key<end)) {
                        auto colon=json.find(':',key);char* parsed_end=nullptr;
                        if(colon!=std::string::npos) {
                            double value=std::strtod(json.c_str()+colon+1,&parsed_end);
                            if(parsed_end!=json.c_str()+colon+1)result.score=value;
                        }
                    }
                }
            }
        }
        if(detail)destroy(detail);if(algorithm)destroy(algorithm);if(node)destroy(node);
        const bool fallback=templ.name=="char_1_text" || templ.name=="char_2_text" || templ.name=="char_3_text" || templ.name=="char_4_text" ||
            templ.name=="target_enemy_white" || templ.name=="target_enemy_long_inner" || templ.name=="pick_up_f_hcenter_vcenter";
        if(!result.hit && fallback && !convert_bw && !gray_threshold){
            int x=0,y=0;double score=0;
            if(cv.shape(search,mw,mh,templ.pixels,templ.w,templ.h,threshold,score,x,y)){
                result.hit=true;result.score=score;result.box={x,y,templ.w,templ.h};
            }
        }
        result.box={original_round(result.box.x/scale)+x1,original_round(result.box.y/scale)+y1,
            original_round(result.box.width/scale),original_round(result.box.height/scale)};
        return result;
    }
    MaaFrameMatch match_box(const char* filename,std::string_view name,double threshold,
        double expand_x=1,double expand_y=1) {
        const auto* source=find_original_box(name);if(!source)return {};
        auto box=scale_original_box(*source,width,height);
        const int w=original_round(box.width*expand_x),h=original_round(box.height*expand_y);
        box.x=std::max(0,original_round(box.x+box.width/2.0-w/2.0));
        box.y=std::max(0,original_round(box.y+box.height/2.0-h/2.0));
        box.width=w;box.height=h;
        return match(filename,box,threshold);
    }
    int active_slot(std::array<double,3>* scores=nullptr) {
        const char* files[]={"56_34.png","52_27.png","54_33.png"};
        int hits=0,absent=-1;
        for(int i=0;i<3;++i) {
            const auto* source=find_original_box("char_"+std::to_string(i+1)+"_text");
            if(!source)return -1;
            auto box=scale_original_box(*source,width,height);
            const int x1=std::max(0,original_round(box.x-width*0.002)),y1=std::max(0,original_round(box.y-height*0.002));
            const int x2=std::min(width,original_round(box.x+box.width+width*0.002)),y2=std::min(height,original_round(box.y+box.height+height*0.002));
            box={x1,y1,x2-x1,y2-y1};
            auto result=match(files[i],box,0.8);
            if(scores)(*scores)[size_t(i)]=result.score;
            if(result.hit)++hits;else if(absent<0)absent=i+1;
        }
        team_count=hits+1;
        return hits==2 || hits==1?absent:-1;
    }
};

