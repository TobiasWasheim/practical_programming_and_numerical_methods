CXXFLAGS += -Wall -std=c++23 #-ferror-limit=1 
LDLIBS += -lstdc++ -lm

Out.txt: main
	./$< > $@

main: main.o vec.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

vec.o: vec.h vec.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
main.o: vec.h main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@


clean:
	$(RM) [Oo]ut* main *.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)