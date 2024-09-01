/*============================================================================
Name : 26a.c
Author : Harshal Gujarathi
Description :Write a program to execute an executable program. 
             a. Use some executable program 
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}

//OUTPUT
//Usage: ./Harshal <name>