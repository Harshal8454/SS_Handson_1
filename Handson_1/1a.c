/*============================================================================
Name : 1a.c
Author : Harshal Gujarathi
Description :Create the following types of a files using (i) shell command (ii) system call 
             a.Soft link (symlink system call) 
Date: 15th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    const char *target = "text1.txt";
    const char *linkpath = "linked_s_text1.txt";

    // Create symlink
    if (symlink(target, linkpath) == 0) {
        printf("symlink: File exists\n");
    } else {
        perror("symlink");
    }

    return 0;
}

//OUTPUT
//symlink: File exists
