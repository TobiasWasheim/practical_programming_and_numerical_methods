# Makefile for Vector, Matrix, and QR classes

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
VECTOR_SRC = ../Matrix/vector.cpp
MATRIX_SRC = ../Matrix/matrix.cpp
QR_SRC = ../LinearEquations/QR.cpp
MC_SRC = OLSFit.cpp # Assuming your QR class is in EVD.cpp
MAIN_SRC = main.cpp # Add main.cpp

# Header files
VECTOR_HDR = ../Matrix/vector.h
MATRIX_HDR = ../Matrix/matrix.h
QR_HDR = ../LinearEquations/QR.h

# Object files
VECTOR_OBJ = vector.o
MATRIX_OBJ = matrix.o
QR_OBJ = QR.o
MC_OBJ = OLSFit.o
MAIN_OBJ = main.o # Add main.o

# Executable name
TARGET = main

# Default target
all: plot.svg

plot.svg: fit.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key right;\
		set xlabel "Time (days)";\
		set ylabel "Activity (relative units)";\
		set title "Decay of ThX";\
		plot \
			"fit.txt" every::4 using 1:2 with lines title "Fit",\
			"DecayData.txt" every::1 using 1:2:3 with yerrorbars title "Experimental data" \
	' | gnuplot

fit.txt: main
	./main > fit.txt

# Create executable
$(TARGET): $(VECTOR_OBJ) $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(QR_OBJ) # Add main.o
	$(CXX) $(CXXFLAGS) $(VECTOR_OBJ) $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(QR_OBJ) -o $(TARGET) 
# Compile main
$(MAIN_OBJ): $(MAIN_SRC) $(VECTOR_HDR) $(MATRIX_HDR) # Correct dependencies
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Compile QR.cpp to QR.o
$(QR_OBJ): $(QR_SRC) $(QR_HDR)
	$(CXX) $(CXXFLAGS) -c $(QR_SRC) -o $(QR_OBJ)

# Compile vector.cpp to vector.o
$(VECTOR_OBJ): $(VECTOR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(VECTOR_SRC) -o $(VECTOR_OBJ)

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) $(VECTOR_HDR)
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $(MATRIX_OBJ)

# Compile EVD.cpp to EVD.o
$(MC_OBJ): $(MC_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(MC_SRC) -o $(MC_OBJ)

# Clean object files and executable
clean:
	rm -f $(VECTOR_OBJ) $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(TARGET)

# Phony targets
.PHONY: all clean