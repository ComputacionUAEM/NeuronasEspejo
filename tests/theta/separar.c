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

int main(int argc, char *argv[]){
  printf("******* Separar datos *******\n");
  if (argc!=2) {
    printf("Error de sintaxis:\n   ./separar dst\n");
    printf("\tdonde dst es la raiz del archivo de salida\n");
    return 1;
  }
  float x[2],y[2],z[2];
  int i=0,indice=0;

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
   if(i<185||(i>300&&i<462)||i>805)
     fprintf(dst1,"%d %f %f %f %f %f %f\n",indice,x[0],x[1],y[0],y[1],z[0],z[1]);
   if((i>184&&i<301)||(i>461&&i<594))
     fprintf(dst2,"%d %f %f %f %f %f %f\n",indice,x[0],x[1],y[0],y[1],z[0],z[1]);
   if(i>593&&i<806)
     fprintf(dst3,"%d %f %f %f %f %f %f\n",indice,x[0],x[1],y[0],y[1],z[0],z[1]);
   i++;   
  }
  fclose(src1);
  fclose(src2);
  fclose(src3);
  fclose(dst1);
  fclose(dst2);
  fclose(dst3);
  return 1;
}
