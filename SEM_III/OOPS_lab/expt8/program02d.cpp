//Program to convert string to lowercase and vice versa
//22CO16 Joshua Fernandes 7/11/23
#include<iostream>
#include<string>
using namespace std;

string lwr(const string& input)
 {
 	string result;
 	for(int i=0;i<input.length();i++)
 	 {
 	 	char ch=input[i];
		result+= static_cast<char>(tolower(static_cast<unsigned char>(ch)));	
	 } 
	return result;
 }
string upr(const string& input)
 {
 	string result;
 	for(int i=0;i<input.length();i++)
 	 {
 	 	char ch=input[i];
		result+= static_cast<char>(toupper(static_cast<unsigned char>(ch)));
	 } 
	return result;
 }

int main()
 {
 	
	string s,lowercase,uppercase;
	cout<<"Enter a string: "<<endl;
 	getline(cin,s);
 	lowercase=lwr(s);
 	cout<<"String in lowercase: "<<lowercase<<endl;
 	uppercase=upr(s);
 	cout<<"String in uppercase: "<<uppercase<<endl;
 	return 0;
 } 
