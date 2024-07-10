/*Write a program to design a class complex to represent complex numbers. The
complex class should use an external function (use it as friend function) to add
two complex numbers. The function should return an object of type complex
representing the sum of two complex numbers.*/
//22CO16 Joshua B Fernandes 19/09/2023
#include<iostream>
using namespace std;
class Complex
{
    int real,imag;
    public:
    Complex()
    {
        real=0;
        imag=0;
    }

    Complex(int r,int i)
    {
        real=r;
        imag=i;
    }

    friend Complex add(Complex &c1,Complex &c2);

    void display()
    {
        cout<<"Complex number="<<real<<"+i"<<imag<<endl;
    }
};

Complex add(Complex &c1, Complex &c2)
{
    Complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return c3;
}

int main()
{
    int real,imag;
    cout<<"Enter the real and imaginary part of 1st complex number:"<<endl;
    cin>>real>>imag;
    Complex c1(real,imag);
    cout<<"Enter the real and imaginary part of 2nd complex number:"<<endl;
    cin>>real>>imag;
    Complex c2(real,imag);
    Complex c3;
    c3=add(c1,c2);
    c3.display();
    return 0;
}
