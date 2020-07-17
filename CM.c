# include <stdio.h>
# include <stdlib.h>//
#include <string.h>
#include <math.h>
#include "funciones.h"


void centromasa(int j, int na,struct entrada *molA){

	     int    i;
	     double H=1.008, C=12.011, N=14.007, Cl=35.45, O=15.999;
	     int    conC, conN, conO, conH, conCl;
	     double xm, ym, zm, M;


	conC=0; conH=0;    xm=0;
       	conN=0; conCl=0;   ym=0;
	conO=0;            zm=0;


         for( i=0;i<na;i++){                                                           
		 
           if(strcmp(molA[i].el,"C")==0){
             conC++;
 	   xm+=C*molA[i].x;
 	   ym+=C*molA[i].y;
 	   zm+=C*molA[i].z;
 
 	  }  
           if(strcmp(molA[i].el,"H")==0){
             conH++;
 	    xm+=H*molA[i].x;
 	    ym+=H*molA[i].y;
 	    zm+=H*molA[i].z; 
 
 	  }  
           if(strcmp(molA[i].el,"Cl")==0){
             conCl++;
 	    xm+=Cl*molA[i].x;
 	    ym+=Cl*molA[i].y;
 	    zm+=Cl*molA[i].z; 
 	    
 	  }  
           if(strcmp(molA[i].el,"N")==0){
             conN++;
 	    xm+=N*molA[i].x;
 	    ym+=N*molA[i].y;
 	    zm+=N*molA[i].z; 
 
 	  }  
           if(strcmp(molA[i].el,"O")==0){
             conO++;
 	    xm+=O*molA[i].x;
 	    ym+=O*molA[i].y;
 	    zm+=O*molA[i].z; 
 
 	  } 
         }
           M=(conC*C+conH*H+conCl*Cl+conN*N+conO*O);   
           xm=(xm)/M;   
           ym=(ym)/M;
 	  zm=(zm)/M;	  
         printf("Molecula :%d.\n ",j+1);
         printf("numero de atomos. C:%d  H:%d  N:%d  Cl:%d  O:%d\n",conC, conH, conN,conCl,conO);
 
 	              // Cambio de origen al centro al centro de masas y tensor de inercia//
 
 	for(i=0;i<na;i++){
 	   molA[i].x=molA[i].x-xm;
 	   molA[i].y=molA[i].y-ym;
 	   molA[i].z=molA[i].z-zm;
 	}
}
