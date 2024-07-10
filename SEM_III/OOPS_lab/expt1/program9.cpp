//prog9:to calculate the value of F
//22co16 joshua fernandes 04/08/2023
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float e=8.8542,pi=3.1415,f;
    int q1,q2,r1,r2;

    cout<<"enter values of q1 and q2:"<<endl;
    cin>>q1>>q2;
    cout<<"enter values of r1 and r2:"<<endl;
    cin>>r1>>r2;

    f=(1/(4*pi*e))*((q1*q2)/pow(r1,2))*r2;

    cout<<"F="<<f;
    return 0;
}
