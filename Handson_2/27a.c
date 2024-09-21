/*============================================================================
Name : 27a.c
Author : Harshal Gujarathi
Description : Write a program to receive messages from the message queue 
            a.with 0 as a flag
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct msgBuffer {
    long mtype;           // Message type
    char mtext[80];       // Message text
};

int main() {
    key_t key = ftok("msgQue", 'O');                // Generate the key
    int msgQueId = msgget(key, 0666 | IPC_CREAT);   // Get access to the message queue

    struct msgBuffer message;

    // Receive messages from the queue with any type (0 as a flag)
    msgrcv(msgQueId, &message, sizeof(message.mtext), 0, 0);

    // Print the received message
    printf("Received message: %s\n", message.mtext);

    return 0;
}

/*
OUTPUT (Firstly run 26.c)
Received message: Hello, this is the first message with mtype 1
*/