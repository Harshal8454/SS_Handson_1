/*============================================================================
Name : 20.c
Author : Harshal Gujarathi
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 19th Sept, 2024.
============================================================================
*/

// reader.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo = "my_fifo";
    char buffer[80];

    // Open the FIFO for reading
    int fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read the message from the FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Message received: %s\n", buffer);

    // Close the FIFO
    close(fd);

    return 0;
}
