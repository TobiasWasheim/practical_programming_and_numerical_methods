# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
GRADIENT_SRC = ../Min/src/gradient.cpp
QNEWTON_SRC = src/qnewton.cpp
ANN_SRC = src/ANN.cpp
MAIN_SRC = src/main.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
GRADIENT_OBJ = obj/gradient.o
QNEWTON_OBJ = obj/qnewton.o
ANN_OBJ = obj/ANN.o
MAIN_OBJ = obj/main.o

# Executable
MAIN = exe/main

all: folders $(MAIN) plots

plots: partA.svg first_derivative.svg second_derivative.svg integral.svg

folders:
	mkdir -p data
	mkdir -p exe
	mkdir -p plots
	mkdir -p obj

partA.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "x";\
			set ylabel "y";\
			set xrange[1:-1];\
			set title "Neural Network fit of f(x) = cos(5x-1) e^{-x^2}";\
			plot \
				"data/data.txt" every :::0::0 using 1:2 with points title "Neural network solution", \
				cos(5 * x - 1) * exp(-x*x) with lines title "Exact solution" \
		' | gnuplot

first_derivative.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "x";\
			set ylabel "y";\
			set xrange[5:-5];\
			set yrange[3:-3];\
			set title "Neural Network fit of f(x) = cos(2x) first derivative";\
			plot \
				"data/data.txt" every :::1::1 using 1:2 with points title "Neural network first derivative solution", \
				-2 * sin(2*x) with lines title "Analytical first derivative solution", \
		' | gnuplot

second_derivative.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "x";\
			set ylabel "y";\
			set xrange[5:-5];\
			set yrange[5.5:-5.5];\
			set title "Neural Network fit of f(x) = cos(2x) second derivative";\
			plot \
				"data/data.txt" every :::1::1 using 1:3 with points title "Neural network second derivative solution", \
				-4 * cos(2*x) with lines title "Analytical double derivative solution" \
		' | gnuplot

integral.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "x";\
			set ylabel "y";\
			set xrange[5:-5];\
			set yrange[1:-1];\
			set title "Neural Network fit of f(x) = cos(2x) integral";\
			plot \
				"data/data.txt" every :::1::1 using 1:4 with points title "Neural network integral solution", \
				0.5 * sin(2*x) with lines title "Analytical integral solution" \
		' | gnuplot

# Create executable
$(MAIN): $(MATRIX_OBJ) $(GRADIENT_OBJ) $(ANN_OBJ) $(MAIN_OBJ) $(QNEWTON_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt


# Compile matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile gradient
$(GRADIENT_OBJ): $(GRADIENT_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile qnewton
$(QNEWTON_OBJ): $(QNEWTON_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile ANN
$(ANN_OBJ): $(ANN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	rm -rf plots exe obj data out.txt

# Phony targets
.PHONY: all clean