#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Youhu.py
// Port source SHA256: 07e40ec38486ef92c5fad067a41398c04503997d4619145b2cf036a820f30785
#include "OriginalBaseChar.h"

class Youhu final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    // OK-WW only overrides __init__; BaseChar.do_perform is inherited.
};
