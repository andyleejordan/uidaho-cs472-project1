/* Copyright 2014 Andrew Schwartzmeyer
 * Header file for base algorithm class
 */

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "individual.hpp"
#include "problem.hpp"

class Algorithm {
protected:
  Problem problem;
public:
  Algorithm(Problem p) : problem(p) {};
  Individual solve();
};

#endif /* _ALGORITHM_H_ */
