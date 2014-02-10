CC=g++-4.8
LFLAGS=-Wall -std=c++11 -O3
CFLAGS=$(LFLAGS) -c
PROGRAM=search
OBJECTS=main.o individual.o problem.o spherical_problem.o schwefel_problem.o algorithm.o hill_climber_algorithm.o 

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(PROGRAM) $(OBJECTS)

main.o: main.cpp spherical_problem.hpp schwefel_problem.hpp problem.hpp hill_climber_algorithm.hpp algorithm.hpp individual.hpp
	$(CC) $(CFLAGS) main.cpp

individual.o: individual.cpp individual.hpp
	$(CC) $(CFLAGS) individual.cpp

problem.o: problem.cpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) problem.cpp

spherical_problem.o: spherical_problem.cpp spherical_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) spherical_problem.cpp

schwefel_problem.o: schwefel_problem.cpp schwefel_problem.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) schwefel_problem.cpp

algorithm.o: algorithm.cpp algorithm.hpp individual.hpp problem.hpp
	$(CC) $(CFLAGS) algorithm.cpp

hill_climber_algorithm.o: hill_climber_algorithm.cpp hill_climber_algorithm.hpp algorithm.hpp problem.hpp individual.hpp
	$(CC) $(CFLAGS) hill_climber_algorithm.cpp

clean:
	rm -f $(OBJECTS) $(PROGRAM)
