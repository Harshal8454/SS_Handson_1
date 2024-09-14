/*============================================================================
Name : 12.c
Author : Harshal Gujarathi
Description : Write a program to create an orphan process.Use kill system call to send 
              SIGKILL signal to the parent process from the child process.
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid > 0) {
        printf("Parent process (PID: %d) is running\n", getpid());
        sleep(10);  // Keep parent alive for a while
    } else if (pid == 0) {
        printf("Child process (PID: %d) sending SIGKILL to parent (PID: %d)\n", getpid(), getppid());
        sleep(2);  // Allow some time before killing the parent
        kill(getppid(), SIGKILL);  // Send SIGKILL to the parent
        printf("Child process becomes orphan now.\n");
        sleep(5);  // Keep the child alive to demonstrate it's an orphan
    } else {
        // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}

/*
OUTPUT
Parent process (PID: 75766) is running
Child process (PID: 75767) sending SIGKILL to parent (PID: 75766)
Child process becomes orphan now.
*/