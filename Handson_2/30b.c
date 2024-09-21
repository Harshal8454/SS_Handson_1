/*============================================================================
Name : 30b.c
Author : Harshal Gujarathi
Description : Write a program to create a shared memory. 
              b. Attach with O_RDONLY and check whether you are able to overwrite. 
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>      
#include <sys/ipc.h>      
#include <sys/shm.h>      
#include <string.h>       


int main() {
    key_t key = ftok("sharedMmy", 0); 
    int sharedMmyId = shmget(key, 256, IPC_CREAT | 0744);  // Create shared memory segment (512 bytes)
    char *data;

    data = shmat(sharedMmyId, 0, SHM_RDONLY);              // Link in read-only mode

    printf("Data to add in shared memory: ");
    scanf("%s", data);                                     // Trying to overwrite. But will fail.

}

/*
OUTPUT
Data to add in shared memory: Hello
Segmentation fault (core dumped)
*/