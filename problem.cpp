/* Copyright 2014 Andrew Schwartzmeyer
 * Source file for base problem class
 */

#include "problem.hpp"
#include "individual.hpp"

Problem::Problem(const int r,
		 const int s,
		 const int g,
		 const int f,
		 const int i,
		 const double d) : range(r),
				   scale(s),
				   goal(g),
				   filter(f),
				   iterations(i),
				   delta(d) {};

Individual Problem::potential() const {
  Individual potential(range, scale);
  return potential;
}

Individual Problem::mutate(Individual potential) const {
  Individual mutated = potential.mutate(delta);
  return mutated;
}
