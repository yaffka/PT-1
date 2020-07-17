# include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

void tensor( int na, struct entrada *molA,double A[3][3]){

	int    i;
	double Ixx, Iyy, Izz, Ixy, Ixz, Iyz;
	double H=1.008, C=12.011, N=14.007, Cl=35.45, O=15.999;
	
	 Ixx=0; Ixy=0; 	
         Iyy=0; Ixz=0;
	 Izz=0; Iyz=0;


	for(i=0;i<na;i++){
          if(strcmp(molA[i].el,"C")==0){

	   Ixx+=C*(pow(molA[i].y,2.f)-pow(molA[i].z,2.f));
	   Iyy+=C*(pow(molA[i].x,2.f)-pow(molA[i].z,2.f));
	   Izz+=C*(pow(molA[i].z,2.f)-pow(molA[i].y,2.f));
	   Ixy+=-C*(molA[i].x)*(molA[i].y);
	   Ixz+=-C*(molA[i].x)*(molA[i].z);
	   Iyz+=-C*(molA[i].y)*(molA[i].z);
          }		  

          if(strcmp(molA[i].el,"H")==0){

	   Ixx+=H*(pow(molA[i].y,2.f)-pow(molA[i].z,2.f));
	   Iyy+=H*(pow(molA[i].x,2.f)-pow(molA[i].z,2.f));
	   Izz+=H*(pow(molA[i].z,2.f)-pow(molA[i].y,2.f));
	   Ixy+=-H*(molA[i].x)*(molA[i].y);
	   Ixz+=-H*(molA[i].x)*(molA[i].z);
	   Iyz+=-H*(molA[i].y)*(molA[i].z);
          } 

          if(strcmp(molA[i].el,"Cl")==0){

	   Ixx+=Cl*(pow(molA[i].y,2.f)-pow(molA[i].z,2.f));
	   Iyy+=Cl*(pow(molA[i].x,2.f)-pow(molA[i].z,2.f));
	   Izz+=Cl*(pow(molA[i].z,2.f)-pow(molA[i].y,2.f));
	   Ixy+=-Cl*(molA[i].x)*(molA[i].y);
	   Ixz+=-Cl*(molA[i].x)*(molA[i].z);
	   Iyz+=-Cl*(molA[i].y)*(molA[i].z);
          }
 
          if(strcmp(molA[i].el,"N")==0){

	   Ixx+=N*(pow(molA[i].y,2.f)-pow(molA[i].z,2.f));
	   Iyy+=N*(pow(molA[i].x,2.f)-pow(molA[i].z,2.f));
	   Izz+=N*(pow(molA[i].z,2.f)-pow(molA[i].y,2.f));
	   Ixy+=-N*(molA[i].x)*(molA[i].y);
	   Ixz+=-N*(molA[i].x)*(molA[i].z);
	   Iyz+=-N*(molA[i].y)*(molA[i].z);
          }

          if(strcmp(molA[i].el,"O")==0){

	   Ixx+=O*(pow(molA[i].y,2.f)-pow(molA[i].z,2.f));
	   Iyy+=O*(pow(molA[i].x,2.f)-pow(molA[i].z,2.f));
	   Izz+=O*(pow(molA[i].z,2.f)-pow(molA[i].y,2.f));
	   Ixy+=-O*(molA[i].x)*(molA[i].y);
	   Ixz+=-O*(molA[i].x)*(molA[i].z);
	   Iyz+=-O*(molA[i].y)*(molA[i].z);
	  }	  
	}
        A[0][0]=Ixx;
	A[0][1]=Ixy;
	A[0][2]=Ixz;
	A[1][0]=Ixy;
	A[1][1]=Iyy;
	A[1][2]=Iyz;
	A[2][0]=Ixz;
	A[2][1]=Iyz;
	A[2][2]=Izz;

}
