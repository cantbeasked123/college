//round robin algorithm

#include<iostream>
using namespace std;
int main()
{
    int n,i,j,ts,t=0;//timeslice and time
    int p[10],bt[10],rem_bt[10],ct[10],wt[10],tt[10];
    float awt=0,att=0,ttt=0,twt=0;
    bool flag;
    cout<<"Enter the number of processes:";
    cin>>n;
    cout<<"Enter the timeslice:";
    cin>>ts;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the process number:";
        cin>>p[i];
        cout<<"Enter the burst time for the processes:";
        cin>>bt[i];
        rem_bt[i]=bt[i];
        cout<<endl;
    }

    while(true)
    {
        flag=true;
        for(i=0;i<=n;i++)
        {
            if(rem_bt[i]>0)
            {
                flag=false;
                if(rem_bt[i]>ts)
                {
                    t+=ts;
                    rem_bt[i]-=ts;
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
        break;
    }
    for(i=1;i<=n;i++)
    {
    tt[i]=wt[i]+bt[i];
    twt=twt+wt[i];
    ttt=ttt+tt[i];
    }

    cout<<"Process number\tBT\tWT\tTT\t\n";
    for(i=1;i<=n;i++)
    {cout<<p[i]<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";}

    awt=twt/n;
    att=ttt/n;
    cout<<"\nThe Average Waiting Time is:"<<awt<<endl;
    cout<<"The Average Turnaround Time is:"<<att<<endl;
    return 0;
}
