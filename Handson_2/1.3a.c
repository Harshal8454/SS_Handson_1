/*============================================================================
Name : 1.3a
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             a.ITIMER_PROF (10 s)
Date: 9th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10s profiling timer expired\n", 28);
}

int main() {
    signal(SIGPROF, handler);
    
    struct itimerval timer = {{10, 0}, {10, 0}}; // 10 seconds interval
    setitimer(ITIMER_PROF, &timer, NULL); // Set ITIMER_PROF timer
    
    while (1) {
        // Busy loop to consume CPU time
        for(volatile int i = 0; i < 100000; i++);
    }
    
    return 0;
}
/*
OUTPUT
10s profiling timer expired
10s profiling timer expired
10s profiling timer expired
*/
