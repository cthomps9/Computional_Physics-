# plot file for invagination over time
set timestamp

set title 'Growth of Invagination over time'

set xlabel 'time (simulation unit)'
set ylabel 'Z-Displacement (nm)' 

plot "dataset.dat" using ($1):($6) title 'Growth in Z' with linespoints, 
# remember terminal type
set term push
set term png enhanced
set out "Growth_in_Z_direction.png"
replot
set out
# restore terminal type
set term pop
