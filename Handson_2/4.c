/*============================================================================
Name : 4.c
Author : Harshal Gujarathi
Description :Write a program to measure how much time is taken to execute 100 getppid() system call. 
             Use time stamp counter.
Date: 10th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
    unsigned long long tsc;
    asm volatile ("rdtsc" : "=A" (tsc));
    return tsc;
}

int main() {
    unsigned long long start = rdtsc();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    unsigned long long end = rdtsc();
    printf("Cycles for 100 getppid() calls: %llu\n", end - start);
    
    return 0;
}

/*
OUTPUT
Cycles for 100 getppid() calls: 21114
*/