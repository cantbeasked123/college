//Write a program to overload array subscript [] operator
//22CO20 Harsh Natekar 5/10/2023
#include<iostream>
using namespace std;
class Number
{
    public:
    int num[100];
    int size;

    void intArray()
    {
        cout<<"Enter size: "<<endl;
        cin>>size;
        cout<<"Enter"<<size<<"elements: "<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>num[i];
        }

        int & operator[](int x)
        {
            if(x>size)
            {
                cout<<"Out of bounds";
                exit(0);
            }
            else
            {
                return num[x];
            }
        }
};

int main()
{
    Number n1;
    n1.intArray();
    int q=n1[3];
    cout<<q;
    return 0;
}

