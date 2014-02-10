/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for spherical problem derived class
 */

#include <cmath>
#include "spherical_problem.hpp"

double Spherical::problem(Individual subject) const {
  double sum = 0;
  for (auto value : subject) sum += std::pow(value, 2);
  return sum;
}
