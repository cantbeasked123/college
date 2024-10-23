//PRODUCER CONSUMER PROBLEM WITH n SIZE OF THE BUFFER
#include<iostream>
#include<cstdlib>
using namespace std;
int buffersize,buffer[50],s=1,empty,full=0,i,in=0,out=0,mutex=1,next_produced,next_consumed,counter=0;
int wait(int s)
{
    while(s<0)
     {
        cout<<"The buffer is not accessible";
        return 0;
     }
     return s--;
}
int signal(int s)
{
    s++;
}
int producer()
{
    empty=wait(empty);
    mutex=wait(mutex);
    if(counter == buffersize)
     {
        cout<<"\nThe buffer is full.Cannot produce further!";
     }
    else
     {
        cout<<"\nEnter the item to be produced: ";
        cin>>next_produced;
        cout<<endl<<next_produced<<" is produced in the buffer successfully"<<endl;
        buffer[in]=next_produced;
        in=(in+1)%buffersize;
        counter++;
        mutex=signal(mutex);
        full=signal(full);
     }
}
int consumer()
{
    full=wait(full);
    mutex=wait(mutex);
    if(counter == 0)
     {
        cout<<"\nThe buffer is empty.Cannot consume further!";
     }
    else
     {
         next_consumed=buffer[out];
         cout<<endl<<next_consumed<<" is the item that is consumed";
         out=(out+1)%buffersize;
         counter--;
         mutex=signal(mutex);
         empty=signal(empty);
     }
}


int main()
{
    cout<<"Enter the buffer size: ";
    cin>>buffersize;
    buffer[buffersize];
    empty=buffersize;
    int choice;
    do
        {
                cout<<"\n1.Produce an item\n2.Consume an item\n3.Exit";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch (choice)
                 {
                    case 1: producer();
                            break;
                    case 2: consumer();
                            break;
                    case 3: cout<<"\nExiting";
                            exit(0);
                    default: cout<<"\nInvalid input!";
                             break;
                 }
        } while (choice!=3);
    return 0;
}