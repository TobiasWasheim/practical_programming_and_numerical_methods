# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = ../LinearEquations/QR.cpp
MC_SRC = OLSFit.cpp # Assuming your QR class is in EVD.cpp
MAIN_SRC = main.cpp # Add main.cpp

# Header files
MATRIX_HDR = ../../Matrix/matrix.h
QR_HDR = ../LinearEquations/QR.h

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/QR.o
MC_OBJ = obj/OLSFit.o
MAIN_OBJ = obj/main.o # Add main.o

# Executable name
TARGET = main

# Default target
all: folder plot.svg

folder:
	mkdir -p exe
	mkdir -p obj
	mkdir -p plots

plot.svg: fit.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
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
$(TARGET): $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(QR_OBJ) # Add main.o
	$(CXX) $(CXXFLAGS) $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(QR_OBJ) -o $@
# Compile main
$(MAIN_OBJ): $(MAIN_SRC) $(MATRIX_HDR) # Correct dependencies
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Compile QR.cpp to QR.o
$(QR_OBJ): $(QR_SRC) $(QR_HDR)
	$(CXX) $(CXXFLAGS) -c $(QR_SRC) -o $(QR_OBJ)

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) $(VECTOR_HDR)
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $@

# Compile EVD.cpp to EVD.o
$(MC_OBJ): $(MC_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(MC_SRC) -o $(MC_OBJ)

# Clean object files and executable
clean:
	rm -f $(VECTOR_OBJ) $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(TARGET) 
	@rm -rf exe obj plots

# Phony targets
.PHONY: all clean