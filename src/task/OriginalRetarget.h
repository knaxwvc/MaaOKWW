#pragma once
#include <functional>
#include <optional>

// CombatCheck.py at f9d808e: the extended timeout applies only to an
// established fight with a visible health/boss indicator.
struct OriginalRetargetSettings {double timeout=3;bool check_health=false;};
inline OriginalRetargetSettings original_retarget_settings(bool in_combat,bool has_health) {
    return {in_combat && has_health?30.0:3.0,in_combat && has_health};
}
enum class OriginalRetargetExit {found,timeout,health_lost,stopped};
struct OriginalRetargetResult {bool locked;double elapsed;OriginalRetargetExit reason;};
struct OriginalRetargetIO {
    std::function<double()> seconds;
    std::function<bool()> stopped,has_target;
    std::function<void()> middle_click,next_frame;
    std::function<bool()> check_health;
};
inline OriginalRetargetResult original_target_enemy(const OriginalRetargetIO& io,
                                                    double timeout,bool check_health) {
    if(io.has_target())return {true,0,OriginalRetargetExit::found};
    const double start=io.seconds();
    std::optional<double> health_lost_start;
    while(io.seconds()-start<timeout && !io.stopped()) {
        io.middle_click();
        if(io.has_target())return {true,io.seconds()-start,OriginalRetargetExit::found};
        io.next_frame();
        if(check_health) {
            if(!io.check_health()) {
                if(!health_lost_start)health_lost_start=io.seconds();
                else if(io.seconds()-*health_lost_start>1.2)
                    return {false,io.seconds()-start,OriginalRetargetExit::health_lost};
            }else health_lost_start.reset();
        }
    }
    return {false,io.seconds()-start,io.stopped()?OriginalRetargetExit::stopped:OriginalRetargetExit::timeout};
}
