//Program to implement a class box and to find the volume and surface area of each box object
//22co16 Joshua Brandon Fernandes 31/08/2023
#include<iostream>
using namespace std;
class box
{
    int length,breadth,height;
    public:
    box()
    {
        length=0;
        breadth=0;
        height=0;
    }

    box(int x,int y,int z)
    {
        length=x;
        breadth=y;
        height=z;
    }

    box(box &t)
    {
        length=t.length;
        breadth=t.breadth;
        height=t.height;
    }

    float volume()
    {
        cout<<"Volume of box="<<length*breadth*height<<endl;
    }
    float surface_area()
    {
        cout<<"Surface area of box="<<2*length*breadth+2*length*height+2*breadth*height<<endl;
    }
};

int main()
{
    box b1(10,10,10),b2(5,5,5);
    b1.volume();
    b1.surface_area();
    box b3(b2);
    b3.volume();
    b3.surface_area();
    return 0;
}


