/*============================================================================
Name : 34a.c
Author : Harshal Gujarathi
Description :Write a program to create a concurrent server. 
            a.Use fork 
Date: 20th Sept, 2024.
============================================================================
*/

//The Server side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

int main() {
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr = {AF_INET, htons(PORT), htonl(INADDR_ANY)};

    bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 5);
    printf("Server running on port %d...\n", PORT);

    while (1) {
        int clientSock = accept(serverSock, NULL, NULL);
        if (fork() == 0) {
            close(serverSock);
            char buffer[BUFFER_SIZE] = {0};
            read(clientSock, buffer, sizeof(buffer) - 1);
            printf("Client: %s\n", buffer);
            write(clientSock, "Message received\n", 17);
            close(clientSock);
            exit(0);
        }
        close(clientSock);
    }

    close(serverSock);
    return 0;
}

/*
OUTPUT (First Run the server)
Server running on port 8080...

Client: Hello!

*/