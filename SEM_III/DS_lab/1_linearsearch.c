//expt1a

#include<stdio.h>
int linearsearch();
int main()
{
int i,n,a[100],s,ls;
printf("enter the size of the array:");
scanf("%d",&n);
printf("enter the elements in the array:");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("enter the elements to be searched:\n");
scanf("%d",&s);
ls=linearsearch(s,a,n);
if(ls==1)
    printf("element %d not found",s);
else
    printf("element %d found at %d",s,ls);
return 0;
}

int linearsearch(int search,int arr[],int size)
{
int i=0;
while(i<size && arr[i]!=search)
    i++;
if(i<size)
    return i;
else
    return 1;
}
