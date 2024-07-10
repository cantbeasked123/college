//Program to implement hybrid inheritance
//Joshua Fernandes 22CO16 03/11/23
#include<iostream>
using namespace std;
class student
{
    protected:
    int rollno;
    public:
    void get_rollno(int a)
    {rollno=a;}
    void put_rollno()
    {cout<<"Rollno:"<<rollno<<endl;}
};
class test : public student
{
    protected:
    float p1,p2;
    public:
    void get_marks(int a,int b)
    {   
        p1=a;
        p2=b;
    }
    void put_marks()
    {cout<<"Marks obtained:\n"<<"Subject 1:"<<p1<<"\nSubject 2:"<<p2<<endl;}
};
class sports
{
    protected:
    int score;
    public:
    void get_score(int a)
    {score=a;}
    void put_score()
    {cout<<"Score:"<<score<<endl;}
};

class result: public test, public sports
{
    float total;
    public:
    void display()
    {      
        total=p1+p2+score;
        put_rollno();
        put_marks();
        put_score();
        cout<<"Total score="<<total<<endl;
    }
};

int main()
{
    result s;
    s.get_rollno(55);
    s.get_marks(75.5,86);
    s.get_score(77);
    s.display();
    return 0;
}