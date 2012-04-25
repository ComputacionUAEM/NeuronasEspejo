# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'XYZerror.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresXYZ.eps'
set multiplot
set size 1,0.333
set origin 0.0,0.666
set title "X error" font "Times-Roman,18"
#set xrange [800:1000]
#set yrange [0:350]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=16.6
plot "error1.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
set origin 0.0,0.333
set title "Y error" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=2.93
plot "error1.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
set origin 0.0,0.0
set title "Z error" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=30.97
plot "error1.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
unset multiplot

