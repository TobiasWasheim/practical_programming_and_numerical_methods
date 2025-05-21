CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

all: main
	./main > output.txt
	cat output.txt

main: main.o matrix.o
	$(CXX) $(CXXFLAGS) main.o matrix.o -o $@

main.o: main.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@


matrix.o: matrix.h matrix.cpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp -o $@

clean:
	rm -f output.txt *.o main output.txt