/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for a singleton class which sets up std::random
 */

#include <random>

#include "random_generator.hpp"

using random_generator::RandomGenerator;

RandomGenerator::RandomGenerator() {
  engine.seed(rd());
}

namespace random_generator {
  // Singleton RandomGenerator object for shared use
  RandomGenerator rg;
}
