//SRTF
#include<iostream>
using namespace std;
int main()
 {
    int n,P[10],bt[10],rem_bt[10],At[10],wt[10],tt[10],i,t=0,small,ct,count=0;
    float awt=0,att=0,tawt=0,tatt=0;
    cout<<"Enter the no. of processes: ";
    cin>>n;
    cout<<"Enter the arrival time and burst time for process:"<<endl;
    for(i=1;i<=n;i++)
     {
        P[i]=i;
        cout<<"P["<<i<<"]: ";
        cin>>At[i]>>bt[i];
        rem_bt[i]=bt[i];
     }

     rem_bt[9]=999;  //inf
     for(t=0;count!=n;t++)
      {
        small=9;  //corresponds to the index where rem_bt is inf(999)
        for(i=1;i<=n;i++)
         {
            if(At[i]<=t && rem_bt[i]>0 && rem_bt[i]<rem_bt[small])
             {
                small=i;
             }
         }
        rem_bt[small]--;
        if(rem_bt[small]==0)
         {
            ct=t+1;
            wt[small]=ct-bt[small]-At[small];
            tt[small]=wt[small]+bt[small];
            count++;
         }
      }
      for(i=1;i<=n;i++)
       {
         tawt=tawt+wt[i];
         tatt=tatt+tt[i];
       }
       awt=(float)tawt/n;
       att=(float)tatt/n;
       cout<<"\nProcess\t    BT\t  WT\t  TT\n";
       for(i=1;i<=n;i++)
        {
          cout<<"P"<<P[i]<<"\t    "<<bt[i]<<"\t  "<<wt[i]<<"\t  "<<tt[i]<<"\n";
        }
      cout<<"\nAverage Waiting time = "<<awt;
      cout<<"\nAverage Turnaround time = "<<att;
      return 0;
 }
