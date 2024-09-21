/*============================================================================
Name : 22.c
Author : Harshal Gujarathi
Description :Write a program, open a file, call fork, and then 
            write to the file by both the child as well as the parent processes. Check output of the file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        return 1;
    } else if (pid == 0) {
        const char *child = "This is the child process.\n";
        close(fd); 
    } else {
        const char *parent = "This is the parent process.\n";
        close(fd); 
    }

    return 0;
}


//OUTPUT
/*This is the child process.
This is the parent process.
*/