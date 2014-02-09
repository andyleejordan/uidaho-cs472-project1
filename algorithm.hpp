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
  Algorithm(Problem p);
  Individual solve() const;
};

#endif /* _ALGORITHM_H_ */
