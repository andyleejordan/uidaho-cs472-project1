/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived hill-climbing algorithm class
 */

#include <iostream>

#include "hill_climbing_algorithm.hpp"
#include "algorithm.hpp"
#include "../individual/individual.hpp"

using algorithm::HillClimbing;
using individual::Individual;

const Individual HillClimbing::solve() const {
  while(true) {
    // random restart
    Individual best = problem.potential();
    // work with "lucky" values
    if (best > problem.filter) {
      // actual hill-climbing algorithm
      for (long i = 0; i < problem.iterations; ++i) {
	const Individual neighbor = mutate(best);
	// keep track of best solution
	if (neighbor > best) {
	  best = neighbor;
	  // terminating condition
	  if (best > problem.goal) return best;
	}
      }
      std::cout << "Exhausted fitness: " << best.fitness << "\n";
    }
  }
}
