//Write a program to add 2 ‘Fraction’ objects using operator overloading concept. Implement using:a) friend functions
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

		void print()
		{
			cout<<"Sum of two Fraction objects: "<<num<<"/"<<denom<<endl;
		}
		friend Fraction operator+(Fraction F1,Fraction F2);
};

Fraction operator+(Fraction F1,Fraction F2)
{
	Fraction temp;
	temp.num=F1.num*F2.denom+F2.num*F1.denom;
	temp.denom=F1.denom*F2.denom;
	return temp;
}

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

