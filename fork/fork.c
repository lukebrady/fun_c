#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    int out;
    // Fork the process and get the PID.
    pid_t pid = fork();
    if(pid != 0) {
        printf("I am the parent process.\n");
        _exit(1);
    } 
    else {
        printf("I am the child process.\n");
        out = execv("echo", (char *[]){"echo", NULL, NULL});
        if(out != 0) {
            printf("The echo failed.\n");
        }
        else {
            printf("The echo successfully ran.\n");
        }
        _exit(2);
    } 
    return 0;
}