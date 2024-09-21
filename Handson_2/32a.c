/*============================================================================
Name : 32a.c
Author : Harshal Gujarathi
Description : Write a program to implement semaphore to protect any critical section. 
              a. Rewrite the ticket number creation program using semaphore
Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>    // For using ftok().
#include <sys/sem.h>    // For using semaphore operations like semget(), semctl() and semop().
#include <fcntl.h>      // For using open(), O_CREAT and O_RDWR.
#include <unistd.h>     // For using lseek(), write(), close().
#include <stdio.h>      // For using perror() and printf.
#include <stdlib.h>     // For using exit().

union semun {
    int val;               // Used for SETVAL
    struct semid_ds *buf;  // Used for IPC_STAT and IPC_SET
    unsigned short *array;  // Used for GETALL and SETALL
    struct seminfo *__buf;  // Used for IPC_INFO
};

struct ticket {
    int number;
};

int main() {
    key_t key = ftok("tktFile", 'O');  
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666);  // Create semaphore
    union semun sem_val;
    sem_val.val = 1;                                // Set initial semaphore value to 1
    semctl(semaphoreId, 0, SETVAL, sem_val);       // Initialize semaphore

    int file = open("ticketdb", O_CREAT | O_RDWR, 0666);  
    struct ticket t = {144}; 

    struct sembuf operations = {0, -1, 0};          // Lock semaphore
    semop(semaphoreId, &operations, 1);             // Begin critical section

    t.number++;  
    lseek(file, 0, SEEK_SET); 
    write(file, &t, sizeof(t));                     // Overwrite the file.
    close(file);

    operations.sem_op = 1;                          // Unlock semaphore
    semop(semaphoreId, &operations, 1);             // End critical section

    return 0;
}
