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
  float x2=0,y2=0,z2=0;
  float x3=0,y3=0,z3=0;
  float x4=0,y4=0,z4=0;
  float x5=0,y5=0,z5=0;
  float temp;
  int i=0,indice=0;
  int xi1=0,yi1=0,zi1=0;
  int xi2=0,yi2=0,zi2=0;
  int xi3=0,yi3=0,zi3=0;
  int xi4=0,yi4=0,zi4=0;
  int xi5=0,yi5=0,zi5=0;

  FILE *dst1;
  FILE *dst2;
  FILE *dst3;
  FILE *dst4;
  FILE *dst5;
  FILE *src1;
  FILE *src2;
  FILE *src3;
  FILE *src4;
  char texto[130];
  
  src1= fopen("x.dat", "r");
  src2= fopen("y.dat", "r");
  src3= fopen("z.dat", "r");
  src4= fopen("patt_temp.dat", "r");
  sprintf(texto,"%s1.dat",argv[1]);
  dst1 = fopen(texto,"w");
  sprintf(texto,"%s2.dat",argv[1]);
  dst2 = fopen(texto,"w");
  sprintf(texto,"%s3.dat",argv[1]);
  dst3 = fopen(texto,"w");
  sprintf(texto,"%s4.dat",argv[1]);
  dst4 = fopen(texto,"w");
  sprintf(texto,"%s5.dat",argv[1]);
  dst5 = fopen(texto,"w");
  
  while (feof(src1)==0) {
   fgets(texto,130,src1);
   sscanf(texto,"%d %f %f",&indice,&x[0],&x[1]);
   fgets(texto,130,src2);
   sscanf(texto,"%d %f %f",&indice,&y[0],&y[1]);
   fgets(texto,130,src3);
   sscanf(texto,"%d %f %f",&indice,&z[0],&z[1]);
   fgets(texto,130,src4);
   sscanf(texto,"%f %f %f %f %f %f %f %f %f %f %f",&temp,&temp,&temp,&temp,&temp,&temp,&temp,&temp,&v[0],&v[1],&temp);
   if(v[0]>15&&v[1]>15){
     fprintf(dst1,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x1+=sqrt(pow(x[0]-x[1],2));
     y1+=sqrt(pow(y[0]-y[1],2));
     z1+=sqrt(pow(z[0]-z[1],2));
     xi1++;
     yi1++;
     zi1++;
   }
   if(v[0]<-15&&v[1]<-15){
     fprintf(dst2,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x2+=sqrt(pow(x[0]-x[1],2));
     y2+=sqrt(pow(y[0]-y[1],2));
     z2+=sqrt(pow(z[0]-z[1],2));
     xi2++;
     yi2++;
     zi2++;
   }
   if((v[0]<15&&v[1]>15)||(v[0]<-15&&v[1]>-15)){
     fprintf(dst3,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x3+=sqrt(pow(x[0]-x[1],2));
     y3+=sqrt(pow(y[0]-y[1],2));
     z3+=sqrt(pow(z[0]-z[1],2));
     xi3++;
     yi3++;
     zi3++;
   }
   if((v[0]>15&&v[1]<15)||(v[0]>-15&&v[1]<-15)){
     fprintf(dst4,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x4+=sqrt(pow(x[0]-x[1],2));
     y4+=sqrt(pow(y[0]-y[1],2));
     z4+=sqrt(pow(z[0]-z[1],2));
     xi4++;
     yi4++;
     zi4++;
   }
   if(v[0]<15&&v[0]>-15&&v[1]<15&&v[1]>-15){
     fprintf(dst5,"%d %f %f %f\n",indice,sqrt(pow(x[0]-x[1],2)),sqrt(pow(y[0]-y[1],2)),sqrt(pow(z[0]-z[1],2)));
     x5+=sqrt(pow(x[0]-x[1],2));
     y5+=sqrt(pow(y[0]-y[1],2));
     z5+=sqrt(pow(z[0]-z[1],2));
     xi5++;
     yi5++;
     zi5++;
   }
   i++;   
  }
  printf("%f %f %f\n",x1/xi1,y1/yi1,z1/zi1);
  printf("%f %f %f\n",x2/xi2,y2/yi2,z2/zi2);
  printf("%f %f %f\n",x3/xi3,y3/yi3,z3/zi3);
  printf("%f %f %f\n",x4/xi4,y4/yi4,z4/zi4);
  printf("%f %f %f\n",x5/xi5,y5/yi5,z5/zi5);
  fclose(src1);
  fclose(src2);
  fclose(src3);
  fclose(src4);
  fclose(dst1);
  fclose(dst2);
  fclose(dst3);
  fclose(dst4);
  fclose(dst5);
  return 1;
}
