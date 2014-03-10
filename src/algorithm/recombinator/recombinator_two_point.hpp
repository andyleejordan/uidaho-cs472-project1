/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for two-point recombinator delegate class
 */

#ifndef _RECOMBINATOR_TWO_POINT_H_
#define _RECOMBINATOR_TWO_POINT_H_

#include "recombinator.hpp"
#include "recombinator_two_point.hpp"
#include "../../problem/problem.hpp"

namespace algorithm {
  namespace recombinator {
    class TwoPoint: public Recombinator {
    public:
      TwoPoint(const parameter & c = 0.8): Recombinator(c) {}
      const population crossover(const population & mates, const Problem & problem) const;
    };
  }
}

#endif /* _RECOMBINATOR_TWO_POINT_H_ */
