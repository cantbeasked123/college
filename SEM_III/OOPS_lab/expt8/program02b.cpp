//Program to find a substring
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
#include<string>
using namespace std;
int main()
 {
 	string str,substr;
 	cout<<"Enter the main string: "<<endl;
 	getline(cin,str);
 	cout<<"Enter the substring to find: "<<endl;
 	getline(cin,substr);
 	int i;
 	i=str.find(substr);
 	if(i<str.length())
 	 cout<<"Substring found at index: "<<i<<endl;
 	else
 	 cout<<"Substring not found"<<endl;
 	 return 0;
 }

