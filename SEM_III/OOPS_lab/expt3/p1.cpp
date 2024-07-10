// program to calculate the pay of regular and contract employees using method overloading.
//22CO16 Joshua B Fernandes 31/08/23
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;

class Employee
{
    string name;
    int empId;

    public:
    void setname(string n){name=n;}
    void setempId(int id){empId=id;}
    string getName( ){return name;}
    int getempId(){return empId;}
    int pay(int bp,int da,int ta);
    int pay(int amt,int hrs);

};

int Employee::pay(int da,int ta,int bp)
{
    cout<<setw(20)<<"Base pay:"<<setw(10)<<bp<<endl;
    cout<<setw(20)<<"Dear allowance:"<<setw(10)<<da<<endl;
    cout<<setw(20)<<"Travel allowance:"<<setw(10)<<ta<<endl;
    cout<<setw(20)<<"Total pay:"<<setw(10)<<bp+ta+da<<endl;
}

int Employee::pay(int amt,int hrs)
{
    cout<<setw(20)<<"Amount per hour:"<<setw(10)<<amt<<endl;
    cout<<setw(20)<<"Hours worked:"<<setw(10)<<hrs<<endl;
    cout<<setw(20)<<"Total pay:"<<setw(10)<<amt*hrs<<endl;
}

int main()
{
    Employee e;
    int c;
    int amt,hrs;
    string name;
    int empid,bp,da,ta;

    while(1)
    {
        cout<<"\n1.For Regular employee\n2.For Contract employee\n3.exit\nEnter choice:";
        cin>>c;

        switch(c)
        {
            case 1: cout<<"Enter name and employee id:\n";
                    cin>>name>>empid;
                    e.setname(name);
                    e.setempId(empid);

                    cout<<"Enter base pay,dear allowance and travel allowance:\n";
                    cin>>bp>>da>>ta;
                    cout<<setw(20)<<"Name:"<<setw(10)<<e.getName()<<endl;
                    cout<<setw(20)<<"Employee id:"<<setw(10)<<e.getempId()<<endl;
                    e.pay(bp,da,ta);
                    break;

            case 2: cout<<"Enter name and employee id:\n";
                    cin>>name>>empid;
                    e.setname(name);
                    e.setempId(empid);

                    cout<<"Enter amount per hour:\n";
                    cin>>amt;
                    cout<<"Enter number of hours worked:\n";
                    cin>>hrs;
                    cout<<setw(20)<<"Name:"<<setw(10)<<e.getName()<<endl;
                    cout<<setw(20)<<"Employee id:"<<setw(10)<<e.getempId()<<endl;
                    e.pay(amt,hrs);
                    break;

            case 3: exit(0);
                    break;

            default:cout<<"Invalid input";
            }
        }
    return 0;
}
