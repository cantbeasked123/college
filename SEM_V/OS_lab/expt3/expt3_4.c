//PRIORITY without AT
#include<stdio.h>
int main(){
int n,i,j;
int p[10],bt[10],ct[10],wt[10],tt[10],pr[10],temp,temp1,temp2;
float awt=0,att=0,ttt=0,twt=0;
printf("Enter the No of Processes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the Process No : ");
scanf("%d",&p[i]);
printf("Enter the Burst Time for that Process : ");
scanf("%d",&bt[i]);
printf("Enter the Priority for that Process : ");
scanf("%d",&pr[i]);
}
for(i=1;i<=n;i++)
{
for(j=i+1;j<=n;j++)
{
if(pr[i]>pr[j])
{
temp=bt[i];

bt[i]=bt[j];
bt[j]=temp;
temp1=p[i];
p[i]=p[j];
p[j]=temp1;
temp2=pr[i];
pr[i]=pr[j];
pr[j]=temp2;
}
}
}
ct[1]=bt[1];
for(i=2;i<=n;i++)
{
ct[i]=ct[i-1]+bt[i];
}
for(i=1;i<=n;i++)
{
wt[i]=ct[i]-bt[i];
tt[i]=wt[i]+bt[i];
}
for(i=1;i<=n;i++)
{
twt=twt+wt[i];
ttt=ttt+tt[i];
}
awt=twt/n;
att=ttt/n;
printf("Process\t Burst Time \tPriority\tCompletion Time\t Waiting Time\tTurnaround
Time\n");
for(i=1;i<=n;i++)
{
printf(" P%d \t %d \t\t%d \t\t%d \t\t %d \t\t%d\n",p[i],pr[i],bt[i],ct[i],wt[i],tt[i]);
}
printf("The Average Waiting Time is: %f\n",awt);
printf("The Average Turnaround Time is: %f",att);
return 0;
}