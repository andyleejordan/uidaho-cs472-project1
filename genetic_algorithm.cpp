/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for derived genetic algorithm class
 */

#include <algorithm>
#include <iostream>
#include <iterator>

#include "genetic_algorithm.hpp"
#include "random_generator.hpp"

void Genetic::mutate(Individual & subject) const {
  // unit Gaussian distribution for delta
  normal_dist delta_dist(mean, stddev);
  for (parameter & value : subject) {
    parameter delta = delta_dist(rg.engine);
    subject.mutate(value, value * delta);
  }
}

const Individual Genetic::solve() const {
  // create initial population
  std::array<Individual, pop_size> population;
  population.fill(problem.potential());
  Individual best;

  for (long i = 0; i < problem.iterations; i++) {
    std::array<Individual, pop_size> mating_pool;
    mating_pool = population;

    // calculate fitnesses of individuals in population
    std::array<parameter, pop_size> weights;
    for (int i = 0; i < pop_size; i++)
      weights[i] = problem.fitness(population[i]);

    // need location of best fitness to get corresponding population member
    int max = std::distance(weights.begin(),
			    std::max_element(weights.begin(), weights.end()));
    best = population[max];
    if (weights[max] > problem.goal) goto finished;
    // std::cout << weights[max] << '\n';

    // setup roulette wheel selection
    std::discrete_distribution<> mate(weights.begin(), weights.end());

    // selection and mutation stage
    for (Individual & member : mating_pool) {
      // select
      member = population[mate(rg.engine)];
      // mutate (GA mutate function receives by reference)
      mutate(member);
    }
    population = mating_pool;
  }
 finished:
  return best;
}
