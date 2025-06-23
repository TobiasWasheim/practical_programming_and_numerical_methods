# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../Matrix/matrix.cpp
EVD_SRC = ../Homework/EVD/src/EVD.cpp
QR_SRC = ../Homework/QR/src/QR.cpp
EVD_SRC = ../Homework/EVD/src/EVD.cpp
INVERSE_SRC = InverseIteration.cpp
MAIN_SRC = main.cpp 

# Object files
MATRIX_OBJ = obj/matrix.o
QR_OBJ = obj/QR.o
EVD_OBJ = obj/EVD.o
INVERSE_OBJ = obj/InverseIteration.o
MAIN_OBJ = obj/main.o

# Executable
MAIN = exe/main

all: folders $(MAIN)

folders:
	mkdir -p obj
	mkdir -p exe

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
	rm -rf exe obj out.txt