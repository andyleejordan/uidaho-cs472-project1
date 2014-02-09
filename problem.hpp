/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base problem class
 */

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "individual.hpp"

class Problem {
protected:
  const int range;
  const int scale;
public:
  const int goal;
  const int filter;
  const int iterations;
  const double delta;

  Problem(const int r = 1,
	  const int s = 100,
	  const int g = 100,
	  const int f = 1000,
	  const int i = 1000000,
	  const double delta = 0.1);
  double fitness(Individual subject);
  Individual potential() const;
  Individual mutate(Individual potential) const;
};

#endif /* _PROBLEM_H_ */
