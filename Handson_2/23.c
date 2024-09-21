/*============================================================================
Name : 23.c
Author : Harshal Gujarathi
Description : Write a program to print the maximum number of files 
              can be opened within a process and size of a pipe (circular buffer).
Date: 19th Sept, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("max size of pipe : %ld", PIPE_BUF);
    printf("\nmax file can be opened : %ld", OPEN_MAX);
}

/*
OUTPUT
max size of pipe : 4096
max file can be opened : 1048576
*/