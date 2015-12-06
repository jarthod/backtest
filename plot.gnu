# set terminal wxt size 2500,1380 enhanced
set datafile separator ","
set xdata time
set timefmt "%s"
set ylabel "EUR"
set grid
plot "data/krakenEUR.csv" every 100 using 1:2 title 'krakenEUR' with lines