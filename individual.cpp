/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for class which represents an individual potential solution
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "individual.hpp"

typedef double parameter;

Individual::Individual(const int r, const int s) : range(r), scale(s) {
  for (auto & value : solution) {
     value = (double(std::rand() % range) - range/2)/scale;
  }
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

Individual Individual::mutate(const double delta) const {
  // Returns a copy of original with delta added to each value with
  // a 50% probability
  Individual copy = *this;
  for (auto & value : copy.solution) {
    if (rand() % 2) if (abs(value + delta) < (range/scale)/2) value += delta;
  }
  return copy;
}

std::string Individual::represent() const {
  std::string representation = "Solution:";
  for (auto value : solution) {
    representation += " (" + std::to_string(value) + ")";
  }
  return representation;
}

void Individual::print() const {
  std::cout << represent();
}
