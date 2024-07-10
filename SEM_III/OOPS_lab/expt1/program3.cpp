//prog3:to find multiples of x between 0 and n
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int x,n,i;
    cout<<"enter a number:"<<endl;
    cin>>x;

    cout<<"enter up to which number the multiple is to be found:"<<endl;
    cin>>n;

    cout<<"the multiples of "<<x<<" are:"<<endl;
    for(i=1;i<=n;i++)
    if(i%x==0)
        cout<<i<<endl;
    return 0;
}
