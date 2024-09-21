/*============================================================================
Name : 7.c
Author : Harshal Gujarathi
Description :Write a program to copy file1 into file2 ($cp file1 file2).
Date: 20th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>  // Required for open() and flags like O_RDONLY, O_WRONLY

int main(int argc, char *argv[]) {
    // Open source file for reading
    int file1 = open(argv[1], O_RDONLY);
    if (file1 < 0) {
        perror("Error opening source file");
        exit(1);
    }

    // Open/create destination file for writing
    int file2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0600); //  the file is created using O_EXCL command
    if (file2 < 0) {
        perror("Error opening/creating destination file");
        close(file1);
        exit(1);
    }

    // Buffer to store read data
    char buffer[1024];
    int size_read;

    // Read from source and write to destination
    while ((size_read = read(file1, buffer, sizeof(buffer))) > 0) {
        write(file2, buffer, size_read);
    }

    // Close both files
    close(file1);
    close(file2);
    printf("File copied successfully.\n");
    return 0;
}

//OUTPUT
/*gcc -o try 7.c
./try file1 file2
*/
//File copied successfully.

