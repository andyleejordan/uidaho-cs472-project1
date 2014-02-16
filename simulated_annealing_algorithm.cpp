/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for simulated annealing derived algorithm class
 */

#include <cmath>
#include <iostream>

#include "simulated_annealing_algorithm.hpp"

bool SimulatedAnnealing::probability(const parameter energy1,
				     const parameter energy2,
				     const parameter temperature) const {
  int_dist percent(1, 100);
  parameter chance = 100 *
    std::exp(-problem.constant * (energy1 - energy2) / temperature);
  return percent(rg.engine) < chance;
}

const Individual SimulatedAnnealing::solve() const {
  while(true) {
    // random restart
    Individual best = problem.potential();
    if (best.fitness > problem.filter) {
      // work with "lucky" values
      for (long T = problem.iterations; T > 0; T--) {
	// actual simulated-annealing algorithm
	parameter temperature = 100. * parameter(T)/problem.iterations;
        Individual neighbor = mutate(best);
	// keep track of best best solution
	if (neighbor.fitness > best.fitness ||
	    probability(best.fitness, neighbor.fitness, temperature)) {
	  best = neighbor; // swap for better neighbor
	  // terminating condition
	  if (best.fitness > problem.goal) return best;
	}
      }
      std::cout << "Exhausted fitness: " << best.fitness << "\n";
    }
  }
}
