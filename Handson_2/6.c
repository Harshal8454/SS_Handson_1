/*============================================================================
Name : 6.c
Author : Harshal Gujarathi
Description : Write a simple program to create three threads.
Date: 10th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* print_message(void* id) {
    printf("Thread %d\n", *(int*)id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3] = {0, 1, 2};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_message, &ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
OUTPUT
Thread 1
Thread 0
Thread 2
*/