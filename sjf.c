#include<stdio.h>
#include <stdint.h>
#include<string.h>

int main(){
    int i,j,n,t,p[30],bt[30],wt[30],tat[30];
    float awt=0;
    float atat=0;
    printf("enter the number of processes ");
    scanf("%d",&n);
    printf("enter the process number ");
    for(i =0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("enter the burst time of the process");
    for(i =0;i<n;i++){
        scanf("%d",&bt[i]);
    }

    // sort the process based on their burst time 
    for(i =0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;

            }
        }
    }
    printf("process\tburst time \twaiting time \tturn around time\n ");
    for(i =0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[j];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("avg wt = %f\n",awt);
    printf("avg tat = %f\n",atat);

}