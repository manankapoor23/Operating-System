#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int email = 0 ;

void* routine(){
    for(int i =0;i<100000;i++){
        email++;
    }

}

int main(int argc , char* argv[]){
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,&routine,NULL);
    pthread_create(&t2,NULL,&routine,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Number of mails %d",email);
    return 0;
}