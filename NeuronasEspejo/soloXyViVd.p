# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'todos.p'
set title "Errores de X y Velocidades*tiempo" font "Times-Roman,18"
set xrange [0:100]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Medida en milimetros" font "Times-Italic,14"
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'X_Vi_Vd.eps'
w=800
f(x)=w
plot "errorx0.dat" u 0:2 w lines t 'Real X', "errorx2.dat" u 0:3 w lines t 'Pred X', "vivd" u 0:3 w lines t 'Vi', "vivd" u 0:4 w lines t 'Vd', f(x) t 'cero Vi Vd'

