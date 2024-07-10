//expt8
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK' '
#define TAB '\t'
#define MAX 50
void push(int symbol);
int pop();
int eval_post();
int isEmpty();
char infix[MAX], postfix[MAX];
int stack[MAX];
int top=-1;

 main()
 {
    int value;
    printf("Enter postfix: ");
    gets(postfix);
    printf("Postfix: %s\n", postfix);
    value = eval_post();
    printf("Value of expression: %d\n", value);
 }

 void push(int symbol)
 {
    if (top>MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = symbol;
 }

 int pop()
 {
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
 }

 int isEmpty()
 {
    if(top==-1)
        return 1;
    else
        return 0;
 }

 int eval_post()
 {
    int a, b, temp, result, i;
    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');                           ///
        else
        {
            a = pop();
            b = pop();
            switch(postfix[i])
            {
                case '+':
                    temp = b+a; break;
                case '-':
                    temp = b-a; break;
                case '*':
                    temp = b*a; break;
                case '/':
                    temp = b/a; break;
                case '%':
                    temp = b%a; break;
                case '^':
                    temp = pow(b,a);
            }
            push(temp);         ///
        }
    }
 result = pop();            //
 return result;
 }

