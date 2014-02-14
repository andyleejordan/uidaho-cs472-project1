/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for derived genetic algorithm class
 */

#ifndef _GENETIC_ALGORITHM_H_
#define _GENETIC_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class Genetic: public Algorithm {
private:
  static const int pop_size = 4000;
  static const int mean = 0;
  static const int stddev = 2;

public:
  Genetic(const Problem & p) : Algorithm(p) {};
  const Individual solve() const;
  void mutate(Individual & subject) const;
};

#endif /* _GENETIC_ALGORITHM_H_ */
