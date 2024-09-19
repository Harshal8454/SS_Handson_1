/*============================================================================
Name : 17a.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -l | wc
             a.Use dup
Date: 14th Sept, 2024.
============================================================================
*/
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd[2];
    pipe(fd);

    if(!fork()) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    }
    else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        execlp("wc", "wc", NULL);
    }
}

/*
OUTPUT
2      11      61
(it represents the number of lines, words and characters)
*/