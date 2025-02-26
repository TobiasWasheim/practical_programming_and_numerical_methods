CXXFLAGS = -std=c++23 -O0 -ffast-math
LDLIBS = -lstdc++ -lm
Out.txt: main.exe
	./main.exe -n 1 -n 2 -n 3 -n 4 -n 5 > Out.txt
main.exe: objects/main.o 
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
objects/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

clean:
	$(RM) [Oo]ut* *.exe objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)