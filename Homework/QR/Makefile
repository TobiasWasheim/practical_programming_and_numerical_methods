# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
ODE_SRC = src/ODE.cpp 
MAIN_SRC = src/main.cpp 
QR_SRC = src/QR.cpp
TIMING_SRC = src/timing.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
TIMING_OBJ = obj/timing.o
QR_OBJ = obj/QR.o
MAIN_OBJ = obj/main.o

# Targets
MAIN = exe/main
TIMING = exe/timing


# Plot factorization O(N^3)
all: folders $(MAIN) plot.svg

folders:
	mkdir -p plots
	mkdir -p exe
	mkdir -p obj

plot.svg: timing.data
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key bottom;\
		set xlabel "log(N)";\
		set ylabel "Time (arb. units)";\
		set title "Time for QR-factorization";\
		plot \
			"$<" using (log($$1)):(log($$2)) with lines title "Factorization"\
	' | gnuplot
	


# Test factorization O(N^3)
timing.data: $(TIMING)
	>$@
	for N in $$(seq 20 20 400); do \
		time --format "$$N %e" --output $@ --append \
		./$^ -size:$$N 1>exe/out 2>exe/err ;\
    done


# Create executable for main
$(MAIN): $(MAIN_OBJ) $(MATRIX_OBJ) $(QR_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Create executable for timing
$(TIMING): $(MATRIX_OBJ) $(QR_OBJ) $(TIMING_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@

# Compile timing.cpp to timing.o
$(TIMING_OBJ): $(TIMING_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile main.cpp to main.o
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile QR.cpp to QR.o
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


clean:
	@rm -rf exe obj plots out.txt timing.data
.PHONY: all clean