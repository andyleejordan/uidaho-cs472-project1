/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for a singleton class which sets up std::random
 */

#ifndef _RANDOM_GENERATOR_H_
#define _RANDOM_GENERATOR_H_

#include <random>

#include "aliases.hpp"

namespace random_generator {
  using aliases::parameter;
  typedef std::uniform_real_distribution<parameter> real_dist;
  typedef std::uniform_int_distribution<> int_dist;
  typedef std::normal_distribution<parameter> normal_dist;

  class RandomGenerator {
  private:
    std::random_device rd;
  public:
    RandomGenerator();
    std::mt19937_64 engine;
  };

  extern RandomGenerator rg;
}

#endif /* _RANDOM_GENERATOR_H_ */
