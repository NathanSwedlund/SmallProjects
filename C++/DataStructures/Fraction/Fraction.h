#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	return (b==0) ? a : GCD (b, a % b);
}

// Fraction
// --------------------------------------------------------------------------------------------
class Fraction
{
	int denominator;
	int numerator;

public:
	Fraction(int n, int d)
	{
		denominator = d;
		numerator = n;
	}
	Fraction() {}

	int& numerator()   { return numerator;  }
	int& denominator() { return denominator; }

	void simplify();
};

Fraction::simplify()
{
	int factor = GCD(denominator, numerator);
	denominator /= factor; 
	numerator /= factor; 
}

Fraction operator=(Fraction f, double a)
{
	
}

istream& operator>>(istream& in, Fraction& f)
{
	char slash;
	in>>f.numerator()>>slash>>f.denominator();
	f.simplify();
	return in;
}

ostream& operator<<(ostream& out, Fraction f)
{
	f.simplify();
	out<<f.numerator()<<'/'<<f.denominator();
	return out;
}

Fraction operator+(Fraction a, Fraction b)
{
	int temp = b.denominator();
	b.denominator() *= a.denominator();
	b.numerator()   *= a.denominator();
	a.denominator() *= temp;
	a.numerator()   *= temp;

	a.numerator()   += b.numerator();

	a.simplify();
	return a;
} 

Fraction operator-(Fraction a, Fraction b)
{
	b.numerator() *= -1;
	return a+b;
}

Fraction operator*(Fraction a, Fraction b)
{
	a.denominator() *= b.denominator();
	a.numerator() *= b.numerator();

	a.simplify();
	return a;
}
Fraction operator/(Fraction a, Fraction b)
{
	int temp = b.numerator();
	b.numerator() = b.denominator();
	b.denominator() = temp;

	return a*b;
}
// --------------------------------------------------------------------------------------------
