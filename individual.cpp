/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for (base) class which represents an individual
 * potential solution.
 */

#include <cmath>
#include <cstdlib>

#include "individual.hpp"
#include "problem.hpp"

Individual::Individual(const parameter n,
		       const parameter x,
		       std::uniform_real_distribution<parameter> range_dis) : min(n),
									      max(x) {
  for (parameter & value : solution)
    value = range_dis(rg->engine);
}

const std::string Individual::represent() const {
  std::string representation = "Solution:";
  for (parameter value : solution)
    representation += " (" + std::to_string(value) + ")";
  return representation += "\n";
}

void Individual::mutate(parameter & value, const parameter delta) const {
  // clip if out of bounds
  parameter value_i = value + delta;
  if (value_i < min) value = min;
  else if (value_i > max) value = max;
  // increment only if it would be within the bounds
  else value = value_i;
}

std::array <parameter, dimension>::iterator Individual::begin() {
  return solution.begin();
}

std::array <parameter, dimension>::iterator Individual::end() {
  return solution.end();
}

std::array <parameter, dimension>::const_iterator Individual::begin() const {
  return solution.begin();
}

std::array <parameter, dimension>::const_iterator Individual::end() const {
  return solution.end();
}

std::array <parameter, dimension>::size_type Individual::size() const {
  return solution.size();
}
