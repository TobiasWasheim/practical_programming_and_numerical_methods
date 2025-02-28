CXXFLAGS = -Wall -O3 -ffast-math
LDLIBS += -lstdc++ -lm

# Create plots!

default: main erf_data.svg sgamma_data.svg lngamma_data.svg


erf_data.svg: data/erf_data.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key left;\
		set xlabel "x";\
		set ylabel "erf(x)";\
		set title "Error function";\
		plot \
			 "$<" with lines title "erf(x)",\
			 "tabulated/erf_tabulated.txt" with points pointtype 7 title "tabulated" \
	' | gnuplot

sgamma_data.svg: data/sgamma_data.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set key left;\
		set xlabel "x";\
		set ylabel "Γ(x)";\
		set title "Gamma Function";\
		set key bottom right; \
		set xrange [-5:5]; \
		set yrange [-5:5]; \
		plot \
			 "$<" with lines title "erf(x)",\
			 "tabulated/sgamma_tabulated.txt" with points pointtype 7 title "tabulated" \
	' | gnuplot

lngamma_data.svg: data/lngamma_data.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "plots/$@"; \
		set grid;\
		set key left;\
		set xlabel "x";\
		set ylabel "erf(x)";\
		set title "Error function";\
		plot \
			 "$<" with lines title "erf(x)"\
	' | gnuplot



# Create files and run them!

main: objects/main.o objects/sfuns.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o run/$@
	./run/main

objects/main.o: src/sfuns.h src/main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

objects/sfuns.o: src/sfuns.cpp src/sfuns.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

clean:
	$(RM) run/main data/* objects/*.o plots/* run/*
test:
	@echo "CXX:" $(CXX)
	@echo "RM:" $(RM)
	@echo "LDFLAGS:" $(LDFLAGS)