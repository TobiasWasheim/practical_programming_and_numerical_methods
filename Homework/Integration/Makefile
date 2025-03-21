# Makefile for compiling integration.cpp with g++ and running tests

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall

# Source files
INTEGR_SRC = integration.cpp

# Header file
INTEGR_HDR = integration.h

# Object files
INTEGR_OBJ = integration.o


# Default target
all:  run/IntegratedFunctions run/ErrorFunctionValues run/ErrorFunctionPrecision plots/ErrorFunctionValues.svg plots/ErrorFunctionPrecision.svg


#################################################################################

#							PART A

#################################################################################

# Make a plot of errorfunction values and their tabulated values
plots/ErrorFunctionPrecision.svg: PartA/ErrorFunctionPrecision.txt 
	mkdir -p plots
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key left;\
		set xlabel "acc";\
		set ylabel "erf(1)";\
		set title "Error function";\
		plot \
			"$<" with lines title "erf(1)"\
	' | gnuplot

plots/ErrorFunctionValues.svg: PartA/ErrorFunctionValues.txt PartA/erf_tabulated.txt
	mkdir -p plots
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key left;\
		set xlabel "x";\
		set ylabel "erf(x)";\
		set title "Error function";\
		plot \
			"$<" with lines title "erf(x)",\
			"PartA/erf_tabulated.txt" with points pointtype 7 title "tabulated" \
	' | gnuplot

# Linker for Errorfunction precision cpp file
run/ErrorFunctionPrecision: Objects/$(INTEGR_OBJ) Objects/ErrorFunctionPrecision.o
	$(CXX) $(CXXFLAGS) Objects/ErrorFunctionPrecision.o Objects/$(INTEGR_OBJ) -o $@
	./$@ > PartA/ErrorFunctionPrecision.txt

# Linker for Errorfunction values cpp file
run/ErrorFunctionValues: Objects/$(INTEGR_OBJ) Objects/ErrorFunctionValues.o
	$(CXX) $(CXXFLAGS) Objects/ErrorFunctionValues.o Objects/$(INTEGR_OBJ) -o $@
	./$@ > PartA/ErrorFunctionValues.txt

# Linker for integrated functions cpp file
run/IntegratedFunctions: Objects/$(INTEGR_OBJ) Objects/IntegratedFunctions.o
	$(CXX) $(CXXFLAGS) Objects/IntegratedFunctions.o Objects/$(INTEGR_OBJ) -o $@
	./$@ > PartA/IntegratedFunctions.txt

# Compile the object file for ErrorFunctionPrecision
Objects/ErrorFunctionPrecision.o: PartA/ErrorFunctionPrecision.cpp integration.h
	$(CXX) $(CXXFLAGS) -c PartA/ErrorFunctionPrecision.cpp -o $@

# Compile the object file for ErrorFunctionValues
Objects/ErrorFunctionValues.o: PartA/ErrorFunctionValues.cpp integration.h
	$(CXX) $(CXXFLAGS) -c PartA/ErrorFunctionValues.cpp -o $@	

# Compile the object file for IntegratedFunctions.cpp
Objects/IntegratedFunctions.o: PartA/IntegratedFunctions.cpp integration.h
	$(CXX) $(CXXFLAGS) -c PartA/IntegratedFunctions.cpp -o $@	

#################################################################################

#							INTEGRATION FILE

#################################################################################


# Compile the object file for integration 
Objects/$(INTEGR_OBJ) : $(INTEGR_SRC) $(INTEGR_HDR)
	$(CXX) $(CXXFLAGS) -c $(INTEGR_SRC) -o $@





# Clean object files and executables
clean:
	rm -f Objects/* plots/* run/* PartA/ErrorFunctionPrecision.txt PartA/ErrorFunctionValues.txt PartA/IntegratedFunctions.txt

# Phony targets
.PHONY: all clean