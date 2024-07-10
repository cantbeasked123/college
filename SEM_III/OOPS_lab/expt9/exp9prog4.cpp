//Program to implement rethrowing of an exception
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
using namespace std;
double div(double num, double den)
{
    try
    {
        if (den==0)
        {
            throw den;
        }
        double value = num / den;
        return value;
    }
    catch(double den)
    {
        cout<<"Error in function: Cannot divide by zero"<<endl;
        throw;
    }
}
int main()
{
    double num, den, value;
    cout<<"Enter Dividend and Divisor: ";
    cin>>num>>den;
    try
    {
        value = div(num, den);
        cout<<"\nValue of "<<num<<" / "<<den<<" = "<<value;
    }
    catch(double n)
    {
        cout<<"Error in main: Cannot divide by zero"<<endl;
    }
    return 0;
}
