//expt5a
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;

void insert()
{
    int x;
    printf("Enter the element to be inserted:");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("No space for Dynamic Memory Allocation\n");
    }
    else
    {
        tmp->data=x;
        tmp->link=NULL;
        if(front==NULL)
        {
            front=tmp;
        }
        else
        {
            rear->link=tmp;
        }
        rear=tmp;
        printf("Element inserted successfully\n");
    }
}

void delete()
{
    struct node *p;
    if(front==NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted successfully\n",front->data);
        p=front;
        front=front->link;
        free(p);
    }
}

void display()
{
    struct node *tmp;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }    
    tmp=front;
    {   
        if(front!=NULL)
            printf("Queue:\t");
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->data);
            tmp=tmp->link;
        }
    }
    printf("\n");
}

void peek()
{
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Front element is %d\n",front->data);
    }
}

void underflow()
{
    if(front==NULL)
    printf("Queue underflow\n");
    else
    printf("No Queue Underflow\n");
}

int main()
{
    int c, i;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Check Queue Underflow Condition\n6.Exit\n");
    while(1)
    {   
        printf("\nEnter choice:");
        scanf("%d", &c);
        switch(c)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:peek();
                   break;
            case 5:underflow();
                   break;
            case 6:exit(0);
                   break;
            default:printf("Invalid choice\n");
                    break;
            }
    }
    return 0;
}

