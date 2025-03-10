# Makefile for Vector and Matrix classes

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
VECTOR_SRC = vector.cpp
MATRIX_SRC = matrix.cpp

# Header files
VECTOR_HDR = vector.h
MATRIX_HDR = matrix.h

# Object files
VECTOR_OBJ = vector.o
MATRIX_OBJ = matrix.o

# Executable name
TARGET = my_program

# Default target
all: $(TARGET)

# Create executable
$(TARGET): $(VECTOR_OBJ) $(MATRIX_OBJ)
	$(CXX) $(CXXFLAGS) $(VECTOR_OBJ) $(MATRIX_OBJ) -o $(TARGET)

# Compile vector.cpp to vector.o
$(VECTOR_OBJ): $(VECTOR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(VECTOR_SRC) -o $(VECTOR_OBJ)

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) $(VECTOR_HDR)
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $(MATRIX_OBJ)

# Clean object files and executable
clean:
	rm -f $(VECTOR_OBJ) $(MATRIX_OBJ) $(TARGET)

# Phony targets
.PHONY: all clean