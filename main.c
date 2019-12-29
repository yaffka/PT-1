//Yaffet-Zambrano
//Proyecto terminal 1 19P
//compilar gcc -Wall main.c CM.c TI.c jacobi3x3.c -o main -lm
//Ejecutar ./main<archivo_entrada>Archivo_salida
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

int main()
{        
        int     na,nm;
	double energia;
	double A[3][3];
        FILE   *out,*in;
	char   c, filename[50],letra[10];
	int    cont=0;
	double *lambda, *lambda_2, *lambda_3;
	int    *mole;
	int    P;
	double D, y,x,z;


       printf("Nombre del archivo: ");
       scanf("%s", filename);

       in = fopen(filename, "r");
       fscanf(in,"%d",&na);
       for (c = getc(in); c != EOF; c = getc(in))
	       if (c == '\n')
		       cont += 1;
       fclose(in);
       printf("lineas %d\n",cont);
       nm=cont/(na+2);
       printf("El numero de moleculas son: %d\n", nm);
       printf("El numero de atomos por cada molecula es : %d\n\n", na);


      /*                    valres propios de las estructuras seleccionadas             */
	in=fopen(filename,"r");
        out=fopen("chido.iso","w");
	struct entrada molA[16311]={};

    for(int j=0;j<nm;j++){	    

     fscanf(in,"%d",&na);
     fscanf(in,"%s",letra);
     fscanf(in,"%s",letra);
     fscanf(in,"%lf",&energia);
     for(int i=0;i<na;i++){
     fscanf(in,"%s %lf %lf %lf",molA[i].el, &molA[i].x, &molA[i].y, &molA[i].z);
     }
        
	/* centro de masa y contador de atomos */
         centromasa(j, na, molA);

	/*Tensor de inercia*/ 
          tensor(na, molA, A);


        /*valores propios*/
         diagonal(A);	
 
       /*Encontando el valor propio  minimo*/


	 if(A[0][0]<A[1][1] && A[1][1]<A[2][2])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[0][0],A[1][1],A[2][2]);
	 if(A[0][0]<A[2][2] && A[2][2]<A[1][1])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[0][0],A[2][2],A[1][1]);
	 if(A[1][1]<A[0][0] && A[0][0]<A[2][2])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[1][1],A[0][0],A[2][2]);
	 if(A[1][1]<A[2][2] && A[2][2]<A[0][0])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[1][1],A[2][2],A[0][0]);
	 if(A[2][2]<A[0][0] && A[0][0]<A[1][1])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[2][2],A[0][0],A[1][1]);
	 if(A[2][2]<A[1][1] && A[1][1]<A[0][0])
		fprintf(out,"%d %lf %lf %lf  \n",j+1,A[2][2],A[1][1],A[0][0]);

     }
       fclose(out);
       fclose(in);
      //ordenamiento de valores propios 
     mole= (int *) malloc(nm * sizeof(int));
      lambda = (double *) malloc(nm * sizeof(double));
      lambda_2 = (double *) malloc(nm * sizeof(double));
      lambda_3 = (double *) malloc(nm * sizeof(double));

	in=fopen("chido.iso","r");
	for(int l=0; l<nm;l++){
    fscanf(in,"%d %lf %lf %lf",&mole[l], &lambda[l], &lambda_2[l], &lambda_3[l]);
	}
       fclose(in);

    for(int i=0;i<nm;i++){
	    for(int j=i+1;j<nm;j++){
		    D=fabs(lambda[i])-fabs(lambda[j]);
		    if(D>0){
		      P=mole[j];
		      x=lambda[j];	    
		      y=lambda_2[j];
		      z=lambda_3[j];
		      mole[j]=mole[i];
                      lambda[j]=lambda[i];
                      lambda_2[j]=lambda_2[i];
                      lambda_3[j]=lambda_3[i];
		      mole[i]=P;
		      lambda[i]=x;
		      lambda_2[i]=y;
		      lambda_3[i]=z;
		    }
	    }
    } 
    out=fopen("valores.iso","w");
    for(int k=0;k<nm;k++){
	fprintf(out,"%d  %lf  %lf  %lf \n",mole[k], lambda[k], lambda_2[k], lambda_3[k]);
    }
    fclose(out);
     return 0;
 } 
