#pragma once
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include "OriginalBoxes.h"
#include "CombatCheck.h"
#include "MaaImageScale.h"
#include "OriginalTemplates.h"
#include "OriginalCvMatch.h"
#include "MaaRecognitionSession.h"
#include <map>
#include <tuple>

struct MaaFrameMatch {
    bool hit=false;
    double score=-1;
    MaaRect box{};
    double raw_score=-1;
};

inline double maa_match_detail_score(const std::string& json,const char* field){
    const auto key=json.find(std::string("\"")+field+"\"");
    if(key==std::string::npos)return -1;
    auto pos=json.find(':',key);
    if(pos==std::string::npos)return -1;
    ++pos;
    while(pos<json.size() && std::isspace(static_cast<unsigned char>(json[pos])))++pos;
    if(pos<json.size() && json[pos]=='['){
        ++pos;
        while(pos<json.size() && std::isspace(static_cast<unsigned char>(json[pos])))++pos;
    }
    if(pos>=json.size() || json[pos]!='{')return -1;
    const auto end=json.find('}',pos),score=json.find("\"score\"",pos);
    if(score==std::string::npos || end==std::string::npos || score>=end)return -1;
    const auto colon=json.find(':',score);
    if(colon==std::string::npos)return -1;
    char* parsed_end=nullptr;
    const double value=std::strtod(json.c_str()+colon+1,&parsed_end);
    return parsed_end!=json.c_str()+colon+1 && std::isfinite(value)?value:-1;
}

// Keep one immutable Maa screenshot for every observation in a HUD snapshot.
// Direct recognition avoids action delays and extra captures between labels.
class MaaFrameRecognition {
    HMODULE dll;
    MaaTasker* tasker;
    MaaController* controller;
    MaaContext* context;
    MaaRecognitionSession recognition;
    MaaImageBuffer* image=nullptr;
    std::filesystem::path root;
    OriginalCvMatch cv;
    struct Template {std::vector<unsigned char> pixels;int w=0,h=0;std::string key;std::string_view name;};
    std::map<std::string,Template> loaded_templates,prepared_templates;
    using MatchKey=std::tuple<std::string,int,int,int,int,double,bool,int,int>;
    std::map<MatchKey,MaaFrameMatch> frame_matches;
    using RegionKey=std::tuple<int,int,int,int,bool,int,int>;
    struct PreparedRegion {
        std::vector<unsigned char> source_pixels;
        std::vector<unsigned char> pixels;
        MaaImageBuffer* image=nullptr;
        std::uint64_t scene=~std::uint64_t(0);
        std::map<MatchKey,MaaFrameMatch> matches;
    };
    std::map<RegionKey,PreparedRegion> prepared_regions;
    std::uint64_t scene=0;
    template<class F> F fn(const char* name) const {return api<F>(dll,name);}
    void clear_regions(){
        for(auto& item:prepared_regions)if(item.second.image)
            fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(item.second.image);
        prepared_regions.clear();
    }
public:
    int width=0,height=0;
    int team_count=0;
    std::uint64_t cache_hits=0,captures=0;
    std::uint64_t sample_hash=0,sample_repeats=0;
    double capture_ms=0;
    std::uint64_t region_preparations=0,region_reuses=0,region_copy_bytes=0;
    std::uint64_t unchanged_region_reuses=0,unchanged_match_reuses=0;
    MaaFrameRecognition(HMODULE module,MaaTasker* t,MaaController* c,const std::filesystem::path& directory,MaaContext* ctx=nullptr)
        :dll(module),tasker(t),controller(c),context(ctx),recognition(module,t,ctx),root(directory) {
        image=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
    }
    ~MaaFrameRecognition(){
        if(image)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(image);
        clear_regions();
    }
    MaaFrameRecognition(const MaaFrameRecognition&)=delete;
    MaaFrameRecognition& operator=(const MaaFrameRecognition&)=delete;
    bool capture() {
        const auto started=std::chrono::steady_clock::now();
        frame_matches.clear();
        ++scene;
        if(!image)return false;
        auto wait=fn<decltype(&MaaControllerWait)>("MaaControllerWait");
        if(wait(controller,fn<decltype(&MaaControllerPostScreencap)>("MaaControllerPostScreencap")(controller))!=MaaStatus_Succeeded ||
           !fn<decltype(&MaaControllerCachedImage)>("MaaControllerCachedImage")(controller,image))return false;
        const int new_width=fn<decltype(&MaaImageBufferWidth)>("MaaImageBufferWidth")(image);
        const int new_height=fn<decltype(&MaaImageBufferHeight)>("MaaImageBufferHeight")(image);
        if(new_width!=width || new_height!=height)clear_regions();
        width=new_width;height=new_height;
        const auto* raw=static_cast<const unsigned char*>(fn<decltype(&MaaImageBufferGetRawData)>("MaaImageBufferGetRawData")(image));
        const int channels=fn<decltype(&MaaImageBufferChannels)>("MaaImageBufferChannels")(image);
        if(!raw || channels<3 || width<=0 || height<=0)return false;
        // Cheap diagnostic only: unchanged samples are never used to reject a frame.
        std::uint64_t hash=14695981039346656037ull;
        for(int y=0;y<16;++y)for(int x=0;x<16;++x) {
            const auto* pixel=raw+(size_t((height-1)*y/15)*width+(width-1)*x/15)*channels;
            for(int c=0;c<3;++c){hash^=pixel[c];hash*=1099511628211ull;}
        }
        sample_repeats=hash==sample_hash?sample_repeats+1:0;sample_hash=hash;
        ++captures;capture_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-started).count();
        return width>0 && height>0;
    }
    void clear_matches(){frame_matches.clear();}
    std::uint64_t sequence() const{return scene;}
    std::uint64_t recognition_calls() const{return recognition.calls;}
    double recognition_ms() const{return recognition.elapsed_ms;}
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
        const auto custom=prepared_templates.find(filename);
        if(custom!=prepared_templates.end())return custom->second;
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
        bool okay=buffer && fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData")(buffer,item.pixels.data(),item.w,item.h,16);
        if(okay){
            if(context)okay=fn<decltype(&MaaContextOverrideImage)>("MaaContextOverrideImage")(context,key.c_str(),buffer)!=0;
            else okay=fn<decltype(&MaaResourceOverrideImage)>("MaaResourceOverrideImage")(
                fn<decltype(&MaaTaskerGetResource)>("MaaTaskerGetResource")(tasker),key.c_str(),buffer)!=0;
        }
        if(buffer)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);
        if(!okay)throw std::runtime_error("Maa original template override failed");
        return prepared_templates.emplace(key,std::move(item)).first->second;
    }
    void process(std::vector<unsigned char>& pixels,int w,int h,bool bw,int gray_threshold) {
        if(bw)for(size_t i=0;i<size_t(w)*h;++i){auto* p=pixels.data()+i*3;p[0]=p[1]=p[2]=p[0]>=244 && p[1]>=244 && p[2]>=244?255:0;}
        if(gray_threshold){auto gray=cv.gray(pixels,w,h);for(size_t i=0;i<gray.size();++i)pixels[i*3]=pixels[i*3+1]=pixels[i*3+2]=gray[i]>gray_threshold?255:0;}
    }
    MaaFrameMatch match_custom(const FrameState& source,ScreenBox region,double threshold){
        if(source.channels!=3 || source.pixels.empty() || source.width<=0 || source.height<=0)
            throw std::runtime_error("Official template requires valid BGR pixels");
        std::uint64_t hash=14695981039346656037ull;
        for(size_t i=0;i<source.pixels.size();++i){hash^=source.pixels.data()[i];hash*=1099511628211ull;}
        const std::string key="official_custom_"+std::to_string(source.width)+"x"+std::to_string(source.height)+"_"+std::to_string(hash)+".png";
        if(!prepared_templates.count(key)){
            Template item;item.w=source.width;item.h=source.height;item.name="official_custom";item.key=key;
            item.pixels.assign(source.pixels.data(),source.pixels.data()+source.pixels.size());
            auto* buffer=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
            bool okay=buffer && fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData")(buffer,item.pixels.data(),item.w,item.h,16);
            if(okay){if(context)okay=fn<decltype(&MaaContextOverrideImage)>("MaaContextOverrideImage")(context,key.c_str(),buffer)!=0;
                else okay=fn<decltype(&MaaResourceOverrideImage)>("MaaResourceOverrideImage")(fn<decltype(&MaaTaskerGetResource)>("MaaTaskerGetResource")(tasker),key.c_str(),buffer)!=0;}
            if(buffer)fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy")(buffer);
            if(!okay)throw std::runtime_error("Official custom Maa template registration failed");
            prepared_templates.emplace(key,std::move(item));
        }
        return match(key.c_str(),region,threshold);
    }
    MaaFrameMatch match(const char* filename,ScreenBox region,double threshold,bool convert_bw=false,int gray_threshold=0,int target_height=0) {
        MaaFrameMatch result;
        const int x1=std::clamp(region.x,0,width),y1=std::clamp(region.y,0,height);
        const int x2=std::clamp(region.x+std::max(0,region.width),0,width),y2=std::clamp(region.y+std::max(0,region.height),0,height);
        if(x2<=x1 || y2<=y1)return result;
        const MatchKey key{filename,x1,y1,x2,y2,threshold,convert_bw,gray_threshold,target_height};
        const auto cached=frame_matches.find(key);
        if(cached!=frame_matches.end()){++cache_hits;return cached->second;}
        const int sw=x2-x1,sh=y2-y1;
        const int channels=fn<decltype(&MaaImageBufferChannels)>("MaaImageBufferChannels")(image);
        const auto* raw=static_cast<const unsigned char*>(fn<decltype(&MaaImageBufferGetRawData)>("MaaImageBufferGetRawData")(image));
        if(!raw || channels<3)return result;
        const double scale=target_height>0 && height>=1.5*target_height?double(target_height)/height:1;
        const int mw=std::max(1,original_round(sw*scale)),mh=std::max(1,original_round(sh*scale));
        const auto& templ=prepare_template(filename,convert_bw,gray_threshold,scale);
        if(templ.w>mw || templ.h>mh)return result;
        // Reuse across captures only after comparing every source BGR byte.
        // New pixels, geometry or preprocessing still force fresh recognition.
        auto& prepared=prepared_regions[RegionKey{x1,y1,x2,y2,convert_bw,gray_threshold,target_height}];
        if(prepared.scene!=scene){
            bool unchanged=prepared.source_pixels.size()==size_t(sw)*sh*3;
            for(int y=0;unchanged && y<sh;++y){
                const auto* row=raw+(size_t(y1+y)*width+x1)*channels;
                const auto* previous=prepared.source_pixels.data()+size_t(y)*sw*3;
                if(channels==3)unchanged=std::memcmp(row,previous,size_t(sw)*3)==0;
                else for(int x=0;unchanged && x<sw;++x)
                    unchanged=std::memcmp(row+size_t(x)*channels,previous+size_t(x)*3,3)==0;
            }
            if(unchanged)++unchanged_region_reuses;
            else {
                prepared.source_pixels.resize(size_t(sw)*sh*3);
                for(int y=0;y<sh;++y)for(int x=0;x<sw;++x)
                    std::copy_n(raw+(size_t(y1+y)*width+x1+x)*channels,3,prepared.source_pixels.data()+(size_t(y)*sw+x)*3);
                prepared.pixels=prepared.source_pixels;
                process(prepared.pixels,sw,sh,convert_bw,gray_threshold);
                if(scale!=1)prepared.pixels=maa_resize_pixels(prepared.pixels.data(),sw,sh,3,mw,mh,3);
                if(!prepared.image)prepared.image=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
                if(!prepared.image || !fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData")(
                    prepared.image,prepared.pixels.data(),mw,mh,16))
                    throw std::runtime_error("Maa original search image failed");
                prepared.matches.clear();++region_preparations;
                region_copy_bytes+=size_t(sw)*sh*3+size_t(mw)*mh*3;
            }
            prepared.scene=scene;
        }else ++region_reuses;
        const auto unchanged_match=prepared.matches.find(key);
        if(unchanged_match!=prepared.matches.end()){
            ++unchanged_match_reuses;
            frame_matches.emplace(key,unchanged_match->second);
            return unchanged_match->second;
        }
        const std::string params="{\"template\":\""+templ.key+
            "\",\"threshold\":"+std::to_string(threshold)+",\"method\":5,\"green_mask\":false,\"order_by\":\"Score\",\"roi\":[0,0,"+
            std::to_string(mw)+","+std::to_string(mh)+"]}";
        const auto reco=recognition.run("TemplateMatch",params.c_str(),prepared.image);
        result.hit=reco.hit;result.box=reco.box;
        const std::string& json=reco.detail;
        // Only best drives recognition. A below-threshold score is diagnostic.
        result.score=maa_match_detail_score(json,"best");
        result.raw_score=maa_match_detail_score(json,"all");
        const bool fallback=templ.name=="char_1_text" || templ.name=="char_2_text" || templ.name=="char_3_text" || templ.name=="char_4_text" ||
            templ.name=="target_enemy_white" || templ.name=="target_enemy_long_inner" || templ.name=="pick_up_f_hcenter_vcenter";
        if(!result.hit && fallback && !convert_bw && !gray_threshold){
            int x=0,y=0;double score=0;
            if(cv.shape(prepared.pixels,mw,mh,templ.pixels,templ.w,templ.h,threshold,score,x,y)){
                result.hit=true;result.score=score;result.box={x,y,templ.w,templ.h};
            }
        }
        result.box={original_round(result.box.x/scale)+x1,original_round(result.box.y/scale)+y1,
            original_round(result.box.width/scale),original_round(result.box.height/scale)};
        result.raw_score=std::max(result.raw_score,result.score);
        prepared.matches.emplace(key,result);
        frame_matches.emplace(key,result);
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

