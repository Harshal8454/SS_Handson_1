/*============================================================================
Name : 1c.c
Author : Harshal Gujarathi
Description :Create the following types of a files using (i) shell command (ii) system call 
             c.FIFO (mkfifo Library Function or mknod system call)
Date: 15th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *fifo_path = "my_fifo";

    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("mkfifo: File exists.\n");
    return 0;
}

//OUTPUT
//mkfifo: File exists