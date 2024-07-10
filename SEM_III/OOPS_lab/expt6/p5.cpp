//Program to implement operator overloading on pre and post increment using friend functions
//22CO16 Joshua Fernandes 12/09
#include<iostream>
#include<stdlib.h>
using namespace std;
class num
{
    int val;
    public:
    num()
    {val=0;}
    num(int n)
    {val=n;}
    friend num operator++(num &);
    friend num operator++(num &, int);
    void display()
    {cout<<"Val="<<val<<endl;}

};


num operator++(num &x)
{
    cout<<"++x="<<++x.val<<endl;
    return x;
}

num operator++(num &x, int)
{
    cout<<"x++="<<x.val++<<endl;
    return x;
}

int main(){
    int c,a;
    cout<<"Enter number: ";
    cin>>a;
    num n(a);
    do{
        cout<<"\n1. Pre increment\n2. Post increment\n3. Display current value\n4. Exit\n\nEnter choice:";
        cin>>c;
        switch(c)
        {
            case 1: ++n;
                    break;
            case 2: n++;
                    break;
            case 3:n.display();
                    break;
            case 4: exit(0);
                    break;
            default:cout<<"Invalid input!";
                    break;
        }
    }while(c!=4);
}
