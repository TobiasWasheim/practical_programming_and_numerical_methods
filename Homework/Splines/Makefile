CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

all: linterp.svg

linterp.svg: linterp.txt CosineTable.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key bottom;\
		set xlabel "x";\
		set ylabel "y";\
		set title "Linear Interpolation of Cosine";\
		plot \
			"linterp.txt" with lines title "Linear Interpolation",\
			"CosineTable.txt" with points pointtype 7 title "tabulated" \
	' | gnuplot


linterp.txt: main
	./main > linterp.txt


main: main.o LinearSpline.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

LinearSpline.o: LinearSpline.cpp LinearSpline.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

clean:
	$(RM) main.o LinearSpline.o