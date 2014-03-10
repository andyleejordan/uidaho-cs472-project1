/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived genetic algorithm class
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>

#include "algorithm.hpp"
#include "genetic_algorithm.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"
#include "../random_generator.hpp"

using algorithm::Genetic;
using algorithm::population;
using aliases::parameter;
using individual::Individual;
using namespace random_generator;

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

void Genetic::uniform_crossover(Genetic::population & children, int_dist & percent) const {
  // uniform crossover
  for (unsigned long i = 0; i < children[0].size(); ++i)
    if (percent(rg.engine) < int(100 * 0.5))
      std::swap(children[0][i], children[1][i]);
}

void Genetic::arithmetic_crossover(Genetic::population & children, int_dist & percent) const {
  // arithmetic crossover
  const population mates = children;
  real_dist alpha_dist(-0.1, 1.1);
  for (unsigned long i = 0; i < children[0].size(); ++i) {
    parameter alpha_1 = alpha_dist(rg.engine);
    parameter alpha_2 = alpha_dist(rg.engine);
    // recombine each child with crossover_chance probability
    if (crossover_chance || percent(rg.engine) < int(100 * crossover_chance))
      children[0][i] = alpha_1 * mates[0][i] + (1 - alpha_1) * mates[1][i];
    if (crossover_chance || percent(rg.engine) < int(100 * crossover_chance))
      children[1][i] = (1 - alpha_2) * mates[0][i] + alpha_2 * mates[1][i];
  }
}

void Genetic::two_point_crossover(Genetic::population & children, int_dist & percent) const {
    // two-point crossover
    if (crossover_chance || percent(rg.engine) < int(100 * crossover_chance)) {
      int_dist gene_dist(0, children[0].size() - 1);
      int start = gene_dist(rg.engine);
      int length = gene_dist(rg.engine);
      for (Individual & child : children)
	std::rotate(child.begin(), child.begin() + start, child.end());
      for (int i = 0; i < length; i++)
	std::swap(children[0][i], children[1][i]);
    }
}

const Genetic::population Genetic::crossover(const Genetic::population & mates) const {
  population children = mates;
  int_dist percent(0, 100);
  switch(crossover_type) {
  case 'u':
    uniform_crossover(children, percent);
    break;
  case 'a':
    arithmetic_crossover(children, percent);
    break;
  case 't':
    two_point_crossover(children, percent);
    break;
  }
  // update fitnesses
  for (Individual & child : children) child.fitness = problem.fitness(child);
  return children;
}

const Individual Genetic::solve() const {
  // setup basic logging
  std::ofstream log("logs/" + problem.name + ".dat");
  log << "# Solving the " << problem.represent()
      << "# Using a Genetic Algorithm"
      << " with population size " << population_size
      << ", tournament size " << tournament_size
      << ", crossover size " << crossover_size
      << ", crossover chance of " << crossover_chance
      << ", mutation chance of " << jumping_mutation_rate
      << ", and elitism replacement size " << elitism << "." << std::endl;
  while(true) {
    // create initial population
    population generation;
    Individual best;
    int_dist population_dist(0, population_size - 1); // closed interval, so (-1)
    for (int i = 0; i < population_size; ++i)
      generation.emplace_back(problem.potential());
    // generations loop
    for (long i = 0; i < problem.iterations; ++i) {
      // find generation's best member
      best = *std::max_element(generation.begin(), generation.end());
      parameter sum = std::accumulate(generation.begin(), generation.end(), 0.);
      // logging
      log << i << '\t' << best.fitness << '\t' << sum / population_size << '\n';
      // terminating condition
      if (best > problem.goal) return best;
      // selection and mutation stage
      population offspring;
      while(offspring.size() != population_size) {
	// tournament selection of parents
	const population parents = selection(generation);
	// crossover
	const population children = crossover(parents);
	// add mutated children to offspring
	for (const Individual child : children) offspring.emplace_back(mutator.mutate(problem, child));
      }
      // replace generation with offspring
      generation.swap(offspring);
      // elitism replacement of random individuals
      for (int i = 0; i < elitism; ++i)
	generation[population_dist(rg.engine)] = best;
    }
    log.close();
    return best;
  }
}
