# Input and output streams

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -O0 -ffast-math
LDLIBS = -lstdc++ -lm


all: Out-CommandLine.txt Out-StandardInputStream.txt Out-FileStreams.txt

Out-CommandLine.txt: CommandLine
	./$< -n 1 -n 2 -n 3 -n 4 -n 5 > $@

Out-StandardInputStream.txt: StandardInputStream
	echo 1 2 3 4 5 | ./$< > $@e clean

Out-FileStreams.txt: FileStreams
	./$< --input input.txt --output $@


CommandLine: CommandLine.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

CommandLine.o: CommandLine.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@


StandardInputStream: StandardInputStream.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

StandardInputStream.o: StandardInputStream.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

FileStreams: FileStreams.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

FileStreams.o: FileStreams.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@




clean:
	$(RM) [Oo]ut* CommandLine StandardInputStream FileStreams *.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)