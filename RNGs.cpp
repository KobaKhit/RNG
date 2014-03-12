// This program is a random number generator that uses the random number generaton algorithm 
// "Real Version 2" from the paper "Random Numbers: Good Ones are Hard to Find" by Park and Miller.
// The "Real Version 2" algorithm in the paper on page 3 is presented in Pascal code. In essence this 
// program is the C++ version of "Real Version 2" algorithm written originally in Pascal.

// Author: Park and Miller
// Modified by: Koba Khitalishvili
// Date: 3/12/2014

// "Random Numbers: Good Ones are Hard to Find" can be retrieved from
// http://www.cems.uwe.ac.uk/~irjohnso/coursenotes/ufeen8-15-m/p1192-parkmiller.pdf

#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cmath>


using namespace std;
//------------------------------------------------------------------------------------------
//-------------Global variables-----------------------------------------------------------
//-----------------------------------------------------------------------------------------
	// Used to generate the next random number 
	// in the sequence. 
	// Is used by my_rand()
	unsigned int NEXT_MY_RAND = 1;

	// The upper bound for my_rand() random number generator
	int MY_RAND_MAX =16807;
//-------------------------------------------------------------------------------------------------------
//---------------Prototypes---------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void randomize(int seed = 0);

double my_rand_0_1(void);

int my_rand_int(void);

void my_srand(unsigned int seed);

//-----------------------------------------------------------------------------------------------------
//----------------MAIN PROGRAM-------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

int main()

{
	// Sets seed of the my_rand() function to the time at which it is called 
	randomize();

	cout << "Random numbers" << setw(33) << "Random integers between" 
		 << "\nbetween 0 and 1" << setw(26) << "1 and MY_RAND_MAX" << endl << endl;

	// Outputs two columns of k random numbers
	int k = 10;
	for(int i = 0; i <= k; i++)
	{
		cout << fixed << setw(2) << setprecision(3) << my_rand_0_1() << setw(25) 
			 << my_rand_int() << endl;
	}

	cout << endl << endl;

	return 0;

}

//---------------------------------------------------------------------------------------------
//--------------Subprograms--------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

void my_srand(unsigned int seed)
{	// This routine is used to initialize the
	// sequence of random numbers produced by
	// my_rand()
	//
	// Arguments:
	//   seed - used to provide the next random
	//          number in sequence.
	//          Supply any number here.
	// Side Effect:
	//   Alters the global variable, NEXT_MY_RAND
	
	NEXT_MY_RAND = seed;
}

/////////////////////////////////////////////////////////////////////////////
void randomize(int seed )
{	// Arguments
	//      seed - an integer that is used as a seed for the my_rand() function
	// When provided 0 arguments, it sets the system random number generator 
	// my_rand() to a random seed based on the current clock time. When provided 1 argument, 
	// it uses that argument as a seed for my_rand().

	if(seed == 0) 
	{
		my_srand((unsigned int) time(0));
	}
	else {my_srand(seed);}
}
//////////////////////////////////////////////////////////////////////////////
double my_rand_0_1(void) 
{		
	// Arguments - none.
	// My implementation of the random number generation algorithm from the paper 
	// "Random number generators: Good ones are hard to find" by Park and Miller.
	// Generates a random number between 1 and 0.

	long double a = MY_RAND_MAX,
				m = 2147483647.0,
				q = 127773.0,
				r = 2836.0,
				lo,
				hi, 
				test;

    hi = floor((NEXT_MY_RAND / 127773.0) + 0.5); // is equivalent to Trunc(seed/q) in the original algorithm
    lo = NEXT_MY_RAND - q * hi;
    test = a * lo - r * hi;

    if(test > 0.0) {NEXT_MY_RAND = test;}
    else{NEXT_MY_RAND = test + m;}

    long double random_0_1 =  NEXT_MY_RAND / m; // the random floating point number between 0 and 1
	
    return(random_0_1);
}
///////////////////////////////////////////////////////////////////////////////////////////////
int my_rand_int(void)
{
	// Arguments - none.
	// Generates a random integer between 1 and a global variable MY_RAND_MAX.

	// random integer between 1 and a where a is MY_RAND_MAX
	int random_int = floor(my_rand_0_1() * MY_RAND_MAX + 0.5); 
	
	return(random_int);
}
