/*============================================================================
Name : 9.c
Author : Harshal Gujarathi
Description :Write a program to print the following information about a given file. 
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    // The variable filestat is declared to store the file information.
    struct stat fileStat;
    stat("file1", &fileStat);

    printf("Inode: %lu\n", fileStat.st_ino);
    printf("Hard links: %lu\n", fileStat.st_nlink);
    printf("UID: %u\n", fileStat.st_uid);
    printf("GID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block size: %ld bytes\n", fileStat.st_blksize);
    printf("Number of blocks: %ld\n", fileStat.st_blocks);
    printf("Last access: %s", ctime(&fileStat.st_atime));
    printf("Last modification: %s", ctime(&fileStat.st_mtime));
    printf("Last change: %s", ctime(&fileStat.st_ctime));
    return 0;
}

//Output
//Inode: 0
//Hard_Links: 0
//UID: 0
//GID: 0
//Size: 0 bytes
//Block_Size: 0 bytes
//Number of blocks: 0
//Last Access: Thr Jan 1 05:30:00 1970
//Last Modification: Thru Jan 1 05:30:00 1970
//Last Change: Thr Jan 1 05:30:00 1970
