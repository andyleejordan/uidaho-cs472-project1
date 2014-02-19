/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for derived genetic algorithm class
 */

#ifndef _GENETIC_ALGORITHM_H_
#define _GENETIC_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class Genetic: private Algorithm {
private:
  static const int population_size = 256;
  static const int tournament_size = 4;
  static const int crossover_size = 2; // binary crossover
  static const int elitism = 8;
  const parameter crossover_chance = 0.8;
  const parameter jumping_mutation_rate = 0.05;
  char mutation_type = 'j';
  char crossover_type = 't';
  typedef std::vector<Individual> population;
  // settings for Gaussian distribution
  static const int mean = 0;
  static const int stddev = 2;
  void gaussian_mutate(Individual & mutant, int_dist & percent) const;
  void jumping_mutate(Individual & mutant, int_dist & percent) const;
  const Individual mutate(const Individual & subject) const;
  const population selection(const population & generation) const;
  void uniform_crossover(population & children, int_dist & percent) const;
  void arithmetic_crossover(const Genetic::population & mates,
			    Genetic::population & children,
			    int_dist & percent) const;
  void two_point_crossover(population & children, int_dist & percent) const;
  const population crossover(const population & mates) const;
public:
  Genetic(const Problem & p): Algorithm(p) {};
  const Individual solve() const;
};

#endif /* _GENETIC_ALGORITHM_H_ */
