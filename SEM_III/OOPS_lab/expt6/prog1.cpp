/*Write a program to add two ‘Complex’ class objects using operator overloading concept.
Overload Binary operator ‘+’ friend functions*/
//22CO20 Harsh Natekar 5/10/2023
#include<iostream>
using namespace std;
class Complex
{
    int real,imag;
    public:
    Complex(int r,int i)
    {
        real=r;
        imag=i;
    }

    Complex()
    {
        real=0;
        imag=0;
    }

    Complex operator+(Complex const& obj)
    {
        Complex temp;
        temp.real=real+obj.real;
        temp.imag=imag+obj.imag;
        return temp;
    }

    void print()
    {
        cout<<real<<"+i"<<imag<<"\n"<<endl;
    }
};

int main()
{
    int real,imag;
	cout<<"Enter real and imaginary part of complex number: "<<endl;
	cin>>real>>imag;
    Complex c1(real,imag);
    cout<<"Enter real and imaginary part of complex number: "<<endl;
	cin>>real>>imag;
    Complex c2(real,imag);
    Complex c3=c1+c2;
    cout<<"Sum of two complex numbers: "<<endl;
	c3.print();
}


