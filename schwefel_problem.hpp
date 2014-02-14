/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for base problem class
 */

#ifndef _SCHWEFEL_PROBLEM_H_
#define _SCHWEFEL_PROBLEM_H_

#include "problem.hpp"

class Schwefel: public Problem {
public:
  Schwefel(const parameter dn = -512.03,
	   const parameter dx = 511.97,
	   const parameter rn = 0,
	   const parameter rx = 21000,
	   const bool z = true,
	   const parameter g = 0.85,
	   const parameter f = 0.65,
	   const parameter d = 0.1,
	   const parameter h = 0.5,
	   const int c = 1000,
	   const long i = 100000000) : Problem(dn, dx, rn, rx, z, g, f, d, h, c, i) {};
  parameter problem(const Individual & subject) const;
};

#endif /* _SCHWEFEL_PROBLEM_H_ */
