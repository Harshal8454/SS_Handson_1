/*============================================================================
Name : 13a.c
Author : Harshal Gujarathi
Description : Write two programs: first program is waiting to catch SIGSTOP signal, 
              the second program will send the signal (using kill system call).
              Find out whether the first  program is able to catch the signal or not.
Date: 12th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigcont_handler(int sig) {
    printf("Received SIGCONT signal. Process resumed.\n");
}

int main() {
    // Set up handler for SIGCONT signal
    signal(SIGCONT, sigcont_handler);

    printf("Waiting for signals. My PID: %d\n", getpid());

    // Infinite loop to keep the process running
    while (1) {
        pause();  // Wait for any signal
    }

    return 0;
}

/*
OUTPUT
Waiting for signals. My PID: 16708

(After execution of program 2)

Received SIGCONT signal. Process resumed.
*/
