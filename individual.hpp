/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for a base class which represents an individual
 * potential solution. Can be derived for, say, a ranged individual.
 */

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <array>
#include <cstdlib>
#include <string>

#include "random_generator.hpp"

extern RandomGenerator * rg;
int const dimension = 30;
typedef float parameter;

class Individual {
protected:
  parameter min;
  parameter max;

public:
  Individual();
  Individual(const parameter n,
	     const parameter x,
	     std::uniform_real_distribution<parameter> range_dis);

  std::array <parameter, dimension> solution;

  const virtual std::string represent() const;
  void mutate(parameter & value, const parameter value_i) const;

  // Individual acts like std::array solution iterator
  std::array <parameter, dimension>::iterator begin();
  std::array <parameter, dimension>::iterator end();
  std::array <parameter, dimension>::const_iterator begin() const;
  std::array <parameter, dimension>::const_iterator end() const;
  std::array <parameter, dimension>::size_type size() const;
};

#endif /* _INDIVIDUAL_H_ */
