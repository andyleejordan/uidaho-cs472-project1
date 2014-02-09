CC=g++-4.8
CFLAGS=-Wall -std=c++11 -O3
PROGRAM=search
OBJECTS=main.o algorithm.o hill_climber_algorithm.o spherical_problem.o problem.o individual.o
SOURCES=main.cpp algorithm.cpp hill_climber_algorithm.cpp spherical_problem.cpp problem.cpp individual.cpp


all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean:
	rm -f $(OBJECTS) $(PROGRAM)

depend:
	makedepend -- $(CFLAGS) -- $(SOURCES)
