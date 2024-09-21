/*============================================================================
Name : 28.c
Author : Harshal Gujarathi
Description : Write a program to change the exiting message queue permission. (Use msqid_ds structure)
Date: 19th Sept, 2024.
============================================================================
*/


#include <sys/types.h>   
#include <sys/ipc.h>    
#include <sys/msg.h>    
#include <stdio.h>      

int main() {
    key_t key = ftok("msgQue", 1);                                                   // Generate a unique key

    int msgQueId = msgget(key, 0);                                                   // Get the existing message queue ID

    struct msqid_ds msgQueDataStruct;                                                // Define the message queue data structure
    
    msgctl(msgQueId, IPC_STAT, &msgQueDataStruct);                                   // Get the current message queue information

    printf("Current permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777);      // Print current permissions

    msgQueDataStruct.msg_perm.mode = 0660;                                           // Modify the permissions

    msgctl(msgQueId, IPC_SET, &msgQueDataStruct);                                    // Set the new permissions

    printf("Updated permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777);      // Print new permissions

    return 0;
}

/*
OUTPUT
Current permissions: 777
Updated permissions: 660
*/