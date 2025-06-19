# Compilers and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MAIN_SRC = src/main.cpp
SPLINE_SRC = src/spline.cpp

# Object files
MAIN_OBJ = obj/main.o
SPLINE_OBJ = obj/spline.o


# Executable files
MAIN = exe/main

all: folders $(MAIN) plots

plots: lspline.svg qspline.svg cspline.svg gnuplot.svg

folders:
	mkdir -p exe
	mkdir -p obj
	mkdir -p plots
	mkdir -p data

lspline.svg:
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid; \
		set key top; \
		set xlabel "x"; \
		set ylabel "y"; \
		set yrange[-2:4]; \
		set title "Linear Interpolation of exp(-x^2) and its integral"; \
		plot \
			exp(-x*x) with lines, \
			0.5 * sqrt(pi)*(erf(x)+erf(5)) with lines, \
			"data/data.txt" every :::0::0 using 1:2 with points pointtype 7 title "Linear interpolation", \
			"data/data.txt" every :::0::0 using 1:3 with points pointtype 7 title "Linear integration" \
	' | gnuplot

qspline.svg: 
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top;\
		set xlabel "x";\
		set ylabel "y";\
		set yrange[-2:4]; \
		set title "Quadratic Interpolation of exp(-x^2), its derivative, and integral";\
		plot \
			exp(-x*x) with lines, \
			-2 * x * exp(-x*x) with lines, \
			0.5*sqrt(pi)*(erf(x)+erf(5)) with lines, \
			"data/data.txt" every :::1::1 using 1:2 with points pointtype 7 title "Quadratic interpolation",\
			"data/data.txt" every :::1::1 using 1:3 with points pointtype 7 title "Quadratic derivative",\
			"data/data.txt" every :::1::1 using 1:4 with points pointtype 7 title "Quadratic integration"\
	' | gnuplot 

cspline.svg: 
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top;\
		set xlabel "x";\
		set ylabel "y";\
		set yrange[-2:4]; \
		set title "Cubic Interpolation of Cosine";\
		plot \
			exp(-x*x) with lines, \
			-2 * x * exp(-x*x) with lines, \
			0.5*sqrt(pi)*(erf(x)+erf(5)) with lines, \
			"data/data.txt" every :::2::2 using 1:2 with points pointtype 7 title "Cubic interpolation",\
			"data/data.txt" every :::2::2 using 1:3 with points pointtype 7 title "Cubic derivative",\
			"data/data.txt" every :::2::2 using 1:4 with points pointtype 7 title "Cubic integration"\
	' | gnuplot 

gnuplot.svg: 
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key top;\
		set xlabel "x";\
		set ylabel "y";\
		set xrange[-5:5];\
		set yrange[-2:4]; \
		set title "Cubic Interpolation of Cosine";\
		plot \
			"data/data.txt" every :::3::3 using 1:2 smooth csplines title "Gnuplot cspline", \
			"data/data.txt" every :::2::2 using 1:2 with points pointtype 7 title "My routine" \
	' | gnuplot 


# Create executable file for main
$(MAIN): $(MAIN_OBJ) $(SPLINE_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@
	./$@ > out.txt

# Create object file for main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Create object file for linear spline
$(SPLINE_OBJ): $(SPLINE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


clean:
	rm -rf data exe obj plots out.txt