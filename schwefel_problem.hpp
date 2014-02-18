/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for base problem class
 */

#ifndef _SCHWEFEL_PROBLEM_H_
#define _SCHWEFEL_PROBLEM_H_

#include "problem.hpp"

class Schwefel: public Problem {
public:
  Schwefel(const long i = 100000000,
	   const parameter g = 0.7,
	   const parameter f = 0.65,
	   const parameter d = 0.1,
	   const parameter h = 0.5,
	   const int c = 10000): Problem(-512.03, 511.97,
					 0, 21000, true,
					 i, g, f, d, h, c) {};
  parameter fitness(const Individual & subject) const;
};

#endif /* _SCHWEFEL_PROBLEM_H_ */
