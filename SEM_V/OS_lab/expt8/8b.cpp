//lru
#include<iostream>
using namespace std;
int main(){
    int pages[25],frame[3],i,j=0,k,available,n,fs,count=0,lastused[25],min,index;

    cout<<"Enter the number of referenced strings: ";
    cin>>n;
    cout<<"\nEnter the referenced pages: ";
    for(i=1;i<=n;i++)
    cin>>pages[i];
    cout<<"\nEnter the frame size: ";
    cin>>fs;

    for(i=0;i<fs;i++){
    frame[i]=-1;
    lastused[i]=0;
    }

    cout<<"\nPages:\tFrame:\n";
    for(i=1;i<=n;i++){
        available=0;
        cout<<pages[i]<<"\t";
        for(k=0;k<fs;k++){
        if(frame[k]==pages[i]){
            available=1;
            lastused[k]=i+1;
        }
        }
        if(available == 0){
            min=lastused[0];
            index=0;
            for(k=1;k<=fs;k++){
                if(lastused[k]<min){
                min=lastused[k];
                index=k;
                }
            }
            frame[index]=pages[i];
            lastused[index]=i+1;
            count++;
        }
        for(k=0;k<fs;k++)
            cout<<frame[k]<<" ";
        cout<<"\n";
    }
    cout<<"\nTotal number of page faults are: "<<count;
    return 0;
}
