//Program to print the details of students by creating a Student class and include different constructors to initialize data members and also include members functions to display student details
//22co16 Joshua Brandon Fernandes 31/08/2023
#include<iostream>
using namespace std;
class student
{
    int rollno;
    string branch,name;
    public:
    void setRollno(int r){rollno=r;}
    void setName(string n){name=n;}
    void setBranch(string b){branch=b;}

    student()
    {
        rollno=0;
        name="N/A";
        branch="N/A";
    }

    student(int r,string n,string b)
    {
        rollno=r;
        name=n;
        branch=b;
    }

    student(student &s)
    {
        rollno=s.rollno;
        name=s.name;
        branch=s.branch;
    }

    void display()
    {
        cout<<"Name:"<<name<<endl<<"Roll no:"<<rollno<<endl<<"Branch:"<<branch<<endl<<endl;
    }
};

int main()
{
    int roll;
    string name,branch;
    student s1(16,"jake","comp"),s2,s3;
    s1.display();
    s2.display();

    cout<<"Enter student name, roll no and department:"<<endl;
    cin>>name>>roll>>branch;
    cout<<endl;

    s3.setName(name);
    s3.setRollno(roll);
    s3.setBranch(branch);
    s3.display();

    student s4(s1);
    s4.display();

    return 0;
}








