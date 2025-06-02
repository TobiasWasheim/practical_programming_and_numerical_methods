# Makefile for compiling integration.cpp with g++ and running tests

# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
QUAD_SRC = integration.cpp
MAIN_SRC = main.cpp

# Object files
QUAD_OBJ = obj/integration.o
MAIN_OBJ = obj/main.o

# Executable files
MAIN = exe/main


# Default target
all: folders $(MAIN) plots

plots: erfPrecision.svg erfValue.svg

folders:
	mkdir -p plots
	mkdir -p exe
	mkdir -p obj

# Make a plot of errorfunction values and their tabulated values
erfPrecision.svg: 
	mkdir -p plots
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set logscale xy; \
		set key left;\
		set xlabel "acc";\
		set ylabel "erf(1)";\
		set title "Error function";\
		plot \
			"data.txt" every:::1::1 using 1:2 with lines title "erf(1)"\
	' | gnuplot

erfValue.svg:
	mkdir -p plots
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key left;\
		set xlabel "x";\
		set ylabel "erf(x)";\
		set title "Error function";\
		plot \
			"data.txt" every:::0::0 with lines title "erf(x)",\
			"erf_tabulated.txt" with points pointtype 7 title "tabulated" \
	' | gnuplot

# Create executable
$(MAIN): $(MAIN_OBJ) $(QUAD_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Compile main
$(MAIN_OBJ): $(MAIN_SRC) 
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


# Compile integration.cpp to integration.o
$(QUAD_OBJ): $(QUAD_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


# Clean object files and executables
clean:
	rm -rf plots exe obj out.txt data.txt

# Phony targets
.PHONY: all clean