CXXFLAGS = -std=c++23 -Wall -O2 -march=native
LDLIBS = -lstdc++ -lm -lpthread
TIME = time --format "$$nthreads %e %U" --append --output out.times

default : threads.svg

N = 200000000
out.times : main 
	>$@
	>log.main
	for nthreads in 1 2 3 4 5 6 7 8; do \
		$(TIME) ./main -n $$nthreads -N $(N) >>log.main ;\
	done

threads.svg : out.times 
	echo '\
	set terminal $(subst .,,$(suffix $@)) background "white" ;\
	set output "$@" ;\
	set tics out ;\
	set title "Program running time as function of number of threads" ;\
	set xlabel "number of threads" ;\
	set ylabel "real time in seconds" ;\
	set xtics 1 ;\
	plot [0.9:8.1][0:] \
		"$<" index 0 with linespoints title "c++"\
		;\
	' | gnuplot

clean:
	$(RM) main [Oo]ut* [Ll]og* *.svg