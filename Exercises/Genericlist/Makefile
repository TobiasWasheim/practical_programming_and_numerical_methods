# Make generic list

# Compile and flags
CXX = g++
CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm




all: output

output: main

main : main.o
	$(CXX) $(CXXFLAGS) main.o -o $@
	./$@ < input.txt > out.txt

main.o : GenList.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

clean:
	rm -f out.txt main.o main