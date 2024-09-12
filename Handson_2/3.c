/*============================================================================
Name : 3.c
Author : Harshal Gujarathi
Description :Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit = {512, 4096};  // Set soft limit to 512, hard limit to 4096
    setrlimit(RLIMIT_NOFILE, &limit);   // Apply the limit

    getrlimit(RLIMIT_NOFILE, &limit);   // Fetch the updated limits
    printf("Open files limit: Soft = %ld, Hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    return 0;
}

/*
OUTPUT
Open files limit: Soft = 512, Hard = 4096
*/
