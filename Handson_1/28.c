/*============================================================================
Name : 28.c
Author : Harshal Gujarathi
Description :Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

void priority_range(int policy) {
    int max = sched_get_priority_max(policy);
    int min = sched_get_priority_min(policy);

    if (max == -1 || min == -1) {
        perror("Failed to get priority");
        return;
    }

    printf("The Policy %d:\n", policy);
    printf("  The Maximum priority is : %d\n", max);
    printf("  The Minimum priority is : %d\n", min);
}

int main() {
    priority_range(SCHED_FIFO);

    priority_range(SCHED_RR);

    return 0;
}


//OUTPUT
/*
The Policy 1:
  The Maximum priority is : 99
  The Minimum priority is : 1
The Policy 2:
  The Maximum priority is : 99
  The Minimum priority is : 1
*/
