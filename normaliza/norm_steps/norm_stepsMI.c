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

int main(int argc, char *argv[]){
  printf("******* Normalizar datos *******\n");
  if (argc!=4) {
    printf("Error de sintaxis:\n   ./normaliza src dst src2\n");
    printf("\tdonde src es el nombre del archivo con los datos de entrada,\n");
    printf("\tdst es el nombre del archivo de salida con los datos normalizados\n");
    printf("\ty src2 es el nombre del archivo con los datos de entrada corregidos\n");
    return 1;
  }
  float t[4],t1[4],mv[3];
  float tM[4],t1M[4],mvM[3];
  float tm[4],t1m[4],mvm[3];
  float cx,cy;
  int i=0,k,j=0,kl;
  FILE *nombre;
  FILE *dst;
  FILE *src;
  char texto[130];
  
  nombre = fopen(argv[1], "r");
  dst = fopen(argv[2],"w");
  src = fopen(argv[3],"w");
  for(k=0;k<4;k++){
    tM[k]=-100;
    t1M[k]=-100;
    tm[k]=1000;
    t1m[k]=1000;
    if(k<3){
      mvM[k]=0;
      mvm[k]=3000;
    }
  }
  if (nombre == NULL){
    printf("El archivo no existe \n");
    exit (EXIT_FAILURE);
  } else {
    while (feof(nombre)==0) {
      fgets(texto,130,nombre);
      //printf("%s",texto);
      sscanf(texto,"%f %f %f %f %f %f %f %f %f %f %f",&t[0],&t[1],&t[2],&t[3],&t1[0],&t1[1],&t1[2],&t1[3],&mv[0],&mv[1],&mv[2]);
      for(k=0;k<4;k++){
	if(tM[k]<t[k])
          tM[k]=t[k];
        if(t1M[k]<t1[k])
          t1M[k]=t1[k];
        if(tm[k]>t[k])
          tm[k]=t[k];
        if(t1m[k]>t1[k])
          t1m[k]=t1[k];
        if(k<3){
          if(mvM[k]<mv[k])
            mvM[k]=mv[k];
          if(mvm[k]>mv[k])
            mvm[k]=mv[k];
        }
      }
      if(t1[0]==0&t1[1]==0&t1[2]==0&t1[3]==0){
      i++;}
      else{
	if(t[2]>=0&&t1[2]>=0&&t[3]>=0&&t[3]<=180&&t1[3]>=0&&t1[3]<=180){
	  mv[0]=(float)(int)mv[0];
	  mv[1]=(float)(int)mv[1];
	  fprintf(src,"%f %f %f %f ",t[0],t[1],t[2],t[3]);
          fprintf(src,"%f %f %f %f ",t1[0],t1[1],t1[2],t1[3]);
          fprintf(src,"%f %f %f\n",mv[0],mv[1],mv[2]);
          fprintf(dst,"%f %f %f ",(t[0]+770)/1540,(t[1]+250)/500,t[2]/2700);
	  fprintf(dst,"%f %f %f ",(t1[0]+770)/1540,(t1[1]+250)/500,t1[2]/2700);
	  cx=0.0;
	  cy=-6.0;
	  for(kl=1;kl<8;kl++){
	    if(mv[0]>=(cx-69.0)&&mv[0]<=(cx-50.0)){
	      mv[0]=cy;
	      break;}
	    else{
	      cx+=20.0;
	      cy+=2.0;
	    }
	  }
	  //printf("%f %f %f\n",cx,cy,mv[0]);
	  cx=0;
	  cy=-6.0;
	  for(kl=1;kl<8;kl++){
	    if(mv[1]>=cx-69.0&&mv[1]<=cx-50.0){
	      mv[1]=cy;
	      break;}
	    else{
	      cx+=20.0;
	      cy+=2.0;
	    }
	  }
	  fprintf(dst,"%f %f\n",((mv[0]*mv[2])+18000)/36000,((mv[1]*mv[2])+18000)/36000);
        }
	else{
	  j++;
	}
      }
    }
    printf("Numero de patrones fuera por perdida de marcador: %d\n",i);
    printf("Numero de patrones fuera por valores erroneos: %d\n",j);
      
  }
  fclose(nombre);
  printf("Los valores mas grandes son:\n");
  printf("%f %f %f %f %f %f %f %f %f %f %f\n",tM[0],tM[1],tM[2],tM[3],t1M[0],t1M[1],t1M[2],t1M[3],mvM[0],mvM[1],mvM[2]);
  printf("Los valores mas pequeños son:\n");
  printf("%f %f %f %f %f %f %f %f %f %f %f\n",tm[0],tm[1],tm[2],tm[3],t1m[0],t1m[1],t1m[2],t1m[3],mvm[0],mvm[1],mvm[2]);    
  fclose(dst);
  fclose(src);
  return 1;
}
