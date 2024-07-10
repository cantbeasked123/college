//Program to implement operator overloading on array subscript operator
//22CO16 Joshua Fernandes 12/09
#include <iostream>
#include <stdlib.h>
using namespace std;
class Array 
{
    int num[10];
    int size;
    public:
    void setArray()
    {
        cout<<"Enter the no of elements"<<endl;
        cin>>size;
        cout<<"Enter the elements:"<<endl;
        for(int i=0;i<size;i++)
        {cin>>num[i];}
    }
    int & operator[](int x)
    {   
        if(x>=size)
        { 
            cout<<"Array out of bounds"<<endl;
            exit(0);
        }
        else
        {return num[x];}
    }
    void display()
    {   
        for(int i=0;i<size;i++)
        {cout<<num[i]<<endl;}
    }
};

int main()
{   Array a1;
    a1.setArray();
    int x=a1[3];
    cout<<"x="<<x<<endl;
    return 0;
}
