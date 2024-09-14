/*============================================================================
Name : 11.c
Author : Harshal Gujarathi
Description : Write a program to ignore a SIGINT signal then reset the default 
              action of the SIGINT signal - use sigaction system call.
Date: 10th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Custom handler for SIGINT
void sigint_handler(int sig) {
    printf("SIGINT received, restoring default action.\n");

    // Reset SIGINT to default action
    struct sigaction sa = {0};
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main() {
    // Ignore SIGINT
    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT ignored. Wait 5 seconds\n");
    sleep(5);

    // Set SIGINT to custom handler
    sa.sa_handler = sigint_handler;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT handler set. (Press Ctrl+C)\n");

    // Wait indefinitely
    while (1) pause();

    return 0;
}

/*
OUTPUT
SIGINT ignored. Wait 5 seconds
SIGINT handler set. (Press Ctrl+C)
SIGINT received, restoring default action.
*/