CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

all: ex1

ex1: ex1.cpp
	$(CXX) $(CXXFLAGS) -o ex1 ex1.cpp

clean:
	rm -f ex1
