/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for simulated annealing derived algorithm class
 */

#include <cmath>
#include <iostream>
#include "simulated_annealing_algorithm.hpp"

bool SimulatedAnnealing::probability(double energy1,
				     double energy2,
				     double temperature) const {
  double chance = 100 * std::exp(-problem->constant*(energy1 - energy2)/temperature);
  return (rand() % 100) < chance;
}

Individual SimulatedAnnealing::solve() const {
  Individual potential;
  double fitness;
  do {
    // random restart
    potential = problem->potential();
    fitness = problem->fitness(potential);
    // std::cout << "Random restart, fitness is: " << fitness << std::endl;
    if (fitness > problem->filter) {
      // work with "lucky" values
      for (long T = problem->iterations; T > 0; T--) {
	// actual simulated-annealing algorithm
	double temperature = 100. * double(T)/problem->iterations;
	problem->delta = -problem->delta; // switch delta sign for convergence
	Individual neighbor = problem->mutate(potential);
	double neighbor_fitness = problem->fitness(neighbor);
	if (neighbor_fitness > fitness || probability(fitness,
						      neighbor_fitness,
						      temperature)) {
	  // keep track of best potential solution
	  potential = neighbor;
	  fitness = neighbor_fitness;
	  if (fitness > problem->goal) goto finished;
	}
      }
      std::cout << "Neighbors exhausted, fitness was: " << fitness << "\n";
    }
  } while (fitness < problem->goal);
 finished:
  return potential;
}
