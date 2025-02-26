CXXFLAGS = -std=c++23 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

all: Out-CommandLine.txt Out-StandardInputStream.txt Out-FileStreams.txt

Out-CommandLine.txt: CommandLine
	./$< -n 1 -n 2 -n 3 -n 4 -n 5 > $@

Out-StandardInputStream.txt: StandardInputStream
	echo 1 2 3 4 5 | ./$< > $@

Out-FileStreams.txt: FileStreams
	./$< --input input.txt --output $@


CommandLine: objects/CommandLine.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

objects/CommandLine.o: src/CommandLine.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@


StandardInputStream: objects/StandardInputStream.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

objects/StandardInputStream.o: src/StandardInputStream.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

FileStreams: objects/FileStreams.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

objects/FileStreams.o: src/FileStreams.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@




clean:
	$(RM) [Oo]ut* CommandLine StandardInputStream FileStreams objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)