//
// Created by justnik on 12.09.2021.
//

#include "dsp.hpp"

using namespace std;

double sinc(double x) {
    if (x != 0) {
        return sin(x) / x;
    } else {
        return 1;
    }
}

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

std::vector<double> recovery(vector<double> &signal, double dt1, double t1, double t2, double dt) {
    auto count = signal.size();
    auto size = static_cast<size_t>((t2 - t1) / dt);
    vector<double> res(size);
    double t = t1;
    for (auto &&v: res) {
        double sum = 0;
        for (auto k = 0; k < count; ++k) {
            sum += signal[k] * sinc(M_PI * (t / dt1 - k));
        }
        v = sum;
        t += dt;
    }
    return res;
}