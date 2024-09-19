/*============================================================================
Name : 16.c
Author : Harshal Gujarathi
Description :Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 14th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main(){
    int fd1[2], fd2[2];
    char buff1[100], buff2[100];

    //creates two pipe for two-way communication
    pipe(fd1);
    pipe(fd2);

    if (fork()==0){
        close(fd1[0]); //close read-end of fd1 for child
        close(fd2[1]); //close write-end of fd2 for child

        printf("Enter Message to parent: ");
        scanf(" %[^\n]", buff1);
        
        write(fd1[1], buff1, sizeof(buff1));
        read(fd2[0], buff2, sizeof(buff2));

        printf("Message from parent: %s\n", buff2);
        close(fd1[1]);
        close(fd2[0]);
    }
    else{
        close(fd1[1]); // close read-end of fd1 for parent
        close(fd2[0]); // close read-end of fd2 for parent

        //child wrote into fd1 first, so read from fd1 first
        read(fd1[0], buff1, sizeof(buff1));
        printf("Message from child: %s\n", buff1);
        printf("Enter message to child: ");
        scanf(" %[^\n]", buff2);
        
        write(fd2[1], buff2, sizeof(buff2));
        close(fd1[0]);
        close(fd2[1]);
    }
    return 0;
}

/*
OUTPUT
Enter Message to parent: Hello Papa!
Message from child: Hello Papa!
Enter message to child: Hello Beta!
Message from parent: Hello Beta!
*/