#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
#include "MaaFramework/MaaAPI.h"
#ifndef MAAOKWW_API_HELPER_DEFINED
#define MAAOKWW_API_HELPER_DEFINED
template<class F> inline F api(HMODULE module,const char* name) {
    auto address=GetProcAddress(module,name);
    if(!address)throw std::runtime_error(std::string("Missing Maa API: ")+name);
    return reinterpret_cast<F>(address);
}
#endif
