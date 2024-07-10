//Program to implement conversion routines
//22CO16 Joshua Fernandes 12/09
#include <iostream>
#include <math.h>
using namespace std;
class Polar;
class Rectangular
{   public:
    double x,y;
    Rectangular()   {x=y=0;}
    Rectangular(double a,double b)  {   x=a;y=b;    }
    double getX()   {   return x;   }
    double getY()   {   return y;   }
    void setX(double x1)
    {   x=x1;}
    void setY(double y1)
    {   y=y1;   }
    void dispRect()
    {   cout<<"\nx="<<x<<" y="<<y<<endl;}
};

class Polar
{   double theta,r;
    public:
    Polar (){   theta=0;r=0;}
    Polar(double r1,double th){ r=r1;theta=th;}
    void setR(double r1){   r=r1;}
    void setTheta(double th){   theta=th;}
    double getR(){return r;}
    double getTheta(){ return theta;}
    Polar(Rectangular &r1)
    {   r=sqrt((r1.x*r1.x)+(r1.y*r1.y));
        theta=atan(r1.y/r1.x);
    }
    operator Rectangular ()
    {   Rectangular r1;
        r1.x=r*cos(theta);
        r1.y=r*sin(theta);
        return r1;
    }
    void dispPolar(){   cout<<"\n r="<<r<<"\t theta="<<theta<<endl;}
};
int main()
{   Rectangular r1(2,3);
    Polar p1(1,0);//0.785398=45 degrees
    Rectangular r2;
    Rectangular r3(1,1);
    r2=p1;
    Polar p2;
    p2=r3;
    p1.dispPolar();
    r2.dispRect();
    p2.dispPolar();
    r3.dispRect();
    return 0;
}
