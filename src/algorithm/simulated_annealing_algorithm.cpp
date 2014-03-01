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
  int_dist percent(0, 100);
  // mutation probability P(e1, e2, T) = e^(-c(e1 - e2)/T)
  const parameter chance = 100 * // [0, 1] -> [0, 100]
    std::exp(-problem.constant * (energy1 - energy2) / temperature);
  return percent(rg.engine) < chance;
}

const Individual SimulatedAnnealing::solve() const {
  while(true) {
    // random restart
    Individual best = problem.potential();
    // work with "lucky" values
    if (best > problem.filter) {
      // actual simulated-annealing algorithm
      for (long T = problem.iterations; T > 0; --T) {
	// convert temperature to [0, 100]
	const parameter temperature = 100. * parameter(T) / problem.iterations;
	// get neighbor
        const Individual neighbor = mutate(best);
	// keep track of best solution
	if (neighbor > best
	    // SA swaps in bad solutions with this probability
	    || probability(problem.normal(best), problem.normal(neighbor),
			   temperature)) {
	  best = neighbor;
	  // terminating condition
	  if (best > problem.goal) return best;
	}
      }
      std::cout << "Exhausted fitness: " << best.fitness << "\n";
    }
  }
}
