#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "nwtfr.h"

//#define N 5

int main (int argc, char *argv[]) {
   double xmn, xmx, ymn, ymx, tolcnv;
   int nx, ny, maxit, narr;
   /* Linia de comandes
   int narr double xmn double xmx int nx double ymn double ymx int ny double tolcnv int maxit
   */

   //used but not via command line
   double *px,*dpx,*py,*dpy;
   int arr;
   /*
   int r[10] = {255,000,000,000,255,255,255,255,130,130};
   int g[10] = {210,255,255,255,255,255,000,130,000,130};
   int b[10] = {210,000,255,130,000,130,255,255,130,255};
   */
   // C dona menys problemes si defineixes una constant per
   //La longitud d'un vector

   //double u[N] = {-1,0.5,0.5} ,v[N] = {0,0.866025,-0.866025}; //3
   //double u[N] = {1,0,-1,0} ,v[N] = {0,1,0,-1}; //4
   //double u[N] = {1,0.30901699,-0.8090169,-0.8090169,0.30901699} , v[N] = {0,0.9510565,0.58778525,-0.58778525,-0.9510565}; //5
   //double u[N] = {1,0.70710678,0,-0.70710678,-1,-0.70710678,0,0.70710678} ,v[N] = {0,0.70710678,1,0.70710678,0,-0.70710678,-1,-0.70710678}; //7



   if (argc<10
         || sscanf(argv[1], "%d", &narr)!=1
         || sscanf(argv[2], "%lf", &xmn)!=1
         || sscanf(argv[3], "%lf", &xmx)!=1
         || sscanf(argv[4], "%d", &nx)!=1
         || sscanf(argv[5], "%lf", &ymn)!=1
         || sscanf(argv[6], "%lf", &ymx)!=1
         || sscanf(argv[7], "%d", &ny)!=1
         || sscanf(argv[8], "%lf", &tolcnv)!=1
         || sscanf(argv[9], "%d", &maxit)!=1
      ) {
      fprintf(stderr,"%s narr xmn xmx nx ymn ymx ny tolcnv maxit\n", argv[0]);
      return -1;
   }
   double * u = (double*) malloc(narr * sizeof(double));
   double * v = (double*) malloc(narr * sizeof(double));
   float * r = (float*) malloc(narr * sizeof(float));
   float * g = (float*) malloc(narr * sizeof(float));
   float * b = (float*) malloc(narr * sizeof(float));

   for(int p = 0; p<narr; p++){
       scanf("%lf ", u+p);
       scanf("%lf ", v+p);
       scanf("%fl ", r+p);
       scanf("%fl ", g+p);
       scanf("%fl\n", b+p);

   }

   double dx = (xmx-xmn)/nx;
   double dy = (ymx-ymn)/ny;

   for(double j = xmn; j<xmx; j+=dx){
      for(double k = ymn; k<ymx; k+=dy){
          arr = cnvnwt(j, k, tolcnv, maxit, narr, u, v);
          printf("%f %f %d %d %d\n",j,k,(int)(255*(r[arr])),(int)(255*(g[arr])),(int)(255*(b[arr])));
      }
   }

   return 0;
}
