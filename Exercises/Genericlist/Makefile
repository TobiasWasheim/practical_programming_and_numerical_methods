# Make generic list

# Compile and flags
CXX = g++
CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm

# Source file
MAIN_SRC = main.cpp

# Header files
GENLIST_HDR = GenList.h

# Object file
MAIN_OBJ = main.o

# Executable name
TARGET = main

# Default target
all: $(TARGET)
	./main < input.txt > Out.txt

$(TARGET) : $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -o $(TARGET)

$(MAIN_OBJ) : $(GENLIST_HDR) $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

clean:
	rm -f Out.txt $(MAIN_OBJ) $(TARGET)