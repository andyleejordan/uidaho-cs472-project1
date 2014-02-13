/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for spherical problem derived class
 */

#include <cmath>

#include "spherical_problem.hpp"

parameter Spherical::problem(const Individual * subject) const {
  parameter sum = 0;
  for (const auto value : *subject) sum += std::pow(value, 2);
  return sum;
}
