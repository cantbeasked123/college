//sstf
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int n,request[20],ch,tdhm=0,i,Count=1,dist=0,index;
 cout<<"Enter the number of requests: ";
 cin>>n;

 cout<<"\nEnter the requests: ";
 for (i=1;i<=n;i++)
 {
  cin>>request[i];
 }
 cout<<"\nEnter the current head position: ";
 cin>>ch;

 while (Count<=n)
 {
  int Min=9999;
  for(i=1;i<=n;i++)
  {
   dist=abs(ch-request[i]);
   if (dist<Min)
   {
    Min=dist;
    index=i;
   }
  }
  tdhm=tdhm+Min;
  ch=request[index];
  request[index]=9999;
  Count++;
 }
cout<<"\nThe total disk head movement is: "<<tdhm<<endl;

return 0;

 }
