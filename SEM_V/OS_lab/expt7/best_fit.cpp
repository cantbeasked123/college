#include <iostream>
using namespace std;

int main()
{
  int pno,bno,temp,psize[10],bsize[10],flag[10],allocation[10],small=999;

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
                 if (small >= temp)
                 {
                    allocation[i]=j;
                    small=temp;
                 }
              }
        }
    }
    flag[allocation[i]]=1;
    small=999;
  }
  cout<<"\nProcess number"<<"\t"<<"Process size"<<"\t"<<"Block number"<<"\t"<<"Block size\n";
  for(int i=0;i<bno;i++)
  {
        cout<<"\nP"<<i+1<<"\t\t"<<psize[i];
    if(flag[i]==1)
     {
       cout<<"\t\tB"<<(allocation[i]+1)<<"\t\t"<<bsize[allocation[i]];
     }
    else
     {
      cout<<"\t\tUnallocated";
     }
  }
  return 0;
}

