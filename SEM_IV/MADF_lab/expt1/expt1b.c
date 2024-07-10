#include<stdio.h>
int RBinarySearch(int a[],int key, int low, int high);
int main()
{
   int a[10],i,j,t,n,key,index;
   printf("Enter the size of the array:\n");
   scanf("%d",&n);
   printf("\nEnter the elements of the array:\n");
   for(i=0;i<n;i++)
        scanf("%d",&a[i]);

   printf("\nDisplay the array before bubble sort:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);

   for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                }
            }

   printf("\nDisplay the array after bubble sort:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);
   printf("\nEnter the elements to be searched:\n");
   scanf("%d",&key);
   int low=0,high=n-1;
   index=RBinarySearch(a,key,low,high);
   if(index!=-1)
        printf("\nItem %d found at position %d",key,index+1);
   else
        printf("\nItem not found\n");
}

int RBinarySearch(int a[],int key, int low, int high)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(key==a[mid])
    {
        return (mid);
    }
    else if(key<a[mid])
    {
        RBinarySearch(a,key,low,mid-1);
    }
    else if(key>a[mid])
    {
        RBinarySearch(a,key,mid+1,high);
    }
    else
        return -1;
}

