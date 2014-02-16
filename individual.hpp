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
extern RandomGenerator rg;

namespace Parameters {
  typedef float parameter;
  typedef std::uniform_real_distribution<parameter> real_dist;
  typedef std::uniform_int_distribution<> int_dist;
  typedef std::normal_distribution<parameter> normal_dist;
}

using namespace Parameters;

class Individual {
private:
  static const int dimension = 30;
  typedef std::array <parameter, dimension> genome;
  genome solution;
  parameter min;
  parameter max;
public:
  Individual();
  Individual(const parameter n, const parameter x, real_dist range_dis);
  // construction wrappers (e.g. potential() / mutate()) set fitness
  parameter fitness;
  // mutate will change gene with bounds-checking
  void mutate(parameter & gene, const parameter gene_i) const;
  const virtual std::string represent() const;
  // Individual acts like std::array solution iterator
  genome::iterator begin();
  genome::iterator end();
  genome::const_iterator begin() const;
  genome::const_iterator end() const;
  genome::size_type size() const;
  // Individual can be compared by fitness
  friend bool operator< (const Individual & left, const Individual & right);
  friend bool operator> (const Individual & left, const Individual & right);
};

#endif /* _INDIVIDUAL_H_ */
