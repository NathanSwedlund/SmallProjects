#include <iostream>
#include "AbstractSet.h"
using namespace std;

int main(){
	AbstractSet<int> s;

	// "Adding" prime numbers
	s.addCondition([](int a){
		bool prime = (a % 2 || a == 2);
		for(int i = 3; i*i <= a && prime; i += 2)
			prime = (a % i != 0);
		return prime;
	});
	s.addCondition( [] (int a) { return a < 0; } );

	for(int a = -100; a < 100; a ++)
		cout<<a<<' '<<s.contains(a)<<'\n';

    cin.ignore();
    cin.get();
}