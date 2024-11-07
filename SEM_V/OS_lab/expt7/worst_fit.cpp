#include <iostream>
using namespace std;

int main()
{
  int pno,bno,temp=0,psize[10],bsize[10],flag[10],allocation[10],big=0;

  cout<<"Enter number of processes:";
  cin>>pno;
  cout<<"Enter process sizes:"<<endl;
  for(int i=0;i<pno;i++)
  {
    cout<<"Process "<<(i+1)<<": ";
    cin>>psize[i];
  }
      cout<<endl;
      cout<<"Enter number of blocks:";
      cin>>bno;
      cout<<"Enter block sizes:"<<endl;
  for(int i=0;i<bno;i++)
  {
    cout<<"Block "<<(i+1)<<": ";
    cin>>bsize[i];
    flag[i]=0;
    allocation[i]=-1;
  }

  for(int i=0;i<pno;i++)
  {
    for(int j=0;j<bno;j++)
    {
        if(flag[j] != 1)
        {
            temp = bsize[j]-psize[i];
              if (temp >= 0)
              {
                 if (big <= temp)
                 {
                    allocation[i]=j;
                    big=temp;
                 }
              }
        }
    }
    flag[allocation[i]]=1;
    big=0;
  }
  cout<<"\nProcess number"<<"\t"<<"Process size"<<"\t"<<"Block  number"<<"\t"<<"Block size\n";
  for(int i=0;i<bno;i++)
  {
        cout<<"\nP"<<i+1<<"\t\t"<<psize[i];
    if(allocation[i]  == -1)
     {
      cout<<"\t\tUnallocated";
     }
    else
     {
       cout<<"\t\tB"<<(allocation[i]+1)<<"\t\t"<<bsize[allocation[i]];
     }
  }
  return 0;
}

