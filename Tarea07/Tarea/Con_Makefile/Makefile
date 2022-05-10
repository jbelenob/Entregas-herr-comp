${NAME}=Matrix_multiplication


datos1.txt: Matrix_multiplication.x
	for M in 2 4 8 16 32 64 128 256 512 1024 2048; do echo -n ; OMP_NUM_THREADS=1 ./$< $$M 10 4; done > $@

${NAME}.x: Matrix_multiplication.cpp
	g++ -fopenmp -O3 $<

GRAFICAS.pdf: SCRIPT.gp datos1.txt datos2.txt datos4.txt datos8.txt
	gnuplot $<.gp
