//Program to handle array index out of bound exception
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
using namespace std;
int main()
{
    int size, i, item;
    int a[100];
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the elements of the array"<<endl;
    for(i=0; i<size; i++)
    {
        cout<<"Value "<<i<<": ";
        cin>>a[i];
    }
    cout<<"\nEnter the Array index to be excessed:"<<endl;
    cin>>item;
    try
    {
        if(item < 0 || item > size)
        {
            throw item;
        }
        cout<<"Value at Array index "<<item<<": "<<a[item];
    }
    catch(int item)
    {
        cout<<"Error: Array index "<<item<<" out of bound.\n";
    }
    return 0;
}
