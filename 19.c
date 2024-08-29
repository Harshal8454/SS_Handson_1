/*============================================================================
Name : 19.c
Author : Harshal Gujarathi
Description :Write a program to find out time taken to execute getpid system
             call. Use time stamp counter.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long long rdtsc(){ //Reads the CPU's time-stamp counter
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc": "=A" (dst)); //reads the current cpu value and stores in dst.
}

int main(void){
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc(); //captures the value of the TSC before entering the loop
    for(i=0; i<10000;i++){
        getppid();
    }
    end = rdtsc();
    nano = (end-start)/2.09; // the factor converts the no of CPU cycles into nanoseconds.
    printf("The function takes %d nano sec\n", nano);
}

//OUTPUT
//The function takes 2572053 nano sec

