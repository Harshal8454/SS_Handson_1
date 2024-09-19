/*============================================================================
Name : 13b.c
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

int main() {
    pid_t pid;

    printf("Enter the PID of the process to send signals to: ");
    scanf("%d", &pid);

    // Sending SIGSTOP to stop the process
    kill(pid, SIGSTOP);
    printf("Sent SIGSTOP to process %d.\n", pid);

    // Sleep for a few seconds to demonstrate stopping
    sleep(5);

    // Sending SIGCONT to resume the process
    kill(pid, SIGCONT);
    printf("Sent SIGCONT to process %d.\n", pid);

    return 0;
}

/*
OUTPUT
Enter the PID of the process to send signals to: 16708 (Entered from the first program)

Sent SIGSTOP to process 16708.

Sent SIGCONT to process 16708.
*/
