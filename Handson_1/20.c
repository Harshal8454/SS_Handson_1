/*============================================================================
Name : 20.c
Author : Harshal Gujarathi
Description :Find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>
int main(){
	int pid = getpid();
	int prior = getpriority(PRIO_PROCESS,pid);
	printf("Priority : %d\n",prior);
	int r = nice(15);
	prior = getpriority(PRIO_PROCESS,pid);
        printf("Priority : %d\n",prior);

	return 0;
}

/*
OUTPUT
Priority : 0
Priority : 15
*/