# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
ODE_SRC = ODE.cpp 
MAIN_SRC = main.cpp 

# Object files
MATRIX_OBJ = obj/matrix.o
ODE_OBJ = obj/ODE.o
MAIN_OBJ = obj/main.o 

# Executable name
MAIN = exe/main

# Default target
all: folders $(MAIN) plots

plots: HarmonicOscillator.svg equatorial_part_B1.svg equatorial_part_B2.svg equatorial_part_B3.svg
	
folders:
	mkdir -p obj
	mkdir -p exe
	mkdir -p plots

HarmonicOscillator.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "Time (arb. unit)";\
		set ylabel "y (arb. unit)";\
		set title "Harmonic Oscillator  with Conditions u(0) = 1, u'\''(0) = 0";\
		plot \
			"data.txt" every :::0::0 using 1:2 with lines title "Displacement",\
			"data.txt" every :::0::0 using 1:3 with lines title "Velocity" \
	' | gnuplot

equatorial_part_B1.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "φ azimuthal angle (arb. unit)";\
		set ylabel "u = 1/r (arb. unit)";\
		set title "Equatorial Equation with Conditions ε = 0, u(0) = 0, u'\''(0) = 0";\
		plot \
			"data.txt" every :::1::1 using 1:2 with lines title "u(φ)", \
	' | gnuplot

equatorial_part_B2.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "cos(φ), cosine of azimuthal angle (arb. unit)";\
		set ylabel "sin(u) (arb. unit)";\
		set title "Equatorial Equation with Conditions ε = 0, u(0) = 0, u'\''(0) = -0.5";\
		plot \
			"data.txt" every :::2::2 using (1/$$2)*cos($$1):(1/$$2)*sin($$1) with lines title "u(φ)", \
	' | gnuplot

equatorial_part_B3.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "cos(φ), cosine of azimuthal angle (arb. unit)";\
		set ylabel "sin(u) (arb. unit)";\
		set title "Equatorial Equation with conditions ε = 0.01, u(0) = 0, u'\''(0) = -0.5";\
		plot \
			"data.txt" every :::3::3 using (1/$$2)*cos($$1):(1/$$2)*sin($$1) with lines title "u(φ)", \
	' | gnuplot

# Create executable
$(MAIN): $(MATRIX_OBJ) $(ODE_OBJ) $(MAIN_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile EVD.cpp to EVD.o
$(ODE_OBJ): $(ODE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	rm -rf plots exe obj data.txt out.txt

# Phony targets
.PHONY: all clean