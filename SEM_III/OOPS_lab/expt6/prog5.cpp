//Write a program to overload ++ operator using friend functions
//22CO20 Harsh Natekar 5/10/2023
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
		friend void operator++(Number& n1);
};

void operator++(Number& n1)
{
	n1.n++;
}


int main()
{
	int x;
	cout<<"Enter a number: "<<endl;
	cin>>x;
	Number n1(x);
	n1.print();
	++n1;
	n1.print();
}

