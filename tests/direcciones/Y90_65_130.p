# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresY.eps'
set multiplot
set size 1,0.2
set origin 0.0,0.8
set title "Y error +Vi +Vd" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:20]
set ytics 4
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=4.18
plot "gerror1.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
set origin 0.0,0.6
set title "Y error -Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=4.39
plot "gerror2.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
set origin 0.0,0.4
set title "Y error -Vi +Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=3.09
plot "gerror3.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
set origin 0.0,0.2
set title "Y error +Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=2.8
plot "gerror4.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
set origin 0.0,0.0
set title "Y error movimientos casi imperceptibles" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=2.53
plot "gerror5.dat" u 0:3 w lines t '{/Symbol \326}(Yr-Yp)^2', f(x) t 'Y Media'
unset multiplot

