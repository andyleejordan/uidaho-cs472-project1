/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for Gaussian mutator delegate class
 */

#ifndef _MUTATOR_GAUSSIAN_H_
#define _MUTATOR_GAUSSIAN_H_

#include "mutator.hpp"
#include "../../individual/individual.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace mutator {
    using individual::Individual;
    using problem::Problem;

    class Gaussian: public Mutator {
    private:
      // settings for Gaussian distribution
      static const int mean = 0;
      static const int stddev = 2;
    public:
      const Individual mutate(const Problem & problem, const Individual & subject) const;
    };
  }
}

#endif /* _MUTATOR_GAUSSIAN_H_ */
