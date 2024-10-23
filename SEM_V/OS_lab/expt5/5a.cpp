//Bankers Safety Search with Resource Request
#include<iostream>
using namespace std;
int n,m,i,j,p[10],alloc[10][10],Max[10][10],need[10][10],avail[10],work[10],finish[10],sequence[10],request[10],check1,check2=0,preq,check3,check4,Count=0,k=1;
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
        cout<<"Enter max for process["<<i<<"]: ";
        for(j=1;j<=m;j++)
        {
            cin>>Max[i][j];
        }
      }
      cout<<endl<<"Enter the available vector: ";
      for(i=1;i<=m;i++)
      {
        cin>>avail[i];
      }
      cout<<endl;
      cout<<"The need matrix is: "<<endl;
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
        {
            need[i][j]=Max[i][j]-alloc[i][j];
            cout<<need[i][j]<<" ";
        }
         cout<<endl;
      }
}

void safety_seq()
{
    for(i=1; i<=m; i++)
    {
        work[i] = avail[i];
    }
    for(i=1; i<=n; i++)
    {
        finish[i] = 0;
    }
    while (Count<n)
    {
        for(i=1; i<=n; i++)
        {
            check1 = 0;
            for(j=1; j<=m; j++)
            {
                if((finish[i]==0) && (need[i][j]<=work[j]))
                {
                    check1++; //for number of resources
                }
                if(check1==m)
                {
                    //process is true,need to update work vector
                    for(j=1; j<=m; j++)
                    {
                        work[j] += alloc[i][j];
                        finish[i] = 1;
                    }
                    sequence[k] = i;
                    k++;
                    Count++;
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            if(finish[i]==1)
            {
                check2++; //for number of processes
            }
            if(check2==n)
            {
                cout<<"\nSafe sequence exists!\n";
                cout<<"\nSafety sequence is:\n{ ";
                for(i=1; i<=n; i++)
                {
                    cout<<"P"<<sequence[i]<<" ";
                }
                cout<<"}";
            }
        }
    }
    if (check2 != n)
    {
        cout << "\nThere is a deadlock. Safety sequence does not exist!";
    }
  }
int resource_request()
 {
    cout<<endl<<"\nEnter the process from which request is coming: ";
    cin>>preq;
    cout<<endl<<"Enter the request: ";
    for(j=1;j<=m;j++)
     {
        cin>>request[j];
     }
     for(j=1;j<=m;j++)
      {
        if(request[j]<=need[preq][j])
         {
            check3++;
         }
      }
      if(check3==m)
       {
         for(j=1;j<=m;j++)
          {
            if(request[j]<=avail[j])
             {
                check4++;
             }
          }
          if(check4==m)
           {
            cout<<endl<<"Request can be granted.Resources are available!";
            for(j=1;j<=m;j++)
             {
                alloc[preq][j]+=request[j];
                need[preq][j]-=request[j];
                avail[j]-=request[j];
             }
             cout<<endl<<"\nAllocation: ";
             for(j=1;j<=m;j++)
              {
                cout<<alloc[preq][j]<<" ";
              }
              cout<<"\nNeed: ";
              for(j=1;j<=m;j++)
               {
                cout<<need[preq][j]<<" ";
               }
               cout<<"\nAvailable: ";
              for(j=1;j<=m;j++)
               {
                cout<<avail[j]<<" ";
               }
           }
          else
           {
            cout<<endl<<"Request cannot be granted. Resources are not available!";
           }
       }
      else
       {
        cout<<endl<<"Request cannot be granted as it is exceeding its maximum claim.";
       }
       return 0;
 }
 int main()
  {
    input();
    safety_seq();
    resource_request();
    return 0;
  }
