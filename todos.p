# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'todos.p'
set title "Errores de X Y Z en la misma escala" font "Times-Roman,18"
set xrange [0:100]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Medida en milimetros" font "Times-Italic,14"
set key 100,1000
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'XYZ.eps'
plot "errorx0.dat" u 1:2 w lines t 'Real X', "errorx0.dat" u 1:3 w lines t 'Pred Net1 X', "errorx1.dat" u 1:3 w lines t 'Pred Net2 X', "errorx2.dat" u 1:3 w lines t 'Pred Net3 X', "errory0.dat" u 1:2 w lines t 'Real Y', "errory1.dat" u 1:3 w lines t 'Pred Net1 Y', "errory1.dat" u 1:3 w lines t 'Pred Net2 Y', "errory2.dat" u 1:3 w lines t 'Pred Net3 Y', "errorz0.dat" u 1:2 w lines t 'Real Z', "errorz0.dat" u 1:3 w lines t 'Pred Net1 Z', "errorz1.dat" u 1:3 w lines t 'Pred Net2 Z', "errorz2.dat" u 1:3 w lines t 'Pred Net3 Z';

