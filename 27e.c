/*============================================================================
Name : 27e.c
Author : Harshal Gujarathi
Description :Write a program to execute ls -Rl 
            by the following system calls
            e. execvp
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execvp\n");
    char *args[] = { "ls", "-Rl", NULL };
    execvp("ls", args);
    
    perror("execvp failed");
    return 1;
}

//OUTPUT
/*
Executing ls -Rl using execvp
.:
total 208
-rw-rw-r-- 1 harshal harshal   900 Aug 28 23:57  10.c
-rw-rw-r-- 1 harshal harshal  2166 Aug 28 23:59  11.c
-rw-rw-r-- 1 harshal harshal  1012 Aug 29 00:00  12.c
-rw-rw-r-- 1 harshal harshal  1222 Aug 29 00:05  13.c
-rw-rw-r-- 1 harshal harshal  1284 Aug 29 00:05  14.c
-rw-rw-r-- 1 harshal harshal  1580 Aug 29 00:03  15.c
-rw-rw-r-- 1 harshal harshal  2771 Aug 29 00:04  16.c
-rw-rw-r-- 1 harshal harshal   871 Aug 29 00:07  17a.c
-rw-rw-r-- 1 harshal harshal  1393 Aug 29 00:08 '17 b.c'
-rw-rw-r-- 1 harshal harshal  1046 Aug 29 00:11  18a.c
-rw-rw-r-- 1 harshal harshal  2406 Aug 29 00:12 '18 b.c'
-rw-rw-r-- 1 harshal harshal  1013 Aug 29 16:43  19.c
*/
