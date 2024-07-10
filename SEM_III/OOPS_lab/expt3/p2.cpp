//Program to calculate the volume of cube and cylinder using method overloading
//22CO16 Joshua B Fernandes 25/08/2023

#include<iostream>
#include<stdlib.h>

using namespace std;

int volume(int s)
{
    cout<<"volume of cube="<<s*s<<endl;
}

float volume(int r,int h)
{
    cout<<"volume of cylinder="<<3.1415*r*r*h<<endl;
}

int main()
{
    int s,r,h,choice=1;

    cout<<"1.cube\n2.cylinder\n3.exit"<<endl;

    while(choice!=0)
    {
        cout<<"enter choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"enter side length of cube:"<<endl;
                    cin>>s;
                    volume(s);
                    break;
            case 2: cout<<"enter the radius and height of the cylinder:"<<endl;
                    cin>>r>>h;
                    volume(r,h);
                    break;
            case 3: exit(0);
                    break;
            default:cout<<"invalid input";
        }

    }

    return 0;
}
