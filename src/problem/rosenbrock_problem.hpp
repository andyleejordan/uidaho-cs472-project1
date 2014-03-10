/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for rosenbrock problem derived class
 */

#ifndef _ROSENBROCK_PROBLEM_H_
#define _ROSENBROCK_PROBLEM_H_

#include "problem.hpp"
#include "../individual/individual.hpp"
#include "../aliases.hpp"

namespace problem {
  using aliases::parameter;
  using individual::Individual;

  class Rosenbrock: public Problem {
  public:
    Rosenbrock(const long i = 1000000000,
	       const parameter g = 0.999,
	       const parameter f = 0.85,
	       const parameter d = 0.1,
	       const parameter h = 0.5,
	       const int c = 10000): Problem("Rosenbrock",
					     -2.048, 2.048, 0, 46000, true,
					     i, g, f, d, h, c) {};
    parameter fitness(const Individual & subject) const;
  };
}

#endif /* _ROSENBROCK_PROBLEM_H_ */
