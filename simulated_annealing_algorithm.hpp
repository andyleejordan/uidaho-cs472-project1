/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for simulated annealing derived algorithm class
 */

#ifndef _SIMULATED_ANNEALING_ALGORITHM_H_
#define _SIMULATED_ANNEALING_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class SimulatedAnnealing: public Algorithm {
private:
  bool probability(const double energy1,
		   const double energy2,
		   const double temperature) const;
public:
  SimulatedAnnealing(Problem * p) : Algorithm(p) {};
  const Individual * solve() const;
};

#endif /* _SIMULATED_ANNEALING_ALGORITHM_H_ */
