/*============================================================================
Name : 1.3b
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             b.ITIMER_PROF (10 ms)
Date: 9th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10ms profiling timer expired\n", 29);
}

int main() {
    signal(SIGPROF, handler);
    
    struct itimerval timer = {{0, 10000}, {0, 10000}}; // 10 milliseconds interval
    setitimer(ITIMER_PROF, &timer, NULL); // Set ITIMER_PROF timer
    
    while (1) {
        // Busy loop to consume CPU time
        for(volatile int i = 0; i < 1000000; i++);
    }
    
    return 0;
}
/*
OUTPUT
10ms profiling timer expired
10ms profiling timer expired
10ms profiling timer expired
10ms profiling timer expired
10ms profiling timer expired
10ms profiling timer expired
10ms profiling timer expired
*/