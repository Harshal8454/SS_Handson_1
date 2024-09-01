/*============================================================================
Name : 27b.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -Rl 
            by the following system calls
            b. execlp
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execlp\n");
    // searches for the ls executable in the path.
    execlp("ls", "ls", "-Rl", NULL);

    perror("execlp failed");
    return 1;
}
/*
executing ls -Rl using execlp
.:
total 148
-rw-rw-r-- 1 harshal harshal   900 Aug 28 23:57  10.c
-rw-rw-r-- 1 harshal harshal  2166 Aug 28 23:59  11.c
-rw-rw-r-- 1 harshal harshal  1012 Aug 29 00:00  12.c
-rw-rw-r-- 1 harshal harshal  1222 Aug 29 00:05  13.c
-rw-rw-r-- 1 harshal harshal  1284 Aug 29 00:05  14.c
-rw-rw-r-- 1 harshal harshal  1580 Aug 29 00:03  15.c
*/
