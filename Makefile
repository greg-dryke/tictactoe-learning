CXXFLAGS=-std=c++11

all:
	g++ -o play main.cpp
	./play

clangall:
	clang -std=c++11 -o play main.cpp
	./play


clean:
	rm play
