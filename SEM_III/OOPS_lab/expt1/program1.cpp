//prog1:to find the minimum of 3 numbers
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"enter 3 numbers:"<<endl;
    cin>>a>>b>>c;

    if(a<b&&a<c)
        cout<<"minimum number: "<<a;
    else if(b<a&&b<c)
        cout<<"minimum number: "<<b;
    else
        cout<<"minimum number: "<<c;
    return 0;
}
