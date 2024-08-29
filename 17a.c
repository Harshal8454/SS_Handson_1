/*============================================================================
Name : 17a.c
Author : Harshal Gujarathi
Description : Write a program to simulate online ticket reservations. Implement a write lock.  
              Write a program to open a file, store a ticket number, and exit. 
Date: 28th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//The database is created which consist of the ticket number.
int main(){
    int fd;
    struct{
        int ticket_no;
    }db;
    db.ticket_no=11;
    fd = open("db", O_CREAT|O_RDWR, 0644);
    write(fd, &db, sizeof(db));
    close(fd);
    fd = open("db",O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket no: %d\n", db.ticket_no);
    close(fd);
}

//OUTPUT
//Ticket no: 11



