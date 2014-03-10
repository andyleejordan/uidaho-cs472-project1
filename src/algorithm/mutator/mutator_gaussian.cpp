/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for Gaussian mutator class
 */

#include "mutator.hpp"
#include "mutator_gaussian.hpp"
#include "../../individual/individual.hpp"
#include "../../aliases.hpp"
#include "../../random_generator.hpp"

using individual::Individual;
using aliases::parameter;
using namespace algorithm::mutator;
using namespace random_generator;

const Individual Gaussian::mutate(const Problem & problem, const Individual & subject) const {
  // GA mutation sequence using a normal distribution
  Individual mutant = subject; // non-const copy to mutate
  int_dist percent(0, 100);
  normal_dist delta_dist(mean, stddev); // unit Gaussian distribution for delta
  for (parameter & gene : mutant)
    // short circuit for problem.chance == 1
    if (problem.chance || percent(rg.engine) < int(100 * problem.chance))
      mutant.mutate(gene, gene * delta_dist(rg.engine));
  // update fitness
  mutant.fitness = problem.fitness(mutant);
  return mutant;
}
