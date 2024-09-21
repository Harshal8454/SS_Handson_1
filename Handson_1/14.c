/*============================================================================
Name : 14.c
Author : Harshal Gujarathi
Description : Write a program to find the type of a file. 
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h> //std i/o
#include <sys/stat.h>//The stat structure.

int main(int argc, char *argv[]) {
    if (argc != 2) { //it ensures that only one argument is provided.
        printf("Usage: %s <file-path>\n", argv[0]);
        return 1;
    }

    struct stat st; //Declares the variable which holds the information about the file
    if (stat(argv[1], &st) < 0) { //Takes the file path and update the stat variable.
        perror("stat");
        return 1;
    }

    if (S_ISREG(st.st_mode)) printf("Regular file\n");
    else if (S_ISDIR(st.st_mode)) printf("Directory\n");
    else if (S_ISLNK(st.st_mode)) printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode)) printf("Character device\n");
    else if (S_ISBLK(st.st_mode)) printf("Block device\n");
    else if (S_ISFIFO(st.st_mode)) printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode)) printf("Socket\n");
    else printf("Unknown type\n");

    return 0;
}

//OUTPUT (passed the input as our file1)
//Regular file
