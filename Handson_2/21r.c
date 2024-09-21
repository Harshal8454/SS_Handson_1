/*============================================================================
Name : 21r.c
Author : Harshal Gujarathi
Description : Write two programs so that both can communicate by FIFO - Use two way communications.
Date: 19th Sept, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1 = open("./fifo1", O_RDONLY);
    int fd2 = open("./fifo2", O_WRONLY);

    char buff[20];

    read(fd1, buff, sizeof(buff));
    printf("%s", buff);
    printf("\nEnter msg to send: ");
    scanf("%s", buff);
    write(fd2, buff, sizeof(buff));
}

/*
OUTPUT

Readers Terminal

Hello
Enter msg to send: Hye
*/