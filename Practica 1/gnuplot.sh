#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoKP.eps"
set key right bottom
set xlabel "Numero de iteracion"
set ylabel "Fitness mejor Solucion"

plot 'KP_soluciones.txt' using 1:2 t "Fitness" w l
_end_
