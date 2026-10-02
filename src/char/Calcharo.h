#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Calcharo.py
// Port source SHA256: e987a65c3923a719a0cda3625b86ddbba987e54a73b34a7d6225134960270198
#include "OriginalBaseChar.h"

class Calcharo final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) {
            sleep(1);
            wait_until([&](){return task.active_slot()>0;},3);
            check_combat();
        }
        OriginalBaseChar::do_perform();
    }
};
