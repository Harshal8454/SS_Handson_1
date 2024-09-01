/*============================================================================
Name : 26b.c
Author : Harshal Gujarathi
Description :Write a program to execute an executable program. 
             b. Pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ./Harshal with an argument\n");
    execlp("./Harshal", "./Harshal", "name", NULL);// Execute "./Harshal" with the argument "name"
    perror("execlp failed");
    return 1;
}

//OUTPUT
//Executing ./Harshal with an argument