# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresY.eps'
set multiplot
set size 1,0.33
set origin 0.0,0.66
set title "Y error 90" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:20]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=2.99
plot "gerror1.dat" u 0:3 w lines t 'Y 90', f(x) t 'Y Media'
set origin 0.0,0.33
set title "Y error 65 45" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=3.5
plot "gerror2.dat" u 0:3 w lines t 'Y 65 45', f(x) t 'Y Media'
set origin 0.0,0.0
set title "Y error 130" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=3.89
plot "gerror3.dat" u 0:3 w lines t 'Y 130', f(x) t 'Y Media'
unset multiplot

