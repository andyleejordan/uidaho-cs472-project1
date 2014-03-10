/* Copyright 2014 Andrew Schwartzmeyer
 *
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 *
 * Project #1 Genetic Algorithm
 *
 * This program uses C++11 extensions (array template, range-based for
 * loop, random library)
 */

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>

// boost
#include <boost/program_options.hpp>

// aliases
#include "aliases.hpp"

// individual
#include "individual/individual.hpp"

// algorithms
#include "algorithm/algorithm.hpp"
#include "algorithm/genetic_algorithm.hpp"
#include "algorithm/hill_climbing_algorithm.hpp"
#include "algorithm/simulated_annealing_algorithm.hpp"
#include "algorithm/mutator/mutator.hpp"
#include "algorithm/mutator/mutator_creep.hpp"
#include "algorithm/mutator/mutator_gaussian.hpp"
#include "algorithm/mutator/mutator_jumping.hpp"

// problems
#include "problem/problem.hpp"
#include "problem/ackley_problem.hpp"
#include "problem/griewangk_problem.hpp"
#include "problem/rastrigin_problem.hpp"
#include "problem/rosenbrock_problem.hpp"
#include "problem/schwefel_problem.hpp"
#include "problem/spherical_problem.hpp"

int main(int argc, char * argv[]) {
  namespace po = boost::program_options;
  using namespace std;
  using aliases::parameter;
  using namespace algorithm;
  using namespace problem;
  // setup program options
  string po_algorithm;
  vector<string> po_problems;
  long po_iterations;
  parameter po_goal;
  po::positional_options_description positionals;
  po::variables_map variables_map;
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "produce help message")
    ("algorithm,a",
     po::value<string>(&po_algorithm)->default_value("Genetic"),
     "choose algorithm, currently unimplemented")
    ("problem,p",
     po::value<vector<string>>(&po_problems),
     "choose problem(s), must be Title case, defaults to all")
    ("mutator,m",
     po::value<string>(&po_mutator)->default_value("Jumping"),
     "choose mutator, creep, gaussian, jumping")
    ("iterations,i",
     po::value<long>(&po_iterations)->default_value(256),
     "set max iterations/generations")
    ("goal,g",
     po::value<parameter>(&po_goal)->default_value(0),
     "set goal, default will run until iterations is exhausted");
  try {
    po::store(po::command_line_parser(argc, argv).
	      options(desc).positional(positionals).run(), variables_map);
    if (variables_map.count("help")) {
      cout << "Search algorithms implemented in C++ by Andrew Schwartzmeyer\n\n"
	   << "Code located at https://github.com/andschwa/uidaho-cs472-project1\n\n"
	   << "Algorithms: Genetic, HillClimbing, and SimulatedAnnealing\n\n"
	   << "Problems: Ackley, Griewangk, Rastrigin, Rosenbrock, Schwefel, and Spherical\n\n"
	   << "Mutators: Creep, Gaussian, Jumping"
	   << "Logs saved to logs/<Problem>.dat\n"
	   << "GNUPlot settings in logs/<Problem>.p\n\n"
	   << desc << endl;
      return 0;
    }
    po::notify(variables_map);
    // add all problems if none specified
    if (po_problems.size() == 0) {
      po_problems.emplace_back("Ackley");
      po_problems.emplace_back("Griewangk");
      po_problems.emplace_back("Rastrigin");
      po_problems.emplace_back("Rosenbrock");
      po_problems.emplace_back("Schwefel");
      po_problems.emplace_back("Spherical");
    }
  }
  catch(exception& e) {
    cout << e.what() << '\n';
    return 1;
  }

  // setup mutator
  unique_ptr<const Mutator> working_mutator;
  if (po_mutator.compare("creep") == 0 || po_mutator.compare("Creep") == 0)
    working_mutator = unique_ptr<const Mutator>(new mutator::Creep());
  else if (po_mutator.compare("gaussian") == 0 || po_mutator.compare("Gaussian") == 0)
    working_mutator = unique_ptr<const Mutator>(new mutator::Gaussian());
  else if (po_mutator.compare("jumping") == 0 || po_mutator.compare("Jumping") == 0)
    working_mutator = unique_ptr<const Mutator>(new mutator::Jumping());


  // setup each problem and run the GA on it
  unique_ptr<Problem> working_problem;
  for (const string name : po_problems) {
    // Ugly replace of switch(name), better than find_if
    if (name.compare("Ackley") == 0 || name.compare("ackley") == 0)
      working_problem = unique_ptr<Problem>(new Ackley(po_iterations, po_goal));
    else if (name.compare("Griewangk") == 0 || name.compare("griewangk") == 0)
      working_problem = unique_ptr<Problem>(new Griewangk(po_iterations, po_goal));
    else if (name.compare("Rastrigin") == 0 || name.compare("rastrigin") == 0)
      working_problem = unique_ptr<Problem>(new Rastrigin(po_iterations, po_goal));
    else if (name.compare("Rosenbrock") == 0 || name.compare("rosenbrock") == 0)
      working_problem = unique_ptr<Problem>(new Rosenbrock(po_iterations, po_goal));
    else if (name.compare("Schwefel") == 0 || name.compare("schwefel") == 0)
      working_problem = unique_ptr<Problem>(new Schwefel(po_iterations, po_goal));
    else if (name.compare("Spherical") == 0 || name.compare("spherical") == 0)
      working_problem = unique_ptr<Problem>(new Spherical(po_iterations, po_goal));
    // Run GA on problem
    if (working_problem != nullptr) {
      Genetic algorithm(*working_problem, *working_mutator, working_recombinator);
      const Individual solution = algorithm.solve();
      cout << working_problem->represent() << solution.represent()
	   << "Raw fitness: " << solution.fitness << '\n' << endl;
    }
  }
  return 0;
}
