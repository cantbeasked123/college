//Write a program to implement a class Complex Nos with data members(real,imag)and include parameterised and copy constructors to initialize data members and also include members functions to compute and display the sum and difference of complex nos.
//22co16 Joshua B Fernandes 31/08/2023
#include<iostream>
#include<stdlib.h>
using namespace std;
class ComplexNos
{
    int real,imag;
    public:
    ComplexNos()
    {   
        real=0;
        imag=0;
    }

    ComplexNos(int x,int y)
    {
        real=x;
        imag=y;
    }

    ComplexNos(ComplexNos &c)
    {
        real=c.real;
        imag=c.imag;
    }

    void display()
    {
        cout<<real<<"+i"<<imag<<endl;
    }

    int add(ComplexNos c1,ComplexNos c2)
    {
        real=c1.real+c2.real;
        imag=c1.imag+c2.imag;
    }

     int sub(ComplexNos c1,ComplexNos c2)
    {
        real=c1.real-c2.real;
        imag=c1.imag-c2.imag;
    }
};

int main()
{
    int real,imag,op;
    ComplexNos c1(5,10),c2(1,5),c3;
    c1.display();
    c2.display();

    do{
        cout<<"Enter operation to be performed:\n1:addition\n2:subtraction\n3:exit\n\n";
        cin>>op;
        cout<<endl;

        switch(op)
        {
            case 1:c3.add(c1,c2);
                    c3.display();
                    break;
            case 2:c3.sub(c1,c2);
                    c3.display();
                    break;
            case 3:cout<<"Exit";
                    exit(0);
            default:cout<<"Invalid input"<<endl;
                    break;
        }
    }while(1);

    return 0;
}


