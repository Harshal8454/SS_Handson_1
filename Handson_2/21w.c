/*============================================================================
Name : 21w.c
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
    int fd1 = open("./fifo1", O_WRONLY);
    int fd2 = open("./fifo2", O_RDONLY);    
    char buff[20];

    printf("Enter text for pipe :");
    scanf("%[^\n]", buff);
    write(fd1, buff, sizeof(buff));
    read(fd2, buff, sizeof(buff));

    printf("%s", buff);
}

/*
OUTPUT
First create two fifo files

Writers Terminal

Enter text for pipe :Hello
Hye
*/