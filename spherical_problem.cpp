/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base problem class
 */

#include <cmath>
#include "spherical_problem.hpp"

double Spherical::fitness(Individual subject) const {
  double sum = 0;
  for (auto value : subject) sum += std::pow(value, 2);
  return sum;
}
