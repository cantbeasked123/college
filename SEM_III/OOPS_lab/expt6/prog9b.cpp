//Write a program to add 2 ‘Fraction’ objects using operator overloading concept. Implement using:b) member functions
//22CO16 Joshua Fernandes 5/10/23
#include<iostream>
using namespace std;
class Fraction
{
	int num,denom;
	public:
		Fraction(int n,int d)
		{
			num=n;
			denom=d;
		}

		Fraction()
		{
			num=0;
			denom=0;
		}

		Fraction operator+(Fraction F)
		{
			Fraction temp;
			temp.num=num*F.denom+F.num*denom;
			temp.denom=denom*F.denom;
			return temp;
		}

		void print()
		{
			cout<<"Sum of two Fraction objects: "<<num<<"/"<<denom<<endl;
		}
};

int main()
{
	int num,denom;
	cout<<"Enter numerator and denominator of first Fraction object: "<<endl;
	cin>>num>>denom;
    Fraction f1(num,denom);
    cout<<"Enter numerator and denominator of second Fraction object: "<<endl;
	cin>>num>>denom;
    Fraction f2(num,denom);
    Fraction f3=f1+f2;
	f3.print();
}


