/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for (base) class which represents an individual
 * potential solution.
 */

#include <cmath>
#include <cstdlib>

#include "individual.hpp"
#include "problem.hpp"

Individual::Individual(): min(0), max(0), fitness(0) {
  // zeroed individual represents error
  for (parameter & value : solution)
    value = 0;
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

Individual::genome::iterator Individual::begin() {
  return solution.begin();
}

Individual::genome::iterator Individual::end() {
  return solution.end();
}

Individual::genome::const_iterator Individual::begin() const {
  return solution.begin();
}

Individual::genome::const_iterator Individual::end() const {
  return solution.end();
}

Individual::genome::size_type Individual::size() const {
  return solution.size();
}
