/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for Jumping mutator delegate class
 */

#ifndef _MUTATOR_JUMPING_H_
#define _MUTATOR_JUMPING_H_

#include "mutator.hpp"
#include "../../individual/individual.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace mutator {
    using individual::Individual;
    using problem::Problem;

    class Jumping: public Mutator {
    public:
      const Individual mutate(const Problem & problem, const Individual & subject) const;
    };
  }
}

#endif /* _MUTATOR_JUMPING_H_ */
