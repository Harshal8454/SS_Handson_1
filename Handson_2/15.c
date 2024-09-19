/*============================================================================
Name : 15.c
Author : Harshal Gujarathi
Description :Write a simple program to send some data from parent to the child process.
Date: 14th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main(){
    char buff[80];
    int fd[2];
    pipe(fd);

    if (fork()){
        close(fd[0]); //close read-end of pipe for parent
        printf("Enter the message to the child: ");
        scanf(" %[^\n]", buff); // Read till new line encountered.
        write(fd[1], buff, sizeof(buff));
    }
    else{
        close(fd[1]); //close write-end of pipe for child
        read(fd[0], buff, sizeof(buff));
        printf("Message from parent: %s\n", buff);
    }
    wait(0);// wait till all children have terminated.
}

/*
OUTPUT
Enter the message to the child: Hello beta!
Message from parent: Hello beta!
*/