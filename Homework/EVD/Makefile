# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = EVD.cpp # Assuming your QR class is in EVD.cpp
MAIN_SRC = partA.cpp
HYDROGEN_SRC = partB.cpp # Add hydrogen.cpp

# Header files
MATRIX_HDR = ../../Matrix/matrix.h

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/EVD.o
MAIN_OBJ = obj/partA.o
HYDROGEN_OBJ = obj/partB.o # Add hydrogen.o

#Text files
PART_A_OUTPUT = txt/partA.txt
PART_B_OUTPUT = txt/partB.txt

# Executable names
TARGET = exe/partA
HYDROGEN_TARGET = exe/partB # Corrected executable name

# Default target
all: folders $(TARGET) $(HYDROGEN_TARGET) psi.svg dr.svg rmax.svg
	
# Create folders
folders:
	mkdir -p txt
	mkdir -p obj
	mkdir -p exe
	mkdir -p plots

psi.svg: $(PART_B_OUTPUT)
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
	' | gnuplot	

dr.svg: $(PART_B_OUTPUT)
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

rmax.svg: $(PART_B_OUTPUT)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top left;\
		set xlabel "r [Bohr radius]";\
		set ylabel "Hartee Energy [E_h]";\
		set title "Hydrogen Atom Ground Energy For Different Radii";\
		plot \
			"$<" every :::1::1 using 1:2 with linespoints pointtype 7 title "Numerical Method",\
			-0.5 with lines title "Ground energy for r=10"\
	' | gnuplot





# Create main executable
$(TARGET): $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) 
	$(CXX) $(CXXFLAGS) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) -o $@
	./$@ > $(PART_A_OUTPUT)


# Create hydrogenAtom executable
$(HYDROGEN_TARGET): $(MATRIX_OBJ) $(QR_OBJ) $(HYDROGEN_OBJ)
	$(CXX) $(CXXFLAGS) $(MATRIX_OBJ) $(QR_OBJ) $(HYDROGEN_OBJ) -o $@
	./$@ > $(PART_B_OUTPUT)


# Compile HydrogenAtom.cpp
$(HYDROGEN_OBJ): $(HYDROGEN_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(HYDROGEN_SRC) -o $@


# Compile main.cpp
$(MAIN_OBJ): $(MAIN_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $@


# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) 
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $(MATRIX_OBJ)


# Compile EVD.cpp to EVD.o
$(QR_OBJ): $(QR_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(QR_SRC) -o $@


# Clean object files and executables
clean: 
	@rm -rf plots exe obj txt

# Phony targets
.PHONY: all clean