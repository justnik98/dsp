//
// Created by justnik on 12.09.2021.
//

#ifndef DSP_1_DSP_HPP
#define DSP_1_DSP_HPP

#include <cmath>
#include <functional>
#include <vector>

void write(std::vector<double> &x, std::vector<double> &val);

std::vector<double> sampling(double (*func)(double), double t1, double t2, double freq, double dt);

std::vector<double> recovery(std::vector<double> &signal, double dt1, double t1, double t2, double dt);

#endif //DSP_1_DSP_HPP
