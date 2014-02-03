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
const int spherical_min = 6100;
const int spherical_max = 52000;
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

int fitness(const param min, const param max, const param sol) {
  // Scales param [min, max] to int [0, 10]
  return (10 * (sol - min)) / (min - max);
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

void print_minmax(const int iterations) {
  vector <param> * spherical_sols_ptr = new vector <param>;
  vector <param> * schwefel_sols_ptr = new vector <param>;

  accumulate_schwefel(schwefel_sols_ptr, iterations);
  accumulate_spherical(spherical_sols_ptr, iterations);

  auto spherical_minmax = minmax_element(spherical_sols_ptr->begin(),
					 spherical_sols_ptr->end());

  auto schwefel_minmax = minmax_element(schwefel_sols_ptr->begin(),
					schwefel_sols_ptr->end());

  cout << "Spherical min\n" << *spherical_minmax.first/spherical_scale << '\n'
       << "Spherical max\n" << *spherical_minmax.second/spherical_scale << '\n';
    
  cout << "Schwefel min\n" << *schwefel_minmax.first/schwefel_scale << '\n'
       << "Schwefel max\n" << *schwefel_minmax.second/schwefel_scale << '\n';
}

int main(int argc, char *argv[]) {
  srand(time(0));

  print_minmax(1000000);
 
  return 0;
}
