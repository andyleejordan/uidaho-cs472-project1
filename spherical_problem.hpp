/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for spherical problem derived class
 */

#ifndef _SPHERICAL_PROBLEM_H_
#define _SPHERICAL_PROBLEM_H_

#include "problem.hpp"
#include "individual.hpp"

class Spherical: public Problem {
public:
  Spherical(const double dn = -5.12,
	    const double dx = 5.12,
	    const double rn = 0,
	    const double rx = 786.432,
	    const bool z = true,
	    const double g = 0.99,
	    const double f = 0.86,
	    const double d = 0.1,
	    const double h = 0.5,
	    const int c = 100000,
	    const long i = 10000000) : Problem(dn, dx, rn, rx, z, g, f, d, h, c, i) {};
  double problem(const Individual * subject) const;
};

#endif /* _SPHERICAL_PROBLEM_H_ */
