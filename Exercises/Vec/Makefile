CXXFLAGS = -std=c++23 -O0 -ffast-math
LDLIBS = -lstdc++ -lm
Out.txt: main.exe
	./main.exe > Out.txt
main.exe: Objects/main.o Objects/vec.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
Objects/main.o: Includes/vec.h main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@
Objects/vec.o: Includes/vec.h Includes/vec.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(filter %.cpp,$^)
clean:
	$(RM) [Oo]ut* *.exe Objects/*.o
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)