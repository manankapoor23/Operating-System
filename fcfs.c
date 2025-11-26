#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    int i,j,n,bt[30],at[30],wt[30],tat[30],temp[30];
    float awt=0;
    float atat=0;
    printf("enter the number of processes: ");
    scanf("%d",&n);
    printf("enter the burst time of the processes");
    for(int i =0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("enter the arrival time of the proccess");
    for(int i =0;i<n;i++){
        scanf("%d",&at[i]);
    }
    temp[0]=0;
    printf("process\t burst time\t arrival time\t waiting time\t tat\t\n");
    for(int i =0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("average wait time is %f \n",awt);
    printf("average turnaround time is %f \n",atat);
}