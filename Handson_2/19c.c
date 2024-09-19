/*============================================================================
Name : 19c.c
Author : Harshal Gujarathi
Description : Create a FIFO file by 
              b.Use strace command to find out, which command (mknod or mkfifo) is better. 
Date: 19th Sept, 2024.
============================================================================
*/


/*
    strace -c mknod my_fifo p 
    strace -c mkfifo my_fifo1

    mkfifo internally calls mknod. So, it is better to use mknod.
*/

