/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for a singleton class which sets up std::random
 */

#include "random_generator.hpp"

RandomGenerator::RandomGenerator() {
  gen.seed(rd());
}

// Singleton RandomGenerator object for shared use
RandomGenerator * rg = new RandomGenerator;
