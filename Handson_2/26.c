/*============================================================================
Name : 26.c
Author : Harshal Gujarathi
Description : Write a program to send messages to the message queue. Check ipcs -q
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/types.h>  
#include <sys/ipc.h>    
#include <sys/msg.h>    
#include <stdio.h>      

int main() {
    key_t key = ftok("msgQue", 'O');                // Generate a unique key for the message queue using the file "mq" and project identifier 1
    int msgQueId = msgget(key, IPC_CREAT | 0666);    // Create a message queue with read and write permissions
    struct msgBuffer {                              // Define the message buffer structure
        long mtype;                                 // Message type
        char mtext[80];                             // Message text
    };

    // Initialize two messages with different types
    struct msgBuffer message1 = {1, "Hello, this is the first message with mtype 1"};
    struct msgBuffer message2 = {2, "Greetings, this is the second message with mtype 2"};

    msgsnd(msgQueId, (void *)&message1, sizeof(message1.mtext), IPC_NOWAIT);     // Send the first message to the message queue
    msgsnd(msgQueId, (void *)&message2, sizeof(message2.mtext), IPC_NOWAIT);     // Send the second message to the message queue

    return 0;
}

/*
OUTPUT (After running ipcs -q)
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          harshal    777        320          4  
*/