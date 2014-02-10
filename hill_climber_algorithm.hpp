/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base algorithm class
 */

#ifndef _HILL_CLIMBER_ALGORITHM_H_
#define _HILL_CLIMBER_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class HillClimber: public Algorithm {
public:
  HillClimber(Problem * p) : Algorithm(p) {};
  Individual solve() const;
};

#endif /* _HILL_CLIMBER_ALGORITHM_H_ */
