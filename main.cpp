/* Copyright 2014 Andrew Schwartzmeyer
 *
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 *
 * Project #1a Hill Climbing and Simulated Annealing
 *
 * This program uses C++11 extensions (array template, range-based for
 * loop, random library)
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "spherical_problem.hpp"
#include "schwefel_problem.hpp"
#include "hill_climbing_algorithm.hpp"
#include "simulated_annealing_algorithm.hpp"
#include "genetic_algorithm.hpp"
#include "individual.hpp"

int main() {
  // seed random number generator
  std::srand(std::time(0));

  Problem * problem = new Schwefel;
  Genetic algorithm(problem);

  const Individual solution = algorithm.solve();
  std::cout << solution.represent() << "\n"
	    << problem->fitness(&solution) << "\n"
	    << problem->problem(&solution) << "\n";
}
