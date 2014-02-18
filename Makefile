CC=g++-4.8
LFLAGS=-Wall -std=c++11 -O3
CFLAGS=$(LFLAGS) -c
PROGRAM=search
OBJECTS=main.o random_generator.o individual.o problem.o ackley_problem.o spherical_problem.o rosenbrock_problem.o rastrigin_problem.o schwefel_problem.o algorithm.o hill_climbing_algorithm.o simulated_annealing_algorithm.o genetic_algorithm.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(PROGRAM) $(OBJECTS)

main.o: main.cpp random_generator.hpp ackley_problem.hpp spherical_problem.hpp rosenbrock_problem.hpp rastrigin_problem.hpp schwefel_problem.hpp problem.hpp hill_climbing_algorithm.hpp simulated_annealing_algorithm.hpp genetic_algorithm.hpp algorithm.hpp individual.hpp
	$(CC) $(CFLAGS) main.cpp

random_generator.o: random_generator.hpp random_generator.cpp
	$(CC) $(CFLAGS) random_generator.cpp

individual.o: individual.cpp individual.hpp random_generator.hpp
	$(CC) $(CFLAGS) individual.cpp

problem.o: problem.cpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) problem.cpp

ackley_problem.o: ackley_problem.cpp ackley_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) ackley_problem.cpp

spherical_problem.o: spherical_problem.cpp spherical_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) spherical_problem.cpp

rosenbrock_problem.o: rosenbrock_problem.cpp rosenbrock_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) rosenbrock_problem.cpp

rastrigin_problem.o: rastrigin_problem.cpp rastrigin_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) rastrigin_problem.cpp

schwefel_problem.o: schwefel_problem.cpp schwefel_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) schwefel_problem.cpp

algorithm.o: algorithm.cpp algorithm.hpp individual.hpp problem.hpp
	$(CC) $(CFLAGS) algorithm.cpp

hill_climbing_algorithm.o: hill_climbing_algorithm.cpp hill_climbing_algorithm.hpp algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) hill_climbing_algorithm.cpp

simulated_annealing_algorithm.o: simulated_annealing_algorithm.cpp simulated_annealing_algorithm.hpp algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) simulated_annealing_algorithm.cpp

genetic_algorithm.o: genetic_algorithm.cpp genetic_algorithm.hpp algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) genetic_algorithm.cpp


clean:
	rm -f $(OBJECTS) $(PROGRAM)
