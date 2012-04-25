/*
 *  mi.c
 *  El modelo inverso por comparacion
 *
 *  Created by esau on 4/12.
 *  Copyright 2012. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K1 70
#define K2 50
#define K3 30
#define K4 5

int main(int argc, char *argv[]){
  printf("******* Modelo Inverso *******\n");
  if (argc!=3) {
    printf("Error de sintaxis:\n   ./mi datos ejemplo\n");
    printf("\tdonde datos es la base de conocimiento,\n");
    printf("\ty ejemplo es el archivo con el ejemplo a probar\n");
    return 1;
  }

  FILE *src;
  FILE *ejemplo;
  char texto[130];
  int k,i,l,worst,r,p;
  float st[2],st1[2],mv[3],est[2],est1[2],emv[3];
  float twnear[K1][8],tennear[K2][7],k3near[K3][7],k4near[K4][7];
  float dtwn,ed,sd,tm;
  
  ejemplo = fopen(argv[2],"r");

  if (ejemplo == NULL || src == NULL){
    printf("El archivo no existe \n");
    exit (EXIT_FAILURE);
  } else {
    for(p=0;p<3;p++){
    fgets(texto,130,ejemplo);
    sscanf(texto,"%f %f %f %f %f %f %f %f %f %f %f",&est[0],&tm,&est[1],&tm,&est1[0],&tm,&est1[1],&tm,&emv[0],&emv[1],&emv[2]);
    i=0;
    worst=0;
    ed=sqrt(pow((est[1]-est1[1]),2)+pow((est[0]-est1[0]),2));
    src = fopen(argv[1],"r");
    while (feof(src)==0) {
      fgets(texto,130,src);
      //printf("%s",texto);
      sscanf(texto,"%f %f %f %f %f %f %f %f %f %f %f",&st[0],&tm,&st[1],&tm,&st1[0],&tm,&st1[1],&tm,&mv[0],&mv[1],&mv[2]);
      if(((est[0]-est1[0])<0&&(st[0]-st1[0])<0)||((est[0]-est1[0])>0&&(st[0]-st1[0])>0)){
	if(i<K1){
	  twnear[i][0]=st[0];
	  twnear[i][1]=st[1];
	  twnear[i][2]=st1[0];
	  twnear[i][3]=st1[1];
	  twnear[i][4]=mv[0];
	  twnear[i][5]=mv[1];
	  twnear[i][6]=mv[2];
	  twnear[i][7]=sqrt(pow((st[1]-st1[1]),2)+pow((st[0]-st1[0]),2));
	  if(i!=0){
	    if(abs(twnear[worst][7]-ed)<abs(twnear[i][7]-ed)){
	      worst=i;
	    }
	  }
	}
	else{
	  sd=sqrt(pow((st[1]-st1[1]),2)+pow((st[0]-st1[0]),2));
	  if(abs(twnear[worst][7]-ed)>abs(sd-ed)){
	    twnear[worst][0]=st[0];
	    twnear[worst][1]=st[1];
	    twnear[worst][2]=st1[0];
	    twnear[worst][3]=st1[1];
	    twnear[worst][4]=mv[0];
	    twnear[worst][5]=mv[1];
	    twnear[worst][6]=mv[2];
	    twnear[worst][7]=sd;
	    worst=0;
	    for(r=1;r<K1;r++){
	      if(abs(twnear[worst][7]-ed)<abs(twnear[r][7]-ed))
		worst=r;
	    }
	  }
	}
	i++;
      }
    }
    fclose(src);
    worst=0;
    for(l=0;l<K1;l++){
      if(l<K2){
	tennear[l][0]=twnear[l][0];
	tennear[l][1]=twnear[l][1];
	tennear[l][2]=twnear[l][2];
	tennear[l][3]=twnear[l][3];
	tennear[l][4]=twnear[l][4];
	tennear[l][5]=twnear[l][5];
	tennear[l][6]=twnear[l][6];
	if(l!=0){
	  if(abs(tennear[worst][1]-est[1])<abs(twnear[l][1]-est[1])){
	    worst=l;
	  }
	}
      }
      else{
	if(abs(tennear[worst][1]-est[1])>abs(twnear[l][1]-est[1])){
	  tennear[worst][0]=twnear[l][0];
	  tennear[worst][1]=twnear[l][1];
	  tennear[worst][2]=twnear[l][2];
	  tennear[worst][3]=twnear[l][3];
	  tennear[worst][4]=twnear[l][4];
	  tennear[worst][5]=twnear[l][5];
	  tennear[worst][6]=twnear[l][6];
	  worst=0;
	  for(r=1;r<K2;r++){
	    if(abs(tennear[worst][1]-est[1])<abs(tennear[r][1]-est[1]))
	      worst=r;
	  }
	}
      }
    }
    worst=0;
    for(l=0;l<K2;l++){
      if(l<K3){
	k3near[l][0]=tennear[l][0];
	k3near[l][1]=tennear[l][1];
	k3near[l][2]=tennear[l][2];
	k3near[l][3]=tennear[l][3];
	k3near[l][4]=tennear[l][4];
	k3near[l][5]=tennear[l][5];
	k3near[l][6]=tennear[l][6];
	if(l!=0){
	  if(abs(k3near[worst][3]-est1[1])<abs(tennear[l][3]-est1[1])){
	    worst=l;
	  }
	}
      }
      else{
	if(abs(k3near[worst][3]-est1[1])>abs(tennear[l][3]-est1[1])){
	  k3near[worst][0]=tennear[l][0];
	  k3near[worst][1]=tennear[l][1];
	  k3near[worst][2]=tennear[l][2];
	  k3near[worst][3]=tennear[l][3];
	  k3near[worst][4]=tennear[l][4];
	  k3near[worst][5]=tennear[l][5];
	  k3near[worst][6]=tennear[l][6];
	  worst=0;
	  for(r=1;r<K3;r++){
	    if(abs(k3near[worst][3]-est1[1])<abs(k3near[r][3]-est1[1]))
	      worst=r;
	  }
	}
      }
    }
    worst=0;
    for(l=0;l<K3;l++){
      if(l<K4){
	k4near[l][0]=k3near[l][0];
	k4near[l][1]=k3near[l][1];
	k4near[l][2]=k3near[l][2];
	k4near[l][3]=k3near[l][3];
	k4near[l][4]=k3near[l][4];
	k4near[l][5]=k3near[l][5];
	k4near[l][6]=k3near[l][6];
	if(l!=0){
	  if(abs(abs(k4near[worst][0]-k4near[worst][2])-abs(est[0]-est1[0]))<abs(abs(k3near[l][0]-k3near[l][2])-abs(est[0]-est1[0]))){
	    worst=l;
	  }
	}
      }
      else{
	if(abs(abs(k4near[worst][0]-k4near[worst][2])-abs(est[0]-est1[0]))>abs(abs(k3near[l][0]-k3near[l][2])-abs(est[0]-est1[0]))){
	  k4near[worst][0]=k3near[l][0];
	  k4near[worst][1]=k3near[l][1];
	  k4near[worst][2]=k3near[l][2];
	  k4near[worst][3]=k3near[l][3];
	  k4near[worst][4]=k3near[l][4];
	  k4near[worst][5]=k3near[l][5];
	  k4near[worst][6]=k3near[l][6];
	  worst=0;
	  for(r=1;r<K4;r++){
	    if((abs(abs(k4near[worst][0]-k4near[worst][2])-abs(est[0]-est1[0]))<abs(abs(k4near[r][0]-k4near[r][2])-abs(est[0]-est1[0]))))
	      worst=r;
	  }
	}
      }
    }
    printf("El ejemplo es:\n");
    printf("\tT->X:%f Z:%f\tT1->X:%f Z:%f\n",est[0],est[1],est1[0],est1[1]);
    printf("\tM Vi:%f Vd:%f t:%f\n\n",emv[0],emv[1],emv[2]);
    for(k=0;k<K4;k++){
      printf("\tT->X:%f Z:%f\tT1->X:%f Z:%f\n",k4near[k][0],k4near[k][1],k4near[k][2],k4near[k][3]);
      printf("\t\tM Vi:%f Vd:%f t:%f\n",k4near[k][4],k4near[k][5],k4near[k][6]);
    }
    }
  }

  fclose(ejemplo);
  return 1;
}
