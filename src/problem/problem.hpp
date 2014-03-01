/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for base problem class
 */

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "individual.hpp"

class Problem {
protected:
  const parameter range_min;
  const parameter range_max;
  const bool minimize;
  real_dist range_dist;
public:
  const std::string name;
  const parameter domain_min;
  const parameter domain_max;
  const parameter goal;
  const parameter filter;
  const parameter delta;
  const parameter chance;
  const int constant;
  const long iterations;
  // sane-ish defaults, should all be overridden
  Problem(const std::string & name = "Base",
	  const parameter dn = 0,
	  const parameter dx = 1,
	  const parameter rn = 0,
	  const parameter rx = 10,
	  const bool z = true,
	  const long i = 1000000,
	  const parameter g = 0.9,
	  const parameter f = 0.5,
	  const parameter d = 0.1,
	  const parameter h = 0.5,
	  const int c = 1);
  const Individual potential() const;
  parameter normal(const Individual & subject) const;
  const Individual worst() const;
  virtual parameter fitness(const Individual & subject) const =0;
  const std::string represent() const;
  bool compare(const std::string & c) const;
};

#endif /* _PROBLEM_H_ */
