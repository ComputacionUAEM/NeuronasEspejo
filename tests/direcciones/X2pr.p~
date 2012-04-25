# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'todos.p'
set title "X Predicho y Real" font "Times-Roman,18"
set xrange [1000:1188]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'Xpr.eps'
set grid 
plot "grados1.dat" u 0:2 w lines t 'X Real', "grados1.dat" u 0:3 w lines t 'X Pred';

