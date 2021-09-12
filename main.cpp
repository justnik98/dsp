#include <iostream>
#include "src/dsp.hpp"

using namespace std;

int main() {

    double F = 10;
    double T = F / 10;
    double dt = T / 20000;
    double dt1 = 1.0 / (1.5 * F);
    double dt2 = 1.0 / (2 * F);
    double dt3 = 1.0 / (3 * F);
    double dt4 = 1.0 / (1000 * F);

    vector<double> time(static_cast<size_t>(T / dt));
    double t = 0;
    for (auto &&v: time) {
        v = t;
        t += dt;
    }
    auto u_a = sampling(sin, 0, T, F, dt); // имитация аналогового сигнала
    auto u_1_5 = sampling(sin, 0, T, F, dt1); // дискретизация с частотой 1.5F
    auto u_2 = sampling(sin, 0, T, F, dt2); // дискретизация с частотой 2F
    auto u_3 = sampling(sin, 0, T, F, dt3); // дискретизация с частотой 3F
    auto u_1000 = sampling(sin, 0, T, F, dt4); // дискретизация с частотой 1000F

    auto u_r1 = recovery(u_1_5, dt1, 0, T, dt);
    auto u_r2 = recovery(u_2, dt2, 0, T, dt);
    auto u_r3 = recovery(u_3, dt3, 0, T, dt);
    auto u_r4 = recovery(u_1000, dt4, 0, T, dt);

    write(time, u_a, "analog.dat");
    write(time, u_r1, "1_5F.dat");
    write(time, u_r2, "2F.dat");
    write(time, u_r3, "3F.dat");
    write(time, u_r4, "1000F.dat");
    return 0;
}
