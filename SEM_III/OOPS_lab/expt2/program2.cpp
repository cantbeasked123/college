//Program to calculate the volume and surface area of a box
//22CO16 Joshua B Fernandes 18/08/23
#include<iostream>
using namespace std;

class box
{
    int len,br,hgt;
    public:
    void setLength(int l){len=l;}
    void setBreadth(int b){br=b;}
    void setHeight(int h){hgt=h;}

    int getLength(){return len;}
    int getBreadth(){return br;}
    int getHeight(){return hgt;}

    int display()
    {
        cout<<"volume of the box:"<<len*br*hgt<<endl<<"surface area of the box:"<<((2*len*br)+(2*len*hgt)+(2*hgt*br))<<endl;
    }
};

int main()
{
    box b[10];
    int i,n,len,br,hgt;

    cout<<"Enter the number of boxes:"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter length,breadth and height of the boxes:"<<endl;
        cin>>len>>br>>hgt;

        b[i].setLength(len);
        b[i].setBreadth(br);
        b[i].setHeight(hgt);

        b[i].getLength();
        b[i].getBreadth();
        b[i].getHeight();

        b[i].display();
    }
    return 0;
}
