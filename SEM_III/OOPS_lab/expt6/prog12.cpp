//Program to use operatr overloading to convert 'Feet' object to Inches' object
//22CO16 Joshua Fernandes 5/10/23
#include <iostream>
#include<stdlib.h>
using namespace std;
class Feet;
class Inches;
class Feet{
    double l;
    public:
    //Constructors
    Feet(){}

    Feet(double d){
        l=d;
    }
    //Function to set length
    void setLength(double length)
    {l=length;}
    //Function to set
    double getLength()
    {return l;}

    void display(){
        cout<<l;
    }

    operator Inches();
    void operator=(Inches);
};

class Inches{
    double l;
    public:
    Inches(){}

    Inches(double d)
    {l=d;}

    void setLength(double length)
    {l=length;}

    double getLength()
    {return l;}

    void display(){
        cout<<l;
    }

    operator Feet();

    void operator=(Feet);
};

//Overloading = operator to convert Inches to Feet
void Feet::operator=(Inches x){
    l=x.getLength()/12.0;
}

//Overloading = operator to convert Feet to Inches
void Inches::operator=(Feet x){
    l=x.getLength()*12.0;
}

//Overlaoding casting operator to convert Feet to Inches
Feet :: operator Inches(){
    Inches temp(l*12.0);
    return temp;
}

//Overloading casting operator to convert Inches to Feet
Inches :: operator Feet(){
    Feet temp(l/12.0);
    return temp;
}



int main(){
    double d;
    int c;
    Inches i;
    Feet f;
    do{
        cout<<"\n\nConvert:\n1.Feet to inches\n2.Inches to feet\n3.Exit\nEnter choice:";
        cin>>c;
        switch(c){
            case 1: cout<<"Enter length in feet: ";
                    cin>>d;
                    f=Feet(d);
                    i=f;
                    cout<<"Length in Inches: "; i.display();
                    break;
            case 2: cout<<"Enter length in inches: ";
                    cin>>d;
                    i=Inches(d);
                    f=Feet(i);
                    cout<<"Length in Feet: "; f.display();
                    break;
            case 3: exit(0);
                    break;
            default:cout<<"Invalid input!";
        }
    }while(c!=3);
    return 0;
}