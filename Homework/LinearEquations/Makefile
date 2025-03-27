# Makefile for Vector, Matrix, and QR classes

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
VECTOR_SRC = ../Matrix/vector.cpp
MATRIX_SRC = ../Matrix/matrix.cpp
QR_SRC = QR.cpp # Assuming your QR class is in qr.cpp
MAIN_SRC = main.cpp
TIMING_SRC = timing.cpp

# Header files
VECTOR_HDR = ../Matrix/vector.h
MATRIX_HDR = ../Matrix/matrix.h

# Object files
VECTOR_OBJ = vector.o
MATRIX_OBJ = matrix.o
QR_OBJ = QR.o
MAIN_OBJ = main.o
TIMING_OBJ = timing.o

# Executable name
MAIN = main
TIMING = timing

# Data files
TIMING_DATA = timing.data

# Plot
PLOT = plot.svg

# Default target
all: $(PLOT) $(MAIN)

# Plot factorization O(N^3)
$(PLOT): $(TIMING_DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key bottom;\
		set xlabel "log(N)";\
		set ylabel "Time (arb. units)";\
		set title "Time for QR-factorization";\
		plot \
			"$<" using (log($$1)):(log($$2)) with lines title "Factorization"\
	' | gnuplot

# Test factorization O(N^3)
$(TIMING_DATA): $(TIMING)
	>$@
	for N in $$(seq 100 20 200); do \
		time --format "$$N %e" --output $@ --append \
		./$(TIMING) -size:$$N 1>out 2>err ;\
    done
# Create executable for timing
$(TIMING): $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(TIMING_OBJ)
	$(CXX) $(CXXFLAGS) $(TIMING_OBJ) $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) -o $@

# Create executable for main
$(MAIN): $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) -o $@
	./main > Out.txt

# compile timing.cpp to timing.o
$(TIMING_OBJ): $(TIMING_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(TIMING_SRC) -o $@	

# compile main.cpp to main.o
$(MAIN_OBJ): $(MAIN_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $@	

# Compile vector.cpp to vector.o
$(VECTOR_OBJ): $(VECTOR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(VECTOR_SRC) -o $(VECTOR_OBJ)

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) $(VECTOR_HDR)
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $(MATRIX_OBJ)

# Compile qr.cpp to qr.o
$(QR_OBJ): $(QR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(QR_SRC) -o $(QR_OBJ)

# Clean object files and executable
clean:
	rm -f $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN) $(MAIN_OBJ) $(TIMING_OBJ) $(TIMING) $(PLOT) $(TIMING_DATA) err

# Phony targets
.PHONY: all clean