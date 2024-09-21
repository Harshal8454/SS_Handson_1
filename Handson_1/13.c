/*============================================================================
Name : 13.c
Author : Harshal Gujarathi
Description : Write a program to wait for a STDIN for 10 seconds using select. 
              Write a proper print statement to verify whether the data is available within 
              10 seconds or not (check in $man 2 select).
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h>// STD I/O
#include <unistd.h>//system call
#include <sys/select.h>//std i/o

int main() {
    fd_set fds; // Declare fd_set that will monitor STDIN
    struct timeval tv = {10, 0};  // 10 seconds timeout for the select function, 10 seconds and 0 microseconds

    FD_ZERO(&fds);//firstly clears fds
    FD_SET(STDIN_FILENO, &fds); //ads stdin file descriptor to fdset

    int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);//to check the no. of file descriptor,the set of fd to 
    //monitor, no fds are monitored for writing,the timeout.

    if (ret == -1) perror("select failed");
    else if (ret == 0) printf("No data within 10 seconds.\n");
    else printf("Data is available!\n");

    return 0;
}

//OUTPUT
//12
//Data is available!

