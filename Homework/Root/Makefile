# Compiler and flags
CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MATRIX_SRC = ../../Matrix/matrix.cpp
QR_SRC = ../QR/src/QR.cpp
ODE_SRC = ../ODE/src/ODE.cpp
NEWTON_SRC = NewtonsMethod.cpp
HYDROGEN_SRC = hydrogen.cpp
MAIN_SRC = main.cpp

# Object files
QR_OBJ = obj/QR.o
MATRIX_OBJ = obj/matrix.o
ODE_OBJ = obj/ODE.o
NEWTON_OBJ = obj/NewtonsMethod.o
HYDROGEN_OBJ = obj/hydrogen.o
MAIN_OBJ = obj/main.o

# Executable file
MAIN = exe/main

all: folders $(MAIN)

folders:
	mkdir -p exe
	mkdir -p obj

$(MAIN): $(MAIN_OBJ) $(NEWTON_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(HYDROGEN_OBJ) $(ODE_OBJ)
	$(CXX) $^ $(LDLIBS) -o $@
	./$(MAIN) > out.txt

# Compile main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# compile ODE
$(ODE_OBJ): $(ODE_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# compile hydrogen
$(HYDROGEN_OBJ): $(HYDROGEN_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# compile NewtonsMethod.cpp to NewtonsMethod.o
$(NEWTON_OBJ): $(NEWTON_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Compile QR.cpp to QR.o
$(QR_OBJ): $(QR_SRC)
	$(CXX) $(CXXFLAGS) -c $(filter %.cpp,$^) -o $@

# Clean object files and executable
clean:
	rm -rf exe obj data.txt out.txt

# Phony targets
.PHONY: all clean