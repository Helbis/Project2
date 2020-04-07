CXX = g++
OPTIONS = -Wall -pedantic
MODULES = matrixT.hpp matrixTG.hpp matrixTC.hpp matrixTD.hpp


output: main.cpp $(MODULES)
	$(CXX) $(OPTIONS) $< -o $@

run:
	./output
