#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void* routine(){
    printf("my name is manan kapoor\n");
    sleep(2);
    printf("ending thread\n");
}
void* hello(){
    printf("hello\n");
    
}

int main(int argc , char* argv[]){
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,&routine,NULL);
    pthread_create(&t2,NULL,&routine,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;

}