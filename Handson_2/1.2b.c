/*============================================================================
Name : 1.2b
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             b.ITIMER_VIRTUAL (10 ms)
Date: 9th Sept, 2024.
============================================================================
*/
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10ms virtual timer expired\n", 27);
}

int main() {
    signal(SIGVTALRM, handler);
    struct itimerval timer = {{0, 10000}, {0, 10000}}; // 10 milliseconds interval
    setitimer(ITIMER_VIRTUAL, &timer, NULL); // Set the ITIMER_VIRTUAL timer
    while (1) {
        for(volatile int i=0;i<1000000;i++);
    }
    return 0;
}

/*OUTPUT
10ms virtual timer expired
10ms virtual timer expired
10ms virtual timer expired
10ms virtual timer expired
*/
