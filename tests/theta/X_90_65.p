# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresX.eps'
set multiplot
set size 1,0.33
set origin 0.0,0.66
set title "X error 90" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:350]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=59.62
plot "gerror1.dat" u 0:2 w lines t 'X 90', f(x) t 'X Media'
set origin 0.0,0.33
set title "X error 65 45" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=71.93
plot "gerror2.dat" u 0:2 w lines t 'X 65 45', f(x) t 'X Media'
set origin 0.0,0.0
set title "X error 130" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=62.60
plot "gerror3.dat" u 0:2 w lines t 'X 130', f(x) t 'X Media'
unset multiplot

