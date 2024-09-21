/*============================================================================
Name : 23.c
Author : Harshal Gujarathi
Description :Write a program to create a Zombie state of the running program.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("In child - PID = %d\n", getpid());
    } else {
        printf("This is parent process - PID = %d\n", getpid());
        sleep(10);  // Keep parent process alive to observe the zombie state
        wait(NULL); // Wait for the child process to finish
    }
    return 0;
}


/*
OUTPUT
This is parent process - PID = 21232
In child - PID = 21233

ps aux | grep 'Z' (by using the command)

USER         PID %CPU %MEM    VSZ   RSS TTY   STAT START   TIME COMMAND
harshal     5897  0.0  0.0      0     0 ?        Z    09:12   0:00 [sd_espeak-ng-mb] <defunct>
harshal    21012  0.0  0.0   9072  2304 pts/0    S+   17:37   0:00 grep --color=auto Z

'Z' state defines that the process is in the Zombie state
*/