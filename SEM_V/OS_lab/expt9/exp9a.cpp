//fcfs
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int n,request[20],ch,tdhm=0,i;
 cout<<"Enter the number of requests: ";
 cin>>n;

 cout<<"\nEnter the requests: ";
 for (i=1;i<=n;i++)
 {
  cin>>request[i];
 }
 cout<<"\nEnter the current head position: ";
 cin>>ch;

 for (i=1;i<=n;i++)
 {
 tdhm= tdhm + abs(ch- request[i]);
  ch=request[i];
 }
 cout<<"\nThe total disk head movement is: "<<tdhm<<endl;

return 0;

}
