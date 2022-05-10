set term pdf
set out "Graficas2.pdf"
set log xy
# set xrange [1:100000]
# set yrange [0.0000001:10]
set xlabel "Tamaño de la matriz"  
set ylabel "Tiempo(s)"  
set title "Tiempo en función del tamaño para diferentes threads "  
plot 'datos1.txt' u 1:2:3 w yerrorlines lw 2 t "1 thread", 'datos2.txt' u 1:2:3 w yerrorlines lw 2 t "2 threads", 'datos4.txt' u 1:2:3 w yerrorlines lw 2 t "4 threads", 'datos8.txt' u 1:2:3 w yerrorlines lw 2 t "8 threads"