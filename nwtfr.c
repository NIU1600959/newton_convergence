#include <stdio.h>
#include <math.h>

void avalp (double x, double y, double *px, double *py, int n, double u[], double v[]) {
    double a0,a1,b0,b1,a2,b2;
    a0 = x-u[0];
    b0 = y-v[0];
    for(int i = 0; i < n-1; i++){
        a1 = x-u[i+1];
        b1 = y-v[i+1];
        a2 = a0*a1-b0*b1;
        b2 = b0*a1+b1*a0;
        a0 = a2;
        b0 = b2;
    }
    *px = a0;
    *py = b0;
}

void avaldp (double x, double y, double *dpx, double *dpy, int n, double u[], double v[]) {
    double a2,b2;
    *dpx =0;
    *dpy = 0;

    for(int j = 0; j <= n-1; j++){
        double a0 = 1;
        double b0 = 0;
        for(int i = 0; i <= n-1; i++){
            if (i != j){
                double a1 = x-u[i];
                double b1 = y-v[i];

                a2 = a0*a1-b0*b1;
                b2 = b0*a1+b1*a0;
                a0 = a2;
                b0 = b2;
            }
        }
      *dpx += a0;
      *dpy += b0;
    }

}

int cnvnwt (double x, double y, double tolcnv, int maxit, int n, double u[], double v[]) {
    double x0, y0, diff, div;
    double a, b, c, d;
    int j = 0; //iteracions d'arrels
    for (j = 0; j < n; j++){
        x0 = x;
        y0 = y;
        diff = pow((pow((u[0]-x0),2)+pow((v[0]-y0),2)),0.5); //mirem la inicial
        int i = 0; //mini iteracions
        while (diff >= tolcnv && i < maxit){
            //volem trobar les noves x0,y0
            avalp(x0,y0,&a,&b,n,u,v);
            avaldp(x0,y0,&c,&d,n,u,v);
            div = (c)*(c)+(d)*(d);
            x0 -= ((a)*(c)+(b)*(d))/div; //part real del resultat de p/p'
            y0 -= ((b)*(c)-(a)*(d))/div; //part imag del resultat de p/p'
            i++;
            //printf("%16g, %16g\n", x0 , y0);
            //diff = ((u[j]-x0)**2+(v[j]-y0)**2)**1/2;
            diff = pow((pow((u[j]-x0),2)+pow((v[j]-y0),2)),0.5);
            if(diff<tolcnv){
                return round(j);
            }
        }
    }
    return -1;

}
