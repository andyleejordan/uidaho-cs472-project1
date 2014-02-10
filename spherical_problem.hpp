/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for spherical problem derived class
 */

#ifndef _SPHERICAL_PROBLEM_H_
#define _SPHERICAL_PROBLEM_H_

#include "problem.hpp"

class Spherical: public Problem {
public:
  Spherical(const int r = 1024,
	    const int s = 100,
	    const double n = 0,
	    const double x = 786.432,
	    const bool z = true,
	    const double g = 0.99995,
	    const double f = 0.86,
	    const double d = 0.1,
	    const long i = 100000000) : Problem(r, s, n, x, z, g, f, d, i) {};
  double problem(Individual subject) const;
};

#endif /* _SPHERICAL_PROBLEM_H_ */
