/* Copyright 2014 Andrew Schwartzmeyer
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 * Project #1a Hill Climbing and Simulated Annealing
 * This program uses C++11 extensions (array template and auto specifier)
 * Todo: make Spherical and Schewfel objects
 *
 * param = int, scale = 100, cpu = 0.004, schwefel = 3.55
 * param = int, scale = 100000, cpu = 0.005, schwefel = 3.55145
 * param = float, scale = 1, cpu = 0.004, schwefel = 0.00457813
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

typedef float param;

const int dim = 30;
const int scale = 100;
/*
  Ranges of the function, multipled by 100 so that rand() can
  generate a value, which can be converted to a float and reduced by
  the scaling factor, giving us random floats to two decimal places
*/
const int spherical_range = 12 * scale;
const int schwefel_range = 1024 * scale;

param spherical(array <param, dim> params) {
  float sum = 0;
  for (int i = 0; i < dim; i++) {
    sum += pow(params[i], 2);
  }
  return sum;
}

void test_spherical(param fill) {
  array <param, dim> params;
  params.fill(fill);
  cout << spherical(params) << '\n';
}

param schwefel(array <param, dim> params) {
  float sum = 0;
  for (int i = 0; i < dim; i++) {
    sum += params[i] * sin(sqrt(abs(params[i])));
  }
  return 418.9829 * dim + sum;
}

void test_schwefel(param fill) {
  array <param, dim> params;
  params.fill(fill);
  cout << schwefel(params) << '\n';
}

array <param, dim> gen_sol(const int range) {
  array <param, dim> solution;
  for (int i = 0; i < dim; i++) {
    /*
      Fills the array with random values to two deciaml places, within
      the proper range.
     */
    solution[i] = (float(rand() % range) - range/2) / scale;
  }
  return solution;
}

array <param, dim> gen_near(array <param, dim> solution,
			    const param delta,
			    const int range) {
  for (int i = 0; i < dim; i++ ) {
    if (rand() % 2) continue; // Skip parameter with .5 change
    float replacement = solution[i] + delta;
    // Update parameter if value within correct range
    if (abs(replacement) < (range/scale)/2) solution[i] = replacement;
  }
  return solution;
}

/*
  Accumulates a vector of iterations number of fitnesses for the given
  function
*/
void accumulate(vector<param> * fitnesses,
		const int iterations,
		const int range,
		param (*function)(array <param, dim> params)) {
  for (int i = 0; i < iterations; i++) {
    fitnesses->push_back(function(gen_sol(range)));
  }
}

void print_solution(array <param, dim> solution) {
  for (int i = 0; i < dim; i++) {
    cout << float(solution[i]) << ' ';
  }
  cout << '\n';
}

/*
  Gather iterations number of fitnesses of the given function, print
  the minimum and maximum values
 */
void print_minmax(const int iterations, 
		  const int range,
		  const string kind,
		  param (*function)(array <param, dim> params)) {

  vector <param> * solutions_ptr = new vector <param>;

  accumulate(solutions_ptr, iterations, range, function);

  auto minmax = minmax_element(solutions_ptr->begin(),
			       solutions_ptr->end());

  cout << kind+" min\n" << float(*minmax.first) << '\n'
       << kind+" max\n" << float(*minmax.second) << '\n';
    
}

pair <array <param, dim>, float> hill_climber(const float goal,
					      const float filter,
					      const param range,
					      const int neighbors,
					      param delta,
					      param (*function)(array <param, dim> params)) {

  array <param, dim> solution;
  array <param, dim> neighbor;
  param fitness;
  param neighbor_fitness;

  do {
    solution = gen_sol(range);
    fitness = function(solution);
    if (fitness < filter) {
      cout << "Random restart - fitness is: " << fitness << '\n';
      for (int i = 0; i < neighbors; i++) {
	delta = -delta; // switch between +/-
	neighbor = gen_near(solution, delta, range);
	neighbor_fitness = function(neighbor);
	if (neighbor_fitness < fitness) { // Trying to reach 0
	  solution = neighbor;
	  fitness = neighbor_fitness;
	  // cout << "Better neighbor with fitness: " << fitness << '\n';
	}
      }
      cout << "Neighbors exhausted - fitness was: " << fitness << '\n';
    }
  } while (fitness > goal);
  auto final = make_pair(solution, fitness);
  return final;
}

bool probability(float e1, float e2, float t, int c) {
  float chance = 100 * pow(M_E, (-c*(e1 - e2)/t));
  bool truth = (rand() % 100) < chance;
  // if (truth) cout << "Replacing value because of chance: " << chance << endl;
  return truth;
}

pair <array <param, dim>, float> annealing(const float goal,
					   const float filter,
					   const param range,
					   const int steps,
					   const int constant,
					   param delta,
					   param (*function)(array <param, dim> params)) {
  array <param, dim> solution;
  array <param, dim> neighbor;
  param fitness;
  param neighbor_fitness;
  float temperature;

  do {
    solution = gen_sol(range);
    fitness = function(solution);
    if (fitness < filter) {
      cout << "Random restart - fitness is: " << fitness << '\n';
      for (int T = steps; T > 0; --T) {
	temperature = 100 * float(T)/steps;
	delta = -delta;
	neighbor = gen_near(solution, delta, range);
	neighbor_fitness = function(neighbor);
	if (neighbor_fitness < fitness ||
	    probability(fitness, neighbor_fitness, temperature, constant)) {
	  solution = neighbor;
	  fitness = neighbor_fitness;
	}
      }
      cout << "Temperature zero - fitness was: " << fitness << '\n';
    }
  } while (fitness > goal);
  auto final = make_pair(solution, fitness);
  return final;
}

void run_spherical_hillclimber() {
  pair <array <param, dim>, float> result = hill_climber(10,
							 100,
							 spherical_range,
							 100000000,
							 0.1,
							 &spherical);
  print_solution(result.first);
  cout << "Spherical function value is: " << spherical(result.first) << '\n'
       << "Fitness is: " << result.second << '\n';
}

void run_spherical_annealing() {
  pair <array <param, dim>, float> result = annealing(10,
						      100,
						      spherical_range,
						      100000,
						      -1000,
						      0.01,
						      &spherical);
  print_solution(result.first);
  cout << "Spherical function value is: " << spherical(result.first) << '\n'
       << "Fitness is: " << result.second << '\n';
}


void run_schewfel_hillclimber() {
  pair <array <param, dim>, float> result = hill_climber(5000,
							 10000,
							 schwefel_range,
							 10000000,
							 10,
							 &schwefel);

  print_solution(result.first);
  cout << "Schwefel function value is: " << schwefel(result.first) << '\n'
       << "Fitness is: " << result.second << '\n';
}

void run_schewfel_annealing() {
  pair <array <param, dim>, float> result = annealing(3000,
						      10000,
						      schwefel_range,
						      10000000,
						      -10,
						      10,
						      &schwefel);
  print_solution(result.first);
  cout << "Schwefel function value is: " << schwefel(result.first) << '\n'
       << "Fitness is: " << result.second << '\n';
}

int main(int argc, char *argv[]) {
  srand(time(0));

  // run_spherical_hillclimber();
  // run_schewfel_hillclimber();
  // run_spherical_annealing();
  run_schewfel_annealing();
  
  // print_solution(gen_sol(schwefel_range));

  // print_minmax(10000000, spherical_range, "Spherical", &spherical);
  // print_minmax(10000000, schwefel_range, "Schwefel", &schwefel);
  // test_schwefel(-420.9687);
  // test_spherical(1);

  return 0;
}
