/*============================================================================
Name : 21.c
Author : Harshal Gujarathi
Description :Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
    } else {
        printf("Parent PID: %d\n", getpid());
    }
    return 0;
}

//OUTPUT
//Parent PID: 18018
//Child PID: 18019
