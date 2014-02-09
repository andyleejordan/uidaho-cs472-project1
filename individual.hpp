/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for class which represents an individual potential solution
 */

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <array>
#include <cstdlib>
#include <string>

class Individual {
private:
  typedef double parameter;
  int range;
  int scale;
  static const int dimension = 30;
  std::array <parameter, dimension> solution;
public:
  Individual(const int r = 1, const int s = 1000000);
  Individual mutate(const double delta) const;
  std::string represent() const;
  void print() const;

  // Individual acts like std::array solution iterator
  std::array <parameter, dimension>::iterator begin();
  std::array <parameter, dimension>::iterator end();
  std::array <parameter, dimension>::const_iterator begin() const;
  std::array <parameter, dimension>::const_iterator end() const;
};

#endif /* _INDIVIDUAL_H_ */
