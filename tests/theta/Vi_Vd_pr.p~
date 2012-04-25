# Gnuplot script para plotear errores
# ejecutar: gnuplot > load 'ViyVdpr.p'
set encoding iso_8859_1
set terminal postscript color eps enhanced 10
set output 'Vi_p_vs_r.eps'
set multiplot
set size 1,0.5
set origin 0.0,0.5
set title "Vi: Predicho y Real" font "Times-Roman,18"
set xrange [0:100]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set key 95,120
set xtic 10
set grid ytic xtic
plot "p_vs_rVi.dat" u 0:2 w lines t 'Vi Real', "p_vs_rVi.dat" u 0:3 w lines t 'Vi Pred'
set origin 0.0,0.0
set title "Vd: Predicho y Real" font "Times-Roman,18"
set xrange [0:100]
set xlabel "Patrones" font "Times-Italic,14"
set ylabel "Milimetros" font "Times-Italic,14"
set key 95,120
set grid ytic xtic
set label "Vi y Vd real y pred estan desnormalizados" at 60,-155 font "Times-Italic,12"
set label "suponiendo a t = 1segundo" at 60,-175 font "Times-Italic,12"
plot "p_vs_rVd.dat" u 0:2 w lines t 'Vd Real', "p_vs_rVd.dat" u 0:3 w lines t 'Vd Pred'
unset multiplot

