//Program to implement class employee and payslip in external header file
//22CO16 Joshua B Fernandes 24/08/23
#include<iostream>
#include<iomanip>
#include "payslip.h"

using namespace std;
using namespace payslip;

int main()
{

    Employee e;
    Pay p;
    int n,i,id,pos;
    string name;

    cout<<"Enter name, employee id and position:"<<endl;
    cin>>name>>id>>pos;

    e.setName(name);
    e.setEmpID(id);
    e.setPosition(pos);

    cout<<setw(20)<<"NAME:"<<setw(10)<<e.getName()<<endl;
    cout<<setw(20)<<"EMPLOYEE ID:"<<setw(10)<<e.getEmpID()<<endl;
    cout<<setw(20)<<"BASIC PAY:"<<setw(10)<<p.basicPay(e.getPosition())<<endl;
    cout<<setw(20)<<"TRAVEL ALLOWANCE:"<<setw(10)<<p.travelAllow(e.getPosition())<<endl;
    cout<<setw(20)<<"DEAR ALLOWANCE:"<<setw(10)<<p.dearAllow(e.getPosition())<<endl;
    cout<<setw(20)<<"TOTAL PAY:"<<setw(10)<<p.total(e.getPosition())<<endl;

    return 0;
}
