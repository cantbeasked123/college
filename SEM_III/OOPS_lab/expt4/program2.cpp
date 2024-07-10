//Program to implement class Date using various constructors to display each date object in ‘dd-mm-yyyy’ format
//22CO16 Joshua B Fernandes 31/08/2023
#include<iostream>
using namespace std;
class date
{
    int day,month,year;
    public:
    date()
    {
        day=0;month=0;year=0;
    }

    date(int x,int y,int z)
    {
        day=x;
        month=y;
        year=z;
    }

    date(date &d)
    {
        day=d.day;
        month=d.month;
        year=d.year;
    }

    void display()
    {
        cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
    }

};

int main()
{
    date d1,d2(5,10,2010),d3(d2);
    d1.display();
    d2.display();
    d3.display();
    return 0;
}







