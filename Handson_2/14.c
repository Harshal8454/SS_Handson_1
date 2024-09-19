/*============================================================================
Name : 14.c
Author : Harshal Gujarathi
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 14th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(){
    int i,j,fd[2]; //fd[2] is the array to hold pipe file descriptors.
    char buf[80]; // Buffer to store data read from the pipe.
    
    i=pipe(fd); // creates the pipe return 0 on success and -1 on failure
    printf("i=%d\n",i);
    
    j=write(fd[1], "Hello\n", 7);
    
    read(fd[0], buf, j);
    
    printf("From pipe: %s\n", buf);
}

/*
OUTPUT
i=0
From pipe: Hello
*/