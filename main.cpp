/* Copyright 2014 Andrew Schwartzmeyer
 *
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 *
 * Project #1 Genetic Algorithm
 *
 * This program uses C++11 extensions (array template, range-based for
 * loop, random library)
 */

#include <cstdlib>
#include <iostream>

// individual
#include "individual.hpp"

// algorithms
#include "genetic_algorithm.hpp"
#include "hill_climbing_algorithm.hpp"
#include "simulated_annealing_algorithm.hpp"

// problems
#include "ackley_problem.hpp"
#include "griewangk_problem.hpp"
#include "rastrigin_problem.hpp"
#include "rosenbrock_problem.hpp"
#include "schwefel_problem.hpp"
#include "spherical_problem.hpp"

int main() {
  Spherical problem;
  Genetic algorithm(problem);

  const Individual solution = algorithm.solve();
  std::cout << solution.represent() << '\n'
	    << problem.fitness(solution) << '\n'
	    << problem.problem(solution) << '\n';
}
