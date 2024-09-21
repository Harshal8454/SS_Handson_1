/*============================================================================
Name : 30c.c
Author : Harshal Gujarathi
Description : Write a program to create a shared memory. 
              c. Detach the shared memory 
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

    shmdt(data);                                           // Unlink shared memory
}