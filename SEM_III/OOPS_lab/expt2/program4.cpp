//Program to perform basic arithmetic operations
//22CO16 Joshua B Fernandes 24/08/23
#include<iostream>
#include<math.h>
using namespace std;

class calculator
{
    int x,y;

    public:
    int add(int x,int y){return(x+y);}
    int sub(int x,int y){return(x-y);}
    int mul(int x,int y){return(x*y);}
    float div(float x,float y){return(x/y);}
    int power(int x,int y){return pow(x,y);}
};

int main()
{
    calculator c;
    int x,y;
    cout<<"Enter 2 numbers:"<<endl;
    cin>>x>>y;
    cout<<endl;

    cout<<"Calculations:"<<endl;
    cout<<"sum="<<c.add(x,y)<<endl;
    cout<<"sub="<<c.sub(x,y)<<endl;
    cout<<"mul="<<c.mul(x,y)<<endl;
    cout<<"div="<<c.div(x,y)<<endl;
    cout<<"pow="<<c.power(x,y)<<endl;
    return 0;
}

