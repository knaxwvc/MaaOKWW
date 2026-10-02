#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Verina.py
// Port source SHA256: 8ad0ec9d4f2ec38907f6ac2672a3bae268cab9db46399569c03ff0c46e96dcd9
#include "OriginalBaseChar.h"

class Verina final : public OriginalBaseChar {
    static constexpr double normal_attack_time = 0.6;
    static constexpr double jump_attack_time = 0.5;
    static constexpr double heavy_attack_time = 0.7;
    static constexpr double recover_time = 0.8;
    static constexpr double field_time = 6.5;
    static constexpr double heavy_attack_interval = 8.0;
    double start = -1;
    double last_heavy = -1;
    bool should_stop() {
        return is_con_full() || time_elapsed_accounting_for_freeze(start) >= field_time;
    }
    void perform_combat() {
        start = task.seconds();
        continues_normal_attack(normal_attack_time);
        if (should_stop()) return;
        if (liberation_available()) click_liberation();
        if (should_stop()) return;
        if (resonance_available()) click_resonance(0, false, true, 0, false, 0);
        if (should_stop()) return;
        if (echo_available()) click_echo(0, 0, 0);
        if (should_stop()) return;
        wait_until([&](){return task.active_slot()>0;},2.0);
        sleep(recover_time);
        if (is_mouse_forte_full() &&
            time_elapsed_accounting_for_freeze(last_heavy) >= heavy_attack_interval) {
            heavy_attack(heavy_attack_time);
            last_heavy = task.seconds();
        }
        if (!task.send_key(VK_SPACE)) throw std::runtime_error("Maa Verina jump failed");
        sleep(0.01);
        continues_normal_attack(jump_attack_time);
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && from=="Hiyuki")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override { perform_combat(); switch_next_char(); }
};
