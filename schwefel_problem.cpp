/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for schwefel problem derived class
 */

#include <cmath>

#include "schwefel_problem.hpp"

parameter Schwefel::problem(const Individual * subject) const {
  parameter sum = 0;
  for (auto value : * subject)
    sum += value * std::sin(std::sqrt(std::abs(value)));
  return 418.9829 * subject->size() + sum;
}
