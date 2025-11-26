#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int shm_fd = shm_open("/myshm",O_CREAT|O_RDWR,0666);
    void *ptr ;
    ftruncate(shm_fd,4096);
    ptr = mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
    sprintf(ptr, "message from write");
    munmap(ptr,4096);
    close(shm_fd);
    return 0;
}