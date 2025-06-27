CXXFLAGS += -Wall -std=c++23 #-ferror-limit=1 
LDLIBS += -lstdc++ -lm

out.txt: main
	./$< > $@

main: objects/main.o objects/vec.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

objects/vec.o: headers/vec.h src/vec.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
objects/main.o: headers/vec.h src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@


clean:
	$(RM) out.txt main objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)