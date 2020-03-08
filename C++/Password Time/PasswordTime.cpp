#include <iostream>
#include "Timer.h"

using namespace std;

void printTime(unsigned long long seconds)
{
	unsigned int nuberOfSeconds[] = {31536000, 86400, 3600, 60};
	string times[] = {" years, "," days, "," hours, "," minutes, "};
	for(int i = 0; i < 4; i++)
	{
		if(seconds > nuberOfSeconds[i])
		{
			cout<<seconds/nuberOfSeconds[i]<<times[i];
			seconds %= nuberOfSeconds[i];
		}
	}
	cout<<seconds<<" seconds.\n";
}

double bruteForceTime()
{
	Timer t;
	string test = "~~~";
	string test2 = "";

	t.start();
	for(int i = 32; i < 127; i++)
		for(int j = 32; j < 127; j++)
			for(int k = 32; k < 127; k++)
			{
				test2 = "";	
				if(test2 == test)
					cout<<"";
			}
	return t.getTime()/2; // Average time
}

long long raiseToPower(int a, int power)
{
	long long returnValue = 1;
	for(int i = 0; i < power; i++)
		returnValue *= a;
	return returnValue;
}
// This program is designed to print the first x prime numbers very quickly
int main()
{
	// getting brute force attack time on current system
	double bruteTime = bruteForceTime(); 
	//initial prompt
	cout<<"Enter passwords between 3 and 12 characters long or *quit* to stop\n";

	// stops when user input *quit*
	string password = "";
	while(password != "*quit*")
	{
		// Prompt user for input
		cout<<"\nEnter password: ";
		cin>>password;

		// Checking if invalid string size
		if(password.size() < 3 || password.size() > 18)
			cout<<"Password size invalid.\n";
		else // Has valid size
		{
			cout<<"This system could brute force hack this password in ";
			// Calculating time
			long double breakTime = bruteTime*raiseToPower(94, (password.size()-3)); // Calculating time
			if (breakTime < 60 && breakTime > 0) // For times less than 1 minute
				cout<<breakTime<<"seconds\n";
			else // For times more than 1 minute
			{
				// Recalculating time in case of extemely long times
				unsigned long long longBreakTime = bruteTime*raiseToPower(94, (password.size()-3));
				printTime(longBreakTime);
			}
		}
	}
}