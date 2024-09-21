/*============================================================================
Name : 32c.c
Author : Harshal Gujarathi
Description : Write a program to implement semaphore to protect any critical section. 
              c. Protect multiple pseudo resources (may be two) using counting semaphore
Date: 20th Sept, 2024.
============================================================================
*/


#include <sys/ipc.h>     // For using ftok().
#include <sys/sem.h>     // For semaphore operations like semget(), semctl(), and semop().
#include <stdio.h>       // For using standard input/output functions like printf().
#include <fcntl.h>       // For using open(), O_RDWR and O_CREAT.
#include <unistd.h>      // For using lseek() and close().

union semun {
    int val;     
};

struct ticketStruct {
    int tktNo; 
};

void wait_semaphore(int semId) {
    struct sembuf op = {0, -1, 0}; // P operation (wait)
    semop(semId, &op, 1);
}

void signal_semaphore(int semId) {
    struct sembuf op = {0, 1, 0}; // V operation (signal)
    semop(semId, &op, 1);
}

int main() {
    key_t key = ftok("countingSem", 435);         
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666); // Create semaphore
    union semun arg;
    arg.val = 2; // Counting semaphore initialized to 2 resources

    semctl(semaphoreId, 0, SETVAL, arg); // Set the initial value

    int fileDescript = open("database", O_CREAT | O_RDWR, 0666); // Open file for resources
    struct ticketStruct tkt = {156}; // Initial ticket number

    for (int i = 0; i < 5; i++) {
        wait_semaphore(semaphoreId); // Lock semaphore for ticket resource
        printf("Ticket Resource accessed by %d iteration.\n", i + 1);
        tkt.tktNo++;

        wait_semaphore(semaphoreId); // Lock semaphore for file resource
        printf("File Resource accessed by %d iteration.\n", i + 1);
        lseek(fileDescript, 0, SEEK_SET); // Move to start of file
        write(fileDescript, &tkt, sizeof(tkt)); // Write resources to file

        signal_semaphore(semaphoreId); // Unlock semaphore for file resource
        signal_semaphore(semaphoreId); // Unlock semaphore for ticket resource
    }

    close(fileDescript);                              
    return 0;
}

/*
OUTPUT
Ticket Resource accessed by 1 iteration.
File Resource accessed by 1 iteration.
Ticket Resource accessed by 2 iteration.
File Resource accessed by 2 iteration.
Ticket Resource accessed by 3 iteration.
File Resource accessed by 3 iteration.
Ticket Resource accessed by 4 iteration.
File Resource accessed by 4 iteration.
Ticket Resource accessed by 5 iteration.
File Resource accessed by 5 iteration.
*/