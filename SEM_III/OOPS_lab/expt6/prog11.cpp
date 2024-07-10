//Program to overload >, <, <=, >=, == to compare class objects
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

		int operator<(Number n1)
		{
			if(n<n1.n)
				return 1;
			else
				return 0;
		}

		int operator>(Number n1)
		{
			if(n>n1.n)
				return 1;
			else
				return 0;
		}

		int operator<=(Number n1)
		{
			if(n<=n1.n)
				return 1;
			else
				return 0;
		}

		int operator>=(Number n1)
		{
			if(n>=n1.n)
				return 1;
			else
				return 0;
		}
};

int main()
{
	int x,y;
	cout<<"enter two numbers"<<endl;
	cin>>x>>y;
	Number n1(x);
	Number n2(y);
	if(n1<n2)
	cout<<"n1 less than n2"<<endl;
	else if(n2<n1)
	cout<<"n2 less than n1"<<endl;
	else
	cout<<"n1 and n2 are equal"<<endl;
}
