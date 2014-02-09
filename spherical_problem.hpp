/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base problem class
 */

#ifndef _SPHERICAL_PROBLEM_H_
#define _SPHERICAL_PROBLEM_H_

#include "problem.hpp"

class Spherical: public Problem {
public:
  Spherical(const int r = 12,
	    const int s = 100,
	    const int g = 10,
	    const int f = 100,
	    const int i = 100000000,
	    const double d = 0.1) : Problem(r, s, g, f, i, d) {};
  double fitness(Individual subject) const;
};

#endif /* _SPHERICAL_PROBLEM_H_ */
