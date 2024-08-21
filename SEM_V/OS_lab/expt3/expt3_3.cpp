//SJF

#include<iostream>
int main()
{
    int n,i,j;
    int p[10],bt[10],ct[10],wt[10],tt[10];
    float awt=0,att=0,ttt=0,twt=0;
    cout<<"Enter the number of processes";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the process number:";
        cin>>p[i];
        cout<<"Enter the burst time for The processes:";
        cin>>bt[i];
        }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
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

    cout<<"\nProcess number\tBT\tCt\tWT\tTT\t\n";
    for(i=1;i<=n;i++)
    {cout<<p[i]<<"\t\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}

    awt=twt/n;
    att=ttt/n;
    cout<<"\nThe Average Waiting Time is:"<<awt<<endl;
    cout<<"The Average Turnaround Time is:"<<att<<endl;
    return 0;
}
