# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresX.eps'
set multiplot
set size 1,0.5
set origin 0.0,0.5
set title "X error 90°" font "Times-Roman,18"
set xrange [1000:1188]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
plot "gerror1.dat" u 0:2 w lines t 'X 90°'
set origin 0.0,0.0
set title "X error 65° 45°" font "Times-Roman,18"
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
plot "gerror2.dat" u 0:2 w lines t 'X 65° 45°'
unset multiplot

