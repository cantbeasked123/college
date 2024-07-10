#include<stdio.h>
int binary_search();
int main()
{
int a[100],i,n,item,index;
printf("enter the size of the array:\n");
scanf("%d",&n);
printf("enter the elements of the array:\n");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("enter the number to be searched:");
scanf("%d",&item);
index=binary_search(a,n,item);
if(index==-1)
    printf("element %d not found",item);
else
    printf("element %d found at location %d",item,index);
return 0;
}

int binary_search(int arr[],int size,int s)
{
int low=0,up=size-1,mid;
while(low<=up)
{
mid=(low+up)/2;
if(s>arr[mid])
    low=mid+1;
else if(s<arr[mid])
    up=mid-1;
else
    return mid; //
}
return -1;
}
