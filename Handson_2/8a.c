/*============================================================================
Name : 8a.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            a.SIGSEGV
Date: 10th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);
    int *ptr = NULL;
    *ptr = 42; // Trigger segmentation fault
    return 0;
}

/*
OUTPUT
Caught SIGSEGV
*/