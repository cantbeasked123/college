//Program to demonstrate multiple catch statements
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
using namespace std;
int main()
{
    try
    {
        throw 100;
        cout<<"After throw"<<endl;
    }
    catch(char exep)
    {
        cout<<"Char exception Caught"<<endl;
    }
    catch(...)
    {
        cout<<"Default exception caught"<<endl<<endl;
    }
    cout<<"After catch"<<endl;
    return 0;
}
