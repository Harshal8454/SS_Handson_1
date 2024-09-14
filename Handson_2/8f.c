/*============================================================================
Name : 8f.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            f. SIGVTALRM (use setitimer system call) 
Date: 10th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigvtalrm(int signum) {
    printf("Caught SIGVTALRM (Virtual Timer)\n");
}

int main() {
    signal(SIGVTALRM, handle_sigvtalrm); // Set up handler for SIGVTALRM

    struct itimerval timer = {{0, 0}, {3, 0}}; // 3 seconds interval
    setitimer(ITIMER_VIRTUAL, &timer, NULL); // Set the virtual timer

    printf("Waiting for virtual timer\n");

    while (1); // Busy loop to trigger SIGVTALRM

    return 0;
}
/*
OUTPUT
Waiting for virtual timer
Caught SIGVTALRM (Virtual Timer)
*/
