/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for abstract base algorithm class
 */

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "../individual/individual.hpp"
#include "../problem/problem.hpp"
#include "mutator/mutator.hpp"

namespace algorithm {
  using problem::Problem;
  using individual::Individual;
  using mutator::Mutator;
  typedef std::vector<Individual> population;

  class Algorithm {
  protected:
    const Problem & problem;
    const Mutator & mutator;
  public:
    Algorithm(const Problem & p, const Mutator & m);
    virtual const Individual solve() const =0;
  };
}

#endif /* _ALGORITHM_H_ */
