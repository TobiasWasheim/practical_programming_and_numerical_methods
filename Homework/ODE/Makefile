# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

RK12_SRC = RK12.cpp
RK12_HDR = RK12.h
RK12_OBJ = RK12.o

TARGET = main

all : $(TARGET)
	./main

$(TARGET) : $(RK12_OBJ) 
	$(CXX) $(CXXFLAGS) $(RK12_OBJ) -o $(TARGET)


clean:
	rm -f $(RK12_OBJ) $(TARGET)