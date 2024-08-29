/*============================================================================
Name : 18a.c
Author : Harshal Gujarathi
Description : Write a program to perform Record locking. 
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
// Creating records with train_no,ticket_count.
int main(){
    int i, fd;
    struct{
        int train_num;
        int ticket_count;
    } db[3];

    for(i=0;i<3;i++){
        db[i].train_num = i+1;
        db[i].ticket_count = 0;
    }

    // Writing all 3 records to record.txt file
    fd = open("record.txt", O_RDWR);
    write(fd, db, sizeof(db));
}

//OUTPUT (This are the 3 records created in the record file in hexadecimal format)
// You can view this by using"hexdump -C record.txt" command in linux terminal.

/*00000000  01 00 00 00 00 00 00 00  02 00 00 00 00 00 00 00  |................|
00000010  03 00 00 00 00 00 00 00                           |........|
00000018
*/