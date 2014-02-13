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

class Individual {
protected:
  const double min;
  const double max;

public:
  Individual(const double n = -1,
	     const double x = 1,
	     std::uniform_real_distribution<> range_dis = std::uniform_real_distribution<>(0, 1));

  std::array <double, dimension> solution;

  const virtual std::string represent() const;
  std::array <double, dimension> mutate(const double delta,
						    const double chance) const;

  // Individual acts like std::array solution iterator
  std::array <double, dimension>::iterator begin();
  std::array <double, dimension>::iterator end();
  std::array <double, dimension>::const_iterator begin() const;
  std::array <double, dimension>::const_iterator end() const;
  std::array <double, dimension>::size_type size() const;
};

#endif /* _INDIVIDUAL_H_ */
