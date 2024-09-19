/*============================================================================
Name : 20w.c
Author : Harshal Gujarathi
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 19th Sept, 2024.
============================================================================
*/

// writer.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo = "my_fifo";
    char message[] = "Hello from the writer!";

    // Open the FIFO for writing
    int fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write the message to the FIFO
    write(fd, message, sizeof(message));
    printf("Message sent: %s\n", message);

    // Close the FIFO
    close(fd);

    return 0;
}
