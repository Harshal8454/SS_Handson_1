/*============================================================================
Name : 24.c
Author : Harshal Gujarathi
Description :Write a program to create an orphan process.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {  
        printf("In child - Before orphan PPID = %d\n", getppid());
        sleep(5);  
        printf("In child - After orphan PPID = %d\n", getppid());
    } 
    else if (pid > 0) { 
        printf("This is parent process %d\n", getpid());
        exit(0);
    } 
    else { 
        printf("Fork failed!\n");
        return 1;
    }
    return 0;
}

/* OUTPUT
This is parent process 7229
In child - Before orphan PPID = 7229

In child - After orphan PPID = 1494
*/