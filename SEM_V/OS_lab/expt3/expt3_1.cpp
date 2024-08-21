//expt3: non preemptive scheduling algorithm
//joshua fernandes
//FCFS

#include <iostream>
using namespace std;

int main()
{
    int i,P[10], bt[10], ct[10], wt[10],tt[10],n,At[10];
    float tawt=0,tatt=0,awt,att;
    cout<<"Enter the number of processes:";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter the process number:";
        cin>>P[i];
        cout<<"Enter the burst time:";
        cin>>bt[i];
    }
    cout<<endl;
    ct[1]=bt[1];

    for(i=2;i<=n;i++)
    {ct[i]=ct[i-1]+bt[i];}

    for(i=1;i<=n;i++)
    {
        wt[i]=ct[i]-bt[i];
        tt[i]=wt[i]+bt[i];
    }

    for(i=1;i<=n;i++)
    {
        tawt+=wt[i];
        tatt+=tt[i];
    }

    cout<<"\nProcess number\tBT\tCt\tWT\tTT\t\n";
    for(i=1;i<=n;i++)
    {cout<<P[i]<<"\t\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}

    awt=tawt/n;
    att=tatt/n;
    cout<<"\nAverage waiting time"<<awt<<endl;
    cout<<"Average turnaround time"<<att<<endl;
    return 0;
}

