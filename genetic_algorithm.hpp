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
  const parameter crossover_chance = 0.8;
  static const int elitism = 2;
  typedef std::vector<Individual> population;
  // settings for Gaussian distribution
  static const int mean = 0;
  static const int stddev = 2;
  const Individual mutate(const Individual & subject) const;
  const Individual selection(const population & contestants) const;
  const population crossover(const population & mates) const;
public:
  Genetic(const Problem & p): Algorithm(p) {};
  const Individual solve() const;
};

#endif /* _GENETIC_ALGORITHM_H_ */
