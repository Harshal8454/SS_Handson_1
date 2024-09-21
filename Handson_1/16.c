/*============================================================================
Name : 16.c
Author : Harshal Gujarathi
Description : Write a program to perform mandatory locking.
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>//std i/o
#include <stdlib.h>//functions
#include <fcntl.h>//file control operations.
#include <unistd.h>//accessing OS


//The function for setting the lock.
void set_lock(int fd, int type, off_t offset, off_t length) {
    struct flock lock;

    lock.l_type = type;     // Sets the type of lock.
    lock.l_whence = SEEK_SET;  // Offset is relative to the beginning of the file
    lock.l_start = offset;   // Starting offset of the lock
    lock.l_len = length;     // Length of the lock
    lock.l_pid = getpid();   // Process ID.

    if (fcntl(fd, F_SETLKW, &lock) == -1) {//F_SETLKW is set,it will wait untill the lock is acquired.
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

//The function to release the lock.
void release_lock(int fd) { //file descriptor to realease the lock.
    struct flock lock;

    lock.l_type = F_UNLCK;   // Unlock type
    lock.l_whence = SEEK_SET; // Offset is relative to the beginning of the file
    lock.l_start = 0;        // Lock the entire file
    lock.l_len = 0;          // Lock the entire file
    lock.l_pid = getpid();   // Process ID 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *filename = "file1";
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    printf("The File opened successfully.\n");

    // Set a write lock on the file
    printf("Acquiring write lock\n");
    set_lock(fd, F_WRLCK, 0, 0); // Lock the entire file

    printf("Write lock acquired.\n");
    getchar(); // Displays the message and Wait for user input

    // Release the write lock
    printf("Releasing write lock\n");
    release_lock(fd); // releases the lock for the given file descriptor.

    printf("Write lock released.\n");
    getchar(); // Displays the message and Wait for user input

    // Set a read lock on the file
    printf("Acquiring read lock\n");
    set_lock(fd, F_RDLCK, 0, 0); // Lock the entire file

    printf("Read lock acquired.\n");
    getchar(); // Displays the result and Wait for user input

    // Release the read lock
    printf("Releasing read lock\n");
    release_lock(fd);

    close(fd);
    return EXIT_SUCCESS;
}


//OUTPUT
/*The File opened successfully.
Acquiring write lock
Write lock acquired.

Releasing write lock
Write lock released.

Acquiring read lock
Read lock acquired.

Releasing read lock
*/