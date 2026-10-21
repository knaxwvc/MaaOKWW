#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <streambuf>
#include <Windows.h>

class MaaTimestampedLog final : public std::streambuf {
    std::streambuf* destination;
    bool line_start=true;
    void prefix(){
        if(!line_start)return;
        SYSTEMTIME now{};GetLocalTime(&now);
        char stamp[40]{};
        const int length=std::snprintf(stamp,sizeof(stamp),"[%04u-%02u-%02u %02u:%02u:%02u.%03u] ",
            unsigned(now.wYear),unsigned(now.wMonth),unsigned(now.wDay),
            unsigned(now.wHour),unsigned(now.wMinute),unsigned(now.wSecond),unsigned(now.wMilliseconds));
        destination->sputn(stamp,length);line_start=false;
    }
    std::streamsize xsputn(const char* text,std::streamsize count) override {
        std::streamsize written=0;
        while(written<count){
            prefix();
            const auto* newline=static_cast<const char*>(std::memchr(text+written,'\n',size_t(count-written)));
            const auto length=newline?std::streamsize(newline-(text+written)+1):count-written;
            const auto result=destination->sputn(text+written,length);
            written+=result;
            if(result!=length)break;
            if(newline)line_start=true;
        }
        return written;
    }
    int_type overflow(int_type value) override {
        if(traits_type::eq_int_type(value,traits_type::eof()))return traits_type::not_eof(value);
        const char text=traits_type::to_char_type(value);
        return xsputn(&text,1)==1?value:traits_type::eof();
    }
    int sync() override {return destination->pubsync();}
public:
    explicit MaaTimestampedLog(std::streambuf* output):destination(output){}
};

class MaaLogRedirect final {
    std::streambuf *previous_output,*previous_error;
public:
    explicit MaaLogRedirect(std::streambuf* output)
        :previous_output(std::cout.rdbuf(output)),previous_error(std::cerr.rdbuf(output)){}
    ~MaaLogRedirect(){
        std::cout.flush();std::cerr.flush();
        std::cout.rdbuf(previous_output);std::cerr.rdbuf(previous_error);
    }
};
