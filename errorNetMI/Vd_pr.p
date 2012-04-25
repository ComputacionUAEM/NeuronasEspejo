# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'todos.p'
set title "Vd: Predicho y Real" font "Times-Roman,18"
set xrange [0:100]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set key 95,120
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'Vd_p_vs_r.eps'
set grid 
set label "Vd real y pred estan desnormalizados" at 60,-155 font "Times-Italic,12"
   set label "suponiendo a t = 1segundo" at 60,-165 font "Times-Italic,12"
plot "p_vs_rVd.dat" u 0:2 w lines t 'Vd Real', "p_vs_rVd.dat" u 0:3 w lines t 'Vd Pred';

