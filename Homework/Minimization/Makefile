# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = ../LinearEquations/QR.cpp
NEWTON_SRC = src/newton.cpp
GRADIENT_SRC = src/gradient.cpp
HESSIAN_SRC = src/hessian.cpp
MAIN_SRC = src/main.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/QR.o
NEWTON_OBJ = obj/newton.o
GRADIENT_OBJ = obj/gradient.o
HESSIAN_OBJ = obj/hessian.o
MAIN_OBJ = obj/main.o

# Executable files
MAIN = exe/main

all: folders $(MAIN) experimental.svg 

folders:
	mkdir -p exe
	mkdir -p obj
	mkdir -p plots

fit.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "Energy (GeV)";\
			set ylabel "Signal (certain units)";\
			set title "The Higgs Particle";\
			plot \
				"new_data.txt" using 1:2 with lines title "Fit" \
		' | gnuplot

experimental.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "Energy (GeV)";\
		set ylabel "Signal (certain units)";\
		set title "The Higgs Particle";\
		plot \
			"data.txt" every::1 using 1:2:3 with yerrorbars title "Experimental data", \
			"new_data.txt" using 1:2 with lines title "Fit" \
	' | gnuplot

# Create executable
$(MAIN): $(MATRIX_OBJ) $(QR_OBJ) $(NEWTON_OBJ) $(GRADIENT_OBJ) $(HESSIAN_OBJ) $(MAIN_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Compile matrix
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile QR-decomposition
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile Newton
$(NEWTON_OBJ): $(NEWTON_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile gradient
$(GRADIENT_OBJ): $(GRADIENT_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile hessian
$(HESSIAN_OBJ): $(HESSIAN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	@rm -rf exe obj plots out.txt new_data.txt

# Phony targets
.PHONY: all clean

