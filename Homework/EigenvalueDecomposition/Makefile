# Makefile for Vector, Matrix, and QR classes

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
VECTOR_SRC = ../Matrix/vector.cpp
MATRIX_SRC = ../Matrix/matrix.cpp
QR_SRC = EVD.cpp # Assuming your QR class is in EVD.cpp
MAIN_SRC = main.cpp # Add main.cpp

# Header files
VECTOR_HDR = ../Matrix/vector.h
MATRIX_HDR = ../Matrix/matrix.h

# Object files
VECTOR_OBJ = vector.o
MATRIX_OBJ = matrix.o
QR_OBJ = EVD.o
MAIN_OBJ = main.o # Add main.o

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Create executable
$(TARGET): $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) # Add main.o
	$(CXX) $(CXXFLAGS) $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) -o $(TARGET) # Add main.o

# Compile main
$(MAIN_OBJ): $(MAIN_SRC) $(VECTOR_HDR) $(MATRIX_HDR) # Correct dependencies
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Compile vector.cpp to vector.o
$(VECTOR_OBJ): $(VECTOR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(VECTOR_SRC) -o $(VECTOR_OBJ)

# Compile matrix.cpp to matrix.o
$(MATRIX_OBJ): $(MATRIX_SRC) $(MATRIX_HDR) $(VECTOR_HDR)
	$(CXX) $(CXXFLAGS) -c $(MATRIX_SRC) -o $(MATRIX_OBJ)

# Compile EVD.cpp to EVD.o
$(QR_OBJ): $(QR_SRC) $(VECTOR_HDR) $(MATRIX_HDR)
	$(CXX) $(CXXFLAGS) -c $(QR_SRC) -o $(QR_OBJ)

# Clean object files and executable
clean:
	rm -f $(VECTOR_OBJ) $(MATRIX_OBJ) $(QR_OBJ) $(MAIN_OBJ) $(TARGET)

# Phony targets
.PHONY: all clean