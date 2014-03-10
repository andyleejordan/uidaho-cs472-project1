/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for Jumping mutator class
 */

#include "mutator.hpp"
#include "mutator_jumping.hpp"
#include "../../individual/individual.hpp"
#include "../../aliases.hpp"
#include "../../random_generator.hpp"

using individual::Individual;
using aliases::parameter;
using namespace algorithm::mutator;
using namespace random_generator;

const Individual Jumping::mutate(const Problem & problem, const Individual & subject) const {
  // jumping sequence like snewt's
  Individual mutant = subject; // non-const copy to mutate
  int_dist percent(0, 100);
  real_dist delta_dist(problem.domain_min, problem.domain_max);
  for (parameter & gene : mutant)
    if (percent(rg.engine) < int(100 * 1./mutant.size()))
      mutant.mutate(gene, delta_dist(rg.engine));
  // update fitness
  mutant.fitness = problem.fitness(mutant);
  return mutant;
}
