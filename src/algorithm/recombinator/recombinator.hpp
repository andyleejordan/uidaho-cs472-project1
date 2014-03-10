/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for abstract recombinator / crossover delegate class
 */

#ifndef _RECOMBINATOR_H_
#define _RECOMBINATOR_H_

#include "../algorithm.hpp"
#include "../../aliases.hpp"

namespace algorithm {
  namespace recombinator {
    using aliases::parameter;

    class Recombinator {
    protected:
      const int size = 2; // binary crossover
      const parameter chance;
    public:
      Recombinator(const parameter & c = 0.8): chance(c) {}
      virtual const population crossover(const population & mates, const Problem & problem) const =0;
      int get_size() const {return size;}
      parameter get_chance() const {return chance;}
    };
  }
}

#endif /* _RECOMBINATOR_H_ */
