//Program to derive classes doctor,engineer,artist from class person and derive class specialist doctor from doctor
//Joshua Fernandes 22CO16 03/11/23
#include<iostream>
#include<string.h>
using namespace std;
class person
{
    protected:
    string name;
    int age;
    public:
    person(string n,int a)
    {
        age=a;
        name=n;
    }
    void display()
    {
        cout<<"\nName:"<<name<<"\nAge:"<<age<<endl;
    }
};

class doctor: public person
{   
    protected:
    string specialization;
    public:
    doctor(string n,int a,string x):person(n,a)
    {
        specialization=x;
    }
    void display()
    {   
        person::display();
        cout<<"Specialization:"<<specialization<<endl;
    }
};

class engineer: public person
{   
    protected:
    string field;
    public:
    engineer(string n,int a,string f):person(n,a)
    {
        field=f;
    }
    void display()
    {
        person::display();
        cout<<"Field:"<<field<<endl;
    }
};

class artist: public person
{   
    protected:
    string type;
    public:
    artist(string n,int a,string t):person(n,a)
    {
        type=t;
    }
    void display()
    {
        person::display();
        cout<<"Type:"<<type<<endl;
    }
};

class specialist_doctor: public doctor
{   
    protected:
    string speciality;
    public:
    specialist_doctor(string n,int a,string x,string s):doctor(n,a,x)
    {
        speciality=s;
    }
    void display()
    {
        doctor::display();
        cout<<"Speciality:"<<speciality<<endl;    
    }
};

int main()
{
    doctor d("Dr.David Fernandes",40,"neurologist");
    engineer e("James May",33,"Computer");
    artist a("Alex Dsouza",29,"oil painting");
    specialist_doctor s("Dr.Jeremy Wells",50,"cardiologist","electrophysiology");
    d.display();
    e.display();
    a.display();
    s.display();
    return 0;
}