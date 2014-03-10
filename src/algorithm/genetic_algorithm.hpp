/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for derived genetic algorithm class
 */

#ifndef _GENETIC_ALGORITHM_H_
#define _GENETIC_ALGORITHM_H_

#include <memory>

#include "algorithm.hpp"
#include "recombinator/recombinator.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"
#include "../problem/problem.hpp"
#include "../random_generator.hpp"

namespace algorithm {
  using aliases::parameter;
  using individual::Individual;
  using problem::Problem;
  using random_generator::int_dist;
  using recombinator::Recombinator;

  class Genetic: private Algorithm {
  private:
    const int population_size = 512;
    const int tournament_size = 4;
    const int elitism = 2;
    const population selection(const population & generation) const;
    std::shared_ptr<const Recombinator> recombinator;
  public:
    Genetic(const Problem & p, const Mutator & m, std::shared_ptr<const Recombinator> r): Algorithm(p, m), recombinator(r) {};
    const Individual solve() const;
  };
}

#endif /* _GENETIC_ALGORITHM_H_ */
