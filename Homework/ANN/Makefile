# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = ../LinearEquations/QR.cpp
NEWTON_SRC = ../Minimization/src/newton.cpp
GRADIENT_SRC = ../Minimization/src/gradient.cpp
HESSIAN_SRC = ../Minimization/src/hessian.cpp
ANN_SRC = ANN.cpp
MAIN_SRC = main.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = QR.o
NEWTON_OBJ = obj/newton.o
GRADIENT_OBJ = obj/gradient.o
HESSIAN_OBJ = obj/hessian.o
ANN_OBJ = obj/ANN.o
MAIN_OBJ = obj/main.o

# Executable
MAIN = exe/main

all: folders $(MAIN) plot.svg

folders:
	mkdir -p exe
	mkdir -p plots
	mkdir -p obj

plot.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "Energy (GeV)";\
			set ylabel "Signal (certain units)";\
			set title "Neural Network fit";\
			plot \
				"data.txt" using 1:2 with points title "NN", \
				"data.txt" using 1:3 with lines title "f(x)"\
		' | gnuplot

# Create executable
$(MAIN): $(MATRIX_OBJ) $(QR_OBJ) $(NEWTON_OBJ) $(GRADIENT_OBJ) $(HESSIAN_OBJ) $(ANN_OBJ) $(MAIN_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt


# Compile matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile QR decomp
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile newton
$(NEWTON_OBJ): $(NEWTON_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile gradient
$(GRADIENT_OBJ): $(GRADIENT_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile hessian
$(HESSIAN_OBJ): $(HESSIAN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Comple ANN
$(ANN_OBJ): $(ANN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	rm -rf plots exe obj data.txt out.txt

# Phony targets
.PHONY: all clean