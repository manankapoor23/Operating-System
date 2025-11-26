#include <stdio.h>
#include <stdlib.h>
#define size 10

int main(){
    int max_need[size][size];
    int alloc[size][size];
    int rem_need[size][size];
    int available[size];
    int completed[size];
    int safe[size];
    int p, r, i, j, count = 0, process;

    printf("enter the number of processes : ");
    scanf("%d", &p);

    printf("enter the number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < p; i++){
        completed[i] = 0;
    }

    printf("enter the max_need matrix for each process:\n");
    for (i = 0; i < p; i++){
        printf("For process %d : ", i+1);
        for (j = 0; j < r; j++){
            scanf("%d", &max_need[i][j]);
        }
    }

    printf("enter allocation matrix for each process:\n");
    for (i = 0; i < p; i++){
        printf("For process %d : ", i+1);
        for (j = 0; j < r; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("enter available resources: ");
    for (j = 0; j < r; j++){
        scanf("%d", &available[j]);
    }

    // remaining need
    for (i = 0; i < p; i++){
        for (j = 0; j < r; j++){
            rem_need[i][j] = max_need[i][j] - alloc[i][j];
        }
    }

    // BANKER ALGO
    do {
        printf("\nmax_need\t allocation\t remaining need\n");
        for (i = 0; i < p; i++){
            for (j = 0; j < r; j++)
                printf("%d ", max_need[i][j]);

            printf("\t");

            for (j = 0; j < r; j++)
                printf("%d ", alloc[i][j]);

            printf("\t");

            for (j = 0; j < r; j++)
                printf("%d ", rem_need[i][j]);

            printf("\n");
        }

        process = -1;

        // Find a process to run
        for (i = 0; i < p; i++){
            if (completed[i] == 0){
                int flag = 0;
                for (j = 0; j < r; j++){
                    if (rem_need[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    process = i;
                    break;
                }
            }
        }

        // ❗ IMPORTANT FIX: if no process found → break loop
        if (process == -1)
            break;

        safe[count] = process;
        count++;

        // release resources
        for (j = 0; j < r; j++){
            available[j] += alloc[process][j];
        }

        completed[process] = 1;

    } while (count != p);

    if (count == p){
        printf("\nSystem is in SAFE state\nSafe sequence: ");
        for (i = 0; i < p; i++){
            printf("P%d ", safe[i] + 1);
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in safe state\n");
    }

    return 0;
}
