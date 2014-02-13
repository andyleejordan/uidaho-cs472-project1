/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for base problem class
 */

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "individual.hpp"

extern const int dimension;

class Problem {
protected:
  const double domain_min;
  const double domain_max;
  const double range_min;
  const double range_max;
  const bool minimize;
  std::uniform_real_distribution<> range_dis;
  std::uniform_real_distribution<> delta_dis;

public:
  const double goal;
  const double filter;
  double delta;
  double chance;
  const int constant;
  const long iterations;

  Problem(const double dn = 0,
	  const double dx = 1,
	  const double rn = 0,
	  const double rx = 10,
	  const bool z = false,
	  const double g = 100,
	  const double f = 0.5,
	  const double d = 0.1,
	  const double h = 0.5,
	  const int c = 1,
	  const long i = 1000000);
  double fitness(const Individual * subject) const;
  virtual double problem(const Individual * subject) const =0;
  virtual Individual * potential() const;
  std::array <double, dimension> mutate(const Individual * subject);
};

#endif /* _PROBLEM_H_ */
