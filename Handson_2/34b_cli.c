/*============================================================================
Name : 34b.c
Author : Harshal Gujarathi
Description :Write a program to create a concurrent server.
             b.Use `pthread_create`
Date: 20th Sept, 2024.
============================================================================
*/

//The client side 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servAddr = {AF_INET, htons(PORT), htonl(INADDR_ANY)};

    connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr));
    send(sock, "Hello!", 6, 0);
    char buffer[256] = {0};
    read(sock, buffer, sizeof(buffer));
    printf("Response: %s\n", buffer);
    close(sock);
    return 0;
}

/*
OUTPUT
Response: Message received
*/