/*============================================================================
Name : 25.c
Author : Harshal Gujarathi
Description :Write a program to create three child processes. 
            The parent should wait for a particular child (use waitpid system call).
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0) {
        printf("The PID of the First child = %d\n", getpid());
        exit(0);
    }
    pid2 = fork();
    if (pid2 == 0) {
        printf("The PID of the Second child = %d\n", getpid());
        exit(0);
    }
    pid3 = fork();
    if (pid3 == 0) {
        printf("The PID of the Third child = %d\n", getpid());
        exit(0);
    }
    if (pid3 > 0) {
        waitpid(pid3, NULL, 0);
        printf("Parent: Finished waiting for Child 3\n");
    }
    return 0;
}

//OUTPUT
/*
The PID of the First child = 7699
The PID of the Second child = 7700
The PID of the Third child = 7701
Parent: Finished waiting for Child 3
*/
