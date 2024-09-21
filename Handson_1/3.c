/*============================================================================
Name : 3.c
Author : Harshal Gujarathi
Description : Write a program to create a file and print the file descriptor value. Use creat() system call
Date: 15th Aug, 2024.
============================================================================
*/

#include <stdio.h> // This is used for standard i/o functions.
#include <fcntl.h> // This is for file control options.
#include <unistd.h> // This is for file descriptor options.

int main() {
    // The file is created.
    const char *fileName = "example.txt";

    // Use creat() system call to create the file with read/write permissions.
    int fd = creat(fileName, 0644); // 0644 is the file permission: rw-r--r--

    // Checks if the file was created successfully
    if (fd == -1) {
        perror("Sorry, The file is not created"); //perror is called to print an error
        return 1;
    }

    // Print the file descriptor value
    printf("The File descriptor values: %d\n", fd);

    // Close the file descriptor to free up the system resources.
    close(fd);

    return 0;
}


//OUTPUT
//The File descriptor values: 3
