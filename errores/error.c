/*
 *  prepara_datos.c
 *  Normaliza los datos para la red
 *
 *  Created by esau on 3/12.
 *  Copyright 2012. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  printf("******* Calcular error *******\n");
  if (argc!=5) {
    printf("Error de sintaxis:\n   ./error src1 src2 src3 dst\n");
    printf("\tdonde src1 archivo error1, src2 archivo error2,\n");
    printf("\tsrc3 archivo error3\n");
    printf("\ty dst es el archivo con la salida\n");
    return 1;
  }
  int i=0,j=0;
  float x0,x1,px0=0,px1=0,px2=0,nx0,nx1,nx2;
  int xm0=0,xm1=0,xm2=0,Mx0[2],Mx1[2],Mx2[2];
  FILE *src1,*src2,*src3;
  FILE *dst;
  char texto[130];
  
  src1 = fopen(argv[1], "r");
  src2 = fopen(argv[2],"r");
  src3 = fopen(argv[3],"r");
  dst = fopen(argv[4],"w");
  Mx0[0]=0;
  Mx1[0]=0;
  Mx2[0]=0;
  if(src1==NULL||src2==NULL||src3==NULL){
    printf("El archivo no existe \n");
    exit (EXIT_FAILURE);
  } 
  else {
    while (feof(src1)==0) {
      fgets(texto,130,src1);
      sscanf(texto,"%d %f %f",&i,&x0,&x1);
      nx0=sqrt((x0-x1)*(x0-x1));
      px0+=nx0;
      fprintf(dst,"%d %f",i,nx0);
      fgets(texto,130,src2);
      sscanf(texto,"%d %f %f",&i,&x0,&x1);
      nx1=sqrt((x0-x1)*(x0-x1));
      px1+=nx1;
      fprintf(dst," %f",nx1);
      fgets(texto,130,src3);
      sscanf(texto,"%d %f %f",&i,&x0,&x1);
      nx2=sqrt((x0-x1)*(x0-x1));
      px2+=nx2;
      fprintf(dst," %f\n",nx2);  
      j++;
      if(Mx0[0]<nx0){
	Mx0[0]=nx0;
	Mx0[1]=(j*2)+1;}
      if(Mx1[0]<nx1){
	Mx1[0]=nx1;
	Mx1[1]=(j*2)+1;}
      if(Mx2[0]<nx2){
	Mx2[0]=nx2;
	Mx2[1]=(j*2)+1;}
      if(nx0>nx1)
	if(nx0>nx2)
	  xm0++;
	else
	  xm2++;
      else
	if(nx1>nx2)
	  xm1++;
	else
	  xm2++;
    }
  }
  printf("%f %f %f\n",px0/j,px1/j,px2/j);
  printf("%d %d %d\n",xm0,xm1,xm2);
  printf("%d %d %d\n",Mx0[0],Mx1[0],Mx2[0]);
  printf("%d %d %d\n",Mx0[1],Mx1[1],Mx2[1]);
  fclose(src1);
  fclose(src2);
  fclose(src3);
  fclose(dst);
  return 1;
}
