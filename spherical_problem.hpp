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
  Spherical(const parameter dn = -5.12,
	    const parameter dx = 5.12,
	    const parameter rn = 0,
	    const parameter rx = 786.432,
	    const bool z = true,
	    const parameter g = 0.99,
	    const parameter f = 0.86,
	    const parameter d = 0.1,
	    const parameter h = 0.2,
	    const int c = 10000,
	    const long i = 100000000) : Problem(dn, dx, rn, rx,
						z, g, f, d, h, c, i) {};
  parameter problem(const Individual * subject) const;
};

#endif /* _SPHERICAL_PROBLEM_H_ */
