/*============================================================================
Name : 17b.c
Author : Harshal Gujarathi
Description : Write a separate program, to open the file,  implement write lock, read the ticket number, 
              increment the number, and print the new ticket number then close the file.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    struct flock lock;
    int fd;
    struct {
        int ticket_no;
    } db;

    fd = open("db", O_RDWR);

    lock.l_type = F_WRLCK;   // Set the lock type to write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  

    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section\n");

    read(fd, &db, sizeof(db));
    printf("Current ticket number: %d\n", db.ticket_no);
    db.ticket_no++;

    lseek(fd,0,SEEK_SET); //To retyrn to the start of the code.
    write(fd,&db, sizeof(db));

    printf("Press enter to unlock\n");
    getchar();

    lock.l_type=F_UNLCK;// here the write lock is unlocked
    fcntl(fd, F_SETLK, &lock); //Apply the unlocking.
    printf("Exited critical section successfully\n");
}

//OUTPUT
/*Inside the critical section
Current ticket number: 12
Press enter to unlock

Exited critical section successfully*/