
// Include the standard library for input output
#include <stdio.h>

// Incliude the standard library that
#include <stdlib.h>

// Include the unix standard header to work on unix with unix compliant stuff
#include <unistd.h>

// Include the string header to deal with user input
#include <string.h>

// Include the math library
#include <math.h>


// top defining the function sused in th efile as clang will not allow for !!hoisting!!
double deltaXn(double xn, double w);

// The main function that is called after the entry point
// returns an int to represent the exit status
int main(int argc, char **argv)
{	
	// declare our variables we would like to use in the newton-rasephon-seki method
	double w = 1.0, xn = w, dxn = 0;
	char* user = getenv("USER");
	int errno;
	if(user==NULL){
		user="";
	}

	// creater a buffer to store our float value
	// also define our counter and assign as it will be smaller than 255 we can use the (unsigned char data type)
	char buffer[0x64] = {0},k=0;
	getinput:
	// Prompt user for input
	fprintf(stderr,"Enter a number you would like the cube-root of %s!\r\n\x1b[28;5;52m>>>",user);
	printf("\x1b[25m");

	// Get user input to store in the buffer
	fgets(buffer,99,stdin);

	// scan the buffer and get float values to use in the float variable we will pass
	// the reference of the variable as otherwise it would be impossible to mutate the value of th e
	// float variable
	errno = sscanf(buffer,"%lf",&w);
	if(errno<=-1){
		goto getinput;
	}

	printf("Finding the cube root of %.6f\r\n",w);
	xn = w;
	do
	{
		printf("The %d%s guess: %.6f \r\n",k+1,((((k+1)%10)==1)&&(((k+1)%100)!=11))?"st":(((((k+1)%10)==2)&&(((k+1)%100)!=12))? "nd":(((((k+1)%10)==3)&&(((k+1)%100)!=13))?"rd":"th")),xn);
		xn = xn - (dxn = deltaXn(xn, w));

	} while (((++k) <= 20) && (dxn*dxn) >= 1e-12);

	printf("The %d%s guess: %.6f \r\n",k+1,((((k+1)%10)==1)&&(((k+1)%100)!=11))?"st":(((((k+1)%10)==2)&&(((k+1)%100)!=12))? "nd":(((((k+1)%10)==3)&&(((k+1)%100)!=13))?"rd":"th")),xn);
	return 0;
}

// The newton-rasephon-seki delta function
// It should take the n-th guess of a root as a complex double then returns
// the difference from the root
double deltaXn(double xn, double w)
{

	return (xn - w / (xn * xn)) / 3.0;
}
