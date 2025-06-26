# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../Matrix/matrix.cpp
EVD_SRC = ../Homework/EVD/src/EVD.cpp
QR_SRC = ../Homework/QR/src/QR.cpp
EVD_SRC = ../Homework/EVD/src/EVD.cpp
INVERSE_SRC = src/InverseIteration.cpp
MAIN_SRC = src/main.cpp 

TIMINGEVD_SRC = src/timingEVD.cpp
TIMINGINVERSE_SRC = src/timingINVERSE.cpp

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/QR.o
EVD_OBJ = obj/EVD.o
INVERSE_OBJ = obj/InverseIteration.o
MAIN_OBJ = obj/main.o

TIMINGEVD_OBJ = obj/timingEVD.o
TIMINGINVERSE_OBJ = obj/timingINVERSE.o

# data files
DATA = data/timing.data

# Executable
MAIN = exe/main
TIMINGEVD = exe/timingEVD
TIMINGINVERSE = exe/timingINVERSE

all: folders $(MAIN) timing.svg psi.svg

folders:
	mkdir -p data
	mkdir -p plots
	mkdir -p obj
	mkdir -p exe

timing.svg: $(DATA)
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key bottom;\
		set xlabel "log(N)";\
		set ylabel "Time (arb. units)";\
		set title "Timing EVD vs inverse method";\
		plot \
			"$^" every:::0::0 using (log($$1)):(log($$2)) with lines title "EVD",\
			"$^" every:::1::1 using (log($$1)):(log($$2)) with lines title "Inverse"\
	' | gnuplot

psi.svg: out.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key bottom;\
		set xlabel "log(N)";\
		set ylabel "Time (arb. units)";\
		set title "Timing EVD vs inverse method";\
		plot \
			"$^" every:::0::0 using 1:2 with points pointtype 7 title "Ground wave function"\
	' | gnuplot


$(DATA): $(TIMINGEVD) $(TIMINGINVERSE)
	>$@
	for N in $$(seq 10 20 290); do \
		time --format "$$N %e" --output $@ --append \
		./$(TIMINGEVD) -size:$$N 1>exe/out 2>exe/err ;\
    done

	echo "" >> $@

	>>$@
	for N in $$(seq 10 20 350); do \
		time --format "$$N %e" --output $@ --append \
		./$(TIMINGINVERSE) -size:$$N 1>exe/out 2>exe/err ;\
    done


# Create executable
$(TIMINGEVD): $(MATRIX_OBJ) $(EVD_OBJ) $(TIMINGEVD_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@



# Create executable
$(TIMINGINVERSE): $(MATRIX_OBJ) $(QR_OBJ) $(TIMINGINVERSE_OBJ) $(INVERSE_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@



# Compile inverse
$(TIMINGEVD_OBJ): $(TIMINGEVD_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


# Compile inverse
$(TIMINGINVERSE_OBJ): $(TIMINGINVERSE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@



# Create executable
$(MAIN): $(MATRIX_OBJ) $(EVD_OBJ) $(QR_OBJ) $(EVD_OBJ) $(INVERSE_OBJ) $(MAIN_OBJ) 
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile inverse iteration
$(INVERSE_OBJ): $(INVERSE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile matrix
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile EVD
$(EVD_OBJ): $(EVD_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile QR
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@


# Clean object files and executable
clean:
	rm -rf exe obj out.txt timing.data plots