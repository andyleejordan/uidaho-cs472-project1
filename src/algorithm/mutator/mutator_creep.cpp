/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for Creep mutator class
 */

#include "mutator.hpp"
#include "mutator_creep.hpp"
#include "../../individual/individual.hpp"
#include "../../aliases.hpp"
#include "../../random_generator.hpp"

using individual::Individual;
using aliases::parameter;
using namespace algorithm::mutator;
using namespace random_generator;

const Individual Creep::mutate(const Problem & problem, const Individual & subject) const {
  // basic mutation by delta distribution and chance
  Individual mutant = subject; // non-const copy to mutate
  int_dist percent(0, 100);
  // distribution of real delta values, scaled for problem domain
  real_dist delta_dist(-problem.delta * (std::abs(problem.domain_min) +
					 std::abs(problem.domain_max)) / 2,
		       problem.delta * (std::abs(problem.domain_min) +
					std::abs(problem.domain_max)) / 2);
  for (parameter & gene : mutant)
    // short circuit for problem.chance == 1
    if (problem.chance || percent(rg.engine) < int(100 * problem.chance))
      mutant.mutate(gene, gene + delta_dist(rg.engine));
  // update fitness
  mutant.fitness = problem.fitness(mutant);
  return mutant;
}
