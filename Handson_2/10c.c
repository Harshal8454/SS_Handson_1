/*============================================================================
Name : 10c.c
Author : Harshal Gujarathi
Description : Write a separate program using sigaction system call to catch the following signals. 
              c.SIGFPE
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_fpe(int sig) {
    printf("SIGFPE caught: Integer division by zero!\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handle_fpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    // Trigger SIGFPE by dividing by zero
    int x = 1 / 0;  // This will trigger SIGFPE on most systems

    return 0;
}

/*
OUTPUT
SIGFPE caught: Integer division by zero!
*/