/*============================================================================
Name : 4.c
Author : Harshal Gujarathi
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 15th Aug, 2024.
============================================================================
*/

#include <stdio.h> //standard i/o
#include <fcntl.h> //File control
#include <unistd.h> //System call functions.

int main() {
    // providing the file name which already exists.
    const char *fileName = "data.txt";

    // Attempt to open the file in read/write mode, also use the O_EXCL flag.
    // If the file does not exits then O_EXCL should be used by O_Create, but here the file already exists.

    int fd = open(fileName, O_RDWR | O_EXCL); // O_Excl stats that no existing file is overwritten or same file is not created by multiple process.

    // Check if the file was opened successfully
    if (fd == -1) {
        perror("Error in opening the file");
        return 1;
    }

    // Print the file descriptor value
    printf("The File descriptor value is : %d\n", fd);

    // Close the file descriptor for useful system resources.
    close(fd);

    return 0;
}


//OUTPUT
//The File descriptor value is : 3
