# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'ErroresZ.eps'
set multiplot
set size 1,0.2
set origin 0.0,0.8
set title "Z error +Vi +Vd" font "Times-Roman,18"
#set xrange [800:1000]
set yrange [0:300]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=41.26
plot "gerror1.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
set origin 0.0,0.6
set title "Z error -Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=41.69
plot "gerror2.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
set origin 0.0,0.4
set title "Z error -Vi +Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=35.58
plot "gerror3.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
set origin 0.0,0.2
set title "Z error +Vi -Vd" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=39.5
plot "gerror4.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
set origin 0.0,0.0
set title "Z error movimientos casi imperceptibles" font "Times-Roman,18"
#set xrange [0:200]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set grid
f(x)=39.3
plot "gerror5.dat" u 0:4 w lines t '{/Symbol \326}(Zr-Zp)^2', f(x) t 'Z Media'
unset multiplot

