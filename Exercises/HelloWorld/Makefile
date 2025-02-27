CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS = -lstdc++ -lm

Out.txt : main
	./main > Out.txt
main: objects/main.o objects/hello.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
objects/main.o: headers/hello.h src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
objects/hello.o: headers/hello.h src/hello.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
clean:
	$(RM) [Oo]ut* main objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)
