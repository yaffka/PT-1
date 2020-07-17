#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

void RTAR(double RT[3][3],double A[3][3],double  R[3][3]);

void diagonal( double A[3][3]){

       int    iteracion=0;
       double R[3][3], RT[3][3] ;
       double w, t, c, s, dif, max;

do{
	iteracion++;
      w=(A[1][1]-A[0][0])/(2*A[0][1]);
      t=(-w+(w/(fabs(w)))*(sqrt(pow(w,2)+1)));
      c=1/(sqrt(pow(t,2)+1));
      s=c*t;
      RT[0][0]=c;       R[0][0]=c; 
      RT[0][1]=-s;      R[0][1]=s;
      RT[0][2]=0;       R[0][2]=0;
      RT[1][0]=s;       R[1][0]=-s; 
      RT[1][1]=c;       R[1][1]=c;
      RT[1][2]=0;       R[1][2]=0;
      RT[2][0]=0;       R[2][0]=0;
      RT[2][1]=0;       R[2][1]=0; 
      RT[2][2]=1;       R[2][2]=1; 

      RTAR(RT,A,R);
          dif=fabs(A[0][1])+fabs(A[0][2])+fabs(A[1][0])+fabs(A[1][2])+fabs(A[2][0])+fabs(A[2][1]);
  if(dif>1.e-5){
      w=(A[2][2]-A[0][0])/(2*A[0][2]);
      t=(-w+(w/(fabs(w)))*(sqrt(pow(w,2)+1)));
      c=1/(sqrt(pow(t,2)+1));
      s=c*t;

      RT[0][0]=c;       R[0][0]=c; 
      RT[0][1]=0;       R[0][1]=0; 
      RT[0][2]=-s;      R[0][2]=s; 
      RT[1][0]=0;       R[1][0]=0; 
      RT[1][1]=1;       R[1][1]=1; 
      RT[1][2]=0;       R[1][2]=0; 
      RT[2][0]=s;       R[2][0]=-s; 
      RT[2][1]=0;       R[2][1]=0; 
      RT[2][2]=c;       R[2][2]=c; 


      RTAR(RT,A,R);

          dif=fabs(A[0][1])+fabs(A[0][2])+fabs(A[1][0])+fabs(A[1][2])+fabs(A[2][0])+fabs(A[2][1]);
  }

   if(dif>1.e-5) {
      w=(A[2][2]-A[1][1])/(2*A[1][2]);
      t=(-w+(w/(fabs(w)))*(sqrt(pow(w,2)+1)));
      c=1/(sqrt(pow(t,2)+1));
      s=c*t;

      RT[0][0]=1;       R[0][0]=1; 
      RT[0][1]=0;       R[0][1]=0; 
      RT[0][2]=0;       R[0][2]=0; 
      RT[1][0]=0;       R[1][0]=0; 
      RT[1][1]=c;       R[1][1]=c; 
      RT[1][2]=-s;      R[1][2]=s; 
      RT[2][0]=0;       R[2][0]=0; 
      RT[2][1]=s;       R[2][1]=-s; 
      RT[2][2]=c;       R[2][2]=c; 
      
      RTAR(RT,A,R);
       
          dif=fabs(A[0][1])+fabs(A[0][2])+fabs(A[1][0])+fabs(A[1][2])+fabs(A[2][0])+fabs(A[2][1]);
   }
}
while(dif>1.e-5 && iteracion<1000);

 max=A[0][0];
 for(int k=0;k<3;k++){
	 if(A[k][k]>max){
		 max=A[k][k];
	 }
 }
   A[0][0]=A[0][0]/max;
   A[1][1]=A[1][1]/max;
   A[2][2]=A[2][2]/max;

}
void RTAR(double RT[3][3],double A[3][3],double  R[3][3]){
   
       int    i,j,l;
       double aij;
       double A_1[3][3];	
	
      for(i=0;i<3;i++){                                                                                    
      for(j=0;j<3;j++){
          aij=0;
          for(l=0;l<3;l++){
             aij=aij+RT[i][l]*A[l][j];
          }	  
          A_1[i][j]=aij;
      }	      
   }
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
          aij=0;
          for(l=0;l<3;l++){
             aij=aij+A_1[i][l]*R[l][j];
          }	  
          A[i][j]=aij;
      }	     
   }
}
