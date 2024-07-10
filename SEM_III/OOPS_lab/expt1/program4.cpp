//prog4:to find quotient and remainder of a number
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int num,div,q,r;
    cout<<"enter a number(dividend) and divisor:"<<endl;
    cin>>num>>div;

    cout<<"quotient="<<num/div<<endl;
    cout<<"remainder="<<num%div;
    return 0;
}
