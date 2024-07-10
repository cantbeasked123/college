//Write a program to overload pre-decrement and post-decrement operator using a) friend functions
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

		void print()
		{
			cout<<"n= "<<n<<endl;
		}
		friend Number operator--(Number& n1);
		friend Number operator--(Number& n1,int);
};

Number operator--(Number& n1)
{
	Number temp;
	temp.n=--n1.n;
	return temp;
}

Number operator--(Number& n1,int)
		{
			Number temp;
			temp.n=n1.n--;
			return temp;
		}

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
