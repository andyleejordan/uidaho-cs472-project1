/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for abstract base algorithm class
 */

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "../individual/individual.hpp"
#include "../problem/problem.hpp"

namespace algorithm {
  using problem::Problem;
  using individual::Individual;

  class Algorithm {
  protected:
    const Problem & problem;
    const virtual Individual mutate(const Individual & subject) const;
  public:
    Algorithm(const Problem & p);
    const virtual Individual solve() const =0;
  };
}

#endif /* _ALGORITHM_H_ */
