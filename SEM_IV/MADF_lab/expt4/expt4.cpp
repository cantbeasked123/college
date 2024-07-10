#include<iostream>
#include<string.h>
using namespace std;
int search(string t,string p,int arr[])
{
    int j,k=0;
    int n=t.length();
    int m=p.length();
    for(int i=0;i<n-m+1;i++)
    {
        j=0;
        while(j<m && p[j]==t[i+j])
            j++;
        if(j==m)
            arr[k++]=i;
    }
    if(k)
        return k;
    return -1;
}

int main()
{
    string test,pattern;
    int index[20],x;
    cout<<"Enter your string:";
    getline(cin,test);
    cout<<"Enter pattern to be tested:";
    getline(cin,pattern);
    x=search(test,pattern,index);
    if(x==-1)
    {
        cout<<"Pattern not present";
    }
    else
    {
        int i;
        cout<<"Pattern found at index:";
        for(i=0;i<x;i++)
            cout<<index[i]+1<<endl;
    }
    return 0;
}
