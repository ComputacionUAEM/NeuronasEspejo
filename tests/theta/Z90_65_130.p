# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresZ.eps'
set multiplot
set size 1,0.33
set origin 0.0,0.66
set title "Z error 90" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:300]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=32.09
plot "gerror1.dat" u 0:4 w lines t 'Z 90', f(x) t 'Z Media'
set origin 0.0,0.33
set title "Z error 65 45" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=61.8
plot "gerror2.dat" u 0:4 w lines t 'Z 65 45', f(x) t 'Z Media'
set origin 0.0,0.0
set title "Z error 130" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=51.26
plot "gerror3.dat" u 0:4 w lines t 'Z 130', f(x) t 'Z Media'
unset multiplot

