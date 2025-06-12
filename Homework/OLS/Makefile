# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = ../QR/src/QR.cpp
OLS_SRC = src/OLS.cpp 
MAIN_SRC = src/main.cpp
THX_SRC = src/thx.cpp


# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/QR.o
OLS_OBJ = obj/OLS.o
MAIN_OBJ = obj/main.o 
THX_OBJ = obj/thx.o

# Executable name
MAIN = exe/main
THX = exe/thx

# Default target
all: folder files plot.svg

# Create folders
folder:
	mkdir -p exe
	mkdir -p obj
	mkdir -p plots

# Create data and output files
files: $(MAIN) $(THX)
	./$(MAIN) > out.txt
	./$(THX) > data/fit.txt

# Create plot
plot.svg: data/fit.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "Time (days)";\
		set ylabel "Activity (relative units)";\
		set title "Decay of ThX";\
		plot \
			"data/fit.txt" using 1:2 with lines title "Fit",\
			"data/DecayData.txt" every::1 using 1:2:3 with yerrorbars title "Experimental data" \
	' | gnuplot


# Executable for main
$(MAIN): $(MAIN_OBJ) $(OLS_OBJ) $(QR_OBJ) $(MATRIX_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Executable for thx
$(THX): $(THX_OBJ) $(OLS_OBJ) $(QR_OBJ) $(MATRIX_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@

# Object file for main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Object file for thx
$(THX_OBJ): $(THX_SRC) 
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Object file for ordinary least square fit method
$(OLS_OBJ): $(OLS_SRC) 
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Object file for matrix
$(MATRIX_OBJ): $(MATRIX_SRC)  
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@
# object file for QR-decomposition
$(QR_OBJ): $(QR_SRC) 
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	rm -f $(MAIN) $(THX) out.txt 
	@rm -rf exe obj plots

# Phony targets
.PHONY: all clean