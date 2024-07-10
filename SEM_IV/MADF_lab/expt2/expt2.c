//Joshua Fernandes 22CO16 5/2/24
//Program to perform merge sort on a given array

#include<stdio.h>
#define MAX 50

//display contents of the array
void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
}

//to merge the sorted arrays
void merge(int a[], int low, int mid, int high)
{
    int temp[high-low+1];
    int i=low,j=mid+1,k=0;

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=temp[i-low];
}

int mergeSort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int a[MAX],i,n;

    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    display(a,n);
    return 0;
}
