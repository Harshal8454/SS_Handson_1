/*============================================================================
Name : 17b.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -l | wc
             b.Use dup2
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
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", NULL);
    }
    else {
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", NULL);
    }
}

/*
OUTPUT
3      20     114
(it represents the number of lines, words and characters)
*/