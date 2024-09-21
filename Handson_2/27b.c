/*============================================================================
Name : 27b.c
Author : Harshal Gujarathi
Description : Write a program to receive messages from the message queue 
            b. With IPC_NOWAIT as a flag
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <errno.h>

struct msgBuffer {
    long mtype;
    char mtext[80];
};

int main() {
    key_t key = ftok("msgQue", 'O');
    int msgQueId = msgget(key, 0666 | IPC_CREAT);
    struct msgBuffer message;

    if (msgrcv(msgQueId, &message, sizeof(message.mtext), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) printf("No message available.\n");
    } else {
        printf("Message: %s\n", message.mtext);
    }

    return 0;
}

/*
OUTPUT (Firstly run the 26.c)
Message: Greetings, this is the second message with mtype 2
*/