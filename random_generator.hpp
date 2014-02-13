/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for a singleton class which sets up std::random
 */

#ifndef _RANDOM_GENERATOR_H_
#define _RANDOM_GENERATOR_H_

#include <random>

class RandomGenerator {
private:
  std::random_device rd;

public:
  RandomGenerator();
  std::mt19937 engine;
};

#endif /* _RANDOM_GENERATOR_H_ */
