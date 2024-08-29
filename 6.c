/*============================================================================
Name : 6.c
Author : Harshal Gujarathi
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 17th Aug, 2024.
============================================================================
*/

#include <unistd.h> //system call
#include <stdlib.h> //lib
#include <stdio.h> //std i/o

// declare the constant buffer size 
#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    // declare the variables to store the number of bytes to be read and write
    ssize_t bytesRead, bytesWritten;

    while (1) {
        // Read from the file descriptor 0
        bytesRead = read(0, buffer, BUFFER_SIZE);
        
        // Check if read failed or the file is ended.
        if (bytesRead <= 0) {
            //exit the loop
            break;
        }

        // Write to standard output file descriptor 1
        bytesWritten = write(1, buffer, bytesRead);
        // Check if write failed
        if (bytesWritten != bytesRead) {
            // If the number of bytes written does not match bytes read, exit with error
            perror("Error writing to standard output");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

//OUTPUT
//----> I am Harshal (input)
//I am Harshal <----- (output)