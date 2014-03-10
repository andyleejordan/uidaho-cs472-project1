/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for derived hill-climbing algorithm class
 */

#ifndef _HILL_CLIMBING_ALGORITHM_H_
#define _HILL_CLIMBING_ALGORITHM_H_

#include "algorithm.hpp"
#include "../individual/individual.hpp"
#include "../problem/problem.hpp"

namespace algorithm {
  using individual::Individual;
  using problem::Problem;

  class HillClimbing: private Algorithm {
  public:
    HillClimbing(const Problem & p): Algorithm(p) {};
    const Individual solve() const;
  };
}

#endif /* _HILL_CLIMBING_ALGORITHM_H_ */
