#include <iostream>
#include "src/dsp.hpp"

using namespace std;

int main() {

    double F = 10;
    double T = F / 10;
    double dt = T / 10000;

    auto u_a = sampling(sin, 0, T, F, dt); // имитация аналогового сигнала
    auto u_1_5 = sampling(sin, 0, T, F, 1.0 / (1.5 * F)); // дискретизация с частотой 1.5F
    auto u_2 = sampling(sin, 0, T, F, 1.0 / (2 * F)); // дискретизация с частотой 2F
    auto u_3 = sampling(sin, 0, T, F, 1.0 / (3 * F)); // дискретизация с частотой 3F
    auto u_1000 = sampling(sin, 0, T, F, 1.0 / (1000 * F)); // дискретизация с частотой 1000F



    return 0;
}
