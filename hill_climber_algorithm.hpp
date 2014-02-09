/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base algorithm class
 */

#ifndef _HILL_CLIMBER_ALGORITHM_H_
#define _HILL_CLIMBER_ALGORITHM_H_
#include "individual.hpp"
#include "problem.hpp"
#include "algorithm.hpp"

class HillClimber: public Algorithm {
public:
  HillClimber(Problem p) : Algorithm(p) {};
  Individual solve();
};

#endif /* _HILL_CLIMBER_ALGORITHM_H_ */
