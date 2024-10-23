//Deadlock Detection
#include <iostream>
using namespace std;
int n, m, i, j, p[10], alloc[10][10], req[10][10], avail[10], work[10], finish[10], sequence[10], check1, check2;
void input()
 {
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter the number of resources: ";
    cin>>m;

     for(i=1;i<=n;i++)
      {
        cout<<"Enter allocation for process["<<i<<"]: ";
        for(j=1;j<=m;j++)
         {
            cin>>alloc[i][j];
         }
      }
      cout<<endl;
      for(i=1;i<=n;i++)
       {
          cout<<"Enter request for process["<<i<<"]: ";
          for(j=1;j<=m;j++)
           {
             cin>>req[i][j];
           }
       }
      cout<<endl<<"Enter the available vector: ";
      for(i=1;i<=m;i++)
       {
        cin>>avail[i];
       }

}

void display()
{
    cout<<"\n\nProcess\tAllocation Request\n";
    for(i=1;i<=n;i++)
    {
        cout<<"P"<<i<<"\t";
        for(j=1;j<=m;j++)
        {
            cout<<alloc[i][j]<<" ";
        }
        cout<<"\t   ";
        for(j=1;j<=m;j++)
        {
            cout<<req[i][j]<<" ";
        }
        cout<<endl;
    }
}

int safeSequence()
{
    int count=0, iteration=0;
    for(i=1;i<=n;i++)
    {
        finish[i] = 0;
    }
    for(j=1;j<=m;j++)
    {
        work[j]=avail[j];
    }
    while(iteration<n)
    {
        for(i=1;i<=n;i++)
        {
            if(!finish[i])
            {
                check1 = 1;
                for(j=1;j<=m;j++)
                {
                    if(req[i][j]>work[j])
                    {
                        check1=0;
                        break;
                    }
                }
                if(check1)
                {
                    finish[i]=1;
                    for(j=1;j<=m;j++)
                    {
                        work[j]+=alloc[i][j];
                    }
                    count++;
                    sequence[count] = i;
                }
            }
        }
        iteration++;
    }
    for(i=1;i<=n;i++)
    {
        if(finish[i]==0)
        {
            return 0;
        }
    }
    return 1;
}

int resReq()
{
    int preq;
    cout<<"\nEnter process number requesting resource: ";
    cin>>preq;
    cout<<"Enter new request request vector: ";
    for(j=1;j<=m;j++)
    {
        cin>>req[preq][j];
    }
    return safeSequence();
}

int main()
{
    input();
    display();
    if(safeSequence())
    {
        cout<<"\nSafe sequence exists.";
        cout<<"\nSafe sequence: ";
        for(i=1;i<=n;i++)
        {
            cout<<"P"<<sequence[i]<<" ";
        }
    }
    else
    {
        cout<<"\nDEADLOCK: No safe sequence.";
    }
    int c = resReq();
    switch(c)
    {
        case 0: cout<<"\nSystem is in deadlock.";
                break;
        case 1: cout<<"\nSafe sequence: ";
        for(i=1;i<=n;i++)
        {
            cout<<"P"<<sequence[i]<<" ";
        }
        break;
        default: cout<<"\nInvalid input.";
    }
}

