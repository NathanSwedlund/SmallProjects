#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> s;
	for(int i = 0; i < 10; i++)
		s.push(i);
	for(int i = 0; i < 10; i++)
		cout<<s.pop();
	cin.get();
}