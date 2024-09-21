/*============================================================================
Name : 1b.c
Author : Harshal Gujarathi
Description :Create the following types of a files using (i) shell command (ii) system call 
             b.Hard link (link system call) 
Date: 15th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    const char *target = "original.txt"; // Ensure this file exists
    const char *linkpath = "linked_h_text.txt";

    // Create hard link
    if (link(target, linkpath) == 0) {
        printf("link: File exists\n");
    } else {
        perror("link");
    }

    return 0;
}

//OUTPUT
//link: File exists


