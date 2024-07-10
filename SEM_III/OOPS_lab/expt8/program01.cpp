//Write a program to count the no of new line,tabs and whitespace characters in a string
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int newline=0;
    int tabs=0;
    int whitespace=0;
    string a;
    cout<<"Enter a string:";
    getline(cin, a);
    for(char ch : a)
    {
        if(ch=='\n')
        {
            newline++;
        }
        else if(ch=='\t')
        {
            tabs++;
        }
        else if(ch==' ')
        {
            whitespace++;
        }
    }
    cout<<"Newline present in string: "<<newline<<endl;
    cout<<"Tabs present in string: "<<tabs<<endl;
    cout<<"Whitespace(s) present is string: "<<whitespace<<endl;

    return 0;
}