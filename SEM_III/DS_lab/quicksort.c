//expt3b
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void quick(int arr[],int low,int high);
int partition(int arr[],int low,int high);
int iter=1,n;

int main()
{
    int a[MAX],i,low,high;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    low=0;
    high=n-1;
    QuickSort(a,low,high);
    printf("The sorted array is: ");
    for(i=low;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

int partition(int a[],int low,int high)
{
    int pivot,i,j,t; 
    i=low+1;
    j=high;
    pivot=a[low];
    while(i<=j)
    {
        while(a[i]<pivot&&(i<high))
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
        else
            i++;
    }
    a[low]=a[j];
    a[j]=pivot;
    printf("Iteration:%d=> ",iter++);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }printf("\n");
    return j;               ///
}

void QuickSort(int arr[], int low, int high)
{
    int pivot;
    if(low>=high)
        return;
    pivot=partition(arr, low, high);
    QuickSort(arr, low, pivot-1);
    QuickSort(arr, pivot+1, high);
}
