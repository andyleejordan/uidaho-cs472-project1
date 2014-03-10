/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for uniform recombinator delegate class
 */

#include <algorithm>

#include "recombinator.hpp"
#include "recombinator_uniform.hpp"
#include "../../random_generator.hpp"

using algorithm::recombinator::Uniform;
using algorithm::population;
using namespace random_generator;

const population Uniform::crossover(const population & mates, const Problem & problem) const {
  // uniform crossover
  population children = mates;
  int_dist percent(0, 100);
  for (unsigned long i = 0; i < children[0].size(); ++i)
    if (percent(rg.engine) < int(100 * chance))
      std::swap(children[0][i], children[1][i]);
  // update fitnesses
  for (Individual & child : children) child.fitness = problem.fitness(child);
  return children;
}
