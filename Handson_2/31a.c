/*============================================================================
Name : 31a.c
Author : Harshal Gujarathi
Description : Write a program to create a semaphore and initialize value to the semaphore. 
              a. Create a binary semaphore 
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main() {
    key_t key = ftok("semfile", 'A'); // Generate a unique key for the semaphore
    int semId = semget(key, 1, IPC_CREAT | 0666); // Create a semaphore set with 1 semaphore

    if (semId == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore value to 1 (binary semaphore)
    if (semctl(semId, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(1);
    }

    printf("Binary semaphore created and initialized to 1.\n");
    return 0;
}

/*
OUTPUT
Binary semaphore created and initialized to 1.
*/