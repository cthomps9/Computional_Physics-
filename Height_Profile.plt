# plot file for Simple Dimple
set timestamp

set title 'Simple Dimple Modeling'

set xlabel 'x and y in 2D plane'
set ylabel 'z position' 

plot "height_profile.dat" using ($1):($3) title 'Z-change' with linespoints, \

# remember terminal type
set term push
set term png enhanced
set out "Height_Profile_of_Simple_Dimple.png"
replot
set out
# restore terminal type
set term pop
