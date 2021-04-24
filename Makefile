CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

main: main.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $^
