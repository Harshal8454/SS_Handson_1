/*============================================================================
Name : 8d.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            d. SIGALRM (use alarm system call) 
Date: 10th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM (Alarm Signal)\n");
}

int main() {
    signal(SIGALRM, handle_sigalrm); // Set up handler for SIGALRM

    alarm(3); // Set an alarm for 3 seconds

    printf("Waiting for alarm\n");

    pause(); // Wait for signal (SIGALRM)

    return 0;
}

/*
OUTPUT
Waiting for alarm
Caught SIGALRM (Alarm Signal)
*/