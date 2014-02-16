/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for (base) class which represents an individual
 * potential solution.
 */

#include <cmath>
#include <cstdlib>

#include "individual.hpp"
#include "problem.hpp"

Individual::Individual() {
  min = -1;
  max = 1;
  real_dist range_dist(min, max);
  for (parameter & value : solution)
    value = range_dist(rg.engine);
}

Individual::Individual(const parameter n,
		       const parameter x,
		       real_dist range_dist): min(n),
					      max(x), 
					      fitness(0) {
  for (parameter & value : solution)
    value = range_dist(rg.engine);
}

const std::string Individual::represent() const {
  std::string representation = "Solution:";
  for (parameter value : solution)
    representation += " (" + std::to_string(value) + ")";
  return representation += "\n";
}

void Individual::mutate(parameter & value, const parameter value_i) const {
  // clip if out of bounds
  if (value_i < min) value = min;
  else if (value_i > max) value = max;
  // increment only if it would be within the bounds
  else value = value_i;
}

std::array <parameter, Individual::dimension>::iterator Individual::begin() {
  return solution.begin();
}

std::array <parameter, Individual::dimension>::iterator Individual::end() {
  return solution.end();
}

std::array <parameter, Individual::dimension>::const_iterator Individual::begin() const {
  return solution.begin();
}

std::array <parameter, Individual::dimension>::const_iterator Individual::end() const {
  return solution.end();
}

std::array <parameter, Individual::dimension>::size_type Individual::size() const {
  return solution.size();
}
