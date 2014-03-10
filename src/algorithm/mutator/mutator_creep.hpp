/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for Creep mutator delegate class
 */

#ifndef _MUTATOR_CREEP_H_
#define _MUTATOR_CREEP_H_

#include "mutator.hpp"
#include "../../individual/individual.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace mutator {
    using individual::Individual;
    using problem::Problem;

    class Creep: public Mutator {
    public:
      const Individual mutate(const Problem & problem, const Individual & subject) const;
    };
  }
}

#endif /* _MUTATOR_CREEP_H_ */
