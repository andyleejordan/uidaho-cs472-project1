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

class Individual {
protected:
  static const int dimension = 30;
  const double min;
  const double max;
  std::array <double, dimension> solution;
public:
  // default to values [0, 1] to six decimal places
  Individual(const double n = -1,
	     const double x = 1,
	     std::uniform_real_distribution<> range_dis = std::uniform_real_distribution<>(0, 1));
  const virtual std::string represent() const;
  const virtual Individual * mutate(const double delta, const double chance) const;

  // Individual acts like std::array solution iterator
  std::array <double, dimension>::iterator begin();
  std::array <double, dimension>::iterator end();
  std::array <double, dimension>::const_iterator begin() const;
  std::array <double, dimension>::const_iterator end() const;
  std::array <double, dimension>::size_type size() const;
};

#endif /* _INDIVIDUAL_H_ */
