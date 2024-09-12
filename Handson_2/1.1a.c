/*============================================================================
Name : 1.1a
Author : Harshal Gujarathi
Description :Write a separate program (for each time domain) to set a interval timer in 10s and 10ms 
             a.ITIMER_REAL (10 s)
Date: 9th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    write(1, "10s timer expired\n", 18);
}

int main() {
    signal(SIGALRM, handler);
    struct itimerval timer = {{10, 0}, {10, 0}};
    setitimer(ITIMER_REAL, &timer, NULL);
    while (1) pause();
}

//OUTPUT
/*10s timer expired
10s timer expired
*/
