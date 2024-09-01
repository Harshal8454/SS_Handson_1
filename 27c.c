/*============================================================================
Name : 27c.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -Rl 
            by the following system calls
            c. execle
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execle\n");
    execle("/usr/bin/ls", "ls", "-Rl", NULL, NULL);

    perror("execle failed");
    return 1;
}

//OUTPUT
/*
Executing ls -Rl using execle
.:
total 168
-rw-rw-r-- 1 harshal harshal   900 Aug 28 23:57  10.c
-rw-rw-r-- 1 harshal harshal  2166 Aug 28 23:59  11.c
-rw-rw-r-- 1 harshal harshal  1012 Aug 29 00:00  12.c
-rw-rw-r-- 1 harshal harshal  1222 Aug 29 00:05  13.c
-rw-rw-r-- 1 harshal harshal  1284 Aug 29 00:05  14.c
-rw-rw-r-- 1 harshal harshal  1580 Aug 29 00:03  15.c
-rw-rw-r-- 1 harshal harshal  2771 Aug 29 00:04  16.c
*/