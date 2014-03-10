/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for uniform recombinator delegate class
 */

#ifndef _RECOMBINATOR_UNIFORM_H_
#define _RECOMBINATOR_UNIFORM_H_

#include "recombinator.hpp"
#include "recombinator_uniform.hpp"
#include "../../problem/problem.hpp"
#include "../../aliases.hpp"

namespace algorithm {
  namespace recombinator {
    using aliases::parameter;

    class Uniform: public Recombinator {
    public:
      Uniform(const parameter & c = 0.5): Recombinator(c) {}
      const population crossover(const population & mates, const Problem & problem) const;
    };
  }
}

#endif /* _RECOMBINATOR_UNIFORM_H_ */
