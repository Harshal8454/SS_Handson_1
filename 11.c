/*============================================================================
Name : 11.c
Author : Harshal Gujarathi
Description : Write a program to open a file, duplicate the file descriptor and append the 
              file with both the descriptors and check whether the file is updated properly or not. 
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h> //std i/o
#include <fcntl.h> //system call
#include <unistd.h>

// USING DUP
int main() {
    // Opening the file in append mode
    int fd = open("file1", O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd < 0) { //if the file cannot be opened printing the error.
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor to the new descriptor
    int fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Write to the file using the original descriptor
    write(fd, "Original File Descriptor\n", 12);

    // Write to the file using the duplicated descriptor
    write(fd_dup, "Duplicated File Descriptor\n", 14);

    // Close both file descriptors
    close(fd);
    close(fd_dup);

    return 0;
}

//USING DUP2
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file1", O_WRONLY | O_APPEND | O_CREAT, 0644);
    int fd_dup = dup2(fd, 10);  // Duplicates fd to descriptor 10
    // stores the value 10 as a duplicated file descriptor
    write(fd, "Original File Descriptor\n", 12);
    write(fd_dup, "Duplicated File Descriptor\n", 14);

    close(fd);
    close(fd_dup);
    return 0;
}

//USING FCNTL
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file1", O_WRONLY | O_APPEND | O_CREAT, 0644);
    int fd_dup = fcntl(fd, F_DUPFD, 0);  // Duplicate fd using fcntl to the lowest available file descriptor 

    write(fd, "Original File Descriptor\n", 12);
    write(fd_dup, "Duplicated File Descriptor\n", 14);

    close(fd);
    close(fd_dup);
    return 0;
}

//OUTPUT
//I am Harshal GujarathiOriginal File Descriptor
// Duplicated File Descriptor