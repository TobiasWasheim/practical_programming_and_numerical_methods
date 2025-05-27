# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
MC_SRC = MonteCarlo.cpp
MAIN_SRC = main.cpp 
OLS_SRC = ../OrdinaryLeastSquares/OLS.cpp
QR_SRC = ../LinearEquations/QR.cpp


# Object files
MATRIX_OBJ = obj/matrix.o
MC_OBJ = obj/MonteCarlo.o
OLS_OBJ = obj/OLS.o
QR_OBJ = obj/QR.o
MAIN_OBJ = obj/main.o

# Executable name
MAIN = exe/main

# Default target
all: folders $(MAIN) plots

plots: unitCircleError.svg unitCircleValue.svg gaussianValue.svg gaussianError.svg functionValue.svg functionError.svg

folders:
	mkdir -p obj
	mkdir -p exe
	mkdir -p plots

functionValue.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "N";\
		set ylabel "Value of integral";\
		set title "Monte Carlo Integration of the Given Function";\
		plot \
			"data.txt" every :::1::1 using 1:2 with points pointtype 7 title "Integral of the given Function",\
			1.3932039296856768591842462603255 with lines title "Exact value" \
	' | gnuplot

functionError.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "N";\
			set ylabel "Error";\
			set title "Plain Monte Carlo Error for the Given Function";\
			plot \
				"data.txt" every :::1::1 using 1:3 with points pointtype 7 title "Errors",\
				"data.txt" every :::1::1 using 1:4 with lines title "1/sqrt(N) fit" \
		' | gnuplot

unitCircleValue.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "N";\
		set ylabel "Value of integral";\
		set title "Monte Carlo Integration of Unit Circle";\
		plot \
			"data.txt" every :::0::0 using 1:2 with points pointtype 7 title "Area of unit circle",\
			pi with lines title "Exact value" \
	' | gnuplot


unitCircleError.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "N";\
			set ylabel "Error";\
			set title "Plain Monte Carlo Error for Unit Circle";\
			plot \
				"data.txt" every :::0::0 using 1:3 with points pointtype 7 title "Errors",\
				"data.txt" every :::0::0 using 1:4 with lines title "1/sqrt(N) fit" \
		' | gnuplot

gaussianValue.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key right;\
		set xlabel "N";\
		set ylabel "Value of integral";\
		set title "Monte Carlo Integral of Gaussian Function";\
		plot \
			"data.txt" every :::0::0 using 1:5 with points pointtype 7 title "Area of gaussian function",\
			pi with lines title "Exact value" \
	' | gnuplot


gaussianError.svg:
	echo '\
			set terminal $(subst .,,$(suffix $@)) background "white"; \
			set output "plots/$@"; \
			set grid;\
			set key right;\
			set xlabel "N";\
			set ylabel "Error";\
			set title "Plain Monte Carlo Error for Gaussian Function";\
			plot \
				"data.txt" every :::0::0 using 1:6 with points pointtype 7 title "Errors",\
				"data.txt" every :::0::0 using 1:7 with lines title "1/sqrt(N) fit" \
		' | gnuplot





# Create executable
$(MAIN): $(MATRIX_OBJ) $(MC_OBJ) $(MAIN_OBJ) $(OLS_OBJ) $(QR_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$@ > out.txt

# Compile main
$(MAIN_OBJ): $(MAIN_SRC) 
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

#Compile QR.cpp to QR.o
$(QR_OBJ): $(QR_SRC) 
	$(CXX) $(CXXFLAGS) -c $^ -o $@

#Comple OLS.cpp to OLS.o
$(OLS_OBJ): $(OLS_SRC) 
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# Compile EVD.cpp to EVD.o
$(MC_OBJ): $(MC_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	@rm -rf exe obj plots data.txt out.txt

# Phony targets
.PHONY: all clean