/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base algorithm class
 */

#include <iostream>
#include "hill_climber_algorithm.hpp"

Individual HillClimber::solve() const {
  Individual potential;
  double fitness;
  do {
    // random restart
    potential = problem->potential();
    fitness = problem->fitness(potential);
    // std::cout << "Random restart, fitness is: " << fitness << std::endl;
    if (fitness > problem->filter) {
      // work with "lucky" values
      for (long i = 0; i < problem->iterations; i++) {
	// actual hill-climber algorithm
	problem->delta = -problem->delta; // switch delta sign for convergence
	Individual neighbor = problem->mutate(potential);
	double neighbor_fitness = problem->fitness(neighbor);
	if (neighbor_fitness > fitness) {
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
