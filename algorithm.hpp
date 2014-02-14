/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for abstract base algorithm class
 */

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "individual.hpp"
#include "problem.hpp"

class Algorithm {
protected:
  const Problem & problem;
public:
  Algorithm(const Problem & p);
  const virtual Individual solve() const =0;
  const virtual Individual mutate(const Individual & subject) const;
};

#endif /* _ALGORITHM_H_ */
