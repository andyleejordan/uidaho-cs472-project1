/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for derived genetic algorithm class
 */

#ifndef _GENETIC_ALGORITHM_H_
#define _GENETIC_ALGORITHM_H_

#include "algorithm.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"
#include "../problem/problem.hpp"
#include "../random_generator.hpp"

namespace algorithm {
  using aliases::parameter;
  using individual::Individual;
  using problem::Problem;
  using random_generator::int_dist;

  class Genetic: private Algorithm {
  private:
    static const int population_size = 512;
    static const int tournament_size = 4;
    static const int crossover_size = 2; // binary crossover
    static const int elitism = 2;
    const parameter crossover_chance = 0.8;
    const population selection(const population & generation) const;
    void uniform_crossover(population & children, int_dist & percent) const;
    void arithmetic_crossover(population & children, int_dist & percent) const;
    void two_point_crossover(population & children, int_dist & percent) const;
    const population crossover(const population & mates) const;
  public:
    Genetic(const Problem & p, const Mutator & m, std::shared_ptr<const Recombinator> r): Algorithm(p, m), recombinator(r) {};
    const Individual solve() const;
  };
}

#endif /* _GENETIC_ALGORITHM_H_ */
