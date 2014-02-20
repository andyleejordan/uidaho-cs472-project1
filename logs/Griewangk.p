unset label
set terminal png size 400,300 enhanced font "Helvetica,20"
set output "Griewangk.png"
set title "Griewangk Problem"
set xlabel "Generations"
set ylabel "Fitness"
set autoscale
plot "Griewangk.dat" using 1:2 with lines title "Best", \
     '' using 1:3 with lines title "Average"
