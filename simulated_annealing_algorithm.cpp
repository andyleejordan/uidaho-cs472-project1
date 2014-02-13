/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for simulated annealing derived algorithm class
 */

#include <cmath>
#include <iostream>

#include "simulated_annealing_algorithm.hpp"

bool SimulatedAnnealing::probability(const double energy1,
				     const double energy2,
				     const double temperature) const {
  double chance = 100 * std::exp(-problem->constant*(energy1 - energy2)/temperature);
  return (rand() % 100) < chance;
}

const Individual * SimulatedAnnealing::solve() const {
  Individual * potential;
  Individual * neighbor;
  double fitness;
  do {
    // random restart
    potential = problem->potential();
    neighbor = potential;
    fitness = problem->fitness(potential);
    if (fitness > problem->filter) {
      // work with "lucky" values
      std::cout << "Lucky restart, with: " << potential->represent()
		<< " and fitness: " << fitness << std::endl;
      for (long T = problem->iterations; T > 0; T--) {
	// actual simulated-annealing algorithm
	const double temperature = 100. * double(T)/problem->iterations;
	std::array <double, dimension> mutation =
	  problem->mutate(potential);
	neighbor->solution = mutation;
	const double neighbor_fitness = problem->fitness(neighbor);
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
