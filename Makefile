CXX = g++
OPTIONS = -Wall -pedantic


output: main.cpp
	$(CXX) $(OPTIONS) $< -o $@
