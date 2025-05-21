# Makefile for Matrix, and QR classes

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra




# Source files
QR_SRC = QR.cpp
MATRIX_SRC = ../../Matrix/matrix.cpp
TIMING_SRC = timing.cpp
PART_A_SRC = partA.cpp
PART_B_SRC = partB.cpp
PART_C_SRC = partC.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
TIMING_OBJ = obj/timing.o
QR_OBJ = obj/QR.o
PART_A_OBJ = obj/partA.o
PART_B_OBJ = obj/partB.o
PART_C_OBJ = obj/partC.o

# Header files
QR_HDR = QR.h
MATRIX_HDR = ../../Matrix/matrix.h


# Targets
PART_A_TARGET = exe/partA
PART_B_TARGET = exe/partB
PART_C_TARGET = exe/partC
TIMING_TARGET = exe/timing




# Plot factorization O(N^3)
all: folders $(PART_A_TARGET) $(PART_B_TARGET) $(PART_C_TARGET) plot.svg
	./$(PART_A_TARGET) > output.txt
	./$(PART_B_TARGET) >> output.txt
	./$(PART_C_TARGET) >> output.txt
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
timing.data: $(TIMING_TARGET)
	>$@
	for N in $$(seq 100 20 400); do \
		time --format "$$N %e" --output $@ --append \
		./$(TIMING_TARGET) -size:$$N 1>exe/out 2>exe/err ;\
    done



$(PART_A_TARGET): $(PART_A_OBJ) $(MATRIX_OBJ) $(QR_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PART_B_TARGET): $(PART_B_OBJ) $(MATRIX_OBJ) $(QR_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PART_C_TARGET): $(PART_C_OBJ) $(MATRIX_OBJ) $(QR_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TIMING_TARGET): $(MATRIX_OBJ) $(QR_OBJ) $(TIMING_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@




$(TIMING_OBJ): $(TIMING_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@	

$(PART_A_OBJ): $(PART_A_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PART_B_OBJ): $(PART_B_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PART_C_OBJ): $(PART_C_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(QR_OBJ): $(QR_SRC) $(QR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f matrix.o timing.o main.o timing.data QR.o plot.svg out.txt output.txt main timing out err partAoutput.txt partBoutput.txt partA partB
	@rm -rf exe obj plots txt
.PHONY: all clean