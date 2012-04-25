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
  float x[2],y[2],z[2];
  float x1=0,y1=0,z1=0;
  float x2=0,y2=0,z2=0;
  float x3=0,y3=0,z3=0;
  int i=0,indice=0;
  int xi1=0,yi1=0,zi1=0;
  int xi2=0,yi2=0,zi2=0;
  int xi3=0,yi3=0,zi3=0;

  FILE *dst1;
  FILE *dst2;
  FILE *dst3;
  FILE *src1;
  FILE *src2;
  FILE *src3;
  char texto[130];
  
  src1= fopen("x.dat", "r");
  src2= fopen("y.dat", "r");
  src3= fopen("z.dat", "r");
  sprintf(texto,"%s1.dat",argv[1]);
  dst1 = fopen(texto,"w");
  sprintf(texto,"%s2.dat",argv[1]);
  dst2 = fopen(texto,"w");
  sprintf(texto,"%s3.dat",argv[1]);
  dst3 = fopen(texto,"w");
  
  while (feof(src1)==0) {
   fgets(texto,130,src1);
   sscanf(texto,"%d %f %f",&indice,&x[0],&x[1]);
   fgets(texto,130,src2);
   sscanf(texto,"%d %f %f",&indice,&y[0],&y[1]);
   fgets(texto,130,src3);
   sscanf(texto,"%d %f %f",&indice,&z[0],&z[1]);
   if(i<185||(i>300&&i<462)||i>805){
     fprintf(dst1,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x1+=sqrt(pow(x[0]-x[1],2));
     y1+=sqrt(pow(y[0]-y[1],2));
     z1+=sqrt(pow(z[0]-z[1],2));
     xi1++;
     yi1++;
     zi1++;
   }
   if((i>184&&i<301)||(i>461&&i<594)){
     fprintf(dst2,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x2+=sqrt(pow(x[0]-x[1],2));
     y2+=sqrt(pow(y[0]-y[1],2));
     z2+=sqrt(pow(z[0]-z[1],2));
     xi2++;
     yi2++;
     zi2++;
   }
   if(i>593&&i<806){
     fprintf(dst3,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x3+=sqrt(pow(x[0]-x[1],2));
     y3+=sqrt(pow(y[0]-y[1],2));
     z3+=sqrt(pow(z[0]-z[1],2));
     xi3++;
     yi3++;
     zi3++;
   }
   i++;   
  }
  printf("%f %f %f\n",x1/xi1,y1/yi1,z1/zi1);
  printf("%f %f %f\n",x2/xi2,y2/yi2,z2/zi2);
  printf("%f %f %f\n",x3/xi3,y3/yi3,z3/zi3);
  fclose(src1);
  fclose(src2);
  fclose(src3);
  fclose(dst1);
  fclose(dst2);
  fclose(dst3);
  return 1;
}
