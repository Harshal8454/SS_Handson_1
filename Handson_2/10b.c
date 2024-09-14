/*============================================================================
Name : 10b.c
Author : Harshal Gujarathi
Description : Write a separate program using sigaction system call to catch the following signals. 
              b.SIGINT
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("SIGINT caught\n");
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigint };
    sigaction(SIGINT, &sa, NULL);
    while (1) sleep(5);  // Wait for SIGINT (Ctrl+C)
    return 0;
}

/*
OUTPUT
SIGINT caught
SIGINT caught
*/
