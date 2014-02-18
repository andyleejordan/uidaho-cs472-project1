/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for base problem class
 */

#include <cassert>
#include <cmath>

#include "problem.hpp"

Problem::Problem(const parameter dn,
		 const parameter dx,
		 const parameter rn,
		 const parameter rx,
		 const bool z,
		 const long i,
		 const parameter g,
		 const parameter f,
		 const parameter d,
		 const parameter h,
		 const int c): range_min(rn),
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

parameter Problem::normal(const Individual & subject) const {
  // Scales problem value [min, max] to parameter [0, 1] with 1 being max fitness
  parameter normal = (subject.fitness - range_min) / (range_max - range_min);
  if (minimize) {
    if (normal > 1) normal = 1; // truncate worst end of fitnesses to 1
    assert(normal >= 0); // fail if best fitness is < 0
    normal = 1. - normal; // inverse if trying to minimize
  } else {
    if (normal < 0) normal = 0; // truncate worst end of fitnesses to 0
    assert(normal <= 1); // fail if best fitness is > 1
  }
  return normal;
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
