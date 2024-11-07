//fifo
#include<iostream>
using namespace std;

int main(){
    int pages[20], frame[3], i, j=0, k, available, n, fs, count=0;

    cout<<"\nEnter the number of referenced strings: ";
    cin>>n;

    cout<<"\nEnter the referenced pages: ";
    for(i=1;i<=n;i++)
    cin>>pages[i];

    cout<<"\nEnter the frame size: ";
    cin>>fs;

    for(i=0;i<fs;i++)
        frame[i]=-1;
    cout<<"\n\nPages:\tFrame:\n";
    for(i=1;i<=n;i++){
        available=0;
        cout<<pages[i]<<"\t";
        for(k=0;k<fs;k++){
            if(frame[k]==pages[i])
            available=1;
        }
        if(available == 0){
            frame[j]=pages[i];
            j=(j+1)%fs;
            count++;
        }
        for(k=0;k<fs;k++)
            cout<<frame[k]<<" ";
        cout<<"\n";
    }
    cout<<"Total number of page faults are: "<<count;
}