#include <cassert>
#include <iostream>
#include <vector>
#include "../combat/OriginalConcerto.h"

int main() {
    constexpr int w=1280,h=720;
    std::vector<unsigned char> image(static_cast<size_t>(w*h*3));
    auto draw=[&](bool partial) {
        std::fill(image.begin(),image.end(),0);
        for(int y=645;y<691;++y) for(int x=475;x<521;++x) {
            const int dx=x-498,dy=y-668,d2=dx*dx+dy*dy;
            if(d2>14*14 && d2<=18*18 && (!partial || x>=498)) {
                auto* pixel=image.data()+(y*w+x)*3;
                pixel[0]=90;pixel[1]=115;pixel[2]=215; // original FIRE range
            }
        }
    };
    OriginalConcerto ring;
    ring.set_color_index(2);
    draw(false);
    const auto full=ring.measure(image.data(),w,h,3);
    assert(full.full && full.percent==1 && full.area>0);
    draw(true);
    const auto half=ring.measure(image.data(),w,h,3);
    assert(!half.full && half.percent<1);
    std::cout << "full_area=" << full.area << " half_area=" << half.area
              << " half_percent=" << half.percent << '\n';
}
