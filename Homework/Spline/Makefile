# Compilers and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MAIN_SRC = src/main.cpp
DATA_SRC = src/data.cpp
SPLINE_SRC = src/spline.cpp

# Object files
MAIN_OBJ = obj/main.o
DATA_OBJ = obj/data.o
SPLINE_OBJ = obj/spline.o


# Executable files
MAIN = exe/main
DATA = exe/data

all: folders $(MAIN) $(DATA) lspline.svg qspline.svg

folders:
	mkdir -p exe
	mkdir -p obj
	mkdir -p plots
	mkdir -p data

lspline.svg: $(DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid; \
		set key bottom; \
		set xlabel "x"; \
		set ylabel "y"; \
		set title "Linear Interpolation of Cosine"; \
		plot \
			sin(x) with points, \
			cos(x) with points, \
			"data/data.txt" every :::0::0 using 1:2 with lines title "Linear interpolation", \
			"data/data.txt" every :::0::0 using 1:3 with lines title "Linear integration" \
	' | gnuplot

qspline.svg: 
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key bottom;\
		set xlabel "x";\
		set ylabel "y";\
		set title "Quadratic Interpolation of Cosine";\
		plot \
			cos(x) with points, \
			sin(x) with points, \
			-sin(x) with points, \
			"data/data.txt" every :::0::0 using 1:4 with lines title "Quadratic interpolation",\
			"data/data.txt" every :::0::0 using 1:5 with lines title "Quadratic integration",\
			"data/data.txt" every :::0::0 using 1:6 with lines title "Quadratic derivative"\
	' | gnuplot 




# Create executable file for main
$(MAIN): $(MAIN_OBJ) $(LSPLINE_OBJ) $(QSPLINE_OBJ) $(CSPLINE_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$@ > out.txt

# Creaet executable file for data for splines
$(DATA): $(DATA_OBJ) $(SPLINE_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$@ > data/data.txt

# Create object file for main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Create object file for data for splines
$(DATA_OBJ): $(DATA_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Create object file for linear spline
$(SPLINE_OBJ): $(SPLINE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


clean:
	rm -rf data exe obj plots out.txt data.txt