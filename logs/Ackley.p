unset label
set terminal png size 400,300 enhanced font "Helvetica,20"
set output "Ackley.png"
set title "Ackley Problem"
set xlabel "Generations"
set ylabel "Fitness"
set autoscale
plot "Ackley.dat" using 1:2 with lines title "Best", \
     '' using 1:3 with lines title "Average"
