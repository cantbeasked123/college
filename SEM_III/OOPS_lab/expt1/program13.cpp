//prog13:to write a program using if else if ladder to display age categories
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"enter the age:";
    cin>>age;

    if(age>=0&&age<=12)
        cout<<"child";
    else if(age>12&&age<18)
        cout<<"teen";
    else if(age>=18&&age<60)
        cout<<"adult";
    else if(age>=60)
        cout<<"senior citizen";
    else
        cout<<"Invalid input";
    return 0;
}

