/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for rosenbrock problem derived class
 */

#include <cmath>

#include "rosenbrock_problem.hpp"

parameter Rosenbrock::fitness(const Individual & subject) const {
  parameter sum = 0;
  for (unsigned long i = 0; i < subject.size() - 1; ++i)
    sum += 100 * std::pow(subject[i + 1] - std::pow(subject[i], 2), 2)
      + std::pow(subject[i] - 1, 2);
  return sum;
}
