#include <iostream>
#include <fstream>
#include "Timer.h"

using namespace std;

// This program is designed to print the first x prime numbers very quickly
int main()
{
	// Prompting user for size
	int totalPrimes = 0;
	cout<<"How many prime numbers would you like to find? ";
	cin>>totalPrimes;
	// Allocating array and placing two in it, size permitting
	if (totalPrimes < 1)
		return 0;
	int* primes = new int[totalPrimes];
	primes[0] = 2;

	// Starting timer
	Timer t;
	t.start();

	// Finding primes
	int primesFound = 1;
	for ( int possiblePrime = 3; primesFound < totalPrimes; possiblePrime += 2)
	{
		// Assuming every number is prime until proven otherwise
		bool isPrime = true;

		// Comparing number to all previous primes
		for ( int j = 0; j < primesFound && primes[j] * primes[j] <= possiblePrime && isPrime; j++ )
			if ( possiblePrime % primes[j] == 0 )
				isPrime = false;

		// If number is prime add it to the array
		if ( isPrime )
			primes[primesFound++] = possiblePrime;
	}
	// Printing primes and calculation time to file
	double calcTime = t.getTime();
	ofstream fout;
	fout.open("primes.txt");
	fout<<"First "<<totalPrimes<<" prime numbers found in "<<calcTime<<" seconds.\n";
	for (int i = 0; i < totalPrimes; i++)
		fout<<i+1<<' '<<primes[i]<<'\n';
	fout.close();

	// Deallocating memory and printing time facts to console
	delete [] primes;
	cout<<"First "<<totalPrimes<<" prime numbers found in "<<calcTime<<" seconds.\n";
	cout<<"File print time = "<<t.getTime()-calcTime<<" seconds";
}
