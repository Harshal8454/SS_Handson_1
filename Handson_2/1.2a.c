/*============================================================================
Name : 1.2a
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             a.ITIMER_VIRTUAL (10 s)
Date: 9th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10s virtual timer expired\n", 26);
}

int main() {
    signal(SIGVTALRM, handler);
    struct itimerval timer = {{10, 0}, {10, 0}}; 
    setitimer(ITIMER_VIRTUAL, &timer, NULL); 
    while (1){
        for(volatile int i = 0; i<100000; i++);//This forces process to consume CPU time
    }
    return 0;
}
/*
OUTPUT
10s virtual timer expired
10s virtual timer expired
10s virtual timer expired
*/
