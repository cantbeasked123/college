//prog8:to calculate median of an array
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
    {
        int a[100],i,n,m;
        cout<<"enter the size of the array:";
        cin>>n;

        cout<<"enter the elements of the array:"<<endl;
        for(i=0;i<n;i++)
            cin>>a[i];
        m=n/2;
        if(n%2!=0)
            cout<<"median="<<a[m];
        else
            cout<<"median="<<(a[m-1]+a[(m)])*1.0/2;
        return 0;
}
