CXXFLAGS=-std=c++11

all:
	g++ -o play.out main.cpp
	./play.out

clangall:
	clang -std=c++11 -o play main.cpp
	./play


clean:
	rm play.out
