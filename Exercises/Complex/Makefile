# Makefile for complex numbers exercise

# Compilers and flags
CXX = g++
CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm

# Source file
MAIN_SRC = main.cpp

# Object files
MAIN_OBJ = main.o

# Executable name
TARGET = main

# Default target
all: $(TARGET)
	./main > Out.txt

# Create executable
$(TARGET) : $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -o $(TARGET)

clean:
	rm -f Out.txt $(MAIN_OBJ) $(TARGET)