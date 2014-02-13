/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for a singleton class which sets up std::random
 */

#ifndef _RANDOM_GENERATOR_H_
#define _RANDOM_GENERATOR_H_

#include <random>

class RandomGenerator {
private:
  typedef std::mt19937 engine;
  std::random_device rd;

public:
  RandomGenerator();
  engine gen;
};

#endif /* _RANDOM_GENERATOR_H_ */
