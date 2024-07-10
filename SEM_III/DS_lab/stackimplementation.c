//expt5b
#include<stdio.h>
#include<stdlib.h>
struct node                                      //
{
   int data;
   struct node*link;
};
struct node *top=NULL;

 void push()
 {
   int x;
   printf("Enter the element to be inserted:");
   scanf("%d",&x);
   struct node*temp;
   temp=(struct node*)malloc(sizeof(struct node));
   if(temp==NULL)
   {
    printf("Stack Overflow\n");
   }
   else
   {
    temp->data=x;
    temp->link=top;
    top=temp;
    printf("Element %d inserted \n",x);
   }
 }

 void pop()
 {
    struct node*p;                              //
    if(top==NULL)
    {printf("Stack Underflow\n");}
    else
    {
      printf("Element %d deleted\n", top->data);
      p=top;
      top=top->link;
      free(p);
    }
 }

 void display()
 {
   struct node*p;
   if(top==NULL)
   {
     printf("List is Empty\n");
     return;
   }
   p=top;
   printf("Stack:\t");
   while(p!=NULL)
   {
    printf("%d\t",p->data);
    p=p->link;
   }
   printf("\n");
 }

 void peek()
 {
   if(top==NULL)
   {
     printf("Stack Underflow\n");
   }
  else
  {
   printf("The top element is %d\n",top->data);
  }
 }

void underflow()
{
  if(top==NULL)
  {
    printf("Stack Underflow\n");
    return;
  }
  else
  {
   printf("Stack not Underflow\n");
  }
}

void count()
{
    struct node *p;
    int count=0;
    p=top;
    while(p!=NULL)                              //
    {
        p=p->link;
        count++;
    }
    printf("count = %d\n",count);
}

int main()
{
  int choice;
  printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Underflow\n6.Count\n7.Exit");

  while(1){
      printf("\nEnter choice:");
      scanf("%d",&choice);

       switch(choice)
       {
          case 1:push();
                  break;
          case 2:pop();
                  break;
          case 3:display();
                  break;
          case 4:peek();
                  break;
          case 5:underflow();
                  break;
          case 6:count();
                  break;
          case 7:exit(0);
          default:printf("invalid choice\n");
       }
  }

  return 0;
}
