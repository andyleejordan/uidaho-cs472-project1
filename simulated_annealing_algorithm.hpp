/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for simulated annealing derived algorithm class
 */

#ifndef _SIMULATED_ANNEALING_ALGORITHM_H_
#define _SIMULATED_ANNEALING_ALGORITHM_H_

#include "algorithm.hpp"
#include "individual.hpp"
#include "problem.hpp"

class SimulatedAnnealing: private Algorithm {
private:
  bool probability(const parameter energy1,
		   const parameter energy2,
		   const parameter temperature) const;
public:
  SimulatedAnnealing(const Problem & p): Algorithm(p) {};
  const Individual solve() const;
};

#endif /* _SIMULATED_ANNEALING_ALGORITHM_H_ */
