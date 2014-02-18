CC=g++-4.8
LFLAGS=-Wall -std=c++11 -O3
CFLAGS=$(LFLAGS) -c
PROGRAM=search
OBJECTS=main.o individual.o random_generator.o \
	algorithm.o \
	hill_climbing_algorithm.o \
	simulated_annealing_algorithm.o \
	genetic_algorithm.o \
	problem.o \
	ackley_problem.o \
	griewangk_problem.o \
	rastrigin_problem.o \
	rosenbrock_problem.o \
	schwefel_problem.o \
	spherical_problem.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(PROGRAM) $(OBJECTS)

main.o: main.cpp individual.hpp random_generator.hpp \
	problem.hpp \
	ackley_problem.hpp \
	griewangk_problem.hpp \
	rastrigin_problem.hpp \
	rosenbrock_problem.hpp \
	schwefel_problem.hpp problem.hpp \
	spherical_problem.hpp \
	algorithm.hpp \
	genetic_algorithm.hpp \
	hill_climbing_algorithm.hpp \
	simulated_annealing_algorithm.hpp
	$(CC) $(CFLAGS) main.cpp

random_generator.o: random_generator.hpp random_generator.cpp
	$(CC) $(CFLAGS) random_generator.cpp

individual.o: individual.cpp individual.hpp random_generator.hpp
	$(CC) $(CFLAGS) individual.cpp

problem.o: problem.cpp problem.hpp individual.hpp random_generator.hpp
	$(CC) $(CFLAGS) problem.cpp

ackley_problem.o: ackley_problem.cpp ackley_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) ackley_problem.cpp

griewangk_problem.o: griewangk_problem.cpp griewangk_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) griewangk_problem.cpp

rastrigin_problem.o: rastrigin_problem.cpp rastrigin_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) rastrigin_problem.cpp

rosenbrock_problem.o: rosenbrock_problem.cpp rosenbrock_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) rosenbrock_problem.cpp

schwefel_problem.o: schwefel_problem.cpp schwefel_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) schwefel_problem.cpp

spherical_problem.o: spherical_problem.cpp spherical_problem.hpp \
	problem.hpp individual.hpp
	$(CC) $(CFLAGS) spherical_problem.cpp

algorithm.o: algorithm.cpp algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) algorithm.cpp

genetic_algorithm.o: genetic_algorithm.cpp genetic_algorithm.hpp \
	algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) genetic_algorithm.cpp

hill_climbing_algorithm.o: hill_climbing_algorithm.cpp hill_climbing_algorithm.hpp \
	algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) hill_climbing_algorithm.cpp

simulated_annealing_algorithm.o: simulated_annealing_algorithm.cpp \
	simulated_annealing_algorithm.hpp \
	algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) simulated_annealing_algorithm.cpp

clean:
	rm -f $(OBJECTS) $(PROGRAM)
