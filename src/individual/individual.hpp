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

#include "../aliases.hpp"
#include "../random_generator.hpp"

namespace individual {
  using aliases::parameter;
  using random_generator::real_dist;

  class Individual {
  private:
    static const int dimension = 30;
    typedef std::array<parameter, dimension> genome;
    genome solution;
    parameter min;
    parameter max;
  public:
    Individual();
    Individual(const parameter & gene, const bool m);
    Individual(const parameter & n,
	       const parameter & x,
	       const bool m,
	       real_dist r);
    bool minimize = true;
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
    // Individual can be compared by fitness to other Individual
    // Takes into account minimize flag, cannot compare unlike Individuals
    friend bool operator<(const Individual & left, const Individual & right);
    friend bool operator>(const Individual & left, const Individual & right);
    // These may be unneeded declarations
    template<typename T> friend bool operator<(const Individual & left, const T & right);
    template<typename T> friend bool operator>(const Individual & left, const T & right);
    // Individuals can be added
    friend parameter operator+(const Individual & left, const Individual & right);
    template<typename T> T friend operator+(const T & number, const Individual & right);
    template<typename T> T friend operator+(const Individual & left, const T & number);
  };

  // Templates to compare Individual with other types
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
}

#endif /* _INDIVIDUAL_H_ */
