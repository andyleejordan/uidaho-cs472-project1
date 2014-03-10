/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for arithmetic recombinator delegate class
 */

#ifndef _RECOMBINATOR_ARITHMETIC_H_
#define _RECOMBINATOR_ARITHMETIC_H_

#include "recombinator.hpp"
#include "recombinator_arithmetic.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace recombinator {
    using aliases::parameter;

    class Arithmetic: public Recombinator {
    public:
      Arithmetic(const parameter & c = 0.8): Recombinator(c) {}
      const population crossover(const population & mates, const Problem & problem) const;
    };
  }
}

#endif /* _RECOMBINATOR_ARITHMETIC_H_ */
