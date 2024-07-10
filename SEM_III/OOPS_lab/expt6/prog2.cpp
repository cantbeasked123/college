/*Write a program to add two ‘Complex’ class objects using operator overloading concept.
Overload Binary operator ‘+’.Write the above program using friend functions*/
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


    void print()
    {
        cout<<real<<"+i"<<imag<<"\n"<<endl;
    }
    friend Complex  operator+(Complex const& obj1, Complex const& obj2);
};

Complex operator+(Complex const& obj1, Complex const& obj2)
    {
        Complex temp;
        temp.real=obj1.real+obj2.real;
        temp.imag=obj1.imag+obj2.imag;
        return temp;
    }

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
