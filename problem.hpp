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
  const parameter domain_min;
  const parameter domain_max;
  const parameter range_min;
  const parameter range_max;
  const bool minimize;
  std::uniform_real_distribution<> range_dis;
  std::uniform_real_distribution<> delta_dis;

public:
  const parameter goal;
  const parameter filter;
  parameter delta;
  parameter chance;
  const int constant;
  const long iterations;

  Problem(const parameter dn = 0,
	  const parameter dx = 1,
	  const parameter rn = 0,
	  const parameter rx = 10,
	  const bool z = false,
	  const parameter g = 100,
	  const parameter f = 0.5,
	  const parameter d = 0.1,
	  const parameter h = 0.5,
	  const int c = 1,
	  const long i = 1000000);
  parameter fitness(const Individual * subject) const;
  virtual parameter problem(const Individual * subject) const =0;
  virtual Individual * potential() const;
  std::array <parameter, dimension> mutate(const Individual * subject);
};

#endif /* _PROBLEM_H_ */
