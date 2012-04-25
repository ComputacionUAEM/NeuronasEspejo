# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresX.eps'
set multiplot
set size 1,0.2
set origin 0.0,0.8
set title "X error +Vi +Vd" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:350]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=57.5
plot "gerror1.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
set origin 0.0,0.6
set title "X error -Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=63.17
plot "gerror2.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
set origin 0.0,0.4
set title "X error -Vi +Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=54.02
plot "gerror3.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
set origin 0.0,0.2
set title "X error +Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=56.19
plot "gerror4.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
set origin 0.0,0.0
set title "X error movimientos casi imperceptibles" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=71.15
plot "gerror5.dat" u 0:2 w lines t '{/Symbol \326}(Xr-Xp)^2', f(x) t 'X Media'
unset multiplot

