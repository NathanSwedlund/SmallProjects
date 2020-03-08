#include <iostream>
#include "Relations.h"
using namespace std;

int main()
{
	Relation<int> R, H;
	R.insert(1,1);
	R.insert(2,2);
	H.insert(1,1);
	H.insert(3,3);

	Relation<int> W = R-H;

	for(int i = 0; i < 5; i++)
	{
		cout<<W.relates(i, i);
	}

    cin.ignore();
    cin.get();
}