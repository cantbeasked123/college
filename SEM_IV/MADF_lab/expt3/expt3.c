//Joshua Fernandes 22CO16 5/2/24
//Program to perform quick sort on a given array

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

int partition(int a[],int low,int high)
{
    int pivot,i,j,t;
    pivot=a[low];
    i=low;
    j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<j)
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
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}

//to perform quick sort
void QuickSort(int a[],int low, int high)
{
    int p;
    if(low<high)
    {
        p=partition(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
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
    QuickSort(a,0,n-1);
    display(a,n);
    return 0;
}

