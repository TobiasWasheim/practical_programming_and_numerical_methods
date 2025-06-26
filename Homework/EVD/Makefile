# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = src/EVD.cpp # Assuming your QR class is in EVD.cpp
MAIN_SRC = src/main.cpp
HYDROGEN_SRC = src/HydrogenAtom.cpp # Add hydrogen.cpp

# Header files
MATRIX_HDR = ../../Matrix/matrix.h

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/EVD.o
MAIN_OBJ = obj/main.o
HYDROGEN_OBJ = obj/hydrogenAtom.o # Add hydrogen.o

# Text files
DATA = data.txt

# Executable names
MAIN = exe/main
HYDROGEN = exe/HydrogenAtom # Corrected executable name

# Default target
all: folders $(MAIN) $(HYDROGEN) psi.svg dr.svg rmax.svg
	
# Create folders
folders:
	mkdir -p obj
	mkdir -p exe
	mkdir -p plots

psi.svg: $(DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top right;\
		set xlabel "r [Bohr radius]";\
		set ylabel "f(r) [arb. unit]";\
		set title "Hydrogen Atom Ground State Wave Function";\
		plot \
			"$<" every :::2::2 using 1:2 with linespoints pointtype 7 title "Wave function for ground state",\
			"$<" every :::2::2 using 1:3 with lines title "Analytical Wave function"\
	' | gnuplot	

dr.svg: $(DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top left;\
		set yrange [-0.51:-0.41];\
		set xlabel "dr [Bohr radius]";\
		set ylabel "Hartee Energy [E_h]";\
		set title "Hydrogen Atom Ground Energy Convergence with dr";\
		plot \
			"$<" every :::0::0 using 1:2 with linespoints pointtype 7 title "Numerical Method",\
			-0.5 with lines title "Analytical Method"\
	' | gnuplot

rmax.svg: $(DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top left;\
		set yrange [-0.1:-0.55];\
		set xlabel "r [Bohr radius]";\
		set ylabel "Hartee Energy [E_h]";\
		set title "Hydrogen Atom Ground Energy For Different Radii";\
		plot \
			"$<" every :::1::1 using 1:2 with linespoints pointtype 7 title "Numerical Method",\
			-0.5 with lines title "Ground energy for r=10"\
	' | gnuplot





# Create main executable
$(MAIN): $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Create hydrogenAtom executable
$(HYDROGEN): $(MATRIX_OBJ) $(QR_OBJ) $(HYDROGEN_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(HYDROGEN) > $(DATA)

# Compile HydrogenAtom.cpp
$(HYDROGEN_OBJ): $(HYDROGEN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile main.cpp
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile EVD.cpp to EVD.o
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executables
clean: 
	@rm -rf plots exe obj txt out.txt data.txt

# Phony targets
.PHONY: all clean