/*============================================================================
Name : 29.c
Author : Harshal Gujarathi
Description : Write a program to remove the message queue.
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key = ftok("msgQue", 'O');          // Generate the key
    int msgQueId = msgget(key, 0666);         // Access the message queue

    if (msgQueId == -1) {
        perror("msgget");
        return 1;
    }

    // Remove the message queue
    if (msgctl(msgQueId, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*
OUTPUT
Message queue removed successfully.
*/