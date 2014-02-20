/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for ackley problem derived class
 */

#include <cmath>

#include "ackley_problem.hpp"

parameter Ackley::fitness(const Individual & subject) const {
  parameter p_inverse = 1. / subject.size();
  parameter sum_pow = 0;
  parameter sum_cos = 0;
  for (const parameter & gene : subject) {
    sum_pow += std::pow(gene, 2);
    sum_cos += std::cos(2 * M_PI * gene);
  }
  parameter exp_0 = std::exp(-0.2 * std::sqrt(p_inverse * sum_pow));
  parameter exp_1 = std::exp(p_inverse * sum_cos);
  return 20 + M_E - 20 * exp_0 - exp_1;
}
