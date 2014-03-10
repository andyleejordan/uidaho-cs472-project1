/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for abstract base algorithm class
 */

#include "algorithm.hpp"
#include "../aliases.hpp"
#include "../individual/individual.hpp"
#include "../problem/problem.hpp"
#include "../random_generator.hpp"
#include "mutator/mutator.hpp"

using algorithm::Algorithm;
using aliases::parameter;
using individual::Individual;
using problem::Problem;
using namespace random_generator;

Algorithm::Algorithm(const Problem & p, const Mutator & m): problem(p), mutator(m) {}
