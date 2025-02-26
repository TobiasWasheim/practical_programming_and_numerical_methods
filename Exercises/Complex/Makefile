CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm
Out.txt : main
	./main > Out.txt
main: objects/main.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
objects/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

clean:
	$(RM) [Oo]ut* main objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)