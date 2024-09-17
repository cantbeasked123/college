//SJF with arrival
#include<iostream>
using namespace std;
int main()
{
    int n,p[10],bt[10],ct[10],wt[10],tt[10],i,j,At[10],min=0,k=2,sum=0;
    float tawt=0,tatt=0,awt=0,att=0;
    cout<<"Enter the number of processes:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\nEnter the Process Number:";
        cin>>p[i];
        cout<<"Enter the Burst Time:";
        cin>>bt[i];
        cout<<"Enter the Arrival time:";
        cin>>At[i];
    }

    for(i=1; i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(At[i] > At[j])
            {
                swap(At[i],At[j]);
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
    }
    ct[1]=bt[1];
    for(i=2; i<=n; i++)
    {
        sum=sum+bt[i-1];
        min=bt[k];
        for(j=k;j<=n;j++)
        {
            if(sum>=At[j] && bt[j]<min) // Check if the process has arrived and has a shorter burst time
            {
                swap(At[i],At[j]);
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
        k++;
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=1;i<=n;i++)
    {
        wt[i]=ct[i]-bt[i]-At[i];
        tt[i]=wt[i]+bt[i];
    }
    for(i=1; i<=n; i++)
    {
        tawt=tawt+wt[i];
        tatt=tatt+tt[i];
    }
    awt=tawt/n;
    att=tatt/n;

    cout<<"\nProcess number\tBT\tAt\tCt\tWT\tTT\t\n";
    for(i=1; i<=n; i++)
    {cout<<p[i]<<"\t\t"<<bt[i]<<"\t"<<At[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}
    cout<<"\nAverage Waiting time:"<<awt;
    cout<<"\nAverage Turnaround time:"<<att;
    return 0;
}
