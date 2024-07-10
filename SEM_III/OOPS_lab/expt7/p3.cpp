//Program to derive a class omnivore from 2 classes herbivore and carnivore
//Joshua Fernandes 22CO16 03/11/23
#include<iostream>
#include<string.h>
using namespace std;
class herbivore
{
    protected:
    string hdiet, hteeth;
    public:
    herbivore(string dh, string th)
    {
        hdiet=dh;
        hteeth=th;
    }
    void displayh()
    {cout<<"Diet:"<<hdiet<<"\nTeeth:"<<hteeth<<endl;}
};

class carnivore
{   
    protected:
    string cdiet, cteeth;
    public:
    carnivore(string dc, string tc)
    {
        cdiet=dc;
        cteeth=tc;
    }
    void displayc()
    {cout<<"Diet:"<<cdiet<<"\nTeeth:"<<cteeth<<endl;}
};

class omnivore: public herbivore,public carnivore
{   
    public:
    omnivore(string dh,string th,string dc, string tc) : herbivore(dh,th),carnivore(dc,tc)
    {
        hdiet=dh;
        hteeth=th;
        cdiet=dc;
        cteeth=tc;
    }
    void display()
    {
        cout<<"Omnivore object created."<<endl;
        displayh();
        displayc();
    }
};

int main()
{
    omnivore o1("plant based","not sharp","meat based","sharp");
    o1.display();
    return 0;
}