//Write a program to overload unary minus operator using member function
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

		void operator-()
		{
			n=-n;
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
	n1.print();
	-n1;
	n1.print();
}
