//expt2a

#include<stdio.h>
#define max 4
int stack[50];top=-1;

int push();
int pop();
int stack_overflow();
int stack_underflow();
int peek();
int display();

int main()
{
    int item,choice=0;
    printf("\n1.push\n");
    printf("2.pop\n");
    printf("3.stack overflow\n");
    printf("4.stack underflow\n");
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
            case 1: push(item);
                    break;
            case 2: pop(item);
                    break;
            case 3: stack_overflow();
                    break;
            case 4: stack_underflow();
                    break;
            case 5: peek();
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

int push(int item)
{
    printf("enter the number to be inserted:");
    scanf("%d",&item);
    printf("\n");
    if(top==max-1)
        {
            printf("stack overflow\n");
        }
    else
        top=top+1;
        stack[top]=item;
}

int pop(int item)
{
    if(top==-1)
        {
            printf("stack underflow\n");
        }
    else
        stack[top]=item;
        top=top-1;
        printf("element deleted\n");
        return item;
}

int stack_overflow()
{
    if(top==max-1)
        printf("stack overflow\n");
    else
        printf("stack not overflow\n");
        return;
}

int stack_underflow()
{
    if(top==-1)
        printf("stack underflow\n");
    else
        printf("stack not underflow\n");
        return;
}

int peek()
{
    if(top==-1)
        printf("stack underflow\n");
    else
        printf("topmost element=%d",stack[top]);
}

int display()
{
    int i;
    if(top==-1)
        printf("stack underflow\n");
    else
    {
        printf("stack:");
        for(i=0;i<=top;i++)
        {
            printf("%d",stack[i]);
        }printf("\n");
    }
}













