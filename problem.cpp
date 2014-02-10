/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for base problem class
 */

#include "problem.hpp"

Problem::Problem(const int r,
		 const int s,
		 const double n,
		 const double x,
		 const bool z,
		 const double g,
		 const double f,
		 const double d,
		 const int c,
		 const long i) : range(r),
				 scale(s),
				 min(n),
				 max(x),
				 minimize(z),
				 goal(g),
				 filter(f),
				 delta(d),
				 constant(c),
				 iterations(i) {};

Individual Problem::potential() const {
  Individual potential(range, scale);
  return potential;
}

Individual Problem::mutate(Individual potential) const {
  Individual mutated = potential.mutate(delta);
  return mutated;
}

double Problem::fitness(Individual subject) const {
  // Scales problem value [min, max] to double [0, 1] with 1 being max fitness
  double sum = this->problem(subject);
  double fitness = ((sum - min) / (max - min)); // normalize
  if (minimize) fitness = 1. - fitness; // inverse if trying to minimize
  return fitness;
}
