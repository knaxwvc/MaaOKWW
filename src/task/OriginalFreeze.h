#pragma once
#include <algorithm>
#include <vector>

// BaseCombatTask.add_freeze_duration/time_elapsed_accounting_for_freeze.
class OriginalFreezeClock {
    struct Freeze { double start, duration, minimum; };
    std::vector<Freeze> freezes;
public:
    void add(double start, double duration, double minimum, double now) {
        if (duration < 0) duration = now - start;
        if (start <= 0 || duration <= minimum) return;
        freezes.erase(std::remove_if(freezes.begin(), freezes.end(), [&](const Freeze& item) {
            return item.start <= now - 60;
        }), freezes.end());
        freezes.push_back({start, duration, minimum});
    }
    double elapsed(double start, bool intro_motion_freeze, double now) const {
        if (start < 0) return 10000;
        double subtract = 0;
        for (const auto& freeze : freezes) {
            if (start >= freeze.start) continue;
            double minimum = freeze.minimum;
            if (minimum == -100) {
                if (!intro_motion_freeze) continue;
                minimum = 0;
            }
            subtract += freeze.duration - minimum;
        }
        return now - start - subtract;
    }
};
