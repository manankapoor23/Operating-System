// fork_demo.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) { // child
        printf("Child: pid=%d, ppid=%d\n", getpid(), getppid());
    } else { // parent
        printf("Parent: pid=%d, child pid=%d\n", getpid(), pid);
    }
    return 0;
}
