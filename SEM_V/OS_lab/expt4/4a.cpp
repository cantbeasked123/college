#include<iostream>
using namespace std;

int main()
{
   int n,ts,P[10],bt[10],rem_bt[10],wt[10],tt[10],i,t=0;
   float awt=0,att=0,tawt=0,tatt=0;
   bool flag;
   cout<<"Enter the no. of processes: ";
   cin>>n;
   cout<<"Enter the burst time for process:"<<endl;
   for(i=1;i<=n;i++)
   {
      P[i]=i;
      cout<<"P["<<i<<"]: ";
      cin>>bt[i];
      rem_bt[i]=bt[i];
   }
   
   cout<<"\nEnter the time slice: ";
   cin>>ts;

   while(true)
   {
      flag=true;
      for(i=1;i<=n;i++)
      {
         if(rem_bt[i]>0)
         {
            flag=false;
            if(rem_bt[i]>ts)
            {
               t=t+ts;
               rem_bt[i]=rem_bt[i]-ts;
            }
            else
            {
               t=t+rem_bt[i];
               rem_bt[i]=0;
               wt[i]=t-bt[i];
            }
         }
      }
      if(flag==true)
      {
         break;
      }
   }
   
   for(i=1;i<=n;i++)
   {
      tt[i]=wt[i]+bt[i];
      tawt=tawt+wt[i];
      tatt=tatt+tt[i];
   }
   awt=tawt/n;
   att=tatt/n;

   cout<<"\nProcess\tBT\tWT\tTT\n";
   for(i=1;i<=n;i++)
   {
      cout<<"P"<<P[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";
   }
   cout<<"\nAverage Waiting time = "<<awt;
   cout<<"\nAverage Turnaround time = "<<att;
   return 0;
}