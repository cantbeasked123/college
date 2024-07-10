//prog12:to write a menu driven program to find area of triangle,circle,square and a rectangle
//22co16 joshua fernandes 04/08/2023
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int choice;
    char c;
    float x,y,ar,pi=3.1415;

    do
    {

        cout<<"1.triangle\n2.circle\n3.square\n4.rectangle\n"<<endl<<"enter choice: "<<endl;
        c=0,choice=1;
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"enter value of base and height of a triangle:"<<endl;
                    cin>>x>>y;
                    ar=(1.0/2)*x*y;
                    cout<<"area of triangle="<<ar;
                    break;

            case 2: cout<<"enter value of radius of circle:"<<endl;
                    cin>>x;
                    ar=pi*pow(x,2);
                    cout<<"area of circle="<<ar;
                    break;

            case 3: cout<<"enter value of side of a square:"<<endl;
                    cin>>x;
                    ar=pow(x,2);
                    cout<<"area of square="<<ar;
                    break;

            case 4: cout<<"enter value of breadth and width of a rectangle:"<<endl;
                    cin>>x>>y;
                    ar=x*y;
                    cout<<"area of rectangle="<<ar;
                    break;
            case 5: return 0;
            default:cout<<"invalid input";
        }
        cout<<"\ndo you want to continue?(y/n)"<<endl;
        cin>>c;
    }while(c=='y');
    return 0;
}
