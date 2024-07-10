//Program to concatenate two strings
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string str1, str2, result;
    cout<<"Enter string 1: ";
    getline(cin, str1);
    cout<<"Enter string 2: ";
    getline(cin, str2);

    result = str1 + str2; 
    cout<<result;

    return 0;
}
