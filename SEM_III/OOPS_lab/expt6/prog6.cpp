//Overloading stream insertion and extraction operator
//22CO20 Harsh Natekar 5/10/2023
#include <iostream>
using namespace std;
class Complex
{
	int real, imag;
	public:
	Complex(int r = 0, int i =0)
	{
		real = r;
		imag = i;
	}

	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter the real part of the complex number:  ";
	in >> c.real;
	cout << "Enter the imaginary part of the complex number:  ";
	in >> c.imag;
	return in;
}

int main()
{
Complex c1;
cin >> c1;
cout << "The complex number is: ";
cout << c1;
return 0;
}

