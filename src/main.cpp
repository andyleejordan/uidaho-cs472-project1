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
	   << "Logs saved to logs/Problem.dat\n"
	   << "GNUPlot settings in logs/Problem.p\n\n"
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

  vector<shared_ptr<Problem>> problems;
  problems.emplace_back(shared_ptr<Problem>(new Ackley(po_iterations, po_goal)));
  problems.emplace_back(shared_ptr<Problem>(new Griewangk(po_iterations, po_goal)));
  problems.emplace_back(shared_ptr<Problem>(new Rastrigin(po_iterations, po_goal)));
  problems.emplace_back(shared_ptr<Problem>(new Rosenbrock(po_iterations, po_goal)));
  problems.emplace_back(shared_ptr<Problem>(new Schwefel(po_iterations, po_goal)));
  problems.emplace_back(shared_ptr<Problem>(new Spherical(po_iterations, po_goal)));

  for (const auto problem_name : po_problems) {
    auto problem = *find_if(problems.begin(), problems.end(),
			    [problem_name](const shared_ptr<Problem>& it)->bool
			    { return it->compare(problem_name); });
    assert(problem != nullptr);
    Genetic algorithm(*problem);
    const Individual solution = algorithm.solve();
    cout << problem->represent() << solution.represent()
	 << "Raw fitness: " << solution.fitness << '\n' << endl;
  }
  return 0;
}
