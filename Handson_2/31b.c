/*============================================================================
Name : 31b.c
Author : Harshal Gujarathi
Description : Write a program to create a semaphore and initialize value to the semaphore. 
              b. Create a counting semaphore
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 'B'); // Generate a unique key for the semaphore
    int semId = semget(key, 1, IPC_CREAT | 0666); // Create a semaphore set with 1 semaphore

    if (semId == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore value to a specific count (e.g., 5)
    if (semctl(semId, 0, SETVAL, 5) == -1) {
        perror("semctl");
        exit(1);
    }
    printf("Counting semaphore created and initialized to 5.\n");
    return 0;
}

/*
OUTPUT
Counting semaphore created and initialized to 5.
*/

