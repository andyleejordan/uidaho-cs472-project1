/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for class which represents an individual potential solution
 */

#include <cmath>
#include <iostream>

#include "individual.hpp"

Individual::Individual(const int r, const int s) : range(r), scale(s) {
  BOOST_FOREACH(parameter &value, solution) {
     value = (float(std::rand() % range) - range/2)/scale;
  }
}

Individual Individual::mutate(const double delta) {
  // Returns a copy of original with delta added to each value with
  // a 50% probability
  Individual copy = *this;
  BOOST_FOREACH(parameter &value, copy.solution) {
    if (rand() % 2) if (abs(value + delta) < (range/scale)/2) value += delta;
  }
  return copy;
}

std::string Individual::represent() {
  std::string representation = "Solution:";
  BOOST_FOREACH(parameter value, solution) {
    representation += " (" + std::to_string(value) + ")";
  }
  return representation;
}

void Individual::print() {
  std::cout << represent();
}
