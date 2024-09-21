/*============================================================================
Name : 10.c
Author : Harshal Gujarathi
Description : Write a program to open a file with read write mode, write 10 bytes, 
             move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
Date: 20th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file1", O_RDWR | O_CREAT, 0644);
    write(fd, "0123456789", 10);

    if (lseek(fd, 10, SEEK_CUR) == -1) return 1;

    write(fd, "ABCDEFGHIJ", 10);
    close(fd);
    return 0;
}

//od -c file1 (This command is used)

//OUTPUT: This shows the two sets of data with the gap in between
//0000000   1   2   3   4   5   6   7   8   9   0   a   l       G   u   j
//0000020   a   r   a   t   A   B   C   D   E   F   G   H   I   J
//0000036

