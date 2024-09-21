/*============================================================================
Name : 29.c
Author : Harshal Gujarathi
Description :Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_scheduler(pid_t pid) {
    int scheduler = sched_getscheduler(pid);
    switch (scheduler) {
        case SCHED_OTHER:
            printf("Current scheduler is SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduler is SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduler is SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduler!\n");
    }
}

int main() {
    pid_t pid = 0;  // 0 means the calling process

    // Get and print current scheduler
    print_scheduler(pid);

    // Set up the scheduling parameters
    struct sched_param param;
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);

    // Try to set SCHED_FIFO
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler (SCHED_FIFO)");
    } else {
        printf("Successfully set scheduler to SCHED_FIFO\n");
        print_scheduler(pid);
    }

    // Try to set SCHED_RR
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler (SCHED_RR)");
    } else {
        printf("Successfully set scheduler to SCHED_RR\n");
        print_scheduler(pid);
    }

    return 0;
}

/*
OUTPUT
Current scheduler is SCHED_OTHER
sched_setscheduler (SCHED_FIFO): Operation not permitted
sched_setscheduler (SCHED_RR): Operation not permitted
*/
