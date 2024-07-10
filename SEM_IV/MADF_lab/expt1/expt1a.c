#include<stdio.h>
int BinarySearch(int a[],int n,int s);
int main()
{
   int a[10],i,j,t,n,s,key;
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
   scanf("%d",&s);
   key=BinarySearch(a,n,s);
   if(key!=-1)
        printf("\nItem %d found at position %d",s,key+1);
   else
        printf("\nItem not found\n");
}

int BinarySearch(int a[], int n, int s)
{
    int low=0, high=n-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(s>a[mid])
            low = mid+1;
        else if(s<a[mid])
            high = mid-1;
        else
            return mid;
    }
return -1;
}