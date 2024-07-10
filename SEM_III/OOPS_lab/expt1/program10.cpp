//prog10:to read an alphabet and check whether it is a vowel or a consonant
//22co16 joshua fernandes 04/08/2023
#include<iostream>
using namespace std;
int main()
{
    char c;
    cout<<"enter an alphabet: ";
    cin>>c;

    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        cout<<"the alphabet is a vowel";
    else
        cout<<"the alphabet is a consonant";
    return 0;
}
