/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for schwefel problem derived class
 */

#include <cmath>

#include "schwefel_problem.hpp"
#include "problem.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"

using namespace problem;
using aliases::parameter;
using individual::Individual;

parameter Schwefel::fitness(const Individual & subject) const {
  parameter sum = 0;
  for (const parameter & gene : subject)
    sum += gene * std::sin(std::sqrt(std::abs(gene)));
  return 418.9829 * subject.size() + sum;
}
