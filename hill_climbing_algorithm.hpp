/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for derived hill-climbing algorithm class
 */

#ifndef _HILL_CLIMBING_ALGORITHM_H_
#define _HILL_CLIMBING_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class HillClimbing: public Algorithm {
public:
  HillClimbing(Problem * p) : Algorithm(p) {};
  Individual solve() const;
};

#endif /* _HILL_CLIMBING_ALGORITHM_H_ */
