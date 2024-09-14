/*============================================================================
Name : 8c.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            c. SIGFPE 
Date: 10th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE (Floating-Point Exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe); // Set up handler for SIGFPE

    int a = 5, b = 0;
    int c = a / b; // Trigger division by zero (SIGFPE)

    return 0;
}
/*
OUTPUT
Caught SIGFPE (Floating-Point Exception)
*/