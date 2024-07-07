/**All byte representation in the file are big endain unless specified otherwise.
 * It is imlplied we are using glibc but libc should work.
 * 0x is the prepend to specifiy the following number is in base 16 ; hexadecimal
 * 0 is the prepend to specifiy the following number is in base 8 ; ocatal
 * 0b is the prepend to specifiy the following number is in base 2 ; binary
*/

// added the stdio.h for linking and compiler preprocessing to allow the compiler to state the
// shape of addition that come from the header. In this instance it will be used for setting up
// the program to use the standard I/O stuff like printf and the likes
#include <stdio.h>

// declare a top level scope value k which is scoped high and may be stored in the code section
// k is top level scoped in the current file and can be used in other sub scopes where it 
// is not redeclared. it is assigned value 4 (0x00000004)
int k = 4;

/*
// this is the start of the "main function", which is the first thing the program "does" when you run it
// return an exit code back to whatever called it this can be checked in the shell with $?.
// $? will be 0 on a successful run of a program and any other value indecating an error otherwise.
// These can be found in th eman page of errno; hius main decleration is one of many allowerd declerations 
// __stdcall int main(int,char**,char**) being the most rigorous and int main() being the least
*/
int main(void) {

	// Declare variable i as an integer and set it to 50
	// 50 is represented by 0x00000032
	int i = 50;

	// declare j as an unsigned integer and set it to the value of i time 2 which his 100; 
	// j is unsigned so no negative values
	// 100 is represented by 0x64
	unsigned int j = i * 2;

	// redeclare as a double k which is initially set to 1.0 which is the double representation of 1 
	// it is represented by 0x3ff0000000000000 in big endian
	// top level scope k is no longer accessable directly using variable name
	double k = 1.0;

	// we create a local code block which allows for redecleration of variables
	// and is identified as an anonymous inner code block as it is not assigned a symbol or a label
	{
		/*
		// declare a floating point variable and sets it to the value 5.0
		// the float variable i which has been created prevents direct access of the outerscope i
		// it is repesented by 0x4014000000000000
		*/ 
		float i = 5.0;

		// print out the value of the float we just created; with size a string size of 6 
		// and a precision 1 decimal place. ;; This prints "The value of i is    5.0\n".
		printf("The value of i is %6.1f\n", i);

		/* assign to k 5.0*100 = 500.0 
		// as double operation normally take precedence when choosing 
		// an arithmetic instruction 
		// at complie time
		// 500.0 is repesented by  of 0x407f400000000000
		*/
		k = i * j;

		// we then assign to the code block local i the value of itself time 6 which give 30.0
		// 30.0 is repesented by  0x403e000000000000
		i *= 6;
	}

	/*
	// Commented out j to fix redecleration in the same scope also it is not used afterwards so 
	// it seems irrelevant
	*/
	//double j; scope redecleration
	

	// i is set to itself plus the value in k  as k is a float float arithmetic is done then the
	// the natural part of the float is taken to form the integer to store in i this results in it being
	// the floor of k + i which is 550
	i = k + i; //or i += k would work just fine
	
	// printf is called and it prints out the value of i using decimal reperesentation 
	// thius prints the string "Now , the value of i is 550\n"
	printf("Now , the value of i is %d\n", i);

	// return 0 from whence main was called from *which is normally the the entry point stub
	// the entry point stub will the preform the halt instruction. The halt instruction will stop the 
	// program execution and prepare to terminate and terminate the program
 	return 0;
}
