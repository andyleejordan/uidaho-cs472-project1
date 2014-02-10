/* Copyright 2014 Andrew Schwartzmeyer
 *
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 *
 * Project #1a Hill Climbing and Simulated Annealing
 *
 * This program uses C++11 extensions (array template, auto specifier,
 * range-based for loop)
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "spherical_problem.hpp"
#include "hill_climber_algorithm.hpp"
#include "individual.hpp"

int main(int argc, char *argv[]) {
  // seed random number generator
  std::srand(std::time(0));

  Spherical * spherical_problem = new Spherical;
  HillClimber hill_climber_algorithm(spherical_problem);
  Individual solution = hill_climber_algorithm.solve();
  std::cout << solution.represent() << "\n"
	    << spherical_problem->fitness(solution) << "\n"
	    << spherical_problem->problem(solution) << "\n";

  return 0;
}
