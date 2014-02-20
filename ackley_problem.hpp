/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for base problem class
 */

#ifndef _ACKLEY_PROBLEM_H_
#define _ACKLEY_PROBLEM_H_

#include "problem.hpp"

class Ackley: public Problem {
public:
  Ackley(const long i = 100000000,
	 const parameter g = 0.99,
	 const parameter f = 0.65,
	 const parameter d = 0.1,
	 const parameter h = 0.5,
	 const int c = 10000): Problem("Ackley",
				       -30, 30, 0, 22, true,
				       i, g, f, d, h, c) {}
  parameter problem(const Individual & subject) const;
};

#endif /* _ACKLEY_PROBLEM_H_ */
