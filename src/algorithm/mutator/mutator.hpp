/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for abstract mutator delegate class
 */

#ifndef _MUTATOR_H_
#define _MUTATOR_H_

#include "../../individual/individual.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace mutator {
    using individual::Individual;
    using problem::Problem;

    class Mutator {
    public:
      virtual const Individual mutate(const Problem & problem, const Individual & subject) const =0;
    };
  }
}

#endif /* _MUTATOR_H_ */
