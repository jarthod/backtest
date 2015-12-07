set terminal wxt size 2500,1380 enhanced font "arial,10"
set datafile separator ","
set xdata time
set timefmt "%s"
set ylabel "EUR"
set grid
# set xrange ["1389174260":"1389184260"]
set pointsize 1
set style line 1 lt 2 lc rgb "#aaaaaa" lw 1
set style line 2 lt 2 lc rgb "#55ee22" lw 2
set style arrow 2 head filled lc rgb "#ff3300" lw 2
set style arrow 3 head filled lc rgb "#5588ff" lw 2

set lmargin 10

set multiplot
set size 1, 0.6
set origin 0, 0.4

plot "data/krakenEUR.csv" every 10 using 1:2 title 'krakenEUR' with lines  ls 1, "positions.dat" using 1:2:3:4 title 'Short positions' with vectors arrowstyle 2, "positions.dat" using 1:5:6:7 title 'Long positions' with vectors arrowstyle 3


set size 1, 0.4
set origin 0, 0

plot "positions.dat" using 1:8 title 'Gain' with lines ls 2
unset multiplot