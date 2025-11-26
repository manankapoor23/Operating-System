#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    int i,j,n,qt,count=0,temp,sq=0,bt[30],wt[30],tat[30],rem_bt[30];
    float awt=0;
    float atat=0;

    printf("enter the number of process: ");
    scanf("%d",&n);

    printf("enter burst time of processes: ");
    for(int i =0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }

    printf("enter quantum time: ");
    scanf("%d",&qt);

    while(1){
        count=0;
        for(int i =0;i<n;i++){
            temp=qt;
            if(rem_bt[i]==0){
                count++;
                continue;
            }
            if(rem_bt[i]>qt){
                rem_bt[i]=rem_bt[i]-qt;
                sq+=qt;
            }
            else{
                temp=rem_bt[i];
                rem_bt[i]=0;
                sq=sq+temp;
                tat[i]=sq;
            }
        }
        if(n==count){
            break;
        }
    }
    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+wt[i];
        printf("\n%d\t%d\t\t%d\t\t%d",i+1,bt[i],tat[i],wt[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("\navg wt = %f\n",awt);
    printf("avt tat = %f",atat);

}