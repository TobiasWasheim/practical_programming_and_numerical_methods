# Hello World

# Compiler and flags
CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm

# Source files
MAIN_SRC = main.cpp
HELLO_SRC = hello.cpp

# Header files
HELLO_HDR = hello.h

# Object files
MAIN_OBJ = main.o
HELLO_OBJ = hello.o

# Executable name
TARGET = main

all: $(TARGET) 
	./main > output.txt

$(TARGET) : $(MAIN_OBJ) $(HELLO_OBJ)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) $(HELLO_OBJ) -o $(TARGET)

$(MAIN_OBJ) : $(MAIN_SRC) $(HELLO_HDR)
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

$(HELLO_OBJ) : $(HELLO_SRC) $(HELLO_HDR)
	$(CXX) $(CXXFLAGS) -c $(HELLO_SRC) -o $(HELLO_OBJ)
clean:
	rm -f output.txt $(MAIN_OBJ) $(HELLO_OBJ) $(TARGET)

