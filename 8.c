/*============================================================================
Name : 8.c
Author : Harshal Gujarathi
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read. 
             Close the file when end of file is reached.
Date: 20th Aug, 2024.
============================================================================
*/

#include <unistd.h> // For system calls like write()
#include <stdlib.h> // For exit() and other standard library functions
#include <stdio.h>  // For standard I/O functions like fopen(), perror()
#include <fcntl.h>  // For file control options

const char EOL = '\n'; // Define the end-of-line character

int main() {
    // Open the file in read mode
    FILE *fd = fopen("file1", "r");
    if (fd == NULL) {
        perror("Program"); // Print error message if file fails to open
        exit(1);
    }

    int c = fgetc(fd); // Read the first character from the file
    char buffer[1024]; // Buffer to store each line
    int k = 0;         // Index for buffer

    // Loop until the end of the file
    while (c != EOF) {
        while (c != EOF && c != EOL) { // Read until end of line or end of file
            buffer[k++] = c;
            c = fgetc(fd);
        }

        buffer[k++] = '\n';            // Append newline character
        write(1, buffer, k);           // Write the buffer to standard output
        k = 0;                         // Reset buffer index for the next line
        if (c != EOF) c = fgetc(fd);   // Read the next character
    }

    fclose(fd); // Close the file
    return 0;
}

//OUTPUT
//The content of my file1 i.e "HELLO"
