/*============================================================================
Name : 22.c
Author : Harshal Gujarathi
Description : Write a program to wait for data to be written into FIFO within 10 seconds, 
              use select system call with FIFO.
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("myfifo", 0666);  // Create FIFO
    int fd = open("myfifo", O_RDONLY | O_NONBLOCK);  // Open in non-blocking mode

    fd_set set;
    FD_ZERO(&set);
    FD_SET(fd, &set);

    struct timeval timeout = {10, 0};  // 10-second timeout

    printf("Waiting for data...\n");
    int res = select(fd + 1, &set, NULL, NULL, &timeout);

    if (res > 0) {
        char buf[100];
        int len = read(fd, buf, sizeof(buf));
        buf[len] = '\0';
        printf("Received: %s\n", buf);
    } else {
        printf("Timeout or error.\n");
    }

    close(fd);
    unlink("myfifo");  // Remove FIFO
    return 0;
}


/*
OUTPUT
created a myfifo 
(When no data is passed in 10 sec)
Waiting for data...
Timeout or error.

(when the data is passed by the other terminal within 10 sec)
Waiting for data...
Received: Hello from FIFO
*/