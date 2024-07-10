//Program to demonstrate the use of destructors
//22C016 Joshua Brandon Fernandes 31/08/2023
#include<iostream>
using namespace std;
class sample
{
	int x,y;
	public:
		sample(int a,int b)
		{
			x=a;
			y=b;
		}

		~sample()
		{
			cout<<"Object is destroyed"<<endl;
		}

		void display()
		{
			cout<<"x= "<<x<<" "<<"y= "<<y<<endl;
		}
};

int main()
{
	int x,y;
	cout<<"Enter value of x and y: "<<endl;
	cin>>x>>y;
	sample s(x,y);
	{
		int x,y;
		cout<<"Enter value of x1 and y1: "<<endl;
		cin>>x>>y;
		sample s1(x,y);
		s1.display();
	}
	s.display();
}
