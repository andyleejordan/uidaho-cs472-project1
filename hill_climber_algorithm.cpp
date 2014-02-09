/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base algorithm class
 */

#include "individual.hpp"
#include "problem.hpp"
#include "hill_climber_algorithm.hpp"

Individual HillClimber::solve() {
  Individual potential;
  double fitness;
  do {
    // random restart
    potential = problem.potential();
    fitness = problem.fitness(potential);
    double delta = problem.delta;
    if (fitness < problem.filter) {
      // work with "lucky" values
      for (int i = 0; i < problem.iterations; i++) {
	// actual hill-climber algorithm
	delta = -delta; // switch delta sign for convergence from either side
	Individual neighbor = problem.mutate(potential);
	double neighbor_fitness = problem.fitness(neighbor);
	if (neighbor_fitness < fitness) {
	  // keep track of best potential solution
	  potential = neighbor;
	  fitness = neighbor_fitness;
	}
      }
    }
  } while (fitness < problem.goal);
  return potential;
}
