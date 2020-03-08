#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	// A simple test for the Queue implementation
	Queue<int> q;
	for(int i = 0; i < 100; i++)
		q.push(i);

	bool fails = false;
	for(int i = 0; i < 100 && !fails; i++)
		if(q.pop() != i)
			fails = true;
	if(fails)
		cout<<"Test failed\n";
	else
		cout<<"Test successful\n";

	cin.get();
}