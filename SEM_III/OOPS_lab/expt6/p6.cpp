//Program to implement operator overloading stream insertion and extraction operators
//22CO16 Joshua Fernandes 12/09
#include<iostream>
using namespace std;
class obj
{   int a;
    public:
    friend ostream & operator<<(ostream &out ,obj &op);
    friend istream & operator>>(istream &in,obj &op);
};

ostream & operator<<(ostream &out, obj &op)
{ out<<op.a;
  return out;
}
istream & operator>>(istream &in ,obj &op)
{ in>>op.a;
  return in;
}
int main()
{   obj i1,i2;
    cout<<"Insert 2 objects:"<<endl;
    cin>>i1>>i2;
    cout<<"Display the objects"<<endl;
    cout<<i1<<" "<<i2;
    return 0;
}
