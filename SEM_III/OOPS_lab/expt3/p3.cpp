//Write a program to calculate the area of circle and triangle using method overloading.
//joshua fernandes 22co16 25/08/2023

#include<iostream>
#include<stdlib.h>

using namespace std;

float area(int r)
{
    cout<<"area of circle="<<3.1415*r*r<<endl;
}

float area(int b,int h)
{
    cout<<"area of triangle="<<0.5*b*h<<endl;
}

int main()
{
    int r,b,h,choice=1;
    cout<<"1.circle\n2.triangle\n3.exit"<<endl;

    while(choice!=0)
    {
        cout<<"enter choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"enter radius of circle:"<<endl;
                    cin>>r;
                    area(r);
                    break;
            case 2: cout<<"enter the base and height of triangle:"<<endl;
                    cin>>b>>h;
                    area(b,h);
                    break;
            case 3: exit(0);
                    break;
            default:cout<<"invalid input";
        }

    }

    return 0;
}
