//
// Created by justnik on 12.09.2021.
//

#include "dsp.hpp"

using namespace std;

std::vector<double> sampling(double (*func)(double), double t1, double t2, double freq, double dt) {
    auto size = static_cast<size_t>((t2 - t1) / dt);
    vector<double> res(size);
    double t = t1;
    for (auto &&v: res) {
        v = func(2.0 * M_PI * freq * t);
        t += dt;
    }
    return res;
}
