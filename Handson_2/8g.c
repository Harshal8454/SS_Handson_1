/*============================================================================
Name : 8g.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            g. SIGPROF (use setitimer system call)
Date: 10th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigprof(int signum) {
    printf("Caught SIGPROF (Profiling Timer)\n");
}

int main() {
    signal(SIGPROF, handle_sigprof); // Set up handler for SIGPROF

    struct itimerval timer = {{0, 0}, {3, 0}}; // 3 seconds interval
    setitimer(ITIMER_PROF, &timer, NULL); // Set the profiling timer

    printf("Waiting for profiling timer\n");

    while (1); // Busy loop to trigger SIGPROF

    return 0;
}

/*
Waiting for profiling timer
Caught SIGPROF (Profiling Timer)
*/

