//Program throw an exception if users enters a number outside the range [1-99]
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter any number in the range of [1-99] to be printed: ";
    cin>>num;
    try
    {
        if(num<0 || num>99)
        {
            throw num;
        }
        cout<<"\nEntered Number is "<<num<<endl;
    }
    catch(int num)
    {
        cout<<"\nError: The entered number is out of range"<<endl;
    }
    return 0;
}
