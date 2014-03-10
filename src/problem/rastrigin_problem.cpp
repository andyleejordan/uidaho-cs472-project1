/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for rastrigin problem derived class
 */

#include <cmath>

#include "rastrigin_problem.hpp"
#include "problem.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"

using namespace problem;
using aliases::parameter;
using individual::Individual;

parameter Rastrigin::fitness(const Individual & subject) const {
  parameter sum = 0;
  for (const parameter & gene : subject)
    sum += std::pow(gene, 2) - 10 * std::cos(2 * M_PI * gene);
  return sum + 10 * subject.size();
}
