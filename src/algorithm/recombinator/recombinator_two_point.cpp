/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for two-point recombinator delegate class
 */

#include <algorithm>

#include "recombinator.hpp"
#include "recombinator_two_point.hpp"
#include "../../random_generator.hpp"

using algorithm::recombinator::TwoPoint;
using algorithm::population;
using namespace random_generator;

const population TwoPoint::crossover(const population & mates, const Problem & problem) const {
  // two-point crossover
  population children = mates;
  int_dist percent(0, 100);
  if (chance || percent(rg.engine) < int(100 * chance)) {
    int_dist gene_dist(0, children[0].size() - 1);
    int start = gene_dist(rg.engine);
    int length = gene_dist(rg.engine);
    for (Individual & child : children)
      std::rotate(child.begin(), child.begin() + start, child.end());
    for (int i = 0; i < length; i++)
      std::swap(children[0][i], children[1][i]);
  }
  // update fitnesses
  for (Individual & child : children) child.fitness = problem.fitness(child);
  return children;
}
