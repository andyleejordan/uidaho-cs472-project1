/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for base problem class
 */

#include <cmath>

#include "problem.hpp"

Problem::Problem(const double dn,
		 const double dx,
		 const double rn,
		 const double rx,
		 const bool z,
		 const double g,
		 const double f,
		 const double d,
		 const double h,
		 const int c,
		 const long i) : domain_min(dn),
				 domain_max(dx),
				 range_min(rn),
				 range_max(rx),
				 minimize(z),
				 range_dis(dn, dx),
				 delta_dis(-d*(std::abs(dn) + std::abs(dx))/2,
					   d*(std::abs(dn) + std::abs(dx))/2),
				 goal(g),
				 filter(f),
				 delta(d),
				 chance(h),
				 constant(c),
				 iterations(i) {};

double Problem::fitness(const Individual * subject) const {
  // Scales problem value [min, max] to double [0, 1] with 1 being max fitness
  double sum = this->problem(subject);
  double fitness = ((sum - range_min) / (range_max - range_min)); // normalize
  if (minimize) fitness = 1. - fitness; // inverse if trying to minimize
  return fitness;
}

Individual * Problem::potential() const {
  Individual * potential = new Individual(domain_min, domain_max, range_dis);
  return potential;
}

std::array <double, dimension> Problem::mutate(const Individual * subject) {
  const double delta = delta_dis(rg->engine);
  return subject->mutate(delta, chance);
}
