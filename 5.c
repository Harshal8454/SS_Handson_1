/*============================================================================
Name : 5.c
Author : Harshal Gujarathi
Description :Write a program to create five new files with an infinite loop. 
             Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 17th Aug, 2024.
============================================================================
*/

#include <stdio.h> //standard i/o
#include <fcntl.h> // file control
#include <unistd.h> // system call execution
#include <stdlib.h> // lib

int main() {
    int count;
    char filename[16]; // created an character array for storing the name of the name.

    while (1) {  // Infinite loop
        for (count = 1; count <= 5; count++) {
            // Create a filename based on the current count
            sprintf(filename, "new_%d.txt", count);

            // Open the file with read_write access, create it if it doesn't exist
            int fd = open(filename, O_CREAT | O_RDWR, 0644);
            if (fd == -1) {
                perror("Failed to create a new file");
                exit(EXIT_FAILURE);
            }

            // Display the file descriptor number
            printf("File %s created with descriptor value: %d\n", filename, fd);

            // Close the file to release the descriptor
            close(fd);
        }
    }
    return 0;
}


//OUTPUT
/*File new_1.txt created with descriptor value: 3
File new_2.txt created with descriptor value: 3
File new_3.txt created with descriptor value: 3
File new_4.txt created with descriptor value: 3
File new_5.txt created with descriptor value: 3
*/