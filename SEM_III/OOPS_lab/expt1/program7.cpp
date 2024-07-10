//prog7:to print min,max and average of an array of numbers
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int a[100],i,n,mn,mx;
    float sum=0;
    cout<<"enter the size of array:";
    cin>>n;
    cout<<"enter the elements of the array:\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    mx=a[0]; mn=a[0];

    for(i=0;i<n;i++)
    {
        if(mn>a[i])
            mn=a[i];
        if(mx<a[i])
            mx=a[i];
    }
    cout<<"minimum ="<<mn<<endl;
    cout<<"maximum ="<<mx<<endl;

    for(i=0;i<n;i++)
        sum=sum+a[i];

    cout<<"average="<<sum/n;
    return 0;
}


