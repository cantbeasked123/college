//Program to implement Bankers Algorithm
#include <iostream>
using namespace std;

int n, m, i, j, p[10], alloc[10][10], Max[10][10], need[10][10], avail[10], work[10], finish[10], sequence[10], check1, check2;

void input()
{
    cout<<"Number of processes:";
    cin>>n;
    cout<<"Number of resources:";
    cin>>m;

    for(i=1;i<=n;i++)
    {
        cout<<"\nProcess number: ";
        cin>>p[i];
        cout<<"Process "<<i<<" allocation:";
        for(j=1;j<=m;j++)
        {cin>>alloc[i][j];}

        cout<<"Process "<<i<<" max:";
        for(j=1;j<=m;j++)
        {
            cin>>Max[i][j];
            need[i][j] = Max[i][j]-alloc[i][j];
        }
    }
    cout<<"Enter Available: ";
    for(j=1;j<=m;j++)
    {cin>>avail[j];}
}

void display()
{
    cout<<"Need: \n";
    cout<<"   A B C\n";

    for(i=1;i<=n;i++)
    {
        cout<<"P"<<i<<" ";
        for(j=1;j<=m;j++)
            cout<<need[i][j]<<" ";
        cout<<endl;
    }
}

int safeSequence()
{
    int count=0, iteration=0;
    for(i=1;i<=n;i++)
    {finish[i] = 0;}

    for(j=1;j<=m;j++)
    {work[j]=avail[j];}

    while(iteration<n)
    {
        for(i=1;i<=n;i++)
        {
            if(!finish[i])
            {
                check1 = 1;
                for(j=1;j<=m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        check1=0;
                        break;
                    }
                }
                if(check1)
                {
                    finish[i]=1;
                    for(j=1;j<=m;j++)
                    {work[j]+=alloc[i][j];}
                    count++;
                    sequence[count] = p[i];
                }
            }
        }
        iteration++;
    }

    for(i=1;i<=n;i++)
    {
        if(finish[i]==0)
        {return 0;}
    }
    return 1;
}

int resReq()
{
    int preq, request[10];
    cout<<"\nEnter process number requesting resource: ";
    cin>>preq;
    cout<<"Enter request: ";
    for(j=1;j<=m;j++)
    {cin>>request[j];}

    int check3=1, check4=1;
    for(j=1;j<=m;j++)
    {
        if(request[j]>need[preq][j])
        {
            check3=0;
            break;
        }
    }
    if(check3)
    {
        for(j=1;j<=m;j++)
        {
            if(request[j]>avail[j])
            {
                check4=0;
                break;
            }
        }
        if(check4)
        {
            for(j=1;j<=m;j++)
            {
                alloc[preq][j]+=request[j];
                need[preq][j]-=request[j];
                avail[j]-=request[j];
            }

            //Display new values
            cout<<"\nP"<<preq<<"] Allocation: ";
            for(j=1;j<=m;j++)
            {cout<<alloc[preq][j]<<" ";}

            cout<<"\nP"<<preq<<"] Need: ";
            for(j=1;j<=m;j++)
            {cout<<need[preq][j]<<" ";}

            cout<<"\nP"<<preq<<"] Available: ";
            for(j=1;j<=m;j++)
            {cout<<avail[j]<<" ";}

        }
        return safeSequence();
        //Exceeds max available
        else
        {            return 3;
}
    }
    //Exceeds max claim
    else
    return 2;
}

int main()
{
    input();
    display();
    if(safeSequence())
    {
        cout<<"Safe sequence: ";
        for(i=1;i<=n;i++)
        {cout<<"P"<<sequence[i]<<" ";}
    }
    else{cout<<"DEADLOCK: No safe sequence.";}

    int c = resReq();
    cout<<"C: "<<c;
    switch(c)
    {
        case 0: cout<<"\nDEADLOCK: No safe sequence."; break;
        case 1: cout<<"\nSafe sequence: ";
                for(i=1;i<=n;i++)
                {cout<<"P"<<sequence[i]<<" ";}
                break;
        case 2: cout<<"\nRequest cannot be granted as it exceeds maximum claim."; break;
        case 3: cout<<"\nRequest cannot be granted as it exceeds maximum available."; break;
        default: cout<<"Invalid input.";
    }
}