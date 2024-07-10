//expt3a
#include<stdio.h>
#define MAX 100
void merge_sort (int a[],int low,int high);
void merge(int a[],int temp[],int low1,int high1,int low2,int high2);
void copy(int a[],int temp[],int low,int high);

int main()
{
int i,n,a[MAX],low,high;
printf("enter the number of elements:");
  scanf("%d",&n);
printf("enter elements:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
low=0;
high=n-1;
merge_sort(a,low,high); //
display(a,low,high);
return 0;
}

void merge_sort(int a[],int low,int high)
{
int mid;
int temp[MAX];      //
if(low<high)
  {
    mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,temp,low,mid,mid+1,high);
    copy(a,temp,low,high);
  }
}

void merge(int a[],int temp[],int low1,int high1,int low2,int high2)
{
int i=low1;
int j=low2;
int k=low1;
while((i<=high1) && (j<=high2))
{
      if(a[i]<=a[j])            ///
          temp[k++]=a[i++];
      else
          temp[k++]=a[j++];
}
  while(i<=high1)
      temp[k++]=a[i++];
 while(j<=high2)
      temp[k++]=a[j++];
}

void copy(int a[],int temp[],int low,int high)
{
   int i;
   for(i=low;i<=high;i++)
   a[i]=temp[i];
}

void display(int a[],int low,int high)
{
    int i;
    printf("\nsorted list is :\n");
    for(i=0;i<=high;i++)
    {
            printf("%d ",a[i]);
    }
}
