/*============================================================================
Name : 34b.c
Author : Harshal Gujarathi
Description :Write a program to create a concurrent server.
             b.Use `pthread_create`
Date: 20th Sept, 2024.
============================================================================
*/

//The server side 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);  // Free the allocated memory for the client socket
    char buffer[BUFFER_SIZE] = {0};
    
    read(sock, buffer, sizeof(buffer) - 1);
    printf("Client: %s\n", buffer);
    
    write(sock, "Message received\n", 17);
    close(sock);
    return NULL;
}

int main() {
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr = {AF_INET, htons(PORT), htonl(INADDR_ANY)};
    
    bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 5);
    printf("Server running on port %d...\n", PORT);
    
    while (1) {
        int *clientSock = malloc(sizeof(int));
        *clientSock = accept(serverSock, NULL, NULL);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, clientSock);
        pthread_detach(thread_id); 
    }

    close(serverSock);
    return 0;
}

/*
OUTPUT
Server running on port 8080...

Client: Hello!
*/