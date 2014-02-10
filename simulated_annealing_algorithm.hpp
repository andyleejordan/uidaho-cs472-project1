/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for simulated annealing derived algorithm class
 */

#ifndef _SIMULATED_ANNEALING_ALGORITHM_H_
#define _SIMULATED_ANNEALING_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class SimulatedAnnealing: public Algorithm {
private:
  bool probability(double energy1, double energy2, double temperature) const;
public:
  SimulatedAnnealing(Problem * p) : Algorithm(p) {};
  Individual solve() const;
};

#endif /* _SIMULATED_ANNEALING_ALGORITHM_H_ */
