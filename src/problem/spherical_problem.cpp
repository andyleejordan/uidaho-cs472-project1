/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for spherical problem derived class
 */

#include <cmath>

#include "spherical_problem.hpp"
#include "problem.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"

using namespace problem;
using aliases::parameter;
using individual::Individual;

parameter Spherical::fitness(const Individual & subject) const {
  parameter sum = 0;
  for (const parameter value : subject) sum += std::pow(value, 2);
  return sum;
}
