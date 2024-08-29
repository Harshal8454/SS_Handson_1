/*============================================================================
Name : 18b.c
Author : Harshal Gujarathi
Description : Implement write and Read lock.
Date: 28th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for records
struct record {
    int train_num;
    int ticket_count;
};

int main() {
    int fd, input;
    struct record db[3];
    // Initialize the records
    for (int i = 0; i < 3; i++) {
        db[i].train_num = i + 1;
        db[i].ticket_count = 0;
    }

    // Open the file for reading and writing, creating it if it does not exist
    fd = open("record.txt", O_RDWR | O_CREAT, 0644);

    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    // Setup the lock structure
    struct flock lock;
    lock.l_type = F_WRLCK;          // Write lock
    lock.l_whence = SEEK_SET;       // Start from the beginning of the file
    lock.l_start = (input - 1) * sizeof(struct record); // Position of the record
    lock.l_len = sizeof(struct record);  // Length of the record
    lock.l_pid = getpid();          // Process ID


    // Move to the record position and read it
    lseek(fd, (input - 1) * sizeof(struct record), SEEK_SET);
    read(fd, &db[input - 1], sizeof(struct record)); //due to indexing(inp-1)

    printf("Before entering the critical section\n");

    fcntl(fd, F_SETLKW, &lock);
    // Display current ticket count and increment it
    printf("Current ticket count: %d\n", db[input - 1].ticket_count);
    db[input - 1].ticket_count++;

    // Move to the record position and write the updated record
    lseek(fd, (input - 1) * sizeof(struct record), SEEK_SET);
    write(fd, &db[input - 1], sizeof(struct record));

    printf("To book a ticket, press Enter\n");
    getchar(); // Consume newline left by scanf
    getchar(); // Wait for user to press Enter

    // Unlock the record
    lock.l_type = F_UNLCK;  // Unlock
    fcntl(fd, F_SETLK, &lock);
    printf("The current booking number is %d\n", db[input - 1].ticket_count);

    // Close the file descriptor
    close(fd);

    return 0;
}


//OUTPUT
/*Select train number: 1, 2, 3
1
Before entering the critical section
Current ticket count: 1
To book a ticket, press Enter

The current booking number is 2*/