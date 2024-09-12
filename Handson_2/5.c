/*============================================================================
Name : 5.c
Author : Harshal Gujarathi
Description :Write a program to print the system limitation of 
    a. Maximum length of the arguments to the exec family of functions. 
    b. Maximum number of simultaneous process per user id. 
    c. Number of clock ticks (jiffy) per second. 
    d. Maximum number of open files 
    e. Size of a page 
    f. Total number of pages in the physical memory 
    g. Number of  currently available pages in the physical memory.
Date: 10th Sept, 2024.
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>

int main() {
    // a. Maximum length of arguments to exec family of functions
    printf("Max argument length (exec): %ld\n", sysconf(_SC_ARG_MAX));

    // b. Maximum number of simultaneous processes per user ID
    printf("Max processes per user: %ld\n", sysconf(_SC_CHILD_MAX));

    // c. Number of clock ticks per second (jiffy)
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));

    // d. Maximum number of open files
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));

    // e. Size of a page
    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE));

    // f. Total number of pages in physical memory
    struct sysinfo info;
    sysinfo(&info);
    printf("Total number of pages in memory: %lu\n", info.totalram / sysconf(_SC_PAGESIZE));

    // g. Number of currently available pages in physical memory
    printf("Available pages in memory: %lu\n", info.freeram / sysconf(_SC_PAGESIZE));

    return 0;
}
