unset label
set terminal png size 400,300 enhanced font "Helvetica,20"
set output "Rosenbrock.png"
set title "Rosenbrock Problem"
set xlabel "Generations"
set ylabel "Fitness"
set autoscale
plot "Rosenbrock.dat" using 1:2 with lines title "Best", \
     '' using 1:3 with lines title "Average"
