//Write a program to implement conversion routines
//22CO20 Harsh Natekar 5/10/2023
#include<iostream>
#include<math.h>
using namespace std;

class Polar;
class Rectangular
{
 public:
 float x,y;
 Rectangular()
 {
    x=0;
    y=0;
 }
 Rectangular(double a,double b)
 {
    x=a;
    y=b;
 }

 void displayrect()
 {
 cout<<"x="<<x;
 cout<<" y= "<<y;
 }

 Rectangular operator+(Rectangular &r1)
 {
  Rectangular tmp;
  tmp.x=x+ r1.x;
  tmp.y=y+ r1.y;
  return tmp;
 }
};

class Polar
{
 public:
 double r,a;
 Polar()
 {
    r=0;
    a=0;
 }

 Polar(double r1,double a1)
 {
    r=r1;
    a=a1;
 }

 Polar (Rectangular &r1)
 {
  r=sqrt((r1.x*r1.x)+(r1.y*r1.y));
  a= a*tan(r1.y/r1.x);
 }

 operator Rectangular()
 {
    float x,y;
    Rectangular r1;
    r1.x=r*cos(a);
    r1.y=r*sin(a);
    return r1;
 }

 void displaypol()
 {
    cout<<"r= "<<r<<" a= "<<a<<"\n";
 }
};
int main()
{
    float x,y;
    double r,a;
    cout<<"Enter length of the reactangle: "<<endl;
    cin>>x;
    cout<<"Enter the breadth of the reactangle: "<<endl;
    cin>>y;
    Rectangular r1(x,y),r2,r3;
    cout<<"Enter the coordinates of Polar: "<<endl;
    cout<<"Enter the radius: "<<endl;
    cin>>r;
    cout<<"Enter the angle: "<<endl;
    cin>>a;
    Polar p1(r,a),p2,p3;
    r1=p1;
    r2=p2;
    r3=r1+r2;
    p3=r3;
    p3.displaypol();
    r3.displayrect();
    return 0;
}
