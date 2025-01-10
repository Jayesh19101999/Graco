#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork(); // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d\n", getpid());
    } else {
        // Parent process
        printf("This is the parent process. Child PID: %d\n", pid);
    }

    return 0;
}

