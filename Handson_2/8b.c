/*============================================================================
Name : 8b.c
Author : Harshal Gujarathi
Description : Write a separate program using signal system call to catch the following signals.
            b. SIGINT 
Date: 10th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT\n");
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1) {
        printf("Its Running, Press Ctrl+C to catch Signal\n");
        sleep(5);
    }
    return 0;
}

/*
Its Running, Press Ctrl+C to catch Signal
Its Running, Press Ctrl+C to catch Signal
Caught SIGINT
Its Running, Press Ctrl+C to catch Signal
Its Running, Press Ctrl+C to catch Signal
Caught SIGINT
Its Running, Press Ctrl+C to catch Signal
*/
