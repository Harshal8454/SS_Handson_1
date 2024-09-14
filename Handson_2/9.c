/*============================================================================
Name : 9.c
Author : Harshal Gujarathi
Description : Write a program to ignore a SIGINT signal then reset the 
              default action of the SIGINT signal - Use signal system call.
Date: 10th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for resetting SIGINT to default action
void reset_sigint(int signum) {
    printf("SIGINT caught, resetting to default\n");
    signal(SIGINT, SIG_DFL); // Reset SIGINT to default action
}

int main() {
    signal(SIGINT, SIG_IGN); // Ignore the SIGINT signal initially
    printf("SIGINT is ignored. (Press Ctrl+C)\n");

    sleep(5);// Sleep for 5 seconds, during which SIGINT will be ignored

    signal(SIGINT, reset_sigint);// Reset SIGINT to be caught and handled by reset_sigint function
    printf("SIGINT reset to custom handler. (Press Ctrl+C)\n");

    while (1) {// Infinite loop to keep the program running and waiting for SIGINT
        pause(); // Wait for signals
    }

    return 0;
}

/*
OUTPUT
SIGINT is ignored. (Press Ctrl+C)
SIGINT reset to custom handler. (Press Ctrl+C)
SIGINT caught, resetting to default
*/