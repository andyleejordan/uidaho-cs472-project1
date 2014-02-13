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
  parameter chance = 100 * std::exp(-problem->constant*(energy1 - energy2)/temperature);
  return (rand() % 100) < chance;
}

const Individual SimulatedAnnealing::solve() const {
  Individual potential;
  Individual neighbor;
  parameter fitness;
  do {
    // random restart
    potential = problem->potential();
    neighbor = potential;
    fitness = problem->fitness(&potential);
    if (fitness > problem->filter) {
      // work with "lucky" values
      std::cout << "Lucky restart, with: " << potential->represent()
		<< " and fitness: " << fitness << std::endl;
      for (long T = problem->iterations; T > 0; T--) {
	// actual simulated-annealing algorithm
	const parameter temperature = 100. * parameter(T)/problem->iterations;
	std::array <parameter, dimension> mutation = mutate(&potential);
	neighbor.solution = mutation;
	const parameter neighbor_fitness = problem->fitness(&neighbor);
	if (neighbor_fitness > fitness || probability(fitness,
						      neighbor_fitness,
						      temperature)) {
	  // keep track of best potential solution
	  potential = neighbor;
	  fitness = neighbor_fitness;
	  // one of the few legitimate modern uses of goto!
	  if (fitness > problem->goal) goto finished;
	}
      }
      std::cout << "Neighbors exhausted, fitness was: " << fitness << "\n";
    }
  } while (fitness < problem->goal);
 finished:
  return potential;
}
