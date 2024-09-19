/*============================================================================
Name : 17c.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -l | wc
             c.Use fcntl
Date: 14th Sept, 2024.
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int fd[2];
    pipe(fd);

    if(fork()) {
        close(0);
        close(fd[1]);
        if(fcntl(fd[0], F_DUPFD, 0) == -1)
            printf("error");

        execlp("wc", "wc", NULL);
    }
    else {
        close(1);
        close(fd[0]);
        if(fcntl(fd[1], F_DUPFD, 1) == -1)
            printf("error");

        execlp("ls", "ls", "-l", NULL);
    }
}

/*
OUTPUT
4      29     166
(it represents the number of lines, words and characters)
*/