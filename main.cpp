/* Copyright 2014 Andrew Schwartzmeyer
 *
 * University of Idaho - CS 472: Evolutionary Computation by Terry Soule
 *
 * Project #1 Genetic Algorithm
 *
 * This program uses C++11 extensions (array template, range-based for
 * loop, random library)
 */

#include <cstdlib>
#include <iostream>

// boost
#include <boost/program_options.hpp>

// individual
#include "individual.hpp"

// algorithms
#include "genetic_algorithm.hpp"
#include "hill_climbing_algorithm.hpp"
#include "simulated_annealing_algorithm.hpp"

// problems
#include "ackley_problem.hpp"
#include "griewangk_problem.hpp"
#include "rastrigin_problem.hpp"
#include "rosenbrock_problem.hpp"
#include "schwefel_problem.hpp"
#include "spherical_problem.hpp"

namespace po = boost::program_options;

int main(int argc, char * argv[]) {
  // setup program options
  std::string po_algorithm;
  std::vector<std::string> po_problem;
  long po_iterations;
  parameter po_goal;
  po::positional_options_description positionals;
  po::variables_map variables_map;
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("algorithm,a",
     po::value<std::string>(&po_algorithm)->default_value("genetic"),
     "choose algorithm")
    ("problem,p",
     po::value<std::vector<std::string>>(&po_problem),
     "choose problem(s)")
    ("iterations,i",
     po::value<long>(&po_iterations)->default_value(256),
     "set max iterations")
    ("goal,g",
     po::value<parameter>(&po_goal)->default_value(0), "set goal");
  try {
    po::store(po::command_line_parser(argc, argv).
	      options(desc).positional(positionals).run(), variables_map);
    if (variables_map.count("help")) {
      std::cout << "Basic Command Line Parameter App" << '\n'
		<< desc << std::endl;
      return 0;
    }
    po::notify(variables_map);
  }
  catch(std::exception& e) {
    std::cout << e.what() << '\n';
    return 1;
  }

  std::vector<Problem *> problems;
  problems.emplace_back(new Ackley(po_iterations, po_goal));
  problems.emplace_back(new Griewangk{po_iterations, po_goal});
  problems.emplace_back(new Rastrigin{po_iterations, po_goal});
  problems.emplace_back(new Rosenbrock{po_iterations, po_goal});
  problems.emplace_back(new Schwefel{po_iterations, po_goal});
  problems.emplace_back(new Spherical{po_iterations, po_goal});

  for (auto problem : problems) {
    Genetic algorithm(*problem);
    const Individual solution = algorithm.solve();
    std::cout << solution.represent() << '\n'
	      << "Raw fitness: " << problem->fitness(solution) << '\n'
	      << "Normalized fitness: " << problem->normal(solution) << std::endl;
  }
  return 0;
}
