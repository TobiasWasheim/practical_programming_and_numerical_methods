CXX = clang
CXXFLAGS = -std=c++20 -O0 -ffast-math
LDLIBS = -lstdc++ -lm

all: plot.svg

plot.svg: data.txt CosineTable.txt
	echo '\
		set terminal $(subst .,,$(suffix $@)) background "white"; \
		set output "$@"; \
		set grid;\
		set key bottom;\
		set xlabel "x";\
		set ylabel "y";\
		set title "Linear Interpolation of Cosine";\
		plot \
			"data.txt" every::1 using 1:2 with lines title "Linear interpolation",\
			"data.txt"  every::1 using 1:3 with lines title "Integration",\
			"CosineTable.txt" with points pointtype 7 title "Tabulated values" \
	' | gnuplot


data.txt: main
	./main > data.txt


main: main.o LinearSpline.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

LinearSpline.o: LinearSpline.cpp LinearSpline.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(filter %.cpp,$^) -o $@

clean:
	$(RM) main.o LinearSpline.o plot.svg