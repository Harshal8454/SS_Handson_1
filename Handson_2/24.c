/*============================================================================
Name : 24.c
Author : Harshal Gujarathi
Description : Write a program to create a message queue and print the key and message queue id.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>      
#include <sys/ipc.h>    
#include <sys/msg.h> 

int main() {
    key_t key;               
    int msgQueId;            
    key = ftok("prgF", 'O');  // Generate a unique key using ftok (file path and project identifier).

    msgQueId = msgget(key, IPC_CREAT | 0777);   // Create the message queue and return its ID

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgQueId);

    return 0;
}


/*
OUTPUT
Message Queue Key: -1
Message Queue ID: 0
*/