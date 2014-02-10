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
  const double min;
  const double max;
  const bool minimize;

public:
  const double goal;
  const double filter;
  double delta;
  const int constant;
  const long iterations;

  Problem(const int r = 1,
	  const int s = 100,
	  const double n = 0,
	  const double x = 10,
	  const bool z = false,
	  const double g = 100,
	  const double f = 0.5,
	  const double delta = 0.1,
	  const int c = 1,
	  const long i = 1000000);
  Individual potential() const;
  Individual mutate(Individual potential) const;
  double fitness(Individual subject) const;
  virtual double problem(Individual subject) const =0;
};

#endif /* _PROBLEM_H_ */
