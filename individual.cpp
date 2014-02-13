/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for (base) class which represents an individual
 * potential solution.
 */

#include <cmath>
#include <cstdlib>

#include "individual.hpp"
#include "problem.hpp"

Individual::Individual(const double n,
		       const double x,
		       std::uniform_real_distribution<> range_dis) : min(n),
								     max(x) {
  for (auto & value : solution)
    value = range_dis(rg->engine);
}

const std::string Individual::represent() const {
  std::string representation = "Solution:";
  for (auto value : solution)
    representation += " (" + std::to_string(value) + ")";
  return representation += "\n";
}

std::array <double, dimension> Individual::mutate(const double delta,
						  const double chance) const {
  // Returns a copy of original 
  std::array <double, dimension> mutation = this->solution;
  std::uniform_int_distribution<> percent(1, 100);
  for (auto & value : mutation)
    if (percent(rg->engine) < int(100 * chance)) { // convert [0, 1] to percent
      double value_i = value + delta;
      // increment only if it would be within the bounds
      if (min <= value_i && value_i <= max) value += value_i;
    }
  return mutation;
}

std::array <double, dimension>::iterator Individual::begin() {
  return solution.begin();
}

std::array <double, dimension>::iterator Individual::end() {
  return solution.end();
}

std::array <double, dimension>::const_iterator Individual::begin() const {
  return solution.begin();
}

std::array <double, dimension>::const_iterator Individual::end() const {
  return solution.end();
}

std::array <double, dimension>::size_type Individual::size() const {
  return solution.size();
}
