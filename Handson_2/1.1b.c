/*============================================================================
Name : 1.1b
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             a.ITIMER_REAL (10 ms)
Date: 9th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10ms timer expired\n", 19);
}

int main() {
    signal(SIGALRM, handler);
    struct itimerval timer = {{0, 10000}, {0, 10000}};
    setitimer(ITIMER_REAL, &timer, NULL);
    while (1) pause();
}

/*OUTPUT
10ms timer expired
10ms timer expired
10ms timer expired
*/

