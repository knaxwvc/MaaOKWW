#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\YangYangSp.py
// Port source SHA256: 84ddab01e2dedb801c4d9e9d58f7bd1983a59049f8302517b22961489ea9f209
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\YangYangSp.py
class YangYangSpOriginal final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        double duration = state.has_intro ? 8.0 : 3.2;
        const double start = task.seconds();
        if (!task.mouse_down()) throw std::runtime_error("Maa YangYangSp heavy down failed");
        double resonance_since = -1;
        bool echo_used = false;
        try {
            while (time_elapsed_accounting_for_freeze(start) < duration && !task.stop_requested()) {
                if (liberation_available()) {
                    if (click_liberation(-1, false, 0)) duration += 2;
                } else if (resonance_available()) {
                    if (resonance_since < 0) resonance_since = task.seconds();
                    if (task.seconds()-resonance_since > 0.2)
                        click_resonance(0, false, false, 0, false, 1);
                } else if (!echo_used) {
                    resonance_since = -1;
                    echo_used = click_echo(0, 0, 0);
                } else resonance_since = -1;
                sleep(0.05);
            }
        } catch (...) { task.mouse_up(); sleep(0.1,false); throw; }
        if (!task.mouse_up()) throw std::runtime_error("Maa YangYangSp heavy up failed");
        sleep(0.1,false);
        switch_next_char();
    }
};
