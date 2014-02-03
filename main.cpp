/* Copyright 2014 Andrew Schwartzmeyer
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 * Project #1a Hill Climbing and Simulated Annealing
 * This program uses C++11 extensions (array template and auto specifier)
 */

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef int param;

const int dim = 30;
const float spherical_scale = 100;
const float schwefel_scale = 10000;
const int spherical_range = (5.12 + 5.12) * spherical_scale;
const int schwefel_range = (512.03 + 511.97) * schwefel_scale;
const int spherical_min = 0;
const int spherical_max = 520;
const int schwefel_min = -6100;
const int schwefel_max = 6900;

param spherical(array <param, dim> params) {
  param sum = 0;
  for (int i = 0; i < dim; i++) {
    sum += pow(params[i], 2);
  }
  return sum;
}

param schwefel(array <param, dim> params) {
  param sum = 0;
  for (int i = 0; i < dim; i++) {
    sum += params[i] * sin(sqrt(abs(params[i])));
  }
  return (418.9829 * schwefel_scale) + sum;
}

float get_fitness(const param min,
		  const param max,
		  const param sol,
		  const float scale) {
  // Scales param [min, max] to int [0, 10]
  return 10. - (10. * float(sol/scale - min)) / float(max - min);
}

array <param, dim> gen_sol(const param range) {
  array <param, dim> sol;
  for (int i = 0; i < dim; i++) {
    sol[i] = (rand() % range) - range/2;
  }
  return sol;
}

array <param, dim> gen_near(array <param, dim> sol, const int adjust) {
  int index = rand() % dim;
  sol[index] += adjust;
  return sol;
}


void accumulate_spherical(vector<param> * solutions, const int iterations) {
  for (int i = 0; i < iterations; i++) {
    solutions->push_back(spherical(gen_sol(spherical_range)));
  }
}

void accumulate_schwefel(vector <param> * solutions, const int iterations) {
  for (int i = 0; i < iterations; i++) {
    solutions->push_back(schwefel(gen_sol(schwefel_range)));
  }
}

void print_sol() {
  array <param, dim> solution = gen_sol(schwefel_range);

  for (int i = 0; i < dim; i++) {
    cout << float(solution[i])/schwefel_scale << ' ';
  }
  cout << '\n';
}

void print_minmax(void (*accumulate)(vector <param> * solutions,
				     const int iterations),
		  const int iterations,
		  const int scale,
		  const string kind) {
  vector <param> * solutions_ptr = new vector <param>;

  accumulate(solutions_ptr, iterations);

  auto minmax = minmax_element(solutions_ptr->begin(),
			       solutions_ptr->end());

  cout << kind+" min\n" << *minmax.first/scale << '\n'
       << kind+" max\n" << *minmax.second/scale << '\n';
    
}

int main(int argc, char *argv[]) {
  srand(time(0));

  void (*accumulate)(vector <param> * solutions,
		     const int iterations) = &accumulate_spherical;

  print_minmax(accumulate, 10000, spherical_scale, "Spherical");
 
  return 0;
}
