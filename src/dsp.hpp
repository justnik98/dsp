//
// Created by justnik on 12.09.2021.
//

#ifndef DSP_1_DSP_HPP
#define DSP_1_DSP_HPP

#include <cmath>
#include <functional>
#include <vector>

std::vector<double> sampling(double (*func)(double), double t1, double t2, double freq, double dt);


#endif //DSP_1_DSP_HPP
