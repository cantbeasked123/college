//Program to add two complex numbers using operator overloading
//22C016 Joshua B Fernandes 3/10/2023
#include <iostream>
using namespace std;

class Complex
{
    public:
    float real, imag;
    Complex()
    {
        real=0;
        imag=0;
    }
    Complex(float x, float y)
    {
        real=x;
        imag=y;
    }
    void display()
    {
        cout<<real<<"+i"<<imag<<endl;
    }
    friend Complex operator +(Complex &,Complex &);
};

Complex operator +(Complex &c1,Complex &c2)
{      
        Complex temp;
        temp.real=c1.real+c2.real;
        temp.imag=c1.imag+c2.imag;
        return temp;
}

int main(){
    float x, y;
    cout<<"Enter real and imaginary part of first number:"<<endl;
    cin>>x>>y;
    Complex c1(x, y);
    cout<<"Enter real and imaginary part of second number:"<<endl;
    cin>>x>>y;
    Complex c2(x, y);
    Complex c3;
    c3=c1+c2;
    cout<<"Sum of 2 inserted complex numbers=";
    c3.display();
    return 0;
}


