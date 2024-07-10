//Program to handle the divide by zero exception
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
using namespace std;
class Fraction
{
    float num, den;
    public:
    Fraction(float n, float d)
    {
        num=n;
        den=d;
    }
    float division()
    {
        float temp;
        try
        {
            if(den==0)
            {
                throw den;
            }
            temp = num / den;
            cout<<"Value of "<<num<<" / "<<den<<" is "<<temp;
            cout<<"\n";
        }
        catch(float den)
        {
            cout<<"Cannot divide by Zero\n";
            cout<<"Instead of "<<den<<", "<<num<<" will be divided by 1\n";
            temp = num / 1;
            cout<<"Value of "<<num<<" / 1 is "<<temp;
            cout<<"\n";
        }
        return temp;
    }
};
int main()
{
    float num, den;
    int ch, i=0;
    do
    {
        if(i!=0)
        {
            cout<<"\n";
        }
        cout<<"Enter Numerator: ";
        cin>>num;
        cout<<"Enter Denominator: ";
        cin>>den;
        Fraction f1(num, den);
        f1.division();
        cout<<"\n";
        cout<<"Do you want to continue?\n1.Yes\n2.No\nEnter your choice: ";
        cin>>ch;
        i++;
    }while(ch!=2);
}
