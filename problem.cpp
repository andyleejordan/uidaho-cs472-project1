/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for base problem class
 */

#include <cassert>
#include <cmath>

#include "problem.hpp"

Problem::Problem(const std::string & n,
		 const parameter dn,
		 const parameter dx,
		 const parameter rn,
		 const parameter rx,
		 const bool z,
		 const long i,
		 const parameter g,
		 const parameter f,
		 const parameter d,
		 const parameter h,
		 const int c): name(n),
			       range_min(rn),
			       range_max(rx),
			       minimize(z),
			       range_dist(dn, dx),
			       domain_min(dn),
			       domain_max(dx),
			       goal(g),
			       filter(f),
			       delta(d),
			       chance(h),
			       constant(c),
			       iterations(i) {};

parameter Problem::fitness(const Individual & subject) const {
  // Scales problem value [min, max] to parameter [0, 1] with 1 being max fitness
  parameter raw = this->problem(subject);
  parameter fitness = std::abs(raw - range_min) / (range_max - range_min); // normalize
  if (minimize) {
    if (fitness > 1) fitness = 1; // truncate worst end of fitnesses to 1
    assert(fitness >= 0); // fail if best fitness is < 0
    fitness = 1. - fitness; // inverse if trying to minimize
  } else {
    if (fitness < 0) fitness = 0; // truncate worst end of fitnesses to 0
    assert(fitness <= 1); // fail if best fitness is > 1
  }
  return fitness;
}

const Individual Problem::worst() const {
  Individual worst = this->potential();
  for (int i = 0; i < iterations; ++i) {
    const Individual subject = this->potential();
    if (subject.fitness < worst.fitness) worst = subject;
  }
  return worst;
}

const Individual Problem::potential() const {
  Individual potential = Individual(domain_min, domain_max, range_dist);
  potential.fitness = fitness(potential);
  return potential;
}

const std::string Problem::represent() const {
  std::string representation = name + " problem with domain ["
    + std::to_string(domain_min) + ", " + std::to_string(domain_max)
    + "] seeking goal of " + std::to_string(goal)
    + " using a maximum of " + std::to_string(iterations) + " iterations.\n";
  return representation;
}
