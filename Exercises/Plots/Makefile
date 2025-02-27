CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS += -lstdc++ -lm


main: main.o sfuns.o
	$(CXX) $(LDFLAGS) objects/$< $(LDLIBS) -o run/$@
	./run/main

main.o: src/main.cpp 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o objects/$@

sfuns.o: src/sfuns.cpp src/sfuns.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o objects/$@

clean:
	$(RM) run/main data/* objects/* plots/* run/*
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)