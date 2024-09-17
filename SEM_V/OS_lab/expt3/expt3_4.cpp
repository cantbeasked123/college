//PRIORITY without AT

#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    int p[10],bt[10],ct[10],wt[10],tt[10],pr[10];
    float awt=0,att=0,ttt=0,twt=0;
    cout<<"Enter the Number of Processes:";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter the Process Number:";
        cin>>p[i];
        cout<<"Enter the Burst Time:";
        cin>>bt[i];
        cout<<"Enter the Priority:";
        cin>>pr[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(pr[i]>pr[j])
            {
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
                swap(pr[i],pr[j]);
            }
        }
    }
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
        twt=twt+wt[i];
        ttt=ttt+tt[i];
    }

    awt=twt/n;
    att=ttt/n;
    cout<<"Process Number\tBt\tPriority\tCt\tWt\tTt\n";
    for(i=1;i<=n;i++)
    {cout<<p[i]<<"\t\t"<<bt[i]<<"\t"<<pr[i]<<"\t\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}

    cout<<"\nAverage Waiting Time:"<<awt;
    cout<<"\nAverage Turnaround Time:"<<att;
    return 0;
}
