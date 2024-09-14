/*============================================================================
Name : 7.c
Author : Harshal Gujarathi
Description : Write a simple program to print the created thread IDs.
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function() {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, thread_function, NULL);

    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
/*
OUTPUT
Thread ID: 140592529012416
Thread ID: 140592520619712
Thread ID: 140592512227008
*/
