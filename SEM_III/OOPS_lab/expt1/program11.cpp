//prog11:to write a menu driven program to determine if a character is  lowercase or uppercase or any other number
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    char a,c;
    int choice=1;
    do
    {
        cout<<"enter an alphabet or a number: ";
        cin>>a;

        if(a>=65 &&a <=90)
            choice=1;
        else if(a>=97 && a<=122)
            choice=2;
        else if(a>=48 && a<=57)
            choice=3;

        switch(choice)
        {
            case 1:cout<<"uppercase";
                   break;

            case 2:cout<<"lowercase";
                   break;

            case 3:cout<<"number";
                   break;
            default:cout<<"invalid input";
        }
        cout<<"\ndo you want to continue?(y/n)"<<endl;
        cin>>c;
    }while(c=='y');
    return 0;
}
