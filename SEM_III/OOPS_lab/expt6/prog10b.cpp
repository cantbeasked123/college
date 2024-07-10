//Write a program to overload pre-decrement and post-decrement operator using b) member functions
//22CO16 Joshua Fernandes 5/10/23
#include<iostream>
using namespace std;
class Number
{
	int n;
	public:
		Number(int x)
		{
			n=x;
		}

		Number()
		{
			n=0;
		}

		Number operator--()
		{
			Number temp;
			temp.n=--n;
			return temp;
		}

		Number operator--(int)
		{
			Number temp;
			temp.n=n--;
			return temp;
		}

		void print()
		{
			cout<<"n= "<<n<<endl;
		}
};

int main()
{
	int x;
	cout<<"Enter a number: "<<endl;
	cin>>x;
	Number n1(x);
	Number n2;
	n2=--n1;
	n2.print();
	n1.print();
	n2=n1--;
	n2.print();
	n1.print();

}
