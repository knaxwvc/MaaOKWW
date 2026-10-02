#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Chixia.py
// Port source SHA256: ffe0b8d1e20a15203331da47e6a77b5b2c46248a7bd32cbb4d5b546ddf60a847
#include "OriginalBaseChar.h"

class Chixia final : public OriginalBaseChar {
    int bullets = 0;
public:
    using OriginalBaseChar::OriginalBaseChar;
    // OK-WW only overrides __init__; its commented do_perform is not active.
};
