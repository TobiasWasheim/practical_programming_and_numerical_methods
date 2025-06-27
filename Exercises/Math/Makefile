CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS += -lstdc++ -lm


Out.txt : main
	./main > out.txt
main: objects/main.o objects/sfuns.o objects/math.o objects/tables.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
objects/main.o: headers/sfuns.h headers/math.h headers/tables.h src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
objects/tables.o: headers/tables.h src/tables.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
objects/sfuns.o: headers/sfuns.h src/sfuns.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
objects/math.o: headers/math.h src/math.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
clean:
	$(RM) out.txt main objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)