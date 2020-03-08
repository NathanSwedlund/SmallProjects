#include <iostream>

using namespace std;
bool isprime(int a);


int main()
{
    // Get input
    int a;


    cout<<"Enter Number Or Zero To Stop: ";
    cin>>a;
    while(a != 0)
    {
        cout<<"Enter Number: ";
        cin>>a;

        // Finding prime factors
        for(int i = 2; i <= a; i++)
        {
            if(a % i == 0)
            {
                cout<<i<<", ";
                a /= i;
                i = 1;
            }
        }
    }
}
