CC=g++-4.8
CFLAGS=-Wall -std=c++11
SOURCES=main.cpp
EXECUTABLE=search

all: $(SOURCES)
	$(CC) $(CFLAGS) -O3 $(SOURCES) -o $(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS) -ggdb $(SOURCES) -o $(EXECUTABLE)

push: $(SOURCES)
	rsync -rl $(SOURCES) Makefile slartibartfast.schwartzmeyer.us:project_1a
