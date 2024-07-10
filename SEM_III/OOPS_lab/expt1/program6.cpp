//prog6:to print percentage and grade of student in external header file
//22co16 joshua fernandes 04/08/2023
#include<iostream>
#include<string>
#include"grade.h"
using namespace std;
using namespace grade;
int main()
{
    int s1,s2,s3,s4,s5;
    float per;
    char g[5];
    cout<<"enter subject1 marks:";
    cin>>s1;
    cout<<"enter subject2 marks:";
    cin>>s2;
    cout<<"enter subject3 marks:";
    cin>>s3;
    cout<<"enter subject4 marks:";
    cin>>s4;
    cout<<"enter subject5 marks:";
    cin>>s5;

    per=percentage(s1,s2,s3,s4,s5);
    cout<<"percentage:"<<per<<endl;
    cout<<"grade:";
    g[5]=grad(per);
	return 0;
}
