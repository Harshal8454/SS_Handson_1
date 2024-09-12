/*============================================================================
Name : 2.c
Author : Harshal Gujarathi
Description :Write a program to print the system resource limits. 
             Use getrlimit system call.
Date: 9th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

void display_limit(int resource, const char *desc) {
    struct rlimit limit;
    getrlimit(resource, &limit);
    printf("%s: Soft = %ld, Hard = %ld\n", desc, limit.rlim_cur, limit.rlim_max);
}

int main() {
    display_limit(RLIMIT_CPU, "CPU Time");
    display_limit(RLIMIT_FSIZE, "File Size");
    display_limit(RLIMIT_STACK, "Stack Size");
    display_limit(RLIMIT_NOFILE, "Open Files");
    return 0;
}

/*
CPU Time: Soft = -1, Hard = -1
File Size: Soft = -1, Hard = -1
Stack Size: Soft = 8388608, Hard = -1
Open Files: Soft = 1048576, Hard = 1048576
*/