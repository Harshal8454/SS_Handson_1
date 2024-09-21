/*============================================================================
Name : 30.c
Author : Harshal Gujarathi
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    if(!fork()){
        setsid(); // creating a new session so that it becomes independent 
        chdir("/");
        umask(0);
        while(1){
            sleep(4);
            printf("child pid: %d\n", getpid());
            printf("Daemon process is running..\n");
        };
    }
    else exit(0);
}

/*
OUTPUT
child pid: 17339
Daemon process is running..
child pid: 17339
Daemon process is running..
child pid: 17339
Daemon process is running..
*/