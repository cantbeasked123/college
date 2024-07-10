//Program to implement a class PhoneBook
//22CO16 Joshua B Fernandes 18/08/23
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class PhoneBook {

    string number;
    string name;

    public:
    void setName(string s){name=s;}
    void setNumber(string n){number=n;}

    string getName(){return name;}
    string getNumber(){return number;}
};

int main(){

    PhoneBook p[10];
    string phoneNumber;
    string phoneName;
    int n;

    cout<<"Enter the number of entries:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter name and number:"<<endl;
        cin>>phoneName>>phoneNumber;
        cout<<endl;

        p[i].setName(phoneName);
        p[i].setNumber(phoneNumber);
    }

    cout<<"CONTACT LIST:"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(10)<<p[i].getName()<<setw(20)<<p[i].getNumber()<<endl;
    }

    return 0;
}
