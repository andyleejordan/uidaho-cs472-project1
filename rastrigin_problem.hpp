/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for rastrigin problem derived class
 */

#ifndef _RASTRIGIN_PROBLEM_H_
#define _RASTRIGIN_PROBLEM_H_

#include "problem.hpp"
#include "individual.hpp"

class Rastrigin: public Problem {
public:
  Rastrigin(const long i = 1000000000,
	    const parameter g = 0.999,
	    const parameter f = 0.85,
	    const parameter d = 0.1,
	    const parameter h = 0.5,
	    const int c = 10000): Problem(-5.12, 5.12,
					  0, 900, true,
					  i, g, f, d, h, c) {};
  parameter problem(const Individual & subject) const;
};

#endif /* _RASTRIGIN_PROBLEM_H_ */
