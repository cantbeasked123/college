#include<stdio.h>
#define max 4
int queue[100],front=-1,rear=-1;

int enqueue();
int dequeue();
int is_full();
int is_empty();
int peek();
int display();

int main()
 {
    int item,choice;


    printf("\n1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.queue overflow\n");
    printf("4.queue underflow\n");
    printf("5.peek\n");
    printf("6.display\n");
    printf("7.quit\n");

    do
    {
        printf("\nenter your choice:");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1: enqueue(item);
                    break;
            case 2: dequeue(item);
                    break;
            case 3: is_full(item);
                    break;
            case 4: is_empty(item);
                    break;
            case 5: peek(item);
                    break;
            case 6: display();
                    break;
            case 7: exit(0);
                    break;
            default:printf("invalid input\n");
        }
     }while(choice!=7);
    return 0;
 }

int enqueue(int item)
{
    if(rear==max-1)
        printf("queue overflow\n");
    else if (front==-1)                             //
        {
            front=0;
            printf("queue was previously empty");  
        }
    else
    {
        printf("enter the number to be inserted:");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
    }
}

int dequeue(int item)
{
    if(front==-1||front>rear)
        printf("queue underflow\n");
    else
        printf("the deleted element is:%d\n",queue[front]);
        front++;
}

int is_full(int item)
{
    if(rear==max-1)
        printf("queue overflow\n");
    else
        printf("queue not overflow\n");
}

int is_empty(int item)
{
    if(front==-1||front>rear)
        printf("queue underflow\n");
    else
        printf("queue not underflow\n");
}

int peek(int item)
{
    if(front==-1||front>rear)
        printf("queue underflow\n");
    else
        printf("the front element=%d\n",queue[front]);
}

int display()
{
    int i;
    if (front==-1||front>rear)
        printf("queue underflow\n");
    else
    {
        printf("queue:");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }printf("\n");

}
