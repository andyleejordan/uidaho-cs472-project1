/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for base problem class
 */

#include <cmath>

#include "problem.hpp"

Problem::Problem(const parameter dn,
		 const parameter dx,
		 const parameter rn,
		 const parameter rx,
		 const bool z,
		 const parameter g,
		 const parameter f,
		 const parameter d,
		 const parameter h,
		 const int c,
		 const long i) : range_min(rn),
				 range_max(rx),
				 minimize(z),
				 domain_min(dn),
				 domain_max(dx),
				 goal(g),
				 filter(f),
				 delta(d),
				 chance(h),
				 constant(c),
				 iterations(i) {};
			       range_dist(dn, dx),

parameter Problem::fitness(const Individual & subject) const {
  // Scales problem value [min, max] to parameter [0, 1] with 1 being max fitness
  parameter sum = this->problem(subject);
  parameter fitness = ((sum - range_min) / (range_max - range_min)); // normalize
  if (minimize) fitness = 1. - fitness; // inverse if trying to minimize
  return fitness;
}

Individual Problem::potential() const {
  return Individual(domain_min, domain_max, range_dis);
 }
