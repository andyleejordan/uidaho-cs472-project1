/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for arithmetic recombinator delegate class
 */


#include "recombinator.hpp"
#include "recombinator_arithmetic.hpp"
#include "../../random_generator.hpp"

using algorithm::recombinator::Arithmetic;
using algorithm::population;
using namespace random_generator;

const population Arithmetic::crossover(const population & mates, const Problem & problem) const {
  // arithmetic crossover
  population children = mates;
  int_dist percent(0, 100);
  real_dist alpha_dist(-0.1, 1.1);
  for (unsigned long i = 0; i < children[0].size(); ++i) {
    parameter alpha_1 = alpha_dist(rg.engine);
    parameter alpha_2 = alpha_dist(rg.engine);
    // recombine each child with crossover_chance probability
    if (chance || percent(rg.engine) < int(100 * chance))
      children[0].mutate(children[0][i], alpha_1 * mates[0][i] + (1 - alpha_1) * mates[1][i]);
    if (chance || percent(rg.engine) < int(100 * chance))
      children[1].mutate(children[1][i], (1 - alpha_2) * mates[0][i] + alpha_2 * mates[1][i]);
  }
  // update fitnesses
  for (Individual & child : children) child.fitness = problem.fitness(child);
  return children;
}
