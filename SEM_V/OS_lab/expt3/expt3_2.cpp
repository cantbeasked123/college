//FCFS scheduling with Arrival Time

#include<iostream>
using namespace std;
int main()
{
    int n,i,j,at[10],p[10],bt[10],ct[10],wt[10],tt[10];
    float awt=0,att=0,tawt=0,tatt=0;
    cout<<"Enter the number of processes:";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the process number:";
        cin>>p[i];
        cout<<"Enter the burst time:";
        cin>>bt[i];
        cout<<"Enter the arrival time:";
        cin>>at[i];
        cout<<endl;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(at[i]<at[j])
            {
                swap(at[i],at[j]);
                swap(p[i],p[j]);
                swap(bt[i],bt[j]);
            }
        }
    }
    ct[1]=bt[1];
    for(i=2;i<=n;i++)
    {ct[i] = ct[i-1]+bt[i];}
    for(i=1;i<=n;i++)
    {
        wt[i] = ct[i]-bt[i]-at[i];
        tt[i] = wt[i]+bt[i];
    }
    for(i=1;i<=n;i++)
    {
        tawt=tawt+wt[i];
        tatt=tatt+tt[i];
    }

    cout<<"\nProcess number\tBT\tAt\tCt\tWT\tTT\t\n";
    for(i=1;i<=n;i++)
    {cout<<p[i]<<"\t\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}

    awt=tawt/n;
    att=tatt/n;
    cout<<"\nAverage waiting time:"<<awt<<endl;
    cout<<"Average turnaround time:"<<att<<endl;
    return 0;
}
