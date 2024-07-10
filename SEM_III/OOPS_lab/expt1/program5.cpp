//prog5:to print average of an array of numbers
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i,sum=0;
    float avg;
    cout<<"enter the size of array:"<<endl;
    cin>>n;
    cout<<"enter the elements of array:"<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    sum=sum+a[i];
    avg=sum*1.0/n;

    cout<<"average="<<avg;
    return 0;
}


