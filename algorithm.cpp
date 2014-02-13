/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for abstract base algorithm class
 */

#include "algorithm.hpp"

Algorithm::Algorithm(Problem * p) : problem(p) {
}

std::array <parameter, dimension> Algorithm::mutate(const Individual * subject) const {
  // basic mutation by delta distribution and chance
  std::array <parameter, dimension> mutation = subject->solution;
  std::uniform_int_distribution<> percent(1, 100);
  for (parameter & value : mutation)
    if (problem->chance || percent(rg->engine) < int(100 * problem->chance))
      subject->mutate(value, problem->delta_dis(rg->engine));
  return mutation;
}
