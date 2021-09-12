#include <iostream>
#include "src/dsp.hpp"

using namespace std;

int main() {

    double F = 10;
    double T = F / 10;
    double dt = T / 100000;
    double dt1 = 1.0 / (1.5 * F);
    double dt2 = 1.0 / (2 * F);
    double dt3 = 1.0 / (3 * F);
    double dt4 = 1.0 / (1000 * F);

    auto u_a = sampling(sin, 0, T, F, dt); // имитация аналогового сигнала
    auto u_1_5 = sampling(sin, 0, T, F, dt1); // дискретизация с частотой 1.5F
    auto u_2 = sampling(sin, 0, T, F, dt2); // дискретизация с частотой 2F
    auto u_3 = sampling(sin, 0, T, F, dt3); // дискретизация с частотой 3F
    auto u_1000 = sampling(sin, 0, T, F, dt4); // дискретизация с частотой 1000F

    auto u_r = recovery(u_1000, dt4, 0, T, dt);

    return 0;
}
