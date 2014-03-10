bin_PROGRAMS = search
search_SOURCES = \
	src/main.cpp \
	src/random_generator.cpp \
	src/algorithm/algorithm.cpp \
	src/algorithm/genetic_algorithm.cpp \
	src/algorithm/hill_climbing_algorithm.cpp \
	src/algorithm/simulated_annealing_algorithm.cpp \
	src/individual/individual.cpp \
	src/problem/problem.cpp \
	src/problem/ackley_problem.cpp \
	src/problem/griewangk_problem.cpp \
	src/problem/rastrigin_problem.cpp \
	src/problem/rosenbrock_problem.cpp \
	src/problem/schwefel_problem.cpp \
	src/problem/spherical_problem.cpp

AM_CPPFLAGS = ${BOOST_CPPFLAGS}
AM_LDFLAGS = ${BOOST_LDFLAGS} ${BOOST_PROGRAM_OPTIONS_LIB}
