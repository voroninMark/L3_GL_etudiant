#!/bin/sh

../build/drawspline.out < input.csv > data.csv

gnuplot -e "set out 'plot.png'; \
    set terminal png size 600,400; \
    set style data linespoints; \
    set xrange [-2:2]; \
    set yrange [-1.5:1.5]; \
    plot 'data.csv' using 2:3 lc rgb 'blue' lw 1.5 title '2D cubic spline', \
    'input.csv' using 2:3 lc rgb 'red' lw 1.5 title 'control points' "

display plot.png

