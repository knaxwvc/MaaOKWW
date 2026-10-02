#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Qingxiao.py
// Port source SHA256: 51cfc8e55b0d3b753feb1294fc6c17eb79d986ca02ebc8b06d7af0edabd0f268
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Qingxiao.py
class QingxiaoOriginal final : public OriginalBaseChar {
    static constexpr double heavy_timeout = 2;
    static constexpr double heavy_confirm = 0.25;
    bool must_cast_lib_this_turn = false;
    int heavy_available() {
        if (find_feature("qingxiao_h1", 0.7)) return 1;
        if (find_feature("qingxiao_h2", 0.7)) return 2;
        return 0;
    }
    int handle_heavy() {
        const int heavy = heavy_available();
        if (!heavy) return 0;
        const double start = task.seconds();
        bool confirmed = false;
        if (!task.mouse_down()) throw std::runtime_error("Maa Qingxiao heavy down failed");
        try {
            while (time_elapsed_accounting_for_freeze(start) < heavy_timeout && !task.stop_requested()) {
                if (heavy_available()) {
                    task.next_frame();
                } else {
                    sleep(heavy_confirm);task.next_frame();
                    if (!heavy_available()) { confirmed = true; break; }
                }
            }
        } catch (...) { task.mouse_up(); throw; }
        if (!task.mouse_up()) throw std::runtime_error("Maa Qingxiao heavy up failed");
        sleep(0.01);
        return confirmed ? heavy : 0;
    }
    bool cast_enhanced_resonance() {
        if (!find_feature("qingxiao_e", 0.7)) return false;
        return click_resonance(0, true, true, 0.5, false, 1.5).clicked;
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        must_cast_lib_this_turn = has_all_buff() && state.has_intro;
        if (!must_cast_lib_this_turn) {
            cast_enhanced_resonance();
            return switch_next_char();
        }
        const double start = task.seconds();
        bool broke_on_h2 = false;
        while (time_elapsed_accounting_for_freeze(start) < 18 && !task.stop_requested()) {
            cycle_start();
            if (const int heavy = handle_heavy()) {
                f_break();
                if (heavy == 2) {
                    if (!liberation_available())
                        wait_until([&]() { return liberation_available(); }, 1.5);
                    click_liberation();
                    broke_on_h2 = true;
                    break;
                }
            } else if (cast_enhanced_resonance()) {
            } else {
                task.click();
            }
            cycle_sleep();
        }
        if (!broke_on_h2) handle_heavy();
        if (broke_on_h2) wait_until([&]() { return task.active_slot() > 0; }, 1.0);
        switch_next_char();
    }
};
