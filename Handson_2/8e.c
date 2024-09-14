/*============================================================================
Name : 8e.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            e. SIGALRM (use setitimer system call) 
Date: 10th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM (Real-time Timer)\n");
}

int main() {
    signal(SIGALRM, handle_sigalrm); // Set up handler for SIGALRM

    struct itimerval timer = {{0, 0}, {3, 0}}; // 3 seconds interval
    setitimer(ITIMER_REAL, &timer, NULL); // Set the real-time timer

    printf("Waiting for real-time timer\n");

    pause(); // Wait for signal (SIGALRM)

    return 0;
}

/*
OUTPUT
Waiting for real-time timer
Caught SIGALRM (Real-time Timer)
*/
