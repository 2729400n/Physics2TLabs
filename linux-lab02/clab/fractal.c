
// Include the standard library for input output
#include <stdio.h>

// Incliude the standard library that
#include <stdlib.h>

// Include the complex header that allows for complex types
#include <complex.h>

// Include the unix standard header to work on unix with unix compliant stuff
#include <unistd.h>

#include <fcntl.h>

// define a type for complx doubles that can be used to imnply the long form
typedef complex double cdouble;

FILE *fp = NULL;

cdouble deltaXn(cdouble xn, cdouble w);

// The main function that is called after the entry point
// returns an int to represent the exit status
int main(int argc, char **argv)
{
	cdouble w = 1.0, xn = w, dxn = 0;

	// I donmt wanna have to deal with using redirects
	// so implement our own stdout
	close(1);
	fp = fopen("fractal.pgm", "wb");
	dup2(fp->_fileno, 1);

	int a = -2, b = a, size = 500, k = 0;


	fputs("The Program will produce a fractal pattern\r\n", stderr);

	if (argc >= 2)
	{
		sscanf(argv[1], "%d", &size);
	}

	double increment = (4.0 / size);
	printf("P2\r\n%1$d %1$d\r\n3\r\n",size);

	for (a = 0; a <= size; a++){


		for (b = 0; b <= size; b++)
		{

			k = 0;
			xn = ((double)-2 + (double)b * increment) + ((double)-2 + (double)a * increment) * I;
			//fprintf(stderr, "%f + %fi\r\n", creal(xn), cimag(xn));
			do
			{
				xn = xn - (dxn = deltaXn(xn, w));
			} while (((++k) <= 20) && creal(dxn * conj(dxn)) >= 1e-6);

			if (k == 20 && creal(dxn * conj(dxn)) >= 1e-6)
			{

				printf("0");
			}
			else if (creal(xn) > 0)
			{

				printf("1");
			}else if (cimag(xn) > 0)
			{

				printf("2");
			}else if (cimag(xn) < 0)
			{

				printf("3");
			}else{
				printf("0");
			}
			if((b+1)<size)
			printf(" ");
		}
		fflush(fp);
		if((a+1)<size)
		puts("");
	}
	return 0;

}

// The newton-rasephon-seki delta function
// It should take the n-th guess of a root as a complex double then returns
// the difference from the root
cdouble deltaXn(cdouble xn, cdouble w)
{

	return (xn - 1 / (xn * xn)) / 3.0;
}
