/*============================================================================
Name : 25.c
Author : Harshal Gujarathi
Description : 25. Write a program to print a message queue's (use `msqid_ds` and `ipc_perm` structures)
    1. Access permission 
    2. `uid`, `gid` 
    3. Time of last message sent and received 
    4. Time of last change in the message queue
    5. Size of the queue 
    6. Number of messages in the queue
    7. Maximum number of bytes allowed
    8. PID of the `msgsnd` and `msgrcv`
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Create or open a file to generate a key for the message queue
    const char *path = "aa"; // Change to an existing file or create it
    int fd = open(path, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Failed to create/open file");
        return 1;
    }
    close(fd);

    // Generate a key for the message queue
    key_t key = ftok(path, 99);
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    // Create the message queue with read/write permissions
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    if (msgq_id == -1) {
        perror("msgget error");
        return 1;
    }

    // Declare a structure to hold message queue information
    struct msqid_ds mq;

    // Get the message queue statistics
    if (msgctl(msgq_id, IPC_STAT, &mq) == -1) {
        perror("msgctl error");
        return 1;
    }

    // Print message queue details
    printf("Access permissions: %03o\n", mq.msg_perm.mode & 0777);
    printf("Effective UID of owner: %d\n", mq.msg_perm.uid);
    printf("Effective GID of owner: %d\n", mq.msg_perm.gid);
    printf("Effective UID of creator: %d\n", mq.msg_perm.cuid);
    printf("Effective GID of creator: %d\n", mq.msg_perm.cgid);
    printf("Time of last message sent: %s", ctime(&mq.msg_stime));
    printf("Time of last message received: %s", ctime(&mq.msg_rtime));
    printf("Time of last change: %s", ctime(&mq.msg_ctime));
    printf("Current size of queue (bytes): %lu\n", mq.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", mq.msg_qnum);
    printf("Maximum number of bytes allowed in queue: %lu\n", mq.msg_qbytes);
    printf("PID of last msgsnd: %d\n", mq.msg_lspid);
    printf("PID of last msgrcv: %d\n", mq.msg_lrpid);

    return 0;
}

/*
OUTPUT
Access permissions: 666
Effective UID of owner: 1000
Effective GID of owner: 1000
Effective UID of creator: 1000
Effective GID of creator: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change: Thu Sep 19 14:41:29 2024
Current size of queue (bytes): 0
Number of messages in queue: 0
Maximum number of bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
*/