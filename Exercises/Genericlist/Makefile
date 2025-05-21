# Make generic list

# Compile and flags
CXX = g++
CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm


all: output

output:
	./main < input.txt > output.txt

main : main.o
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -o $(TARGET)

main.o : GenList.h main.cpp
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

clean:
	rm -f output.txt main.o main