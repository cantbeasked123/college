//Program to implement operator overloading on pre and post increment
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

    num operator ++()
    {
        cout<<"++x="<<++val<<endl;
    }                                   //pre increment
    num operator ++(int)
    {
        cout<<"x++="<<val++<<endl;
    }                                   //post increment
    void display()
    {
        cout<<"val="<<val<<endl;
    }
};

int main()
{
    int c,a;
    cout<<"Enter number:";
    cin>>a;
    num n(a);
    do
    {
        cout<<endl<<"1.Pre increment\n2.Post increment\n3.Display current value\n4.Exit\n\nEnter choice:"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:++n;
                   break;
            case 2:n++;
                   break;
            case 3:n.display();
                   break;
            case 4:exit(0);
                   break;
        }
    }while(c!=4);
    return 0;
}