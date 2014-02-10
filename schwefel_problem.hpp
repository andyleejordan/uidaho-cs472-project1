/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base problem class
 */

#ifndef _SCHWEFEL_PROBLEM_H_
#define _SCHWEFEL_PROBLEM_H_

#include "problem.hpp"

class Schwefel: public Problem {
public:
  Schwefel(const int r = 102400,
	   const int s = 100,
	   const double n = 0,
	   const double x = 19000,
	   const bool z = true,
	   const double g = 0.75,
	   const double f = 0.60,
	   const double d = 10,
	   const long i = 10000000) : Problem(r, s, n, x, z, g, f, d, i) {};
  double problem(Individual subject) const;
};

#endif /* _SCHWEFEL_PROBLEM_H_ */
