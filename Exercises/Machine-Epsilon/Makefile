CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm
CXX = clang

all: Out.txt

Out.txt: main.exe
	./main.exe > Out.txt
main.exe: Objects/main.o Objects/Integers.o Objects/Machine-Epsilon.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
Objects/main.o: Includes/Integers.h Includes/Machine-Epsilon.h main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
Objects/Integers.o: Includes/Integers.h Includes/Integers.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
Objects/Machine-Epsilon.o: Includes/Machine-Epsilon.h Includes/Machine-Epsilon.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
clean:
	$(RM) [Oo]ut* *.exe Objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)