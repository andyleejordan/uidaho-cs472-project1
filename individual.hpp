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
  typedef double parameter;
  typedef std::uniform_real_distribution<parameter> real_dist;
  typedef std::uniform_int_distribution<> int_dist;
  typedef std::normal_distribution<parameter> normal_dist;
}

using namespace Parameters;

class Individual {
private:
  static const int dimension = 30;
  typedef std::array<parameter, dimension> genome;
  genome solution;
  parameter min;
  parameter max;
protected:
  bool minimize = true;
public:
  Individual();
  Individual(const parameter & gene, const bool m);
  Individual(const parameter & n,
	     const parameter & x,
	     const bool m,
	     real_dist r);
  // construction wrappers (e.g. potential() / mutate()) set fitness
  parameter fitness; // raw, not normalized
  // mutate will change gene with bounds-checking
  void mutate(parameter & gene, const parameter gene_i) const;
  const virtual std::string represent() const;
  // Individual acts like genome iterator
  genome::iterator begin();
  genome::iterator end();
  genome::const_iterator begin() const;
  genome::const_iterator end() const;
  genome::size_type size() const;
  parameter & operator[](size_t pos);
  const parameter & operator[](size_t pos) const;
  // Individual can be compared by fitness to other Individual or paramter
  // Takes into account minimize flag, cannot compare unlike Individuals
  friend bool operator<(const Individual & left, const Individual & right);
  friend bool operator>(const Individual & left, const Individual & right);
  template<typename T> friend bool operator<(const Individual & left, const T & right);
  template<typename T> friend bool operator>(const Individual & left, const T & right);
  // Individuals can be added
  friend parameter operator+(const Individual & left, const Individual & right);
  template<typename T> T friend operator+(const T & number, const Individual & right);
  template<typename T> T friend operator+(const Individual & left, const T & number);
};

template<typename T> bool operator<(const Individual & left, const T & right) {
  // switch comparison so 0 is a "higher" fitness
  if (left.minimize) return left.fitness > right;
  // else assume lesser fitness is in fact lesser
  else return left.fitness < right;
}

template<typename T> bool operator>(const Individual & left, const T & right) {
  // switch comparison so 0 is a "higher" fitness
  if (left.minimize) return left.fitness < right;
  // else assume greate fitness is in fact greater
  else return left.fitness > right;
}

template<typename T> T operator+(const Individual & left, const Individual & right) {
  return left.fitness + right.fitness;
}

template<typename T> T operator+(const T & number, const Individual & right) {
  return number + right.fitness;
}

template<typename T> T operator+(const Individual & left, const T & number) {
  return left.fitness + number;
}

#endif /* _INDIVIDUAL_H_ */
