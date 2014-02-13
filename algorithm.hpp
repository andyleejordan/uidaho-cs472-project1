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
  Problem * problem;
public:
  Algorithm(Problem * p);
  const virtual Individual * solve() const =0;
  virtual std::array <parameter, dimension> mutate(const Individual * subject) const;
};

#endif /* _ALGORITHM_H_ */
