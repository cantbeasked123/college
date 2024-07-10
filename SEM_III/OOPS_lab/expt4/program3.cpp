//Program to implement a class Solid using various constructors to compute volume of cylinder and cone.Include default argument for the data member ‘radius’.
//22co16 Joshua B Fernandes 31/08/2023
#include<iostream>
using namespace std;
class solid
{
    float radius,height;
    public:
    solid()
    {
        radius=0;
    }

    solid(float r,float h)
    {
        radius=r;
        height=h;
    }

    solid(solid &x)
    {
        radius=x.radius;
        height=x.height;
    }

    void vol_cylinder()
    {
        cout<<"Volume of cylinder="<<3.1415*radius*radius*height<<endl;
    }
    void vol_cone()
    {
        cout<<"Volume of cone="<<0.333*3.1415*radius*radius*height<<endl;
    }
};

int main()
{
    solid s1(5,10),s2(10,10),s3(s2);
    s1.vol_cylinder();
    s1.vol_cone();
    s2.vol_cylinder();
    s2.vol_cone();
    s3.vol_cylinder();
    s3.vol_cone();
    return 0;
}







