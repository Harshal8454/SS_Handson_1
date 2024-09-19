/*============================================================================
Name : 19e.c
Author : Harshal Gujarathi
Description : Create a FIFO file by 
              d.mknod system call 
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    if(mkfifo("./myfifo3", 0666) == -1)
        printf("%s", strerror(errno));

}