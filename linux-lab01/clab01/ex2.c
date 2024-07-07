#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

 


int main(argc,argv,environ)
int argc;
char** argv,**environ;
{
    double w=0;
    puts("What value do you wanna find the cube root of?");
    scanf("%lf",&w);
    double x0=w,x1=0,x2=0;
    x1 = ((1/3.0)*((x0)-w/(x0*x0)));
    x2 = ((1/3.0)*((x0)-w/(x1*x1)));
    printf("Finding cube-root of %1$4.1f by NRS. Initial guess: %1$4.1f \n\
First guess: %2$4.1f, Second guess: %3$4.1f",w,x1,x2);
    return 0;
}
