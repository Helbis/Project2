CXX = g++
OPTIONS = -Wall -pedantic
MODULES = matrix.hpp matrixG.hpp matrixC.hpp matrixD.hpp


output: main.cpp $(MODULES)
	$(CXX) $(OPTIONS) $< -o $@

run:
	./output
