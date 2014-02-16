/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived hill-climbing algorithm class
 */

#include <iostream>

#include "hill_climbing_algorithm.hpp"

const Individual HillClimbing::solve() const {
  while(true) {
    // random restart
    Individual best = problem.potential();
    if (best.fitness > problem.filter) {
      // work with "lucky" values
      for (long i = 0; i < problem.iterations; i++) {
	// actual hill-climbing algorithm
	Individual neighbor = mutate(best);
	// keep track of best best solution
	if (neighbor.fitness > best.fitness) {
	  best = neighbor;  // swap for better neighbor
	  // terminating condition
	  if (best.fitness > problem.goal) return best;
	}
      }
      std::cout << "Exhausted fitness: " << best.fitness << "\n";
    }
  }
}
