/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived genetic algorithm class
 */

#include <algorithm>
#include <iostream>
#include <iterator>

#include "genetic_algorithm.hpp"
#include "random_generator.hpp"

const Individual Genetic::mutate(const Individual & subject) const {
  // unit Gaussian distribution for delta
  Individual mutation = subject;
  normal_dist delta_dist(mean, stddev);
  for (parameter & gene : mutation)
    mutation.mutate(gene, gene * delta_dist(rg.engine));
  mutation.fitness = problem.fitness(mutation);
  return mutation;
}

const Individual Genetic::selection(const Genetic::population & contestants) const {
  // return best Individual from a set of contestants
  return *std::max_element(contestants.begin(), contestants.end());
}

const Genetic::population Genetic::crossover(const Genetic::population & mates) const {
  // return two offspring for two mates
  return mates;
}

const Individual Genetic::solve() const {
  while(true) {
    // create initial population
    population generation;
    for (int i = 0; i < population_size; ++i)
      generation.emplace_back(problem.potential());
    // generations loop
    for (long i = 0; i < problem.iterations; ++i) {
      // find generation's best member (general form of selection)
      const Individual best = selection(generation);
      // terminating condition
      if (best.fitness > problem.goal) return best;
      // std::cout << best.fitness << '\n';
      // selection and mutation stage
      population offspring;
      while(offspring.size() != population_size) {
	// tournament selection of parents
	population parents;
	for (int i = 0; i < crossover_size; ++i) {
	  population contestants;
	  int_dist population_dist(0, population_size-1); // closed interval
	  // create tournament of random members drawn from generation
	  for (int i = 0; i < tournament_size; ++i)
	    contestants.emplace_back(generation[population_dist(rg.engine)]);
	  // select best member from each tournament
	  parents.emplace_back(selection(contestants));
	}
	// crossover
	population children = crossover(parents);
	// add mutated children to offspring
	for (const Individual child : children) offspring.emplace_back(mutate(child));
      }
      // replace generation with offspring
      generation.swap(offspring);
    }
    std::cout << "Exhausted generations!\n";
  }
}
