/*
 *  separar.c
 *  Separa en categorias por theta
 *
 *  Created by esau on 3/12.
 *  Copyright 2012. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  printf("******* Separar datos *******\n");
  if (argc!=2) {
    printf("Error de sintaxis:\n   ./separar dst\n");
    printf("\tdonde dst es la raiz del archivo de salida\n");
    return 1;
  }
  float x[2],y[2],z[2],v[2];
  float x1=0,y1=0,z1=0;
   float temp;
  int i=0,indice=0;
  int xi1=0,yi1=0,zi1=0;
  
  FILE *dst1;
  FILE *src1;
  FILE *src2;
  FILE *src3;
  char texto[130];
  
  src1= fopen("x.dat", "r");
  src2= fopen("y.dat", "r");
  src3= fopen("z.dat", "r");
  sprintf(texto,"%s1.dat",argv[1]);
  dst1 = fopen(texto,"w");
  
  while (feof(src1)==0) {
   fgets(texto,130,src1);
   sscanf(texto,"%d %f %f",&indice,&x[0],&x[1]);
   fgets(texto,130,src2);
   sscanf(texto,"%d %f %f",&indice,&y[0],&y[1]);
   fgets(texto,130,src3);
   sscanf(texto,"%d %f %f",&indice,&z[0],&z[1]);
   fprintf(dst1,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
   x1+=sqrt(pow(x[0]-x[1],2));
   y1+=sqrt(pow(y[0]-y[1],2));
   z1+=sqrt(pow(z[0]-z[1],2));
   xi1++;
   yi1++;
   zi1++;
   i++;   
  }
  printf("%f %f %f\n",x1/xi1,y1/yi1,z1/zi1);
  fclose(src1);
  fclose(src2);
  fclose(src3);
  fclose(dst1);
  return 1;
}
