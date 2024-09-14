/*============================================================================
Name : 10a.c
Author : Harshal Gujarathi
Description : Write a separate program using sigaction system call to catch the following signals. 
              a.SIGSEGV
Date: 10th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int signum) {
    printf("SIGSEGV caught\n");
    exit(1);
}

int main() {
    // sigaction struct is used to define how the signal is handled.
    struct sigaction sa = { .sa_handler = handle_sigsegv };
    sigaction(SIGSEGV, &sa, NULL);
    *(int *)0 = 0;  // Trigger segmentation fault by dereferencing the pointer.
    return 0;
}

/*
OUTPUT
SIGSEGV caught
*/