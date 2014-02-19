/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived genetic algorithm class
 */

#include <algorithm>
#include <iostream>

#include "genetic_algorithm.hpp"
#include "random_generator.hpp"

void Genetic::gaussian_mutate(Individual & mutant, int_dist & percent) const {
  // GA mutation sequence using a normal distribution
  normal_dist delta_dist(mean, stddev); // unit Gaussian distribution for delta
  for (parameter & gene : mutant)
    // short circuit for problem.chance == 1
    if (problem.chance || percent(rg.engine) < int(100 * problem.chance))
      mutant.mutate(gene, gene * delta_dist(rg.engine));
}

void Genetic::jumping_mutate(Individual & mutant, int_dist & percent) const {
  // jumping sequence like snewt's
  real_dist delta_dist(problem.domain_min, problem.domain_max);
  for (parameter & gene : mutant)
    if (percent(rg.engine) < int(100 * jumping_mutation_rate))
      mutant.mutate(gene, delta_dist(rg.engine));
}

const Individual Genetic::mutate(const Individual & subject) const {
  Individual mutant = subject; // non-const copy to mutate
  int_dist percent(0, 100);
  switch(mutation_type) {
  case 'g':
    gaussian_mutate(mutant, percent);
    break;
  case 'j':
    jumping_mutate(mutant, percent);
    break;
  }
  // update fitness
  mutant.fitness = problem.fitness(mutant);
  return mutant;
}

const Genetic::population Genetic::selection(const Genetic::population & generation) const {
  // implements tournament selection, returning desired number of best parents
  population parents;
  int_dist population_dist(0, population_size - 1); // closed interval, so (-1)
  for (int i = 0; i < crossover_size; ++i) {
    population contestants;
    // create tournament of random members drawn from generation
    for (int i = 0; i < tournament_size; ++i)
      contestants.emplace_back(generation[population_dist(rg.engine)]);
    // select best member from each tournament
    parents.emplace_back(*std::max_element(contestants.begin(), contestants.end()));
  }
  // return best Individual from a set of contestants
  return parents;
}

const Genetic::population Genetic::crossover(const Genetic::population & parents) const {
  population children = parents;
  int_dist percent(0, 100);
  // arithmetic binary crossover
  if (crossover_size == 2) {
    real_dist alpha_dist(-0.1, 1.1);
    for (unsigned long i = 0; i < parents[0].size(); ++i) {
      parameter alpha = alpha_dist(rg.engine);
      // recombine each child with crossover_chance probability
      if (crossover_chance || percent(rg.engine) < int(100 * crossover_chance))
	children[0][i] = alpha * parents[0][i] + (1 - alpha) * parents[1][i];
      if (crossover_chance || percent(rg.engine) < int(100 * crossover_chance))
	children[1][i] = (1 - alpha) * parents[0][i] + alpha * parents[1][i];
    }
  }
  else {
    // implement uniform crossover
  }
  // update fitnesses
  for (Individual & child : children) child.fitness = problem.fitness(child);
  return children;
}

const Individual Genetic::solve() const {
  while(true) {
    // create initial population
    population generation;
    for (int i = 0; i < population_size; ++i)
      generation.emplace_back(problem.potential());
    // generations loop
    for (long i = 0; i < problem.iterations; ++i) {
      // find generation's best member
      const Individual best = *std::max_element(generation.begin(), generation.end());
      // terminating condition
      if (best.fitness > problem.goal) return best;
      // std::cout << best.fitness << '\n';
      // selection and mutation stage
      population offspring;
      while(offspring.size() != population_size) {
	// tournament selection of parents
	const population parents = selection(generation);
	// crossover
	const population children = crossover(parents);
	// add mutated children to offspring
	for (const Individual child : children) offspring.emplace_back(mutate(child));
      }
      // replace generation with offspring
      generation.swap(offspring);
      // elitism replacement of random individuals
      int_dist population_dist(0, population_size - 1); // closed interval, so (-1)
      for (int i = 0; i < elitism; ++i)
	generation[population_dist(rg.engine)] = best;
    }
    std::cout << "Exhausted generations!\n";
  }
}
