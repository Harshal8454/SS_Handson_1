/*============================================================================
Name : 12.c
Author : Harshal Gujarathi
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file1", O_RDONLY);//This will store the file descriptor returned by the open.
    int flags = fcntl(fd, F_GETFL); //describes the status of the file and how the file was actually opened.
    
    if ((flags & O_ACCMODE) == O_RDONLY) //ACCMODE collects the file status from the flags.
        printf("File is opened in read-only mode.\n");
    else if ((flags & O_ACCMODE) == O_WRONLY)
        printf("File is opened in write-only mode.\n");
    else if ((flags & O_ACCMODE) == O_RDWR)
        printf("File is opened in read-write mode.\n");

    close(fd);
    return 0;
}

//OUTPUT
//File is opened in read-only mode.
