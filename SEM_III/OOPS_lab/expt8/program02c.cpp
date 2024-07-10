//Program to spilt a string
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string main_string;
    string spilt;
    string left = "";
    string right = "";

    cout<<"Enter string: ";
    getline(cin, main_string);
    int len = main_string.length();

    cout<<"Enter character to which the string should spilt: ";
    getline(cin, spilt);

    int found = main_string.find(spilt);
    if(found)
    {
        for(int i=0;i<len;i++)
        {
            if(i<found)
            {
                left = left + main_string[i];
            }
            else
            {
                right = right + main_string[i];
            }
        }
        cout<<"Left part of the string: "<<left<<endl;
        cout<<"Right part of the string: "<<right<<endl;
    }
    else
    {
        cout<<"Character not found in main string"<<endl;
    }

    return 0;

}
