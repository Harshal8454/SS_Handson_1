/*============================================================================
Name : 30a.c
Author : Harshal Gujarathi
Description : Write a program to create a shared memory. 
              a. Write some data to the shared memory
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>       
#include <sys/ipc.h>      
#include <sys/shm.h>      
#include <string.h>       

int main() {
    key_t key = ftok("sharedMmy", 'O');                       
    int sharedMmyId = shmget(key, 1024, IPC_CREAT | 0774); // Create shared memory. Create 1024 bytes of shared memory

    
    char *dt = (char *)shmat(sharedMmyId, NULL, 0);  // Link to the shared memory 
    strcpy(dt, "Hello, Welcome to IIITB!");                 // Write dt
    
    return 0;
}