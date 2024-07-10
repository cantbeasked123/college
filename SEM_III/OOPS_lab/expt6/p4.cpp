//Program to implement operator overloading on unary minus
//22CO16 Joshua Fernandes 12/09
#include<iostream>
#include<stdlib.h>
using namespace std;
class num
{
    public:
    int val;
    num()
    {val=0;}
    num(int v)
    {val=v;}

    num operator -()
    {val=-val;}
    void display()
    {cout<<"val="<<-val<<endl;}
};

int main()
{
    int a;
    cout<<"Enter number:";
    cin>>a;
    cout<<endl;
    num n(a);
    n.display();
    return 0;
}