CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm
CXX = clang

all: main
	./main > output.txt
main: objects/main.o objects/Integers.o objects/Machine-Epsilon.o objects/Parts.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
objects/main.o: headers/Integers.h headers/Machine-Epsilon.h src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
objects/Parts.o: headers/Parts.h src/Parts.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
objects/Integers.o: headers/Integers.h src/Integers.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
objects/Machine-Epsilon.o: headers/Machine-Epsilon.h src/Machine-Epsilon.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
clean:
	$(RM) output.txt main objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)