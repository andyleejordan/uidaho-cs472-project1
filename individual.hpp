/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for class which represents an individual potential solution
 */

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <array>
#include <cstdlib>
#include <string>
#include <boost/foreach.hpp>

class Individual {
private:
  typedef double parameter;
  int range;
  int scale;
  static const int dimension = 30;
  std::array <parameter, dimension> solution;
public:
  Individual(const int r = 1, const int s = 100);
  Individual mutate(const double delta);
  std::string represent();
  void print();
};

#endif /* _INDIVIDUAL_H_ */
