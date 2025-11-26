#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int shm_fd = shm_open("/myshm",O_RDONLY,0666);
    void *ptr ;
    ptr = mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
    printf("data: %s\n",ptr);
    munmap(ptr,4096);
    close(shm_fd);
    shm_unlink("/myshm");
    return 0;
}